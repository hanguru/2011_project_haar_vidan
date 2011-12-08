#include "i2s.h"

#include "map_hif.h"
#include "interrupt_handler.h" //jykim_080725_ucos_porintg++
#include "usb.h" //jykim_080725_ucos_porintg++
#include "commandProcess.h" //jykim_080725_ucos_porintg++
#include "uart.h" 

int i2s_int_enabled = 0; //090413_hunnoh_i2s+
int pcm_exist = 0;
int lost_pcm_len = 0;

void init_i2s(void)
{
	I2S_RegSet(I2S_RxCR, (RX_STEREO << 21) & I2S_StereoMonoClr);
	I2S_RegSet(I2S_RxCR, I2S_CompactMode); 
	I2S_DataSize(I2S_RxCR, (DATA_FORMAT << 16) & I2S_DataSizeClr);
	I2S_IrqCnt(I2S_RxCR, 512);
	//I2S_IrqCnt(I2S_RxCR, 720);

	//I2S_IrqCnt(I2S_RxCR, 256);
	//I2S_RegSet(I2S_RxCR, I2S_En);

	//IntEnable(I2S_RX_IRQ_BIT);
	//uart_print("I2S_initialized\n\r");

	return;
}

void i2s_interrupt_handler(void)
{
	int pcmDataCnt = 0;
	int pcmDataCnt_i = 0;
	volatile int temp;
	pcmDataCnt = I2S_RxCnt;
	if ( pcmDataCnt >= 1024 )
	{
	  uart_print("!!\n\r");
	}

	//Debugging Error
	if ( pcminDualStreamBuf.full[(int)pcminDualStreamBuf.set_idx] ) 
	{
		uart_print("p\n\r");
		for (pcmDataCnt_i = 0; pcmDataCnt_i < pcmDataCnt; pcmDataCnt_i += 4) {
			temp = *(volatile int*) I2S_FIFO;
			lost_pcm_len += 4;
		}
		return;
	}
	else
	{
		if ( pcminDualStreamBuf.len[(int)pcminDualStreamBuf.set_idx] + pcmDataCnt > MAX_PCM_STREAM_LEN )
		{
			uart_print("j\n\r");
		}
	}

	for (pcmDataCnt_i = 0; pcmDataCnt_i < pcmDataCnt; pcmDataCnt_i
			+= 4) {
		*(volatile int*) (PCMIN_STREAM_ADDR
				+ (pcminDualStreamBuf.set_idx * MAX_PCM_STREAM_LEN)
				+ pcminDualStreamBuf.len[(int)pcminDualStreamBuf.set_idx])
				= *(volatile int*) I2S_FIFO;
		pcminDualStreamBuf.len[(int)pcminDualStreamBuf.set_idx] += 4;
	}
	if ( pcminDualStreamBuf.len[(int)pcminDualStreamBuf.set_idx] >= MAX_PCM_STREAM_LEN - 1024 )
	{
		pcminDualStreamBuf.full[(int)pcminDualStreamBuf.set_idx] = 1;
		pcminDualStreamBuf.count++;
		pcminDualStreamBuf.set_idx++;
		if (pcminDualStreamBuf.set_idx == PCM_BUFFER_CNT) {
			pcminDualStreamBuf.set_idx = 0;
		}
		//pcm_exist = 1;
	}
	return;
}






void I2S_RegSet(volatile int reg, int val) {
	*(volatile int*) reg |= val;
	return;
}
void I2S_RegClr(volatile int reg, int val) {
	*(volatile int*) reg &= ~val;
	return;
}


void I2S_DataSize(volatile int reg, int val) {
	*(volatile int*) reg &= ~I2S_DataSizeClr;
	*(volatile int*) reg |= val;
	return;
}

void I2S_IrqCnt(volatile int reg, short val) {
	*(volatile int*) reg &= ~I2S_SizeBits;
	*(volatile int*) reg |= (val & I2S_SizeBits);
	return;
}



