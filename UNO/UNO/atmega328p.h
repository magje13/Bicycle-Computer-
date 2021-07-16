// -----------------------------------------------
// -- atmega328p.h
// -----------------------------------------------
// -- Part specific header file
// -- ..made for FIS, 2019
// -- Morten Hansen
// -----------------------------------------------

// Port B
// ------
#define PINB  (*(volatile unsigned char *)(0x23)) 
#define DDRB  (*(volatile unsigned char *)(0x24)) 
#define PORTB (*(volatile unsigned char *)(0x25))

// Port C
// ------
#define PINC  (*(volatile unsigned char *)(0x26)) 
#define DDRC  (*(volatile unsigned char *)(0x27)) 
#define PORTC (*(volatile unsigned char *)(0x28))

// Port D
// ------
#define PIND  (*(volatile unsigned char *)(0x29)) 
#define DDRD  (*(volatile unsigned char *)(0x2A)) 
#define PORTD (*(volatile unsigned char *)(0x2B))

#define TIFR2 (*(volatile unsigned char *)(0x37))

// Timer 0
// -------
#define GTCCR  (*(volatile unsigned char *)(0x43))

#define TCCR0A (*(volatile unsigned char *)(0x44))
#define TCCR0B (*(volatile unsigned char *)(0x45))
#define TCNT0  (*(volatile unsigned char *)(0x46))
#define OCR0A  (*(volatile unsigned char *)(0x47))
#define OCR0B  (*(volatile unsigned char *)(0x48))

// CPU registers
// -------------
#define SREG  (*(volatile unsigned char *)(0x5F))

// Interrupt masks
// ---------------
#define TIMSK2 (*(volatile unsigned char *)(0x70))

// AD-Converter
// ------------
#define ADCL   (*(volatile unsigned char *)(0x78))
#define ADCH   (*(volatile unsigned char *)(0x79))
#define ADCSRA (*(volatile unsigned char *)(0x7A))
#define ADCSRB (*(volatile unsigned char *)(0x7B))
#define ADMUX  (*(volatile unsigned char *)(0x7C))
#define DIDR0  (*(volatile unsigned char *)(0x7E))
#define DIDR1  (*(volatile unsigned char *)(0x7F))


// Timer 2
// -------
#define TCCR2A (*(volatile unsigned char *)(0xB0))
#define TCCR2B (*(volatile unsigned char *)(0xB1))
#define TCNT2  (*(volatile unsigned char *)(0xB2))
#define OCR2A  (*(volatile unsigned char *)(0xB3))
#define OCR2B  (*(volatile unsigned char *)(0xB4))
#define ASSR   (*(volatile unsigned char *)(0xB6))

// UART
// ----
#define UCSR0A (*(volatile unsigned char *)(0xC0))
#define UCSR0B (*(volatile unsigned char *)(0xC1))
#define UCSR0C (*(volatile unsigned char *)(0xC2))
#define UBRR0L (*(volatile unsigned char *)(0xC4))
#define UBRR0H (*(volatile unsigned char *)(0xC5))
#define UDR0   (*(volatile unsigned char *)(0xC6))

