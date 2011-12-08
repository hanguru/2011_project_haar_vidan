#include "map_hif.h"
#include "sensor_set.h"
#include "i2c_operation.h"
#include "uart.h"

int videoApiContrastSet(VIDEO_PROP_LEVEL vpl);
int videoApiBrightnessSet(VIDEO_PROP_LEVEL vpl);
int videoApiSaturationSet(VIDEO_PROP_LEVEL vpl);
int videoApiSharpnessSet(VIDEO_PROP_LEVEL vpl);
int videoApiHueSet(VIDEO_PROP_LEVEL vpl);
int videoApiGammaSet(VIDEO_PROP_LEVEL vpl);
int videoApiWhitebalanceSet(VIDEO_PROP_LEVEL vpl);
int videoApiExposureSet(VIDEO_PROP_LEVEL vpl);
int videoApiPowerlinefreqSet(VIDEO_PROP_LEVEL vpl);
int videoAPICheck(void);

volatile int isVideoPropertySet = 0;

int sensorSetToVGA(void)
{
	int ret;
	char tempBuf[256];
	int nop_i;

	tempBuf[0] = 0x30; tempBuf[1] = 0x12; tempBuf[2] = 0x80;
	ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
 	for ( nop_i = 0; nop_i < 10000000; nop_i++ ) __asm __volatile("l.nop   0");

	for ( nop_i = 0; nop_i < 3; nop_i++ )
	{
// {{{
		tempBuf[0] = 0x30; tempBuf[1] = 0x8c; tempBuf[2] = 0x80; 
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x8d; tempBuf[2] = 0x0e;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x36; tempBuf[1] = 0x0b; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xb0; tempBuf[2] = 0xff;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xb1; tempBuf[2] = 0xff;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xb2; tempBuf[2] = 0x04;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x0e; tempBuf[2] = 0x34;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x0f; tempBuf[2] = 0xa6;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x10; tempBuf[2] = 0x81;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x82; tempBuf[2] = 0x01;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xf4; tempBuf[2] = 0x01;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x90; tempBuf[2] = 0x43;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x91; tempBuf[2] = 0xc0;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xac; tempBuf[2] = 0x42;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xd1; tempBuf[2] = 0x08;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xa8; tempBuf[2] = 0x54;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x15; tempBuf[2] = 0x02;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x93; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x7e; tempBuf[2] = 0xe5;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x79; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xaa; tempBuf[2] = 0x52;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x17; tempBuf[2] = 0x40;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xf3; tempBuf[2] = 0x83;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x6a; tempBuf[2] = 0x0c;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x6d; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x6a; tempBuf[2] = 0x3c;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x76; tempBuf[2] = 0x6a;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xd9; tempBuf[2] = 0x95;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x16; tempBuf[2] = 0x82;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x36; tempBuf[1] = 0x01; tempBuf[2] = 0x30;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x4e; tempBuf[2] = 0x88;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xf1; tempBuf[2] = 0x82;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x6f; tempBuf[2] = 0x14;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x2a; tempBuf[2] = 0x02;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x2b; tempBuf[2] = 0x6a;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x12; tempBuf[2] = 0x10;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x11; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x13; tempBuf[2] = 0xf7;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x18; tempBuf[2] = 0x80;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x19; tempBuf[2] = 0x70;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x1a; tempBuf[2] = 0xd4;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x1c; tempBuf[2] = 0x13;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x1d; tempBuf[2] = 0x17;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x70; tempBuf[2] = 0x5d;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x72; tempBuf[2] = 0x4d;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xaf; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x48; tempBuf[2] = 0x1f;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x49; tempBuf[2] = 0x4e;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x4a; tempBuf[2] = 0x20;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x4f; tempBuf[2] = 0x20;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x4b; tempBuf[2] = 0x02;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x4c; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x4d; tempBuf[2] = 0x02;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x4f; tempBuf[2] = 0x20;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xa3; tempBuf[2] = 0x10;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x13; tempBuf[2] = 0xf7;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x14; tempBuf[2] = 0x44;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x71; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x70; tempBuf[2] = 0x5d;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x73; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x72; tempBuf[2] = 0x4d;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x1c; tempBuf[2] = 0x05;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x1d; tempBuf[2] = 0x06;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x4d; tempBuf[2] = 0x42;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x4a; tempBuf[2] = 0x40;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x4f; tempBuf[2] = 0x40;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x95; tempBuf[2] = 0x07;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x96; tempBuf[2] = 0x16;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x97; tempBuf[2] = 0x1d;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x20; tempBuf[2] = 0x01;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x21; tempBuf[2] = 0x18;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x22; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x23; tempBuf[2] = 0x06;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x24; tempBuf[2] = 0x06;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x25; tempBuf[2] = 0x58;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x26; tempBuf[2] = 0x02;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x27; tempBuf[2] = 0x61;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x88; tempBuf[2] = 0x02;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x89; tempBuf[2] = 0x80;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x8a; tempBuf[2] = 0x01;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x8b; tempBuf[2] = 0xe0;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x16; tempBuf[2] = 0x64;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x17; tempBuf[2] = 0x25;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x18; tempBuf[2] = 0x80;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x19; tempBuf[2] = 0x08;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x1a; tempBuf[2] = 0x28;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x1b; tempBuf[2] = 0x1e;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x1c; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x1d; tempBuf[2] = 0x38;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x31; tempBuf[1] = 0x00; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x20; tempBuf[2] = 0xfa;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x21; tempBuf[2] = 0x11;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x22; tempBuf[2] = 0x92;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x23; tempBuf[2] = 0x01;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x24; tempBuf[2] = 0x97;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x25; tempBuf[2] = 0x02;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x26; tempBuf[2] = 0xff;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x27; tempBuf[2] = 0x10;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x28; tempBuf[2] = 0x10;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x29; tempBuf[2] = 0x1f;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x2a; tempBuf[2] = 0x58;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x2b; tempBuf[2] = 0x50;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x2c; tempBuf[2] = 0xbe;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x2d; tempBuf[2] = 0xce;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x2e; tempBuf[2] = 0x2e;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x2f; tempBuf[2] = 0x36;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x30; tempBuf[2] = 0x4d;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x31; tempBuf[2] = 0x44;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x32; tempBuf[2] = 0xf0;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x33; tempBuf[2] = 0x0a;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x34; tempBuf[2] = 0xf0;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x35; tempBuf[2] = 0xf0;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x36; tempBuf[2] = 0xf0;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x37; tempBuf[2] = 0x40;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x38; tempBuf[2] = 0x40;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x39; tempBuf[2] = 0x40;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x3a; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x3b; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x80; tempBuf[2] = 0x20;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x81; tempBuf[2] = 0x5b;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x82; tempBuf[2] = 0x05;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x83; tempBuf[2] = 0x22;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x84; tempBuf[2] = 0x9d;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x85; tempBuf[2] = 0xc0;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x86; tempBuf[2] = 0xb6;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x87; tempBuf[2] = 0xb5;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x88; tempBuf[2] = 0x02;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x89; tempBuf[2] = 0x98;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x8a; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x40; tempBuf[2] = 0x09;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x41; tempBuf[2] = 0x19;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x42; tempBuf[2] = 0x2f;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x43; tempBuf[2] = 0x45;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x44; tempBuf[2] = 0x5a;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x45; tempBuf[2] = 0x69;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x46; tempBuf[2] = 0x75;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x47; tempBuf[2] = 0x7e;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x48; tempBuf[2] = 0x88;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x49; tempBuf[2] = 0x96;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x4a; tempBuf[2] = 0xa3;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x4b; tempBuf[2] = 0xaf;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x4c; tempBuf[2] = 0xc4;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x4d; tempBuf[2] = 0xd7;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x4e; tempBuf[2] = 0xe8;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x4f; tempBuf[2] = 0x20;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x50; tempBuf[2] = 0x35;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x51; tempBuf[2] = 0x0a;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x52; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x53; tempBuf[2] = 0x16;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x54; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x55; tempBuf[2] = 0x85;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x56; tempBuf[2] = 0x35;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x57; tempBuf[2] = 0x0a;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x58; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x59; tempBuf[2] = 0x19;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x5a; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x5b; tempBuf[2] = 0x85;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x5c; tempBuf[2] = 0x35;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x5d; tempBuf[2] = 0x0a;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x5e; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x5f; tempBuf[2] = 0x14;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x60; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x61; tempBuf[2] = 0x85;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x63; tempBuf[2] = 0x01;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x64; tempBuf[2] = 0x03;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x65; tempBuf[2] = 0x02;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x66; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x01; tempBuf[2] = 0xff;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x8B; tempBuf[2] = 0x1e;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x8c; tempBuf[2] = 0x10;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x8d; tempBuf[2] = 0x40;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x70; tempBuf[2] = 0xd0;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x71; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x72; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x73; tempBuf[2] = 0x40;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x74; tempBuf[2] = 0x10;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x75; tempBuf[2] = 0x10;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x76; tempBuf[2] = 0x04;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x77; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x78; tempBuf[2] = 0x04;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x79; tempBuf[2] = 0x80;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x69; tempBuf[2] = 0x86;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x7c; tempBuf[2] = 0x10;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x87; tempBuf[2] = 0x02;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x90; tempBuf[2] = 0x03;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xaa; tempBuf[2] = 0x52;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xa3; tempBuf[2] = 0x80;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xa1; tempBuf[2] = 0x41;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x00; tempBuf[2] = 0xfc;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x02; tempBuf[2] = 0x11;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x34; tempBuf[1] = 0x00; tempBuf[2] = 0x02;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x36; tempBuf[1] = 0x06; tempBuf[2] = 0x20;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x36; tempBuf[1] = 0x01; tempBuf[2] = 0x30;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x0e; tempBuf[2] = 0x34;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xf3; tempBuf[2] = 0x83;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x4e; tempBuf[2] = 0x88;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x36; tempBuf[1] = 0x3b; tempBuf[2] = 0x01;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x36; tempBuf[1] = 0x3c; tempBuf[2] = 0xf2;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xa1; tempBuf[2] = 0x81;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x86; tempBuf[2] = 0x0f;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x86; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x91; tempBuf[2] = 0x07; //Enable Video Setting API
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");


// }}}
	}

	//zoomControl(0, ZOOM_LEVEL);

 	for ( nop_i = 0; nop_i < 10000000; nop_i++ ) __asm __volatile("l.nop   0");

	return 0;
}

int sensorSetToHD(void)
{
	int ret;
	char tempBuf[256];
	int nop_i;

	tempBuf[0] = 0x30; tempBuf[1] = 0x12; tempBuf[2] = 0x80;
	ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
 	for ( nop_i = 0; nop_i < 10000000; nop_i++ ) __asm __volatile("l.nop   0");

	for ( nop_i = 0; nop_i < 3; nop_i++ )
	{
	// HD Setting {{{
		tempBuf[0] = 0x30; tempBuf[1] = 0x8c; tempBuf[2] = 0x80; 
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x8d; tempBuf[2] = 0x0e;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x36; tempBuf[1] = 0x0b; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xb0; tempBuf[2] = 0xff;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xb1; tempBuf[2] = 0xff;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xb2; tempBuf[2] = 0x04;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x0e; tempBuf[2] = 0x34;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x0f; tempBuf[2] = 0xa6;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x10; tempBuf[2] = 0x81;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x82; tempBuf[2] = 0x01;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xf4; tempBuf[2] = 0x01;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x90; tempBuf[2] = 0x43;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x91; tempBuf[2] = 0xc0;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xac; tempBuf[2] = 0x42;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xd1; tempBuf[2] = 0x08;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xa8; tempBuf[2] = 0x54;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x15; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x93; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x7e; tempBuf[2] = 0xe5;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x79; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xaa; tempBuf[2] = 0x52;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x17; tempBuf[2] = 0x40;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xf3; tempBuf[2] = 0x83;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x6a; tempBuf[2] = 0x0c;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x6d; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x6a; tempBuf[2] = 0x3c;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x76; tempBuf[2] = 0x6a;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xd9; tempBuf[2] = 0x95;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x16; tempBuf[2] = 0x82;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x36; tempBuf[1] = 0x01; tempBuf[2] = 0x30;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x4e; tempBuf[2] = 0x88;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xf1; tempBuf[2] = 0x82;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x11; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		//tempBuf[0] = 0x30; tempBuf[1] = 0x13; tempBuf[2] = 0xf7;
		tempBuf[0] = 0x30; tempBuf[1] = 0x13; tempBuf[2] = 0xf3;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x18; tempBuf[2] = 0x70;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x19; tempBuf[2] = 0x60;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x1a; tempBuf[2] = 0xd4;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x1c; tempBuf[2] = 0x13;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x1d; tempBuf[2] = 0x17;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x70; tempBuf[2] = 0x3e;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x72; tempBuf[2] = 0x34;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xaf; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x48; tempBuf[2] = 0x1f;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x49; tempBuf[2] = 0x4e;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x4a; tempBuf[2] = 0x20;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x4f; tempBuf[2] = 0x20;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x4b; tempBuf[2] = 0x02;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x4c; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x4d; tempBuf[2] = 0x02;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x4f; tempBuf[2] = 0x20;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xa3; tempBuf[2] = 0x10;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x13; tempBuf[2] = 0xf7;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x14; tempBuf[2] = 0x45;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x71; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x70; tempBuf[2] = 0x3e;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x73; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x72; tempBuf[2] = 0x34;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x1c; tempBuf[2] = 0x12;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x1d; tempBuf[2] = 0x16;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x4d; tempBuf[2] = 0x42;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x4a; tempBuf[2] = 0x40;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x4f; tempBuf[2] = 0x40;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x95; tempBuf[2] = 0x07;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x96; tempBuf[2] = 0x16;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x97; tempBuf[2] = 0x1d;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x20; tempBuf[2] = 0x01;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x21; tempBuf[2] = 0x18;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x22; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x23; tempBuf[2] = 0x0a;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x24; tempBuf[2] = 0x06;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x25; tempBuf[2] = 0x58;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x26; tempBuf[2] = 0x04;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x27; tempBuf[2] = 0xbc;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x88; tempBuf[2] = 0x06;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x89; tempBuf[2] = 0x40;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x8a; tempBuf[2] = 0x04;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x8b; tempBuf[2] = 0xb0;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x16; tempBuf[2] = 0x64;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x17; tempBuf[2] = 0x4b;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x18; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x1a; tempBuf[2] = 0x64;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x1b; tempBuf[2] = 0x4b;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x1c; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x31; tempBuf[1] = 0x00; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x20; tempBuf[2] = 0xfa;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x21; tempBuf[2] = 0x11;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x22; tempBuf[2] = 0x92;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x23; tempBuf[2] = 0x01;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x24; tempBuf[2] = 0x97;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x25; tempBuf[2] = 0x02;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x26; tempBuf[2] = 0xff;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x27; tempBuf[2] = 0x10;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x28; tempBuf[2] = 0x10;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x29; tempBuf[2] = 0x1f;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x2a; tempBuf[2] = 0x58;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x2b; tempBuf[2] = 0x50;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x2c; tempBuf[2] = 0xbe;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x2d; tempBuf[2] = 0xce;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x2e; tempBuf[2] = 0x2e;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x2f; tempBuf[2] = 0x36;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x30; tempBuf[2] = 0x4d;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x31; tempBuf[2] = 0x44;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x32; tempBuf[2] = 0xf0;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x33; tempBuf[2] = 0x0a;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x34; tempBuf[2] = 0xf0;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x35; tempBuf[2] = 0xf0;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x36; tempBuf[2] = 0xf0;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x37; tempBuf[2] = 0x40;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x38; tempBuf[2] = 0x40;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x39; tempBuf[2] = 0x40;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x3a; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x3b; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x80; tempBuf[2] = 0x28;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x81; tempBuf[2] = 0x48;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x82; tempBuf[2] = 0x10;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x83; tempBuf[2] = 0x4e;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x84; tempBuf[2] = 0x82;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x85; tempBuf[2] = 0xd0;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x86; tempBuf[2] = 0xd0;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x87; tempBuf[2] = 0xa9;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x88; tempBuf[2] = 0x27;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x89; tempBuf[2] = 0x98;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x8a; tempBuf[2] = 0x01;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x40; tempBuf[2] = 0x09;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x41; tempBuf[2] = 0x19;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x42; tempBuf[2] = 0x2f;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x43; tempBuf[2] = 0x45;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x44; tempBuf[2] = 0x5a;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x45; tempBuf[2] = 0x69;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x46; tempBuf[2] = 0x75;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x47; tempBuf[2] = 0x7e;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x48; tempBuf[2] = 0x88;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x49; tempBuf[2] = 0x96;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x4a; tempBuf[2] = 0xa3;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x4b; tempBuf[2] = 0xaf;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x4c; tempBuf[2] = 0xc4;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x4d; tempBuf[2] = 0xd7;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x4e; tempBuf[2] = 0xe8;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x4f; tempBuf[2] = 0x20;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x50; tempBuf[2] = 0x35;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x51; tempBuf[2] = 0x21;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x52; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x53; tempBuf[2] = 0x16;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x54; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x55; tempBuf[2] = 0x85;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x56; tempBuf[2] = 0x35;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x57; tempBuf[2] = 0x21;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x58; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x59; tempBuf[2] = 0x19;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x5a; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x5b; tempBuf[2] = 0x85;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x5c; tempBuf[2] = 0x35;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x5d; tempBuf[2] = 0x21;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x5e; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x5f; tempBuf[2] = 0x14;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x60; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x61; tempBuf[2] = 0x85;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x63; tempBuf[2] = 0x01;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x64; tempBuf[2] = 0x03;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x65; tempBuf[2] = 0x02;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x66; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x01; tempBuf[2] = 0xff;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x8B; tempBuf[2] = 0x1e;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x8c; tempBuf[2] = 0x10;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x8d; tempBuf[2] = 0x40;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x70; tempBuf[2] = 0xf3;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x71; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x72; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x73; tempBuf[2] = 0x7a;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x74; tempBuf[2] = 0x10;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x75; tempBuf[2] = 0x10;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x76; tempBuf[2] = 0x04;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x77; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x78; tempBuf[2] = 0x04;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x79; tempBuf[2] = 0x80;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x69; tempBuf[2] = 0x86;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x7c; tempBuf[2] = 0x10;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x87; tempBuf[2] = 0x02;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x90; tempBuf[2] = 0x03;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xaa; tempBuf[2] = 0x52;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xa3; tempBuf[2] = 0x80;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xa1; tempBuf[2] = 0x41;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x00; tempBuf[2] = 0xfc;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x02; tempBuf[2] = 0x01;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x34; tempBuf[1] = 0x00; tempBuf[2] = 0x02;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x36; tempBuf[1] = 0x06; tempBuf[2] = 0x20;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x36; tempBuf[1] = 0x01; tempBuf[2] = 0x30;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x0e; tempBuf[2] = 0x34;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0xf3; tempBuf[2] = 0x83;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x4e; tempBuf[2] = 0x88;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x36; tempBuf[1] = 0x3b; tempBuf[2] = 0x01;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x36; tempBuf[1] = 0x3c; tempBuf[2] = 0xf2;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x23; tempBuf[2] = 0x0c;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x19; tempBuf[2] = 0x4c;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x86; tempBuf[2] = 0x0f;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x86; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x20; tempBuf[2] = 0x01;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x21; tempBuf[2] = 0xb8;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x22; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x23; tempBuf[2] = 0xfa;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x24; tempBuf[2] = 0x05;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x25; tempBuf[2] = 0x18;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x26; tempBuf[2] = 0x02;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x27; tempBuf[2] = 0xdc;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x88; tempBuf[2] = 0x05;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x89; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x8a; tempBuf[2] = 0x02;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x30; tempBuf[1] = 0x8b; tempBuf[2] = 0xd0;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x16; tempBuf[2] = 0x64;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x17; tempBuf[2] = 0x4b;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x18; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x1a; tempBuf[2] = 0x64;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x1b; tempBuf[2] = 0x4b;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x33; tempBuf[1] = 0x1c; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
		tempBuf[0] = 0x31; tempBuf[1] = 0x00; tempBuf[2] = 0x00;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");	// HD Setting Done }}}
		tempBuf[0] = 0x33; tempBuf[1] = 0x91; tempBuf[2] = 0x07; //Enable Video Setting API
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
	}

	zoomControl(0, ZOOM_LEVEL);

 	for ( nop_i = 0; nop_i < 10000000; nop_i++ ) __asm __volatile("l.nop   0");

	return 0;
}



int initialSensorI2CSet(char *buf)
{
	int retryCnt;
	int ret;
	int nop_i;

	for ( retryCnt = 0; retryCnt < 3; retryCnt++ )
	{
		ret = i2c_write(0x30, 3, buf); 
		if ( !ret ) break;
 		for ( nop_i = 0; nop_i < 10000000; nop_i++ ) __asm __volatile("l.nop   0");
	}
	if ( retryCnt == 3 )
		return ret;
	else
		return I2C_SUCCESS;
}


int zoomControl(int prevZoomLevel, int zoom_level) 
{ // {{{
	char tempBuf[256];
	int ret;
	int nop_i;

	tempBuf[0] = 0x30; tempBuf[1] = 0x12; tempBuf[2] = 0x80;
	ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
 	for ( nop_i = 0; nop_i < 10000000; nop_i++ ) __asm __volatile("l.nop   0");

	if ( ZOOM_LEVEL == 0 )
	{
			// {{{
			tempBuf[0] = 0x30; tempBuf[1] = 0x8c; tempBuf[2] = 0x80; 
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x8d; tempBuf[2] = 0x0e;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x36; tempBuf[1] = 0x0b; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xb0; tempBuf[2] = 0xff;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xb1; tempBuf[2] = 0xff;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xb2; tempBuf[2] = 0x04;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x0e; tempBuf[2] = 0x34;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x0f; tempBuf[2] = 0xa6;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x10; tempBuf[2] = 0x81;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x82; tempBuf[2] = 0x01;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xf4; tempBuf[2] = 0x01;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x90; tempBuf[2] = 0x43;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x91; tempBuf[2] = 0xc0;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xac; tempBuf[2] = 0x42;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xd1; tempBuf[2] = 0x08;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xa8; tempBuf[2] = 0x54;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x15; tempBuf[2] = 0x02;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x93; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x7e; tempBuf[2] = 0xe5;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x79; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xaa; tempBuf[2] = 0x52;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x17; tempBuf[2] = 0x40;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xf3; tempBuf[2] = 0x83;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x6a; tempBuf[2] = 0x0c;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x6d; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x6a; tempBuf[2] = 0x3c;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x76; tempBuf[2] = 0x6a;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xd9; tempBuf[2] = 0x95;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x16; tempBuf[2] = 0x82;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x36; tempBuf[1] = 0x01; tempBuf[2] = 0x30;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x4e; tempBuf[2] = 0x88;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xf1; tempBuf[2] = 0x82;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x6f; tempBuf[2] = 0x14;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x2a; tempBuf[2] = 0x02;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x2b; tempBuf[2] = 0x6a;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x12; tempBuf[2] = 0x10;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x11; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x13; tempBuf[2] = 0xf7;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x18; tempBuf[2] = 0x80;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x19; tempBuf[2] = 0x70;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x1a; tempBuf[2] = 0xd4;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x1c; tempBuf[2] = 0x13;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x1d; tempBuf[2] = 0x17;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x70; tempBuf[2] = 0x5d;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x72; tempBuf[2] = 0x4d;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xaf; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x48; tempBuf[2] = 0x1f;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x49; tempBuf[2] = 0x4e;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x4a; tempBuf[2] = 0x20;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x4f; tempBuf[2] = 0x20;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x4b; tempBuf[2] = 0x02;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x4c; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x4d; tempBuf[2] = 0x02;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x4f; tempBuf[2] = 0x20;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xa3; tempBuf[2] = 0x10;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x13; tempBuf[2] = 0xf7;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x14; tempBuf[2] = 0x44;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x71; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x70; tempBuf[2] = 0x5d;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x73; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x72; tempBuf[2] = 0x4d;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x1c; tempBuf[2] = 0x05;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x1d; tempBuf[2] = 0x06;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x4d; tempBuf[2] = 0x42;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x4a; tempBuf[2] = 0x40;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x4f; tempBuf[2] = 0x40;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x95; tempBuf[2] = 0x07;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x96; tempBuf[2] = 0x16;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x97; tempBuf[2] = 0x1d;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x20; tempBuf[2] = 0x01;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x21; tempBuf[2] = 0x18;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x22; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x23; tempBuf[2] = 0x06;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x24; tempBuf[2] = 0x06;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x25; tempBuf[2] = 0x58;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x26; tempBuf[2] = 0x02;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x27; tempBuf[2] = 0x61;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x88; tempBuf[2] = 0x02;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x89; tempBuf[2] = 0x80;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x8a; tempBuf[2] = 0x01;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x8b; tempBuf[2] = 0xe0;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x16; tempBuf[2] = 0x64;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x17; tempBuf[2] = 0x25;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x18; tempBuf[2] = 0x80;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x19; tempBuf[2] = 0x08;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x1a; tempBuf[2] = 0x28;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x1b; tempBuf[2] = 0x1e;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x1c; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x1d; tempBuf[2] = 0x38;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x31; tempBuf[1] = 0x00; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x20; tempBuf[2] = 0xfa;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x21; tempBuf[2] = 0x11;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x22; tempBuf[2] = 0x92;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x23; tempBuf[2] = 0x01;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x24; tempBuf[2] = 0x97;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x25; tempBuf[2] = 0x02;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x26; tempBuf[2] = 0xff;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x27; tempBuf[2] = 0x10;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x28; tempBuf[2] = 0x10;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x29; tempBuf[2] = 0x1f;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x2a; tempBuf[2] = 0x58;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x2b; tempBuf[2] = 0x50;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x2c; tempBuf[2] = 0xbe;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x2d; tempBuf[2] = 0xce;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x2e; tempBuf[2] = 0x2e;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x2f; tempBuf[2] = 0x36;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x30; tempBuf[2] = 0x4d;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x31; tempBuf[2] = 0x44;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x32; tempBuf[2] = 0xf0;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x33; tempBuf[2] = 0x0a;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x34; tempBuf[2] = 0xf0;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x35; tempBuf[2] = 0xf0;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x36; tempBuf[2] = 0xf0;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x37; tempBuf[2] = 0x40;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x38; tempBuf[2] = 0x40;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x39; tempBuf[2] = 0x40;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x3a; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x3b; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x80; tempBuf[2] = 0x20;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x81; tempBuf[2] = 0x5b;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x82; tempBuf[2] = 0x05;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x83; tempBuf[2] = 0x22;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x84; tempBuf[2] = 0x9d;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x85; tempBuf[2] = 0xc0;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x86; tempBuf[2] = 0xb6;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x87; tempBuf[2] = 0xb5;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x88; tempBuf[2] = 0x02;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x89; tempBuf[2] = 0x98;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x8a; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x40; tempBuf[2] = 0x09;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x41; tempBuf[2] = 0x19;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x42; tempBuf[2] = 0x2f;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x43; tempBuf[2] = 0x45;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x44; tempBuf[2] = 0x5a;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x45; tempBuf[2] = 0x69;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x46; tempBuf[2] = 0x75;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x47; tempBuf[2] = 0x7e;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x48; tempBuf[2] = 0x88;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x49; tempBuf[2] = 0x96;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x4a; tempBuf[2] = 0xa3;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x4b; tempBuf[2] = 0xaf;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x4c; tempBuf[2] = 0xc4;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x4d; tempBuf[2] = 0xd7;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x4e; tempBuf[2] = 0xe8;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x4f; tempBuf[2] = 0x20;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x50; tempBuf[2] = 0x35;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x51; tempBuf[2] = 0x0a;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x52; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x53; tempBuf[2] = 0x16;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x54; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x55; tempBuf[2] = 0x85;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x56; tempBuf[2] = 0x35;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x57; tempBuf[2] = 0x0a;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x58; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x59; tempBuf[2] = 0x19;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x5a; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x5b; tempBuf[2] = 0x85;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x5c; tempBuf[2] = 0x35;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x5d; tempBuf[2] = 0x0a;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x5e; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x5f; tempBuf[2] = 0x14;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x60; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x61; tempBuf[2] = 0x85;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x63; tempBuf[2] = 0x01;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x64; tempBuf[2] = 0x03;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x65; tempBuf[2] = 0x02;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x66; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x01; tempBuf[2] = 0xff;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x8B; tempBuf[2] = 0x1e;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x8c; tempBuf[2] = 0x10;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x8d; tempBuf[2] = 0x40;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x70; tempBuf[2] = 0xd0;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x71; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x72; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x73; tempBuf[2] = 0x40;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x74; tempBuf[2] = 0x10;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x75; tempBuf[2] = 0x10;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x76; tempBuf[2] = 0x04;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x77; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x78; tempBuf[2] = 0x04;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x79; tempBuf[2] = 0x80;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x69; tempBuf[2] = 0x86;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x7c; tempBuf[2] = 0x10;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x87; tempBuf[2] = 0x02;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x90; tempBuf[2] = 0x03;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xaa; tempBuf[2] = 0x52;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xa3; tempBuf[2] = 0x80;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xa1; tempBuf[2] = 0x41;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x00; tempBuf[2] = 0xfc;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x02; tempBuf[2] = 0x11;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x34; tempBuf[1] = 0x00; tempBuf[2] = 0x02;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x36; tempBuf[1] = 0x06; tempBuf[2] = 0x20;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x36; tempBuf[1] = 0x01; tempBuf[2] = 0x30;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x0e; tempBuf[2] = 0x34;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xf3; tempBuf[2] = 0x83;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x4e; tempBuf[2] = 0x88;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x36; tempBuf[1] = 0x3b; tempBuf[2] = 0x01;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x36; tempBuf[1] = 0x3c; tempBuf[2] = 0xf2;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xa1; tempBuf[2] = 0x81;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x86; tempBuf[2] = 0x0f;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x86; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			// }}}
	}
	else
	{
			// {{{
			tempBuf[0] = 0x30; tempBuf[1] = 0x8c; tempBuf[2] = 0x80; 
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x8d; tempBuf[2] = 0x0e;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x36; tempBuf[1] = 0x0b; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xb0; tempBuf[2] = 0xff;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xb1; tempBuf[2] = 0xff;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xb2; tempBuf[2] = 0x04;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x0e; tempBuf[2] = 0x34;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x0f; tempBuf[2] = 0xa6;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x10; tempBuf[2] = 0x81;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x82; tempBuf[2] = 0x01;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xf4; tempBuf[2] = 0x01;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x90; tempBuf[2] = 0x43;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x91; tempBuf[2] = 0xc0;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xac; tempBuf[2] = 0x42;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xd1; tempBuf[2] = 0x08;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xa8; tempBuf[2] = 0x54;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x15; tempBuf[2] = 0x22;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x93; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x7e; tempBuf[2] = 0xe5;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x79; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xaa; tempBuf[2] = 0x52;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x17; tempBuf[2] = 0x40;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xf3; tempBuf[2] = 0x83;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x6a; tempBuf[2] = 0x0c;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x6d; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x6a; tempBuf[2] = 0x3c;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x76; tempBuf[2] = 0x6a;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xd9; tempBuf[2] = 0x95;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x16; tempBuf[2] = 0x82;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x36; tempBuf[1] = 0x01; tempBuf[2] = 0x30;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x4e; tempBuf[2] = 0x88;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xf1; tempBuf[2] = 0x82;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x11; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x13; tempBuf[2] = 0xf7;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x18; tempBuf[2] = 0x80;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x19; tempBuf[2] = 0x70;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x1a; tempBuf[2] = 0xd4;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x1c; tempBuf[2] = 0x13;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x1d; tempBuf[2] = 0x17;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x70; tempBuf[2] = 0x3e;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x72; tempBuf[2] = 0x34;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xaf; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x48; tempBuf[2] = 0x1f;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x49; tempBuf[2] = 0x4e;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x4a; tempBuf[2] = 0x20;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x4f; tempBuf[2] = 0x20;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x4b; tempBuf[2] = 0x02;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x4c; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x4d; tempBuf[2] = 0x02;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x4f; tempBuf[2] = 0x20;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xa3; tempBuf[2] = 0x10;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x13; tempBuf[2] = 0xf7;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x14; tempBuf[2] = 0x45;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x71; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x70; tempBuf[2] = 0x3e;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x73; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x72; tempBuf[2] = 0x34;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x1c; tempBuf[2] = 0x12;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x1d; tempBuf[2] = 0x16;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x4d; tempBuf[2] = 0x42;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x4a; tempBuf[2] = 0x40;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x4f; tempBuf[2] = 0x40;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x95; tempBuf[2] = 0x07;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x96; tempBuf[2] = 0x16;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x97; tempBuf[2] = 0x1d;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x20; tempBuf[2] = 0x01;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x21; tempBuf[2] = 0x18;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x22; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x23; tempBuf[2] = 0x0a;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x24; tempBuf[2] = 0x06;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x25; tempBuf[2] = 0x58;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x26; tempBuf[2] = 0x04;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x27; tempBuf[2] = 0xbc;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x88; tempBuf[2] = 0x06;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x89; tempBuf[2] = 0x40;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x8a; tempBuf[2] = 0x04;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x8b; tempBuf[2] = 0xb0;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x16; tempBuf[2] = 0x64;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x17; tempBuf[2] = 0x4b;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x18; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x1a; tempBuf[2] = 0x64;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x1b; tempBuf[2] = 0x4b;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x1c; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x31; tempBuf[1] = 0x00; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x20; tempBuf[2] = 0xfa;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x21; tempBuf[2] = 0x11;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x22; tempBuf[2] = 0x92;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x23; tempBuf[2] = 0x01;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x24; tempBuf[2] = 0x97;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x25; tempBuf[2] = 0x02;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x26; tempBuf[2] = 0xff;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x27; tempBuf[2] = 0x10;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x28; tempBuf[2] = 0x10;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x29; tempBuf[2] = 0x1f;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x2a; tempBuf[2] = 0x58;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x2b; tempBuf[2] = 0x50;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x2c; tempBuf[2] = 0xbe;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x2d; tempBuf[2] = 0xce;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x2e; tempBuf[2] = 0x2e;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x2f; tempBuf[2] = 0x36;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x30; tempBuf[2] = 0x4d;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x31; tempBuf[2] = 0x44;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x32; tempBuf[2] = 0xf0;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x33; tempBuf[2] = 0x0a;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x34; tempBuf[2] = 0xf0;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x35; tempBuf[2] = 0xf0;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x36; tempBuf[2] = 0xf0;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x37; tempBuf[2] = 0x40;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x38; tempBuf[2] = 0x40;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x39; tempBuf[2] = 0x40;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x3a; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x3b; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x80; tempBuf[2] = 0x28;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x81; tempBuf[2] = 0x48;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x82; tempBuf[2] = 0x10;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x83; tempBuf[2] = 0x4e;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x84; tempBuf[2] = 0x82;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x85; tempBuf[2] = 0xd0;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x86; tempBuf[2] = 0xd0;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x87; tempBuf[2] = 0xa9;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x88; tempBuf[2] = 0x27;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x89; tempBuf[2] = 0x98;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x8a; tempBuf[2] = 0x01;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x40; tempBuf[2] = 0x09;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x41; tempBuf[2] = 0x19;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x42; tempBuf[2] = 0x2f;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x43; tempBuf[2] = 0x45;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x44; tempBuf[2] = 0x5a;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x45; tempBuf[2] = 0x69;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x46; tempBuf[2] = 0x75;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x47; tempBuf[2] = 0x7e;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x48; tempBuf[2] = 0x88;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x49; tempBuf[2] = 0x96;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x4a; tempBuf[2] = 0xa3;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x4b; tempBuf[2] = 0xaf;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x4c; tempBuf[2] = 0xc4;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x4d; tempBuf[2] = 0xd7;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x4e; tempBuf[2] = 0xe8;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x4f; tempBuf[2] = 0x20;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x50; tempBuf[2] = 0x35;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x51; tempBuf[2] = 0x21;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x52; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x53; tempBuf[2] = 0x16;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x54; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x55; tempBuf[2] = 0x85;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x56; tempBuf[2] = 0x35;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x57; tempBuf[2] = 0x21;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x58; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x59; tempBuf[2] = 0x19;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x5a; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x5b; tempBuf[2] = 0x85;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x5c; tempBuf[2] = 0x35;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x5d; tempBuf[2] = 0x21;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x5e; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x5f; tempBuf[2] = 0x14;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x60; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x61; tempBuf[2] = 0x85;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x63; tempBuf[2] = 0x01;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x64; tempBuf[2] = 0x03;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x65; tempBuf[2] = 0x02;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x66; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x01; tempBuf[2] = 0xff;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x8B; tempBuf[2] = 0x1e;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x8c; tempBuf[2] = 0x10;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x8d; tempBuf[2] = 0x40;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x70; tempBuf[2] = 0xF3;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x71; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x72; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x73; tempBuf[2] = 0x7A;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x74; tempBuf[2] = 0x10;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x75; tempBuf[2] = 0x10;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x76; tempBuf[2] = 0x04;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x77; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x78; tempBuf[2] = 0x04;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x79; tempBuf[2] = 0x80;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x69; tempBuf[2] = 0x86;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x7c; tempBuf[2] = 0x10;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x87; tempBuf[2] = 0x02;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x90; tempBuf[2] = 0x03;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xaa; tempBuf[2] = 0x52;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xa3; tempBuf[2] = 0x80;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xa1; tempBuf[2] = 0x41;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x00; tempBuf[2] = 0xfc;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x02; tempBuf[2] = 0x01;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x34; tempBuf[1] = 0x00; tempBuf[2] = 0x02;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x36; tempBuf[1] = 0x06; tempBuf[2] = 0x20;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x36; tempBuf[1] = 0x01; tempBuf[2] = 0x30;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x0e; tempBuf[2] = 0x34;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0xf3; tempBuf[2] = 0x83;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x4e; tempBuf[2] = 0x88;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x36; tempBuf[1] = 0x3b; tempBuf[2] = 0x01;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x36; tempBuf[1] = 0x3c; tempBuf[2] = 0xf2;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x23; tempBuf[2] = 0x0c;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x33; tempBuf[1] = 0x19; tempBuf[2] = 0x4c;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x86; tempBuf[2] = 0x0f;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			tempBuf[0] = 0x30; tempBuf[1] = 0x86; tempBuf[2] = 0x00;
			ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
			// }}}
		if ( ZOOM_LEVEL == 1 )
		{
				// {{{
				tempBuf[0] = 0x30; tempBuf[1] = 0x20; tempBuf[2] = 0x01;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x21; tempBuf[2] = 0xb8;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x22; tempBuf[2] = 0x00;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x23; tempBuf[2] = 0x82;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x24; tempBuf[2] = 0x05;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x25; tempBuf[2] = 0x18;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x26; tempBuf[2] = 0x04;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x27; tempBuf[2] = 0xbc;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x33; tempBuf[1] = 0x02; tempBuf[2] = 0x10; 
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x88; tempBuf[2] = 0x02;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x89; tempBuf[2] = 0x80;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x8a; tempBuf[2] = 0x01;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x8b; tempBuf[2] = 0xe0;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x33; tempBuf[1] = 0x16; tempBuf[2] = 0x50;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x33; tempBuf[1] = 0x17; tempBuf[2] = 0x3c;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x33; tempBuf[1] = 0x18; tempBuf[2] = 0x00;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x33; tempBuf[1] = 0x1a; tempBuf[2] = 0x28;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x33; tempBuf[1] = 0x1b; tempBuf[2] = 0x1e;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x33; tempBuf[1] = 0x1c; tempBuf[2] = 0x00;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				// }}}
		}
		else if ( ZOOM_LEVEL == 2 )
		{
				// {{{
				tempBuf[0] = 0x30; tempBuf[1] = 0x20; tempBuf[2] = 0x02; 
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x21; tempBuf[2] = 0x38;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x22; tempBuf[2] = 0x00;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x23; tempBuf[2] = 0xe2;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x24; tempBuf[2] = 0x04;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x25; tempBuf[2] = 0x18;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x26; tempBuf[2] = 0x04;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x27; tempBuf[2] = 0xbc;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x33; tempBuf[1] = 0x02; tempBuf[2] = 0x10; 
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x88; tempBuf[2] = 0x02;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x89; tempBuf[2] = 0x80;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x8a; tempBuf[2] = 0x01;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x8b; tempBuf[2] = 0xe0;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x33; tempBuf[1] = 0x16; tempBuf[2] = 0x40;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x33; tempBuf[1] = 0x17; tempBuf[2] = 0x30;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x33; tempBuf[1] = 0x18; tempBuf[2] = 0x00;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x33; tempBuf[1] = 0x1a; tempBuf[2] = 0x28;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x33; tempBuf[1] = 0x1b; tempBuf[2] = 0x1e;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x33; tempBuf[1] = 0x1c; tempBuf[2] = 0x00;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				// }}}
		}
		else if ( ZOOM_LEVEL == 3 )
		{
				// {{{
				tempBuf[0] = 0x30; tempBuf[1] = 0x20; tempBuf[2] = 0x02;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x21; tempBuf[2] = 0xa8;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x22; tempBuf[2] = 0x01;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x23; tempBuf[2] = 0x36;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x24; tempBuf[2] = 0x03;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x25; tempBuf[2] = 0x38;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x26; tempBuf[2] = 0x04;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x27; tempBuf[2] = 0xbc;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x33; tempBuf[1] = 0x02; tempBuf[2] = 0x10; 
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x88; tempBuf[2] = 0x02;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x89; tempBuf[2] = 0x80;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x8a; tempBuf[2] = 0x01;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x30; tempBuf[1] = 0x8b; tempBuf[2] = 0xe0;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x33; tempBuf[1] = 0x16; tempBuf[2] = 0x32;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x33; tempBuf[1] = 0x17; tempBuf[2] = 0x25;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x33; tempBuf[1] = 0x18; tempBuf[2] = 0x80;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x33; tempBuf[1] = 0x1a; tempBuf[2] = 0x28;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x33; tempBuf[1] = 0x1b; tempBuf[2] = 0x1e;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				tempBuf[0] = 0x33; tempBuf[1] = 0x1c; tempBuf[2] = 0x00;
				ret = initialSensorI2CSet(tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
				// }}}
		}
	}

	tempBuf[0] = 0x33; tempBuf[1] = 0x91; tempBuf[2] = 0x07; //Enable Video Setting API
	ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");

 	for ( nop_i = 0; nop_i < 10000000; nop_i++ ) __asm __volatile("l.nop   0");

	videoAPICheck();

 	for ( nop_i = 0; nop_i < 10000000; nop_i++ ) __asm __volatile("l.nop   0");
	return 0;
	// }}}
}


int videoAPICheck(void)
{
	int nop_i;

	if ( VIDEO_PROP_CONTRAST != PROP_DEFAULT )
		videoApiControl(PROP_CONTRAST, VIDEO_PROP_CONTRAST);
	if ( VIDEO_PROP_BRIGHTNESS != PROP_DEFAULT )
		videoApiControl(PROP_BRIGHTNESS, VIDEO_PROP_BRIGHTNESS);
	if ( VIDEO_PROP_SATURATION != PROP_DEFAULT )
		videoApiControl(PROP_SATURATION, VIDEO_PROP_SATURATION);
	if ( VIDEO_PROP_SHARPNESS != PROP_DEFAULT )
		videoApiControl(PROP_SHARPNESS, VIDEO_PROP_SHARPNESS);
	if ( VIDEO_PROP_HUE != PROP_DEFAULT )
		videoApiControl(PROP_HUE, VIDEO_PROP_HUE);
	if ( VIDEO_PROP_GAMMA != PROP_DEFAULT )
		videoApiControl(PROP_GAMMA, VIDEO_PROP_GAMMA);
	if ( VIDEO_PROP_WHITE_BALANCE != PROP_DEFAULT )
		videoApiControl(PROP_WHITE_BALANCE, VIDEO_PROP_WHITE_BALANCE);
	if ( VIDEO_PROP_POWER_LINE_FREQ != PROP_DEFAULT )
		videoApiControl(PROP_POWER_LINE_FREQ, VIDEO_PROP_POWER_LINE_FREQ);

 	for ( nop_i = 0; nop_i < 10000000; nop_i++ ) __asm __volatile("l.nop   0");
	if ( VIDEO_PROP_EXPOSURE != PROP_DEFAULT )
		videoApiControl(PROP_EXPOSURE, VIDEO_PROP_EXPOSURE);

	return 0;
}

int videoApiControl(char vpt, char vpl)
{
	int ret;

	switch(vpt)
	{
		case PROP_CONTRAST:
			ret = videoApiContrastSet(vpl);
			break;
		case PROP_BRIGHTNESS:
			ret = videoApiBrightnessSet(vpl);
			break;
		case PROP_SATURATION:
			ret = videoApiSaturationSet(vpl);
			break;
		case PROP_SHARPNESS:
			ret = videoApiSharpnessSet(vpl);
			break;
		case PROP_HUE:
			ret = videoApiHueSet(vpl);
			break;
		case PROP_GAMMA:
			ret = videoApiGammaSet(vpl);
			break;
		case PROP_WHITE_BALANCE:
			ret = videoApiWhitebalanceSet(vpl);
			break;
		case PROP_EXPOSURE:
			ret = videoApiExposureSet(vpl);
			break;
		case PROP_POWER_LINE_FREQ:
			ret = videoApiPowerlinefreqSet(vpl);
			break;
		default:
			ret = VIDEOAPISET_FAIL;
			uart_print("undefined video api\n\r");
	}
	isVideoPropertySet = 1;

	return ret;
}

int videoApiContrastSet(VIDEO_PROP_LEVEL vpl)
{
	int ret;
	char dataBuf[8];

	//uart_print("Con:");
	//uart_printInt(vpl);
	//uart_print("\n\r");

	dataBuf[0] = 0x33;
	dataBuf[1] = 0x99;
	switch(vpl)
	{
		// {{{
		case PROP_LEVEL_0:
			dataBuf[2] = 0x10;
			break;
		case PROP_LEVEL_1:
			dataBuf[2] = 0x12;
			break;
		case PROP_LEVEL_2:
			dataBuf[2] = 0x14;
			break;
		case PROP_LEVEL_3:
			dataBuf[2] = 0x18;
			break;
		case PROP_LEVEL_4:
			dataBuf[2] = 0x1c;
			break;
		case PROP_LEVEL_5:
			dataBuf[2] = 0x20;
			break;
		case PROP_LEVEL_6:
			dataBuf[2] = 0x22;
			break;
		case PROP_LEVEL_7:
			dataBuf[2] = 0x24;
			break;
		case PROP_LEVEL_8:
			dataBuf[2] = 0x26;
			break;
		case PROP_LEVEL_9:
			dataBuf[2] = 0x28;
			break;
		case PROP_LEVEL_10:
			dataBuf[2] = 0x2c;
			break;
		default:
			uart_print("Wrong level\n\r");
		// }}}
	}

	ret = i2c_write(0x30, 3, dataBuf);

	return ret;
}

int videoApiBrightnessSet(VIDEO_PROP_LEVEL vpl)
{
	int ret;
	char dataBuf[8];
	char readVal[4];

	//uart_print("Bri:");
	//uart_printInt(vpl);
	//uart_print("\n\r");

	dataBuf[0] = 0x33;
	dataBuf[1] = 0x90;
	ret = i2c_write(0x30, 2, dataBuf);
	if ( ret < 0 )
		return ret;

	ret = i2c_read(0x30, 1, readVal);
	if ( ret < 0 )
		return ret;

	if ( vpl < 5 ) 
		dataBuf[2] = (readVal[0] | 0x08);
	else
		dataBuf[2] = (readVal[0] & ~0x08);

	ret = i2c_write(0x30, 3, dataBuf);
	if ( ret < 0 )
		return ret;

	dataBuf[0] = 0x33;
	dataBuf[1] = 0x9A;

	switch(vpl)
	{
		// {{{
		case PROP_LEVEL_0:
		case PROP_LEVEL_10:
			dataBuf[2] = 0x50;
			break;
		case PROP_LEVEL_1:
		case PROP_LEVEL_9:
			dataBuf[2] = 0x40;
			break;
		case PROP_LEVEL_2:
		case PROP_LEVEL_8:
			dataBuf[2] = 0x30;
			break;
		case PROP_LEVEL_3:
		case PROP_LEVEL_7:
			dataBuf[2] = 0x20;
			break;
		case PROP_LEVEL_4:
		case PROP_LEVEL_6:
			dataBuf[2] = 0x10;
			break;
		case PROP_LEVEL_5:
			dataBuf[2] = 0x00;
			break;
		default:
			uart_print("Wrong level\n\r");
		// }}}
	}

	ret = i2c_write(0x30, 3, dataBuf);

	return ret;
}

int videoApiSaturationSet(VIDEO_PROP_LEVEL vpl)
{
	int ret;
	char dataBuf[8];

	//uart_print("Sat:");
	//uart_printInt(vpl);
	//uart_print("\n\r");

	dataBuf[0] = 0x33;
	dataBuf[1] = 0x94;
	switch(vpl)
	{
		// {{{
		case PROP_LEVEL_0:
			dataBuf[2] = 0x18;
			dataBuf[3] = 0x18;
			break;
		case PROP_LEVEL_1:
			dataBuf[2] = 0x20;
			dataBuf[3] = 0x20;
			break;
		case PROP_LEVEL_2:
			dataBuf[2] = 0x28;
			dataBuf[3] = 0x28;
			break;
		case PROP_LEVEL_3:
			dataBuf[2] = 0x30;
			dataBuf[3] = 0x30;
			break;
		case PROP_LEVEL_4:
			dataBuf[2] = 0x34;
			dataBuf[3] = 0x34;
			break;
		case PROP_LEVEL_5:
			dataBuf[2] = 0x40;
			dataBuf[3] = 0x40;
			break;
		case PROP_LEVEL_6:
			dataBuf[2] = 0x48;
			dataBuf[3] = 0x48;
			break;
		case PROP_LEVEL_7:
			dataBuf[2] = 0x50;
			dataBuf[3] = 0x50;
			break;
		case PROP_LEVEL_8:
			dataBuf[2] = 0x58;
			dataBuf[3] = 0x58;
			break;
		case PROP_LEVEL_9:
			dataBuf[2] = 0x60;
			dataBuf[3] = 0x60;
			break;
		case PROP_LEVEL_10:
			dataBuf[2] = 0x68;
			dataBuf[3] = 0x68;
			break;
		default:
			uart_print("Wrong level\n\r");
		// }}}
	}

	ret = i2c_write(0x30, 4, dataBuf);

	return ret;
}

int videoApiSharpnessSet(VIDEO_PROP_LEVEL vpl)
{
	int ret;
	char dataBuf[8];
	char readVal[4];

	//uart_print("Sha:");
	//uart_printInt(vpl);
	//uart_print("\n\r");

	dataBuf[0] = 0x33;
	dataBuf[1] = 0x06;
	ret = i2c_write(0x30, 2, dataBuf);
	if ( ret < 0 )
		return ret;

	ret = i2c_read(0x30, 1, readVal);
	if ( ret < 0 )
		return ret;

	dataBuf[2] = (readVal[0] | 0x08);

	ret = i2c_write(0x30, 3, dataBuf);
	if ( ret < 0 )
		return ret;

	dataBuf[0] = 0x33;
	dataBuf[1] = 0x71;

	switch(vpl)
	{
		// {{{
		case PROP_LEVEL_0:
			dataBuf[2] = 0x00;
			break;
		case PROP_LEVEL_1:
			dataBuf[2] = 0x01;
			break;
		case PROP_LEVEL_2:
			dataBuf[2] = 0x02;
			break;
		case PROP_LEVEL_3:
			dataBuf[2] = 0x03;
			break;
		case PROP_LEVEL_4:
			dataBuf[2] = 0x04;
			break;
		case PROP_LEVEL_5:
			dataBuf[2] = 0x05;
			break;
		case PROP_LEVEL_6:
			dataBuf[2] = 0x06;
			break;
		case PROP_LEVEL_7:
			dataBuf[2] = 0x07;
			break;
		case PROP_LEVEL_8:
			dataBuf[2] = 0x08;
			break;
		case PROP_LEVEL_9:
			dataBuf[2] = 0x09;
			break;
		case PROP_LEVEL_10:
			dataBuf[2] = 0x0a;
			break;
		default:
			uart_print("Wrong level\n\r");
		// }}}
	}

	ret = i2c_write(0x30, 3, dataBuf);

	return ret;
}

int videoApiHueSet(VIDEO_PROP_LEVEL vpl)
{
	int ret;
	char dataBuf[8];
	char readVal[4];

	//uart_print("Hue:");
	//uart_printInt(vpl);
	//uart_print("\n\r");

	dataBuf[0] = 0x33;
	dataBuf[1] = 0x90;
	ret = i2c_write(0x30, 2, dataBuf);
	if ( ret < 0 )
		return ret;

	ret = i2c_read(0x30, 1, readVal);
	if ( ret < 0 )
		return ret;

	if ( vpl < 5 )
		dataBuf[2] = ((readVal[0] & ~0x03) | 0x01);
	else
		dataBuf[2] = ((readVal[0] & ~0x03) | 0x02);

	ret = i2c_write(0x30, 3, dataBuf);
	if ( ret < 0 )
		return ret;

	dataBuf[0] = 0x33;
	dataBuf[1] = 0x92;

	switch(vpl)
	{
		// {{{
		case PROP_LEVEL_0:
			dataBuf[2] = 0x67;
			dataBuf[3] = 0x4b;
			break;
		case PROP_LEVEL_1:
			dataBuf[2] = 0x72;
			dataBuf[3] = 0x3a;
			break;
		case PROP_LEVEL_2:
			dataBuf[2] = 0x79;
			dataBuf[3] = 0x27;
			break;
		case PROP_LEVEL_3:
			dataBuf[2] = 0x7e;
			dataBuf[3] = 0x14;
			break;
		case PROP_LEVEL_4:
			dataBuf[2] = 0x80;
			dataBuf[3] = 0x00;
			break;
		case PROP_LEVEL_5:
			dataBuf[2] = 0x7e;
			dataBuf[3] = 0x14;
			break;
		case PROP_LEVEL_6:
			dataBuf[2] = 0x79;
			dataBuf[3] = 0x27;
			break;
		case PROP_LEVEL_7:
			dataBuf[2] = 0x72;
			dataBuf[3] = 0x3a;
			break;
		case PROP_LEVEL_8:
			dataBuf[2] = 0x67;
			dataBuf[3] = 0x4b;
			break;
		case PROP_LEVEL_9:
			dataBuf[2] = 0x5a;
			dataBuf[3] = 0x5a;
			break;
		case PROP_LEVEL_10:
			dataBuf[2] = 0x4b;
			dataBuf[3] = 0x67;
			break;
		default:
			uart_print("Wrong level\n\r");
		// }}}
	}

	ret = i2c_write(0x30, 4, dataBuf);

	return ret;

}

int videoApiGammaSet(VIDEO_PROP_LEVEL vpl)
{
	int ret;
	char dataBuf[18];

	//uart_print("Gam:");
	//uart_printInt(vpl);
	//uart_print("\n\r");

	dataBuf[0] = 0x33;
	dataBuf[1] = 0x40;
	switch(vpl)
	{
		// {{{
		case PROP_LEVEL_0:
			dataBuf[ 2] = 0x00; 
			dataBuf[ 3] = 0x0a;
			dataBuf[ 4] = 0x20;
			dataBuf[ 5] = 0x36;
			dataBuf[ 6] = 0x4b;
			dataBuf[ 7] = 0x5a;
			dataBuf[ 8] = 0x66;
			dataBuf[ 9] = 0x6f;
			dataBuf[10] = 0x79;
			dataBuf[11] = 0x87;
			dataBuf[12] = 0x94;
			dataBuf[13] = 0xa0;
			dataBuf[14] = 0xb5;
			dataBuf[15] = 0xc8;
			dataBuf[16] = 0xd9;
			dataBuf[17] = 0x34;
			break;
		case PROP_LEVEL_1:
			dataBuf[ 2] = 0x00; 
			dataBuf[ 3] = 0x0d;
			dataBuf[ 4] = 0x23;
			dataBuf[ 5] = 0x39;
			dataBuf[ 6] = 0x4e;
			dataBuf[ 7] = 0x5d;
			dataBuf[ 8] = 0x69;
			dataBuf[ 9] = 0x72;
			dataBuf[10] = 0x7c;
			dataBuf[11] = 0x8a;
			dataBuf[12] = 0x97;
			dataBuf[13] = 0xa3;
			dataBuf[14] = 0xb8;
			dataBuf[15] = 0xcb;
			dataBuf[16] = 0xdc;
			dataBuf[17] = 0x30;
			break;
		case PROP_LEVEL_2:
			dataBuf[ 2] = 0x00; 
			dataBuf[ 3] = 0x10;
			dataBuf[ 4] = 0x26;
			dataBuf[ 5] = 0x3c;
			dataBuf[ 6] = 0x51;
			dataBuf[ 7] = 0x60;
			dataBuf[ 8] = 0x6c;
			dataBuf[ 9] = 0x75;
			dataBuf[10] = 0x7f;
			dataBuf[11] = 0x8d;
			dataBuf[12] = 0x9a;
			dataBuf[13] = 0xa6;
			dataBuf[14] = 0xbb;
			dataBuf[15] = 0xce;
			dataBuf[16] = 0xdf;
			dataBuf[17] = 0x2c;
			break;
		case PROP_LEVEL_3:
			dataBuf[ 2] = 0x03; 
			dataBuf[ 3] = 0x13;
			dataBuf[ 4] = 0x29;
			dataBuf[ 5] = 0x3f;
			dataBuf[ 6] = 0x54;
			dataBuf[ 7] = 0x63;
			dataBuf[ 8] = 0x6f;
			dataBuf[ 9] = 0x78;
			dataBuf[10] = 0x82;
			dataBuf[11] = 0x90;
			dataBuf[12] = 0x9d;
			dataBuf[13] = 0xa9;
			dataBuf[14] = 0xbe;
			dataBuf[15] = 0xd1;
			dataBuf[16] = 0xe2;
			dataBuf[17] = 0x28;
			break;
		case PROP_LEVEL_4:
			dataBuf[ 2] = 0x06; 
			dataBuf[ 3] = 0x16;
			dataBuf[ 4] = 0x2c;
			dataBuf[ 5] = 0x42;
			dataBuf[ 6] = 0x57;
			dataBuf[ 7] = 0x66;
			dataBuf[ 8] = 0x72;
			dataBuf[ 9] = 0x7b;
			dataBuf[10] = 0x85;
			dataBuf[11] = 0x93;
			dataBuf[12] = 0xa0;
			dataBuf[13] = 0xac;
			dataBuf[14] = 0xc1;
			dataBuf[15] = 0xd4;
			dataBuf[16] = 0xe5;
			dataBuf[17] = 0x24;
			break;
		case PROP_LEVEL_5:
			dataBuf[ 2] = 0x09; 
			dataBuf[ 3] = 0x19;
			dataBuf[ 4] = 0x2f;
			dataBuf[ 5] = 0x45;
			dataBuf[ 6] = 0x5a;
			dataBuf[ 7] = 0x69;
			dataBuf[ 8] = 0x75;
			dataBuf[ 9] = 0x7e;
			dataBuf[10] = 0x88;
			dataBuf[11] = 0x96;
			dataBuf[12] = 0xa3;
			dataBuf[13] = 0xaf;
			dataBuf[14] = 0xc4;
			dataBuf[15] = 0xd7;
			dataBuf[16] = 0xe8;
			dataBuf[17] = 0x20;
			break;
		case PROP_LEVEL_6:
			dataBuf[ 2] = 0x0c; 
			dataBuf[ 3] = 0x1c;
			dataBuf[ 4] = 0x32;
			dataBuf[ 5] = 0x48;
			dataBuf[ 6] = 0x5d;
			dataBuf[ 7] = 0x6c;
			dataBuf[ 8] = 0x78;
			dataBuf[ 9] = 0x81;
			dataBuf[10] = 0x8b;
			dataBuf[11] = 0x99;
			dataBuf[12] = 0xa6;
			dataBuf[13] = 0xb2;
			dataBuf[14] = 0xc7;
			dataBuf[15] = 0xda;
			dataBuf[16] = 0xeb;
			dataBuf[17] = 0x1c;
			break;
		case PROP_LEVEL_7:
			dataBuf[ 2] = 0x0f; 
			dataBuf[ 3] = 0x1f;
			dataBuf[ 4] = 0x35;
			dataBuf[ 5] = 0x4b;
			dataBuf[ 6] = 0x60;
			dataBuf[ 7] = 0x6f;
			dataBuf[ 8] = 0x7b;
			dataBuf[ 9] = 0x84;
			dataBuf[10] = 0x8e;
			dataBuf[11] = 0x9c;
			dataBuf[12] = 0xa9;
			dataBuf[13] = 0xb5;
			dataBuf[14] = 0xca;
			dataBuf[15] = 0xdd;
			dataBuf[16] = 0xee;
			dataBuf[17] = 0x18;
			break;
		case PROP_LEVEL_8:
			dataBuf[ 2] = 0x12; 
			dataBuf[ 3] = 0x22;
			dataBuf[ 4] = 0x38;
			dataBuf[ 5] = 0x4e;
			dataBuf[ 6] = 0x63;
			dataBuf[ 7] = 0x72;
			dataBuf[ 8] = 0x7e;
			dataBuf[ 9] = 0x87;
			dataBuf[10] = 0x91;
			dataBuf[11] = 0x9f;
			dataBuf[12] = 0xac;
			dataBuf[13] = 0xb8;
			dataBuf[14] = 0xcd;
			dataBuf[15] = 0xe0;
			dataBuf[16] = 0xf1;
			dataBuf[17] = 0x14;
			break;
		case PROP_LEVEL_9:
			dataBuf[ 2] = 0x15; 
			dataBuf[ 3] = 0x25;
			dataBuf[ 4] = 0x3b;
			dataBuf[ 5] = 0x51;
			dataBuf[ 6] = 0x66;
			dataBuf[ 7] = 0x75;
			dataBuf[ 8] = 0x81;
			dataBuf[ 9] = 0x8a;
			dataBuf[10] = 0x94;
			dataBuf[11] = 0xa2;
			dataBuf[12] = 0xaf;
			dataBuf[13] = 0xbb;
			dataBuf[14] = 0xd0;
			dataBuf[15] = 0xe3;
			dataBuf[16] = 0xf4;
			dataBuf[17] = 0x10;
			break;
		case PROP_LEVEL_10:
			dataBuf[ 2] = 0x18; 
			dataBuf[ 3] = 0x28;
			dataBuf[ 4] = 0x3e;
			dataBuf[ 5] = 0x54;
			dataBuf[ 6] = 0x69;
			dataBuf[ 7] = 0x78;
			dataBuf[ 8] = 0x84;
			dataBuf[ 9] = 0x8d;
			dataBuf[10] = 0x97;
			dataBuf[11] = 0xa5;
			dataBuf[12] = 0xb2;
			dataBuf[13] = 0xbe;
			dataBuf[14] = 0xd3;
			dataBuf[15] = 0xe6;
			dataBuf[16] = 0xf7;
			dataBuf[17] = 0x0c;
			break;
		default:
			uart_print("Wrong level\n\r");
		// }}}
	}

	ret = i2c_write(0x30, 18, dataBuf);

	return ret;
}

int videoApiWhitebalanceSet(VIDEO_PROP_LEVEL vpl)
{
	int ret;
	char dataBuf[8];
	char readVal[4];

	//uart_print("Whi:");
	//uart_printInt(vpl);
	//uart_print("\n\r");

	dataBuf[0] = 0x33;
	dataBuf[1] = 0x06;
	ret = i2c_write(0x30, 2, dataBuf);
	if ( ret < 0 )
		return ret;

	ret = i2c_read(0x30, 1, readVal);
	if ( ret < 0 )
		return ret;

	dataBuf[0] = 0x33;
	dataBuf[1] = 0x06;

	if ( vpl == PROP_AUTO_ON )
	{
		dataBuf[2] = readVal[0] & ~0x02;
		ret = i2c_write(0x30, 3, dataBuf);
		if ( ret < 0 )
			return ret;
	}
	else
	{
		dataBuf[2] = readVal[0] | 0x02;
		ret = i2c_write(0x30, 3, dataBuf);
		if ( ret < 0 )
			return ret;

		dataBuf[0] = 0x33;
		dataBuf[1] = 0x37;
		switch(vpl)
		{
			case PROP_LEVEL_0:
				dataBuf[ 2] = 0x40; 
				dataBuf[ 3] = 0x40;
				dataBuf[ 4] = 0x5c;
				break;
			case PROP_LEVEL_1:
				dataBuf[ 2] = 0x47; 
				dataBuf[ 3] = 0x40;
				dataBuf[ 4] = 0x56;
				break;
			case PROP_LEVEL_2:
				dataBuf[ 2] = 0x4a; 
				dataBuf[ 3] = 0x40;
				dataBuf[ 4] = 0x52;
				break;
			case PROP_LEVEL_3:
				dataBuf[ 2] = 0x4d; 
				dataBuf[ 3] = 0x40;
				dataBuf[ 4] = 0x4f;
				break;
			case PROP_LEVEL_4:
				dataBuf[ 2] = 0x52; 
				dataBuf[ 3] = 0x40;
				dataBuf[ 4] = 0x4b;
				break;
			case PROP_LEVEL_5:
				dataBuf[ 2] = 0x54; 
				dataBuf[ 3] = 0x40;
				dataBuf[ 4] = 0x49;
				break;
			case PROP_LEVEL_6:
				dataBuf[ 2] = 0x56; 
				dataBuf[ 3] = 0x40;
				dataBuf[ 4] = 0x47;
				break;
			case PROP_LEVEL_7:
				dataBuf[ 2] = 0x58; 
				dataBuf[ 3] = 0x40;
				dataBuf[ 4] = 0x45;
				break;
			case PROP_LEVEL_8:
				dataBuf[ 2] = 0x59; 
				dataBuf[ 3] = 0x40;
				dataBuf[ 4] = 0x43;
				break;
			case PROP_LEVEL_9:
				dataBuf[ 2] = 0x5c; 
				dataBuf[ 3] = 0x40;
				dataBuf[ 4] = 0x42;
				break;
			case PROP_LEVEL_10:
				dataBuf[ 2] = 0x5d; 
				dataBuf[ 3] = 0x40;
				dataBuf[ 4] = 0x40;
				break;

			default:
				uart_print("Wrong level\n\r");
				ret = WRONG_LEVEL;
		}
		ret = i2c_write(0x30, 5, dataBuf);
	}

	return ret;
}

int videoApiExposureSet(VIDEO_PROP_LEVEL vpl)
{
	int ret;
	char dataBuf[8];

	//uart_print("Exp:");
	//uart_printInt(vpl);
	//uart_print("\n\r");

	dataBuf[0] = 0x30;
	dataBuf[1] = 0x13;

	if ( vpl == PROP_AUTO_ON )
	{
		dataBuf[2] = 0xf7;
		//while (IMAGE_FRAME_CNT < 2)
		//		;
		//while (S_IMAGE_FRAME_CNT < 2)
		//		;
		ret = i2c_write(0x30, 3, dataBuf);
		if ( ret < 0 )
			return ret;
	}
	else
	{
		dataBuf[2] = 0xe2;
		ret = i2c_write(0x30, 3, dataBuf);
		if ( ret < 0 )
			return ret;

		dataBuf[0] = 0x30;
		dataBuf[1] = 0x02;
		switch(vpl)
		{
			// {{{
			case PROP_LEVEL_0:
				dataBuf[ 2] = 0x01; 
				dataBuf[ 3] = 0x10;
				break;
			case PROP_LEVEL_1:
				dataBuf[ 2] = 0x01; 
				dataBuf[ 3] = 0x20;
				break;
			case PROP_LEVEL_2:
				dataBuf[ 2] = 0x01; 
				dataBuf[ 3] = 0x30;
				break;
			case PROP_LEVEL_3:
				dataBuf[ 2] = 0x01; 
				dataBuf[ 3] = 0x50;
				break;
			case PROP_LEVEL_4:
				dataBuf[ 2] = 0x01; 
				dataBuf[ 3] = 0x70;
				break;
			case PROP_LEVEL_5:
				dataBuf[ 2] = 0x01; 
				dataBuf[ 3] = 0x90;
				break;
			case PROP_LEVEL_6:
				dataBuf[ 2] = 0x01; 
				dataBuf[ 3] = 0xb0;
				break;
			case PROP_LEVEL_7:
				dataBuf[ 2] = 0x01; 
				dataBuf[ 3] = 0xd0;
				break;
			case PROP_LEVEL_8:
				dataBuf[ 2] = 0x01; 
				dataBuf[ 3] = 0xf0;
				break;
			case PROP_LEVEL_9:
				dataBuf[ 2] = 0x02; 
				dataBuf[ 3] = 0x00;
				break;
			case PROP_LEVEL_10:
				dataBuf[ 2] = 0x02; 
				dataBuf[ 3] = 0x10;
				break;
			default:
				uart_print("Wrong level\n\r");
				ret = WRONG_LEVEL;
			// }}}
		}
		ret = i2c_write(0x30, 4, dataBuf);
	}

	return ret;
}

int videoApiPowerlinefreqSet(VIDEO_PROP_LEVEL vpl)
{
	int ret;
	char dataBuf[8];
	char readVal[4];

	//uart_print("Pow:");
	//uart_printInt(vpl);
	//uart_print("\n\r");

	dataBuf[0] = 0x30;
	dataBuf[1] = 0x14;
	ret = i2c_write(0x30, 2, dataBuf);
	if ( ret < 0 )
		return ret;

	ret = i2c_read(0x30, 1, readVal);
	if ( ret < 0 )
		return ret;

	switch(vpl)
	{
		// {{{
		case PROP_LEVEL_0:
			dataBuf[2] = ((readVal[0] & ~0xc0) | 0x80);
			break;
		case PROP_LEVEL_1:
			dataBuf[2] = ((readVal[0] & ~0xc0) | 0x00);
			break;
		default:
			uart_print("Wrong level\n\r");
		// }}}
	}

	ret = i2c_write(0x30, 3, dataBuf);

	return ret;
}





