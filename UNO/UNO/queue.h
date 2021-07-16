//-----------------------------
// queue.h
// ----------------------------

# define Q_ILLEGAL   -1

//  ---------------------------
//  Open queue.
//  ---------------------------
//  Input:
//  Queue ID
//  Output:
//    Queue ID; if ID ok
//    Q_ILLEGAL; if illegal ID
//  ---------------------------
int openQueue( int );



//  ---------------------------
//  Get queue.
//  Get a character if any
//  ---------------------------
//  Input:
//    Queue ID
//    Pointer to destination
//  Output:
//    1; if character ok
//    0; if no character or 
//       illegal queue ID
//  ---------------------------
int getQueue( int, unsigned char* );


//  ---------------------------
//  putQueue.
//  Put a character if space
//  ---------------------------
//  Input:
//    Queue ID
//    The character
//  Output:
//    1; character send
//    0; if no space or 
//       illegal queue ID
//  ---------------------------
int putQueue( int, unsigned char );
