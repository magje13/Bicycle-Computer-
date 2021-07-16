// --------------------------------------------------
// uart2.c (Version 2) Now with interrupt.    FIS/UNO
// 14.10.2019                                     MoH
// --------------------------------------------------
// 26.11.2019 Version 2
// --------------------------------------------------
#include <avr/io.h>
#include <avr/interrupt.h>
#include "app.h"
#include "queue.h"


int getUART( unsigned char *pCh )
{
  int Result = 0;

  if( UCSR0A & 0x80 )
  {
    *pCh = UDR0;
    Result = 1;
  }
  return( Result );
}

int putUART( unsigned char Ch )
{
  int Result = 0;

  if( UCSR0A & 0x20 )  // Transmit data register empty
  {
    UDR0 = Ch;
    Result = 1;
  }
  return( Result );
}

ISR( USART_RX_vect )
{
  putQueue( Q_IN, UDR0 );
}

ISR( USART_UDRE_vect )
{
  unsigned char Ch;

  if( getQueue( Q_OUT, &Ch ))
    UDR0 = Ch;
  else
    UCSR0B &= 0xDF;  // Disable Data Register Empty Interrupt ( bit5)
}

void initUART()
// -----------------------------------
// Initialize the UART
// -----------------------------------
{
  UBRR0H = 0;
  UBRR0L = 103;   // Baudrate = 9600.
  UCSR0C = 0x06;  // 8,1,n
  UCSR0B = 0x98;  // Enable receiver (bit4) and transmitter (bit3)
                  // Enable RX Interrupt (bit7)
}


