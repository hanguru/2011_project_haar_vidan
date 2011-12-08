#include <string.h>
#include "usb.h"
#include "uart.h"
#include "i2s.h"
#include "interrupt_handler.h"
#include "commandProcess.h"

///Descriptors // {{{
//#define DEVICE_DESCRIPTOR_LENGTH 18
#define DEVICE_DESCRIPTOR_LENGTH 18
//unsigned char sDeviceDescriptor[] = {
//  18,
//  0x01,  //BYTE bDescriptorType
//  0x00,  //WORD bcdUSB
//  0x02,  //
//  0x00,  //Byte bDeviceClass
//  0x00,  //BYTE bDeviceSubClass
//  0x00,  //BYTE bDeviceProtocol
//  0x40,  //BYTE bMaxPacketSize of 64
//  0xb4,
//  0x04,
//  0x0c,  //WORD idProduct
//  0x10,  //
//  0x00,  //WORD bcdDevice
//  0x00,  //
//  0x01,  //BYTE iManufacturer
//  0x02,  //BYTE iProduct
//  0x00,  //BYTE iSerialNumber
//  0x01   //BYTE bNumConfigurations
//};

unsigned int sDeviceDescriptor[] = {
	0x02000112,
	0x40000000,
	//0x700115B8,
	0x30012232,
	0x02010100, //Version Info 1.00
	0x00000103,
};

#define len_sConfigDescriptor 53

//unsigned char sConfigDescriptor[] = {
//  // CONFIG
//  0x09, //BYTE bLength
//  0x02, //BYTE bDescriptorType //Assigned by USB
//  60, //BYTE wTotalLength                          //sizeof( struct CONFIG),
//  0x00, //BYTE wZero, always 00
//  0x01, //BYTE bNumInterfaces
//  0x01, //BYTE bConfigurationValue
//  0x00, //BYTE iConfiguration
//  0x80, //BYTE bmAttributes, Bus powered and !remote wakeup
//  50, //BYTE MaxPower
//  // INTERFACE
//  0x09, //BYTE bLength
//  0x04, //BYTE bDescriptionType, assigned by USB
//  0x00, //BYTE bInterfaceNumber
//  0x00, //BYTE bAlternateSetting
//  0x06, //BYTE bNumEndpoints, uses 2 endpoints
//  0xff, //BYTE bInterfaceClass, mass storage - 0x08
//  0x00, //BYTE bInterfaceSubClass, SCSI commands
//  0x00, //BYTE bInterfaceProtocol, BULK only
//  0x00, //BYTE iInterface
//
//  // ENDPOINT 1 IN
//  //                 sizeof(struct ENDPOINT),
//  0x07, //BYTE bLength
//  0x05, //BYTE bDescriptorType, assigned by USB
//  0x81, //BYTE bEndpointAddress, IN endpoint, endpoint 1
//  0x02, //BYTE bmAttributes
//  0x00, //WORD wMaxPacketSize
//  0x02, //
//  0x00, //Polling Time
//     
//  // ENDPOINT 2 OUT
//  //                 sizeof(struct ENDPOINT),
//  0x07, //BYTE bLength
//  0x05, //BYTE bDescriptorType, assigned by USB
//  0x02, //BYTE bEndpointAddress, IN endpoint, endpoint 2
//  0x02, //BYTE bmAttributes
//  0x00, //WORD wMaxPacketSize
//  0x02, //
//  0x00, //Polling Time
//
//  // ENDPOINT 3 OUT
//  //                 sizeof(struct ENDPOINT),
//  0x07, //BYTE bLength
//  0x05, //BYTE bDescriptorType, assigned by USB
//  0x03, //BYTE bEndpointAddress, IN endpoint, endpoint 2
//  0x02, //BYTE bmAttributes
//  0x00, //WORD wMaxPacketSize
//  0x02, //
//  0x00, //Polling Time
//
//  // ENDPOINT 4 OUT
//  //                 sizeof(struct ENDPOINT),
//  0x07, //BYTE bLength
//  0x05, //BYTE bDescriptorType, assigned by USB
//  0x04, //BYTE bEndpointAddress, IN endpoint, endpoint 2
//  0x02, //BYTE bmAttributes
//  0x00, //WORD wMaxPacketSize
//  0x02, //
//  0x00, //Polling Time
//
//  // ENDPOINT 5 OUT
//  //                 sizeof(struct ENDPOINT),
//  0x07, //BYTE bLength
//  0x05, //BYTE bDescriptorType, assigned by USB
//  0x05, //BYTE bEndpointAddress, IN endpoint, endpoint 2
//  0x02, //BYTE bmAttributes
//  0x00, //WORD wMaxPacketSize
//  0x02, //
//  0x00, //Polling Time
//
//  // ENDPOINT 6 OUT
//  //                 sizeof(struct ENDPOINT),
//  0x07, //BYTE bLength
//  0x05, //BYTE bDescriptorType, assigned by USB
//  0x06, //BYTE bEndpointAddress, IN endpoint, endpoint 2
//  0x02, //BYTE bmAttributes
//  0x00, //WORD wMaxPacketSize
//  0x02, //
//  0x00 //Polling Time
//};

#if BCM3549 // Off
//////////////////////////////
// Software Initialization
//////////////////////////////
unsigned int sConfigDescriptor[] = {
//{{{
  //0x09, 
  //0x02, 
  //0x35,
  //0x00, 
  0x00350209,
  //0x01, 
  //0x01, 
  //0x00, 
  //0x80, 
  0x80000101,
  //0x32,
  //0x09, 
  //0x04, 
  //0x00, 
  0x000409C8, //400mA
  //0x00, 
  //0x06, 
  //0xff, 
  //0x00, 
  0x00ff0500,
  //0x00, 
  //0x00, 
  //0x07, 
  //0x05, 
  0x05070000,
  //0x81, 
  //0x02, 
  //0x40, 
  //0x00, 
  0x00400281,
  //0x00, 
  //0x07, 
  //0x05, 
  //0x02, 
  0x02050700,
  //0x02, 
  //0x10, 
  //0x00, 
  //0x00, 
  0x00004002,
  //0x07, 
  //0x05, 
  //0x83, 
  //0x02, 
  0x02830507,
  //0x10, 
  //0x00, 
  //0x00, 
  //0x07, 
  0x07000040,
  //0x05, 
  //0x84, 
  //0x02, 
  //0x10, 
  0x40028405,
  //0x00, 
  //0x00, 
  //0x07, 
  //0x05, 
  0x05070000,
  //0x85, 
  //0x02, 
  //0x10, 
  //0x00, 
  0x00400285,
  //0x00, 
  //0x07, 
  //0x05, 
  //0x06, 
  0x00000000,
//}}}
};
#endif

#if BCM3556 // On
unsigned int sConfigDescriptor[] = {
//{{{
  //0x09, 
  //0x02, 
  //0x35,
  //0x00, 
  0x00350209,
  //0x01, 
  //0x01, 
  //0x00, 
  //0x80, 
  0x80000101,
  //0x32,
  //0x09, 
  //0x04, 
  //0x00, 
  0x000409C8, //400mA
  //0x00, 
  //0x06, 
  //0xff, 
  //0x00, 
  0x00ff0500,
  //0x00, 
  //0x00, 
  //0x07, 
  //0x05, 
  0x05070000,
  //0x81, 
  //0x02, 
  //0x40, 
  //0x00, 
  0x00400281,
  //0x00, 
  //0x07, 
  //0x05, 
  //0x02, 
  0x02050700,
  //0x02, 
  //0x10, 
  //0x00, 
  //0x00, 
  0x00004002,
  //0x07, 
  //0x05, 
  //0x83, 
  //0x02, 
  0x02830507,
  //0x10, 
  //0x00, 
  //0x00, 
  //0x07, 
  0x07000010,
  //0x05, 
  //0x84, 
  //0x02, 
  //0x10, 
  0x10028405,
  //0x00, 
  //0x00, 
  //0x07, 
  //0x05, 
  0x05070000,
  //0x85, 
  //0x02, 
  //0x10, 
  //0x00, 
  0x00100285,
  //0x00, 
  //0x07, 
  //0x05, 
  //0x06, 
  0x00000000,
//}}}
};
#endif


#define len_sQualifier 10

unsigned int sQualifier[] = {
//{{{
	0x0200060a,
	0x40000000,
	0x00000001,
//}}}
};


//String
//Xuint8 sString0[] = {
//  0x04, 0x03,
//  0x09, 0x04, 
//};
unsigned int sString0 = 0x04090304;

//N[0x4e]a[0x61]m[0x6d]u[0x75]g[0x67]a[0x61] [0x20]I[0x49]n[0x6e]c[0x63].[0x2e] //Namuga Inx

//Namuga Multimedia Lab.
//4e 61 6d 75 67 61 20 4d 75 6c 74 69 6d 65 64 69 61 20 4c 61 62 2e
// ASCII code
unsigned int sString1[] = {
//{{{
	0x004e032e,
	0x006d0061, 
	0x00670075,
	0x00200061,
	0x0075004d,
	0x0074006c,
	0x006d0069,
	0x00640065,
	0x00610069,
	0x004c0020,
	0x00620061,
	0x0000002e,
//}}}
};

//ViDAN4110-USBDevice
//56 69 44  ...   
//LG DTV Skype Device(ViDAN4110)
//4c 47 20 44 54 56 20 53 6b 79 70 65 20 44 65 76 69 63 65 28 56 69 44 41 4e 34 31 31 30 29
// ASCII code
unsigned int sString2[] = {
//{{{
 	0x004c033e,
	0x00200047,
	0x00540044,
	0x00200056,
	0x006b0053,
	0x00700079,
	0x00200065,
	0x00650044,
	0x00690076,
	0x00650063,
	0x00560028,
	0x00440069,
	0x004e0041,
	0x00310034,
	0x00300031,
	0x00000029,
//}}}
};

//NCA-207F-VIDAN4110
//4e 43 41 2d 32 30 37 46 
// ASCII code
unsigned int sString3[] = {
//{{{
	0x004e0312,
	0x00410043,
	0x0032002d,
	0x00370030,
	0x00000046
//}}}
};


// }}}

//Variable
int get_status_from_host = 0;
tUsbSystemObj       SystemInfo;

OS_EVENT *pH264StreamSem;
OS_EVENT *pJPEGStreamSem;
OS_EVENT *pPCMINStreamSem;

extern volatile int isVideoStarted;
extern volatile int isJpegDataExist;

volatile int isH264Pend = 0;
volatile int isJPEGPend = 0;

//Function
void ep_clear_dpid(void);
void clr_stall_endpoint(int ep_num);

void process_ep0(void);
void process_ep1(void);
void process_ep2(void);
void process_ep3(void);
void process_ep4(void);
void process_ep5(void);

void disable_device_mode(void);

int init_usb(void)
{
    //{{{
	//uart_print("usb_init6\n\r");

	pH264StreamSem = OSSemCreate(0);
	pJPEGStreamSem = OSSemCreate(0);
	pPCMINStreamSem = OSSemCreate(0);

	//init_streamBuf();
	
	//init_video_streamBuf();
	//init_audio_streamBuf();

	USB_FA      = 0x00000000; // Function Address
	USB_CSR     = 0x00000000; // Configuration and Status Register
	ms50_delay();
	
    USB_CSR     = USB_CSR_BASE_ADDR | USB_CSR_DISABLE_HS | USB_CSR_ENABLE_CORE; // full_speed
	//USB_CSR     = USB_CSR_BASE_ADDR | USB_CSR_ENABLE_CORE; //high_speed
	ms50_delay();

	//All Interrupt
	USB_INT_MSK = USB_INT_MSK_EN_NO_EP_ERROR << USB_INT_MSK_ENABLE_A_BASE_BIT;

	//Control Point Init
	USB_EP0_CSR = USB_EP_CSR_UC_DPD_NO_MODIFICATION 
							| USB_EP_CSR_EP_TYPE_CTRL 
							| USB_EP_CSR_TR_TYPE_BULK 
							| USB_EP_CSR_EP_DIS_NORMAL
							| EP0_EP_NO
							| USB_EP_CSR_EP_NACK_SET
							| USB_EP_CSR_EP_AUTO_NACK_SET
							| USB_EP_CSR_ZERO_LEN_DISABLE_RESET
							| EP0_TR_FR
							| EP0_MAX_PL_SZ
							;
	
	USB_EP0_INT = USB_EP_INT_ALL_INTS << USB_EP_INT_ENABLE_A_BASE_BIT;
  
	USB_EP0_OBA = ( EP0_BUF_SIZE << USB_EP_BUF_SZ_BIT ) | ( EP0_OUT_BUF_ADDR & USB_EP_BUF_PTR_MSK );

	get_status_from_host = 0;
	
	//ba usb interrupt enable
	IntEnable(USB_DEV_INTA_O_BIT);
	
	return 0;
    //}}}
}

void init_device_mode_noncontrol() 
{
    //{{{
	int temp;
	
	SystemInfo.Dev.max_pl = BULK_MAXPACKET_LENGTH;
	
	//EP1 Setting //control read (D -> H)
	USB_EP1_CSR = USB_EP_CSR_UC_DPD_NO_MODIFICATION 
							| USB_EP_CSR_EP_TYPE_IN 
							| USB_EP_CSR_TR_TYPE_BULK 
							| USB_EP_CSR_EP_DIS_NORMAL
							| EP1_EP_NO
							| USB_EP_CSR_EP_NACK_SET
							| USB_EP_CSR_EP_AUTO_NACK_SET
							| USB_EP_CSR_ZERO_LEN_DISABLE_SET
							| EP1_TR_FR
							| EP1_MAX_PL_SZ
							;
	
	//EP2 Setting //control write (H -> D)
	USB_EP2_CSR = USB_EP_CSR_UC_DPD_NO_MODIFICATION 
							| USB_EP_CSR_EP_TYPE_OUT 
							| USB_EP_CSR_TR_TYPE_BULK 
							| USB_EP_CSR_EP_DIS_NORMAL
							| EP2_EP_NO
							| USB_EP_CSR_EP_NACK_RESET
							| USB_EP_CSR_EP_AUTO_NACK_SET
							| USB_EP_CSR_ZERO_LEN_DISABLE_RESET
							| EP2_TR_FR
							| EP2_MAX_PL_SZ
							;
	
	USB_EP2_OBA = ( EP2_BUF_SIZE << USB_EP_BUF_SZ_BIT ) | ( EP2_BUF_ADDR & USB_EP_BUF_PTR_MSK );

	//EP3 Setting //JPEG
	USB_EP3_CSR = USB_EP_CSR_UC_DPD_NO_MODIFICATION 
							| USB_EP_CSR_EP_TYPE_IN 
							| USB_EP_CSR_TR_TYPE_BULK 
							| USB_EP_CSR_EP_DIS_NORMAL
							| EP3_EP_NO
							| USB_EP_CSR_EP_NACK_SET
							| USB_EP_CSR_EP_AUTO_NACK_SET
							| USB_EP_CSR_ZERO_LEN_DISABLE_SET
							| EP3_TR_FR
							| EP3_MAX_PL_SZ
							;
	
	//EP4 Setting //H264
	USB_EP4_CSR = USB_EP_CSR_UC_DPD_NO_MODIFICATION 
							| USB_EP_CSR_EP_TYPE_IN 
							| USB_EP_CSR_TR_TYPE_BULK 
							| USB_EP_CSR_EP_DIS_NORMAL
							| EP4_EP_NO
							| USB_EP_CSR_EP_NACK_SET
							| USB_EP_CSR_EP_AUTO_NACK_SET
							| USB_EP_CSR_ZERO_LEN_DISABLE_SET
							| EP4_TR_FR
							| EP4_MAX_PL_SZ
							;

	//EP5 Setting //PCM IN
	USB_EP5_CSR = USB_EP_CSR_UC_DPD_NO_MODIFICATION 
							| USB_EP_CSR_EP_TYPE_IN 
							| USB_EP_CSR_TR_TYPE_BULK 
							| USB_EP_CSR_EP_DIS_NORMAL
							| EP5_EP_NO
							| USB_EP_CSR_EP_NACK_SET
							| USB_EP_CSR_EP_AUTO_NACK_SET
							| USB_EP_CSR_ZERO_LEN_DISABLE_SET
							| EP5_TR_FR
							| EP5_MAX_PL_SZ
							;

	USB_EP1_INT = ( USB_EP_INT_ALL_INTS 
					//& ~(USB_EP_INT_TX_DATA_PKT | USB_EP_INT_TIMEOUT | USB_EP_INT_IN_FIFO_EMPTYON_READ | USB_EP_INT_BUFFER_EMPTY)) 
					//& ~(USB_EP_INT_TX_DATA_PKT | USB_EP_INT_TIMEOUT | USB_EP_INT_IN_FIFO_EMPTYON_READ)) 
					//& ~(USB_EP_INT_TX_DATA_PKT | USB_EP_INT_TIMEOUT )) 
					& ~(USB_EP_INT_BUFFER_EMPTY)) 
					<< USB_EP_INT_ENABLE_A_BASE_BIT;	

	USB_EP2_INT = USB_EP_INT_ALL_INTS << USB_EP_INT_ENABLE_A_BASE_BIT;
	USB_EP3_INT = ( USB_EP_INT_ALL_INTS 
					//& ~(USB_EP_INT_TX_DATA_PKT | USB_EP_INT_TIMEOUT | USB_EP_INT_IN_FIFO_EMPTYON_READ )) 
					//& ~(USB_EP_INT_TX_DATA_PKT | USB_EP_INT_TIMEOUT )) 
					)					 
					<< USB_EP_INT_ENABLE_A_BASE_BIT;	

	USB_EP4_INT = ( USB_EP_INT_ALL_INTS 
					//& ~(USB_EP_INT_TX_DATA_PKT | USB_EP_INT_TIMEOUT | USB_EP_INT_IN_FIFO_EMPTYON_READ )) 
					//& ~(USB_EP_INT_TX_DATA_PKT | USB_EP_INT_TIMEOUT )) 
					)
					<< USB_EP_INT_ENABLE_A_BASE_BIT;	

	USB_EP5_INT = ( USB_EP_INT_ALL_INTS 
					//& ~(USB_EP_INT_TX_DATA_PKT | USB_EP_INT_TIMEOUT | USB_EP_INT_IN_FIFO_EMPTYON_READ )) 
					//& ~(USB_EP_INT_TX_DATA_PKT | USB_EP_INT_TIMEOUT )) 
					)
					<< USB_EP_INT_ENABLE_A_BASE_BIT;	

	//Clear Interrupt
	temp = USB_EP1_INT;
	temp = USB_EP2_INT;
	temp = USB_EP3_INT;
	temp = USB_EP4_INT;
	temp = USB_EP5_INT;
    //}}}
}

void usb_interrupt_handler(void)
{
    //{{{
	int usb_int_src;

	usb_int_src = USB_INT_SRC;
	//uart_print("int_src:");
	//uart_printInt(usb_int_src);
	//uart_print("\n\r");

	//ep0
	if ( usb_int_src & USB_INT_SRC_EP0 )
	{
		process_ep0();
	}
	//ep3
	if ( usb_int_src & USB_INT_SRC_EP3 )
	{
		process_ep3();
	}
	//ep4
	if ( usb_int_src & USB_INT_SRC_EP4 )
	{
		process_ep4();
	}
	//ep5
	if ( usb_int_src & USB_INT_SRC_EP5 )
	{
		process_ep5();
	}
	//ep2
	if ( usb_int_src & USB_INT_SRC_EP2 )
	{
		process_ep2();
	}
	//ep1
	if ( usb_int_src & USB_INT_SRC_EP1 )
	{
		process_ep1();
	}
	return;
    //}}}
}


// ep point handler
void process_ep0(void)
{
	// {{{
	int usb_ep_int;

    int SETUPDAT1;
    int SETUPDAT2;
  
    int len;
    int len2;
    int idx;
    int vle;
    int reqt;

	int i;

	usb_ep_int = USB_EP0_INT & USB_EP_INT_ALL_INTS;
	//uart_print("usb_ep_int:");
	//uart_printInt(usb_ep_int);
	//uart_print("\n\r");

	// After Sending Out Data
	if ( ( usb_ep_int & ( USB_EP_INT_RX_CONTROL_PKT | USB_EP_INT_TX_DATA_PKT ) ) == USB_EP_INT_TX_DATA_PKT )
	{
		if (get_status_from_host) 
        {
			get_status_from_host = 0;
			ep0_nack_toggle();
		}
		return;
	}
	
    // Received nothing
	if ( ( usb_ep_int & ( USB_EP_INT_RX_CONTROL_PKT | USB_EP_INT_RX_DATA_PKT ) ) == USB_EP_INT_RX_DATA_PKT )
	{
		return;
	}

	// Received 0 payload ACK (0 length)
	if ( ( usb_ep_int & USB_EP_INT_RX_CONTROL_PKT ) == 0x00 )
	{
		get_status_from_host = 0;
		return;
	}
	
	// Receive Control Pkt and Data pkt
	if ( usb_ep_int & USB_EP_INT_RX_DATA_PKT )
	{
		if ( get_status_from_host )
		{
			get_status_from_host = 0;
		}
	}

    SETUPDAT1 = *(volatile int*)(EP0_OUT_BUF_ADDR); // EP0_OUT_BUF_ADDR = 0xf1000000 + 0x40
    SETUPDAT2 = *(volatile int*)(EP0_OUT_BUF_ADDR + 4);

	//uart_print("SETUP : ");
	//uart_printInt(SETUPDAT1);
	//uart_print(", ");
	//uart_printInt(SETUPDAT2);
	//uart_print("\n\r");

    len = (SETUPDAT2>>16) & 0xFFFF;
    idx = (SETUPDAT2) & 0xFFFF;
    vle = (SETUPDAT1>>16) & 0xFFFF;
    reqt = SETUPDAT1 & 0xFFFF;

    switch ((SETUPDAT1 >> 8) & 0xFF) 
    {
        case SC_GET_DESCRIPTOR: // 0x06
            //{{{
            switch ((SETUPDAT1 >> 24) & 0xFF) 
            {
                //{{{
                case GD_DEVICE:
                    //{{{
                    //memcpy(EP0_IN_BUF_ADDR, sDeviceDescriptor, 20);
                    for ( i = 0; i < DEVICE_DESCRIPTOR_LENGTH; i +=4 )
                    //for ( i = 0; i < 24; i +=4 )
                    {
                        *(volatile int*)(EP0_IN_BUF_ADDR + i) = sDeviceDescriptor[i/4]; 
                    }
                    //uart_print("read Again\n\r");
                    //uart_printInt(*(volatile int*)(EP0_IN_BUF_ADDR + 16 ));
                    //uart_print("\n\r");
          	
                    if (len > DEVICE_DESCRIPTOR_LENGTH) 
                    { 
                        len = DEVICE_DESCRIPTOR_LENGTH; 
                    }
                    
                    USB_EP0_IBA = ( DEVICE_DESCRIPTOR_LENGTH << USB_EP_BUF_SZ_BIT ) | ( EP0_IN_BUF_ADDR & USB_EP_BUF_PTR_MSK );
                    ms50_delay();
        	
                    break;
                    //}}}

                case GD_CONFIGURATION:
                    //{{{
                    len2 = len_sConfigDescriptor;
          	
                    if (len > len2) 
                    { 
                        len = len2; 
                    }
                    
                    //memcpy(EP0_IN_BUF_ADDR, sConfigDescriptor, len2);
                    for ( i = 0; i < len; i +=4 )
                    {
                        *(volatile int*)(EP0_IN_BUF_ADDR + i) = sConfigDescriptor[i/4];
                    }

                    USB_EP0_IBA = ( len << USB_EP_BUF_SZ_BIT ) | ( EP0_IN_BUF_ADDR & USB_EP_BUF_PTR_MSK );
                    ms50_delay();
                    break;
                    //}}}

                case GD_STRING:
                    //{{{
                    if ( ( vle & 0xFF ) == 0 )
                    {
                        len2 = 4;
                        if(len > len2) {len = len2;}
                        *(volatile int*)EP0_IN_BUF_ADDR = sString0;
           
                        USB_EP0_IBA = ( len << USB_EP_BUF_SZ_BIT ) | ( EP0_IN_BUF_ADDR & USB_EP_BUF_PTR_MSK );
                    }
			
                    //Manufacturer
                    else if ( ( vle & 0xFF ) == 1)
                    {
                        //memcpy(EP0_IN_BUF_ADDR, sString1, 20);
                        for ( i = 0; i < 48; i +=4 )
                        {
                            *(volatile int*)(EP0_IN_BUF_ADDR + i) = sString1[i/4];
                        }
           
                        USB_EP0_IBA = ( 48 << USB_EP_BUF_SZ_BIT ) | ( EP0_IN_BUF_ADDR & USB_EP_BUF_PTR_MSK );
                    }
			
                    //Product
                    else if ( ( vle & 0xFF ) == 2)
                    {
                        //memcpy(EP0_IN_BUF_ADDR, sString2, 40);
                        for ( i = 0; i < 64; i +=4 )
                        {
                            *(volatile int*)(EP0_IN_BUF_ADDR + i) = sString2[i/4];
                        }
           
                        USB_EP0_IBA = ( 62 << USB_EP_BUF_SZ_BIT ) | ( EP0_IN_BUF_ADDR & USB_EP_BUF_PTR_MSK );
                    }
			
                    //Serial No.
                    else if ( ( vle & 0xFF ) == 3)
                    {
                        //memcpy(EP0_IN_BUF_ADDR, sString2, 40);
                        for ( i = 0; i < 20; i +=4 )
                        {
                            *(volatile int*)(EP0_IN_BUF_ADDR + i) = sString3[i/4];
                        }
           
                        USB_EP0_IBA = ( 18 << USB_EP_BUF_SZ_BIT ) | ( EP0_IN_BUF_ADDR & USB_EP_BUF_PTR_MSK );
                    }

                    break;
                    //}}}

                case GD_DEVICE_QUALIFIER:
                    //{{{
                    for ( i = 0; i < len_sQualifier; i +=4 )
                    {
                        *(volatile int*)(EP0_IN_BUF_ADDR + i) = sQualifier[i/4];
                    }
  		  	
                    USB_EP0_IBA = ( len_sQualifier << USB_EP_BUF_SZ_BIT ) | ( EP0_IN_BUF_ADDR & USB_EP_BUF_PTR_MSK );
			
                    break;
                    //}}}

                default:
                    //{{{
                    //Invalid request, STALL !!
					uart_print("Invalid request");
					uart_printInt(SETUPDAT1);
					uart_print("\n\r");
                    //}}}
                //}}}
            }//switch
      
            get_status_from_host = 1;
			
            *(volatile int*)(EP0_OUT_BUF_ADDR) = 0x00000000; //Clear
      
            break;
		    //}}}
        
        case SC_SET_ADDRESS: // 0x05
            //{{{
            *(volatile int*)(EP0_IN_BUF_ADDR) = 0x00000000; //0 payload
            USB_EP0_IBA = ( 0 << USB_EP_BUF_SZ_BIT ) | ( EP0_IN_BUF_ADDR & USB_EP_BUF_PTR_MSK );
            USB_FA = SETUPDAT1>>16 & 0x7F;
    	
            //Set the device as ADDRESSED if it in the UNCONFIGURED STATE
            if (SystemInfo.DeviceState == DEV_UNCONFIGURED) {
                SystemInfo.DeviceState = DEV_ADDRESSED;
            }
      
            break;
		    //}}}

        case SC_SET_CONFIGURATION:
            //{{{
            SystemInfo.Dev.set_halt = 0;
            SystemInfo.Dev.set_remote_wakeup = 0;
		
            *(volatile int*)(EP0_IN_BUF_ADDR) = 0x00000000; //0 payload
  		
            USB_EP0_IBA = ( 0 << USB_EP_BUF_SZ_BIT ) | ( EP0_IN_BUF_ADDR & USB_EP_BUF_PTR_MSK );
		
            SystemInfo.Dev.Device_Config_Value = SETUPDAT1 >> 16;
		
            ep_clear_dpid();
		  
            //Set the device as CONFIGURED and set-up other endpoints
            if (SystemInfo.Dev.Device_Config_Value) {
                SystemInfo.DeviceState = DEV_CONFIGURED;
                init_device_mode_noncontrol();
            } else {
                SystemInfo.DeviceState = DEV_UNCONFIGURED;
                disable_device_mode();
            }
			
            break;
  	        //}}}

        case SC_SET_INTERFACE:
            //{{{
            *(volatile int*)(EP0_IN_BUF_ADDR) = 0x00000000; //0 payload
  		
            USB_EP0_IBA = ( 0 << USB_EP_BUF_SZ_BIT ) | ( EP0_IN_BUF_ADDR & USB_EP_BUF_PTR_MSK );
      
            break;
		    //}}}

        case SC_CLEAR_FEATURE:
            //{{{
            *(volatile int*)(EP0_IN_BUF_ADDR) = 0x00000000; //0 payload
  		
            USB_EP0_IBA = ( 0 << USB_EP_BUF_SZ_BIT ) | ( EP0_IN_BUF_ADDR & USB_EP_BUF_PTR_MSK );
      
            switch ( (SETUPDAT1 >>16) & 0xFF ) {
                // HALT
                case 0:
                    SystemInfo.Dev.set_halt = 0;
                    clr_stall_endpoint(SETUPDAT2 & 0x0F);
        	
                    break;
      	
                // REMOTE WAKEUP
                case 1:
                    SystemInfo.Dev.set_remote_wakeup = 0;
      	  
                    break;
            }

            break;
            //}}}

        case SC_GET_CONFIGURATION:
            //{{{
            if (SystemInfo.Dev.Device_Config_Value) {
                *(volatile int*)(EP0_IN_BUF_ADDR) = 0x00000001; //1 payload
                uart_print("configured\n\r");
            } else {
                *(volatile int*)(EP0_IN_BUF_ADDR) = 0x00000000; //1 payload
                uart_print("Not configured\n\r");
            }
  		
            USB_EP0_IBA = ( 1 << USB_EP_BUF_SZ_BIT ) | ( EP0_IN_BUF_ADDR & USB_EP_BUF_PTR_MSK );

            get_status_from_host = 1;
        
            break;
            //}}}

        //Other Control Command
        default:
            //{{{
            //Invalid request, STALL !!
			uart_print("Default request:");
			uart_printInt(SETUPDAT1);
			uart_print(",");
			uart_printInt(SETUPDAT2);
			uart_print("\n\r");
			return;
            //}}}
    }

    USB_EP0_OBA = ( EP0_BUF_SIZE << USB_EP_BUF_SZ_BIT ) | ( EP0_OUT_BUF_ADDR & USB_EP_BUF_PTR_MSK );

    ep0_nack_toggle();

	return;
	// }}}
}

void process_ep1(void) // Command Send (D -> H)
{
	// {{{
	int usb_ep_int;
	
    usb_ep_int = USB_EP1_INT & USB_EP_INT_ALL_INTS;

	if ( usb_ep_int & USB_EP_INT_BUFFER_EMPTY ) 
	{
	}
	else if ( usb_ep_int & USB_EP_INT_TX_DATA_PKT )
    {
		ep1_nack_toggle();
    }

	return;
	// }}}
}

void process_ep2(void) // Command Receive (H -> D)
{
	// {{{
	int usb_ep_int;
	//uart_print("ep2 int\n");
	usb_ep_int = USB_EP2_INT & USB_EP_INT_ALL_INTS; // 4-bytes = 32-bits

	//uart_print("ep2:");
	//uart_printInt(*(volatile int*)EP2_BUF_ADDR);
	//uart_print("\n\r");

	int empty_len = 0;
	int transferred_len = 0;

	if (usb_ep_int & USB_EP_INT_RX_DATA_PKT) // receiving a data packet successfully...
	{
		empty_len = USB_EP2_OBA >> USB_EP_BUF_SZ_BIT; // USB_EP_BUF_SZ_BIT = 17
		transferred_len = EP0_BUF_SIZE - empty_len; // EP0_BUF_SIZE = 0x40
		
		////debug
		//if ( transferred_len == 0 )
		//{
		//	uart_print("tranLen:");
		//	uart_printInt(transferred_len);
		//	uart_print("\n\r");
		//}

		commandProcess((char*)EP2_BUF_ADDR, transferred_len); // transferred_len is not used...
		
        //Command Buffer Reset
		memset((char*)EP2_BUF_ADDR,0,4);

		//Reset EP2
		USB_EP2_OBA = ( EP2_BUF_SIZE << USB_EP_BUF_SZ_BIT ) | ( EP2_BUF_ADDR & USB_EP_BUF_PTR_MSK );
		
        //ms50_delay();
		//ms50_delay();
		ms50_delay();
		
        ep2_nack_toggle();
	}
	else
	{
		uart_print("ep2int:");
		uart_printInt(usb_ep_int);
		uart_print("\n\r");
	}

	return;
	// }}}
}

void process_ep3(void) // JPEG
{
	// {{{
    int usb_ep_int;
	int packet_len = 0;
	
    usb_ep_int = USB_EP3_INT & USB_EP_INT_ALL_INTS;
	
    if ( usb_ep_int & USB_EP_INT_BUFFER_EMPTY ) 
	{
		if ( jpegDualStreamBuf.len[(int)jpegDualStreamBuf.get_idx] > 0 )
		{
			//ep3_nack();
			packet_len = 
				( jpegDualStreamBuf.len[(int)jpegDualStreamBuf.get_idx] > USB_EP_MAX_BUFFER_SIZE ) ? 
                USB_EP_MAX_BUFFER_SIZE : jpegDualStreamBuf.len[(int)jpegDualStreamBuf.get_idx];
                // packet_len = shorter one
                // USB_EP_MAX_BUFFER_SIZE = 16320

			USB_EP3_IBA = ( packet_len << USB_EP_BUF_SZ_BIT ) 
                | ( jpegDualStreamBuf.address[(int)jpegDualStreamBuf.get_idx] & USB_EP_BUF_PTR_MSK );
			jpegDualStreamBuf.len[(int)jpegDualStreamBuf.get_idx] -= packet_len; 
			jpegDualStreamBuf.address[(int)jpegDualStreamBuf.get_idx] += packet_len;

			ms50_delay();

			ep3_nack_toggle();
		}
		else
		{
			jpegDualStreamBuf.len[(int)jpegDualStreamBuf.get_idx] = 0;
			jpegDualStreamBuf.address[(int)jpegDualStreamBuf.get_idx]
				= JPEG_STREAM_ADDR + MAX_JPEG_STREAM_LEN * jpegDualStreamBuf.get_idx;
			jpegDualStreamBuf.full[(int)jpegDualStreamBuf.get_idx] = 0;
			//ep3_nack();
			//jpegDualStreamBuf.get_idx++;
			//if ( jpegDualStreamBuf.get_idx == VIDEO_BUFFER_CNT )
			//	jpegDualStreamBuf.get_idx = 0;

			if ( isJPEGPend )
			{
				OSSemPost(pJPEGStreamSem);
			}
		}
	}
	else if ( usb_ep_int & USB_EP_INT_TX_DATA_PKT ) // BUFFER Not Empty
    {
		ep3_nack_toggle();
    }
    //}}}
}

void process_ep4(void) // H264
{
	// {{{
    int usb_ep_int; // 4-bytes = 32-bits
	int packet_len = 0;
	
    usb_ep_int = USB_EP4_INT & USB_EP_INT_ALL_INTS;
	
    if ( usb_ep_int & USB_EP_INT_BUFFER_EMPTY ) 
	{
		if ( h264DualStreamBuf.len[(int)h264DualStreamBuf.get_idx] > 0 )
		{
			//ep4_nack();
			packet_len = 
				( h264DualStreamBuf.len[(int)h264DualStreamBuf.get_idx] > USB_EP_MAX_BUFFER_SIZE ) ? 
                USB_EP_MAX_BUFFER_SIZE : h264DualStreamBuf.len[(int)h264DualStreamBuf.get_idx];
                // packet_len = shorter one
                // USB_EP_MAX_BUFFER_SIZE = 16320

			USB_EP4_IBA = ( packet_len << USB_EP_BUF_SZ_BIT ) 
                | ( h264DualStreamBuf.address[(int)h264DualStreamBuf.get_idx] & USB_EP_BUF_PTR_MSK );

			h264DualStreamBuf.len[(int)h264DualStreamBuf.get_idx] -= packet_len; 
			h264DualStreamBuf.address[(int)h264DualStreamBuf.get_idx] += packet_len;
			
            ms50_delay();
			ep4_nack_toggle();
		}
		else
		{
			h264DualStreamBuf.count--;
			h264DualStreamBuf.len[(int)h264DualStreamBuf.get_idx] = 0;
			h264DualStreamBuf.address[(int)h264DualStreamBuf.get_idx]
				= H264_STREAM_ADDR + MAX_H264_STREAM_LEN * h264DualStreamBuf.get_idx;
			h264DualStreamBuf.full[(int)h264DualStreamBuf.get_idx] = 0;
			//ep4_nack();
			h264DualStreamBuf.get_idx++;
			
            if ( h264DualStreamBuf.get_idx == VIDEO_BUFFER_CNT ) // VIDEO_BUFFER_CNT = 2
				h264DualStreamBuf.get_idx = 0;

			if ( isJpegDataExist ) // cannot understand
			{
				isJpegDataExist = 0;
				packet_len = 
					( jpegDualStreamBuf.len[(int)jpegDualStreamBuf.get_idx] > USB_EP_MAX_BUFFER_SIZE ) ? 
                    USB_EP_MAX_BUFFER_SIZE : jpegDualStreamBuf.len[(int)jpegDualStreamBuf.get_idx];
				USB_EP3_IBA = ( packet_len << USB_EP_BUF_SZ_BIT ) 
					| ( jpegDualStreamBuf.address[(int)jpegDualStreamBuf.get_idx] & USB_EP_BUF_PTR_MSK );
				jpegDualStreamBuf.len[(int)jpegDualStreamBuf.get_idx] -= packet_len; 
				jpegDualStreamBuf.address[(int)jpegDualStreamBuf.get_idx] += packet_len;
				ms50_delay();
				ep3_nack_toggle();
			}

			if ( isH264Pend )
			{
				OSSemPost(pH264StreamSem);
			}
		}
	}
	else if ( usb_ep_int & USB_EP_INT_TX_DATA_PKT )
    {
		ep4_nack_toggle();
    }
    //}}}
}

void process_ep5(void) // PCM IN
{
    //{{{
	int usb_ep_int;
	usb_ep_int = USB_EP5_INT & USB_EP_INT_ALL_INTS;

	if ( usb_ep_int & USB_EP_INT_BUFFER_EMPTY ) 
	{
	}
	else if ( usb_ep_int & USB_EP_INT_TX_DATA_PKT )
		ep5_nack_toggle();

	return;
    //}}}
}

//usb utility
void ms50_delay() {
  int i;
  for (i=0;i<1000;i++) {
   __asm __volatile("l.nop   0");
  }
}

//usb utility
void ms10_delay() {
  int i;
  for (i=0;i<500;i++) __asm __volatile("l.nop   0");
}

void ep0_nack_toggle() {
  int temp;
  temp = USB_EP0_CSR;
  temp &= 0xCF3DFFFF;

  USB_EP0_CSR = temp;
}

void ep1_nack_toggle() {
  int temp;
  temp = USB_EP1_CSR;
  temp &= 0xCFFDFFFF;
  USB_EP1_CSR = temp;
}

void ep2_nack_toggle() {
  int temp;
  temp = USB_EP2_CSR;
  temp &= 0xCFFDFFFF;
  USB_EP2_CSR = temp;
}

void ep2_nack() {
  int temp;
  temp = USB_EP2_CSR;
  temp &= 0xCFFDFFFF;
  temp |= ( USB_EP_CSR_UC_DPD_NO_MODIFICATION | USB_EP_CSR_EP_NACK_SET );
  USB_EP2_CSR = temp;
}

void ep3_nack_toggle() {
  int temp;
  temp = USB_EP3_CSR;
  temp &= 0xCFFDFFFF;
  USB_EP3_CSR = temp;
}

void ep3_nack() {
  int temp;
  temp = USB_EP3_CSR;
  temp &= 0xCFFDFFFF;
  temp |= ( USB_EP_CSR_UC_DPD_NO_MODIFICATION | USB_EP_CSR_EP_NACK_SET );
  USB_EP3_CSR = temp;
}

void ep4_nack_toggle() {
  int temp;
  temp = USB_EP4_CSR;
  temp &= 0xCFFDFFFF;
  USB_EP4_CSR = temp;
}

void ep4_nack() {
  int temp;
  temp = USB_EP4_CSR;
  temp &= 0xCFFDFFFF;
  temp |= ( USB_EP_CSR_UC_DPD_NO_MODIFICATION | USB_EP_CSR_EP_NACK_SET );
  USB_EP4_CSR = temp;
}

void ep5_nack_toggle() {
  int temp;
  temp = USB_EP5_CSR;
  temp &= 0xCFFDFFFF;
  USB_EP5_CSR = temp;
}

void ep5_nack() {
  int temp;
  temp = USB_EP5_CSR;
  temp &= 0xCFFDFFFF;
  temp |= ( USB_EP_CSR_UC_DPD_NO_MODIFICATION | USB_EP_CSR_EP_NACK_SET );
  USB_EP5_CSR = temp;
}

void ep_clear_dpid() {
  int temp;
  temp = USB_EP1_CSR;  temp &= 0x0FFFFFFF; temp |= 0x10000000; USB_EP1_CSR = temp;
  temp = USB_EP2_CSR;  temp &= 0x0FFFFFFF; temp |= 0x10000000; USB_EP2_CSR = temp;
  temp = USB_EP3_CSR;  temp &= 0x0FFFFFFF; temp |= 0x10000000; USB_EP3_CSR = temp;
  temp = USB_EP4_CSR;  temp &= 0x0FFFFFFF; temp |= 0x10000000; USB_EP4_CSR = temp;
  temp = USB_EP5_CSR;  temp &= 0x0FFFFFFF; temp |= 0x10000000; USB_EP5_CSR = temp;
}

void disable_device_mode(void) 
{
		USB_EP1_CSR |= USB_EP_CSR_EP_DIS_IGNORE; // 0000_0000_0100_0000_0000_0000_0000_0000
		USB_EP1_INT = 0x00000000;
		USB_EP1_OBA = 0x00000000;
		USB_EP1_IBA = 0x00000000;

		USB_EP2_CSR |= USB_EP_CSR_EP_DIS_IGNORE;
		USB_EP2_INT = 0x00000000;
		USB_EP2_OBA = 0x00000000;
		USB_EP2_IBA = 0x00000000;

		USB_EP3_CSR |= USB_EP_CSR_EP_DIS_IGNORE;
		USB_EP3_INT = 0x00000000;
		USB_EP3_OBA = 0x00000000;
		USB_EP3_IBA = 0x00000000;

		USB_EP4_CSR |= USB_EP_CSR_EP_DIS_IGNORE;
		USB_EP4_INT = 0x00000000;
		USB_EP4_OBA = 0x00000000;
		USB_EP4_IBA = 0x00000000;

		USB_EP5_CSR |= USB_EP_CSR_EP_DIS_IGNORE;
		USB_EP5_INT = 0x00000000;
		USB_EP5_OBA = 0x00000000;
		USB_EP5_IBA = 0x00000000;
}

void clr_stall_endpoint(int ep_num) 
{
	int temp;

	uart_print("clr_stall_endpoint ep_num:");
	uart_printInt(ep_num);
	uart_print("\n\r");
	
    switch (ep_num) {
		case 0:	temp = USB_EP0_CSR;
						temp &= ~USB_EP_CSR_EP_DIS_NORMAL;
						USB_EP0_CSR = temp;
						break;
		case 1: temp = USB_EP1_CSR;
						temp &= ~USB_EP_CSR_EP_DIS_HALT;
						USB_EP1_CSR = temp;
						break;
		case 2: temp = USB_EP2_CSR;
						temp &= ~USB_EP_CSR_EP_DIS_HALT;
						USB_EP2_CSR = temp;
						break;
		case 3: temp = USB_EP3_CSR;
						temp &= ~USB_EP_CSR_EP_DIS_HALT;
						USB_EP3_CSR = temp;
						break;
		case 4: temp = USB_EP4_CSR;
						temp &= ~USB_EP_CSR_EP_DIS_HALT;
						USB_EP4_CSR = temp;
						break;
		case 5: temp = USB_EP5_CSR;
						temp &= ~USB_EP_CSR_EP_DIS_HALT;
						USB_EP5_CSR = temp;
						break;
		}
}

void init_video_streamBuf(void)
{
	int i;

	// jpeg stream
	for ( i = 0; i < VIDEO_BUFFER_CNT; i++ ) // VIDEO_BUFFER_CNT = 2
	{
		jpegDualStreamBuf.len[i] = 0;
		jpegDualStreamBuf.address[i] = JPEG_STREAM_ADDR + MAX_JPEG_STREAM_LEN * i;
        // JPEG_STREAM_ADDR = JPEG_STREAM_BASE_TEST = 0xf1000100
        // MAX_JPEG_STREAM_LEN = 12*1024 // cannot understand
		jpegDualStreamBuf.full[i] = 0;
	}
	jpegDualStreamBuf.set_idx = 0;
	jpegDualStreamBuf.get_idx = 0;
	jpegDualStreamBuf.count = 0;

	// h264 stream
	for ( i = 0; i < VIDEO_BUFFER_CNT; i++ )
	{
		h264DualStreamBuf.len[i] = 0;
		h264DualStreamBuf.address[i] = H264_STREAM_ADDR + MAX_H264_STREAM_LEN * i;
        // H264_STREAM_ADDR = 0xf1000100 + 12*1024 * 2
        // MAX_H264_STREAM_LEN = 36*1024
		h264DualStreamBuf.full[i] = 0;
	}
	h264DualStreamBuf.set_idx = 0;
	h264DualStreamBuf.get_idx = 0;
	h264DualStreamBuf.count = 0;

	return;
}

void init_audio_streamBuf(void)
{
	int i;

	// pcmin stream
	for ( i = 0; i < PCM_BUFFER_CNT; i++ ) // PCM_BUFFER_CNT = 10
	{
		pcminDualStreamBuf.len[i] = 0;
		pcminDualStreamBuf.address[i] = PCMIN_STREAM_ADDR + MAX_PCM_STREAM_LEN * i;
        // PCMIN_STREAM_ADDR = 0xf1000100 + 12*1024 * 2 + 36*1024 * 2
        // MAX_PCM_STREAM_LEN = 3*1024
		pcminDualStreamBuf.full[i] = 0;
	}
	pcminDualStreamBuf.set_idx = 0;
	pcminDualStreamBuf.get_idx = 0;
	pcminDualStreamBuf.count = 0;

	return;
}

void wdt_interrupt_handler(void)
{
	//int packet_len = 0;
	if ( isH264Pend )
	{
		uart_print("H264POST\n\r");

		OPERATION_DEFINE3 |= KEYFRAME_REQUEST_BIT;
		init_video_streamBuf();
		OSSemPost(pH264StreamSem);
	}

	if ( isJPEGPend )
	{
		uart_print("JPEGPOST\n\r");

		OPERATION_DEFINE3 |= KEYFRAME_REQUEST_BIT;
		init_video_streamBuf();
		OSSemPost(pJPEGStreamSem);
	}

	*(volatile int*)WDT_BASE_ADDR = 0xffffffff; //100ms
   __asm __volatile("l.nop   0");
   __asm __volatile("l.nop   0");
   __asm __volatile("l.nop   0");
   __asm __volatile("l.nop   0");
   __asm __volatile("l.nop   0");
   __asm __volatile("l.nop   0");
   __asm __volatile("l.nop   0");
   __asm __volatile("l.nop   0");
   __asm __volatile("l.nop   0");
   __asm __volatile("l.nop   0");
   __asm __volatile("l.nop   0");
}

void ptc_interrupt_handler(void)
{
	RPTC_CTRL |= 0x040; //Interrupt Clear
	uart_print("ptc interrupt\n\r");
	RPTC_CNTR = 0x0; //Reset PTC Counter
}
