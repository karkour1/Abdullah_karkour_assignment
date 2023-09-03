#make file prepared by Eng.abdullah karkour

CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m4 -gdwarf-2 -g
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
AS= $(wildcard *.s)
ASOBJ= $(AS:.s=.o)
project_name=Lab4_cortexM4
all: $(project_name).bin

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@


$(project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(ASOBJ) -o $(project_name).elf -Map=Map_file.map
	cp $(project_name).elf $(project_name).axf
$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $(project_name).elf $(project_name).bin
	
clean:
	rm *.elf *.bin
	
clean_all:
	rm *.o *.elf *.bin *.map