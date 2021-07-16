// -----------------------------------------------
// -- systimer.h                           FIS/UNO
// -- 03.10.2019                               MoH
// -----------------------------------------------

extern volatile unsigned int Ticks;
 
// -----------------------------------------------
// Initialise systimer.
// Set up timer 2 and enable systimer interrupt.
// The interrupt will increment Ticks.
// -----------------------------------------------
// Input: systimer interrupt period in micro sec.
// -----------------------------------------------
void initSystimer( unsigned long );
// -----------------------------------------------
