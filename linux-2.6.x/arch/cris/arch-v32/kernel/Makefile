# $Id: Makefile 573 2006-02-20 17:09:11Z stsp2 $
#
# Makefile for the linux kernel.
#

extra-y	:= head.o


obj-y   := entry.o traps.o irq.o debugport.o dma.o pinmux.o \
	   process.o ptrace.o setup.o signal.o traps.o time.o \
	   arbiter.o io.o

obj-$(CONFIG_ETRAXFS_SIM) += vcs_hook.o

obj-$(CONFIG_SMP) += smp.o
obj-$(CONFIG_ETRAX_KGDB) += kgdb.o kgdb_asm.o
obj-$(CONFIG_ETRAX_FAST_TIMER) += fasttimer.o
obj-$(CONFIG_MODULES)    += crisksyms.o

clean:

