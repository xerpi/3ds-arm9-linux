#-include $(DEVKITARM)/base_rules

all: build loadme.bin

loadme.bin: build/loader.elf
	$(CROSS)$(OBJCOPY) $< -O binary $@

build/loader.elf: loader.s
	$(CROSS)$(CC) -Wall -o $@ $< -Ttext 0x080000C0 -nostdlib

.PHONY: build clean

build:
	[ -d $@ ] || mkdir -p $@

clean:
	@echo clean ...
	rm -rf build loadme.bin
