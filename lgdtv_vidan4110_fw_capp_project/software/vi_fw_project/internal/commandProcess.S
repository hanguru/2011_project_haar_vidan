	.file	"commandProcess.c"
	.stabs	"/home/hanguru/2011_project_original/lgdtv_vidan4110_fw_capp_project/software/vi_fw_project/",100,0,2,.Ltext0
	.stabs	"internal/commandProcess.c",100,0,2,.Ltext0
.section .internalrom, "ax"
.Ltext0:
	.stabs	"gcc2_compiled.",60,0,0,0
	.stabs	"int:t(0,1)=r(0,1);-2147483648;2147483647;",128,0,0,0
	.stabs	"char:t(0,2)=r(0,2);0;127;",128,0,0,0
	.stabs	"long int:t(0,3)=r(0,3);-2147483648;2147483647;",128,0,0,0
	.stabs	"unsigned int:t(0,4)=r(0,4);0;037777777777;",128,0,0,0
	.stabs	"long unsigned int:t(0,5)=r(0,5);0;037777777777;",128,0,0,0
	.stabs	"long long int:t(0,6)=@s64;r(0,6);01000000000000000000000;0777777777777777777777;",128,0,0,0
	.stabs	"long long unsigned int:t(0,7)=@s64;r(0,7);0;01777777777777777777777;",128,0,0,0
	.stabs	"short int:t(0,8)=@s16;r(0,8);-32768;32767;",128,0,0,0
	.stabs	"short unsigned int:t(0,9)=@s16;r(0,9);0;65535;",128,0,0,0
	.stabs	"signed char:t(0,10)=@s8;r(0,10);-128;127;",128,0,0,0
	.stabs	"unsigned char:t(0,11)=@s8;r(0,11);0;255;",128,0,0,0
	.stabs	"float:t(0,12)=r(0,1);4;0;",128,0,0,0
	.stabs	"double:t(0,13)=r(0,1);8;0;",128,0,0,0
	.stabs	"long double:t(0,14)=r(0,1);8;0;",128,0,0,0
	.stabs	"void:t(0,15)=(0,15)",128,0,0,0
	.stabs	"interface/usb.h",130,0,0,0
	.stabs	"EndpointDescriptorObj:t(1,1)=(1,2)=s24num:(0,1),0,32;enabled:(0,1),32,32;type:(0,1),64,32;maxpacketsize:(0,1),96,32;pid:(0,1),128,32;dir:(0,1),160,32;;",128,0,427,0
	.stabs	"IntfDescriptorObj:t(1,3)=(1,4)=s12Class:(0,1),0,32;SubClass:(0,1),32,32;Protocol:(0,1),64,32;;",128,0,433,0
	.stabs	" :T(1,5)=eMSD_BOT:0,MSD_CBI:1,;",128,0,0,0
	.stabs	"MsdDeviceType:t(1,6)=(1,5)",128,0,438,0
	.stabs	" :T(1,7)=eDISCONNECTED:0,FS_CONNECT:1,HS_CONNECT:2,LS_CONNECT:3,SUSPENDED:4,RESUMING:5,;",128,0,0,0
	.stabs	"UsbConnectionType:t(1,8)=(1,7)",128,0,447,0
	.stabs	"tUsbHostObj:t(1,9)=(1,10)=s164VID:(0,1),0,32;PID:(0,1),32,32;DevClass:(0,1),64,32;Intf:(1,3),96,96;Address:(0,1),192,32;NumEp:(0,1),224,32;enumerated:(0,1),256,32;resume_complete:(0,1),288,32;suspended:(0,1),320,32;configured:(0,1),352,32;OtgSupport:(0,1),384,32;InterfaceType:(0,1),416,32;EP0:(1,1),448,192;EPIIn:(1,1),640,192;EPBIn:(1,1),832,192;EPBOut:(1,1),1024,192;EPcsw:(1,11)=*(1,1),1216,32;connection:(1,8),1248,32;MsdType:(1,6),1280,32;;",128,0,469,0
	.stabs	" :T(1,12)=eDEFAULT:0,B_IDLE:1,B_SRP_INIT:2,B_PERIPHERAL:3,B_WAIT_ACON:4,B_HOST:5,A_IDLE:6,A_WAIT_VRISE:7,A_WAIT_BCON:8,A_HOST:9,A_HOST_REG:10,A_SUSPEND:11,A_RESUME:12,A_PERIPHERAL:13,A_WAIT_VFALL:14,A_VBUS_ERR:15,;",128,0,0,0
	.stabs	"tOtgStateType:t(1,13)=(1,12)",128,0,488,0
	.stabs	" :T(1,14)=eDEV_UNCONFIGURED:0,DEV_ADDRESSED:1,DEV_CONFIGURED:2,DEV_SUSPENDED:3,DEV_RESUME:4,HST_UNCONNECTED:5,HST_CONNECTED:6,;",128,0,0,0
	.stabs	"tUsbStateType:t(1,15)=(1,14)",128,0,498,0
	.stabs	"tOtgInfoObj:t(1,16)=(1,17)=s24SrpSupport:(0,1),0,32;HnpSupport:(0,1),32,32;hnp_enabled:(0,1),64,32;b_hnp_enable:(0,1),96,32;a_hnp_support:(0,1),128,32;a_alt_hnp_support:(0,1),160,32;;",128,0,507,0
	.stabs	"tUsbDeviceObj:t(1,18)=(1,19)=s20set_halt:(0,1),0,32;Device_Config_Value:(0,1),32,32;ep0_max_pl:(0,1),64,32;max_pl:(0,1),96,32;set_remote_wakeup:(0,1),128,32;;",128,0,515,0
	.stabs	"tUsbSystemObj:t(1,20)=(1,21)=s240DeviceState:(1,15),0,32;MainState:(1,13),32,32;otg_support:(0,1),64,32;is_host:(0,1),96,32;RegularHost:(0,1),128,32;gpout_shadow:(0,1),160,32;rxBuffer:(0,4),192,32;txBuffer:(0,4),224,32;OtgConfig:(1,16),256,192;Host:(1,9),448,1312;Dev:(1,18),1760,160;;",128,0,529,0
	.stabn	162,0,0,0
	.stabs	"interface/i2c_operation.h",130,0,0,0
	.stabs	" :T(2,1)=eI2C_NACK:-2,I2C_TIMEOUT:-1,I2C_SUCCESS:0,;",128,0,0,0
	.stabn	162,0,0,0
	.stabs	"interface/commandProcess.h",130,0,0,0
	.stabs	"ucos/ucos_ii.h",130,0,0,0
	.stabs	"ucos/os_cpu.h",130,0,0,0
	.stabs	"BOOLEAN:t(5,1)=(0,11)",128,0,9,0
	.stabs	"INT8U:t(5,2)=(0,11)",128,0,10,0
	.stabs	"INT8S:t(5,3)=(0,2)",128,0,11,0
	.stabs	"INT16U:t(5,4)=(0,9)",128,0,12,0
	.stabs	"INT16S:t(5,5)=(0,8)",128,0,13,0
	.stabs	"INT32U:t(5,6)=(0,5)",128,0,14,0
	.stabs	"INT32S:t(5,7)=(0,3)",128,0,15,0
	.stabs	"VBOOLEAN:t(5,8)=(5,9)=B(0,11)",128,0,16,0
	.stabs	"OS_STK:t(5,10)=(0,4)",128,0,17,0
	.stabs	"OS_CPU_SR:t(5,11)=(0,4)",128,0,18,0
	.stabn	162,0,0,0
	.stabs	"ucos/os_cfg.h",130,0,0,0
	.stabs	"OS_FLAGS:t(6,1)=(5,4)",128,0,112,0
	.stabn	162,0,0,0
	.stabs	"os_event:T(4,1)=s44OSEventType:(5,2),0,8;OSEventGrp:(5,2),8,8;OSEventCnt:(5,4),16,16;OSEventPtr:(4,2)=*(0,15),32,32;OSEventTbl:(4,3)=ar(4,4)=r(4,4);0;037777777777;;0;0;(5,2),64,8;OSEventName:(4,5)=ar(4,4);0;31;(0,2),72,256;;",128,0,0,0
	.stabs	"OS_EVENT:t(4,6)=(4,1)",128,0,257,0
	.stabs	"os_sem_data:T(4,7)=s4OSCnt:(5,4),0,16;OSEventTbl:(4,3),16,8;OSEventGrp:(5,2),24,8;;",128,0,0,0
	.stabs	"OS_SEM_DATA:t(4,8)=(4,7)",128,0,387,0
	.stabs	"os_stk_data:T(4,9)=s8OSFree:(5,6),0,32;OSUsed:(5,6),32,32;;",128,0,0,0
	.stabs	"OS_STK_DATA:t(4,10)=(4,9)",128,0,400,0
	.stabs	"os_tcb:T(4,11)=s96OSTCBStkPtr:(4,12)=*(5,10),0,32;OSTCBExtPtr:(4,2),32,32;OSTCBStkBottom:(4,12),64,32;OSTCBStkSize:(5,6),96,32;OSTCBOpt:(5,4),128,16;OSTCBId:(5,4),144,16;OSTCBNext:(4,13)=*(4,11),160,32;OSTCBPrev:(4,13),192,32;OSTCBEventPtr:(4,14)=*(4,6),224,32;OSTCBDly:(5,4),256,16;OSTCBStat:(5,2),272,8;OSTCBPendTO:(5,1),280,8;OSTCBPrio:(5,2),288,8;OSTCBX:(5,2),296,8;OSTCBY:(5,2),304,8;OSTCBBitX:(5,2),312,8;OSTCBBitY:(5,2),320,8;OSTCBDelReq:(5,2),328,8;OSTCBCtxSwCtr:(5,6),352,32;OSTCBCyclesTot:(5,6),384,32;OSTCBCyclesStart:(5,6),416,32;OSTCBStkBase:(4,12),448,32;OSTCBStkUsed:(5,6),480,32;OSTCBTaskName:(4,5),512,256;;",128,0,0,0
	.stabs	"OS_TCB:t(4,15)=(4,11)",128,0,464,0
	.stabn	162,0,0,0
	.stabs	" :T(3,1)=eUSB_COMMAND_FIRMWARE_VERSION_CHECK_FAIL:-9,USB_COMMAND_FIRMWARE_UPLOAD_FAIL:-8,USB_COMMAND_FIRMWARE_SET_LENGTH_FAIL:-7,USB_COMMAND_FIRMWARE_SDRAM_WRITE_FAIL:-6,USB_COMMAND_VIDEOAPISET_FAIL:-5,USB_COMMAND_STREAM_NOT_READY:-4,USB_COMMAND_I2C_FAIL:-3,USB_COMMAND_UNDEFINED_COMMAND:-2,USB_COMMAND_FAIL:-1,USB_COMMAND_SUCCESS:0,;",128,0,0,0
	.stabs	" :T(3,2)=eINTERNAL_REGISTER_READ:16,INTERNAL_REGISTER_WRITE:17,HIF_REGISTER_READ:32,HIF_REGISTER_WRITE:33,HIF_REGISTER_BIT_SET:34,HIF_REGISTER_BIT_RESET:35,I2C_MASTER_READ:48,I2C_MASTER_WRITE:49,STREAM_GET_JPEG_LENGTH:64,STREAM_GET_H264_LENGTH:65,STREAM_GET_PCMIN_LENGTH:66,COMMAND_VIDEO_START:80,COMMAND_VIDEO_STOP:81,COMMAND_AUDIO_START:82,COMMAND_AUDIO_STOP:83,COMMAND_FIRMWARE_SDRAM_WRITE:84,COMMAND_FIRMWARE_SET_LENGTH:85,COMMAND_FIRMWARE_UPLOAD:86,COMMAND_FIRMWARE_VERSION_CHECK:87,VIDEO_API_SET:96,;",128,0,0,0
	.stabs	"VIDEO_STREAM_BUF:t(3,3)=(3,4)=s24len:(3,5)=ar(4,4);0;1;(3,6)=B(0,1),0,64;address:(3,5),64,64;full:(3,7)=ar(4,4);0;1;(3,8)=B(0,2),128,16;set_idx:(3,8),144,8;get_idx:(3,8),152,8;count:(3,8),160,8;;",128,0,55,0
	.stabs	"PCM_STREAM_BUF:t(3,9)=(3,10)=s96len:(3,11)=ar(4,4);0;9;(3,6),0,320;address:(3,11),320,320;full:(3,12)=ar(4,4);0;9;(3,8),640,80;set_idx:(3,8),720,8;get_idx:(3,8),728,8;count:(3,8),736,8;;",128,0,66,0
	.stabn	162,0,0,0
	.stabs	"interface/AIC3101.h",130,0,0,0
	.stabs	"Uint8:t(7,1)=(0,11)",128,0,14,0
	.stabs	"Uint16:t(7,2)=(0,9)",128,0,15,0
	.stabs	"Uint32:t(7,3)=(0,4)",128,0,16,0
	.stabn	162,0,0,0
	.stabs	"interface/sensor_set.h",130,0,0,0
	.stabs	" :T(8,1)=eWRONG_LEVEL:-2,VIDEOAPISET_FAIL:-1,VIDEOAPISET_SUCCESS:0,;",128,0,0,0
	.stabs	" :T(8,2)=ePROP_CONTRAST:0,PROP_BRIGHTNESS:1,PROP_SATURATION:2,PROP_SHARPNESS:3,PROP_HUE:4,PROP_GAMMA:5,PROP_WHITE_BALANCE:6,PROP_EXPOSURE:7,PROP_POWER_LINE_FREQ:8,;",128,0,0,0
	.stabs	"VIDEO_PROP_TYPE:t(8,3)=(8,2)",128,0,23,0
	.stabs	" :T(8,4)=ePROP_LEVEL_0:0,PROP_LEVEL_1:1,PROP_LEVEL_2:2,PROP_LEVEL_3:3,PROP_LEVEL_4:4,PROP_LEVEL_5:5,PROP_LEVEL_6:6,PROP_LEVEL_7:7,PROP_LEVEL_8:8,PROP_LEVEL_9:9,PROP_LEVEL_10:10,PROP_AUTO_ON:11,PROP_AUTO_OFF:12,PROP_DEFAULT:13,;",128,0,0,0
	.stabs	"VIDEO_PROP_LEVEL:t(8,5)=(8,4)",128,0,41,0
	.stabn	162,0,0,0
	.stabs	"interface/firmware_upload.h",130,0,0,0
	.stabs	" :T(9,1)=eFIRMWARE_OPERATION_FAIL:-1,FIRMWARE_OPERATION_SUCCESS:0,;",128,0,0,0
	.stabn	162,0,0,0
.proc _setCommandResponse
	.stabs	"setCommandResponse:F(0,15)",36,0,970,_setCommandResponse
	.stabs	"responseBuf:P(0,16)=*(0,2)",64,0,969,3
	.stabs	"responseLen:P(0,1)",64,0,969,4
	.global _setCommandResponse
	.type	_setCommandResponse, @function
_setCommandResponse:
	.stabd	46,0,0
	.stabn	68,0,970,.LM0-.LFBB1
.LM0:
.LFBB1:
	b.entri 	1,0
	.stabn	68,0,974,.LM1-.LFBB1
.LM1:
	b.blesi  	r4,0,.L2
	b.movi 	r6,0	     # movsi imm P
.L4:
	.stabn	68,0,970,.LM2-.LFBB1
.LM2:
	b.add   	r7,r3,r6
	.stabn	68,0,976,.LM3-.LFBB1
.LM3:
	b.lwz   	r7,0(r7)	    # movsi load
	bw.sw    	-251658112(r6),r7	   # movsi store
	.stabn	68,0,974,.LM4-.LFBB1
.LM4:
	b.addi  	r6,r6,4
	b.bgts   	r4,r6,.L4
.L2:
	.stabn	68,0,978,.LM5-.LFBB1
.LM5:
	b.slli  	r7,r4,17
	b.ori   	r7,r7,128
	bw.sw    	-804978596(r0),r7	   # movsi store
	.stabn	68,0,982,.LM6-.LFBB1
.LM6:
	b.jal  	_ep1_nack_toggle
	.stabn	68,0,988,.LM7-.LFBB1
.LM7:
	b.reti  	1,0
	.size	_setCommandResponse, .-_setCommandResponse
	.stabs	"i:r(0,1)",64,0,971,6
	.stabn	192,0,0,.LFBB1-.LFBB1
	.stabn	224,0,0,.Lscope1-.LFBB1
.Lscope1:
	.stabs	"",36,0,0,.Lscope1-.LFBB1
	.stabd	78,0,0
.proc _streamGetJpegLength
	.stabs	"streamGetJpegLength:F(0,15)",36,0,446,_streamGetJpegLength
	.stabs	"commandBuf:P(0,16)",64,0,445,3
	.global _streamGetJpegLength
	.type	_streamGetJpegLength, @function
_streamGetJpegLength:
	.stabd	46,0,0
	.stabn	68,0,446,.LM8-.LFBB2
.LM8:
.LFBB2:
	b.entri 	1,16
	.stabn	68,0,447,.LM9-.LFBB2
.LM9:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,0	     # movsi imm P
	b.ori  	r5,r0,64	  # movsi imm J
	b.jal  	_memset
	.stabn	68,0,450,.LM10-.LFBB2
.LM10:
	bw.lbz   	r7,(_jpegDualStreamBuf+20)(r0)
	b.extbs 	r7,r7
	b.blesi  	r7,0,.L8
	.stabn	68,0,458,.LM11-.LFBB2
.LM11:
	bw.lbz   	r7,(_jpegDualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.ori  	r6,r0,_jpegDualStreamBuf	  # movsi imm i
	b.slli  	r7,r7,2
	b.add   	r7,r7,r6
	b.lwz   	r25,0(r7)	    # movsi load
	.stabn	68,0,460,.LM12-.LFBB2
.LM12:
	bw.lbz   	r7,(_jpegDualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.slli  	r7,r7,2
	b.add   	r7,r7,r6
	b.lwz   	r24,0(r7)	    # movsi load
	.stabn	68,0,462,.LM13-.LFBB2
.LM13:
	bw.lbz   	r7,(_jpegDualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.slli  	r7,r7,2
	b.add   	r7,r7,r6
	b.lwz   	r23,0(r7)	    # movsi load
	.stabn	68,0,464,.LM14-.LFBB2
.LM14:
	bw.lbz   	r7,(_jpegDualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.slli  	r7,r7,2
	b.add   	r7,r7,r6
	b.lwz   	r5,0(r7)	    # movsi load
	.stabn	68,0,468,.LM15-.LFBB2
.LM15:
	bw.lbz   	r7,(_jpegDualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.slli  	r7,r7,2
	b.add   	r7,r7,r6
	b.lwz   	r7,0(r7)	    # movsi load
	b.addi 	r4,r0,16320	  # movsi imm I
	b.bgts   	r7,r4,.L12
	bw.lbz   	r7,(_jpegDualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.slli  	r7,r7,2
	b.addi  	r7,r7,_jpegDualStreamBuf
	b.lwz   	r4,0(r7)	    # movsi load
.L12:
	.stabn	68,0,452,.LM16-.LFBB2
.LM16:
	b.sb    	3(r1),r0	   # movqi store
	.stabn	68,0,453,.LM17-.LFBB2
.LM17:
	b.ori   	r7,r0,64	 # movqi imm J
	b.sb    	2(r1),r7	   # movqi store
	.stabn	68,0,454,.LM18-.LFBB2
.LM18:
	b.sb    	1(r1),r0	   # movqi store
	.stabn	68,0,455,.LM19-.LFBB2
.LM19:
	b.sb    	0(r1),r0	   # movqi store
	.stabn	68,0,458,.LM20-.LFBB2
.LM20:
	b.sb    	7(r1),r25	   # movqi store
	.stabn	68,0,460,.LM21-.LFBB2
.LM21:
	b.srli  	r7,r24,8
	b.sb    	6(r1),r7	   # movqi store
	.stabn	68,0,462,.LM22-.LFBB2
.LM22:
	b.srli  	r7,r23,16
	b.sb    	5(r1),r7	   # movqi store
	.stabn	68,0,464,.LM23-.LFBB2
.LM23:
	b.srli  	r7,r5,24
	b.sb    	4(r1),r7	   # movqi store
	.stabn	68,0,476,.LM24-.LFBB2
.LM24:
	bw.lbz   	r7,(_jpegDualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.ori  	r5,r0,_jpegDualStreamBuf	  # movsi imm i
	b.slli  	r7,r7,2
	b.add   	r7,r7,r5
	b.lwz   	r7,8(r7)	    # movsi load
	b.slli  	r6,r4,17
	b.andi  	r7,r7,131071
	b.or    	r6,r6,r7
	bw.sw    	-804978564(r0),r6	   # movsi store
	.stabn	68,0,491,.LM25-.LFBB2
.LM25:
	bw.lbz   	r7,(_jpegDualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.slli  	r7,r7,2
	b.add   	r7,r7,r5
	b.lwz   	r6,0(r7)	    # movsi load
	b.sub   	r6,r6,r4
	b.sw    	0(r7),r6	   # movsi store
	.stabn	68,0,492,.LM26-.LFBB2
.LM26:
	bw.lbz   	r7,(_jpegDualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.slli  	r7,r7,2
	b.add   	r7,r7,r5
	b.lwz   	r6,8(r7)	    # movsi load
	b.add   	r6,r6,r4
	b.sw    	8(r7),r6	   # movsi store
	b.j    	.L13
.L8:
	.stabn	68,0,500,.LM27-.LFBB2
.LM27:
	b.movi  	r7,-4	    # movqi imm P
	b.sb    	3(r1),r7	   # movqi store
	.stabn	68,0,501,.LM28-.LFBB2
.LM28:
	b.ori   	r7,r0,64	 # movqi imm J
	b.sb    	2(r1),r7	   # movqi store
	.stabn	68,0,502,.LM29-.LFBB2
.LM29:
	b.sb    	1(r1),r0	   # movqi store
	.stabn	68,0,503,.LM30-.LFBB2
.LM30:
	b.sb    	0(r1),r0	   # movqi store
	.stabn	68,0,504,.LM31-.LFBB2
.LM31:
	b.sb    	7(r1),r0	   # movqi store
	.stabn	68,0,505,.LM32-.LFBB2
.LM32:
	b.sb    	6(r1),r0	   # movqi store
	.stabn	68,0,506,.LM33-.LFBB2
.LM33:
	b.sb    	5(r1),r0	   # movqi store
	.stabn	68,0,507,.LM34-.LFBB2
.LM34:
	b.sb    	4(r1),r0	   # movqi store
.L13:
	.stabn	68,0,511,.LM35-.LFBB2
.LM35:
	b.mov  	r3,r1	     # movsi
	b.ori  	r4,r0,8	  # movsi imm J
	b.jal  	_setCommandResponse
	.stabn	68,0,514,.LM36-.LFBB2
.LM36:
	b.reti  	1,16
	.size	_streamGetJpegLength, .-_streamGetJpegLength
	.stabs	"responseBuf:(0,17)=ar(4,4);0;63;(0,2)",128,0,447,0
	.stabs	"packet_len:r(0,1)",64,0,449,4
	.stabn	192,0,0,.LFBB2-.LFBB2
	.stabn	224,0,0,.Lscope2-.LFBB2
.Lscope2:
	.stabs	"",36,0,0,.Lscope2-.LFBB2
	.stabd	78,0,0
.proc _hifRegisterBitReset
	.stabs	"hifRegisterBitReset:F(0,15)",36,0,314,_hifRegisterBitReset
	.stabs	"commandBuf:P(0,16)",64,0,313,10
	.global _hifRegisterBitReset
	.type	_hifRegisterBitReset, @function
_hifRegisterBitReset:
	.stabd	46,0,0
	.stabn	68,0,314,.LM37-.LFBB3
.LM37:
.LFBB3:
	b.entri 	3,16
	b.mov  	r10,r3	     # movsi
	.stabn	68,0,315,.LM38-.LFBB3
.LM38:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,0	     # movsi imm P
	b.ori  	r5,r0,64	  # movsi imm J
	b.jal  	_memset
	.stabn	68,0,322,.LM39-.LFBB3
.LM39:
	b.lbz   	r5,2(r10)
	b.slli  	r5,r5,2
	bw.lwz   	r6,-536735744(r5)	    # movsi load
	.stabn	68,0,323,.LM40-.LFBB3
.LM40:
	b.lbz   	r4,0(r10)
	b.lbz   	r23,1(r10)
	b.and   	r7,r4,r23
	.stabn	68,0,324,.LM41-.LFBB3
.LM41:
	b.nand  	r7,r7,r7
	b.and   	r6,r6,r7
	b.extbz 	r6,r6
	bw.sw    	-536735744(r5),r6	   # movsi store
	.stabn	68,0,327,.LM42-.LFBB3
.LM42:
	b.sb    	3(r1),r0	   # movqi store
	.stabn	68,0,328,.LM43-.LFBB3
.LM43:
	b.ori   	r7,r0,35	 # movqi imm J
	b.sb    	2(r1),r7	   # movqi store
	.stabn	68,0,331,.LM44-.LFBB3
.LM44:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,2	     # movsi imm P
	b.jal  	_setCommandResponse
	.stabn	68,0,334,.LM45-.LFBB3
.LM45:
	b.reti  	3,16
	.size	_hifRegisterBitReset, .-_hifRegisterBitReset
	.stabs	"responseBuf:(0,17)",128,0,315,0
	.stabn	192,0,0,.LFBB3-.LFBB3
	.stabn	224,0,0,.Lscope3-.LFBB3
.Lscope3:
	.stabs	"",36,0,0,.Lscope3-.LFBB3
	.stabd	78,0,0
.proc _hifRegisterBitSet
	.stabs	"hifRegisterBitSet:F(0,15)",36,0,287,_hifRegisterBitSet
	.stabs	"commandBuf:P(0,16)",64,0,286,10
	.global _hifRegisterBitSet
	.type	_hifRegisterBitSet, @function
_hifRegisterBitSet:
	.stabd	46,0,0
	.stabn	68,0,287,.LM46-.LFBB4
.LM46:
.LFBB4:
	b.entri 	3,16
	b.mov  	r10,r3	     # movsi
	.stabn	68,0,288,.LM47-.LFBB4
.LM47:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,0	     # movsi imm P
	b.ori  	r5,r0,64	  # movsi imm J
	b.jal  	_memset
	.stabn	68,0,295,.LM48-.LFBB4
.LM48:
	b.lbz   	r6,2(r10)
	b.slli  	r6,r6,2
	bw.lwz   	r5,-536735744(r6)	    # movsi load
	.stabn	68,0,296,.LM49-.LFBB4
.LM49:
	b.lbz   	r4,0(r10)
	b.lbz   	r23,1(r10)
	b.and   	r7,r4,r23
	.stabn	68,0,297,.LM50-.LFBB4
.LM50:
	b.or    	r7,r7,r5
	b.extbz 	r7,r7
	bw.sw    	-536735744(r6),r7	   # movsi store
	.stabn	68,0,300,.LM51-.LFBB4
.LM51:
	b.sb    	3(r1),r0	   # movqi store
	.stabn	68,0,301,.LM52-.LFBB4
.LM52:
	b.ori   	r7,r0,34	 # movqi imm J
	b.sb    	2(r1),r7	   # movqi store
	.stabn	68,0,305,.LM53-.LFBB4
.LM53:
	b.lbz   	r7,2(r10)
	b.extbs 	r7,r7
	b.ori  	r4,r0,62	  # movsi imm J
	b.beq   	r7,r4,.L20
	b.ori  	r6,r0,66	  # movsi imm J
	b.beq   	r7,r6,.L20
	.stabn	68,0,308,.LM54-.LFBB4
.LM54:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,2	     # movsi imm P
	b.jal  	_setCommandResponse
.L20:
	.stabn	68,0,311,.LM55-.LFBB4
.LM55:
	b.reti  	3,16
	.size	_hifRegisterBitSet, .-_hifRegisterBitSet
	.stabs	"responseBuf:(0,17)",128,0,288,0
	.stabn	192,0,0,.LFBB4-.LFBB4
	.stabn	224,0,0,.Lscope4-.LFBB4
.Lscope4:
	.stabs	"",36,0,0,.Lscope4-.LFBB4
	.stabd	78,0,0
.proc _internalRegisterWrite
	.stabs	"internalRegisterWrite:F(0,15)",36,0,181,_internalRegisterWrite
	.stabs	"commandBuf:P(0,16)",64,0,180,10
	.global _internalRegisterWrite
	.type	_internalRegisterWrite, @function
_internalRegisterWrite:
	.stabd	46,0,0
	.stabn	68,0,181,.LM56-.LFBB5
.LM56:
.LFBB5:
	b.entri 	2,16
	b.mov  	r10,r3	     # movsi
	.stabn	68,0,182,.LM57-.LFBB5
.LM57:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,0	     # movsi imm P
	b.ori  	r5,r0,64	  # movsi imm J
	b.jal  	_memset
	.stabn	68,0,185,.LM58-.LFBB5
.LM58:
	b.lbz   	r7,0(r10)
	b.extbs 	r4,r7
	.stabn	68,0,186,.LM59-.LFBB5
.LM59:
	b.lwz   	r7,4(r10)	    # movsi load
	.stabn	68,0,190,.LM60-.LFBB5
.LM60:
	b.blesi  	r4,0,.L22
	b.addi  	r3,r10,8
	b.mov  	r6,r7	     # movsi
	b.movi 	r5,0	     # movsi imm P
.L24:
	.stabn	68,0,192,.LM61-.LFBB5
.LM61:
	b.lwz   	r7,0(r3)	    # movsi load
	b.sw    	0(r6),r7	   # movsi store
	.stabn	68,0,190,.LM62-.LFBB5
.LM62:
	b.addi  	r5,r5,1
	b.addi  	r3,r3,4
	b.addi  	r6,r6,4
	b.bne   	r5,r4,.L24
.L22:
	.stabn	68,0,196,.LM63-.LFBB5
.LM63:
	b.sb    	3(r1),r0	   # movqi store
	.stabn	68,0,197,.LM64-.LFBB5
.LM64:
	b.ori   	r7,r0,17	 # movqi imm J
	b.sb    	2(r1),r7	   # movqi store
	.stabn	68,0,200,.LM65-.LFBB5
.LM65:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,2	     # movsi imm P
	b.jal  	_setCommandResponse
	.stabn	68,0,203,.LM66-.LFBB5
.LM66:
	b.reti  	2,16
	.size	_internalRegisterWrite, .-_internalRegisterWrite
	.stabs	"responseBuf:(0,17)",128,0,182,0
	.stabs	"registerAddress:r(0,1)",64,0,186,7
	.stabs	"i:r(0,1)",64,0,188,5
	.stabn	192,0,0,.LFBB5-.LFBB5
	.stabn	224,0,0,.Lscope5-.LFBB5
.Lscope5:
	.stabs	"",36,0,0,.Lscope5-.LFBB5
	.stabd	78,0,0
.proc _internalRegisterRead
	.stabs	"internalRegisterRead:F(0,15)",36,0,153,_internalRegisterRead
	.stabs	"commandBuf:P(0,16)",64,0,152,10
	.global _internalRegisterRead
	.type	_internalRegisterRead, @function
_internalRegisterRead:
	.stabd	46,0,0
	.stabn	68,0,153,.LM67-.LFBB6
.LM67:
.LFBB6:
	b.entri 	2,16
	b.mov  	r10,r3	     # movsi
	.stabn	68,0,154,.LM68-.LFBB6
.LM68:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,0	     # movsi imm P
	b.ori  	r5,r0,64	  # movsi imm J
	b.jal  	_memset
	.stabn	68,0,157,.LM69-.LFBB6
.LM69:
	b.lbz   	r7,0(r10)
	b.extbs 	r24,r7
	.stabn	68,0,158,.LM70-.LFBB6
.LM70:
	b.lwz   	r7,4(r10)	    # movsi load
	.stabn	68,0,162,.LM71-.LFBB6
.LM71:
	b.movi 	r4,0	     # movsi imm P
	b.blesi  	r24,0,.L30
	b.mov  	r6,r7	     # movsi
	.stabn	68,0,153,.LM72-.LFBB6
.LM72:
	b.addi  	r23,r1,4
	b.movi 	r5,0	     # movsi imm P
.L31:
	.stabn	68,0,164,.LM73-.LFBB6
.LM73:
	b.addi  	r5,r5,1
	b.lwz   	r7,0(r6)	    # movsi load
	b.sw    	0(r23),r7	   # movsi store
	b.slli  	r4,r5,2
	b.addi  	r6,r6,4
	b.addi  	r23,r23,4
	.stabn	68,0,162,.LM74-.LFBB6
.LM74:
	b.bne   	r5,r24,.L31
.L30:
	.stabn	68,0,169,.LM75-.LFBB6
.LM75:
	b.sb    	3(r1),r0	   # movqi store
	.stabn	68,0,170,.LM76-.LFBB6
.LM76:
	b.ori   	r7,r0,16	 # movqi imm J
	b.sb    	2(r1),r7	   # movqi store
	.stabn	68,0,171,.LM77-.LFBB6
.LM77:
	b.sb    	1(r1),r0	   # movqi store
	.stabn	68,0,172,.LM78-.LFBB6
.LM78:
	b.sb    	0(r1),r24	   # movqi store
	.stabn	68,0,175,.LM79-.LFBB6
.LM79:
	b.mov  	r3,r1	     # movsi
	b.addi  	r4,r4,4
	b.jal  	_setCommandResponse
	.stabn	68,0,178,.LM80-.LFBB6
.LM80:
	b.reti  	2,16
	.size	_internalRegisterRead, .-_internalRegisterRead
	.stabs	"responseBuf:(0,17)",128,0,154,0
	.stabs	"registerAddress:r(0,1)",64,0,158,7
	.stabs	"i:r(0,1)",64,0,160,5
	.stabn	192,0,0,.LFBB6-.LFBB6
	.stabn	224,0,0,.Lscope6-.LFBB6
.Lscope6:
	.stabs	"",36,0,0,.Lscope6-.LFBB6
	.stabd	78,0,0
.proc _firmware_version_check
	.stabs	"firmware_version_check:F(0,15)",36,0,943,_firmware_version_check
	.stabs	"commandBuf:P(0,16)",64,0,942,3
	.global _firmware_version_check
	.type	_firmware_version_check, @function
_firmware_version_check:
	.stabd	46,0,0
	.stabn	68,0,943,.LM81-.LFBB7
.LM81:
.LFBB7:
	b.entri 	1,16
	.stabn	68,0,944,.LM82-.LFBB7
.LM82:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,0	     # movsi imm P
	b.ori  	r5,r0,64	  # movsi imm J
	b.jal  	_memset
	.stabn	68,0,949,.LM83-.LFBB7
.LM83:
	b.addi  	r3,r1,4
	b.jal  	_firmwareVersionCheck
	.stabn	68,0,952,.LM84-.LFBB7
.LM84:
	b.bnei  	r3,0,.L35
	.stabn	68,0,953,.LM85-.LFBB7
.LM85:
	b.sb    	3(r1),r0	   # movqi store
	b.j    	.L37
.L35:
	.stabn	68,0,955,.LM86-.LFBB7
.LM86:
	b.addi  	r7,r0,-9	 # movqi imm N
	b.sb    	3(r1),r7	   # movqi store
.L37:
	.stabn	68,0,957,.LM87-.LFBB7
.LM87:
	b.ori   	r7,r0,87	 # movqi imm J
	b.sb    	2(r1),r7	   # movqi store
	.stabn	68,0,958,.LM88-.LFBB7
.LM88:
	b.sb    	1(r1),r3	   # movqi store
	.stabn	68,0,961,.LM89-.LFBB7
.LM89:
	b.mov  	r3,r1	     # movsi
	b.ori  	r4,r0,64	  # movsi imm J
	b.jal  	_setCommandResponse
	.stabn	68,0,964,.LM90-.LFBB7
.LM90:
	b.reti  	1,16
	.size	_firmware_version_check, .-_firmware_version_check
	.stabs	"responseBuf:(0,17)",128,0,944,0
	.stabs	"ret:r(0,1)",64,0,947,3
	.stabn	192,0,0,.LFBB7-.LFBB7
	.stabn	224,0,0,.Lscope7-.LFBB7
.Lscope7:
	.stabs	"",36,0,0,.Lscope7-.LFBB7
	.stabd	78,0,0
.proc _firmware_upload
	.stabs	"firmware_upload:F(0,15)",36,0,917,_firmware_upload
	.stabs	"commandBuf:P(0,16)",64,0,916,3
	.global _firmware_upload
	.type	_firmware_upload, @function
_firmware_upload:
	.stabd	46,0,0
	.stabn	68,0,917,.LM91-.LFBB8
.LM91:
.LFBB8:
	b.entri 	1,0
	.stabn	68,0,923,.LM92-.LFBB8
.LM92:
	b.lbz   	r3,0(r3)
	b.jal  	_firmwareUpload
	.stabn	68,0,940,.LM93-.LFBB8
.LM93:
	b.reti  	1,0
	.size	_firmware_upload, .-_firmware_upload
.Lscope8:
	.stabs	"",36,0,0,.Lscope8-.LFBB8
	.stabd	78,0,0
.proc _firmware_set_length
	.stabs	"firmware_set_length:F(0,15)",36,0,885,_firmware_set_length
	.stabs	"commandBuf:P(0,16)",64,0,884,10
	.global _firmware_set_length
	.type	_firmware_set_length, @function
_firmware_set_length:
	.stabd	46,0,0
	.stabn	68,0,885,.LM94-.LFBB9
.LM94:
.LFBB9:
	b.entri 	2,16
	b.mov  	r10,r3	     # movsi
	.stabn	68,0,886,.LM95-.LFBB9
.LM95:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,0	     # movsi imm P
	b.ori  	r5,r0,64	  # movsi imm J
	b.jal  	_memset
	.stabn	68,0,899,.LM96-.LFBB9
.LM96:
	b.lbz   	r4,1(r10)
	b.extbs 	r4,r4
	b.exthz 	r4,r4
	b.slli  	r4,r4,8
	b.lbz   	r7,0(r10)
	b.or    	r4,r4,r7
	b.lbz   	r3,2(r10)
	b.exthz 	r4,r4
	b.jal  	_firmwareSetLength
	.stabn	68,0,902,.LM97-.LFBB9
.LM97:
	b.bnei  	r3,0,.L42
	.stabn	68,0,903,.LM98-.LFBB9
.LM98:
	b.sb    	3(r1),r0	   # movqi store
	b.j    	.L44
.L42:
	.stabn	68,0,905,.LM99-.LFBB9
.LM99:
	b.movi  	r7,-7	    # movqi imm P
	b.sb    	3(r1),r7	   # movqi store
.L44:
	.stabn	68,0,907,.LM100-.LFBB9
.LM100:
	b.ori   	r7,r0,85	 # movqi imm J
	b.sb    	2(r1),r7	   # movqi store
	.stabn	68,0,908,.LM101-.LFBB9
.LM101:
	b.sb    	1(r1),r3	   # movqi store
	.stabn	68,0,911,.LM102-.LFBB9
.LM102:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,3	     # movsi imm P
	b.jal  	_setCommandResponse
	.stabn	68,0,914,.LM103-.LFBB9
.LM103:
	b.reti  	2,16
	.size	_firmware_set_length, .-_firmware_set_length
	.stabs	"responseBuf:(0,17)",128,0,886,0
	.stabs	"ret:r(0,1)",64,0,889,3
	.stabn	192,0,0,.LFBB9-.LFBB9
	.stabn	224,0,0,.Lscope9-.LFBB9
.Lscope9:
	.stabs	"",36,0,0,.Lscope9-.LFBB9
	.stabd	78,0,0
.proc _firmware_sdram_write
	.stabs	"firmware_sdram_write:F(0,15)",36,0,856,_firmware_sdram_write
	.stabs	"commandBuf:P(0,16)",64,0,855,10
	.global _firmware_sdram_write
	.type	_firmware_sdram_write, @function
_firmware_sdram_write:
	.stabd	46,0,0
	.stabn	68,0,856,.LM104-.LFBB10
.LM104:
.LFBB10:
	b.entri 	2,16
	b.mov  	r10,r3	     # movsi
	.stabn	68,0,857,.LM105-.LFBB10
.LM105:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,0	     # movsi imm P
	b.ori  	r5,r0,64	  # movsi imm J
	b.jal  	_memset
	.stabn	68,0,867,.LM106-.LFBB10
.LM106:
	b.lbz   	r6,2(r10)
	b.slli  	r3,r6,16
	b.lbz   	r6,1(r10)
	b.slli  	r7,r6,8
	b.or    	r3,r3,r7
	b.lbz   	r7,0(r10)
	b.or    	r3,r3,r7
	b.addi  	r4,r10,4
	b.jal  	_firmwareSdramWrite
	.stabn	68,0,873,.LM107-.LFBB10
.LM107:
	b.sb    	3(r1),r0	   # movqi store
	.stabn	68,0,875,.LM108-.LFBB10
.LM108:
	b.ori   	r7,r0,84	 # movqi imm J
	b.sb    	2(r1),r7	   # movqi store
	.stabn	68,0,876,.LM109-.LFBB10
.LM109:
	b.sb    	1(r1),r3	   # movqi store
	.stabn	68,0,879,.LM110-.LFBB10
.LM110:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,3	     # movsi imm P
	b.jal  	_setCommandResponse
	.stabn	68,0,882,.LM111-.LFBB10
.LM111:
	b.reti  	2,16
	.size	_firmware_sdram_write, .-_firmware_sdram_write
	.stabs	"responseBuf:(0,17)",128,0,857,0
	.stabn	192,0,0,.LFBB10-.LFBB10
	.stabn	224,0,0,.Lscope10-.LFBB10
.Lscope10:
	.stabs	"",36,0,0,.Lscope10-.LFBB10
	.stabd	78,0,0
.proc _videoApiSet
	.stabs	"videoApiSet:F(0,15)",36,0,833,_videoApiSet
	.stabs	"commandBuf:P(0,16)",64,0,832,10
	.global _videoApiSet
	.type	_videoApiSet, @function
_videoApiSet:
	.stabd	46,0,0
	.stabn	68,0,833,.LM112-.LFBB11
.LM112:
.LFBB11:
	b.entri 	2,16
	b.mov  	r10,r3	     # movsi
	.stabn	68,0,834,.LM113-.LFBB11
.LM113:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,0	     # movsi imm P
	b.ori  	r5,r0,64	  # movsi imm J
	b.jal  	_memset
	.stabn	68,0,839,.LM114-.LFBB11
.LM114:
	b.lbz   	r3,1(r10)
	b.lbz   	r4,0(r10)
	b.extbs 	r3,r3
	b.extbs 	r4,r4
	b.jal  	_videoApiControl
	.stabn	68,0,841,.LM115-.LFBB11
.LM115:
	b.bnei  	r3,0,.L52
	.stabn	68,0,842,.LM116-.LFBB11
.LM116:
	b.sb    	3(r1),r0	   # movqi store
	b.j    	.L54
.L52:
	.stabn	68,0,844,.LM117-.LFBB11
.LM117:
	b.movi  	r7,-5	    # movqi imm P
	b.sb    	3(r1),r7	   # movqi store
.L54:
	.stabn	68,0,846,.LM118-.LFBB11
.LM118:
	b.ori   	r7,r0,96	 # movqi imm J
	b.sb    	2(r1),r7	   # movqi store
	.stabn	68,0,847,.LM119-.LFBB11
.LM119:
	b.sb    	1(r1),r3	   # movqi store
	.stabn	68,0,850,.LM120-.LFBB11
.LM120:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,3	     # movsi imm P
	b.jal  	_setCommandResponse
	.stabn	68,0,853,.LM121-.LFBB11
.LM121:
	b.reti  	2,16
	.size	_videoApiSet, .-_videoApiSet
	.stabs	"responseBuf:(0,17)",128,0,834,0
	.stabs	"videoApicRet:r(0,1)",64,0,837,3
	.stabn	192,0,0,.LFBB11-.LFBB11
	.stabn	224,0,0,.Lscope11-.LFBB11
.Lscope11:
	.stabs	"",36,0,0,.Lscope11-.LFBB11
	.stabd	78,0,0
.proc _commandAudioStop
	.stabs	"commandAudioStop:F(0,15)",36,0,806,_commandAudioStop
	.stabs	"commandBuf:P(0,16)",64,0,805,3
	.global _commandAudioStop
	.type	_commandAudioStop, @function
_commandAudioStop:
	.stabd	46,0,0
	.stabn	68,0,806,.LM122-.LFBB12
.LM122:
.LFBB12:
	b.entri 	1,16
	.stabn	68,0,807,.LM123-.LFBB12
.LM123:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,0	     # movsi imm P
	b.ori  	r5,r0,64	  # movsi imm J
	b.jal  	_memset
	.stabn	68,0,810,.LM124-.LFBB12
.LM124:
	bw.lwz   	r7,(_isAudioStarted)(r0)	    # movsi load
	b.beqi  	r7,0,.L57
	.stabn	68,0,813,.LM125-.LFBB12
.LM125:
	bw.sw    	(_isAudioStarted)(r0),r0	   # movsi store
	.stabn	68,0,814,.LM126-.LFBB12
.LM126:
	b.jal  	_init_audio_streamBuf
.L59:
	.stabn	68,0,815,.LM127-.LFBB12
.LM127:
	bw.lwz   	r7,-804913140(r0)	    # movsi load
	b.srai  	r7,r7,16
	b.andi  	r7,r7,3
	b.bnei  	r7,0,.L59
	.stabn	68,0,816,.LM128-.LFBB12
.LM128:
	b.ori  	r3,r0,-804913152	  # movsi imm i
	b.ori  	r4,r0,-2147483648	  # movsi imm i
	b.jal  	_I2S_RegClr
	.stabn	68,0,817,.LM129-.LFBB12
.LM129:
	b.addi 	r3,r0,4096	  # movsi imm I
	b.jal  	_IntDisable
	.stabn	68,0,818,.LM130-.LFBB12
.LM130:
	bw.sw    	(_pcm_exist)(r0),r0	   # movsi store
	.stabn	68,0,820,.LM131-.LFBB12
.LM131:
	bw.lwz   	r7,(_isVideoStarted)(r0)	    # movsi load
	b.bnei  	r7,0,.L57
	.stabn	68,0,821,.LM132-.LFBB12
.LM132:
	b.addi 	r3,r0,4096	  # movsi imm I
	b.jal  	_GPIOSetHigh
.L57:
	.stabn	68,0,823,.LM133-.LFBB12
.LM133:
	b.sb    	3(r1),r0	   # movqi store
	.stabn	68,0,824,.LM134-.LFBB12
.LM134:
	b.ori   	r7,r0,83	 # movqi imm J
	b.sb    	2(r1),r7	   # movqi store
	.stabn	68,0,827,.LM135-.LFBB12
.LM135:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,2	     # movsi imm P
	b.jal  	_setCommandResponse
	.stabn	68,0,830,.LM136-.LFBB12
.LM136:
	b.reti  	1,16
	.size	_commandAudioStop, .-_commandAudioStop
	.stabs	"responseBuf:(0,17)",128,0,807,0
	.stabn	192,0,0,.LFBB12-.LFBB12
	.stabn	224,0,0,.Lscope12-.LFBB12
.Lscope12:
	.stabs	"",36,0,0,.Lscope12-.LFBB12
	.stabd	78,0,0
.proc _hifRegisterRead
	.stabs	"hifRegisterRead:F(0,15)",36,0,206,_hifRegisterRead
	.stabs	"commandBuf:P(0,16)",64,0,205,10
	.global _hifRegisterRead
	.type	_hifRegisterRead, @function
_hifRegisterRead:
	.stabd	46,0,0
	.stabn	68,0,206,.LM137-.LFBB13
.LM137:
.LFBB13:
	b.entri 	2,16
	b.mov  	r10,r3	     # movsi
	.stabn	68,0,207,.LM138-.LFBB13
.LM138:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,0	     # movsi imm P
	b.ori  	r5,r0,64	  # movsi imm J
	b.jal  	_memset
	.stabn	68,0,210,.LM139-.LFBB13
.LM139:
	b.lbz   	r7,0(r10)
	b.extbs 	r23,r7
	.stabn	68,0,211,.LM140-.LFBB13
.LM140:
	b.addi  	r24,r10,2
	b.lbz   	r7,2(r10)
	b.slli  	r7,r7,2
	b.addi  	r7,r7,-536735744
	.stabn	68,0,215,.LM141-.LFBB13
.LM141:
	b.movi 	r10,0	     # movsi imm P
	b.blesi  	r23,0,.L68
	b.mov  	r4,r7	     # movsi
	b.movi 	r10,0	     # movsi imm P
.L69:
	.stabn	68,0,217,.LM142-.LFBB13
.LM142:
	b.lwz   	r7,0(r4)	    # movsi load
	b.srai  	r6,r10,2
	b.movi 	r5,7	     # movsi imm P
	b.sub   	r5,r5,r10
	b.slli  	r6,r6,3
	b.addi  	r25,r1,64
	b.add   	r6,r6,r25
	b.add   	r6,r6,r5
	bg.sb    	-64(r6),r7	   # movqi store
	.stabn	68,0,219,.LM143-.LFBB13
.LM143:
	b.addi  	r10,r10,1
	b.addi  	r4,r4,4
	.stabn	68,0,215,.LM144-.LFBB13
.LM144:
	b.bne   	r10,r23,.L69
.L68:
	.stabn	68,0,223,.LM145-.LFBB13
.LM145:
	b.sb    	3(r1),r0	   # movqi store
	.stabn	68,0,224,.LM146-.LFBB13
.LM146:
	b.ori   	r7,r0,32	 # movqi imm J
	b.sb    	2(r1),r7	   # movqi store
	.stabn	68,0,225,.LM147-.LFBB13
.LM147:
	b.lbz   	r7,0(r24)
	b.extbs 	r7,r7
	b.sb    	1(r1),r7	   # movqi store
	.stabn	68,0,226,.LM148-.LFBB13
.LM148:
	b.sb    	0(r1),r23	   # movqi store
	.stabn	68,0,230,.LM149-.LFBB13
.LM149:
	b.ori  	r6,r0,11	  # movsi imm J
	b.bne   	r7,r6,.L70
	.stabn	68,0,231,.LM150-.LFBB13
.LM150:
	b.addi 	r3,r0,4096	  # movsi imm I
	b.jal  	_GPIOSetHigh
.L70:
	.stabn	68,0,233,.LM151-.LFBB13
.LM151:
	b.mov  	r3,r1	     # movsi
	b.addi  	r4,r10,4
	b.jal  	_setCommandResponse
	.stabn	68,0,236,.LM152-.LFBB13
.LM152:
	b.reti  	2,16
	.size	_hifRegisterRead, .-_hifRegisterRead
	.stabs	"responseBuf:(0,17)",128,0,207,0
	.stabs	"responseLen:r(0,1)",64,0,208,10
	.stabn	192,0,0,.LFBB13-.LFBB13
	.stabn	224,0,0,.Lscope13-.LFBB13
.Lscope13:
	.stabs	"",36,0,0,.Lscope13-.LFBB13
	.stabd	78,0,0
.proc _commandAudioStart
	.stabs	"commandAudioStart:F(0,15)",36,0,756,_commandAudioStart
	.stabs	"commandBuf:P(0,16)",64,0,755,3
	.global _commandAudioStart
	.type	_commandAudioStart, @function
_commandAudioStart:
	.stabd	46,0,0
	.stabn	68,0,756,.LM153-.LFBB14
.LM153:
.LFBB14:
	b.entri 	1,18
	.stabn	68,0,757,.LM154-.LFBB14
.LM154:
	b.addi  	r3,r1,8
	b.movi 	r4,0	     # movsi imm P
	b.ori  	r5,r0,64	  # movsi imm J
	b.jal  	_memset
	.stabn	68,0,759,.LM155-.LFBB14
.LM155:
	b.sw    	4(r1),r0	   # movsi store
	.stabn	68,0,763,.LM156-.LFBB14
.LM156:
	bw.lwz   	r7,(_isAudioStarted)(r0)	    # movsi load
	b.bnei  	r7,0,.L75
	.stabn	68,0,766,.LM157-.LFBB14
.LM157:
	bw.lwz   	r7,-536735716(r0)	    # movsi load
	b.andi  	r7,r7,3
	b.bnei  	r7,1,.L77
	.stabn	68,0,768,.LM158-.LFBB14
.LM158:
	bw.lwz   	r6,-536735492(r0)	    # movsi load
	b.movi 	r3,1	     # movsi imm P
	b.ori  	r4,r0,102	  # movsi imm J
	b.movi 	r5,1	     # movsi imm P
	b.extbz 	r6,r6
	b.jal  	_AIC3101Init
	b.j    	.L79
.L77:
	.stabn	68,0,773,.LM159-.LFBB14
.LM159:
	bw.lwz   	r6,-536735492(r0)	    # movsi load
	b.movi 	r3,1	     # movsi imm P
	b.ori  	r4,r0,68	  # movsi imm J
	b.movi 	r5,1	     # movsi imm P
	b.extbz 	r6,r6
	b.jal  	_AIC3101Init
.L79:
	.stabn	68,0,777,.LM160-.LFBB14
.LM160:
	b.movi 	r7,1	     # movsi imm P
	bw.sw    	(_isAudioStarted)(r0),r7	   # movsi store
	.stabn	68,0,779,.LM161-.LFBB14
.LM161:
	bw.lwz   	r7,-804913140(r0)	    # movsi load
	b.srai  	r5,r7,16
	.stabn	68,0,780,.LM162-.LFBB14
.LM162:
	b.blesi  	r5,0,.L80
	b.movi 	r6,0	     # movsi imm P
.L82:
	.stabn	68,0,782,.LM163-.LFBB14
.LM163:
	bw.lwz   	r7,-804909056(r0)	    # movsi load
	b.sw    	4(r1),r7	   # movsi store
	.stabn	68,0,781,.LM164-.LFBB14
.LM164:
	b.addi  	r6,r6,4
	.stabn	68,0,780,.LM165-.LFBB14
.LM165:
	b.bgts   	r5,r6,.L82
.L80:
	.stabn	68,0,784,.LM166-.LFBB14
.LM166:
	bw.sw    	(_pcm_exist)(r0),r0	   # movsi store
	.stabn	68,0,786,.LM167-.LFBB14
.LM167:
	b.jal  	_init_audio_streamBuf
	.stabn	68,0,789,.LM168-.LFBB14
.LM168:
	b.ori  	r3,r0,32768	  # movsi imm i
	b.jal  	_GPIOIntEnable
	.stabn	68,0,791,.LM169-.LFBB14
.LM169:
	b.addi 	r3,r0,6144	  # movsi imm I
	b.jal  	_IntEnable
	.stabn	68,0,793,.LM170-.LFBB14
.LM170:
	b.addi 	r3,r0,4096	  # movsi imm I
	b.jal  	_GPIOSetLow
.L75:
	.stabn	68,0,796,.LM171-.LFBB14
.LM171:
	b.sb    	11(r1),r0	   # movqi store
	.stabn	68,0,797,.LM172-.LFBB14
.LM172:
	b.ori   	r7,r0,82	 # movqi imm J
	b.sb    	10(r1),r7	   # movqi store
	.stabn	68,0,800,.LM173-.LFBB14
.LM173:
	b.addi  	r3,r1,8
	b.movi 	r4,2	     # movsi imm P
	b.jal  	_setCommandResponse
	.stabn	68,0,803,.LM174-.LFBB14
.LM174:
	b.reti  	1,18
	.size	_commandAudioStart, .-_commandAudioStart
	.stabs	"responseBuf:(0,17)",128,0,757,8
	.stabs	"temp:(3,6)",128,0,759,4
	.stabs	"pcmDataCnt:r(0,1)",64,0,760,5
	.stabs	"pcmDataCnt_i:r(0,1)",64,0,761,6
	.stabn	192,0,0,.LFBB14-.LFBB14
	.stabn	224,0,0,.Lscope14-.LFBB14
.Lscope14:
	.stabs	"",36,0,0,.Lscope14-.LFBB14
	.stabd	78,0,0
.proc _commandVideoStop
	.stabs	"commandVideoStop:F(0,15)",36,0,732,_commandVideoStop
	.stabs	"commandBuf:P(0,16)",64,0,731,3
	.global _commandVideoStop
	.type	_commandVideoStop, @function
_commandVideoStop:
	.stabd	46,0,0
	.stabn	68,0,732,.LM175-.LFBB15
.LM175:
.LFBB15:
	b.entri 	1,16
	.stabn	68,0,733,.LM176-.LFBB15
.LM176:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,0	     # movsi imm P
	b.ori  	r5,r0,64	  # movsi imm J
	b.jal  	_memset
	.stabn	68,0,737,.LM177-.LFBB15
.LM177:
	bw.lwz   	r7,(_isVideoStarted)(r0)	    # movsi load
	b.beqi  	r7,0,.L86
	.stabn	68,0,739,.LM178-.LFBB15
.LM178:
	bw.sw    	(_isVideoStarted)(r0),r0	   # movsi store
	.stabn	68,0,740,.LM179-.LFBB15
.LM179:
	b.movi 	r7,1	     # movsi imm P
	bw.sw    	(_command_video_stop)(r0),r7	   # movsi store
	.stabn	68,0,741,.LM180-.LFBB15
.LM180:
	b.jal  	_init_video_streamBuf
	.stabn	68,0,742,.LM181-.LFBB15
.LM181:
	bw.lwz   	r3,(_pH264StreamSem)(r0)	    # movsi load
	b.jal  	_OSSemPost
.L86:
	.stabn	68,0,745,.LM182-.LFBB15
.LM182:
	b.sb    	3(r1),r0	   # movqi store
	.stabn	68,0,746,.LM183-.LFBB15
.LM183:
	b.ori   	r7,r0,81	 # movqi imm J
	b.sb    	2(r1),r7	   # movqi store
	.stabn	68,0,749,.LM184-.LFBB15
.LM184:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,2	     # movsi imm P
	b.jal  	_setCommandResponse
	.stabn	68,0,752,.LM185-.LFBB15
.LM185:
	b.reti  	1,16
	.size	_commandVideoStop, .-_commandVideoStop
	.stabs	"responseBuf:(0,17)",128,0,733,0
	.stabn	192,0,0,.LFBB15-.LFBB15
	.stabn	224,0,0,.Lscope15-.LFBB15
.Lscope15:
	.stabs	"",36,0,0,.Lscope15-.LFBB15
	.stabd	78,0,0
.proc _commandVideoStart
	.stabs	"commandVideoStart:F(0,15)",36,0,700,_commandVideoStart
	.stabs	"commandBuf:P(0,16)",64,0,699,3
	.global _commandVideoStart
	.type	_commandVideoStart, @function
_commandVideoStart:
	.stabd	46,0,0
	.stabn	68,0,700,.LM186-.LFBB16
.LM186:
.LFBB16:
	b.entri 	1,16
	.stabn	68,0,701,.LM187-.LFBB16
.LM187:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,0	     # movsi imm P
	b.ori  	r5,r0,64	  # movsi imm J
	b.jal  	_memset
	.stabn	68,0,706,.LM188-.LFBB16
.LM188:
	bw.lwz   	r7,(_isVideoStarted)(r0)	    # movsi load
	b.bnei  	r7,0,.L90
	.stabn	68,0,708,.LM189-.LFBB16
.LM189:
	b.movi 	r7,1	     # movsi imm P
	bw.sw    	(_isVideoStarted)(r0),r7	   # movsi store
	.stabn	68,0,709,.LM190-.LFBB16
.LM190:
	bw.lwz   	r3,(_pStartSem)(r0)	    # movsi load
	b.jal  	_OSSemPost
	.stabn	68,0,714,.LM191-.LFBB16
.LM191:
	b.ori  	r7,r0,22	  # movsi imm J
	bw.sw    	-536735648(r0),r7	   # movsi store
	.stabn	68,0,715,.LM192-.LFBB16
.LM192:
	bw.lwz   	r7,-536735712(r0)	    # movsi load
	bw.sw    	-536735644(r0),r7	   # movsi store
	.stabn	68,0,716,.LM193-.LFBB16
.LM193:
	b.ori  	r7,r0,32	  # movsi imm J
	bw.sw    	-536735480(r0),r7	   # movsi store
	.stabn	68,0,717,.LM194-.LFBB16
.LM194:
	bw.sw    	-536735476(r0),r0	   # movsi store
	.stabn	68,0,718,.LM195-.LFBB16
.LM195:
	b.ori  	r7,r0,15	  # movsi imm J
	bw.sw    	-536735472(r0),r7	   # movsi store
.L90:
	.stabn	68,0,722,.LM196-.LFBB16
.LM196:
	b.sb    	3(r1),r0	   # movqi store
	.stabn	68,0,723,.LM197-.LFBB16
.LM197:
	b.ori   	r7,r0,80	 # movqi imm J
	b.sb    	2(r1),r7	   # movqi store
	.stabn	68,0,726,.LM198-.LFBB16
.LM198:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,2	     # movsi imm P
	b.jal  	_setCommandResponse
	.stabn	68,0,729,.LM199-.LFBB16
.LM199:
	b.reti  	1,16
	.size	_commandVideoStart, .-_commandVideoStart
	.stabs	"responseBuf:(0,17)",128,0,701,0
	.stabn	192,0,0,.LFBB16-.LFBB16
	.stabn	224,0,0,.Lscope16-.LFBB16
.Lscope16:
	.stabs	"",36,0,0,.Lscope16-.LFBB16
	.stabd	78,0,0
.proc _streamGetPCMInLength
	.stabs	"streamGetPCMInLength:F(0,15)",36,0,614,_streamGetPCMInLength
	.stabs	"commandBuf:P(0,16)",64,0,613,3
	.global _streamGetPCMInLength
	.type	_streamGetPCMInLength, @function
_streamGetPCMInLength:
	.stabd	46,0,0
	.stabn	68,0,614,.LM200-.LFBB17
.LM200:
.LFBB17:
	b.entri 	1,16
	.stabn	68,0,615,.LM201-.LFBB17
.LM201:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,0	     # movsi imm P
	b.ori  	r5,r0,64	  # movsi imm J
	b.jal  	_memset
	.stabn	68,0,620,.LM202-.LFBB17
.LM202:
	bw.lbz   	r7,(_pcminDualStreamBuf+91)(r0)
	b.extbs 	r7,r7
	b.ori  	r24,r0,_pcminDualStreamBuf+80	  # movsi imm i
	b.add   	r7,r7,r24
	b.lbz   	r7,0(r7)
	b.extbs 	r7,r7
	b.beqi  	r7,0,.L94
	.stabn	68,0,622,.LM203-.LFBB17
.LM203:
	bw.lbz   	r7,(_pcminDualStreamBuf+91)(r0)
	b.extbs 	r7,r7
	b.ori  	r5,r0,_pcminDualStreamBuf	  # movsi imm i
	b.slli  	r7,r7,2
	b.add   	r7,r7,r5
	b.lwz   	r7,0(r7)	    # movsi load
	b.addi 	r4,r0,3072	  # movsi imm I
	b.sflesi 	r7,3072
	b.cmov  	r23,r7,r4
	.stabn	68,0,643,.LM204-.LFBB17
.LM204:
	bw.lbz   	r7,(_pcminDualStreamBuf+91)(r0)
	b.extbs 	r7,r7
	b.slli  	r7,r7,2
	b.add   	r7,r7,r5
	b.lwz   	r7,40(r7)	    # movsi load
	b.slli  	r6,r23,17
	b.andi  	r7,r7,131071
	b.or    	r6,r6,r7
	bw.sw    	-804978532(r0),r6	   # movsi store
	.stabn	68,0,651,.LM205-.LFBB17
.LM205:
	bw.lbz   	r7,(_pcminDualStreamBuf+92)(r0)
	b.addi  	r7,r7,-1
	b.extbs 	r7,r7
	bw.sb    	(_pcminDualStreamBuf+92)(r0),r7	   # movqi store
	.stabn	68,0,652,.LM206-.LFBB17
.LM206:
	bw.lbz   	r7,(_pcminDualStreamBuf+91)(r0)
	b.extbs 	r7,r7
	b.slli  	r7,r7,2
	b.add   	r7,r7,r5
	b.sw    	0(r7),r0	   # movsi store
	.stabn	68,0,653,.LM207-.LFBB17
.LM207:
	bw.lbz   	r6,(_pcminDualStreamBuf+91)(r0)
	b.extbs 	r6,r6
	bw.lbz   	r7,(_pcminDualStreamBuf+91)(r0)
	b.extbs 	r7,r7
	b.mul   	r7,r7,r4
	b.addi  	r7,r7,-251559680
	b.slli  	r6,r6,2
	b.add   	r6,r6,r5
	b.sw    	40(r6),r7	   # movsi store
	.stabn	68,0,655,.LM208-.LFBB17
.LM208:
	bw.lbz   	r7,(_pcminDualStreamBuf+91)(r0)
	b.extbs 	r7,r7
	b.add   	r7,r7,r24
	b.sb    	0(r7),r0	   # movqi store
	.stabn	68,0,657,.LM209-.LFBB17
.LM209:
	bw.lbz   	r7,(_pcminDualStreamBuf+91)(r0)
	b.addi  	r7,r7,1
	b.extbs 	r7,r7
	bw.sb    	(_pcminDualStreamBuf+91)(r0),r7	   # movqi store
	.stabn	68,0,658,.LM210-.LFBB17
.LM210:
	bw.lbz   	r7,(_pcminDualStreamBuf+91)(r0)
	b.extbs 	r7,r7
	b.ori  	r6,r0,10	  # movsi imm J
	b.bne   	r7,r6,.L96
	.stabn	68,0,659,.LM211-.LFBB17
.LM211:
	bw.sb    	(_pcminDualStreamBuf+91)(r0),r0	   # movqi store
.L96:
	.stabn	68,0,628,.LM212-.LFBB17
.LM212:
	b.sb    	3(r1),r0	   # movqi store
	.stabn	68,0,629,.LM213-.LFBB17
.LM213:
	b.ori   	r7,r0,66	 # movqi imm J
	b.sb    	2(r1),r7	   # movqi store
	.stabn	68,0,630,.LM214-.LFBB17
.LM214:
	b.sb    	1(r1),r0	   # movqi store
	.stabn	68,0,631,.LM215-.LFBB17
.LM215:
	b.sb    	0(r1),r0	   # movqi store
	.stabn	68,0,633,.LM216-.LFBB17
.LM216:
	b.sb    	7(r1),r23	   # movqi store
	.stabn	68,0,635,.LM217-.LFBB17
.LM217:
	b.srli  	r7,r23,8
	b.sb    	6(r1),r7	   # movqi store
	.stabn	68,0,637,.LM218-.LFBB17
.LM218:
	b.srli  	r7,r23,16
	b.sb    	5(r1),r7	   # movqi store
	.stabn	68,0,639,.LM219-.LFBB17
.LM219:
	b.srli  	r7,r23,24
	b.sb    	4(r1),r7	   # movqi store
	.stabn	68,0,661,.LM220-.LFBB17
.LM220:
	b.jal  	_ms50_delay
	.stabn	68,0,662,.LM221-.LFBB17
.LM221:
	b.jal  	_ep5_nack_toggle
	b.j    	.L98
.L94:
	.stabn	68,0,666,.LM222-.LFBB17
.LM222:
	b.movi  	r7,-4	    # movqi imm P
	b.sb    	3(r1),r7	   # movqi store
	.stabn	68,0,667,.LM223-.LFBB17
.LM223:
	b.ori   	r7,r0,66	 # movqi imm J
	b.sb    	2(r1),r7	   # movqi store
	.stabn	68,0,668,.LM224-.LFBB17
.LM224:
	b.sb    	1(r1),r0	   # movqi store
	.stabn	68,0,669,.LM225-.LFBB17
.LM225:
	b.sb    	0(r1),r0	   # movqi store
	.stabn	68,0,670,.LM226-.LFBB17
.LM226:
	b.sb    	7(r1),r0	   # movqi store
	.stabn	68,0,671,.LM227-.LFBB17
.LM227:
	b.sb    	6(r1),r0	   # movqi store
	.stabn	68,0,672,.LM228-.LFBB17
.LM228:
	b.sb    	5(r1),r0	   # movqi store
	.stabn	68,0,673,.LM229-.LFBB17
.LM229:
	b.sb    	4(r1),r0	   # movqi store
.L98:
	.stabn	68,0,676,.LM230-.LFBB17
.LM230:
	bw.lwz   	r6,(_lost_pcm_len)(r0)	    # movsi load
	b.sflesi 	r6,3072
	b.addi 	r7,r0,3072	  # movsi imm I
	b.cmov  	r7,r6,r7
	.stabn	68,0,681,.LM231-.LFBB17
.LM231:
	b.sub   	r6,r6,r7
	bw.sw    	(_lost_pcm_len)(r0),r6	   # movsi store
	.stabn	68,0,683,.LM232-.LFBB17
.LM232:
	b.sb    	11(r1),r7	   # movqi store
	.stabn	68,0,685,.LM233-.LFBB17
.LM233:
	b.srli  	r6,r7,8
	b.sb    	10(r1),r6	   # movqi store
	.stabn	68,0,687,.LM234-.LFBB17
.LM234:
	b.srli  	r6,r7,16
	b.sb    	9(r1),r6	   # movqi store
	.stabn	68,0,689,.LM235-.LFBB17
.LM235:
	b.srli  	r7,r7,24
	b.sb    	8(r1),r7	   # movqi store
	.stabn	68,0,694,.LM236-.LFBB17
.LM236:
	b.mov  	r3,r1	     # movsi
	b.ori  	r4,r0,12	  # movsi imm J
	b.jal  	_setCommandResponse
	.stabn	68,0,697,.LM237-.LFBB17
.LM237:
	b.reti  	1,16
	.size	_streamGetPCMInLength, .-_streamGetPCMInLength
	.stabs	"responseBuf:(0,17)",128,0,615,0
	.stabs	"pcmBufferLen:r(0,1)",64,0,617,7
	.stabs	"dummyPcmLen:r(0,1)",64,0,618,7
	.stabn	192,0,0,.LFBB17-.LFBB17
	.stabn	224,0,0,.Lscope17-.LFBB17
.Lscope17:
	.stabs	"",36,0,0,.Lscope17-.LFBB17
	.stabd	78,0,0
.proc _streamGetH264Length
	.stabs	"streamGetH264Length:F(0,15)",36,0,517,_streamGetH264Length
	.stabs	"commandBuf:P(0,16)",64,0,516,3
	.global _streamGetH264Length
	.type	_streamGetH264Length, @function
_streamGetH264Length:
	.stabd	46,0,0
	.stabn	68,0,517,.LM238-.LFBB18
.LM238:
.LFBB18:
	b.entri 	2,16
	.stabn	68,0,518,.LM239-.LFBB18
.LM239:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,0	     # movsi imm P
	b.ori  	r5,r0,64	  # movsi imm J
	b.jal  	_memset
	.stabn	68,0,521,.LM240-.LFBB18
.LM240:
	bw.lbz   	r7,(_h264DualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.addi  	r7,r7,_h264DualStreamBuf+16
	b.lbz   	r7,0(r7)
	b.extbs 	r7,r7
	b.beqi  	r7,0,.L101
	bw.lbz   	r7,(_h264DualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.ori  	r6,r0,_h264DualStreamBuf	  # movsi imm i
	b.slli  	r7,r7,2
	b.add   	r7,r7,r6
	b.lwz   	r7,0(r7)	    # movsi load
	b.blesi  	r7,0,.L101
	.stabn	68,0,528,.LM241-.LFBB18
.LM241:
	bw.lbz   	r7,(_h264DualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.slli  	r7,r7,2
	b.add   	r7,r7,r6
	b.lwz   	r25,0(r7)	    # movsi load
	.stabn	68,0,530,.LM242-.LFBB18
.LM242:
	bw.lbz   	r7,(_h264DualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.slli  	r7,r7,2
	b.add   	r7,r7,r6
	b.lwz   	r24,0(r7)	    # movsi load
	.stabn	68,0,532,.LM243-.LFBB18
.LM243:
	bw.lbz   	r7,(_h264DualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.slli  	r7,r7,2
	b.add   	r7,r7,r6
	b.lwz   	r23,0(r7)	    # movsi load
	.stabn	68,0,534,.LM244-.LFBB18
.LM244:
	bw.lbz   	r7,(_h264DualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.slli  	r7,r7,2
	b.add   	r7,r7,r6
	b.lwz   	r4,0(r7)	    # movsi load
	.stabn	68,0,537,.LM245-.LFBB18
.LM245:
	bw.lbz   	r7,(_h264DualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.slli  	r7,r7,2
	b.add   	r7,r7,r6
	b.lwz   	r7,0(r7)	    # movsi load
	b.addi 	r10,r0,16320	  # movsi imm I
	b.bgts   	r7,r10,.L106
	bw.lbz   	r7,(_h264DualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.slli  	r7,r7,2
	b.addi  	r7,r7,_h264DualStreamBuf
	b.lwz   	r10,0(r7)	    # movsi load
.L106:
	.stabn	68,0,540,.LM246-.LFBB18
.LM246:
	bw.lbz   	r7,(_h264DualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.ori  	r5,r0,_h264DualStreamBuf	  # movsi imm i
	b.slli  	r7,r7,2
	b.add   	r7,r7,r5
	b.lwz   	r7,8(r7)	    # movsi load
	b.slli  	r6,r10,17
	b.andi  	r7,r7,131071
	b.or    	r6,r6,r7
	bw.sw    	-804978548(r0),r6	   # movsi store
	.stabn	68,0,543,.LM247-.LFBB18
.LM247:
	bw.lbz   	r7,(_h264DualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.slli  	r7,r7,2
	b.add   	r7,r7,r5
	b.lwz   	r6,0(r7)	    # movsi load
	b.sub   	r6,r6,r10
	b.sw    	0(r7),r6	   # movsi store
	.stabn	68,0,544,.LM248-.LFBB18
.LM248:
	bw.lbz   	r7,(_h264DualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.slli  	r7,r7,2
	b.add   	r7,r7,r5
	b.lwz   	r6,8(r7)	    # movsi load
	b.add   	r6,r6,r10
	b.sw    	8(r7),r6	   # movsi store
	.stabn	68,0,523,.LM249-.LFBB18
.LM249:
	b.sb    	3(r1),r0	   # movqi store
	.stabn	68,0,524,.LM250-.LFBB18
.LM250:
	b.ori   	r7,r0,65	 # movqi imm J
	b.sb    	2(r1),r7	   # movqi store
	.stabn	68,0,525,.LM251-.LFBB18
.LM251:
	b.sb    	1(r1),r0	   # movqi store
	.stabn	68,0,526,.LM252-.LFBB18
.LM252:
	b.sb    	0(r1),r0	   # movqi store
	.stabn	68,0,528,.LM253-.LFBB18
.LM253:
	b.sb    	7(r1),r25	   # movqi store
	.stabn	68,0,530,.LM254-.LFBB18
.LM254:
	b.srli  	r7,r24,8
	b.sb    	6(r1),r7	   # movqi store
	.stabn	68,0,532,.LM255-.LFBB18
.LM255:
	b.srli  	r7,r23,16
	b.sb    	5(r1),r7	   # movqi store
	.stabn	68,0,534,.LM256-.LFBB18
.LM256:
	b.srli  	r7,r4,24
	b.sb    	4(r1),r7	   # movqi store
	.stabn	68,0,546,.LM257-.LFBB18
.LM257:
	b.jal  	_ms50_delay
	.stabn	68,0,547,.LM258-.LFBB18
.LM258:
	b.jal  	_ep4_nack_toggle
	b.j    	.L107
.L101:
	.stabn	68,0,551,.LM259-.LFBB18
.LM259:
	b.movi  	r7,-4	    # movqi imm P
	b.sb    	3(r1),r7	   # movqi store
	.stabn	68,0,552,.LM260-.LFBB18
.LM260:
	b.ori   	r7,r0,65	 # movqi imm J
	b.sb    	2(r1),r7	   # movqi store
	.stabn	68,0,553,.LM261-.LFBB18
.LM261:
	b.sb    	1(r1),r0	   # movqi store
	.stabn	68,0,554,.LM262-.LFBB18
.LM262:
	b.sb    	0(r1),r0	   # movqi store
	.stabn	68,0,555,.LM263-.LFBB18
.LM263:
	b.sb    	7(r1),r0	   # movqi store
	.stabn	68,0,556,.LM264-.LFBB18
.LM264:
	b.sb    	6(r1),r0	   # movqi store
	.stabn	68,0,557,.LM265-.LFBB18
.LM265:
	b.sb    	5(r1),r0	   # movqi store
	.stabn	68,0,558,.LM266-.LFBB18
.LM266:
	b.sb    	4(r1),r0	   # movqi store
	b.movi 	r10,0	     # movsi imm P
.L107:
	.stabn	68,0,562,.LM267-.LFBB18
.LM267:
	bw.lbz   	r7,(_jpegDualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.addi  	r7,r7,_jpegDualStreamBuf+16
	b.lbz   	r7,0(r7)
	b.extbs 	r7,r7
	b.beqi  	r7,0,.L108
	bw.lbz   	r7,(_jpegDualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.ori  	r6,r0,_jpegDualStreamBuf	  # movsi imm i
	b.slli  	r7,r7,2
	b.add   	r7,r7,r6
	b.lwz   	r7,0(r7)	    # movsi load
	b.blesi  	r7,0,.L108
	.stabn	68,0,564,.LM268-.LFBB18
.LM268:
	b.sb    	11(r1),r0	   # movqi store
	.stabn	68,0,565,.LM269-.LFBB18
.LM269:
	b.ori   	r7,r0,64	 # movqi imm J
	b.sb    	10(r1),r7	   # movqi store
	.stabn	68,0,566,.LM270-.LFBB18
.LM270:
	b.sb    	9(r1),r0	   # movqi store
	.stabn	68,0,567,.LM271-.LFBB18
.LM271:
	b.sb    	8(r1),r0	   # movqi store
	.stabn	68,0,569,.LM272-.LFBB18
.LM272:
	bw.lbz   	r7,(_jpegDualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.slli  	r7,r7,2
	b.add   	r7,r7,r6
	b.lwz   	r7,0(r7)	    # movsi load
	b.sb    	15(r1),r7	   # movqi store
	.stabn	68,0,571,.LM273-.LFBB18
.LM273:
	bw.lbz   	r7,(_jpegDualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.slli  	r7,r7,2
	b.add   	r7,r7,r6
	b.lwz   	r7,0(r7)	    # movsi load
	b.srli  	r7,r7,8
	b.sb    	14(r1),r7	   # movqi store
	.stabn	68,0,573,.LM274-.LFBB18
.LM274:
	bw.lbz   	r7,(_jpegDualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.slli  	r7,r7,2
	b.add   	r7,r7,r6
	b.lwz   	r7,0(r7)	    # movsi load
	b.srli  	r7,r7,16
	b.sb    	13(r1),r7	   # movqi store
	.stabn	68,0,575,.LM275-.LFBB18
.LM275:
	bw.lbz   	r7,(_jpegDualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.slli  	r7,r7,2
	b.add   	r7,r7,r6
	b.lwz   	r7,0(r7)	    # movsi load
	b.srli  	r7,r7,24
	b.sb    	12(r1),r7	   # movqi store
	.stabn	68,0,578,.LM276-.LFBB18
.LM276:
	b.bnei  	r10,0,.L111
	.stabn	68,0,581,.LM277-.LFBB18
.LM277:
	bw.lbz   	r7,(_jpegDualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.slli  	r7,r7,2
	b.add   	r7,r7,r6
	b.lwz   	r7,0(r7)	    # movsi load
	b.addi 	r4,r0,16320	  # movsi imm I
	b.bgts   	r7,r4,.L115
	bw.lbz   	r7,(_jpegDualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.slli  	r7,r7,2
	b.addi  	r7,r7,_jpegDualStreamBuf
	b.lwz   	r4,0(r7)	    # movsi load
.L115:
	.stabn	68,0,584,.LM278-.LFBB18
.LM278:
	bw.lbz   	r7,(_jpegDualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.ori  	r5,r0,_jpegDualStreamBuf	  # movsi imm i
	b.slli  	r7,r7,2
	b.add   	r7,r7,r5
	b.lwz   	r7,8(r7)	    # movsi load
	b.slli  	r6,r4,17
	b.andi  	r7,r7,131071
	b.or    	r6,r6,r7
	bw.sw    	-804978564(r0),r6	   # movsi store
	.stabn	68,0,586,.LM279-.LFBB18
.LM279:
	bw.lbz   	r7,(_jpegDualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.slli  	r7,r7,2
	b.add   	r7,r7,r5
	b.lwz   	r6,0(r7)	    # movsi load
	b.sub   	r6,r6,r4
	b.sw    	0(r7),r6	   # movsi store
	.stabn	68,0,587,.LM280-.LFBB18
.LM280:
	bw.lbz   	r7,(_jpegDualStreamBuf+19)(r0)
	b.extbs 	r7,r7
	b.slli  	r7,r7,2
	b.add   	r7,r7,r5
	b.lwz   	r6,8(r7)	    # movsi load
	b.add   	r6,r6,r4
	b.sw    	8(r7),r6	   # movsi store
	.stabn	68,0,589,.LM281-.LFBB18
.LM281:
	b.jal  	_ms50_delay
	.stabn	68,0,590,.LM282-.LFBB18
.LM282:
	b.jal  	_ep3_nack_toggle
	b.j    	.L116
.L111:
	.stabn	68,0,593,.LM283-.LFBB18
.LM283:
	b.movi 	r7,1	     # movsi imm P
	bw.sw    	(_isJpegDataExist)(r0),r7	   # movsi store
	b.j    	.L116
.L108:
	.stabn	68,0,597,.LM284-.LFBB18
.LM284:
	b.movi  	r7,-4	    # movqi imm P
	b.sb    	11(r1),r7	   # movqi store
	.stabn	68,0,598,.LM285-.LFBB18
.LM285:
	b.ori   	r7,r0,64	 # movqi imm J
	b.sb    	10(r1),r7	   # movqi store
	.stabn	68,0,599,.LM286-.LFBB18
.LM286:
	b.sb    	9(r1),r0	   # movqi store
	.stabn	68,0,600,.LM287-.LFBB18
.LM287:
	b.sb    	8(r1),r0	   # movqi store
	.stabn	68,0,601,.LM288-.LFBB18
.LM288:
	b.sb    	15(r1),r0	   # movqi store
	.stabn	68,0,602,.LM289-.LFBB18
.LM289:
	b.sb    	14(r1),r0	   # movqi store
	.stabn	68,0,603,.LM290-.LFBB18
.LM290:
	b.sb    	13(r1),r0	   # movqi store
	.stabn	68,0,604,.LM291-.LFBB18
.LM291:
	b.sb    	12(r1),r0	   # movqi store
.L116:
	.stabn	68,0,608,.LM292-.LFBB18
.LM292:
	b.mov  	r3,r1	     # movsi
	b.ori  	r4,r0,16	  # movsi imm J
	b.jal  	_setCommandResponse
	.stabn	68,0,611,.LM293-.LFBB18
.LM293:
	b.reti  	2,16
	.size	_streamGetH264Length, .-_streamGetH264Length
	.stabs	"responseBuf:(0,17)",128,0,518,0
	.stabs	"packet_len:r(0,1)",64,0,520,10
	.stabn	192,0,0,.LFBB18-.LFBB18
	.stabn	224,0,0,.Lscope18-.LFBB18
.Lscope18:
	.stabs	"",36,0,0,.Lscope18-.LFBB18
	.stabd	78,0,0
.proc _i2cMasterWrite
	.stabs	"i2cMasterWrite:F(0,15)",36,0,392,_i2cMasterWrite
	.stabs	"commandBuf:P(0,16)",64,0,391,10
	.global _i2cMasterWrite
	.type	_i2cMasterWrite, @function
_i2cMasterWrite:
	.stabd	46,0,0
	.stabn	68,0,392,.LM294-.LFBB19
.LM294:
.LFBB19:
	b.entri 	2,32
	b.mov  	r10,r3	     # movsi
	.stabn	68,0,393,.LM295-.LFBB19
.LM295:
	b.addi  	r3,r1,64
	b.movi 	r4,0	     # movsi imm P
	b.ori  	r5,r0,64	  # movsi imm J
	b.jal  	_memset
	.stabn	68,0,399,.LM296-.LFBB19
.LM296:
	b.addi  	r3,r1,4
	b.movi 	r4,0	     # movsi imm P
	b.ori  	r5,r0,60	  # movsi imm J
	b.jal  	_memset
	.stabn	68,0,403,.LM297-.LFBB19
.LM297:
	b.lbz   	r7,0(r10)
	b.extbs 	r4,r7
	b.mov  	r24,r4	     # movsi
	.stabn	68,0,404,.LM298-.LFBB19
.LM298:
	b.lbz   	r7,2(r10)
	b.extbs 	r3,r7
	.stabn	68,0,423,.LM299-.LFBB19
.LM299:
	b.blesi  	r4,0,.L119
	b.movi 	r23,0	     # movsi imm P
	.stabn	68,0,425,.LM300-.LFBB19
.LM300:
	b.addi  	r25,r1,4
.L121:
	b.add   	r5,r25,r23
	b.srai  	r7,r23,2
	b.movi 	r6,7	     # movsi imm P
	b.sub   	r6,r6,r23
	b.slli  	r7,r7,3
	b.add   	r7,r7,r6
	b.add   	r7,r7,r10
	b.lbz   	r7,0(r7)
	b.sb    	0(r5),r7	   # movqi store
	.stabn	68,0,423,.LM301-.LFBB19
.LM301:
	b.addi  	r23,r23,1
	b.bne   	r23,r24,.L121
.L119:
	.stabn	68,0,428,.LM302-.LFBB19
.LM302:
	b.addi  	r5,r1,4
	b.jal  	_i2c_write
	b.extbs 	r3,r3
	.stabn	68,0,431,.LM303-.LFBB19
.LM303:
	b.bnei  	r3,0,.L122
	.stabn	68,0,432,.LM304-.LFBB19
.LM304:
	b.sb    	67(r1),r0	   # movqi store
	b.j    	.L124
.L122:
	.stabn	68,0,434,.LM305-.LFBB19
.LM305:
	b.movi  	r7,-3	    # movqi imm P
	b.sb    	67(r1),r7	   # movqi store
.L124:
	.stabn	68,0,436,.LM306-.LFBB19
.LM306:
	b.ori   	r7,r0,49	 # movqi imm J
	b.sb    	66(r1),r7	   # movqi store
	.stabn	68,0,437,.LM307-.LFBB19
.LM307:
	b.sb    	65(r1),r3	   # movqi store
	.stabn	68,0,440,.LM308-.LFBB19
.LM308:
	b.addi  	r3,r1,64
	b.movi 	r4,3	     # movsi imm P
	b.jal  	_setCommandResponse
	.stabn	68,0,443,.LM309-.LFBB19
.LM309:
	b.reti  	2,32
	.size	_i2cMasterWrite, .-_i2cMasterWrite
	.stabs	"responseBuf:(0,17)",128,0,393,64
	.stabs	"len:r(0,1)",64,0,396,4
	.stabs	"slaveID:r(0,2)",64,0,397,3
	.stabs	"dataBuf:(0,18)=ar(4,4);0;59;(0,2)",128,0,399,4
	.stabs	"i2cRet:r(0,2)",64,0,400,3
	.stabs	"i:r(0,1)",64,0,401,23
	.stabn	192,0,0,.LFBB19-.LFBB19
	.stabn	224,0,0,.Lscope19-.LFBB19
.Lscope19:
	.stabs	"",36,0,0,.Lscope19-.LFBB19
	.stabd	78,0,0
.proc _i2cMasterRead
	.stabs	"i2cMasterRead:F(0,15)",36,0,337,_i2cMasterRead
	.stabs	"commandBuf:P(0,16)",64,0,336,11
	.global _i2cMasterRead
	.type	_i2cMasterRead, @function
_i2cMasterRead:
	.stabd	46,0,0
	.stabn	68,0,337,.LM310-.LFBB20
.LM310:
.LFBB20:
	b.entri 	4,32
	b.mov  	r11,r3	     # movsi
	.stabn	68,0,338,.LM311-.LFBB20
.LM311:
	b.addi  	r3,r1,64
	b.movi 	r4,0	     # movsi imm P
	b.ori  	r5,r0,64	  # movsi imm J
	b.jal  	_memset
	.stabn	68,0,344,.LM312-.LFBB20
.LM312:
	b.addi  	r10,r1,4
	b.mov  	r3,r10	     # movsi
	b.movi 	r4,0	     # movsi imm P
	b.ori  	r5,r0,60	  # movsi imm J
	b.jal  	_memset
	.stabn	68,0,348,.LM313-.LFBB20
.LM313:
	b.lbz   	r7,0(r11)
	b.extbs 	r12,r7
	.stabn	68,0,367,.LM314-.LFBB20
.LM314:
	b.lbz   	r3,2(r11)
	b.extbs 	r3,r3
	b.mov  	r4,r12	     # movsi
	b.mov  	r5,r10	     # movsi
	b.jal  	_i2c_read
	b.extbs 	r3,r3
	.stabn	68,0,369,.LM315-.LFBB20
.LM315:
	b.movi 	r4,0	     # movsi imm P
	b.blesi  	r12,0,.L130
	b.movi 	r4,0	     # movsi imm P
	.stabn	68,0,371,.LM316-.LFBB20
.LM316:
	b.addi  	r5,r1,4
.L131:
	b.srai  	r7,r4,2
	b.movi 	r6,7	     # movsi imm P
	b.sub   	r6,r6,r4
	b.slli  	r7,r7,3
	b.addi  	r23,r1,128
	b.add   	r7,r7,r23
	b.add   	r7,r7,r6
	b.add   	r6,r5,r4
	b.lbz   	r6,0(r6)
	bg.sb    	-64(r7),r6	   # movqi store
	.stabn	68,0,372,.LM317-.LFBB20
.LM317:
	b.addi  	r4,r4,1
	.stabn	68,0,369,.LM318-.LFBB20
.LM318:
	b.bne   	r4,r12,.L131
.L130:
	.stabn	68,0,376,.LM319-.LFBB20
.LM319:
	b.bnei  	r3,0,.L132
	.stabn	68,0,377,.LM320-.LFBB20
.LM320:
	b.sb    	67(r1),r0	   # movqi store
	b.j    	.L134
.L132:
	.stabn	68,0,379,.LM321-.LFBB20
.LM321:
	b.movi  	r7,-3	    # movqi imm P
	b.sb    	67(r1),r7	   # movqi store
.L134:
	.stabn	68,0,381,.LM322-.LFBB20
.LM322:
	b.ori   	r7,r0,48	 # movqi imm J
	b.sb    	66(r1),r7	   # movqi store
	.stabn	68,0,382,.LM323-.LFBB20
.LM323:
	b.sb    	65(r1),r3	   # movqi store
	.stabn	68,0,383,.LM324-.LFBB20
.LM324:
	b.sb    	64(r1),r12	   # movqi store
	.stabn	68,0,386,.LM325-.LFBB20
.LM325:
	b.addi  	r3,r1,64
	b.addi  	r4,r4,4
	b.jal  	_setCommandResponse
	.stabn	68,0,389,.LM326-.LFBB20
.LM326:
	b.reti  	4,32
	.size	_i2cMasterRead, .-_i2cMasterRead
	.stabs	"responseBuf:(0,17)",128,0,338,64
	.stabs	"responseLen:r(0,1)",64,0,339,4
	.stabs	"dataBuf:(0,18)",128,0,344,4
	.stabs	"i2cRet:r(0,2)",64,0,345,3
	.stabn	192,0,0,.LFBB20-.LFBB20
	.stabn	224,0,0,.Lscope20-.LFBB20
.Lscope20:
	.stabs	"",36,0,0,.Lscope20-.LFBB20
	.stabd	78,0,0
.proc _hifRegisterWrite
	.stabs	"hifRegisterWrite:F(0,15)",36,0,239,_hifRegisterWrite
	.stabs	"commandBuf:P(0,16)",64,0,238,10
	.global _hifRegisterWrite
	.type	_hifRegisterWrite, @function
_hifRegisterWrite:
	.stabd	46,0,0
	.stabn	68,0,239,.LM327-.LFBB21
.LM327:
.LFBB21:
	b.entri 	2,16
	b.mov  	r10,r3	     # movsi
	.stabn	68,0,240,.LM328-.LFBB21
.LM328:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,0	     # movsi imm P
	b.ori  	r5,r0,64	  # movsi imm J
	b.jal  	_memset
	.stabn	68,0,243,.LM329-.LFBB21
.LM329:
	b.lbz   	r7,0(r10)
	b.extbs 	r4,r7
	b.mov  	r5,r4	     # movsi
	.stabn	68,0,244,.LM330-.LFBB21
.LM330:
	b.addi  	r23,r10,2
	b.lbz   	r6,2(r10)
	b.extbs 	r6,r6
	b.andi  	r7,r6,255
	b.slli  	r7,r7,2
	b.addi  	r7,r7,-536735744
	.stabn	68,0,249,.LM331-.LFBB21
.LM331:
	b.ori  	r24,r0,23	  # movsi imm J
	b.bne   	r6,r24,.L138
	b.movi 	r6,0	     # movsi imm P
.L140:
	.stabn	68,0,250,.LM332-.LFBB21
.LM332:
	l.nop   0
	b.addi  	r6,r6,1
	b.ori  	r24,r0,10000000	  # movsi imm i
	b.bne   	r6,r24,.L140
.L138:
	.stabn	68,0,252,.LM333-.LFBB21
.LM333:
	b.blesi  	r5,0,.L141
	b.mov  	r6,r7	     # movsi
	b.movi 	r5,0	     # movsi imm P
.L143:
	.stabn	68,0,260,.LM334-.LFBB21
.LM334:
	b.srai  	r7,r5,2
	b.slli  	r7,r7,3
	b.sub   	r7,r7,r5
	b.add   	r7,r7,r10
	b.lbz   	r7,7(r7)
	b.sw    	0(r6),r7	   # movsi store
	.stabn	68,0,252,.LM335-.LFBB21
.LM335:
	b.addi  	r5,r5,1
	b.addi  	r6,r6,4
	b.bne   	r5,r4,.L143
.L141:
	.stabn	68,0,265,.LM336-.LFBB21
.LM336:
	b.sb    	3(r1),r0	   # movqi store
	.stabn	68,0,266,.LM337-.LFBB21
.LM337:
	b.ori   	r7,r0,33	 # movqi imm J
	b.sb    	2(r1),r7	   # movqi store
	.stabn	68,0,270,.LM338-.LFBB21
.LM338:
	b.lbz   	r7,0(r23)
	b.extbs 	r7,r7
	b.ori  	r6,r0,62	  # movsi imm J
	b.beq   	r7,r6,.L149
	b.ori  	r24,r0,66	  # movsi imm J
	b.beq   	r7,r24,.L149
	b.ori  	r6,r0,23	  # movsi imm J
	b.beq   	r7,r6,.L149
	.stabn	68,0,275,.LM339-.LFBB21
.LM339:
	b.ori  	r24,r0,63	  # movsi imm J
	b.bne   	r7,r24,.L147
	.stabn	68,0,277,.LM340-.LFBB21
.LM340:
	bw.lwz   	r3,-536735492(r0)	    # movsi load
	b.extbz 	r3,r3
	b.jal  	_AIC3101InputGain
	b.j    	.L149
.L147:
	.stabn	68,0,281,.LM341-.LFBB21
.LM341:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,2	     # movsi imm P
	b.jal  	_setCommandResponse
.L149:
	.stabn	68,0,284,.LM342-.LFBB21
.LM342:
	b.reti  	2,16
	.size	_hifRegisterWrite, .-_hifRegisterWrite
	.stabs	"responseBuf:(0,17)",128,0,240,0
	.stabs	"writeToLen:r(0,1)",64,0,243,5
	.stabs	"i:r(0,1)",64,0,246,6
	.stabn	192,0,0,.LFBB21-.LFBB21
	.stabn	224,0,0,.Lscope21-.LFBB21
.Lscope21:
	.stabs	"",36,0,0,.Lscope21-.LFBB21
	.stabd	78,0,0
.proc _commandProcess
	.stabs	"commandProcess:F(0,15)",36,0,60,_commandProcess
	.stabs	"commandBuf:P(0,16)",64,0,59,10
	.stabs	"commandLen:P(0,1)",64,0,59,4
	.global _commandProcess
	.type	_commandProcess, @function
_commandProcess:
	.stabd	46,0,0
	.stabn	68,0,60,.LM343-.LFBB22
.LM343:
.LFBB22:
	b.entri 	2,16
	b.mov  	r10,r3	     # movsi
	.stabn	68,0,63,.LM344-.LFBB22
.LM344:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,0	     # movsi imm P
	b.ori  	r5,r0,64	  # movsi imm J
	b.jal  	_memset
	.stabn	68,0,81,.LM345-.LFBB22
.LM345:
	b.lbz   	r6,3(r10)
	b.addi  	r7,r6,-16
	b.extbz 	r7,r7
	b.ori  	r6,r0,80	  # movsi imm J
	b.bgtu   	r7,r6,.L153
	b.slli  	r7,r7,2
	b.addi  	r7,r7,.L174
	b.lwz   	r7,0(r7)	    # movsi load
	b.jr    	r7
	.align 4
	.align 4
.L174:
	.word .L154
	.word .L155
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L156
	.word .L157
	.word .L158
	.word .L159
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L160
	.word .L161
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L162
	.word .L163
	.word .L164
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L165
	.word .L166
	.word .L167
	.word .L168
	.word .L169
	.word .L170
	.word .L171
	.word .L172
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L153
	.word .L173
.L154:
	.stabn	68,0,84,.LM346-.LFBB22
.LM346:
	b.mov  	r3,r10	     # movsi
	b.jal  	_internalRegisterRead
	b.j    	.L176
.L155:
	.stabn	68,0,87,.LM347-.LFBB22
.LM347:
	b.mov  	r3,r10	     # movsi
	b.jal  	_internalRegisterWrite
	b.j    	.L176
.L156:
	.stabn	68,0,90,.LM348-.LFBB22
.LM348:
	b.mov  	r3,r10	     # movsi
	b.jal  	_hifRegisterRead
	b.j    	.L176
.L157:
	.stabn	68,0,93,.LM349-.LFBB22
.LM349:
	b.mov  	r3,r10	     # movsi
	b.jal  	_hifRegisterWrite
	b.j    	.L176
.L158:
	.stabn	68,0,96,.LM350-.LFBB22
.LM350:
	b.mov  	r3,r10	     # movsi
	b.jal  	_hifRegisterBitSet
	b.j    	.L176
.L159:
	.stabn	68,0,99,.LM351-.LFBB22
.LM351:
	b.mov  	r3,r10	     # movsi
	b.jal  	_hifRegisterBitReset
	b.j    	.L176
.L160:
	.stabn	68,0,102,.LM352-.LFBB22
.LM352:
	b.mov  	r3,r10	     # movsi
	b.jal  	_i2cMasterRead
	b.j    	.L176
.L161:
	.stabn	68,0,105,.LM353-.LFBB22
.LM353:
	b.mov  	r3,r10	     # movsi
	b.jal  	_i2cMasterWrite
	b.j    	.L176
.L162:
	.stabn	68,0,108,.LM354-.LFBB22
.LM354:
	b.mov  	r3,r10	     # movsi
	b.jal  	_streamGetJpegLength
	b.j    	.L176
.L163:
	.stabn	68,0,111,.LM355-.LFBB22
.LM355:
	b.mov  	r3,r10	     # movsi
	b.jal  	_streamGetH264Length
	b.j    	.L176
.L164:
	.stabn	68,0,114,.LM356-.LFBB22
.LM356:
	b.mov  	r3,r10	     # movsi
	b.jal  	_streamGetPCMInLength
	b.j    	.L176
.L165:
	.stabn	68,0,117,.LM357-.LFBB22
.LM357:
	b.mov  	r3,r10	     # movsi
	b.jal  	_commandVideoStart
	b.j    	.L176
.L166:
	.stabn	68,0,120,.LM358-.LFBB22
.LM358:
	b.mov  	r3,r10	     # movsi
	b.jal  	_commandVideoStop
	b.j    	.L176
.L167:
	.stabn	68,0,123,.LM359-.LFBB22
.LM359:
	b.mov  	r3,r10	     # movsi
	b.jal  	_commandAudioStart
	b.j    	.L176
.L168:
	.stabn	68,0,126,.LM360-.LFBB22
.LM360:
	b.mov  	r3,r10	     # movsi
	b.jal  	_commandAudioStop
	b.j    	.L176
.L173:
	.stabn	68,0,129,.LM361-.LFBB22
.LM361:
	b.mov  	r3,r10	     # movsi
	b.jal  	_videoApiSet
	b.j    	.L176
.L169:
	.stabn	68,0,132,.LM362-.LFBB22
.LM362:
	b.addi 	r3,r0,4096	  # movsi imm I
	b.jal  	_GPIOSetLow
	.stabn	68,0,133,.LM363-.LFBB22
.LM363:
	b.mov  	r3,r10	     # movsi
	b.jal  	_firmware_sdram_write
	b.j    	.L176
.L170:
	.stabn	68,0,136,.LM364-.LFBB22
.LM364:
	b.mov  	r3,r10	     # movsi
	b.jal  	_firmware_set_length
	b.j    	.L176
.L171:
	.stabn	68,0,139,.LM365-.LFBB22
.LM365:
	b.mov  	r3,r10	     # movsi
	b.jal  	_firmware_upload
	b.j    	.L176
.L172:
	.stabn	68,0,142,.LM366-.LFBB22
.LM366:
	b.mov  	r3,r10	     # movsi
	b.jal  	_firmware_version_check
	b.j    	.L176
.L153:
	.stabn	68,0,145,.LM367-.LFBB22
.LM367:
	b.movi  	r7,-2	    # movqi imm P
	b.sb    	3(r1),r7	   # movqi store
	.stabn	68,0,146,.LM368-.LFBB22
.LM368:
	b.mov  	r3,r1	     # movsi
	b.movi 	r4,1	     # movsi imm P
	b.jal  	_setCommandResponse
.L176:
	.stabn	68,0,150,.LM369-.LFBB22
.LM369:
	b.reti  	2,16
	.size	_commandProcess, .-_commandProcess
	.stabs	"responseBuf:(0,17)",128,0,63,0
	.stabn	192,0,0,.LFBB22-.LFBB22
	.stabn	224,0,0,.Lscope22-.LFBB22
.Lscope22:
	.stabs	"",36,0,0,.Lscope22-.LFBB22
	.stabd	78,0,0
	.global _dummy_k
.section .data
	.align 4
	.type	_dummy_k, @object
	.size	_dummy_k, 4
_dummy_k:
	.long	305419896
	.global _command_video_start
.section .bss
	.align 4
	.type	_command_video_start, @object
	.size	_command_video_start, 4
_command_video_start:
	.zero	4
	.global _command_video_stop
	.align 4
	.type	_command_video_stop, @object
	.size	_command_video_stop, 4
_command_video_stop:
	.zero	4
	.global _command_audio_start
	.align 4
	.type	_command_audio_start, @object
	.size	_command_audio_start, 4
_command_audio_start:
	.zero	4
	.global _command_audio_stop
	.align 4
	.type	_command_audio_stop, @object
	.size	_command_audio_stop, 4
_command_audio_stop:
	.zero	4
	.global _isVideoStarted
	.align 4
	.type	_isVideoStarted, @object
	.size	_isVideoStarted, 4
_isVideoStarted:
	.zero	4
	.global _isAudioStarted
	.align 4
	.type	_isAudioStarted, @object
	.size	_isAudioStarted, 4
_isAudioStarted:
	.zero	4
	.global _isJpegDataExist
	.align 4
	.type	_isJpegDataExist, @object
	.size	_isJpegDataExist, 4
_isJpegDataExist:
	.zero	4
	.comm	_jpegDualStreamBuf,24,4
	.comm	_h264DualStreamBuf,24,4
	.comm	_pcminDualStreamBuf,96,4
	.comm	_pEventExternalTaskDone,4,4
	.stabs	"jpegDualStreamBuf:G(3,3)",32,0,19,0
	.stabs	"h264DualStreamBuf:G(3,3)",32,0,20,0
	.stabs	"pcminDualStreamBuf:G(3,9)",32,0,21,0
	.stabs	"command_video_start:G(3,6)",32,0,23,0
	.stabs	"command_video_stop:G(3,6)",32,0,24,0
	.stabs	"pEventExternalTaskDone:G(4,14)",32,0,15,0
	.stabs	"dummy_k:G(0,1)",32,0,13,0
	.stabs	"command_audio_start:G(3,6)",32,0,25,0
	.stabs	"command_audio_stop:G(3,6)",32,0,26,0
	.stabs	"isVideoStarted:G(0,1)",32,0,28,0
	.stabs	"isAudioStarted:G(0,1)",32,0,29,0
	.stabs	"isJpegDataExist:G(3,6)",32,0,31,0
.section .internalrom, "ax"
	.stabs	"",100,0,0,.Letext0
.Letext0:
	.ident	"GCC: (GNU) 4.2.1"
