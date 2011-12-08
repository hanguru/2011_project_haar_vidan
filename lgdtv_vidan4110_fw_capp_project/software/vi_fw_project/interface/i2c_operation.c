#include "map.h"
#include "map_hif.h"
#include "i2c_operation.h"


void i2c_init(void)
{
	ISP_I2C_CTRL_REG = 0x00;	 //Clear 'EN' bit
	ISP_I2C_PS_REG_LOW  = I2C_M_PRESCALE_LOW; 		//clock prescale register lo-byte
	ISP_I2C_PS_REG_HIGH = I2C_M_PRESCALE_HIGH; 	//cokck prescale register hi-byte
	ISP_I2C_CTRL_REG = 0x80;	 //Enable I2C
	return;
}

int i2c_read(char slaveID, int len, char *buf)
{
	int i = 0;
	int timeOutCount = 0;

	ISP_I2C_TX_REG = (slaveID << 1) + 1; //Slave address + read bit
	ISP_I2C_COM_REG = COMMAND_STA | COMMAND_WR ;
	while ( ISP_I2C_SR_REG & STATUS_TIP )
	{
		if ( timeOutCount ++ == I2C_TIMEOUT_COUNT )
			return I2C_TIMEOUT;
	}

	WaitCycles(1000);
	for ( i = 0; i < len; i++ )
	{
		timeOutCount = 0;
		//Last one
		if ( i == len - 1 )
		{
			ISP_I2C_COM_REG = COMMAND_RD | COMMAND_ACK | COMMAND_STO;
		}
		else
		{
			ISP_I2C_COM_REG = COMMAND_RD ;
		}

		while ( ISP_I2C_SR_REG & STATUS_TIP )
		{
			if ( timeOutCount ++ == I2C_TIMEOUT_COUNT )
				return I2C_TIMEOUT;
		}
		buf[i] = ISP_I2C_RX_REG;
		WaitCycles(1000);
	}

	return I2C_SUCCESS;
}

int i2c_write(char slaveID, int len, char *buf)
{

	int i = 0;
	int timeOutCount = 0;

	//uart_print("slaveID:");
	//uart_printInt((slaveID << 1));
	//uart_print("\n\r");
	ISP_I2C_TX_REG = (slaveID << 1); //Slave address

	ISP_I2C_COM_REG = COMMAND_STA | COMMAND_WR ;
	while ( ISP_I2C_SR_REG & STATUS_TIP )
	{
		if ( timeOutCount ++ == I2C_TIMEOUT_COUNT )
			return I2C_TIMEOUT;
	}
	//There may not be ACK if SCCB
	if ( ISP_I2C_SR_REG & STATUS_RXACK )
		return I2C_NACK;

	WaitCycles(1000);
	for ( i = 0; i < len; i++ )
	{
		timeOutCount = 0;
		ISP_I2C_TX_REG = buf[i];
		//uart_print("buf:");
		//uart_printInt(buf[i]);
		//uart_print("\n\r");
		//Last one
		if ( i == len - 1 )
		{
			ISP_I2C_COM_REG = COMMAND_WR | COMMAND_STO;
		}
		else
		{
			ISP_I2C_COM_REG = COMMAND_WR ;
		}

		while ( ISP_I2C_SR_REG & STATUS_TIP )
		{
			if ( timeOutCount ++ == I2C_TIMEOUT_COUNT )
				return I2C_TIMEOUT;
		}

		//There may not be ACK if SCCB
		if ( ISP_I2C_SR_REG & STATUS_RXACK )
			return I2C_NACK;
		WaitCycles(1000);
	}

	return I2C_SUCCESS;
}

void WaitCycles( unsigned int count )
{
	unsigned int nop_i;
 	for ( nop_i = 0; nop_i < count; nop_i++ ) __asm __volatile("l.nop   0");
}







