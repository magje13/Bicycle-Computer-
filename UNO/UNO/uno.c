// uno.c
// Main function.

#include "atmega328p.h"
#include "app.h"
#include "systimer.h"
#include "queue.h"
#include "print.h"
#include "uart2.h"
#include <avr/io.h>

void readMagnet(){
  
  static int state = 0;
  static unsigned int timer = 0;

  // This is the maximum value for timer variable. The cyclist must have fallen of the bike by then :-)
  if(timer != 65535)
    timer++;

  // Finite State machine.
  switch (state)
  {
  case 0:  // no magnet
    if(!(PIND & (1<<PD2))){   // State change: magnet present
      state = 1;
      }
    break;
  case 1:  // magnet
    if(PIND & (1<<PD2)){  // State change: NO magnet present
      state = 0;
      printInt(timer,5);
      printStr("\r\n");
      timer = 0;
      }
    break;
  }

}

void initialize(){

  // Initialize GPIOs
  DDRD &= ~(1 << PD2);     //Sets the data direction for digital Pin 2 to input.
  initSystimer( 5000 );
  initUART();
}

void main()
{
  initialize();

  //Super loop
  while( 1 )
  {
    while( !Ticks );         // Runs every 5 ms.
      Ticks--;
    readMagnet();

  }
}

