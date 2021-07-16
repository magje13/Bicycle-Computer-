//--------------------------
// queue.c
// -------------------------
#include "atmega328p.h" 
#include "queue.h"

#define MAX_QUEUES        8
#define MAX_QUEUE_SIZE  128

typedef struct
{
  unsigned char iHead;
  unsigned char iTail;
  unsigned char len;
  unsigned char data[MAX_QUEUE_SIZE];
} queue_descriptor;

queue_descriptor pofQueues[MAX_QUEUES];

int openQueue( int id )
{
  if( id < MAX_QUEUES )
  {
    pofQueues[id].iHead = 0;
    pofQueues[id].iTail = 0;
    pofQueues[id].len = 0;
  }
  else
    id = Q_ILLEGAL;
  return( id );
}

int getQueue( int id, unsigned char *pCh )
{
  int Result = 0;
  
  if( id < MAX_QUEUES )
  {
    if( pofQueues[id].len )
    {
      *pCh = pofQueues[id].data[pofQueues[id].iHead];
      pofQueues[id].iHead++;
      if( pofQueues[id].iHead >= MAX_QUEUE_SIZE )
        pofQueues[id].iHead = 0;
      pofQueues[id].len--;
	  Result = 1;
    }
  }
  return( Result );
}

int putQueue( int id, unsigned char Ch )
{
  int Result = 0;
  
  if( id < MAX_QUEUES )
  {
    if( pofQueues[id].len < MAX_QUEUE_SIZE )
    {
      pofQueues[id].data[pofQueues[id].iTail] = Ch;
      pofQueues[id].iTail++;
      if( pofQueues[id].iTail >= MAX_QUEUE_SIZE )
        pofQueues[id].iTail = 0;
      pofQueues[id].len++;
      Result = 1;
    }
  }
  return( Result );
}

