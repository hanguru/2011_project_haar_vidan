//090408_jykim_dvp_handshaking_head+
#ifndef _INTERRUPT_HANDLER_GPIO_H_
#define _INTERRUPT_HANDLER_GPIO_H_

#include "interrupt_handler.h"

/**************************************************************
 *                                                            *
 *                 GPIO Interrupt Source                      *
 *                                                            *
 *   interrupt source    : 32bit                              *
 *                                                            *
 **************************************************************/
#define GPIOINT0  	( 1 <<  0 )
#define GPIOINT1   	( 1 <<  1 ) 
#define GPIOINT2    	( 1 <<  2 )
#define GPIOINT3    	( 1 <<  3 )
#define GPIOINT4    	( 1 <<  4 )
#define GPIOINT5    	( 1 <<  5 )
#define GPIOINT6    	( 1 <<  6 )
#define GPIOINT7    	( 1 <<  7 )
#define GPIOINT8    	( 1 <<  8 )
#define GPIOINT9    	( 1 <<  9 )
#define GPIOINT10  	( 1 << 10 )
#define GPIOINT11   	( 1 << 11 ) 
#define GPIOINT12    ( 1 << 12 )
#define GPIOINT13    ( 1 << 13 )
#define GPIOINT14    ( 1 << 14 )
#define GPIOINT15    ( 1 << 15 )
#define GPIOINT16    ( 1 << 16 )
#define GPIOINT17    ( 1 << 17 )
#define GPIOINT18    ( 1 << 18 )
#define GPIOINT19    ( 1 << 19 )
#define GPIOINT20  	( 1 << 20 )
#define GPIOINT21   	( 1 << 21 ) 
#define GPIOINT22    ( 1 << 22 )
#define GPIOINT23    ( 1 << 23 )
#define GPIOINT24    ( 1 << 24 )
#define GPIOINT25    ( 1 << 25 )
#define GPIOINT26    ( 1 << 26 )
#define GPIOINT27    ( 1 << 27 )
#define GPIOINT28    ( 1 << 28 )
#define GPIOINT29    ( 1 << 29 )
#define GPIOINT30  	( 1 << 30 )
#define GPIOINT31   	( 1 << 31 ) 

#define INTE			( 1 << 0 )
#define INTS			( 1 << 1 )

/*
 * GPIO Interrupt Handler
 */

void GPIOIntEnable(INT32U type);
void GPIOIntDisable(INT32U type);
void IntHandlerGPIO(void);

#endif

//090408_jykim_dvp_handshaking_tail+


