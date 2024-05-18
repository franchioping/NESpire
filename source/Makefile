PREFIX=nspire-

all: nes_emu.tns clean_p
	@echo DONE

nes_emu.tns : nespire.elf
	genzehn --input $< --output $@ --name "nes_emu"
	make-prg $@ ./nes_emu.prg.tns

nespire.elf : main.o cpu.o debug.o memory.o ppu.o rom.o menu.o
	$(PREFIX)ld main.o cpu.o debug.o memory.o ppu.o rom.o menu.o -o $@

%.o : %.S
	$(PREFIX)gcc  -Wall -W -marm -Os -c $< -o $@


clean_p: 
	@rm -f *.o nespire.elf


clean: clean_p
	@rm -f nes_emu.tns nes_emu.prg.tns
