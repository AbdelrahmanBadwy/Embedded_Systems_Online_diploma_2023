#Abdelrahman El-Badawy --Makefile--
#30/8/2023
# Compiler settings
CC = arm-none-eabi-
CFLAGS = -c -mcpu=cortex-m3 -g
INCS =-I .
# Source files and target executable
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As =  $(wildcard *.s)
AsOBJ = $(As:.s=.o)
EXECUTABLE = lab2_lesson3

# Default target
all: $(EXECUTABLE).bin
	@echo "=============Done=============="

# Compile source files to object files
%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) $< -o $@

# Link object files to create executable
$(EXECUTABLE).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map
	
$(EXECUTABLE).bin: $(EXECUTABLE).elf
	$(CC)objcopy.exe -O binary $<  $@

# Clean up compiled files
clean_all:
	rm -f *.o *.elf *.bin
clean:
	rm -f *.elf *.bin