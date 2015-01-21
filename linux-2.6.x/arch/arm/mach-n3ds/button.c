/*
 * Nintendo 3DS buttons driver
 *
 * Copyright (c) 2005 Malcolm Parsons
 */

/*
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by
 * the Free Software Foundation.
 */

#include <linux/input.h>
#include <linux/module.h>
#include <linux/init.h> 
#include <linux/interrupt.h> 

#include <asm/irq.h>
#include <asm/io.h>
#include <asm/arch/fifo.h>

#define REG_KEYINPUT 	0x10146000
static struct input_dev n3dsbutton_dev;

#if 0
	BTN_A, BTN_B, BTN_SELECT, BTN_START,
       	BTN_0, BTN_1, BTN_2, BTN_3,
	BTN_THUMBR, BTN_THUMBL
};
#else
static short n3dsbuttons[] = { 
	KEY_ENTER, KEY_SPACE, BTN_SELECT, BTN_START,
       	KEY_RIGHT, KEY_LEFT, KEY_UP, KEY_DOWN,
	#ifndef CONFIG_N3DS_SWAP_LR
	KEY_RIGHTCTRL, KEY_LEFTSHIFT
	#else
	KEY_RIGHTSHIFT, KEY_LEFTCTRL
	#endif
};
static short n3dsbuttons2[] = { 
	KEY_PAGEUP, KEY_PAGEDOWN
};
#endif

static irqreturn_t n3dsbutton_interrupt(int irq, void *dev_id, struct pt_regs *regs)
{
	int i;
	u16 state = readw(REG_KEYINPUT);

	for (i = 0 ; i < (sizeof(n3dsbuttons)/sizeof(n3dsbuttons[0])) ; i++)
		input_report_key(&n3dsbutton_dev, n3dsbuttons[i], !((state >> i) & 1));

        input_sync(&n3dsbutton_dev);

	return IRQ_HANDLED ;
}

static void n3dsbutton_xkeys(u32 state)
{
	int i;
	for (i = 0 ; i < (sizeof(n3dsbuttons2)/sizeof(n3dsbuttons2[0])) ; i++)
	{
		input_report_key(&n3dsbutton_dev, n3dsbuttons2[i], !((state >> i) & 1));
	}
       input_report_switch(&n3dsbutton_dev, SW_0, ((state >> 7 )&1)); 
       input_sync(&n3dsbutton_dev);
}

static struct fifo_cb n3dsbutton_fifocb = {
	.type = FIFO_BUTTONS,
	.handler.button_handler = n3dsbutton_xkeys
};

static int __init n3dsbutton_init(void)
{
	int i;

        if (request_irq(IRQ_VBLANK, n3dsbutton_interrupt, SA_SHIRQ, "button", &n3dsbutton_dev)) {
                printk(KERN_ERR "button.c: Can't allocate irq %d\n", IRQ_KEYPAD);
                return -EBUSY;
        }

	*(volatile u16*) 0x04000004 |= 1 << 3 ;

        n3dsbutton_dev.evbit[0] = BIT(EV_KEY) | BIT(EV_REP) | BIT(EV_SW);
	n3dsbutton_dev.swbit[0] = BIT(SW_0);
	for ( i = 0 ; i < (sizeof(n3dsbuttons)/sizeof(n3dsbuttons[0])) ; i++ )
		n3dsbutton_dev.keybit[LONG(n3dsbuttons[i])] |= BIT(n3dsbuttons[i]);
	for ( i = 0 ; i < (sizeof(n3dsbuttons2)/sizeof(n3dsbuttons2[0])) ; i++ )
		n3dsbutton_dev.keybit[LONG(n3dsbuttons2[i])] |= BIT(n3dsbuttons2[i]);
        
        input_register_device(&n3dsbutton_dev);

	register_fifocb( &n3dsbutton_fifocb ) ;

	return 0;
}

static void __exit n3dsbutton_exit(void)
{
        input_unregister_device(&n3dsbutton_dev);
        free_irq(IRQ_VBLANK, &n3dsbutton_dev);
}

module_init(n3dsbutton_init);
module_exit(n3dsbutton_exit);

