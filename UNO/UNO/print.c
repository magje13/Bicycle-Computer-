// print.c
// 14.10.2019                 MoH
// -------------------------------
// 22.11.2019 Error in printInt 
//            (number of digits) 
//            is corrected.
// 26.11.2019 Enable interrupt in 
//            printCh.
// -------------------------------    
#include "atmega328p.h"
#include "app.h"
#include "queue.h"

void printCh( unsigned char Ch )
{
  putQueue( Q_OUT, Ch );
  UCSR0B |= 0x20;        // Enable Data Rdegister Empty Interrupt.
}

void printStr( unsigned char *pStr )
{
  while( *pStr )
    printCh( *pStr++ );
}

void printInt( unsigned int Value, unsigned int Digits )
{
  int Power = 1;

  if( Digits > 0 )
  {
    while( --Digits )
      Power *= 10;
    while( Power )
    {
      printCh( (unsigned char)(Value / Power + '0' ));
      Value %= Power;
      Power /= 10;
    }
  }
}

