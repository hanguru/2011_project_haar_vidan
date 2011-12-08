/***********************************************************
* 	
*	AIC3101 Register Define Header 
*                              
*	File Name : AIC3101_REG.h
*	Date Created :
*	Last modified :
*
************************************************************/

#ifndef _AIC3101_REG_H_
#define _AIC3101_REG_H_


/* AIC3101 Register Define */

#define PAGE_SELECT					0
#define SOFT_RESET					1
#define CODEC_SAMPLE_RATE_SEL		2
#define PLL_PROGRAMMING_A			3
#define PLL_PROGRAMMING_B			4
#define PLL_PROGRAMMING_C			5
#define PLL_PROGRAMMING_D			6
#define CODEC_DATAPATH_SETUP		7
#define AUDIO_SERIAL_DATA_INTFACE_A	8
#define AUDIO_SERIAL_DATA_INTFACE_B	9
#define AUDIO_SERIAL_DATA_INTFACE_C	10
#define AUDIO_CODEC_OVERFLOW		11
#define AUDIO_CODEC_DIGITAL_FILTER	12

#define LEFT_ADC_PGA_GAIN			15
#define RIGHT_ADC_PGA_GAIN			16
#define MIC2LR_LEFT_ADC				17
#define MIC2LR_RIGHT_ADC			18
#define LINE1L_LEFT_ADC				19
#define LINE1R_LEFT_ADC				21
#define LINE1R_RIGHT_ADC			22
#define LINE1L_RIGHT_ADC			24

#define MICBIAS						25

#define LEFT_AGC_A					26
#define LEFT_AGC_B					27
#define LEFT_AGC_C					28
#define RIGHT_AGC_A					29
#define RIGHT_AGC_B					30
#define RIGHT_AGC_C					31

#define DAC_POWER_OUTPUT_DRIVER		37
#define HIGHPOWER_OUTPUT_DRIVER		38

#define DAC_OUTPUT_SWITCHING		41
#define LEFT_DAC_VOLUME				43
#define RIGHT_DAC_VOLUME			44

#define PGA_L_HPLOUT_VOLUME			46
#define DAC_L1_HPLOUT_VOLUME		47
#define PGA_R_HPLOUT_VOLUME			49
#define DAC_R1_HPLOUT_VOLUME		50
#define HPLOUT_OUTPUT_LEVEL			51

#define PGA_L_HPLCOM_VOLUME			53
#define DAC_L1_HPLCOM_VOLUME		54
#define PGA_R_HPLCOM_VOLUME			56
#define DAC_R1_HPLCOM_VOLUME		57
#define HPLCOM_OUTPUT_LEVEL			58

#define PGA_L_HPROUT_VOLUME			60
#define DAC_L1_HPROUT_VOLUME		61
#define PGA_R_HPROUT_VOLUME			63
#define DAC_R1_HPROUT_VOLUME		64
#define HPROUT_OUTPUT_LEVEL			65

#define PGA_L_HPRCOM_VOLUME			67
#define DAC_L1_HPRCOM_VOLUME		68
#define PGA_R_HPRCOM_VOLUME			70
#define DAC_R1_HPRCOM_VOLUME		71
#define HPRCOM_OUTPUT_LEVEL			72

#define PGA_L_MONOLOPM_VOLUME		74
#define DAC_L1_MONOLOPM_VOLUME		75
#define PGA_R_MONOLOPMT_VOLUME		77
#define DAC_R1_MONOLOPM_VOLUME		78
#define MONOLOPM_OUTPUT_LEVEL		79

#define PGA_L_LEFT_LOPM_VOLUME		81
#define DAC_L1_LEFT_LOPM_VOLUME		82
#define PGA_R_LEFT_LOPM_VOLUME		84
#define DAC_R1_LEFT_LOPM_VOLUME		85
#define LEFT_LOPMM_OUTPUT_LEVEL		86

#define PGA_L_RIGHT_LOPM_VOLUME		88
#define DAC_L1_RIGHT_LOPM_VOLUME	89
#define PGA_R_RIGHT_LOPM_VOLUME		91
#define DAC_R1_RIGHT_LOPM_VOLUME	92
#define RIGHT_LOPMM_OUTPUT_LEVEL	93

#define GPIO1						98
#define GPIO2						99
#define ADDITIONAL_GPIO_A			100
#define ADDITIONAL_GPIO_B			101
#define CLOCK_GENERATION			102


#endif
