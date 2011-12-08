/***********************************************************
* 	
*	AIC3101 Initialization & Control Module Header 
*                              
*	File Name : AIC3101.h
*	Date Created :
*	Last modified :
*
************************************************************/

#ifndef _AIC3101_H_
#define _AIC3101_H_

typedef	unsigned char Uint8;
typedef unsigned short Uint16;
typedef unsigned int Uint32;


extern void AIC3101Init( Uint16 ms, Uint16 sampling_freq, Uint8 input, Uint8 dB );
extern void AIC3101InputGain( Uint8 dB );
extern void AIC3101OutputAttenuation( Uint8 dB );
extern void AIC3101InputSelect( Uint8 input_sel );

#define AIC3101_I2C_ADDR			0x18    // I2C address

#define AIC3101_FS_48KHz			0x00
#define AIC3101_FS_24KHz			0x22
#define AIC3101_FS_16KHz			0x44
#define AIC3101_FS_12KHz			0x66
#define AIC3101_FS_8KHz				0xAA

#define MIC							0x01
#define LINE_IN						0x02

#define MASTER						1
#define SLAVE						2


#endif
