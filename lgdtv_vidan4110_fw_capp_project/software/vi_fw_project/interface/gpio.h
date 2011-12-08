//090408_jykim_dvp_handshaking_head+
#ifndef _GPIO_H_
#define _GPIO_H_

#include "map.h"

#define GPIO0  	( 1 <<  0 )
#define GPIO1   	( 1 <<  1 ) 
#define GPIO2    	( 1 <<  2 )
#define GPIO3    	( 1 <<  3 )
#define GPIO4    	( 1 <<  4 )
#define GPIO5    	( 1 <<  5 )
#define GPIO6    	( 1 <<  6 )
#define GPIO7    	( 1 <<  7 )
#define GPIO8    	( 1 <<  8 )
#define GPIO9    	( 1 <<  9 )
#define GPIO10  	( 1 << 10 )
#define GPIO11   	( 1 << 11 ) 
#define GPIO12    ( 1 << 12 )
#define GPIO13    ( 1 << 13 )
#define GPIO14    ( 1 << 14 )
#define GPIO15    ( 1 << 15 )
#define GPIO16    ( 1 << 16 )
#define GPIO17    ( 1 << 17 )
#define GPIO18    ( 1 << 18 )
#define GPIO19    ( 1 << 19 )
#define GPIO20  	( 1 << 20 )
#define GPIO21   	( 1 << 21 ) 
#define GPIO22    ( 1 << 22 )
#define GPIO23    ( 1 << 23 )
#define GPIO24    ( 1 << 24 )
#define GPIO25    ( 1 << 25 )
#define GPIO26    ( 1 << 26 )
#define GPIO27    ( 1 << 27 )
#define GPIO28    ( 1 << 28 )
#define GPIO29    ( 1 << 29 )
#define GPIO30  	( 1 << 30 )
#define GPIO31   	( 1 << 31 ) 

void GPIOInit(void);
void GPIOSetInput(unsigned int type);
void GPIOSetOutput(unsigned int type);
void GPIOSetHigh(unsigned int type);
void GPIOSetLow(unsigned int type);
int readGPIO(int idx);

#endif

//090408_jykim_dvp_handshaking_tail+

