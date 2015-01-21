/*
 *  linux/arch/arm/mach-nds/arch.c
 *
 *  Copyright (C) 2004 SAMSUNG ELECTRONICS Co.,Ltd.
 *			      Hyok S. Choi (hyok.choi@samsung.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#include <linux/config.h>
#include <linux/types.h>
#include <linux/sched.h>
#include <linux/interrupt.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/list.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/sysdev.h>

#include <asm/hardware.h>
#include <asm/io.h>
#include <asm/irq.h>
#include <asm/setup.h>
#include <asm/mach-types.h>

#include <asm/mach/arch.h>
#include <asm/mach/irq.h>
#include <asm/mach/map.h>

#include <asm/arch/power.h>
#include <asm/arch/fifo.h>

#define WAIT_CR 	0x04000204

extern struct sys_timer n3ds_timer;

extern void __init n3ds_init_irq(void);

static void poweroff(void)
{
	printk("arch N3DS: poweroff");
	//nds_fifo_send(FIFO_POWER_CMD(FIFO_POWER_CMD_SYSTEM_POWER, 0));
}

static void n3ds_machine_init(void)
{
	printk("arch N3DS: n3ds_machine_init");
	//POWER_CR = POWER_2D | POWER_2D_SUB | POWER_LCD | POWER_SWAP_LCDS ;

	/* Note: initial setup of wait_cr in head.S */

	pm_power_off = poweroff;
}

static void __init
fixup_n3ds(struct machine_desc *desc, struct tag *tags,
	      char **cmdline, struct meminfo *mi)
{
	printk("arch N3DS: fixup_n3ds");
	/*mi->bank[0].start = CONFIG_DRAM_BASE;
	mi->bank[0].size  = CONFIG_DRAM_SIZE;
	mi->bank[0].node  = 0;
	mi->nr_banks = 1;
#ifdef CONFIG_NDS_ROM8BIT
	if (gba_activate_ram()) {
		mi->bank[1].start = gba_start;
		mi->bank[1].size  = gba_length;
		mi->bank[1].node  = 0;
		mi->nr_banks = 2;
	}
#endif*/
}

MACHINE_START(N3DS, "Nintendo 3DS")
	.phys_ram	= CONFIG_DRAM_BASE,
	.phys_io	= 0x10000000,
	.init_irq	= n3ds_init_irq,
	.timer		= &n3ds_timer,
	.init_machine	= n3ds_machine_init,
	.fixup		= fixup_n3ds,
MACHINE_END
