//090408_jykim_dvp_handshaking_head+
#include "i2s.h"
#include "gpio.h"
#include "interrupt_handler_gpio.h"

void GPIOIntEnable(INT32U type) {
	//Set Pin to Input
	GPIOSetInput(type);
	//RGPIO_INTE
	RGPIO_INTE |= type;
	//RGPIO_CTRL[INTE]
	RGPIO_CTRL = INTE | INTS;
	//RGPIO_PTRIG
	RGPIO_PTRIG |= type; //All Positive Edge
	//INTERRUPT CLEAR
	RGPIO_INTS &= ~0xffffffff;

}

void GPIOIntDisable(INT32U type) {
	//RGPIO_INTE
	RGPIO_INTE &= ~type;
	//INTERRUPT CLEAR
	RGPIO_INTS &= ~0xffffffff;
}

void IntHandlerGPIO(void) {

	INT32U gpio_int_flag = RGPIO_INTS;

	if (gpio_int_flag & GPIOINT0) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT0;

		//Service routine
	} else if (gpio_int_flag & GPIOINT1) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT1;

		//Service routine
	} else if (gpio_int_flag & GPIOINT2) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT2;

		//Service routine
	} else if (gpio_int_flag & GPIOINT3) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT3;

		//Service routine
	} else if (gpio_int_flag & GPIOINT4) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT4;

		//Service routine
	} else if (gpio_int_flag & GPIOINT5) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT5;

		//Service routine
	} else if (gpio_int_flag & GPIOINT6) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT6;

		//Service routine
	} else if (gpio_int_flag & GPIOINT7) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT7;

		//Service routine
	} else if (gpio_int_flag & GPIOINT8) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT8;

		//Service routine
	} else if (gpio_int_flag & GPIOINT9) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT9;

		//Service routine
	} else if (gpio_int_flag & GPIOINT10) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT10;

		//Service routine
	} else if (gpio_int_flag & GPIOINT11) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT11;

		//Service routine
	} else if (gpio_int_flag & GPIOINT12) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT12;

		//Service routine
	} else if (gpio_int_flag & GPIOINT13) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT13;

		//Service routine
	} else if (gpio_int_flag & GPIOINT14) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT14;

		//Service routine
	} else if (gpio_int_flag & GPIOINT15) {
		int temp;
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT15;

		if ( RGPIO_IN & GPIO15 )
		{
			temp = I2S_RxCnt;
			while(RGPIO_IN & GPIO15);
			while(!(RGPIO_IN & GPIO15));
			while(RGPIO_IN & GPIO15);
			I2S_RegSet(I2S_RxCR, I2S_En);
			GPIOIntDisable(GPIO15);
			IntDisable(AHB2APB_GPIO_INT_BIT);
		}
		//uart_print("i2s_en:");
		//uart_printInt(temp);
		//uart_print("\n\r");

		//Service routine
	} else if (gpio_int_flag & GPIOINT16) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT16;

		//Service routine
	} else if (gpio_int_flag & GPIOINT17) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT17;

		//Service routine
	} else if (gpio_int_flag & GPIOINT18) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT18;

		//Service routine
	} else if (gpio_int_flag & GPIOINT19) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT19;

		//Service routine
	} else if (gpio_int_flag & GPIOINT20) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT20;

		//Service routine
	} else if (gpio_int_flag & GPIOINT21) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT21;

		//Service routine
	} else if (gpio_int_flag & GPIOINT22) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT22;

		//Service routine
	} else if (gpio_int_flag & GPIOINT23) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT23;

		//Service routine
	} else if (gpio_int_flag & GPIOINT24) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT24;

		//Service routine
	} else if (gpio_int_flag & GPIOINT25) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT25;

		//Service routine
	} else if (gpio_int_flag & GPIOINT26) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT26;

		//Service routine
	} else if (gpio_int_flag & GPIOINT27) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT27;

		//Service routine
	} else if (gpio_int_flag & GPIOINT28) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT28;

		//Service routine
	} else if (gpio_int_flag & GPIOINT29) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT29;

		//Service routine
	} else if (gpio_int_flag & GPIOINT30) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT30;

		//Service routine
	} else if (gpio_int_flag & GPIOINT31) {
		//Interrupt Source Clear
		RGPIO_INTS &= ~GPIOINT31;

		//Service routine
	} else {
		//Interrupt Source Clear
		RGPIO_INTS &= ~0xffffffff;
	}
	return;
}

//090408_jykim_dvp_handshaking_tail+


