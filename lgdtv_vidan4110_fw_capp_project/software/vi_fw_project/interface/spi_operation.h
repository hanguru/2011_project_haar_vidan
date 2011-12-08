#ifndef _SPI_OPERATION_H_
#define _SPI_OPERATION_H_

extern unsigned char spi_write_buf[256];
extern unsigned char spi_read_buf[256];

int spi_open(int hz);
int spi_close(void);

int spi_write(int nss, int len);

#endif

