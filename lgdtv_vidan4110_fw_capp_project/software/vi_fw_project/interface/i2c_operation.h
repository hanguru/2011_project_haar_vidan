#ifndef _I2C_OPERATION_H_
#define _I2C_OPERATION_H_


//Command register
#define COMMAND_STA		( 1 << 7 )
#define COMMAND_STO		( 1 << 6 )
#define COMMAND_RD		( 1 << 5 )
#define COMMAND_WR		( 1 << 4 )
#define COMMAND_ACK		( 1 << 3 )
#define COMMAND_IACK	( 1 << 0 )

//Status register
#define STATUS_RXACK	( 1 << 7 )
#define STATUS_BUSY		( 1 << 6 )
#define STATUS_AL			( 1 << 5 )
#define STATUS_TIP		( 1 << 1 )
#define STATUS_IF			( 1 << 0 )


#define I2C_TIMEOUT_COUNT	 100000

enum
{
	I2C_NACK = -2,
	I2C_TIMEOUT = -1,
	I2C_SUCCESS = 0,
};
	
void i2c_init(void);
int i2c_read(char slaveID, int len, char *buf);
int i2c_write(char slaveID, int len, char *buf);

void WaitCycles( unsigned int count );

#endif
