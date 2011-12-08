//090408_jykim_dvp_handshaking_head+
#include "gpio.h"

void GPIOInit(void) {
	//Initialize GPIO pin as input
	RGPIO_OE = 0xffffffff; //oe is reversed because of pad
}

void GPIOSetInput(unsigned int type) {
	RGPIO_OE |= type;
}

void GPIOSetOutput(unsigned int type) {
	RGPIO_OE &= ~type;
}

void GPIOSetHigh(unsigned int type) {
	RGPIO_OUT |= type;
}

void GPIOSetLow(unsigned int type) {
	RGPIO_OUT &= ~type;
}

int readGPIO(int idx) {
	return (RGPIO_IN & (1 << idx));
}

//090408_jykim_dvp_handshaking_tail+


