#ifndef DEBUG_H_
#define DEBUG_H_

#include <stdio.h>

extern int dbg;

#define  _DBGP( flag, p )  do {if (flag) fprintf( stderr, "%s(%d): %s = 0x%p\n", __FILE__, __LINE__, #p, p );} while(0);


#endif // DEBUG_H_
