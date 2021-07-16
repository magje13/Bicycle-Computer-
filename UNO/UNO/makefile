CC=avr-gcc
CFLAGS=-mmcu=atmega328p
DEPS = atmega328p.h app.h systimer.h queue.h print.h uart2.h
OBJ = uno.o systimer.o queue.o print.o uart2.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

uno: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	avr-objcopy -j .text -j .data -O ihex uno uno.hex
