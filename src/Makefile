# The 3pi is running an atmega328p:
DEVICE = atmega328p
AVRDUDE_DEVICE = atmega328p
MCU = atmega328p

# Compiler Flags/Options:
CFLAGS=-g -Wall -mcall-prologues -mmcu=$(MCU) $(DEVICE_SPECIFIC_CFLAGS) -Os 

# AVR Compiler:
CC=avr-gcc

# Object Copy program:
OBJ2HEX=avr-objcopy

# Linker Flags/Options:
LDFLAGS=-Wl,-gc-sections -lpololu_$(DEVICE) -Wl,-relax

# AVRDude Binary:
AVRDUDE=avrdude

TARGET=main
OBJECT_FILES=main.o

all: $(TARGET).hex

clean:
	rm -rf *.o *.hex *.obj

%.hex: %.obj
	$(OBJ2HEX) -R .eeprom -O ihex $< $@

main.o: main.c

%.obj: $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) $(LDFLAGS) -o $@

# We have the hex file.  Flash it in via the USBTinyISP device:
program: $(TARGET).hex
	$(AVRDUDE) -c usbtiny -p $(AVRDUDE_DEVICE) -U flash:w:$(TARGET).hex
