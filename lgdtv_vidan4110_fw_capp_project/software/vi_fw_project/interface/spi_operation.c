#include "map_hif.h"

extern unsigned int calulate_system_clock(void);

unsigned char spi_write_buf[300] = {0};
unsigned char spi_read_buf[300] = {0};

int om_select_temp_variable = 0;

int spi_open(int hz)
{
	int divider = 0;

	om_select_temp_variable = OM_SELECT;
	OM_SELECT &= ~OM_SELECT_I2C_M_SELECT_BIT;

	divider = (calulate_system_clock() / ( hz * 2)) - 1;

	SPI_MASTER_DIVIDER = divider;
	return 0;
}


int spi_close(void)
{
	OM_SELECT = om_select_temp_variable;
	return 0;
}


int spi_write(int nss, int len)
{
	int i = 0;

	unsigned int readyCmd = SPI_MASTER_CTRL_TX_NEG | 8; // Length : 8
	unsigned int startCmd = SPI_MASTER_CTRL_TX_NEG | SPI_MASTER_CTRL_GO_BUSY |8; // Length : 8

   SPI_MASTER_SS = (nss << 1);

	//Data transfer
	for ( i = 0; i < len; i ++ )
	{
	   SPI_MASTER_DATA0 = spi_write_buf[i];
	   SPI_MASTER_CTRL = readyCmd;
	   SPI_MASTER_CTRL = startCmd;
	   while ( SPI_MASTER_CTRL & SPI_MASTER_CTRL_GO_BUSY );

	   spi_read_buf[i] = SPI_MASTER_DATA0;
	}

   SPI_MASTER_SS = 0x0;

   return i;
}


