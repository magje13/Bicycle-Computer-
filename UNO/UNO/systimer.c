// ----------------------------------------------
// systimer.c                            FIS/UNO
// 03.10.2019                                MoH
// ----------------------------------------------
#include <avr/io.h>
#include <avr/interrupt.h>
#include "print.h"

volatile unsigned int Ticks = 0;

void initSystimer( unsigned long MicroSec ) 
{
  long CounterValue;

  TCCR2A = 0x02;       // Timer 2 mode = CTC, Clear Timer on Compare
  TCCR2B = 0x07;       // Prescaler = 1024 => 15625 Hz
                       // 16 [MHz] * MicroSec / Prescaler
  CounterValue  = (16*MicroSec) / 1024;      // Ex. 78 for 5mS
  OCR2A  = (unsigned char)CounterValue;      // 
  TIMSK2 = 0x02;       // Enable interrupt on A match
  SREG  |= 0x80;       // Enable global interrupt
}

ISR(TIMER2_COMPA_vect)
{
  Ticks++;
}
