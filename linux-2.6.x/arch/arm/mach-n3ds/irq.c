/*
 *  linux/arch/arm/kernel/irq.c
 *
 *  Copyright (C) 1992 Linus Torvalds
 *  Modifications for ARM processor Copyright (C) 1995, 1996 Russell King.
 *
 * This file contains the code used by various IRQ handling routines:
 * asking for different IRQ's should be done through these routines
 * instead of just grabbing them. Thus setups with different IRQ numbers
 * shouldn't result in any weird surprises, and installing new handlers
 * should be easier.
 */

/*
 * IRQ's are in fact implemented a bit like signal handlers for the kernel.
 * Naturally it's not a 1:1 relation, but there are similarities.
 */
#include <linux/ptrace.h>
#include <linux/errno.h>
#include <linux/kernel_stat.h>
#include <linux/signal.h>
#include <linux/sched.h>
#include <linux/interrupt.h>
#include <linux/timex.h>
#include <linux/random.h>

#include <asm/io.h>
#include <asm/system.h>
#include <asm/hardware.h>
#include <asm/irq.h>
#include <asm/mach/irq.h>

/*
 *  Nintendo 3DS interrupts are controlled by 3 registers in the IO memory space.
 */
#define N3DS_IE      0x10001000      /* Interrupt mask */
#define N3DS_IF      0x10001004      /* Interrup service */
//#define N3DS_IME     0x04000208      /* Enable/disable */

static __inline__ void __n3ds_mask_irq(unsigned int irq)
{
	*((u32*) N3DS_IE) &= ~(0x1 << irq);
}

static __inline__ void __n3ds_unmask_irq(unsigned int irq)
{
	*((u32*) N3DS_IE) |= (0x1 << irq);
}

static __inline__ void __n3ds_ack_irq(unsigned int irq)
{
	*((u32*) N3DS_IF) = (0x1 << irq);
	*((u32*) N3DS_IE) &= ~(0x1 << irq);
}

static struct irqchip n3ds_chip = {
	.ack    = __n3ds_ack_irq,
	.mask	= __n3ds_mask_irq,
	.unmask = __n3ds_unmask_irq
};

void n3ds_init_irq( void )
{
	int irq;

	for (irq = 0; irq < NR_IRQS; irq++) {
		set_irq_chip(irq, &n3ds_chip);
		set_irq_handler(irq, do_level_IRQ);
		set_irq_flags(irq, IRQF_VALID | IRQF_PROBE);
	}

	*((u32*) N3DS_IE) = 0;
	//*((u32*) N3DS_IME) = 0x0001;
}

