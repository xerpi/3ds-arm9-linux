#
# Makefile for the linux kernel.
#

# Object file lists.

obj-y += debug.o arch.o irq.o time.o button.o fifo.o rtc.o disable-itcm-writes.o

obj-$(CONFIG_N3DS_TEXT_CONSOLE) += console.o font_data.o
obj-$(CONFIG_N3DS_SOUNDTEST) += soundtest.o

clean:
	rm -f *.o
