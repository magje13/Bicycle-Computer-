// --------------------------------------------------
// uart.u                                     FIS/UNO
// 14.10.2019                                     MoH
// --------------------------------------------------

// --------------------------------------------------
// getUART
// Reads a character from the UART receiver, if any
// --------------------------------------------------
// Input: A pointer to a receive buffer
// Output: 1, if a character received.
//         0, if no character received.
// -------------------------------------------------- 
int getUART( unsigned char *pCh );

// --------------------------------------------------
// putUART
// sends a character to the UART transmitter, if 
//   the transmitter is ready.
// --------------------------------------------------
// Input:  The character to send.
// Output: 1, if character send.
//         0, if transmitter not ready.
// -------------------------------------------------- 
int putUART( unsigned char Ch );

// --------------------------------------------------
// initUART
// initialize the UART to 9600,8,1,n
// --------------------------------------------------
// Input:  -
// Output: -
// -------------------------------------------------- 
void initUART();


