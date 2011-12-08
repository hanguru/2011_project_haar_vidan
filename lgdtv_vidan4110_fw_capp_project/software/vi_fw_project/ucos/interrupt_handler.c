#include "map.h"
#include "map_hif.h"
#include "interrupt_handler.h"
#include "interrupt_handler_gpio.h"
#include "task_manage.h"

#include "tube.h" //jykim_debug
#include "uart.h" 
#include "i2s.h"	//090324_hunnoh_i2s+
#include "usb.h"	//090324_hunnoh_i2s+
INT32U int_flag = 0;

/**************************************************************
 *                                                            *
 *                 Timer Interrupt Function                   *
 *                                                            *
 **************************************************************/
void OpenRiscEnableTimerInt(INT32U tick) {
	//Make Counter Zero
	mtspr(SPR_TTCR, 0);
	//SPR_TTMR Setting
	//SPR_TTMR(M) : 0x1
	//SPR_TTMR(IE) : enable
	//SPR_TTMR(TP) : mask to 28 bit
	mtspr(SPR_TTMR, (TTMR_M(0x1) | TTMR_IE | (tick & TTMR_TPMASK)));
	//Timer Interrupt Enable
	mtspr(SPR_SR, mfspr(SPR_SR) | SR_TEE);
}

void OpenRiscDisableTimerInt(void) {
	//Make Counter Zero
	mtspr(SPR_TTCR, 0);
	//SPR_TTMR Setting
	//SPR_TTMR(M) : 0x0
	//SPR_TTMR(IE) : disable
	//SPR_TTMR(TP) : mask to 28 bit
	mtspr(SPR_TTMR, 0);
	//Timer Interrupt Disable
	mtspr(SPR_SR, mfspr(SPR_SR) & ~SR_TEE);
}

void OpenRiscTimerRestart(void) {
	mtspr(SPR_TTMR, (mfspr(SPR_TTMR) & ~TTMR_M(0x3)) | TTMR_M(0x1));
}

void OpenRiscTimerPause(void) {
	mtspr(SPR_TTMR, mfspr(SPR_TTMR) & ~TTMR_M(0x3));
}

/**************************************************************
 *                                                            *
 *               External Interrupt Function                  *
 *                                                            *
 **************************************************************/
void OpenRiscEnableInt(void) {
	//External Interrupt Enable
	mtspr(SPR_SR, mfspr(SPR_SR) | SR_IEE);
	return;
}

void OpenRiscDisableInt(void) {
	//External Interrupt Disable
	mtspr(SPR_SR, mfspr(SPR_SR) & ~SR_IEE);
	return;
}

void IntEnable(INT32U type) {
	//Extenal Interrupt Mask
	mtspr(SPR_PICMR, mfspr(SPR_PICMR) | (type));
	return;
}

void IntDisable(INT32U type) {
	//Extenal Interrupt Mask
	mtspr(SPR_PICMR, mfspr(SPR_PICMR) & ~(type));
	return;
}

/**************************************************************
 *                                                            *
 *               Interrupt Handler Function                   *
 *                                                            *
 * Clearing Timing of SPR_PICSR is little bit delayed.        *
 *                                                            *
 * If this causes interrupt nesting problem, this code has to *
 *  be moved to assembly file.                                *
 *                                                            *
 * Interrupt Clear Sequence :                                 *
 *   Src(device) clear -> PICSR(interrupt Status) clear       *
 *   If picsr is cleared before interrupt source,             *
 *   picsr is not cleared correctly.                          *
 *                                                            *
 **************************************************************/

void IntHandler(void) {

	int_flag = mfspr(SPR_PICSR);
	if (int_flag & I2S_RX_IRQ_BIT) {
		//i2s Interrupt
		i2s_interrupt_handler(); 
		//Interrupt Status Clear
		mtspr(SPR_PICSR, int_flag & ~I2S_RX_IRQ_BIT);
	} else if (int_flag & AHB2APB_GPIO_INT_BIT) {
		//Interrupt Source Clear
		IntHandlerGPIO();
		//Interrupt Status Clear
		mtspr(SPR_PICSR, int_flag & ~AHB2APB_GPIO_INT_BIT);
	} else if (int_flag & WDT_WB_INT_BIT) { //wdt
		//Interrupt Source Clear
		wdt_interrupt_handler();
		//Interrupt Status Clear
		//uart_print("wdt clear\n\r");
		mtspr(SPR_PICSR, int_flag & ~WDT_WB_INT_BIT);
	} else if (int_flag & USB_DEV_INTA_O_BIT) {
		//Interrupt Source Clear
		usb_interrupt_handler();
		//Interrupt Status Clear
		mtspr(SPR_PICSR, int_flag & ~USB_DEV_INTA_O_BIT);
	} else {
		uart_print("UNDEFINED INT\n");
		//Interrupt Status Clear
		mtspr(SPR_PICSR, 0); //All Clear
	}

   __asm __volatile("l.nop   0");
   __asm __volatile("l.nop   0");
   __asm __volatile("l.nop   0");
   __asm __volatile("l.nop   0");
   __asm __volatile("l.nop   0");
   __asm __volatile("l.nop   0");
   __asm __volatile("l.nop   0");
   __asm __volatile("l.nop   0");
   __asm __volatile("l.nop   0");
	return;
}

