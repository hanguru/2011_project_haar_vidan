#ifndef _USB_H_
#define _USB_H_

#include "map_hif.h"

#define BCM3549  0
#define BCM3556  1

//////////////////////////////////////////////////////////////////////////////
// USB General
//////////////////////////////////////////////////////////////////////////////

#define SC_GET_STATUS	         	0x00	// Setup command: Get Status
#define SC_CLEAR_FEATURE	      0x01	// Setup command: Clear Feature
#define SC_RESERVED	            0x02	// Setup command: Reserved
#define SC_SET_FEATURE		      0x03	// Setup command: Set Feature
#define SC_SET_ADDRESS		      0x05	// Setup command: Set Address
#define SC_GET_DESCRIPTOR	      0x06	// Setup command: Get Descriptor
#define SC_SET_DESCRIPTOR	      0x07	// Setup command: Set Descriptor
#define SC_GET_CONFIGURATION	  0x08	// Setup command: Get Configuration
#define SC_SET_CONFIGURATION	  0x09	// Setup command: Set Configuration
#define SC_GET_INTERFACE	      0x0a	// Setup command: Get Interface
#define SC_SET_INTERFACE	      0x0b	// Setup command: Set Interface
#define SC_SYNC_FRAME		      	0x0c	// Setup command: Sync Frame
#define SC_ANCHOR_LOAD		      0xa0	// Setup command: Anchor load


#define GD_DEVICE		         		0x01	// Get device descriptor: Device
#define GD_CONFIGURATION	      0x02	// Get device descriptor: Configuration
#define GD_STRING	            	0x03	// Get device descriptor: String
#define GD_INTERFACE            0x04
#define GD_ENDPOINT             0x05
#define GD_OTGDESCRIPTOR        0x09
#define USB_MSC_CLASS           0x08
#define USB_HUB_CLASS           0x09
#define USB_BOT_INTF            0x50
#define USB_SCSI_SUBCLASS       0x06

#define GD_DEVICE_QUALIFIER	   	0x06	// Get device descriptor: Qualifier
#define GD_OTHER_SPEED		     	0x07	// Get device descriptor: Other speed

#define GD_REPORT		         		0x22	// Get device descriptor: String

#define GS_DEVICE		         		0x80	// Get Status: Device
#define GS_INTERFACE	         	0x81	// Get Status: Interface
#define GS_ENDPOINT		         	0x82	// Get Status: End Point

#define FT_DEVICE		         		0x00	// Feature: Device
#define FT_ENDPOINT		         	0x02	// Feature: End Point
#define FT_B_HNP_ENABLE					0x03
#define FT_A_HNP_ENABLE					0x04
#define FT_A_ALT_HNP_ENABLE			0x05



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

//CSR Bit Define
#define USB_CSR_BASE_ADDR_BIT							17
#define USB_CSR_DISABLE_HS_BIT						15
#define USB_CSR_PHY_SUSPEND_BIT						14
#define USB_CSR_MCU_RESUME_REQ_BIT				12
#define USB_CSR_TD_EXEC_INTERVAL_BIT			10
#define USB_CSR_ENABLE_CORE_BIT						7
#define USB_CSR_FS_IDLE_DETECTED_BIT			6
#define USB_CSR_SE0_DETECTED_BIT					5
#define USB_CSR_INTERFACE_STATUS_BIT			2
#define USB_CSR_INTERFACE_SPEED_BIT				1
#define USB_CSR_ENTERED_SUSPEND_BIT				0

#define USB_CSR_BASE_ADDR_MSK							( 0xfffe0000 )
#define USB_CSR_DISABLE_HS								( 1 << USB_CSR_DISABLE_HS_BIT )
#define USB_CSR_ENABLE_CORE								( 1 << USB_CSR_ENABLE_CORE_BIT )
#define USB_CSR_TD_EXEC_INTERVAL_STOPPED_VALUE			0x00
#define USB_CSR_TD_EXEC_INTERVAL_025_VALUE				0x01
#define USB_CSR_TD_EXEC_INTERVAL_050_VALUE				0x10
#define USB_CSR_TD_EXEC_INTERVAL_100_VALUE				0x11
#define USB_CSR_TD_EXEC_INTERVAL_STOPPED			(USB_CSR_TD_EXEC_INTERVAL_STOPPED_VALUE <<  USB_CSR_TD_EXEC_INTERVAL_BIT)
#define USB_CSR_TD_EXEC_INTERVAL_025				(USB_CSR_TD_EXEC_INTERVAL_025_VALUE	    <<  USB_CSR_TD_EXEC_INTERVAL_BIT)
#define USB_CSR_TD_EXEC_INTERVAL_050				(USB_CSR_TD_EXEC_INTERVAL_050_VALUE	    <<  USB_CSR_TD_EXEC_INTERVAL_BIT)
#define USB_CSR_TD_EXEC_INTERVAL_100				(USB_CSR_TD_EXEC_INTERVAL_100_VALUE	    <<  USB_CSR_TD_EXEC_INTERVAL_BIT)

//INT_MSK define
#define USB_INT_MSK_EN_FSDISC_DETECT  (1 << 11)
#define USB_INT_MSK_EN_SE0_DETECT     (1 << 10
#define USB_INT_MSK_EN_IDLE_DETECT    (1 << 9)
#define USB_INT_MSK_EN_USBRESET       (1 << 8)
#define USB_INT_MSK_EN_RXERROR        (1 << 7)
#define USB_INT_MSK_EN_DETACHED       (1 << 6)
#define USB_INT_MSK_EN_ATTACHED       (1 << 5)
#define USB_INT_MSK_EN_RESUME         (1 << 4)
#define USB_INT_MSK_EN_SUSPEND        (1 << 3)
#define USB_INT_MSK_EN_NO_EP_ERROR    (1 << 2)
#define USB_INT_MSK_EN_PID_ERROR      (1 << 1)
#define USB_INT_MSK_EN_BAD_TOKEN      (1 << 0)
#define USB_INT_MSK_ENABLE_A_BASE_BIT	0
#define USB_INT_MSK_ENABLE_B_BASE_BIT	16


//INT_SRC define
#define USB_INT_SRC_SE0_DETECT_BIT				30
#define USB_INT_SRC_IDLE_DETECT_BIT				29
#define USB_INT_SRC_USB_RESET_BIT					28
#define USB_INT_SRC_UTMI_RX_ERR_BIT				27
#define USB_INT_SRC_DETACHED_BIT					26
#define USB_INT_SRC_ATTACHED_BIT					25
#define USB_INT_SRC_RESUME_BIT						24
#define USB_INT_SRC_SUSPEND_BIT						23
#define USB_INT_SRC_NO_SUCH_EP_BIT				22
#define USB_INT_SRC_PID_ERR_BIT						21
#define USB_INT_SRC_BAD_TOKEN_BIT					20
#define USB_INT_SRC_EP15_BIT							15
#define USB_INT_SRC_EP14_BIT							14
#define USB_INT_SRC_EP13_BIT							13
#define USB_INT_SRC_EP12_BIT							12
#define USB_INT_SRC_EP11_BIT							11
#define USB_INT_SRC_EP10_BIT							10
#define USB_INT_SRC_EP9_BIT								9
#define USB_INT_SRC_EP8_BIT								8
#define USB_INT_SRC_EP7_BIT								7
#define USB_INT_SRC_EP6_BIT								6
#define USB_INT_SRC_EP5_BIT								5
#define USB_INT_SRC_EP4_BIT								4
#define USB_INT_SRC_EP3_BIT								3
#define USB_INT_SRC_EP2_BIT								2
#define USB_INT_SRC_EP1_BIT								1
#define USB_INT_SRC_EP0_BIT								0

#define USB_INT_SRC_SE0_DETECT				 	( 1 << USB_INT_SRC_SE0_DETECT_BIT 	)
#define USB_INT_SRC_IDLE_DETECT					( 1 << USB_INT_SRC_IDLE_DETECT_BIT	)
#define USB_INT_SRC_USB_RESET						( 1 << USB_INT_SRC_USB_RESET_BIT		)
#define USB_INT_SRC_UTMI_RX_ERR					( 1 << USB_INT_SRC_UTMI_RX_ERR_BIT	)
#define USB_INT_SRC_DETACHED						( 1 << USB_INT_SRC_DETACHED_BIT			)
#define USB_INT_SRC_ATTACHED						( 1 << USB_INT_SRC_ATTACHED_BIT			)
#define USB_INT_SRC_RESUME							( 1 << USB_INT_SRC_RESUME_BIT				)
#define USB_INT_SRC_SUSPEND							( 1 << USB_INT_SRC_SUSPEND_BIT			)
#define USB_INT_SRC_NO_SUCH_EP					( 1 << USB_INT_SRC_NO_SUCH_EP_BIT		)
#define USB_INT_SRC_PID_ERR							( 1 << USB_INT_SRC_PID_ERR_BIT			)
#define USB_INT_SRC_BAD_TOKEN						( 1 << USB_INT_SRC_BAD_TOKEN_BIT		)
#define USB_INT_SRC_EP15								( 1 << USB_INT_SRC_EP15_BIT					)
#define USB_INT_SRC_EP14								( 1 << USB_INT_SRC_EP14_BIT					)
#define USB_INT_SRC_EP13								( 1 << USB_INT_SRC_EP13_BIT					)
#define USB_INT_SRC_EP12								( 1 << USB_INT_SRC_EP12_BIT					)
#define USB_INT_SRC_EP11								( 1 << USB_INT_SRC_EP11_BIT					)
#define USB_INT_SRC_EP10								( 1 << USB_INT_SRC_EP10_BIT					)
#define USB_INT_SRC_EP9									( 1 << USB_INT_SRC_EP9_BIT					)
#define USB_INT_SRC_EP8									( 1 << USB_INT_SRC_EP8_BIT					)
#define USB_INT_SRC_EP7									( 1 << USB_INT_SRC_EP7_BIT					)
#define USB_INT_SRC_EP6									( 1 << USB_INT_SRC_EP6_BIT					)
#define USB_INT_SRC_EP5									( 1 << USB_INT_SRC_EP5_BIT					)
#define USB_INT_SRC_EP4									( 1 << USB_INT_SRC_EP4_BIT					)
#define USB_INT_SRC_EP3									( 1 << USB_INT_SRC_EP3_BIT					)
#define USB_INT_SRC_EP2									( 1 << USB_INT_SRC_EP2_BIT					)
#define USB_INT_SRC_EP1									( 1 << USB_INT_SRC_EP1_BIT					)
#define USB_INT_SRC_EP0									( 1 << USB_INT_SRC_EP0_BIT					)


//EP_CSR bit define
#define USB_EP_CSR_UC_DPD_BIT							28
#define USB_EP_CSR_EP_TYPE_BIT						26
#define USB_EP_CSR_TR_TYPE_BIT						24
#define USB_EP_CSR_EP_DIS_BIT							22
#define USB_EP_CSR_EP_NO_BIT							18
#define USB_EP_CSR_EP_NACK_BIT						17
#define USB_EP_CSR_EP_AUTO_NACK_BIT				16
#define USB_EP_CSR_ZERO_LEN_DISABLE_BIT		13
#define USB_EP_CSR_TR_FR_BIT							11
#define USB_EP_CSR_MAX_PL_SZ_BIT					0

#define USB_EP_CSR_UC_DPD_NO_MODIFICATION_VALUE	0x0
#define USB_EP_CSR_UC_DPD_CLEARED_DATA0_VALUE		0x1
#define USB_EP_CSR_UC_DPD_INCREMENTED_VALUE			0x2
#define USB_EP_CSR_UC_DPD_CLEARED_DATA1_VALUE		0x3

#define USB_EP_CSR_EP_TYPE_CTRL_VALUE						0x0
#define USB_EP_CSR_EP_TYPE_IN_VALUE							0x1
#define USB_EP_CSR_EP_TYPE_OUT_VALUE						0x2

#define USB_EP_CSR_TR_TYPE_INT_VALUE						0x0
#define USB_EP_CSR_TR_TYPE_ISO_VALUE						0x1
#define USB_EP_CSR_TR_TYPE_BULK_VALUE						0x2

#define USB_EP_CSR_EP_DIS_NORMAL_VALUE					0x0
#define USB_EP_CSR_EP_DIS_IGNORE_VALUE					0x1
#define USB_EP_CSR_EP_DIS_HALT_VALUE						0x2
#define USB_EP_CSR_EP_DIS_BUSY_VALUE						0x3


#define USB_EP_CSR_UC_DPD_NO_MODIFICATION	( USB_EP_CSR_UC_DPD_NO_MODIFICATION_VALUE	<< USB_EP_CSR_UC_DPD_BIT )
#define USB_EP_CSR_UC_DPD_CLEARED_DATA0		( USB_EP_CSR_UC_DPD_CLEARED_DATA0_VALUE 	<< USB_EP_CSR_UC_DPD_BIT )
#define USB_EP_CSR_UC_DPD_INCREMENTED			( USB_EP_CSR_UC_DPD_INCREMENTED_VALUE 		<< USB_EP_CSR_UC_DPD_BIT )
#define USB_EP_CSR_UC_DPD_CLEARED_DATA1		( USB_EP_CSR_UC_DPD_CLEARED_DATA1_VALUE 	<< USB_EP_CSR_UC_DPD_BIT )

#define USB_EP_CSR_EP_TYPE_CTRL						( USB_EP_CSR_EP_TYPE_CTRL_VALUE << USB_EP_CSR_EP_TYPE_BIT )
#define USB_EP_CSR_EP_TYPE_IN							( USB_EP_CSR_EP_TYPE_IN_VALUE 	<< USB_EP_CSR_EP_TYPE_BIT )
#define USB_EP_CSR_EP_TYPE_OUT							( USB_EP_CSR_EP_TYPE_OUT_VALUE 	<< USB_EP_CSR_EP_TYPE_BIT )

#define USB_EP_CSR_TR_TYPE_INT			  			( USB_EP_CSR_TR_TYPE_INT_VALUE 	<< USB_EP_CSR_TR_TYPE_BIT )      			
#define USB_EP_CSR_TR_TYPE_ISO							( USB_EP_CSR_TR_TYPE_ISO_VALUE 	<< USB_EP_CSR_TR_TYPE_BIT )	
#define USB_EP_CSR_TR_TYPE_BULK						( USB_EP_CSR_TR_TYPE_BULK_VALUE << USB_EP_CSR_TR_TYPE_BIT )

#define USB_EP_CSR_EP_DIS_NORMAL						( USB_EP_CSR_EP_DIS_NORMAL_VALUE << USB_EP_CSR_EP_DIS_BIT )
#define USB_EP_CSR_EP_DIS_IGNORE						( USB_EP_CSR_EP_DIS_IGNORE_VALUE << USB_EP_CSR_EP_DIS_BIT )
#define USB_EP_CSR_EP_DIS_HALT							( USB_EP_CSR_EP_DIS_HALT_VALUE	 << USB_EP_CSR_EP_DIS_BIT )
#define USB_EP_CSR_EP_DIS_BUSY							( USB_EP_CSR_EP_DIS_BUSY_VALUE	 << USB_EP_CSR_EP_DIS_BIT )


#define USB_EP_CSR_EP_NACK_RESET						( 0	 << USB_EP_CSR_EP_NACK_BIT )
#define USB_EP_CSR_EP_NACK_SET							( 1	 << USB_EP_CSR_EP_NACK_BIT )
#define USB_EP_CSR_EP_AUTO_NACK_RESET				( 0	 << USB_EP_CSR_EP_AUTO_NACK_BIT )
#define USB_EP_CSR_EP_AUTO_NACK_SET					( 1	 << USB_EP_CSR_EP_AUTO_NACK_BIT )


#define USB_EP_CSR_ZERO_LEN_DISABLE_RESET				( 0	 << USB_EP_CSR_ZERO_LEN_DISABLE_BIT )
#define USB_EP_CSR_ZERO_LEN_DISABLE_SET					( 1	 << USB_EP_CSR_ZERO_LEN_DISABLE_BIT )

//EP_INT
#define USB_EP_INT_TIMEOUT_BIT                0
#define USB_EP_INT_BADPACKET_BIT              1
#define USB_EP_INT_RX_CONTROL_PKT_BIT         2
#define USB_EP_INT_BUFFER_FULL_BIT            3
#define USB_EP_INT_BUFFER_EMPTY_BIT           4
#define USB_EP_INT_PID_SEQUENCE_ERROR_BIT     5
#define USB_EP_INT_RX_TOO_LARGE_BIT           6
#define USB_EP_INT_IN_FIFO_EMPTYON_READ_BIT   7
#define USB_EP_INT_OUT_FIFO_FULLON_WRITE_BIT  8
#define USB_EP_INT_RX_DATA_PKT_BIT            9
#define USB_EP_INT_TX_DATA_PKT_BIT            10
#define USB_EP_INT_ENABLE_B_BASE_BIT          11
#define USB_EP_INT_ENABLE_A_BASE_BIT          20

#define USB_EP_INT_TIMEOUT               (1 << USB_EP_INT_TIMEOUT_BIT              )
#define USB_EP_INT_BADPACKET             (1 << USB_EP_INT_BADPACKET_BIT            )
#define USB_EP_INT_RX_CONTROL_PKT        (1 << USB_EP_INT_RX_CONTROL_PKT_BIT       )
#define USB_EP_INT_BUFFER_FULL           (1 << USB_EP_INT_BUFFER_FULL_BIT          )
#define USB_EP_INT_BUFFER_EMPTY          (1 << USB_EP_INT_BUFFER_EMPTY_BIT         )
#define USB_EP_INT_PID_SEQUENCE_ERROR    (1 << USB_EP_INT_PID_SEQUENCE_ERROR_BIT   )
#define USB_EP_INT_RX_TOO_LARGE          (1 << USB_EP_INT_RX_TOO_LARGE_BIT         )
#define USB_EP_INT_IN_FIFO_EMPTYON_READ  (1 << USB_EP_INT_IN_FIFO_EMPTYON_READ_BIT )
#define USB_EP_INT_OUT_FIFO_FULLON_WRITE (1 << USB_EP_INT_OUT_FIFO_FULLON_WRITE_BIT)
#define USB_EP_INT_RX_DATA_PKT           (1 << USB_EP_INT_RX_DATA_PKT_BIT          )
#define USB_EP_INT_TX_DATA_PKT           (1 << USB_EP_INT_TX_DATA_PKT_BIT          )

#define USB_EP_INT_ALL_INTS 		( USB_EP_INT_TIMEOUT               	   \
										| USB_EP_INT_BADPACKET             \
										| USB_EP_INT_RX_CONTROL_PKT        \
										| USB_EP_INT_BUFFER_FULL           \
										| USB_EP_INT_BUFFER_EMPTY          \
										| USB_EP_INT_PID_SEQUENCE_ERROR    \
										| USB_EP_INT_RX_TOO_LARGE          \
										| USB_EP_INT_IN_FIFO_EMPTYON_READ  \
										| USB_EP_INT_OUT_FIFO_FULLON_WRITE \
										| USB_EP_INT_RX_DATA_PKT           \
										| USB_EP_INT_TX_DATA_PKT	       \
									)



//EP_OBA/IBA
#define USB_EP_MAX_BUFFER_SIZE	16320
#define USB_EP_MAX_PACKET_SIZE	64
#define USB_EP_BUF_SZ_BIT    	17
#define USB_EP_BUF_PTR_MSK    ( 0x0001ffff )
#define USB_EP_BUF_SZ_MSK    ( 0xfffe0000 )


//EP Setting
#define EP_BASE_ADDR											0xf1000000
#define USB_CSR_BASE_ADDR									( EP_BASE_ADDR & USB_CSR_BASE_ADDR_MSK )

//ep0
#define EP0_NO_VALUE								0x0
#define EP0_TR_FR_VALUE							0x0
#define EP0_BUF_SIZE								0x40
#define EP0_IN_BUF_ADDR							( EP_BASE_ADDR )
#define EP0_OUT_BUF_ADDR						( EP0_IN_BUF_ADDR + EP0_BUF_SIZE )
#define EP0_EP_NO									 	( EP0_NO_VALUE << USB_EP_CSR_EP_NO_BIT )
#define EP0_TR_FR									 	( EP0_TR_FR_VALUE << USB_EP_CSR_TR_FR_BIT )
#define EP0_MAX_PL_SZ								( EP0_BUF_SIZE << USB_EP_CSR_MAX_PL_SZ_BIT )

//ep1
#define EP1_NO_VALUE								0x1
#define EP1_TR_FR_VALUE							0x0
#define EP1_BUF_SIZE								0x40
#define EP1_BUF_ADDR								( EP0_OUT_BUF_ADDR 	+ EP0_BUF_SIZE )
#define EP1_EP_NO									 	( EP1_NO_VALUE << USB_EP_CSR_EP_NO_BIT )
#define EP1_TR_FR									 	( EP1_TR_FR_VALUE << USB_EP_CSR_TR_FR_BIT )
#define EP1_MAX_PL_SZ								( EP1_BUF_SIZE << USB_EP_CSR_MAX_PL_SZ_BIT )

//ep2
#define EP2_NO_VALUE								0x2
#define EP2_TR_FR_VALUE							0x0
#define EP2_BUF_SIZE								0x40
#define EP2_BUF_ADDR								( EP1_BUF_ADDR 			+ EP1_BUF_SIZE )
#define EP2_EP_NO									 	( EP2_NO_VALUE << USB_EP_CSR_EP_NO_BIT )
#define EP2_TR_FR									 	( EP2_TR_FR_VALUE << USB_EP_CSR_TR_FR_BIT )
#define EP2_MAX_PL_SZ								( EP2_BUF_SIZE << USB_EP_CSR_MAX_PL_SZ_BIT )

//ep3
#define EP3_NO_VALUE								0x3
#define EP3_TR_FR_VALUE							0x0
#if BCM3549
#define EP3_BUF_SIZE								0x40
#endif
#if BCM3556
#define EP3_BUF_SIZE								0x10
#endif
#define EP3_BUF_ADDR								( EP2_BUF_ADDR 			+ EP2_BUF_SIZE )
#define EP3_EP_NO									 	( EP3_NO_VALUE << USB_EP_CSR_EP_NO_BIT )
#define EP3_TR_FR									 	( EP3_TR_FR_VALUE << USB_EP_CSR_TR_FR_BIT )
#define EP3_MAX_PL_SZ								( EP3_BUF_SIZE << USB_EP_CSR_MAX_PL_SZ_BIT )

//ep4
#define EP4_NO_VALUE								0x4
#define EP4_TR_FR_VALUE							0x0
#if BCM3549
#define EP4_BUF_SIZE								0x40
#endif
#if BCM3556
#define EP4_BUF_SIZE								0x10
#endif
#define EP4_BUF_ADDR								( EP3_BUF_ADDR 			+ EP3_BUF_SIZE )
#define EP4_EP_NO									 	( EP4_NO_VALUE << USB_EP_CSR_EP_NO_BIT )
#define EP4_TR_FR									 	( EP4_TR_FR_VALUE << USB_EP_CSR_TR_FR_BIT )
#define EP4_MAX_PL_SZ								( EP4_BUF_SIZE << USB_EP_CSR_MAX_PL_SZ_BIT )

//ep5
#define EP5_NO_VALUE								0x5
#define EP5_TR_FR_VALUE							0x0
#if BCM3549
#define EP5_BUF_SIZE								0x40
#endif
#if BCM3556
#define EP5_BUF_SIZE								0x10
#endif
#define EP5_BUF_ADDR								( EP4_BUF_ADDR 			+ EP4_BUF_SIZE )
#define EP5_EP_NO									 	( EP5_NO_VALUE << USB_EP_CSR_EP_NO_BIT )
#define EP5_TR_FR									 	( EP5_TR_FR_VALUE << USB_EP_CSR_TR_FR_BIT )
#define EP5_MAX_PL_SZ								( EP5_BUF_SIZE << USB_EP_CSR_MAX_PL_SZ_BIT )


//#define BULK_MAXPACKET_LENGTH  0x200
#define BULK_MAXPACKET_LENGTH  0x10

typedef struct  {
  int   num;
  int   enabled;
  int   type;
  int   maxpacketsize;
  int   pid;
  int		dir;
} EndpointDescriptorObj;

typedef struct {
  int   Class;
  int   SubClass;
  int   Protocol;
} IntfDescriptorObj;

typedef enum {
  MSD_BOT,
  MSD_CBI
} MsdDeviceType;

typedef enum {
  DISCONNECTED,
  FS_CONNECT,
  HS_CONNECT,
  LS_CONNECT,
  SUSPENDED,
  RESUMING
} UsbConnectionType;

typedef struct  {
  int VID;
  int PID;
  int DevClass;
  IntfDescriptorObj Intf;
  int Address;
  int NumEp;
  int enumerated;
  int resume_complete;
  int suspended;
  int configured;
  int OtgSupport;
  int InterfaceType;
  EndpointDescriptorObj EP0;
  EndpointDescriptorObj EPIIn;
  EndpointDescriptorObj EPBIn;
  EndpointDescriptorObj EPBOut;
  EndpointDescriptorObj * EPcsw;
  UsbConnectionType connection;
  MsdDeviceType  MsdType;
} tUsbHostObj;

typedef enum {
  DEFAULT,
  B_IDLE,
  B_SRP_INIT,
  B_PERIPHERAL,
  B_WAIT_ACON,
  B_HOST,
  A_IDLE,
  A_WAIT_VRISE,
  A_WAIT_BCON,
  A_HOST,
  A_HOST_REG,
  A_SUSPEND,
  A_RESUME,
  A_PERIPHERAL,
  A_WAIT_VFALL,
  A_VBUS_ERR
} tOtgStateType;

typedef enum {
  DEV_UNCONFIGURED,
  DEV_ADDRESSED,
  DEV_CONFIGURED,
  DEV_SUSPENDED,
  DEV_RESUME,
  HST_UNCONNECTED,
  HST_CONNECTED
} tUsbStateType;

typedef struct {
  int SrpSupport;
  int HnpSupport;
  int hnp_enabled;
  int b_hnp_enable;
  int a_hnp_support;
  int a_alt_hnp_support;
} tOtgInfoObj;

typedef struct {
  int            set_halt;
  int            Device_Config_Value;
  int            ep0_max_pl;
  int            max_pl;
  int            set_remote_wakeup;
} tUsbDeviceObj;

typedef struct {
  tUsbStateType     DeviceState;
  tOtgStateType     MainState;
  int               otg_support;
  int               is_host;
  int               RegularHost;
  int								gpout_shadow;
  unsigned int						rxBuffer;
  unsigned int						txBuffer;
  tOtgInfoObj       OtgConfig;
  tUsbHostObj       Host;
  tUsbDeviceObj     Dev;
} tUsbSystemObj;

extern tUsbSystemObj SystemInfo;



//Function Call
int init_usb(void);
void usb_interrupt_handler(void);

void ep0_nack_toggle(void);
void ep1_nack_toggle(void);
void ep2_nack_toggle(void);
void ep3_nack_toggle(void);
void ep4_nack_toggle(void);
void ep5_nack_toggle(void);
void ep2_nack(void);
void ep3_nack(void);
void ep4_nack(void);
void ep5_nack(void);

void ms50_delay();
void ms10_delay();
//#define USB_SET_DELAY

void wdt_interrupt_handler(void);

void init_video_streamBuf(void);
void init_audio_streamBuf(void);

#endif

