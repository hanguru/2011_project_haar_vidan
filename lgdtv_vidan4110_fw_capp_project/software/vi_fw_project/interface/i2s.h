#ifndef __I2S__
#define __I2S__

#include "map.h"

/**********************************************************************/
/* Register       Offset Size Type Function                           */
/* ================================================================== */
/* I2S Normal Registers                                               */
/* =====================                                              */
/* I2S_RXCR       0x00   32   R/W                                     */
/* I2S_TXCR       0x04   32   R/W                                     */
/* I2S_SR         0x08   10   R                                       */
/* I2S_COUNTER    0x0C   32   R                                       */
/**********************************************************************/
//#define I2S_RxCR              (I2S_BASE + 0x0000)
//#define I2S_TxCR              (I2S_BASE + 0x0004)
//#define I2S_SR                (I2S_BASE + 0x0008)
//#define I2S_COUNTER           (I2S_BASE + 0x000C)
//#define I2S_FIFO		        (I2S_BASE + 0x1000)
#define I2S_RxCnt           	((*(volatile int*)(I2S_COUNTER)) >> 16)		//090413_hunnoh_i2s*
#define I2S_TxCnt           	((*(volatile int*)(I2S_COUNTER)) & 0xFFFF)	//090413_hunnoh_i2s*
//090403_hunnoh_i2s_head+
#ifdef VIDAN4110
#define I2S1_RxCnt           	((*(volatile int*)(I2S1_COUNTER)) >> 16)	//090413_hunnoh_i2s*
#define I2S1_TxCnt           	((*(volatile int*)(I2S1_COUNTER)) & 0xFFFF)	//090413_hunnoh_i2s*
#endif
//090403_hunnoh_i2s_tail+
/**********************************************************************/
/******************** I2S Control Register Bits. **********************/
/**********************************************************************/
#define I2S_En                0x80000000
#define I2S_MonoRightMode     0x00400000	//090409_hunnoh_i2s_reg+
#define I2S_StereoMode        0x00200000
#define I2S_StereoMonoClr     0x00600000	//090409_hunnoh_i2s_reg+
#define I2S_CompactMode       0x00100000
#define I2S_DataSizeClr       0x00070000
#define I2S_8Bits             0x00000000
#define I2S_12Bits            0x00010000
#define I2S_16Bits            0x00020000
#define I2S_20Bits            0x00030000
#define I2S_32Bits            0x00040000
#define I2S_SizeBits          0x000003FF

/**********************************************************************/
/*********************** I2S Status Register. *************************/
/**********************************************************************/
#define I2S_RxFE              0x001 //Receive FIFO empty flag, active HIGH.
#define I2S_TxFE              0x002 //Transmit FIFO empty flag, active HIGH.
#define I2S_RxHF              0x004 //Receive FIFO half-full flag, active HIGH.
#define I2S_TxHE              0x008 //Transmit FIFO half-empty flag, active HIGH.
#define I2S_RxFF              0x010 //Receive FIFO full flag, active HIGH.
#define I2S_TxFF              0x020 //Transmit FIFO full flag, active HIGH.
#define I2S_RxBusy            0x040 //Receive busy, active HIGH.
#define I2S_TxBusy            0x080 //Transmit busy, active HIGH.
#define I2S_RxOverrun         0x100 //Receive overrun error. This bit is set to 1 if an overrun error is detected.
#define I2S_TxUnderrun        0x200 //Transmit underrun error, active HIGH.
void I2S_RegSet(volatile int reg, int val);

void I2S_RegClr(volatile int reg, int val);
/*
 void I2S_TxCR_Set(int val);

 void I2S_TxCR_Clr(int val);
 */
void I2S_DataSize(volatile int reg, int val);

//void I2S_TxDataSize(int val);

void I2S_IrqCnt(volatile int reg, short val);

//void I2S_TxIrqCnt(short val);

//short I2S_FifoNum(int reg);	//090413_hunnoh_i2s-

//short I2S_TxFifoRestNum(void);

void I2S_RxFifoEmpty(volatile int reg, int num);

void audio_init(); //090413_hunnoh_i2s+
void audio_start();

#define I2S_FifoNum(_X_) (short)(_X_)	//090413_hunnoh_i2s+
//#define I2S_Word2Word     0
//#define I2S_Word2HWord    1
#define I2S_Fifo_Size     0x400

//#define PCM_Buf_Size  0x3fc0 //160*102=0x3fc0 //161*101=0x3f85//(PCM_TX_STREAM_BASE - PCM_RX_STREAM_BASE)*2/4=0x4000
#define PCM_Buf_Size  0x1e00 //160*102=0x3fc0 //161*101=0x3f85//(PCM_TX_STREAM_BASE - PCM_RX_STREAM_BASE)*2/4=0x4000
//#define PCM_Data_Size 640 //160*2*2=640 0x280	//090409_hunnoh_i2s_reg- 
extern int rx_buffer_index;
extern int tx_buffer_index;
extern int i2s_data_cnt;
extern int audio_data_cnt;
extern int audio_data_consumed; //090408_jykim_mux+
extern int audio_offset; //090408_jykim_mux+
extern int i2s_txflag;
extern int rx_irq_size; //090409_hunnoh_i2s_reg+
extern int tx_irq_size; //090409_hunnoh_i2s_reg+
extern int audio_sflag; //090413_hunnoh_i2s+
/* 
 * rx_buf       : recevied buffer.
 * rx_cnt       : get word count.(basis rx_buf)
 * copy_mode    : copy mode.
 * return value : 1 = Normal
 *                0 = Error
 */
int I2S_Receive(int *rx_buf, int rx_cnt);//, int copy_mode);

/* 
 * tx_buf       : transmit buffer.
 * tx_cnt       : put word count.(basis tx_buf)
 * copy_mode    : copy mode.
 * return value : 1 = Normal
 *                0 = Error
 */
int I2S_Transmit(int *tx_buf, int tx_cnt);//, int copy_mode);

//090403_hunnoh_i2s_head+
#ifdef VIDAN4110
#define PCM_Data_Size 640 //160*2*2=640 0x280	//090409_hunnoh_i2s_reg+ 
extern int rx1_buffer_index;
extern int tx1_buffer_index;
extern int i2s1_data_cnt;
extern int audio1_data_cnt;
extern int audio1_data_consumed; //090408_jykim_mux+
extern int audio1_offset; //090408_jykim_mux+
extern int i2s1_txflag;

int I2S1_Receive(int *rx_buf, int rx_cnt);//, int copy_mode);
int I2S1_Transmit(int *tx_buf, int tx_cnt);//, int copy_mode);

extern int i2s_int_enabled;
extern int pcm_exist;
extern int lost_pcm_len;

void init_i2s(void);

void i2s_interrupt_handler(void);

#endif
//090403_hunnoh_i2s_tail+
#endif //__I2S__
