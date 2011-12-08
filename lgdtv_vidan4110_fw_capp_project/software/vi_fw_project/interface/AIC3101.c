/***********************************************************
* 	
*	AIC3101 Initialization & Control Module  
*                              
*	File Name : AIC3101.c 
*	Date Created :
*	Last modified :
*
************************************************************/

#include "AIC3101.h"
#include "AIC3101_REG.h"
#include "i2c_operation.h"

void AIC3101_RSET( Uint16 reg_num, Uint16 reg_val )
{
    Uint16 data;

    data = (reg_num << 8) | reg_val;       	// 7-bit Device Address & 8-bit Register Data

		i2c_write(AIC3101_I2C_ADDR, 2, (char*)&data);
		
}


void AIC3101InputGain( Uint8 dB )
{
	AIC3101_RSET(  LEFT_ADC_PGA_GAIN, dB<<1 );    			// Mute Off, (dB) dB
    AIC3101_RSET(  RIGHT_ADC_PGA_GAIN, dB<<1 );    			// Mute Off, (dB) dB	
}


void AIC3101OutputAttenuation( Uint8 dB )
{
	AIC3101_RSET( LEFT_DAC_VOLUME, (dB<<1) & 0x7F );    		// Mute Off, -(dB) dB
    AIC3101_RSET( RIGHT_DAC_VOLUME, (dB<<1) & 0x7F  );    		// Mute Off, -(dB) dB
}

void AIC3101InputSelect( Uint8 input_sel )
{
	if( input_sel == MIC )
	{
		AIC3101_RSET( LINE1L_LEFT_ADC, 0x7C ); 				// not connected Power up
    	AIC3101_RSET( LINE1R_RIGHT_ADC, 0x7C ); 			// not connected Power up

		AIC3101_RSET( MIC2LR_LEFT_ADC, 0x0F ); 				// MIC2L-->Left: 0dB, MIC2L-->Right: not connected
		//AIC3101_RSET( MIC2LR_LEFT_ADC, 0x0 ); 				// MIC2L-->Left: 0dB, MIC2L-->Right: not connected
    	AIC3101_RSET( MIC2LR_RIGHT_ADC, 0xF0 ); 			// MIC2R-->Rihgt: 0dB, MIC2L-->Left: not connected
    	//AIC3101_RSET( MIC2LR_RIGHT_ADC, 0x0 ); 			// MIC2R-->Rihgt: 0dB, MIC2L-->Left: not connected

//		AIC3101_RSET( MICBIAS, 0x40 ); 						// Mic-Bias=2.0V
		//AIC3101_RSET( MICBIAS, 0x80 ); 						// Mic-Bias=2.5V
		AIC3101_RSET( MICBIAS, 0x0 ); 						// Mic-Bias=2.5V
	}
	else
	{
		AIC3101_RSET( LINE1L_LEFT_ADC, 0x04 ); 				// Single-Ended, 0dB, Power up
   		AIC3101_RSET( LINE1R_RIGHT_ADC, 0x04 ); 			// Single-Ended, 0dB, Power up

		AIC3101_RSET( MIC2LR_LEFT_ADC, 0xFF ); 				// not connected
    	AIC3101_RSET( MIC2LR_RIGHT_ADC, 0xFF ); 			// not connected

		AIC3101_RSET( MICBIAS, 0x00 ); 						// Mic-Bias power down
	}
}


//void WaitCycles( Uint32 count )
//{
//    Uint32 i;
//
//	for( i=0; i < count; i++ )		
//		 __asm __volatile("l.nop   0"); 
//}


void AIC3101Init( Uint16 ms, Uint16 sampling_freq, Uint8 input_sel, Uint8 dB )
{

	AIC3101_RSET( PAGE_SELECT, 0 ); 							// Select Page 0
    AIC3101_RSET( SOFT_RESET, 0x80 );   						// Reset the AIC3106
    
	/****     Sampling Rate Setting	( Codec System Clock : 12.288MHz )    ***/		
	AIC3101_RSET( CODEC_SAMPLE_RATE_SEL, sampling_freq ); 		// ADC fs=fs(ref)/X, DAC fs=fs(ref)/X;
	AIC3101_RSET( PLL_PROGRAMMING_A, 0x10 );  					// PLL off, Q=2(48KHz), P=0  

	AIC3101_RSET( CODEC_DATAPATH_SETUP, 0x00 );  				//R7:Left DAC=LEFT, Right DAC=RIGHT

	if( ms == MASTER )
		AIC3101_RSET( AUDIO_SERIAL_DATA_INTFACE_A, 0xC0 );  	// BCLK=Master, WCLK=Master
	else
		AIC3101_RSET( AUDIO_SERIAL_DATA_INTFACE_A, 0x00 );  	// BCLK=slave, WCLK=slave

	AIC3101_RSET( AUDIO_SERIAL_DATA_INTFACE_B, 0x00 );  		// I2S mode, Word len=word_len, Bit clock rate=continuous
    AIC3101_RSET( AUDIO_SERIAL_DATA_INTFACE_C, 0x00);  			// Data offset=0

	AIC3101_RSET( AUDIO_CODEC_OVERFLOW, 0xC1 );  				//R11 
	AIC3101_RSET( AUDIO_CODEC_DIGITAL_FILTER, 0xF0 ); 			//R12 

	AIC3101_RSET( LINE1R_LEFT_ADC, 0x78);						// not connected
	AIC3101_RSET( LINE1L_RIGHT_ADC, 0x78);						// not connected

	AIC3101_RSET( LINE1L_LEFT_ADC, 0x04 ); 						// Single-Ended, 0dB, Power up
    AIC3101_RSET( LINE1R_RIGHT_ADC, 0x04 ); 					// Single-Ended, 0dB, Power up
/*   
    if( input_sel == MIC )
	{
		AIC3101_RSET(  LEFT_ADC_PGA_GAIN, 80 );    				// Mute Off, 40dB (default vol for mic)
    	AIC3101_RSET(  RIGHT_ADC_PGA_GAIN, 80 );    			// Mute Off, 40dB (default vol for mic)
	}
	else
	{
		AIC3101_RSET(  LEFT_ADC_PGA_GAIN, 10 );    				// Mute Off, 5dB (default vol for line-in)
    	AIC3101_RSET(  RIGHT_ADC_PGA_GAIN, 10 );    			// Mute Off, 5dB (default vol for line-in)

	}
*/
	AIC3101InputGain( dB );
    AIC3101InputSelect( input_sel );

	//AGC Control Setting //////////////////////////////////////////////////////////////
    AIC3101_RSET( LEFT_AGC_A,  0xB3 );    							// AGC off
	AIC3101_RSET( LEFT_AGC_B,  0x24 );    							// AGC max gain=0
	AIC3101_RSET( LEFT_AGC_C,  0x00 );    							// AGC max gain=0
    AIC3101_RSET( RIGHT_AGC_A, 0xB3 );    							// AGC off
    AIC3101_RSET( RIGHT_AGC_B, 0x24 );    							// AGC max gain=0
    AIC3101_RSET( RIGHT_AGC_C, 0x00 );    							// AGC max gain=0
	//////////////////////////////////////////////////////////////////////////////////////

    AIC3101_RSET( DAC_POWER_OUTPUT_DRIVER, 0xE0 ); 				// Left DAC On, Right DAC On, HPLCOM:Single-Ended
    AIC3101_RSET( HIGHPOWER_OUTPUT_DRIVER, 0x10 );				// HPRCOM:Single-End, Short-Circuit Off

    AIC3101_RSET( DAC_OUTPUT_SWITCHING, 0 );    				// Left DAC-->DAC_L1, Right DAC-->DAC_R1
    AIC3101_RSET( LEFT_DAC_VOLUME, 0 );    						// Mute Off, 0dB
    AIC3101_RSET( RIGHT_DAC_VOLUME, 0 );    					// Mute Off, 0dB

    AIC3101_RSET( DAC_L1_HPLOUT_VOLUME, 0x80 ); 				// DAC_L1-->HPLOUT, 0dB
    AIC3101_RSET( HPLOUT_OUTPUT_LEVEL, 0x09 ); 					// Mute Off, 0dB, Power-up
    AIC3101_RSET( HPLCOM_OUTPUT_LEVEL, 0 );    					// Mute On, 0dB, Not power-up
    AIC3101_RSET( DAC_R1_HPROUT_VOLUME, 0x80 ); 				// DAC_R1-->HPROUT, 0dB
    AIC3101_RSET( HPROUT_OUTPUT_LEVEL, 0x09 ); 					// Mute Off, 0dB, Power-up
    AIC3101_RSET( HPRCOM_OUTPUT_LEVEL, 0 );    					// Mute On, 0dB, Not power-up

    AIC3101_RSET( DAC_L1_LEFT_LOPM_VOLUME, 0x80 ); 				// DAC_L1-->LEFT_LOP/M, 0dB
    AIC3101_RSET( LEFT_LOPMM_OUTPUT_LEVEL, 0x09 ); 				//  Mute Off, 0dB, Power-up
    AIC3101_RSET( DAC_R1_RIGHT_LOPM_VOLUME, 0x80 ); 			// DAC_R1-->RIGHT_LOP/M, 0dB
    AIC3101_RSET( RIGHT_LOPMM_OUTPUT_LEVEL, 0x09 ); 			//  Mute Off, 0dB, Power-up

    AIC3101_RSET( ADDITIONAL_GPIO_B, 0x01 ); 					// CODEC_CLKIN=CLKDIV_OUT
    AIC3101_RSET( CLOCK_GENERATION, 0x00 );    					// PLLCLK_IN=MCLK,  CLKDIV_IN=MCLK

	WaitCycles( 2000 );
}

		
