#ifndef __MAP_H__
#define __MAP_H__

//-------------------------------------------------------------------

//-------------------------------------------------------------------
//BASE addresses

//AHB1
#define H264E_BASE_ADDR           0x80000000
#define CACHE_SLAVE               0x04000000
#define AHB_WRAPPED_OPENRISC      ((CACHE_SLAVE >> 16) & 0xFFFF)
#define ISP_BASE_ADDR             0xA0000000
//#define OR_RAM                    0xc0000000

#define JPEG_BASE_ADDR            0xB0000000 // jarre 2008.07.11 jpeg +

#define VIM_TO_MEM                0xD0000000
#define UART_BASE_ADDR            0xD0010000
#define IMG_BASE                  0xD0020000 // camera interface
#define S_IMG_BASE                0xD0028000 // camera interface s // jarre 2009.06.08 dual stream + 
#define SCCB_BASE_ADDR            0xD0030000
#define DVP_BASE_ADDR             0xD0040000
#define USB_BASE_ADDR             0xD0050000

//090407_jykim_i2s1_add_head-
//#define I2S0_BASE_ADDR            0xD0060000
//#define I2S1_BASE_ADDR            0xD0070000
//#define I2S_BASE_ADDR             I2S0_BASE_ADDR
//#define SPI_MASTER_BASE_ADDR      0xD0080000
//#define SDIO0_BASE                0xD0090000
//#define SDIO1_BASE                0xD00A0000
//#define IIC_MASTER_BASE           0xD00B0000
//#define PCI_BASE                  0xD00C0000
//090407_jykim_i2s1_add_tail-

//090407_jykim_i2s1_add_head+
#define I2S_BASE_ADDR             0xD0060000
#define SPI_MASTER_BASE_ADDR      0xD0070000
#define SDIO0_BASE                0xD0080000
#define SDIO1_BASE                0xD0090000
#define IIC_MASTER_BASE           0xD00A0000
#define PCI_BASE                  0xD00B0000

#ifdef VIDAN4110
#undef SPI_MASTER_BASE_ADDR      
#undef SDIO0_BASE                
#undef SDIO1_BASE                
#undef IIC_MASTER_BASE           
#undef PCI_BASE                  

#define I2S1_BASE_ADDR            0xD0070000
#define SPI_MASTER_BASE_ADDR      0xD0080000
#define SDIO0_BASE                0xD0090000
#define SDIO1_BASE                0xD00A0000
#define IIC_MASTER_BASE           0xD00B0000
#define PCI_BASE                  0xD00C0000
#define SRAM_IF_BASE              0xD00D0000 // jarre 2009.07.02 SRAM_IF + 
#endif
//090407_jykim_i2s1_add_tail+

//#define CtrlFlashBR_BASE_ADDR     0xE0000000
#define SPI_SLV_BUF_BASE          0xE0000000
#define OR_CTRL                   0xE0010000
#define APB_BASE_ADDR             0xE0020000
#define CPM_BASE_ADDR             0xE0030000
//090721_hunnoh_peri_head+
#define WDT_BASE_ADDR             0xE0040000
#define RTC_BASE_ADDR             0xE0050000
#define PTC_BASE_ADDR             0xE0060000
#define UART1_BASE_ADDR           0xE0070000
#define UART2_BASE_ADDR           0xE0080000
//090721_hunnoh_peri_tail+
#define STREAM_PUMP               0x10008000 // Unused
#define LTCTRL_BASE_ADDR          0xE0040000
#define SDRAMC_BASE_ADDR	       0xF0000000

// ======= H.264 encoder ======= //
#define VIM_BASE                  (H264E_BASE_ADDR + 0x10000)
#define VLC_BASE                  (H264E_BASE_ADDR + 0x20000)
#define DCTQ_BASE                 (H264E_BASE_ADDR + 0x30000)
#define ME_BASE                   (H264E_BASE_ADDR + 0x40000)
#define ADF_BASE                  (H264E_BASE_ADDR + 0x50000)
//#define DMAC_BASE                 (H264E_BASE_ADDR + 0x60000)
#define OSC_BASE                  (H264E_BASE_ADDR + 0x70000)
//commented by eskim
//#define IMG_BASE                  (H264E_BASE_ADDR + 0x80000  // external image interface)
#define OSB_BASE                  (H264E_BASE_ADDR + 0xA0000)  // osb )

// ======= ISP ======= //
#define LS_BASE_ADDR              (ISP_BASE_ADDR + 0x000000)      //0
#define AE_BASE_ADDR              (ISP_BASE_ADDR + 0x100000)      //1
#define AWB_BASE_ADDR             (ISP_BASE_ADDR + 0x200000)      //2
#define DM_BASE_ADDR              (ISP_BASE_ADDR + 0x300000)      //3
#define SHP_BASE_ADDR             (ISP_BASE_ADDR + 0x400000)      //4
#define GC_BASE_ADDR              (ISP_BASE_ADDR + 0x500000)      //5
#define CC_BASE_ADDR              (ISP_BASE_ADDR + 0x600000)      //6
#define CSC_BASE_ADDR             (ISP_BASE_ADDR + 0x700000)      //7
#define CTRL_BASE_ADDR            (ISP_BASE_ADDR + 0x800000)      //8
//#define OUT_BASE_ADDR             (ISP_BASE_ADDR + 0x900000)      //9
#define OUT_YUV_BASE_ADDR	       (ISP_BASE_ADDR + 0x900000)      //9
#define FM_BASE_ADDR		       (ISP_BASE_ADDR + 0xa00000)	//a
#define YUV_CC_BASE_ADDR           (ISP_BASE_ADDR + 0xb00000)	//b
#define AGC_BASE_ADDR		       (ISP_BASE_ADDR + 0xc00000)	    //c
#define OUT_RGB_BASE_ADDR	       (ISP_BASE_ADDR + 0xd00000)      //d
#define DNF_BASE_ADDR		       (ISP_BASE_ADDR + 0xe00000)      //e
#define SC_BASE_ADDR		          (ISP_BASE_ADDR + 0xf00000)      //f


//jykim_20080715_HIF_CONV_head++
// ==HOST INTERFACE== //
#define HIF_BASE_ADDR             (APB_BASE_ADDR + 0x1000)
#define GPIO_BASE_ADDR            (APB_BASE_ADDR + 0x2000)
//jykim_20080715_HIF_CONV_tail++

// ======= JPEG ======= //
#define JPEG_DCTQ_BASE_ADDR       (JPEG_BASE_ADDR + 0x00099000) // jarre 2008.07.11 jpeg +
#define JPEG_MI_BASE_ADDR         (JPEG_BASE_ADDR + 0x0009A000) // jarre 2008.07.11 jpeg +
#define JPEG_CTRL_BASE_ADDR       (JPEG_BASE_ADDR + 0x0009B000) // jarre 2008.07.11 jpeg +
#define JPEG_TVLC_BASE_ADDR       (JPEG_BASE_ADDR + 0x0009C000) // jarre 2008.07.11 jpeg +
#define JPEG_OS_BASE_ADDR         (JPEG_BASE_ADDR + 0x0009E000) // jarre 2008.07.11 jpeg +

// ======= SPI Slave buf ======= //
#define SPI_SLV_BUF_FILL_NUM      (SPI_SLV_BUF_BASE)
#define SPI_SLV_BUF_EMPTY_NUM     (SPI_SLV_BUF_BASE+0x4)
#define SPI_SLV_BUF_FILL_RATE     (SPI_SLV_BUF_BASE+0x8)
#define SPI_SLV_BUF_SAFE          (SPI_SLV_BUF_BASE+0xC)
#define SPI_SLV_BUF_FIFO          (SPI_SLV_BUF_BASE+(0x1<<12))

#define LTCTRL_OSC0               *((volatile int*) (LTCTRL_BASE_ADDR + 0x00))
#define LTCTRL_OSC1               *((volatile int*) (LTCTRL_BASE_ADDR + 0x04))
#define LTCTRL_OSC2               *((volatile int*) (LTCTRL_BASE_ADDR + 0x08))
#define LTCTRL_LOCK               *((volatile int*) (LTCTRL_BASE_ADDR + 0x0C))
#define LTCTRL_LEDS               *((volatile int*) (LTCTRL_BASE_ADDR + 0x10))
#define LTCTRL_SW                 *((volatile int*) (LTCTRL_BASE_ADDR + 0x1C))

// LT User Switch (SW1 - SW8)
//#define LTCTRL_SW_SELFCONTROL     (LTCTRL_SW & 0x1) // [SW1] 0: PB board control, 1: OpenRISC self-control //jykim_20080715_HIF_CONV-- ==> move to configfile.h, configfile.c
//#define LTCTRL_SW_CAM_HD          (LTCTRL_SW & 0x2) // [SW2] Frame size (0: VGA, 1: HD) //jykim_20080715_HIF_CONV-- ==> move to configfile.h, configfile.c
//#define LTCTRL_SW_DOWNSAMPLING    (LTCTRL_SW & 0x4) // [SW3] Camera downsampling (0: OFF, 1: ON) //jykim_20080715_HIF_CONV-- ==> move to configfile.h, configfile.c
//#define LTCTRL_SW_ISP             (LTCTRL_SW & 0x8) // [SW4] ISP (0: OFF, 1: ON) //jykim_20080715_HIF_CONV-- ==> move to configfile.h, configfile.c
//#define LTCTRL_SW_UART_CONTROL    (LTCTRL_SW & 0x10)   // [SW5] Parameter setting by UART //jykim_20080715_HIF_CONV-- ==> move to configfile.h, configfile.c
//#define LTCTRL_SW_FREERUN         (LTCTRL_SW & 0x20)   // [SW6] Free-running //jykim_20080715_HIF_CONV-- ==> move to configfile.h, configfile.c
//#define LTCTRL_SW_SW7             (LTCTRL_SW & 0x40)   // [SW7] Reserved
//#define LTCTRL_SW_HIF_CONTROL	    (LTCTRL_SW & 0x80)	// [SW8] Parameter setting by HIF //jykim_20080715_HIF_CONV-- ==> move to configfile.h, configfile.c
//#define LTCTRL_SW_SW8             (LTCTRL_SW & 0x80)   // [SW8] Reserved

// redefine signals below !! (to-do)
#define LTCTRL_SW_USBSRC	(LTCTRL_SW & 0x00)	// [SW5] USB_SOURCE (0:osb, 1:frame mem.)
#define LTCTRL_SW_DVP		(LTCTRL_SW & 0x00)	// [SW6] DVP (0: DVP OFF, USB ON, 1: DVP ON, DVP OFF) // jarre 2008.04.18 dvp +
#define LTCTRL_SW_DVPCLK0	(LTCTRL_SW & 0x00)	// [SW7] DVP clk_div[1:0]                             // jarre 2008.04.18 dvp +
#define LTCTRL_SW_DVPCLK1	(LTCTRL_SW & 0x00)	// [SW8] (00:1/1, 01:1/2, 10:1/4, 11:1/6)             // jarre 2008.04.18 dvp +



// Memory Logic Tile
// 0xF0000000: SSRAM0
// 0xF1000000: SSRAM1
// 0xF2000000: Registers

// SRC_BASE
// 0xF0000000: Uppper logic tile memory SSRAM0
#define SRC_BASE                  0xf0000000
#define S_SRC_BASE                0xf0180000 // jarre 2009.06.09 for dual stream test +++
#define FRAME_SIZE                0x00200000

#define FRAME_OFFSET              (FRAME_SIZE) // +++ luslas
#define FRAME_OFFSET1             (FRAME_SIZE*2)
#define SRC_BASE1                 (SRC_BASE + FRAME_OFFSET)

#ifdef BI_PREDICTION_MODE
  #define FRAME_OFFSET2         0x00552000
  #define FRAME_OFFSET3         0x007A4000
#else
  #define FRAME_OFFSET2         (FRAME_SIZE*4)
  #define FRAME_OFFSET3         (FRAME_SIZE*5)
#endif


// RGB FRAME MEMORY BASE ADDR
//#define RGB_BASE	0xf1800000
#define RGB_BASE	0xf0600000
#define RGB_FRAME_SIZE            (1280*1024*4)  //jykim_080724_isp_dvp++ 
#define RGB_FRAME_OFFSET          (RGB_FRAME_SIZE)  //jykim_080724_isp_dvp++

#define H264_STREAM_BASE          0xf1000000
#define EXTERNAL_PGM_BASE         0xf10A4000
#define JPEG_STREAM_BASE0         0xf1124000
#define JPEG_STREAM_BASE1         0xf11D3800
#define JPEG_STREAM_BASE2         0xf1283000
#define JPEG_STREAM_BASE3         0xf1332800
#define PCM_RX_STREAM_BASE        0xF13E2000	//090401_hunnoh_i2s+
#define PCM_TX_STREAM_BASE        0xF13EA000	//090401_hunnoh_i2s+
//090403_hunnoh_i2s_head+
#ifdef VIDAN4110
#define PCM1_RX_STREAM_BASE       0xF13F2000
#define PCM1_TX_STREAM_BASE       0xF13FA000
#endif
//090403_hunnoh_i2s_tail+

// DMA_BUFFER
// 0xF0100000: Uppper logic tile memory SSRAM0 (use SSRAM0 only)
// 0xF1000000: Uppper logic tile memory SSRAM1
// 0x38080000: Versatile PB base board memory
// #define DMA_BUFFER   0xf1000000 // --- luslas
#define DMA_BUFFER                SRC_BASE1 // +++ luslas

#define STREAM_BASE               0x38100000

//-------------------------------------------------------------------

//added by eskim:begin
#define VIM_Y_BASE                *((volatile int *) (VIM_TO_MEM + 0x0))
#define VIM_U_BASE                *((volatile int *) (VIM_TO_MEM + 0x4))
#define VIM_V_BASE                *((volatile int *) (VIM_TO_MEM + 0x8))

#define STR_DST_PT                *((volatile int *) (STREAM_PUMP))
#define STR_CNT_OVERFLOW          *((volatile int *) (STREAM_PUMP+0x04))
#define STR_CNT_STREAM            *((volatile int *) (STREAM_PUMP+0x08))
#define STR_CNT_CUR_QUEUE_SIZE    *((volatile int *) (STREAM_PUMP+0x0c))
#define STR_CNT_MAX_QUEUE_SIZE    *((volatile int *) (STREAM_PUMP+0x10))
#define STR_SEARCH_CTRL           *((volatile int *) (STREAM_PUMP+0x14))
#define STR_PATTERN               *((volatile int *) (STREAM_PUMP+0x18))
#define STR_CNT_FOUND             *((volatile int *) (STREAM_PUMP+0x1c))

#define ORC_LED                   *((volatile int *) (OR_CTRL + 0x0))
#define ORC_RESET                 *((volatile int *) (OR_CTRL + 0x4))
#define ORC_RECV_SIGNAL           *((volatile int *) (OR_CTRL + 0x8))
#define ORC_SEND_SIGNAL           *((volatile int *) (OR_CTRL + 0xc))
#define ORC_RECV_SIGNAL2          *((volatile int *) (OR_CTRL + 0x10))
#define ORC_SEND_SIGNAL2          *((volatile int *) (OR_CTRL + 0x14))
#define ORC_FRAME_SIZE            *((volatile int *) (OR_CTRL + 0x18))
#define ORC_FRAME_COUNT           *((volatile int *) (OR_CTRL + 0x1c))
//#define ORC_SYS_KIND              *((volatile int *) (OR_CTRL + 0x20)) //jykim_20080715_HIF_CONV-- ==> move to configfile.h, configfile.c
#define STREAM_RECEIVER_SEL       *((volatile int *) (OR_CTRL + 0x24))
#define FRAME_SRC_SEL             *((volatile int *) (OR_CTRL + 0x28))
#define ORC_CAM_SIZE              *((volatile int *) (OR_CTRL + 0x2c))
#define FRAME_ENCODE_OFFSET       *((volatile int *) (OR_CTRL + 0x30))
#define FACE_SIZE                 *((volatile int *) (OR_CTRL + 0x34))
//#define FACE_DETECTION            *((volatile int *) (OR_CTRL + 0x38)) //jykim_20080715_HIF_CONV--
#define ORC_EXT_MEM_TYPE_SEL      *((volatile int *) (OR_CTRL + 0x3C)) /* 0: SSRAM, 1: SDRAM */
#define ORC_EXT_SDRAM_OPMODE      *((volatile int *) (OR_CTRL + 0x40))

#define DMAC_Y_BASE               *((volatile int *) (DMAC_BASE + 0x24))
#define DMAC_U_BASE               *((volatile int *) (DMAC_BASE + 0x28))
#define DMAC_V_BASE               *((volatile int *) (DMAC_BASE + 0x2c))
//added by eskim, jonghwan:end


//AHB2
//#define DCT_DMA_BASE  0x3000000
//#define ME_DMA_BASE   0x3400000
//#define ADF_DMA_BASE  0x3800000

/* VIM */
#define VIM_START                 *((volatile int *) (VIM_BASE + 0x00))
#define VIM_DONE                  *((volatile int *) (VIM_BASE + 0x04))
#define VIM_SIZE                  *((volatile int *) (VIM_BASE + 0x08))
#define VIM_FRAME_SIZE            *((volatile int *) (VIM_BASE + 0x0C))

/* VLC */
#define VLC_HVCR0                 *((volatile int *) (VLC_BASE + 0x00))
#define VLC_HVCR1                 *((volatile int *) (VLC_BASE + 0x04))
#define VLC_HVCR2                 *((volatile int *) (VLC_BASE + 0x08))
#define VLC_HVCR3                 *((volatile int *) (VLC_BASE + 0x0C))
#define VLC_HVSR0                 *((volatile int *) (VLC_BASE + 0x10))
#define VLC_MVCR0                 *((volatile int *) (VLC_BASE + 0x14))
#define VLC_MVCR1                 *((volatile int *) (VLC_BASE + 0x18))
#define VLC_MVCR2                 *((volatile int *) (VLC_BASE + 0x1C))
#define VLC_MVCR3                 *((volatile int *) (VLC_BASE + 0x20))
#define VLC_MVCR4                 *((volatile int *) (VLC_BASE + 0x24))
#define VLC_MVCR5                 *((volatile int *) (VLC_BASE + 0x28))
#define VLC_MVCR6                 *((volatile int *) (VLC_BASE + 0x2C))
#define VLC_MVCR7                 *((volatile int *) (VLC_BASE + 0x30))
#define VLC_MVCR8                 *((volatile int *) (VLC_BASE + 0x34))
#define VLC_MVCR9                 *((volatile int *) (VLC_BASE + 0x38))
#define VLC_MVCR10                *((volatile int *) (VLC_BASE + 0x3C))
#define VLC_MVCR11                *((volatile int *) (VLC_BASE + 0x40))
#define VLC_MVCR12                *((volatile int *) (VLC_BASE + 0x44))
#define VLC_MVCR13                *((volatile int *) (VLC_BASE + 0x48))
#define VLC_MVCR14                *((volatile int *) (VLC_BASE + 0x4C))
#define VLC_MVCR15                *((volatile int *) (VLC_BASE + 0x50))
#define VLC_MVCR16                *((volatile int *) (VLC_BASE + 0x54))
#define VLC_DVCR0                 *((volatile int *) (VLC_BASE + 0x58))
#define VLC_DVCR1                 *((volatile int *) (VLC_BASE + 0x5C))
#define VLC_DVCR2                 *((volatile int *) (VLC_BASE + 0x60))
#define VLC_DVCR3                 *((volatile int *) (VLC_BASE + 0x64))
#define VLC_DVCR4                 *((volatile int *) (VLC_BASE + 0x68))
#define VLC_DVSR0                 *((volatile int *) (VLC_BASE + 0x6C))
#define VLC_DVSR1                 *((volatile int *) (VLC_BASE + 0x70))
#define VLC_DVSR2                 *((volatile int *) (VLC_BASE + 0x74))
#define VLC_DVSR3                 *((volatile int *) (VLC_BASE + 0x78))
#define VLC_DVSR4                 *((volatile int *) (VLC_BASE + 0x7C))
#define VLC_DVSR5                 *((volatile int *) (VLC_BASE + 0x80))
#define VLC_CR0                   *((volatile int *) (VLC_BASE + 0x84)) 
#define VLC_SR0                   *((volatile int *) (VLC_BASE + 0x88)) 
#define VLC_CR1                   *((volatile int *) (VLC_BASE + 0x8C)) // chae
#define VLC_SIZE                  *((volatile int *) (VLC_BASE + 0x90))
#define VLC_SLICE_ARGUMENT        *((volatile int *) (VLC_BASE + 0x94)) //chae
#define MB_HEADER_BITS            *((volatile int *) (VLC_BASE + 0x100))
#define MB_TEXTURE_BITS           *((volatile int *) (VLC_BASE + 0x104))
#define FR_HEADER_BITS            *((volatile int *) (VLC_BASE + 0x108))
#define FR_TEXTURE_BITS           *((volatile int *) (VLC_BASE + 0x10c))
#define FR_ACC_LENGTH             *((volatile int *) (VLC_BASE + 0x110))


/* DCTQ */
// ===============================================================
// 05 : 00 - img->qp
// 06      - image_type ( P : 0, I : 1)
// 09 : 07 - i16mode
// 31 : 10 - Reserved
#define DCTQ_CR0                  *((volatile int *) (DCTQ_BASE + 0x00))
// ===============================================================
// DCTQ START signal
#define DCTQ_CR1                  *((volatile int *) (DCTQ_BASE + 0x04))
// ===============================================================
//(31:16)MB_X & (15:0)MB_Y : 
//    Macroblock x,y position
#define DCTQ_CR2                  *((volatile int *) (DCTQ_BASE + 0x98))
// ===============================================================
// (31:16)NEIGHBOR_IMODE_BASE_ADDR : 
//       neighbor_ipred sram base address
// (15:0)WIDTH_IN_MB - 1 :
//       Number of Macroblocks in a image row - 1
//       QCIF( 11 - 1 = 10), D1( 45 - 1 = 44)
#define DCTQ_CR3                  *((volatile int *) (DCTQ_BASE + 0x9C))
// ===============================================================
// EarlyTermination threshold control
// (4:0) M0 for early termination of 4x4 intra prediction
// (20:16)  M0 for early termination of 16x16 intra prediction
// (31)     Enable early termination of 16x16 intra prediction
// (30)  Enable early termination of 4x4 intra prediction
#define EarlyTerm_Control         *((volatile int *) (DCTQ_BASE + 0xA0))
// ===============================================================
//(31:16)slice_first_mb_x & (15:0)slice_first_mb_y : first MB of this slice
#define SliceFirstMB_I *((volatile int *) (DCTQ_BASE + 0xA4))
#define SliceLastMB_I  *((volatile int *) (DCTQ_BASE + 0xA8))
// ===============================================================
// intra_pred_modes: 
//       ME register reg69 ~ 72 --> DCTQ register SR2 ~ SR5
#define DCTQ_SR0                  *((volatile int *) (DCTQ_BASE + 0x54))
#define DCTQ_SR1                  *((volatile int *) (DCTQ_BASE + 0x58))
#define DCTQ_SR2                  *((volatile int *) (DCTQ_BASE + 0x5C))
#define DCTQ_SR3                  *((volatile int *) (DCTQ_BASE + 0x60))
// ===============================================================
//IP_RESULT:
//    (23:22) luma16x16bestmode
//       (21:18) lumabestmode
//       (17:16) c_ipredmode
//       (15:0)  luma_mincost
#define DCTQ_SR4                  *((volatile int *) (DCTQ_BASE + 0x64))
// ===============================================================
// CBP_BLK & INTER_DONE & INTRA_DONE
//       (31:8)CBP_BLK
//       (1)   INTER_DONE
//       (0)   INTRA_DONE
#define DCTQ_SR5                  *((volatile int *) (DCTQ_BASE + 0x44))
// ===============================================================
// CBP:
//       (11:6)PCBP
//       (5:0) ICBP
#define DCTQ_SR6                  *((volatile int *) (DCTQ_BASE + 0x48))
// ===============================================================
// i16offset
#define DCTQ_SR7                  *((volatile int *) (DCTQ_BASE + 0x40))
// ===============================================================


/* ME */
#define ME_CR0                    *((volatile int *) (ME_BASE + 0x00)) // Frame Size in Pixel Unit ( height[23:16], width[9:0] )
#define ME_CR1                    *((volatile int *) (ME_BASE + 0x04)) // MB_TYPE ( I or P )
#define ME_CR2                    *((volatile int *) (ME_BASE + 0x08)) // QP of current picture
#define ME_CR3                    *((volatile int *) (ME_BASE + 0x0C)) // Position of MB in pixel unit ( height[23:16], width[9:0] )
#define ME_CR4                    *((volatile int *) (ME_BASE + 0x10)) // NeighbourMV0
#define ME_CR5                    *((volatile int *) (ME_BASE + 0x14)) // NeighbourMV1
#define ME_CR6                    *((volatile int *) (ME_BASE + 0x18)) // NeighbourMV2
#define ME_CR7                    *((volatile int *) (ME_BASE + 0x1C)) // NeighbourMV3
#define ME_CR8                    *((volatile int *) (ME_BASE + 0x20)) // NeighbourMV4
#define ME_CR9                    *((volatile int *) (ME_BASE + 0x24)) // NeighbourMV5
#define ME_CR10                   *((volatile int *) (ME_BASE + 0x28)) // ME start
#define ME_CR11                   *((volatile int *) (ME_BASE + 0x2C)) // ME conbined setting
//added by eskim
#define ME_DMA_Y_BASE             *((volatile int *) (ME_BASE + 0x30))
#define ME_DMA_U_BASE             *((volatile int *) (ME_BASE + 0x34))
#define ME_DMA_V_BASE             *((volatile int *) (ME_BASE + 0x38))
#define ME_DMA_START              *((volatile int *) (ME_BASE + 0x3c))
//added by janghack
#define ME_SEARCH_WINDOW_MARGINY_0_3   *((volatile int *) (ME_BASE + 0x40))
#define ME_SEARCH_WINDOW_MARGINY_4_7   *((volatile int *) (ME_BASE + 0x44))
#define ME_SEARCH_WINDOW_MARGINX_0_3   *((volatile int *) (ME_BASE + 0x48))
#define ME_SEARCH_WINDOW_MARGINX_4_7   *((volatile int *) (ME_BASE + 0x4C))
#define ME_FAST_FME_CONTROL            *((volatile int *) (ME_BASE + 0x60))

#define SPEED_CONTROL_TARGET_FR   *((volatile int *) (ME_BASE + 0x64))
#define SPEED_CONTROL_TARGET_MB   *((volatile int *) (ME_BASE + 0x68))
#define SPEED_CONTROL_SET_PER_MB  *((volatile int *) (ME_BASE + 0x84)) //[28:17]:curr_mb_nr [16:0]:future time in line
#define SPEED_CONTROL_SET_PER_FR  *((volatile int *) (ME_BASE + 0x88)) // previous frame encoding time

#define SliceFirstMB_P            *((volatile int *) (ME_BASE + 0x90))
#define SliceLastMB_P             *((volatile int *) (ME_BASE + 0x94))

#define SPEED_CONTROL_PREV_ENC_TIME  *((volatile int *) (ME_BASE + 0x200))

// [9:8] : Number of Probes (1 probe word = 256 bit), [4:0] : Signal Select
#define ME_CHIPSCOPE              *((volatile int *) (ME_BASE + 0x54))
#define BYPASS_MODE0              *((volatile int *) (ME_BASE + 0x58)) // Reserved for Mode 0 problem

#define ME_SR0                    *((volatile int *) (ME_BASE + 0x100)) // reg64 in VHE_ME_DECISION_OUTREG.v
#define ME_SR1                    *((volatile int *) (ME_BASE + 0x104)) // reg65 in VHE_ME_DECISION_OUTREG.v
#define ME_SR2                    *((volatile int *) (ME_BASE + 0x108)) // reg66 in VHE_ME_DECISION_OUTREG.v
#define ME_SR3                    *((volatile int *) (ME_BASE + 0x10C)) // reg67 in VHE_ME_DECISION_OUTREG.v
#define ME_SR4                    *((volatile int *) (ME_BASE + 0x110)) // reg68 in VHE_ME_DECISION_OUTREG.v
#define ME_SR5                    *((volatile int *) (ME_BASE + 0x114)) // reg69 in VHE_ME_DECISION_OUTREG.v INTRA_i4predmode
#define ME_SR6                    *((volatile int *) (ME_BASE + 0x118)) // reg70 in VHE_ME_DECISION_OUTREG.v INTRA_i4predmode
#define ME_SR7                    *((volatile int *) (ME_BASE + 0x11C)) // reg71 in VHE_ME_DECISION_OUTREG.v INTRA_i4predmode
#define ME_SR8                    *((volatile int *) (ME_BASE + 0x120)) // reg72 in VHE_ME_DECISION_OUTREG.v INTRA_i4predmode
#define ME_SR9                    *((volatile int *) (ME_BASE + 0x124)) // reg73 in VHE_ME_DECISION_OUTREG.v INTRA_cmode
#define ME_SR10                   *((volatile int *) (ME_BASE + 0x128)) // reg74 in VHE_ME_DECISION_OUTREG.v b8mode
#define ME_SR11                   *((volatile int *) (ME_BASE + 0x12C)) // reg75 in VHE_ME_DECISION_OUTREG.v b8pdir (1 when bestmode is I in P)
#define ME_SR12                   *((volatile int *) (ME_BASE + 0x130)) // reg76 in VHE_ME_DECISION_OUTREG.v
#define ME_SR13                   *((volatile int *) (ME_BASE + 0x134)) // reg77 in VHE_ME_DECISION_OUTREG.v
#define ME_SR14                   *((volatile int *) (ME_BASE + 0x138)) // reg78 in VHE_ME_DECISION_OUTREG.v
#define ME_SR15                   *((volatile int *) (ME_BASE + 0x13C)) // reg79 in VHE_ME_DECISION_OUTREG.v
#define ME_SR16                   *((volatile int *) (ME_BASE + 0x140)) // reg80 in VHE_ME_DECISION_OUTREG.v mv0
#define ME_SR17                   *((volatile int *) (ME_BASE + 0x144)) // reg81 in VHE_ME_DECISION_OUTREG.v mv1
#define ME_SR18                   *((volatile int *) (ME_BASE + 0x148)) // reg82 in VHE_ME_DECISION_OUTREG.v mv2
#define ME_SR19                   *((volatile int *) (ME_BASE + 0x14C)) // reg83 in VHE_ME_DECISION_OUTREG.v mv3
#define ME_SR20                   *((volatile int *) (ME_BASE + 0x150)) // reg84 in VHE_ME_DECISION_OUTREG.v mv4
#define ME_SR21                   *((volatile int *) (ME_BASE + 0x154)) // reg85 in VHE_ME_DECISION_OUTREG.v mv5
#define ME_SR22                   *((volatile int *) (ME_BASE + 0x158)) // reg86 in VHE_ME_DECISION_OUTREG.v mv6
#define ME_SR23                   *((volatile int *) (ME_BASE + 0x15C)) // reg87 in VHE_ME_DECISION_OUTREG.v mv7
#define ME_SR24                   *((volatile int *) (ME_BASE + 0x160)) // reg88 in VHE_ME_DECISION_OUTREG.v mv8
#define ME_SR25                   *((volatile int *) (ME_BASE + 0x164)) // reg89 in VHE_ME_DECISION_OUTREG.v mv9
#define ME_SR26                   *((volatile int *) (ME_BASE + 0x168)) // reg90 in VHE_ME_DECISION_OUTREG.v mv10
#define ME_SR27                   *((volatile int *) (ME_BASE + 0x16C)) // reg91 in VHE_ME_DECISION_OUTREG.v mv11
#define ME_SR28                   *((volatile int *) (ME_BASE + 0x170)) // reg92 in VHE_ME_DECISION_OUTREG.v mv12
#define ME_SR29                   *((volatile int *) (ME_BASE + 0x174)) // reg93 in VHE_ME_DECISION_OUTREG.v mv13
#define ME_SR30                   *((volatile int *) (ME_BASE + 0x178)) // reg94 in VHE_ME_DECISION_OUTREG.v mv14
#define ME_SR31                   *((volatile int *) (ME_BASE + 0x17C)) // reg95 in VHE_ME_DECISION_OUTREG.v mv15
#define ME_SR32                   *((volatile int *) (ME_BASE + 0x180)) // reg96 in VHE_ME_DECISION_OUTREG.v mvd0
#define ME_SR33                   *((volatile int *) (ME_BASE + 0x184)) // reg97 in VHE_ME_DECISION_OUTREG.v mvd1
#define ME_SR34                   *((volatile int *) (ME_BASE + 0x188)) // reg98 in VHE_ME_DECISION_OUTREG.v mvd2
#define ME_SR35                   *((volatile int *) (ME_BASE + 0x18C)) // reg99 in VHE_ME_DECISION_OUTREG.v mvd3
#define ME_SR36                   *((volatile int *) (ME_BASE + 0x190)) // reg100 in VHE_ME_DECISION_OUTREG.v mvd4
#define ME_SR37                   *((volatile int *) (ME_BASE + 0x194)) // reg101 in VHE_ME_DECISION_OUTREG.v mvd5
#define ME_SR38                   *((volatile int *) (ME_BASE + 0x198)) // reg102 in VHE_ME_DECISION_OUTREG.v mvd6
#define ME_SR39                   *((volatile int *) (ME_BASE + 0x19C)) // reg103 in VHE_ME_DECISION_OUTREG.v mvd7
#define ME_SR40                   *((volatile int *) (ME_BASE + 0x1A0)) // reg104 in VHE_ME_DECISION_OUTREG.v mvd8
#define ME_SR41                   *((volatile int *) (ME_BASE + 0x1A4)) // reg105 in VHE_ME_DECISION_OUTREG.v mvd9
#define ME_SR42                   *((volatile int *) (ME_BASE + 0x1A8)) // reg106 in VHE_ME_DECISION_OUTREG.v mvd10
#define ME_SR43                   *((volatile int *) (ME_BASE + 0x1AC)) // reg107 in VHE_ME_DECISION_OUTREG.v mvd11
#define ME_SR44                   *((volatile int *) (ME_BASE + 0x1B0)) // reg108 in VHE_ME_DECISION_OUTREG.v mvd12
#define ME_SR45                   *((volatile int *) (ME_BASE + 0x1B4)) // reg109 in VHE_ME_DECISION_OUTREG.v mvd13
#define ME_SR46                   *((volatile int *) (ME_BASE + 0x1B8)) // reg110 in VHE_ME_DECISION_OUTREG.v mvd14
#define ME_SR47                   *((volatile int *) (ME_BASE + 0x1BC)) // reg111 in VHE_ME_DECISION_OUTREG.v mvd15
//////////////////////////////// ME_SR48 ///////////////////////////////////////
// Refers to reg112 defined in VHE_ME_DECISION_OUTREG.v 
// me_state[3:0]     : defined in VHE_ME_DECISION_OUTREG.v
// qme_merger_state[7:0]      : defined in VHE_ME_QME_MERGER.v
// reg64[11:8]             : defined in VHE_ME_DECISION_OUTREG.v
// VHE_ME_DCTQ_INTER_IDLE,IME_done[13:12]
// P_state[19:16]          : Main FSM of VHE_ME_CONTROL_INREG.v
// qme_merger_mv_state[23:20] : defined in VHE_ME_QME_MERGER.v
// done_state[27:24]       : defined in VHE_ME_DECISION_OUTREG.v
// state[31:28]               : Main FSM of VHE_ME_DECISION_OUTREG.v
#define ME_SR48                   *((volatile int *) (ME_BASE + 0x1C0)) 
////////////////////////////////////////////////////////////////////////////////
#define ME_SR49                   *((volatile int *) (ME_BASE + 0x1C4)) //l_intra_mode[31:0]  for recompression dmac
#define ME_SR50                   *((volatile int *) (ME_BASE + 0x1C8)) //l_intra_mode[63:32] for recompression dmac
#define ME_SR51                   *((volatile int *) (ME_BASE + 0x1CC)) //c_intra_mode[1:0]   for recompression dmac
#define ME_SR123                  *((volatile int *) (ME_BASE + 0x1EC)) // ME cost
#define ME_DMA_DONE               *((volatile int *) (ME_BASE + 0x1F0))
#define ME_INTERPOLATION_DONE     *((volatile int *) (ME_BASE + 0x1F4))
#define ME_IVEC                   *((volatile int *) (ME_BASE + 0x214))
#define ME_SAD_16x                *((volatile int *) (ME_BASE + 0x218))
#define ME_SAD_8x                 *((volatile int *) (ME_BASE + 0x21C))
#define ME_SAD_4x                 *((volatile int *) (ME_BASE + 0x220))
#define ME_MB_TOT_COST		       *((volatile int *) (ME_BASE + 0x204)) //d129
#define ME_FR_TOT_COST		       *((volatile int *) (ME_BASE + 0x208)) //d130


/* ADF */
// modified for new ADF by shpark, 2008.02.16.
#define DB_CR1                    *((volatile int *) (ADF_BASE  + 0x00))
#define DB_CR2                    *((volatile int *) (ADF_BASE  + 0x04))
#define DB_DIM                    *((volatile int *) (ADF_BASE  + 0x08))
#define DB_BASE_ADDR_Y            *((volatile int *) (ADF_BASE  + 0x0C))
#define DB_BASE_ADDR_U            *((volatile int *) (ADF_BASE  + 0x10))
#define DB_BASE_ADDR_V            *((volatile int *) (ADF_BASE  + 0x14))
//#define DB_STATUS               *((volatile int *) (ADF_BASE  + 0x18))
#define ADF_DONE                  *((volatile int *) (ADF_BASE  + 0x18))
#define ADF_START                 *((volatile int *) (ADF_BASE  + 0x1C))
#define ADF_READ_DONE             *((volatile int *) (ADF_BASE  + 0x20))


/* DMAC  - regular dmac */
#define DMA_STAT                  *((volatile int *) (DMAC_BASE + 0x00))
#define DMA_SADDY                 *((volatile int *) (DMAC_BASE + 0x04))
#define DMA_SADDU                 *((volatile int *) (DMAC_BASE + 0x08))
#define DMA_SADDV                 *((volatile int *) (DMAC_BASE + 0x0C))
#define DMA_DADDY                 *((volatile int *) (DMAC_BASE + 0x10))
#define DMA_DADDU                 *((volatile int *) (DMAC_BASE + 0x14))
#define DMA_DADDV                 *((volatile int *) (DMAC_BASE + 0x18))
#define DMA_CTRL                  *((volatile int *) (DMAC_BASE + 0x1C))
#define DMA_SIZE                  *((volatile int *) (DMAC_BASE + 0x20))
#define DMA_MODE                  *((volatile int *) (DMAC_BASE + 0x24)) //0 : normal 1: recompression



/* DMAC - recompression version*/
//#define DMA_CR0                 *((volatile int *) (DMAC_BASE + 0x00))
//#define DMA_CR1                 *((volatile int *) (DMAC_BASE + 0x04))
//#define DMA_CR2                 *((volatile int *) (DMAC_BASE + 0x08))
//#define DMA_CR3                 *((volatile int *) (DMAC_BASE + 0x0C))
//#define DMA_SR0                 *((volatile int *) (DMAC_BASE + 0x10))

/* OSC */
#define OSCCR0                    *((volatile int *) (OSC_BASE + 0x00))
#define OSCSR0                    *((volatile int *) (OSC_BASE + 0x04))
//added by eskim:begin
#define OSC_CNT_STREAM            *((volatile int *) (OSC_BASE + 0x10))
#define OSC_CNT_OVERFLOW          *((volatile int *) (OSC_BASE + 0x14))
#define OSC_CUR_QUEUE_SIZE        *((volatile int *) (OSC_BASE + 0x18))
#define OSC_MAX_QUEUE_SIZE        *((volatile int *) (OSC_BASE + 0x1c))

/* OSB */
#define OSB_FILL_NUM              *((volatile int *) (OSB_BASE + 0x00))
#define OSB_EMPTY_NUM             *((volatile int *) (OSB_BASE + 0x04))
#define OSB_FILL_RATE             *((volatile int *) (OSB_BASE + 0x08))
#define OSB_SAFE                  *((volatile int *) (OSB_BASE + 0x0c))
#define OSB_DATA_FIFO             *((volatile int *) (OSB_BASE + (1 << 15))) //090408_jykim_mux+

/* IMG */
#define IMAGE_Y_BASE                  *((volatile int *) (IMG_BASE + 0x00)) //0x00
#define IMAGE_U_BASE                  *((volatile int *) (IMG_BASE + 0x04)) //0x04
#define IMAGE_V_BASE                  *((volatile int *) (IMG_BASE + 0x08)) //0x08
#define IMAGE_Y_ADDR                  *((volatile int *) (IMG_BASE + 0x0c)) //0x0c
#define IMAGE_U_ADDR                  *((volatile int *) (IMG_BASE + 0x10)) //0x10
#define IMAGE_V_ADDR                  *((volatile int *) (IMG_BASE + 0x14)) //0x14
#define IMAGE_CAM_X_SIZE              *((volatile int *) (IMG_BASE + 0x18)) //0x18
#define IMAGE_CAM_Y_SIZE              *((volatile int *) (IMG_BASE + 0x1c)) //0x1c
#define IMAGE_FRAME_X_SIZE            *((volatile int *) (IMG_BASE + 0x20)) //0x20
#define IMAGE_FRAME_Y_SIZE            *((volatile int *) (IMG_BASE + 0x24)) //0x24
#define IMAGE_SAMPLE_RATE_X           *((volatile int *) (IMG_BASE + 0x28)) //0x28
#define IMAGE_SAMPLE_RATE_Y           *((volatile int *) (IMG_BASE + 0x2c)) //0x2c
#define IMAGE_X_CNT                   *((volatile int *) (IMG_BASE + 0x30)) //0x30
#define IMAGE_Y_CNT                   *((volatile int *) (IMG_BASE + 0x34)) //0x34
#define IMAGE_TRANS_Y_CNT             *((volatile int *) (IMG_BASE + 0x38)) //0x38
#define IMAGE_DOUBLE_BUFFER_EN        *((volatile int *) (IMG_BASE + 0x3c)) //0x3c
#define IMAGE_FRAME_OFFSET            *((volatile int *) (IMG_BASE + 0x40)) //0x40
#define IMAGE_FRAME_CNT               *((volatile int *) (IMG_BASE + 0x44)) //0x44
#define IMAGE_ENCODING_ONE_FRAME_DONE *((volatile int *) (IMG_BASE + 0x48)) //0x48
#define IMAGE_ENABLE                  *((volatile int *) (IMG_BASE + 0x4c)) //0x4c
#define IMAGE_AFIFO_SIZE_IN_BURST16   *((volatile int *) (IMG_BASE + 0x50))	//0x50
#define IMAGE_AFIFO_ALMOST_FULL       *((volatile int *) (IMG_BASE + 0x54))	//0x54
#define IMAGE_ENCODING_MB_Y           *((volatile int *) (IMG_BASE + 0x58)) //0x58
#define IMAGE_FRAME_OFFSET1           *((volatile int *) (IMG_BASE + 0x5c)) //0x5c
#define IMAGE_SXGA_TO_VGA             *((volatile int *) (IMG_BASE + 0x60)) //0x60
#define IMAGE_VSYNC_SKIP_ONLY         *((volatile int *) (IMG_BASE + 0x60)) //0x60
#ifdef BI_PREDICTION_MODE
#define IMAGE_FRAME_OFFSET2           *((volatile int *) (IMG_BASE + 0x64))	//0x64
#define IMAGE_FRAME_OFFSET3           *((volatile int *) (IMG_BASE + 0x68))	//0x68
#endif

//#define IMAGE_CR                *((volatile int *) (IMG_BASE + 0x00))
//#define IMAGE_SR                *((volatile int *) (IMG_BASE + 0x04))

///////////////////////////////////////////////////
//  // jarre 2009.06.08 dual stream +      vvvvvvvv
/* S_IMG */
#define S_IMAGE_Y_BASE                  *((volatile int *) (S_IMG_BASE + 0x00)) //0x00
#define S_IMAGE_U_BASE                  *((volatile int *) (S_IMG_BASE + 0x04)) //0x04
#define S_IMAGE_V_BASE                  *((volatile int *) (S_IMG_BASE + 0x08)) //0x08
#define S_IMAGE_Y_ADDR                  *((volatile int *) (S_IMG_BASE + 0x0c)) //0x0c
#define S_IMAGE_U_ADDR                  *((volatile int *) (S_IMG_BASE + 0x10)) //0x10
#define S_IMAGE_V_ADDR                  *((volatile int *) (S_IMG_BASE + 0x14)) //0x14
#define S_IMAGE_CAM_X_SIZE              *((volatile int *) (S_IMG_BASE + 0x18)) //0x18
#define S_IMAGE_CAM_Y_SIZE              *((volatile int *) (S_IMG_BASE + 0x1c)) //0x1c
#define S_IMAGE_FRAME_X_SIZE            *((volatile int *) (S_IMG_BASE + 0x20)) //0x20
#define S_IMAGE_FRAME_Y_SIZE            *((volatile int *) (S_IMG_BASE + 0x24)) //0x24
#define S_IMAGE_SAMPLE_RATE_X           *((volatile int *) (S_IMG_BASE + 0x28)) //0x28
#define S_IMAGE_SAMPLE_RATE_Y           *((volatile int *) (S_IMG_BASE + 0x2c)) //0x2c
#define S_IMAGE_X_CNT                   *((volatile int *) (S_IMG_BASE + 0x30)) //0x30
#define S_IMAGE_Y_CNT                   *((volatile int *) (S_IMG_BASE + 0x34)) //0x34
#define S_IMAGE_TRANS_Y_CNT             *((volatile int *) (S_IMG_BASE + 0x38)) //0x38
#define S_IMAGE_DOUBLE_BUFFER_EN        *((volatile int *) (S_IMG_BASE + 0x3c)) //0x3c
#define S_IMAGE_FRAME_OFFSET            *((volatile int *) (S_IMG_BASE + 0x40)) //0x40
#define S_IMAGE_FRAME_CNT               *((volatile int *) (S_IMG_BASE + 0x44)) //0x44
#define S_IMAGE_ENCODING_ONE_FRAME_DONE *((volatile int *) (S_IMG_BASE + 0x48)) //0x48
#define S_IMAGE_ENABLE                  *((volatile int *) (S_IMG_BASE + 0x4c)) //0x4c
#define S_IMAGE_AFIFO_SIZE_IN_BURST16   *((volatile int *) (S_IMG_BASE + 0x50))	//0x50
#define S_IMAGE_AFIFO_ALMOST_FULL       *((volatile int *) (S_IMG_BASE + 0x54))	//0x54
#define S_IMAGE_ENCODING_MB_Y           *((volatile int *) (S_IMG_BASE + 0x58)) //0x58
#define S_IMAGE_FRAME_OFFSET1           *((volatile int *) (S_IMG_BASE + 0x5c)) //0x5c
#define S_IMAGE_SXGA_TO_VGA             *((volatile int *) (S_IMG_BASE + 0x60)) //0x60
#define S_IMAGE_VSYNC_SKIP_ONLY         *((volatile int *) (S_IMG_BASE + 0x60)) //0x60
#ifdef BI_PREDICTION_MODE
#define S_IMAGE_FRAME_OFFSET2           *((volatile int *) (S_IMG_BASE + 0x64))	//0x64
#define S_IMAGE_FRAME_OFFSET3           *((volatile int *) (S_IMG_BASE + 0x68))	//0x68
#endif
//  // jarre 2009.06.08 dual stream +      ^^^^^^^^
///////////////////////////////////////////////////

//#define IMAGE_VOP_WIDTH         (_x_)      ((_x_ & 0xFF) << 24)
//#define IMAGE_VOP_HEIGHT        (_x_)     ((_x_ & 0xFF) << 16)
//#define IMAGE_CAM_SEL           (_x_)        ((_x_ & 0x7) << 4)
//#define IMAGE_JPEG_MODE         (_x_)      ((_x_ & 0x1) << 2)
//#define IMAGE_GRAY_EN           (_x_)        ((_x_ & 0x1) << 1)
//#define IMAGE_VIM_START         (_x_)      ((_x_ & 0x1))

#define CAM_SEL_SXGA              0 // 1280x1024
#define CAM_SEL_VGA               1 // 640x480
#define CAM_SEL_QVGA              2 // 320x240
#define CAM_SEL_QQVGA             3 // 160x128
#define CAM_SEL_CIF               4 // 352x288
#define CAM_SEL_QCIF              5 // 176x144
#define CAM_SEL_QQCIF             6 // 96x80

#define IMG_IF_VOP_DONE           3 
#define IMG_IF_VIM_DONE           2 
#define IMG_IF_LINE_DONE          1

//////////////////////////////////////////////////////////////////////////////
// ISP
//////////////////////////////////////////////////////////////////////////////
/* LS; Lens-Shading */
#define ISP_LS_CAM_SEL            *((volatile int *) (LS_BASE_ADDR + 0x00))
#define ISP_LS_RX                 *((volatile int *) (LS_BASE_ADDR + 0x04))
#define ISP_LS_RY                 *((volatile int *) (LS_BASE_ADDR + 0x08))
#define ISP_LS_XO                 *((volatile int *) (LS_BASE_ADDR + 0x0c))
#define ISP_LS_YO                 *((volatile int *) (LS_BASE_ADDR + 0x10))

/* AE; Auto Exposure */
#define ISP_AE_IMG_WIDTH          *((volatile int *) (AE_BASE_ADDR + 0x00))
#define ISP_AE_IMG_HEIGHT         *((volatile int *) (AE_BASE_ADDR + 0x04))
#define ISP_AE_OBJ_START_X        *((volatile int *) (AE_BASE_ADDR + 0x08))
#define ISP_AE_OBJ_STOP_X         *((volatile int *) (AE_BASE_ADDR + 0x0c))
#define ISP_AE_OBJ_START_Y        *((volatile int *) (AE_BASE_ADDR + 0x10))
#define ISP_AE_OBJ_STOP_Y         *((volatile int *) (AE_BASE_ADDR + 0x14))

#define ISP_AE_STATUS				*((volatile int *) (AE_BASE_ADDR + 0x18))
//#define ISP_AE_SUM_BG				*((volatile int *) (AE_BASE_ADDR + 0x1c))
#define ISP_AE_SUM_BG1				*((volatile int *) (AE_BASE_ADDR + 0x1c))
#define ISP_AE_SUM_OBJ				*((volatile int *) (AE_BASE_ADDR + 0x20))
//#define ISP_AE_ADDER_INDICATOR		*((volatile int *) (AE_BASE_ADDR + 0x24))
#define ISP_AE_SUM_BG2				*((volatile int *) (AE_BASE_ADDR + 0x24))
//#define ISP_AE_GAIN_R				*((volatile int *) (AE_BASE_ADDR + 0x28))
#define ISP_AE_ADDER_INDICATOR		*((volatile int *) (AE_BASE_ADDR + 0x28))
//#define ISP_AE_GAIN_G				*((volatile int *) (AE_BASE_ADDR + 0x2c))
#define ISP_AE_GAIN_R				*((volatile int *) (AE_BASE_ADDR + 0x2c))
//#define ISP_AE_GAIN_B				*((volatile int *) (AE_BASE_ADDR + 0x30))
#define ISP_AE_GAIN_G				*((volatile int *) (AE_BASE_ADDR + 0x30))
//#define ISP_AE_SUBMIT_GAIN			*((volatile int *) (AE_BASE_ADDR + 0x34))
#define ISP_AE_GAIN_B				*((volatile int *) (AE_BASE_ADDR + 0x34))

//#define ISP_AE_AE_SUM_OUT           *((volatile int *) (AE_BASE_ADDR + 0x18))
//#define ISP_AE_BACK_SUM_OUT         *((volatile int *) (AE_BASE_ADDR + 0x1c))
//#define ISP_AE_OBJECT_SUM_OUT       *((volatile int *) (AE_BASE_ADDR + 0x20))
//#define ISP_AE_ADDER_INDICATOR      *((volatile int *) (AE_BASE_ADDR + 0x24))
//#define ISP_AE_R_GAIN               *((volatile int *) (AE_BASE_ADDR + 0x28))
//#define ISP_AE_G_GAIN               *((volatile int *) (AE_BASE_ADDR + 0x2c))
//#define ISP_AE_B_GAIN               *((volatile int *) (AE_BASE_ADDR + 0x30))
//#define ISP_AE_AE_GAIN              *((volatile int *) (AE_BASE_ADDR + 0x34))
#define ISP_AAC_BYPASS_EN           *((volatile int *) (AE_BASE_ADDR + 0x38))
#ifdef USE_HIF
#define ISP_AEC_BYPASS_EN           *HIF_REG2
#endif

/* AWB; Auto White Banlance */
#define ISP_AWB_IMG_WIDTH           *((volatile int *) (AWB_BASE_ADDR + 0x00))
#define ISP_AWB_IMG_HEIGHT          *((volatile int *) (AWB_BASE_ADDR + 0x04))
#define ISP_AWB_STATUS				*((volatile int *) (AWB_BASE_ADDR + 0x08))
#define ISP_AWB_SUM_R			    *((volatile int *) (AWB_BASE_ADDR + 0x0c))
#define ISP_AWB_SUM_G			    *((volatile int *) (AWB_BASE_ADDR + 0x10))
#define ISP_AWB_SUM_B			    *((volatile int *) (AWB_BASE_ADDR + 0x14))
#define ISP_AWB_GAIN_R				*((volatile int *) (AWB_BASE_ADDR + 0x18))
#define ISP_AWB_GAIN_G				*((volatile int *) (AWB_BASE_ADDR + 0x1c))
#define ISP_AWB_GAIN_B				*((volatile int *) (AWB_BASE_ADDR + 0x20))
//#define ISP_AWB_SUBMIT_GAIN			*((volatile int *) (AWB_BASE_ADDR + 0x24))
//#define ISP_AWB_SUM_OUT             *((volatile int *) (AWB_BASE_ADDR + 0x08))
//#define ISP_AWB_R_SUM_OUT           *((volatile int *) (AWB_BASE_ADDR + 0x0c))
//#define ISP_AWB_G_SUM_OUT           *((volatile int *) (AWB_BASE_ADDR + 0x10))
//#define ISP_AWB_B_SUM_OUT           *((volatile int *) (AWB_BASE_ADDR + 0x14))
//#define ISP_AWB_R_GAIN              *((volatile int *) (AWB_BASE_ADDR + 0x18))
//#define ISP_AWB_G_GAIN              *((volatile int *) (AWB_BASE_ADDR + 0x1c))
//#define ISP_AWB_B_GAIN              *((volatile int *) (AWB_BASE_ADDR + 0x20))
//#define ISP_AWB_GAIN_OK             *((volatile int *) (AWB_BASE_ADDR + 0x24))
//#define ISP_AWB_BYPASS_EN           *((volatile int *) (AWB_BASE_ADDR + 0x28))
#define ISP_AWB_BYPASS_EN           *((volatile int *) (AWB_BASE_ADDR + 0x24))

//#define ISP_AWB_HW_SW               *HIF_REG2
//#define ISP_AE_REGION_GAIN          *HIF_REG2 //signal97_080123++
//#define ISP_AWB_SW_GAIN_R           *HIF_REG3
//#define ISP_AWB_SW_GAIN_G           *HIF_REG4
//#define ISP_AWB_SW_GAIN_B           *HIF_REG5

/* DM; Demosaick */
#define ISP_DM_IMG_WIDTH            *((volatile int *) (DM_BASE_ADDR + 0x00))
#define ISP_DM_IMG_HEIGHT           *((volatile int *) (DM_BASE_ADDR + 0x04))
#define ISP_DM_HREF_LOW_DURATION    *((volatile int *) (DM_BASE_ADDR + 0x08))
#define ISP_DM_VSYNC_DELAY			*((volatile int *) (DM_BASE_ADDR + 0x0c))
#define ISP_DM_VSYNC_LEN			*((volatile int *) (DM_BASE_ADDR + 0x10))

/* SP; Spread */
//#define ISP_SP_IMG_WIDTH          *((volatile int *) (SP_BASE_ADDR + 0x00))
//removed

/* DNF; Denoise Filter */
#define ISP_DNF_IMG_WIDTH            *((volatile int *) (DNF_BASE_ADDR + 0x00))
#define ISP_DNF_IMG_HEIGHT           *((volatile int *) (DNF_BASE_ADDR + 0x04))
#define ISP_DNF_BYPASS_EN            *((volatile int *) (DNF_BASE_ADDR + 0x08))

// DHKIM
#define ISP_DNF_RUN_MODE            *((volatile int *) (DNF_BASE_ADDR + 0x0c))
/* SHP; Sharpening */
#define ISP_SHP_IMG_WIDTH			*((volatile int *) (SHP_BASE_ADDR + 0x00))
#define ISP_SHP_IMG_HEIGHT			*((volatile int *) (SHP_BASE_ADDR + 0x04))
#define ISP_SHP_BYPASS_EN			*((volatile int *) (SHP_BASE_ADDR + 0x08))

/* SC; Scaler */
#define ISP_SC_FINISH				*((volatile int *) (SC_BASE_ADDR + 0x00))
#define ISP_SC_BASE_ADDR			*((volatile int *) (SC_BASE_ADDR + 0x04))
#define ISP_SC_VALID_SET			*((volatile int *) (SC_BASE_ADDR + 0x08))
#define ISP_SC_MAGNIF				*((volatile int *) (SC_BASE_ADDR + 0x0c))
#define ISP_SC_POINT_X				*((volatile int *) (SC_BASE_ADDR + 0x10))
#define ISP_SC_POINT_Y				*((volatile int *) (SC_BASE_ADDR + 0x14))
#define ISP_SC_WIDTH				*((volatile int *) (SC_BASE_ADDR + 0x18))
#define ISP_SC_HEIGHT				*((volatile int *) (SC_BASE_ADDR + 0x1c))
#define ISP_SC_NEW_WIDTH			*((volatile int *) (SC_BASE_ADDR + 0x20))
#define ISP_SC_NEW_HEIGHT			*((volatile int *) (SC_BASE_ADDR + 0x24))
#define ISP_SC_FRAME_OFFSET			*((volatile int *) (SC_BASE_ADDR + 0x28))
#define ISP_SC_EXT_REQ				*((volatile int *) (SC_BASE_ADDR + 0x2c))
#define ISP_SC_EXT_MODE				*((volatile int *) (SC_BASE_ADDR + 0x30))

#define ISP_SC_COEF_RAM_START_ADDR	((volatile int *) (SC_BASE_ADDR + 0x1000))

/* GC; Gamma Correction */
//#define ISP_GC_MODE                 *((volatile int *) (GC_BASE_ADDR + 0x00))
#define ISP_GC_EXT_MODE             *((volatile int *) (GC_BASE_ADDR + 0x00))
#define ISP_GC_BYPASS_EN            *((volatile int *) (GC_BASE_ADDR + 0x04))

#define ISP_GC_COEF_RAM_START_ADDR	((volatile int *) (GC_BASE_ADDR + 0x1000))

/* CC; Color Correction */
#define ISP_CC_IMG_WIDTH          *((volatile int *) (CC_BASE_ADDR + 0x00))
#define ISP_CC_MATRIX_00          *((volatile int *) (CC_BASE_ADDR + 0x04))
#define ISP_CC_MATRIX_01          *((volatile int *) (CC_BASE_ADDR + 0x08))
#define ISP_CC_MATRIX_02          *((volatile int *) (CC_BASE_ADDR + 0x0c))
#define ISP_CC_MATRIX_10          *((volatile int *) (CC_BASE_ADDR + 0x10))
#define ISP_CC_MATRIX_11          *((volatile int *) (CC_BASE_ADDR + 0x14))
#define ISP_CC_MATRIX_12          *((volatile int *) (CC_BASE_ADDR + 0x18))
#define ISP_CC_MATRIX_20          *((volatile int *) (CC_BASE_ADDR + 0x1c))
#define ISP_CC_MATRIX_21          *((volatile int *) (CC_BASE_ADDR + 0x20))
#define ISP_CC_MATRIX_22          *((volatile int *) (CC_BASE_ADDR + 0x24))

/* YUV CC; YUV correction by hue/saturation */
#define ISP_YUV_CC_IMG_WIDTH         *((volatile int *) (YUV_CC_BASE_ADDR + 0x00))
#define ISP_YUV_CC_MATRIX_00          *((volatile int *) (YUV_CC_BASE_ADDR + 0x04))
#define ISP_YUV_CC_MATRIX_01          *((volatile int *) (YUV_CC_BASE_ADDR + 0x08))
#define ISP_YUV_CC_MATRIX_02          *((volatile int *) (YUV_CC_BASE_ADDR + 0x0c))
#define ISP_YUV_CC_MATRIX_10          *((volatile int *) (YUV_CC_BASE_ADDR + 0x10))
#define ISP_YUV_CC_MATRIX_11          *((volatile int *) (YUV_CC_BASE_ADDR + 0x14))
#define ISP_YUV_CC_MATRIX_12          *((volatile int *) (YUV_CC_BASE_ADDR + 0x18))
#define ISP_YUV_CC_MATRIX_20          *((volatile int *) (YUV_CC_BASE_ADDR + 0x1c))
#define ISP_YUV_CC_MATRIX_21          *((volatile int *) (YUV_CC_BASE_ADDR + 0x20))
#define ISP_YUV_CC_MATRIX_22          *((volatile int *) (YUV_CC_BASE_ADDR + 0x24))

/* CSC; Color Space Conversion */
#define ISP_CSC_IMG_WIDTH         *((volatile int *) (CSC_BASE_ADDR + 0x00))
#define ISP_CSC_BW_MODE         *((volatile int *) (CSC_BASE_ADDR + 0x04))

/* CTRL; Control module */
#define ISP_CTRL_MODE               *((volatile int *) (CTRL_BASE_ADDR + 0x00))
#define ISP_CTRL_ENABLE             *((volatile int *) (CTRL_BASE_ADDR + 0x04))
#define ISP_DOUBLE_BUFFER_EN        *((volatile int *) (CTRL_BASE_ADDR + 0x08))
#define ISP_VALID_FRAME_CNT         *((volatile int *) (CTRL_BASE_ADDR + 0x0c))
#define ISP_ENCODING_ONE_FRAME_DONE *((volatile int *) (CTRL_BASE_ADDR + 0x10))
#define ISP_INTR_CLR                *((volatile int *) (CTRL_BASE_ADDR + 0x14))
#define ISP_FRAME_SKIP_DISEN        *((volatile int *) (CTRL_BASE_ADDR + 0x18))
#define ISP_BYPASS_SCALER           *((volatile int *) (CTRL_BASE_ADDR + 0x1c))
#define ISP_AFIFO_ALMOST_FULL       *((volatile int *) (CTRL_BASE_ADDR + 0x20))

/* OUT; Output module YUV */
#define ISP_OUT_Y_START_ADDR        *((volatile int *) (OUT_YUV_BASE_ADDR + 0x00))
#define ISP_OUT_U_START_ADDR        *((volatile int *) (OUT_YUV_BASE_ADDR + 0x04))
#define ISP_OUT_V_START_ADDR        *((volatile int *) (OUT_YUV_BASE_ADDR + 0x08))
#define ISP_OUT_Y_END_ADDR          *((volatile int *) (OUT_YUV_BASE_ADDR + 0x0c))
#define ISP_OUT_U_END_ADDR          *((volatile int *) (OUT_YUV_BASE_ADDR + 0x10))
#define ISP_OUT_V_END_ADDR          *((volatile int *) (OUT_YUV_BASE_ADDR + 0x14))
#define ISP_OUT_WORDS_PER_LINE      *((volatile int *) (OUT_YUV_BASE_ADDR + 0x18))
#define ISP_OUT_TRANS_Y_CNT         *((volatile int *) (OUT_YUV_BASE_ADDR + 0x1c))
#define ISP_OUT_FRAME_OFFSET        *((volatile int *) (OUT_YUV_BASE_ADDR + 0x20))
#define ISP_OUT_Y_ADDR_DST          *((volatile int *) (OUT_YUV_BASE_ADDR + 0x24))
#define ISP_OUT_U_ADDR_DST          *((volatile int *) (OUT_YUV_BASE_ADDR + 0x28))
#define ISP_OUT_V_ADDR_DST          *((volatile int *) (OUT_YUV_BASE_ADDR + 0x2c))
#define ISP_OUT_FIFO_IN_CNT         *((volatile int *) (OUT_YUV_BASE_ADDR + 0x30))
#define ISP_OUT_FIFO_MAX_CNT        *((volatile int *) (OUT_YUV_BASE_ADDR + 0x34))
#define ISP_OUT_TRANS_OUT_WDATA_CNT *((volatile int *) (OUT_YUV_BASE_ADDR + 0x38))
#define ISP_OUT_TRANS_OUT_DONE_CNT  *((volatile int *) (OUT_YUV_BASE_ADDR + 0x3c))
#define ISP_OUT_YUV_ENABLE			*((volatile int *) (OUT_YUV_BASE_ADDR + 0x40))
//#define ISP_OUT_FIFO_CNT_VSYNC_CLEAR    *((volatile int *) (OUT_YUV_BASE_ADDR + 0x44)) // to trace async fifo
//#define ISP_OUT_FIFO_WR_CNT             *((volatile int *) (OUT_YUV_BASE_ADDR + 0x48)) // to trace async fifo
//#define ISP_OUT_FIFO_RD_CNT             *((volatile int *) (OUT_YUV_BASE_ADDR + 0x4c)) // to trace async fifo
#define ISP_OUT_ENCODING_MB_Y           *((volatile int *) (OUT_YUV_BASE_ADDR + 0x50))
#define ISP_OUT_FRAME_OFFSET1           *((volatile int *) (OUT_YUV_BASE_ADDR + 0x54))
#define ISP_OUT_ALMOST_FULL_RATE        *((volatile int *) (OUT_YUV_BASE_ADDR + 0x58))

/* FM; Focusing Measure Calculator */
#define ISP_FM_SUM_VALID        *((volatile int *) (FM_BASE_ADDR + 0x00))
#define ISP_FM_SUM     		   *((volatile int *) (FM_BASE_ADDR + 0x04))
#define ISP_FM_IMG_WIDTH        *((volatile int *) (FM_BASE_ADDR + 0x08))
#define ISP_FM_IMG_HEIGHT        *((volatile int *) (FM_BASE_ADDR + 0x0c))
#define ISP_FM_HSYNC_DELAY        *((volatile int *) (FM_BASE_ADDR + 0x10))

/* OUT; Output module RGB */
#define ISP_OUT_RGB_START_ADDR        *((volatile int *) (OUT_RGB_BASE_ADDR + 0x00))	// RGB
#define ISP_OUT_RGB_END_ADDR          *((volatile int *) (OUT_RGB_BASE_ADDR + 0x04))	// RGB
#define ISP_OUT_RGB_COLOR_DEPTH       *((volatile int *) (OUT_RGB_BASE_ADDR + 0x08))	// RGB
#define ISP_OUT_RGB_FRAME_OFFSET      *((volatile int *) (OUT_RGB_BASE_ADDR + 0x0c))	// RGB
#define ISP_OUT_RGB_CURRENT_ADDR      *((volatile int *) (OUT_YUV_BASE_ADDR + 0x58))	// RGB
#define ISP_OUT_RGB_ALMOST_FULL_RATE  *((volatile int *) (OUT_YUV_BASE_ADDR + 0x58))	// RGB

/* AGC; Auto Gain Control */
//#define ISP_AGC_IMG_WIDTH			*((volatile int *) (AGC_BASE_ADDR + 0x00))
//#define ISP_AGC_IMG_HEIGHT			*((volatile int *) (AGC_BASE_ADDR + 0x04))
//#define ISP_AGC_GAIN				*((volatile int *) (AGC_BASE_ADDR + 0x08))
//#define ISP_AGC_SUBMIT_GAIN			*((volatile int *) (AGC_BASE_ADDR + 0x0c))
//#define ISP_AGC_BYPASS_EN			*((volatile int *) (AGC_BASE_ADDR + 0x10))
#define ISP_AGC_IMG_WIDTH           *((volatile int *) (AGC_BASE_ADDR + 0x00))
#define ISP_AGC_IMG_HEIGHT          *((volatile int *) (AGC_BASE_ADDR + 0x04))
#define ISP_AGC_OBJ_START_X         *((volatile int *) (AGC_BASE_ADDR + 0x08))
#define ISP_AGC_OBJ_STOP_X          *((volatile int *) (AGC_BASE_ADDR + 0x0c))
#define ISP_AGC_OBJ_START_Y         *((volatile int *) (AGC_BASE_ADDR + 0x10))
#define ISP_AGC_OBJ_STOP_Y          *((volatile int *) (AGC_BASE_ADDR + 0x14))
#define ISP_AGC_STATUS				*((volatile int *) (AGC_BASE_ADDR + 0x18))
//#define ISP_AGC_SUM_BG				*((volatile int *) (AGC_BASE_ADDR + 0x1c))
#define ISP_AGC_SUM_BG1				*((volatile int *) (AGC_BASE_ADDR + 0x1c))
#define ISP_AGC_SUM_OBJ				*((volatile int *) (AGC_BASE_ADDR + 0x20))
//#define ISP_AGC_GAIN					*((volatile int *) (AGC_BASE_ADDR + 0x24))
#define ISP_AGC_SUM_BG2				*((volatile int *) (AGC_BASE_ADDR + 0x24))
//#define ISP_AGC_SUBMIT_GAIN			*((volatile int *) (AGC_BASE_ADDR + 0x28))
#define ISP_AGC_GAIN				*((volatile int *) (AGC_BASE_ADDR + 0x28))
#define ISP_AGC_BYPASS_EN           *((volatile int *) (AGC_BASE_ADDR + 0x2c))


/* SCCB; SCCB Master */
#if 0
#define ISP_SCCB_SLAVE_ID           *((volatile int *) (SCCB_BASE_ADDR + 0x03fc))
#else
#define ISP_SCCB_ADDR               *((volatile int *) (SCCB_BASE_ADDR + 0x00))
#define ISP_SCCB_WDATA              *((volatile int *) (SCCB_BASE_ADDR + 0x04))
#define ISP_SCCB_RDATA              *((volatile int *) (SCCB_BASE_ADDR + 0x08))
#define ISP_SCCB_RW                 *((volatile int *) (SCCB_BASE_ADDR + 0x0c))
#define ISP_SCCB_START              *((volatile int *) (SCCB_BASE_ADDR + 0x10))
#define ISP_SCCB_STATUS             *((volatile int *) (SCCB_BASE_ADDR + 0x14))
#define ISP_SCCB_SLAVE_ID           *((volatile int *) (SCCB_BASE_ADDR + 0x18))
#endif

/* I2C; I2C Master */				//signal97 I2C_Master ++		
#define ISP_I2C_PS_REG_LOW          *((volatile int *) (IIC_MASTER_BASE + 0x00))   //prescale register	
#define ISP_I2C_PS_REG_HIGH         *((volatile int *) (IIC_MASTER_BASE + 0x04))   //prescale register
#define ISP_I2C_CTRL_REG            *((volatile int *) (IIC_MASTER_BASE + 0x08))   //control register
#define ISP_I2C_TX_REG		        *((volatile int *) (IIC_MASTER_BASE + 0x0c))   //tranmit register, write_enable
#define ISP_I2C_RX_REG              *((volatile int *) (IIC_MASTER_BASE + 0x0c))   //receiver register
#define ISP_I2C_COM_REG             *((volatile int *) (IIC_MASTER_BASE + 0x10))   //command register, write_enable
#define ISP_I2C_SR_REG              *((volatile int *) (IIC_MASTER_BASE + 0x10))   //status register
									//signal97 I2C_Master -- 
#ifdef MEM_TO_USB
//////////////////////////////////////////////////////////////////////////////
// MEM_TO_USB
//////////////////////////////////////////////////////////////////////////////
#define MEM_USB_ENABLE				*((volatile int *) (USB_BASE_ADDR + 0x00))
#define MEM_USB_START				*((volatile int *) (USB_BASE_ADDR + 0x04))
#define MEM_USB_FINISH				*((volatile int *) (USB_BASE_ADDR + 0x08))
#define MEM_USB_SRC_BASE_ADDR		*((volatile int *) (USB_BASE_ADDR + 0x0c))
#define MEM_USB_SRC_END_ADDR		*((volatile int *) (USB_BASE_ADDR + 0x10))
#else
//////////////////////////////////////////////////////////////////////////////
// USB device
//////////////////////////////////////////////////////////////////////////////
#define USB_CSR						*((volatile int *) (USB_BASE_ADDR + 0x0000))
#define USB_FA						*((volatile int *) (USB_BASE_ADDR + 0x0004))
#define USB_INT_MSK					*((volatile int *) (USB_BASE_ADDR + 0x0008))
#define USB_INT_SRC					*((volatile int *) (USB_BASE_ADDR + 0x000c))
#define USB_FRM_NAT					*((volatile int *) (USB_BASE_ADDR + 0x0010))
#define USB_REV						*((volatile int *) (USB_BASE_ADDR + 0x0014))
#define USB_GPOUT					*((volatile int *) (USB_BASE_ADDR + 0x0018))
#define USB_GPIN					*((volatile int *) (USB_BASE_ADDR + 0x001c))
/* Endpoint Registers */
#define USB_EP0_CSR					*((volatile int *) (USB_BASE_ADDR + 0x0040))
#define USB_EP0_INT					*((volatile int *) (USB_BASE_ADDR + 0x0044))
#define USB_EP0_OBA					*((volatile int *) (USB_BASE_ADDR + 0x0048))
#define USB_EP0_IBA					*((volatile int *) (USB_BASE_ADDR + 0x004c))
#define USB_EP1_CSR					*((volatile int *) (USB_BASE_ADDR + 0x0050))
#define USB_EP1_INT					*((volatile int *) (USB_BASE_ADDR + 0x0054))
#define USB_EP1_OBA					*((volatile int *) (USB_BASE_ADDR + 0x0058))
#define USB_EP1_IBA					*((volatile int *) (USB_BASE_ADDR + 0x005c))
#define USB_EP2_CSR					*((volatile int *) (USB_BASE_ADDR + 0x0060))
#define USB_EP2_INT					*((volatile int *) (USB_BASE_ADDR + 0x0064))
#define USB_EP2_OBA					*((volatile int *) (USB_BASE_ADDR + 0x0068))
#define USB_EP2_IBA					*((volatile int *) (USB_BASE_ADDR + 0x006c))
#define USB_EP3_CSR					*((volatile int *) (USB_BASE_ADDR + 0x0070))
#define USB_EP3_INT					*((volatile int *) (USB_BASE_ADDR + 0x0074))
#define USB_EP3_OBA					*((volatile int *) (USB_BASE_ADDR + 0x0078))
#define USB_EP3_IBA					*((volatile int *) (USB_BASE_ADDR + 0x007c))
#define USB_EP4_CSR					*((volatile int *) (USB_BASE_ADDR + 0x0080))
#define USB_EP4_INT					*((volatile int *) (USB_BASE_ADDR + 0x0084))
#define USB_EP4_OBA					*((volatile int *) (USB_BASE_ADDR + 0x0088))
#define USB_EP4_IBA					*((volatile int *) (USB_BASE_ADDR + 0x008c))
#define USB_EP5_CSR					*((volatile int *) (USB_BASE_ADDR + 0x0090))
#define USB_EP5_INT					*((volatile int *) (USB_BASE_ADDR + 0x0094))
#define USB_EP5_OBA					*((volatile int *) (USB_BASE_ADDR + 0x0098))
#define USB_EP5_IBA					*((volatile int *) (USB_BASE_ADDR + 0x009c))
#define USB_EP6_CSR					*((volatile int *) (USB_BASE_ADDR + 0x00a0))
#define USB_EP6_INT					*((volatile int *) (USB_BASE_ADDR + 0x00a4))
#define USB_EP6_OBA					*((volatile int *) (USB_BASE_ADDR + 0x00a8))
#define USB_EP6_IBA					*((volatile int *) (USB_BASE_ADDR + 0x00ac))
#define USB_EP7_CSR					*((volatile int *) (USB_BASE_ADDR + 0x00b0))
#define USB_EP7_INT					*((volatile int *) (USB_BASE_ADDR + 0x00b4))
#define USB_EP7_OBA					*((volatile int *) (USB_BASE_ADDR + 0x00b8))
#define USB_EP7_IBA					*((volatile int *) (USB_BASE_ADDR + 0x00bc))
#define USB_EP8_CSR					*((volatile int *) (USB_BASE_ADDR + 0x00c0))
#define USB_EP8_INT					*((volatile int *) (USB_BASE_ADDR + 0x00c4))
#define USB_EP8_OBA					*((volatile int *) (USB_BASE_ADDR + 0x00c8))
#define USB_EP8_IBA					*((volatile int *) (USB_BASE_ADDR + 0x00cc))
#define USB_EP9_CSR					*((volatile int *) (USB_BASE_ADDR + 0x00d0))
#define USB_EP9_INT					*((volatile int *) (USB_BASE_ADDR + 0x00d4))
#define USB_EP9_OBA					*((volatile int *) (USB_BASE_ADDR + 0x00d8))
#define USB_EP9_IBA					*((volatile int *) (USB_BASE_ADDR + 0x00dc))
#define USB_EP10_CSR				*((volatile int *) (USB_BASE_ADDR + 0x00e0))
#define USB_EP10_INT				*((volatile int *) (USB_BASE_ADDR + 0x00e4))
#define USB_EP10_OBA				*((volatile int *) (USB_BASE_ADDR + 0x00e8))
#define USB_EP10_IBA				*((volatile int *) (USB_BASE_ADDR + 0x00ec))
#define USB_EP11_CSR				*((volatile int *) (USB_BASE_ADDR + 0x00f0))
#define USB_EP11_INT				*((volatile int *) (USB_BASE_ADDR + 0x00f4))
#define USB_EP11_OBA				*((volatile int *) (USB_BASE_ADDR + 0x00f8))
#define USB_EP11_IBA				*((volatile int *) (USB_BASE_ADDR + 0x00fc))
#define USB_EP12_CSR				*((volatile int *) (USB_BASE_ADDR + 0x0100))
#define USB_EP12_INT				*((volatile int *) (USB_BASE_ADDR + 0x0104))
#define USB_EP12_OBA				*((volatile int *) (USB_BASE_ADDR + 0x0108))
#define USB_EP12_IBA				*((volatile int *) (USB_BASE_ADDR + 0x010c))
#define USB_EP13_CSR				*((volatile int *) (USB_BASE_ADDR + 0x0110))
#define USB_EP13_INT				*((volatile int *) (USB_BASE_ADDR + 0x0114))
#define USB_EP13_OBA				*((volatile int *) (USB_BASE_ADDR + 0x0118))
#define USB_EP13_IBA				*((volatile int *) (USB_BASE_ADDR + 0x011c))
#define USB_EP14_CSR				*((volatile int *) (USB_BASE_ADDR + 0x0120))
#define USB_EP14_INT				*((volatile int *) (USB_BASE_ADDR + 0x0124))
#define USB_EP14_OBA				*((volatile int *) (USB_BASE_ADDR + 0x0128))
#define USB_EP14_IBA				*((volatile int *) (USB_BASE_ADDR + 0x012c))
#define USB_EP15_CSR				*((volatile int *) (USB_BASE_ADDR + 0x0130))
#define USB_EP15_INT				*((volatile int *) (USB_BASE_ADDR + 0x0134))
#define USB_EP15_OBA				*((volatile int *) (USB_BASE_ADDR + 0x0138))
#define USB_EP15_IBA				*((volatile int *) (USB_BASE_ADDR + 0x013c))
#endif

//090401_hunnoh_i2s_head+
//////////////////////////////////////////////////////////////////////////////
// I2S Device
//////////////////////////////////////////////////////////////////////////////
#define I2S_RxCR 				(I2S_BASE_ADDR + 0x0000) //(I2S Receive Control Register.)
#define I2S_TxCR 				(I2S_BASE_ADDR + 0x0004) //(I2S Transmit Control Register.)
#define I2S_SR 					(I2S_BASE_ADDR + 0x0008) //(I2S Status Register.)
#define I2S_COUNTER 			(I2S_BASE_ADDR + 0x000C) //(I2S Counter regster.)
#define I2S_FIFO 				(I2S_BASE_ADDR + 0x1000) //(Data read or written, from or to FIFO)
//090401_hunnoh_i2s_tail+

//090403_hunnoh_i2s_head+
#ifdef VIDAN4110
//////////////////////////////////////////////////////////////////////////////
// I2S1 Device
//////////////////////////////////////////////////////////////////////////////
#define I2S1_RxCR 				(I2S1_BASE_ADDR + 0x0000) //(I2S Receive Control Register.)
#define I2S1_TxCR 				(I2S1_BASE_ADDR + 0x0004) //(I2S Transmit Control Register.)
#define I2S1_SR 				(I2S1_BASE_ADDR + 0x0008) //(I2S Status Register.)
#define I2S1_COUNTER 			(I2S1_BASE_ADDR + 0x000C) //(I2S Counter regster.)
#define I2S1_FIFO 				(I2S1_BASE_ADDR + 0x1000) //(Data read or written, from or to FIFO)
#endif
//090403_hunnoh_i2s_tail+

//////////////////////////////////////////////////////////////////////////////
// SPI Master
//////////////////////////////////////////////////////////////////////////////
#define SPI_MASTER_DATA0   	    *((volatile int *) (SPI_MASTER_BASE_ADDR + 0x00))
#define SPI_MASTER_DATA1   	    *((volatile int *) (SPI_MASTER_BASE_ADDR + 0x04))
#define SPI_MASTER_DATA2   	    *((volatile int *) (SPI_MASTER_BASE_ADDR + 0x08))
#define SPI_MASTER_DATA3   	    *((volatile int *) (SPI_MASTER_BASE_ADDR + 0x0c))
#define SPI_MASTER_CTRL      	    *((volatile int *) (SPI_MASTER_BASE_ADDR + 0x10))
#define SPI_MASTER_CTRL_ASS       ( 1 << 13 )
#define SPI_MASTER_CTRL_IE        ( 1 << 12 )
#define SPI_MASTER_CTRL_LSB       ( 1 << 11 )
#define SPI_MASTER_CTRL_TX_NEG    ( 1 << 10 )
#define SPI_MASTER_CTRL_RX_NEG    ( 1 <<  9 )
#define SPI_MASTER_CTRL_GO_BUSY   ( 1 <<  8 )
#define SPI_MASTER_DIVIDER		    *((volatile int *) (SPI_MASTER_BASE_ADDR + 0x14))
#define SPI_MASTER_SS    		    *((volatile int *) (SPI_MASTER_BASE_ADDR + 0x18))


// -----------------------------------------------------------------------------
// SDIO jwjang 2008.08.07 +
// -----------------------------------------------------------------------------

//SDIO0 Register Define/*{{{*/
//#define SDIO0_BASE                0xD0080000
#define SDIO0_CC_CORECTRL_ADR     ( SDIO0_BASE + 0x00) //10d6_8100 
#define SDIO0_CC_CAPABILITY_ADR   ( SDIO0_BASE + 0x01)
#define SDIO0_CC_CORECTRL1_ADR    ( SDIO0_BASE + 0x02)
#define SDIO0_CC_CORESTATE_ADR    ( SDIO0_BASE + 0x03)

#define SDIO0_CC_CMDEVENTS0_ADR   ( SDIO0_BASE + 0x04) //0000_0000
#define SDIO0_CC_DATEVENTS0_ADR   ( SDIO0_BASE + 0x05)
#define SDIO0_CC_CMDEVENTS1_ADR   ( SDIO0_BASE + 0x06)
#define SDIO0_CC_DMAEVENTS_ADR    ( SDIO0_BASE + 0x07)

#define SDIO0_CC_CMDINTMASK0_ADR  ( SDIO0_BASE + 0x08) //0000_0000
#define SDIO0_CC_DATINTMASK0_ADR  ( SDIO0_BASE + 0x09)
#define SDIO0_CC_CMDINTMASK1_ADR  ( SDIO0_BASE + 0x0A)
#define SDIO0_CC_DMAINTMASK_ADR   ( SDIO0_BASE + 0x0B)

#define SDIO0_CC_CMDCTRL_ADR      ( SDIO0_BASE + 0x0C) //003f_0000
#define SDIO0_CC_CMDTRAP_ADR      ( SDIO0_BASE + 0x0D)
#define SDIO0_CC_CMDINDEX_ADR     ( SDIO0_BASE + 0x0E) 
#define SDIO0_CC_CMDCRC7_ADR      ( SDIO0_BASE + 0x0F)

#define SDIO0_CC_ARG_3_ADR        ( SDIO0_BASE + 0x10) //0000_0000
#define SDIO0_CC_ARG_2_ADR        ( SDIO0_BASE + 0x11)
#define SDIO0_CC_ARG_1_ADR        ( SDIO0_BASE + 0x12)
#define SDIO0_CC_ARG_0_ADR        ( SDIO0_BASE + 0x13)

#define SDIO0_CC_RESPCTRL_ADR     ( SDIO0_BASE + 0x14) //1000_0001
//reserved                        ( SDIO0_BASE + 0x15)
#define SDIO0_CC_RESPHDR_ADR      ( SDIO0_BASE + 0x16)
#define SDIO0_CC_RESPCRC7_ADR     ( SDIO0_BASE + 0x17)

#define SDIO0_CC_RESP_3_ADR       ( SDIO0_BASE + 0x18) //0000_0000
#define SDIO0_CC_RESP_2_ADR       ( SDIO0_BASE + 0x19)
#define SDIO0_CC_RESP_1_ADR       ( SDIO0_BASE + 0x1A)
#define SDIO0_CC_RESP_0_ADR       ( SDIO0_BASE + 0x1B)

#define SDIO0_CC_DATCTRL_ADR      ( SDIO0_BASE + 0x1C) //0000_0200
//reserved                        ( SDIO0_BASE + 0x1D)
#define SDIO0_CC_BLKLENHI_ADR     ( SDIO0_BASE + 0x1E)
#define SDIO0_CC_BLKLENLO_ADR     ( SDIO0_BASE + 0x1F)

#define SDIO0_CC_READCTRL_ADR     ( SDIO0_BASE + 0x20) //4100_0000
#define SDIO0_CC_SD_CRC16STT_ADR  ( SDIO0_BASE + 0x21)
//reserved                        ( SDIO0_BASE + 0x22)
//reserved                        ( SDIO0_BASE + 0x23)

#define SDIO0_CC_WRITECTRL_ADR    ( SDIO0_BASE + 0x24) //0100_0000
//reserved                        ( SDIO0_BASE + 0x25)
//reserved                        ( SDIO0_BASE + 0x26)
//reserved                        ( SDIO0_BASE + 0x27)

#define SDIO0_CC_WRFIFO_3_ADR     ( SDIO0_BASE + 0x28) //xxxx_xxxx //out
#define SDIO0_CC_WRFIFO_2_ADR     ( SDIO0_BASE + 0x29) 
#define SDIO0_CC_WRFIFO_1_ADR     ( SDIO0_BASE + 0x2A) 
#define SDIO0_CC_WRFIFO_0_ADR     ( SDIO0_BASE + 0x2B) 

#define SDIO0_CC_RDFIFO_3_ADR     ( SDIO0_BASE + 0x2C) //0000_0000 //in 
#define SDIO0_CC_RDFIFO_2_ADR     ( SDIO0_BASE + 0x2D)
#define SDIO0_CC_RDFIFO_1_ADR     ( SDIO0_BASE + 0x2E)
#define SDIO0_CC_RDFIFO_0_ADR     ( SDIO0_BASE + 0x2F)

//reserved      From 30 to 3F

#define SDIO0_CC_DMACTRL_ADR      ( SDIO0_BASE + 0x40) //0000_0000
#define SDIO0_CC_DMACTRL1_ADR     ( SDIO0_BASE + 0x41)
#define SDIO0_CC_DMABCNTHI_ADR    ( SDIO0_BASE + 0x42)
#define SDIO0_CC_DMABCNTLO_ADR    ( SDIO0_BASE + 0x43)

#define SDIO0_CC_DMANUMBHI_ADR    ( SDIO0_BASE + 0x44) //0000_0080
#define SDIO0_CC_DMANUMBLO_ADR    ( SDIO0_BASE + 0x45)
#define SDIO0_CC_DMALENHI_ADR     ( SDIO0_BASE + 0x46)
#define SDIO0_CC_DMALENLO_ADR     ( SDIO0_BASE + 0x47)

#define SDIO0_CC_DMAMSADR_3_ADR   ( SDIO0_BASE + 0x48) //0000_0000
#define SDIO0_CC_DMAMSADR_2_ADR   ( SDIO0_BASE + 0x49)
#define SDIO0_CC_DMAMSADR_1_ADR   ( SDIO0_BASE + 0x4A)
#define SDIO0_CC_DMAMSADR_0_ADR   ( SDIO0_BASE + 0x4B)

#define SDIO0_CC_DMA_BASE_3_ADR   ( SDIO0_BASE + 0x4C) //0000_0000
#define SDIO0_CC_DMA_BASE_2_ADR   ( SDIO0_BASE + 0x4D)
#define SDIO0_CC_DMA_BASE_1_ADR   ( SDIO0_BASE + 0x4E)
#define SDIO0_CC_DMA_BASE_0_ADR   ( SDIO0_BASE + 0x4F)

#define SDIO0_CC_DMA_MASK_3_ADR   ( SDIO0_BASE + 0x50) //0000_0000
#define SDIO0_CC_DMA_MASK_2_ADR   ( SDIO0_BASE + 0x51)
#define SDIO0_CC_DMA_MASK_1_ADR   ( SDIO0_BASE + 0x52)
#define SDIO0_CC_DMA_MASK_0_ADR   ( SDIO0_BASE + 0x53)/*}}}*/

//SDIO1 Register Define/*{{{*/
//#define SDIO1_BASE                0xD0090000
#define SDIO1_CC_CORECTRL_ADR     ( SDIO1_BASE + 0x00) //10d6_8100 
#define SDIO1_CC_CAPABILITY_ADR   ( SDIO1_BASE + 0x01)
#define SDIO1_CC_CORECTRL1_ADR    ( SDIO1_BASE + 0x02)
#define SDIO1_CC_CORESTATE_ADR    ( SDIO1_BASE + 0x03)

#define SDIO1_CC_CMDEVENTS0_ADR   ( SDIO1_BASE + 0x04) //0000_0000
#define SDIO1_CC_DATEVENTS0_ADR   ( SDIO1_BASE + 0x05)
#define SDIO1_CC_CMDEVENTS1_ADR   ( SDIO1_BASE + 0x06)
#define SDIO1_CC_DMAEVENTS_ADR    ( SDIO1_BASE + 0x07)

#define SDIO1_CC_CMDINTMASK0_ADR  ( SDIO1_BASE + 0x08) //0000_0000
#define SDIO1_CC_DATINTMASK0_ADR  ( SDIO1_BASE + 0x09)
#define SDIO1_CC_CMDINTMASK1_ADR  ( SDIO1_BASE + 0x0A)
#define SDIO1_CC_DMAINTMASK_ADR   ( SDIO1_BASE + 0x0B)

#define SDIO1_CC_CMDCTRL_ADR      ( SDIO1_BASE + 0x0C) //003f_0000
#define SDIO1_CC_CMDTRAP_ADR      ( SDIO1_BASE + 0x0D)
#define SDIO1_CC_CMDINDEX_ADR     ( SDIO1_BASE + 0x0E) 
#define SDIO1_CC_CMDCRC7_ADR      ( SDIO1_BASE + 0x0F)

#define SDIO1_CC_ARG_3_ADR        ( SDIO1_BASE + 0x10) //0000_0000
#define SDIO1_CC_ARG_2_ADR        ( SDIO1_BASE + 0x11)
#define SDIO1_CC_ARG_1_ADR        ( SDIO1_BASE + 0x12)
#define SDIO1_CC_ARG_0_ADR        ( SDIO1_BASE + 0x13)

#define SDIO1_CC_RESPCTRL_ADR     ( SDIO1_BASE + 0x14) //1000_0001
//reserved                        ( SDIO1_BASE + 0x15)
#define SDIO1_CC_RESPHDR_ADR      ( SDIO1_BASE + 0x16)
#define SDIO1_CC_RESPCRC7_ADR     ( SDIO1_BASE + 0x17)

#define SDIO1_CC_RESP_3_ADR       ( SDIO1_BASE + 0x18) //0000_0000
#define SDIO1_CC_RESP_2_ADR       ( SDIO1_BASE + 0x19)
#define SDIO1_CC_RESP_1_ADR       ( SDIO1_BASE + 0x1A)
#define SDIO1_CC_RESP_0_ADR       ( SDIO1_BASE + 0x1B)

#define SDIO1_CC_DATCTRL_ADR      ( SDIO1_BASE + 0x1C) //0000_0200
//reserved                        ( SDIO1_BASE + 0x1D)
#define SDIO1_CC_BLKLENHI_ADR     ( SDIO1_BASE + 0x1E)
#define SDIO1_CC_BLKLENLO_ADR     ( SDIO1_BASE + 0x1F)

#define SDIO1_CC_READCTRL_ADR     ( SDIO1_BASE + 0x20) //4100_0000
#define SDIO1_CC_SD_CRC16STT_ADR  ( SDIO1_BASE + 0x21)
//reserved                        ( SDIO1_BASE + 0x22)
//reserved                        ( SDIO1_BASE + 0x23)

#define SDIO1_CC_WRITECTRL_ADR    ( SDIO1_BASE + 0x24) //0100_0000
//reserved                        ( SDIO1_BASE + 0x25)
//reserved                        ( SDIO1_BASE + 0x26)
//reserved                        ( SDIO1_BASE + 0x27)

#define SDIO1_CC_WRFIFO_3_ADR     ( SDIO1_BASE + 0x28) //xxxx_xxxx //out
#define SDIO1_CC_WRFIFO_2_ADR     ( SDIO1_BASE + 0x29) 
#define SDIO1_CC_WRFIFO_1_ADR     ( SDIO1_BASE + 0x2A) 
#define SDIO1_CC_WRFIFO_0_ADR     ( SDIO1_BASE + 0x2B) 

#define SDIO1_CC_RDFIFO_3_ADR     ( SDIO1_BASE + 0x2C) //0000_0000 //in 
#define SDIO1_CC_RDFIFO_2_ADR     ( SDIO1_BASE + 0x2D)
#define SDIO1_CC_RDFIFO_1_ADR     ( SDIO1_BASE + 0x2E)
#define SDIO1_CC_RDFIFO_0_ADR     ( SDIO1_BASE + 0x2F)

//reserved     From 30 to 3F

#define SDIO1_CC_DMACTRL_ADR      ( SDIO1_BASE + 0x40) //0000_0000
#define SDIO1_CC_DMACTRL1_ADR     ( SDIO1_BASE + 0x41)
#define SDIO1_CC_DMABCNTHI_ADR    ( SDIO1_BASE + 0x42)
#define SDIO1_CC_DMABCNTLO_ADR    ( SDIO1_BASE + 0x43)

#define SDIO1_CC_DMANUMBHI_ADR    ( SDIO1_BASE + 0x44) //0000_0080
#define SDIO1_CC_DMANUMBLO_ADR    ( SDIO1_BASE + 0x45)
#define SDIO1_CC_DMALENHI_ADR     ( SDIO1_BASE + 0x46)
#define SDIO1_CC_DMALENLO_ADR     ( SDIO1_BASE + 0x47)

#define SDIO1_CC_DMAMSADR_3_ADR   ( SDIO1_BASE + 0x48) //0000_0000
#define SDIO1_CC_DMAMSADR_2_ADR   ( SDIO1_BASE + 0x49)
#define SDIO1_CC_DMAMSADR_1_ADR   ( SDIO1_BASE + 0x4A)
#define SDIO1_CC_DMAMSADR_0_ADR   ( SDIO1_BASE + 0x4B)

#define SDIO1_CC_DMA_BASE_3_ADR   ( SDIO1_BASE + 0x4C) //0000_0000
#define SDIO1_CC_DMA_BASE_2_ADR   ( SDIO1_BASE + 0x4D)
#define SDIO1_CC_DMA_BASE_1_ADR   ( SDIO1_BASE + 0x4E)
#define SDIO1_CC_DMA_BASE_0_ADR   ( SDIO1_BASE + 0x4F)

#define SDIO1_CC_DMA_MASK_3_ADR   ( SDIO1_BASE + 0x50) //0000_0000
#define SDIO1_CC_DMA_MASK_2_ADR   ( SDIO1_BASE + 0x51)
#define SDIO1_CC_DMA_MASK_1_ADR   ( SDIO1_BASE + 0x52)
#define SDIO1_CC_DMA_MASK_0_ADR   ( SDIO1_BASE + 0x53)/*}}}*/
// -----------------------------------------------------------------------------
// DVP jarre 2008.04.18 dvp +
// -----------------------------------------------------------------------------
#define DVP_CTRL_REG0               *((volatile int *) (DVP_BASE_ADDR + 0x00))
#define DVP_CTRL_REG1               *((volatile int *) (DVP_BASE_ADDR + 0x04))
#define DVP_CTRL_REG2               *((volatile int *) (DVP_BASE_ADDR + 0x08))
#define DVP_INIT_Y_ADDR             *((volatile int *) (DVP_BASE_ADDR + 0x0C))
#define DVP_INIT_U_ADDR             *((volatile int *) (DVP_BASE_ADDR + 0x10))
#define DVP_INIT_V_ADDR             *((volatile int *) (DVP_BASE_ADDR + 0x14))
#define DVP_FINAL_Y_ADDR            *((volatile int *) (DVP_BASE_ADDR + 0x18))
#define DVP_FINAL_U_ADDR            *((volatile int *) (DVP_BASE_ADDR + 0x1C))
#define DVP_FINAL_V_ADDR            *((volatile int *) (DVP_BASE_ADDR + 0x20))
#define DVP_FRAME_OFFSET            *((volatile int *) (DVP_BASE_ADDR + 0x24))
#define DVP_INIT_J_ADDR             *((volatile int *) (DVP_BASE_ADDR + 0x28))
#define DVP_FINAL_J_ADDR            *((volatile int *) (DVP_BASE_ADDR + 0x2C))
#define DVP_STATUS                  *((volatile int *) (DVP_BASE_ADDR + 0x80))
// -----------------------------------------------------------------------------
// JEPG jarre 2008.06.19 jpeg +

#define JPEG_MI_S_ADDR              *((volatile int *) (JPEG_MI_BASE_ADDR + 0x18))
#define JPEG_MI_OS_LEN              *((volatile int *) (JPEG_MI_BASE_ADDR + 0x84))

#define OS_BUF        ((volatile int *)JPEG_OS_BASE_ADDR)

#define DQ_CTRL       ((volatile int *)JPEG_DCTQ_BASE_ADDR)
#define DQ_OPMODE     ((volatile int *)JPEG_DCTQ_BASE_ADDR + 0x01)
//#define DQ_DQP        ((volatile int *)JPEG_DCTQ_BASE_ADDR + 0x02)
#define DQ_CBP_DONE   ((volatile int *)JPEG_DCTQ_BASE_ADDR + 0x14)
#define DQ_LU         ((volatile int *)JPEG_DCTQ_BASE_ADDR + 0x20) //kik+
#define DQ_CH         ((volatile int *)JPEG_DCTQ_BASE_ADDR + 0x21) //kik+
#define DQ_RST        ((volatile int *)JPEG_DCTQ_BASE_ADDR + 0x22) //kik+
/*
#define DQ_OPMODE     ((volatile int *)JPEG_DCTQ_BASE_ADDR + 0x04)
//#define DQ_DQP        ((volatile int *)JPEG_DCTQ_BASE_ADDR + 0x02)
#define DQ_LU         ((volatile int *)JPEG_DCTQ_BASE_ADDR + 0x80) //kik+
#define DQ_CH         ((volatile int *)JPEG_DCTQ_BASE_ADDR + 0x84) //kik+
#define DQ_RST        ((volatile int *)JPEG_DCTQ_BASE_ADDR + 0x88) //kik+
*/

#define TCR0          ((volatile int *)JPEG_TVLC_BASE_ADDR)
#define TCR2          ((volatile int *)JPEG_TVLC_BASE_ADDR +0x16)
/*
#define TCR0          ((volatile int *)JPEG_TVLC_BASE_ADDR)
#define TCR2          ((volatile int *)JPEG_TVLC_BASE_ADDR +0x58)
*/

#define MI_REG0       ((volatile int *)JPEG_MI_BASE_ADDR)
#define MI_REG1       ((volatile int *)JPEG_MI_BASE_ADDR + 0x01)
#define MI_IY_ADDR    ((volatile int *)JPEG_MI_BASE_ADDR + 0x02)
#define MI_IU_ADDR    ((volatile int *)JPEG_MI_BASE_ADDR + 0x03)
#define MI_IV_ADDR    ((volatile int *)JPEG_MI_BASE_ADDR + 0x04)
#define MI_FO         ((volatile int *)JPEG_MI_BASE_ADDR + 0x05)
#define MI_S_ADDR     ((volatile int *)JPEG_MI_BASE_ADDR + 0x06)
#define MI_REG2       ((volatile int *)JPEG_MI_BASE_ADDR + 0x07)
#define MI_STATUS     ((volatile int *)JPEG_MI_BASE_ADDR + 0x20)
#define MI_OS_LEN     ((volatile int *)JPEG_MI_BASE_ADDR + 0x21)
/*
#define MI_REG1       ((volatile int *)JPEG_MI_BASE_ADDR + 0x04)
#define MI_IY_ADDR    ((volatile int *)JPEG_MI_BASE_ADDR + 0x08)
#define MI_IU_ADDR    ((volatile int *)JPEG_MI_BASE_ADDR + 0x0C)
#define MI_IV_ADDR    ((volatile int *)JPEG_MI_BASE_ADDR + 0x10)
#define MI_FO         ((volatile int *)JPEG_MI_BASE_ADDR + 0x14)
#define MI_S_ADDR     ((volatile int *)JPEG_MI_BASE_ADDR + 0x18)
#define MI_STATUS     ((volatile int *)JPEG_MI_BASE_ADDR + 0x80)
#define MI_OS_LEN     ((volatile int *)JPEG_MI_BASE_ADDR + 0x84)
*/
#define JPEG_CTRL_REG0              *((volatile int *) (JPEG_CTRL_BASE_ADDR + 0x00))
#define JPEG_CTRL_REG1              *((volatile int *) (JPEG_CTRL_BASE_ADDR + 0x04))
#define JPEG_CTRL_STATUS            *((volatile int *) (JPEG_CTRL_BASE_ADDR + 0x80))

// ======= SDRAMC  ======= //
// { 1'bMODESET | 2'b0 | 3'bTRCD | 3'bTRAS | 3'bTRP | 4'bTRFC | 12'bTREF | 3'bCL }
#define SDRAMC_CTRL		   *((volatile int*) (SDRAMC_BASE_ADDR + 0x0))
#define SDRAMC_CONFIG		*((volatile int*) (SDRAMC_BASE_ADDR + 0x4))
#define SDRAMC_OPMODE		*((volatile int*) (SDRAMC_BASE_ADDR + 0x8))
#define SDRAMC_TRMODE		*((volatile int*) (SDRAMC_BASE_ADDR + 0xC))

// ======= GPIO  ======= //
#define RGPIO_IN           *((volatile int*) (GPIO_BASE_ADDR + 0x0))
#define RGPIO_OUT          *((volatile int*) (GPIO_BASE_ADDR + 0x4))
#define RGPIO_OE           *((volatile int*) (GPIO_BASE_ADDR + 0x8))
#define RGPIO_INTE         *((volatile int*) (GPIO_BASE_ADDR + 0xc))
#define RGPIO_PTRIG        *((volatile int*) (GPIO_BASE_ADDR + 0x10))
#define RGPIO_AUX          *((volatile int*) (GPIO_BASE_ADDR + 0x14))
#define RGPIO_CTRL         *((volatile int*) (GPIO_BASE_ADDR + 0x18))
#define RGPIO_INTS         *((volatile int*) (GPIO_BASE_ADDR + 0x1c))
#define RGPIO_ECLK         *((volatile int*) (GPIO_BASE_ADDR + 0x20))
#define RGPIO_NEC          *((volatile int*) (GPIO_BASE_ADDR + 0x24))

//////////////////////////////////////////////////////////////////////
// // jarre 2009.07.02 SRAM_IF + vvvvv
// ======= SRAM_IF  ======= // 
#define SRAM_IF_FIFO_FILL_NUM	   *((volatile int*) (SRAM_IF_BASE + 0x0)) // 1 byte
#define SRAM_IF_FIFO_EMPTY_NUM	   *((volatile int*) (SRAM_IF_BASE + 0x4)) // 1 byte
#define SRAM_IF_WRITE_FIFO_CNT	   *((volatile int*) (SRAM_IF_BASE + 0x8)) // 1 byte
#define SRAM_IF_READ_FIFO_CNT	   *((volatile int*) (SRAM_IF_BASE + 0xC)) // 1 byte
#define SRAM_IF_READ_FIFO_ADDR	   *((volatile int*) (SRAM_IF_BASE + 0x00008000))
#define SRAM_IF_SLV_BASE_ADDR	   (SRAM_IF_BASE + 0x0000C000)
// // jarre 2009.07.02 SRAM_IF + ^^^^^
//////////////////////////////////////////////////////////////////////

/////PTC Registers
#define RPTC_CNTR				*((volatile int*) (PTC_BASE_ADDR + 0x0))	
#define RPTC_HRC				*((volatile int*) (PTC_BASE_ADDR + 0x4))	
#define RPTC_LRC				*((volatile int*) (PTC_BASE_ADDR + 0x8))	
#define RPTC_CTRL				*((volatile int*) (PTC_BASE_ADDR + 0xC))	

#endif // __MAP_H__ 
