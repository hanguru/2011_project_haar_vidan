#include "map_hif.h"
#include "task_manage.h" //jykim_080725_ucos_porintg++
#include "interrupt_handler.h" //jykim_080725_ucos_porintg++
#include "cpm.h"
#include "sdram_control.h"
#include "uart.h"
#include "i2s.h" //090324_hunnoh_i2s+
#include "interrupt_handler_gpio.h" //090408_jykim_dvp_handshaking+
#include "gpio.h" //090408_jykim_dvp_handshaking+
#include "usb.h"
#include "AIC3101.h"
#include "flash_operation.h"
#include "i2c_operation.h"
#include "i2s.h"
#include "sensor_set.h"

//090409_hunnoh_product_id_head+
#define SET_PID(_X_) ( PID_0 = (_X_ & 0x000000ff) >> 0  ); \
 					 ( PID_1 = (_X_ & 0x0000ff00) >> 8  ); \
					 ( PID_2 = (_X_ & 0x00ff0000) >> 16 ); \
					 ( PID_3 = (_X_ & 0xff000000) >> 24 ) 
//090409_hunnoh_product_id_tail+

unsigned char avata_capture_mode = 0;

extern int lencod(void); //jykim_080725_ucos_porintg-- 
extern void ParamToHIFConv(void);
//jykim_080725_ucos_porintg_head++
//Main + H264Encoder Task Create
void MainTaskCreate(void);
OS_STK main_stack[MAIN_TASK_STACK_SIZE];
void main_task(void *data);

void InterruptControl(void); //jykim_080730_default_interrupt_disable++

unsigned int calulate_system_clock(void) {
	// FOUT = {(feedback+2) x FIN} / {(input+2)x2**output}
	return (((PLL_FEEDBACK_DIV_VALUE + 2) * (PLL_INPUT_CLOCK_VALUE
			/ (SYS_CLK_DIV_VALUE + 1))) / ((PLL_INPUT_DIV_VALUE + 2) * (1
			<< PLL_OUTPUT_DIV_VALUE)));
}

unsigned int uart_baud_rate(void) {
	unsigned int baud_rate = 38400;
	if (UART_BAUD_RATE_SEL == UART_BAUD_RATE_SEL_HIF) {
		switch (UART_BAUD_RATE_VALUE) {
		case UART_BAUD_RATE_VALUE_4800:
			baud_rate = 4800;
			break;
		case UART_BAUD_RATE_VALUE_9600:
			baud_rate = 9600;
			break;
		case UART_BAUD_RATE_VALUE_14400:
			baud_rate = 14400;
			break;
		case UART_BAUD_RATE_VALUE_19200:
			baud_rate = 19200;
			break;
		case UART_BAUD_RATE_VALUE_38400:
			baud_rate = 38400;
			break;
		case UART_BAUD_RATE_VALUE_57600:
			baud_rate = 57600;
			break;
		case UART_BAUD_RATE_VALUE_115200:
			baud_rate = 115200;
			break;
		case UART_BAUD_RATE_VALUE_128000:
			baud_rate = 128000;
			break;
		default:
			baud_rate = 38400;
		}
	}
	return baud_rate;
}

int main(void) {
	SET_PID(0x04100948); //090409_hunnoh_product_id+

	uart_init_param(calulate_system_clock(), uart_baud_rate());


	CHIP_STATUS |= CHIP_READY_BIT;

	//audio_init();

	//GPIOInit(); //declare before interrupt control //090408_jykim_dvp_handshaking+

	OpenRiscEnableInt();
	OpenRiscEnableTimerInt(0x0fffffff);

	OSInit();

	InterruptControl();

	MainTaskCreate();

	OSStart();

	//Never Reach
	return 0;
}

void MainTaskCreate(void) {
	OSTaskCreate(main_task, (void *) 0, &main_stack[MAIN_TASK_STACK_SIZE - 1],
			MAIN_TASK_PRIO);
	return;
}

//jykim_080730_default_interrupt_disable_head++
void InterruptControl(void) {
	/*Timer Interrupt Setting*/
	if (TIMER_INT_ENABLE) {
		OpenRiscEnableTimerInt(TIMER_INT_PERIOD_VALUE);//(0xfff : 4096 clk)
	} else {
		OpenRiscDisableTimerInt();
	}

	/*Extenal Interrupt Setting*/
	IntDisable(0xffffffff);
	IntEnable(INTERRUPT_CONTROL_VALUE);

	//090408_jykim_dvp_handshaking_head+
	//GPIO Interrupt Enable
	if (INTERRUPT_CONTROL_VALUE & AHB2APB_GPIO_INT_BIT) {
		GPIOIntEnable(GPIO14 | GPIO15);
	}
	//090408_jykim_dvp_handshaking_tail+
}
//jykim_080730_default_interrupt_disable_tail++

void main_task(void *data) {
	int nop_i;
	//char tempBuf[256];
	//int ret;

	//uart_print("SCLK:");
	//uart_printInt(calulate_system_clock());
	//uart_print("\n\r");

	//while(1);
	//OM_SELECT : //I2C MASTER[4], UPHY_IN_REG
	//OM_SELECT |= ( OM_SELECT_I2C_M_SELECT_BIT | OM_SELECT_UPHY_IN_REG_BIT );
	OM_SELECT |= ( OM_SELECT_I2C_M_SELECT_BIT );
 	for ( nop_i = 0; nop_i < 100000; nop_i++ ) __asm __volatile("l.nop   0");

	
	//usb init
	init_usb();

	//sensorSetToVGA();

	//GPIO init
	GPIOInit();
	//GPIO12 : LED
	//GPIO13 : AIC RESET
	//GPIO14 : Dummy
	//GPIO15 : I2S_WS
	GPIOSetOutput(GPIO12|GPIO13|GPIO14); // ViDan -> ...
	GPIOSetInput(GPIO15);

	GPIOSetHigh(GPIO12);

	//i2c devider setting
	I2C_M_PRESCALE_LOW = 0x62;
	I2C_M_PRESCALE_HIGH =0x00;

	//i2c init
	i2c_init();
	//uart_print("i2c_initialized\n\r");

	//flash_avata_mode_check();

	//temporary vidan register setting //h.264 only
	//*HIF_REG2   = 0x28; //HIF_REG2   ;640 / 16 ;HIF_REG
	//*HIF_REG3   = 0x1e; //HIF_REG3   ;480 / 16
	//*HIF_REG4   = 0x28; //HIF_REG4   ;640 / 16
	//*HIF_REG5   = 0x1e; //HIF_REG5   ;480 / 16
	//*HIF_REG6   = 0x45; //HIF_REG6   ; for jpeg 20 ;DVP_OUT 60 ;OUTPUT_PATH : 11(sim) 66:jpeg only
	//*HIF_REG10  = 0x22; //HIF_REG10  ;start Mux
	*HIF_REG24  = 0x33; //HIF_REG24  ;qp value i : 28 1c
	*HIF_REG25  = 0x33; //HIF_REG25  ;qp value p : 28 1c
	//*HIF_REG26  = 0x64; //HIF_REG26  ;intra period : 10 0a
	*HIF_REG26  = 0x00; //HIF_REG26  ;intra period : 10 0a
	//*HIF_REG31  = 0x02; //HIF_REG31  ;#############rate control disable 02
	//*HIF_REG31  = 0x00; //HIF_REG31  ;#############rate control disable 02
	//*HIF_REG54  = 0x44; //HIF_REG54  ;no fastme defined in user.mk slice mode 02
	//*HIF_REG55  = 0x10; //HIF_REG55  ;#############safe_mode on [4] , frame_rate_control on[5], audio start[6] 50
	*HIF_REG194 = 0x16; //HIF_REG194 ;afifo_almost_full_size (max = 512 / 16 - 1)
	//*HIF_REG57  = 0xab; //HIF_REG57  ;slice_argument : 12
	*HIF_REG58  = 0xfe; //HIF_REG58  ;LFAlphaC0Offset : -2
	*HIF_REG59  = 0xff; //HIF_REG59  ;LFBetaOffset : -1
	*HIF_REG66  = 0x20; //HIF_REG66  ;rate control bit rate :  51200 / 1024 ( 50k)
	*HIF_REG67  = 0x00; //HIF_REG67  ;rate control bit rate :  51200 / 1024 ( 50k)
	*HIF_REG68  = 0x0f; //HIF_REG68  ;rate control frame rate : 11
	*HIF_REG69  = 0x31; //HIF_REG69  ;osb_fifo_rate_idx : 0, RATE_CONTROL_SEINITIAL_QP_VALUE : 0
	//*HIF_REG70  = 0xe8; //HIF_REG70  ;SPEED_CONTROL_MB_CYCLE_VALUE : 1000
	//*HIF_REG71  = 0x03; //HIF_REG71  ;SPEED_CONTROL_MB_CYCLE_VALUE : 1000
	*HIF_REG50  = 0x32; //HIF_REG50  ; quality factor 30
	*HIF_REG60  = 0x21; //HIF_REG60  ; i2s_ctrl
	*HIF_REG63  = 10; //HIF_REG63  ; audio_gain
	//*HIF_REG64 = 0; //Zoom Level : 0
	
	// Never set SDRAM registers here!!!
	// If you set, SDRAM module will Die ... 
	//*HIF_REG140  = 0xcb;	//0xea;  //HIF_REG40 SDRAMC
	//*HIF_REG141  = 0x30;	//0x40;  //HIF_REG41 SDRAMC
	//*HIF_REG142  = 0x4b;	//0x8c;  //HIF_REG42 SDRAMC
	//*HIF_REG143  = 0x12;	//0x02;  //HIF_REG43 SDRAMC
	//*HIF_REG143  = *HIF_REG143 & (0xef);
	
	
	CONSTANT_QP_VALUE = 32;
	MAX_BIT_RATE_LOW = 0xB0;
	MAX_BIT_RATE_HIGH = 0x04;
	JPEG_FPS = 15;

	//if ( avata_capture_mode )
	//{
	//	uart_print("avata_capture_mode\n\r");
	//	//Sensor2 Setting
	//	*HIF_REG74 = 0x1e; //SENSOR2_OUT_W
	//	*HIF_REG75 = 0x1e; //SENSOR2_OUT_H
	//	*HIF_REG76 = 0x0f; //IMAGE2_OUT_W
	//	*HIF_REG77 = 0x0f; //IMAGE2_OUT_H
	//	*HIF_REG51 = 0x0f; //HIF_REG51  ; jpeg width
	//	*HIF_REG52 = 0x0f; //HIF_REG52  ; jpeg height
	//}
	//else //normal mode
	//{
	//	//Sensor2 Setting
	//	*HIF_REG74 = 0x28; //SENSOR2_OUT_W
	//	*HIF_REG75 = 0x1e; //SENSOR2_OUT_H
	//	*HIF_REG76 = 0x28; //IMAGE2_OUT_W
	//	*HIF_REG77 = 0x1e; //IMAGE2_OUT_H
	//	*HIF_REG51 = 0x14; //HIF_REG51  ; jpeg width
	//	*HIF_REG52 = 0x0f; //HIF_REG52  ; jpeg height
	//}
	//*HIF_REG102 = 0x80; //JPEG from CAM2

	//uart_print("hif_initialized\n\r");

//	if ( !avata_capture_mode )
//	{
//// {{{
//	//Sensor Setting
//	//Sensor Reset
//	tempBuf[0] = 0x30;
//	tempBuf[1] = 0x12;
//	tempBuf[2] = 0x80;
//	ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//	//uart_print("ret:");
//	//uart_printInt(ret);
//	//uart_print("\n\r");
//
// 	for ( nop_i = 0; nop_i < 10000000; nop_i++ ) __asm __volatile("l.nop   0");
//
//	////read Sensor ID
//	//tempBuf[0] = 0x30;
//	//tempBuf[1] = 0x0a;
//	//ret = i2c_write(0x30, 2, tempBuf);
//	////uart_print("ret:");
//	////uart_printInt(ret);
//	////uart_print("\n\r");
//	//ret = i2c_read(0x30, 2, tempBuf);
//	//uart_print("read id ret:");
//	//uart_printInt(ret);
//	//uart_print(",");
//	//uart_printInt(tempBuf[0]);
//	//uart_print(",");
//	//uart_printInt(tempBuf[1]);
//	//uart_print("\n\r");
//	////read Sensor ID
//	for ( nop_i = 0; nop_i < 3; nop_i++ )
//	{
//// {{{
//		tempBuf[0] = 0x30; tempBuf[1] = 0x8c; tempBuf[2] = 0x80; 
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x8d; tempBuf[2] = 0x0e;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x36; tempBuf[1] = 0x0b; tempBuf[2] = 0x00;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0xb0; tempBuf[2] = 0xff;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0xb1; tempBuf[2] = 0xff;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0xb2; tempBuf[2] = 0x04;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x0e; tempBuf[2] = 0x34;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x0f; tempBuf[2] = 0xa6;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x10; tempBuf[2] = 0x81;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x82; tempBuf[2] = 0x01;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0xf4; tempBuf[2] = 0x01;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x90; tempBuf[2] = 0x43;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x91; tempBuf[2] = 0xc0;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0xac; tempBuf[2] = 0x42;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0xd1; tempBuf[2] = 0x08;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0xa8; tempBuf[2] = 0x54;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x15; tempBuf[2] = 0x02;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x93; tempBuf[2] = 0x00;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x7e; tempBuf[2] = 0xe5;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x79; tempBuf[2] = 0x00;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0xaa; tempBuf[2] = 0x52;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x17; tempBuf[2] = 0x40;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0xf3; tempBuf[2] = 0x83;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x6a; tempBuf[2] = 0x0c;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x6d; tempBuf[2] = 0x00;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x6a; tempBuf[2] = 0x3c;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x76; tempBuf[2] = 0x6a;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0xd9; tempBuf[2] = 0x95;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x16; tempBuf[2] = 0x82;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x36; tempBuf[1] = 0x01; tempBuf[2] = 0x30;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x4e; tempBuf[2] = 0x88;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0xf1; tempBuf[2] = 0x82;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x6f; tempBuf[2] = 0x14;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x2a; tempBuf[2] = 0x02;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x2b; tempBuf[2] = 0x6a;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x12; tempBuf[2] = 0x10;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x11; tempBuf[2] = 0x00;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x13; tempBuf[2] = 0xf7;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x18; tempBuf[2] = 0x80;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x19; tempBuf[2] = 0x70;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x1a; tempBuf[2] = 0xd4;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x1c; tempBuf[2] = 0x13;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x1d; tempBuf[2] = 0x17;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x70; tempBuf[2] = 0x5d;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x72; tempBuf[2] = 0x4d;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0xaf; tempBuf[2] = 0x00;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x48; tempBuf[2] = 0x1f;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x49; tempBuf[2] = 0x4e;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x4a; tempBuf[2] = 0x20;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x4f; tempBuf[2] = 0x20;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x4b; tempBuf[2] = 0x02;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x4c; tempBuf[2] = 0x00;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x4d; tempBuf[2] = 0x02;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x4f; tempBuf[2] = 0x20;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0xa3; tempBuf[2] = 0x10;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x13; tempBuf[2] = 0xf7;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x14; tempBuf[2] = 0x44;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x71; tempBuf[2] = 0x00;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x70; tempBuf[2] = 0x5d;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x73; tempBuf[2] = 0x00;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x72; tempBuf[2] = 0x4d;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x1c; tempBuf[2] = 0x05;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x1d; tempBuf[2] = 0x06;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x4d; tempBuf[2] = 0x42;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x4a; tempBuf[2] = 0x40;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x4f; tempBuf[2] = 0x40;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x95; tempBuf[2] = 0x07;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x96; tempBuf[2] = 0x16;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x97; tempBuf[2] = 0x1d;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x20; tempBuf[2] = 0x01;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x21; tempBuf[2] = 0x18;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x22; tempBuf[2] = 0x00;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x23; tempBuf[2] = 0x06;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x24; tempBuf[2] = 0x06;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x25; tempBuf[2] = 0x58;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x26; tempBuf[2] = 0x02;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x27; tempBuf[2] = 0x61;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x88; tempBuf[2] = 0x02;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x89; tempBuf[2] = 0x80;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x8a; tempBuf[2] = 0x01;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x8b; tempBuf[2] = 0xe0;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x16; tempBuf[2] = 0x64;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x17; tempBuf[2] = 0x25;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x18; tempBuf[2] = 0x80;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x19; tempBuf[2] = 0x08;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x1a; tempBuf[2] = 0x28;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x1b; tempBuf[2] = 0x1e;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x1c; tempBuf[2] = 0x00;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x1d; tempBuf[2] = 0x38;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x31; tempBuf[1] = 0x00; tempBuf[2] = 0x00;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x20; tempBuf[2] = 0xfa;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x21; tempBuf[2] = 0x11;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x22; tempBuf[2] = 0x92;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x23; tempBuf[2] = 0x01;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x24; tempBuf[2] = 0x97;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x25; tempBuf[2] = 0x02;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x26; tempBuf[2] = 0xff;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x27; tempBuf[2] = 0x10;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x28; tempBuf[2] = 0x10;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x29; tempBuf[2] = 0x1f;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x2a; tempBuf[2] = 0x58;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x2b; tempBuf[2] = 0x50;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x2c; tempBuf[2] = 0xbe;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x2d; tempBuf[2] = 0xce;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x2e; tempBuf[2] = 0x2e;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x2f; tempBuf[2] = 0x36;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x30; tempBuf[2] = 0x4d;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x31; tempBuf[2] = 0x44;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x32; tempBuf[2] = 0xf0;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x33; tempBuf[2] = 0x0a;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x34; tempBuf[2] = 0xf0;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x35; tempBuf[2] = 0xf0;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x36; tempBuf[2] = 0xf0;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x37; tempBuf[2] = 0x40;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x38; tempBuf[2] = 0x40;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x39; tempBuf[2] = 0x40;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x3a; tempBuf[2] = 0x00;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x3b; tempBuf[2] = 0x00;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x80; tempBuf[2] = 0x20;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x81; tempBuf[2] = 0x5b;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x82; tempBuf[2] = 0x05;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x83; tempBuf[2] = 0x22;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x84; tempBuf[2] = 0x9d;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x85; tempBuf[2] = 0xc0;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x86; tempBuf[2] = 0xb6;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x87; tempBuf[2] = 0xb5;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x88; tempBuf[2] = 0x02;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x89; tempBuf[2] = 0x98;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x8a; tempBuf[2] = 0x00;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x40; tempBuf[2] = 0x09;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x41; tempBuf[2] = 0x19;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x42; tempBuf[2] = 0x2f;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x43; tempBuf[2] = 0x45;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x44; tempBuf[2] = 0x5a;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x45; tempBuf[2] = 0x69;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x46; tempBuf[2] = 0x75;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x47; tempBuf[2] = 0x7e;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x48; tempBuf[2] = 0x88;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x49; tempBuf[2] = 0x96;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x4a; tempBuf[2] = 0xa3;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x4b; tempBuf[2] = 0xaf;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x4c; tempBuf[2] = 0xc4;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x4d; tempBuf[2] = 0xd7;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x4e; tempBuf[2] = 0xe8;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x4f; tempBuf[2] = 0x20;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x50; tempBuf[2] = 0x35;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x51; tempBuf[2] = 0x0a;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x52; tempBuf[2] = 0x00;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x53; tempBuf[2] = 0x16;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x54; tempBuf[2] = 0x00;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x55; tempBuf[2] = 0x85;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x56; tempBuf[2] = 0x35;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x57; tempBuf[2] = 0x0a;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x58; tempBuf[2] = 0x00;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x59; tempBuf[2] = 0x19;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x5a; tempBuf[2] = 0x00;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x5b; tempBuf[2] = 0x85;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x5c; tempBuf[2] = 0x35;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x5d; tempBuf[2] = 0x0a;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x5e; tempBuf[2] = 0x00;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x5f; tempBuf[2] = 0x14;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x60; tempBuf[2] = 0x00;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x61; tempBuf[2] = 0x85;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x63; tempBuf[2] = 0x01;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x64; tempBuf[2] = 0x03;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x65; tempBuf[2] = 0x02;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x66; tempBuf[2] = 0x00;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x01; tempBuf[2] = 0xff;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x8B; tempBuf[2] = 0x1e;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x8c; tempBuf[2] = 0x10;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x8d; tempBuf[2] = 0x40;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x70; tempBuf[2] = 0xd0;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x71; tempBuf[2] = 0x00;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x72; tempBuf[2] = 0x00;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x73; tempBuf[2] = 0x40;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x74; tempBuf[2] = 0x10;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x75; tempBuf[2] = 0x10;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x76; tempBuf[2] = 0x04;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x77; tempBuf[2] = 0x00;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x78; tempBuf[2] = 0x04;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x79; tempBuf[2] = 0x80;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x69; tempBuf[2] = 0x86;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x7c; tempBuf[2] = 0x10;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x87; tempBuf[2] = 0x02;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x90; tempBuf[2] = 0x03;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0xaa; tempBuf[2] = 0x52;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0xa3; tempBuf[2] = 0x80;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0xa1; tempBuf[2] = 0x41;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x00; tempBuf[2] = 0xfc;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x33; tempBuf[1] = 0x02; tempBuf[2] = 0x11;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x34; tempBuf[1] = 0x00; tempBuf[2] = 0x02;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x36; tempBuf[1] = 0x06; tempBuf[2] = 0x20;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x36; tempBuf[1] = 0x01; tempBuf[2] = 0x30;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x0e; tempBuf[2] = 0x34;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0xf3; tempBuf[2] = 0x83;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x4e; tempBuf[2] = 0x88;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x36; tempBuf[1] = 0x3b; tempBuf[2] = 0x01;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x36; tempBuf[1] = 0x3c; tempBuf[2] = 0xf2;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0xa1; tempBuf[2] = 0x81;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x86; tempBuf[2] = 0x0f;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//		tempBuf[0] = 0x30; tempBuf[1] = 0x86; tempBuf[2] = 0x00;
//		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
//
//
//// }}}
//	}
//	uart_print("Sensor Setting Done\n\r");
//// }}}
//	}
	//sensorSetToVGA();

	//AIC Initialize
	//AIC Reset
	GPIOSetHigh(GPIO13);
 	for ( nop_i = 0; nop_i < 1000; nop_i++ ) __asm __volatile("l.nop   0");
	GPIOSetLow(GPIO13);
 	for ( nop_i = 0; nop_i < 1000; nop_i++ ) __asm __volatile("l.nop   0");
	GPIOSetHigh(GPIO13);
 	for ( nop_i = 0; nop_i < 1000; nop_i++ ) __asm __volatile("l.nop   0");
	//uart_print("AIC_reset\n\r");

	AIC3101Init( MASTER, AIC3101_FS_16KHz, MIC, AUDIO_GAIN );
	//i2s init
	init_i2s();

	//ParamToHIFConv(); //jykim_20080715_HIF_CONV++

	//Wait I2C Start Command 
	//while (!COMMAND_START)
//		;

	lencod();
}
/*
void StopProcess(void) {
	int i = 0;

	//cpm setting
	for (i = 0; i < 10; i++)
		;
	sys_clk_div(0xf);
	for (i = 0; i < 10; i++)
		;
	risc_clk_div(0xf);
	for (i = 0; i < 10; i++)
		;
	amba_clk_div(0xf);
	for (i = 0; i < 10; i++)
		;
	cam_clk_div(0xf);
	for (i = 0; i < 10; i++)
		;
	dramc_clk_div(0xf);

	//PLL Bypass
	if (PLL_MODE_BYPASS) {
		set_bypass;
	}

	//Clock Gating
	set_dis_clk(PERI_GATING_VALUE);

	for (i = 0; i < 10; i++)
		;
	rst_active(0xFFFFFFFF);
	for (i = 0; i < 10; i++)
		;
	rst_deactive(0xFFFFFFFF);
	for (i = 0; i < 10; i++)
		;
}
*/

