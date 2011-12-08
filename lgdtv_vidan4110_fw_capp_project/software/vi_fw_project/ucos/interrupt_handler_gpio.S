	.file	"interrupt_handler_gpio.c"
	.stabs	"/home/hanguru/2011_project_original/lgdtv_vidan4110_fw_capp_project/software/vi_fw_project/",100,0,2,.Ltext0
	.stabs	"ucos/interrupt_handler_gpio.c",100,0,2,.Ltext0
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
	.stabs	"ucos/interrupt_handler_gpio.h",130,0,0,0
	.stabs	"ucos/interrupt_handler.h",130,0,0,0
	.stabs	"ucos/task_manage.h",130,0,0,0
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
	.stabn	162,0,0,0
	.stabn	162,0,0,0
	.stabn	162,0,0,0
.proc _GPIOIntDisable
	.stabs	"GPIOIntDisable:F(0,15)",36,0,20,_GPIOIntDisable
	.stabs	"type:P(5,6)",64,0,20,3
	.global _GPIOIntDisable
	.type	_GPIOIntDisable, @function
_GPIOIntDisable:
	.stabd	46,0,0
	.stabn	68,0,20,.LM0-.LFBB1
.LM0:
.LFBB1:
	.stabn	68,0,22,.LM1-.LFBB1
.LM1:
	bw.lwz   	r7,-536731636(r0)	    # movsi load
	b.nand  	r3,r3,r3
	b.and   	r3,r3,r7
	bw.sw    	-536731636(r0),r3	   # movsi store
	.stabn	68,0,24,.LM2-.LFBB1
.LM2:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	bw.sw    	-536731620(r0),r0	   # movsi store
	.stabn	68,0,25,.LM3-.LFBB1
.LM3:
	b.jr    	r9
	.size	_GPIOIntDisable, .-_GPIOIntDisable
.Lscope1:
	.stabs	"",36,0,0,.Lscope1-.LFBB1
	.stabd	78,0,0
.proc _IntHandlerGPIO
	.stabs	"IntHandlerGPIO:F(0,15)",36,0,27,_IntHandlerGPIO
	.global _IntHandlerGPIO
	.type	_IntHandlerGPIO, @function
_IntHandlerGPIO:
	.stabd	46,0,0
	.stabn	68,0,27,.LM4-.LFBB2
.LM4:
.LFBB2:
	b.entri 	1,0
	.stabn	68,0,29,.LM5-.LFBB2
.LM5:
	bw.lwz   	r6,-536731620(r0)	    # movsi load
	.stabn	68,0,31,.LM6-.LFBB2
.LM6:
	b.andi  	r7,r6,1
	b.beqi  	r7,0,.L4
	.stabn	68,0,33,.LM7-.LFBB2
.LM7:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-2
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L4:
	.stabn	68,0,36,.LM8-.LFBB2
.LM8:
	b.andi  	r7,r6,2
	b.beqi  	r7,0,.L7
	.stabn	68,0,38,.LM9-.LFBB2
.LM9:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-3
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L7:
	.stabn	68,0,41,.LM10-.LFBB2
.LM10:
	b.andi  	r7,r6,4
	b.beqi  	r7,0,.L9
	.stabn	68,0,43,.LM11-.LFBB2
.LM11:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-5
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L9:
	.stabn	68,0,46,.LM12-.LFBB2
.LM12:
	b.andi  	r7,r6,8
	b.beqi  	r7,0,.L11
	.stabn	68,0,48,.LM13-.LFBB2
.LM13:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-9
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L11:
	.stabn	68,0,51,.LM14-.LFBB2
.LM14:
	b.andi  	r7,r6,16
	b.beqi  	r7,0,.L13
	.stabn	68,0,53,.LM15-.LFBB2
.LM15:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-17
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L13:
	.stabn	68,0,56,.LM16-.LFBB2
.LM16:
	b.andi  	r7,r6,32
	b.beqi  	r7,0,.L15
	.stabn	68,0,58,.LM17-.LFBB2
.LM17:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-33
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L15:
	.stabn	68,0,61,.LM18-.LFBB2
.LM18:
	b.andi  	r7,r6,64
	b.beqi  	r7,0,.L17
	.stabn	68,0,63,.LM19-.LFBB2
.LM19:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-65
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L17:
	.stabn	68,0,66,.LM20-.LFBB2
.LM20:
	b.andi  	r7,r6,128
	b.beqi  	r7,0,.L19
	.stabn	68,0,68,.LM21-.LFBB2
.LM21:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-129
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L19:
	.stabn	68,0,71,.LM22-.LFBB2
.LM22:
	b.andi  	r7,r6,256
	b.beqi  	r7,0,.L21
	.stabn	68,0,73,.LM23-.LFBB2
.LM23:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-257
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L21:
	.stabn	68,0,76,.LM24-.LFBB2
.LM24:
	b.andi  	r7,r6,512
	b.beqi  	r7,0,.L23
	.stabn	68,0,78,.LM25-.LFBB2
.LM25:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-513
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L23:
	.stabn	68,0,81,.LM26-.LFBB2
.LM26:
	b.andi  	r7,r6,1024
	b.beqi  	r7,0,.L25
	.stabn	68,0,83,.LM27-.LFBB2
.LM27:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-1025
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L25:
	.stabn	68,0,86,.LM28-.LFBB2
.LM28:
	b.andi  	r7,r6,2048
	b.beqi  	r7,0,.L27
	.stabn	68,0,88,.LM29-.LFBB2
.LM29:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-2049
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L27:
	.stabn	68,0,91,.LM30-.LFBB2
.LM30:
	b.andi  	r7,r6,4096
	b.beqi  	r7,0,.L29
	.stabn	68,0,93,.LM31-.LFBB2
.LM31:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-4097
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L29:
	.stabn	68,0,96,.LM32-.LFBB2
.LM32:
	b.andi  	r7,r6,8192
	b.beqi  	r7,0,.L31
	.stabn	68,0,98,.LM33-.LFBB2
.LM33:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-8193
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L31:
	.stabn	68,0,101,.LM34-.LFBB2
.LM34:
	b.andi  	r7,r6,16384
	b.beqi  	r7,0,.L33
	.stabn	68,0,103,.LM35-.LFBB2
.LM35:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-16385
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L33:
	.stabn	68,0,106,.LM36-.LFBB2
.LM36:
	b.andi  	r7,r6,32768
	b.beqi  	r7,0,.L35
.LBB2:
	.stabn	68,0,109,.LM37-.LFBB2
.LM37:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-32769
	bw.sw    	-536731620(r0),r7	   # movsi store
	.stabn	68,0,111,.LM38-.LFBB2
.LM38:
	bw.lwz   	r7,-536731648(r0)	    # movsi load
	b.andi  	r7,r7,32768
	b.beqi  	r7,0,.L74
	.stabn	68,0,113,.LM39-.LFBB2
.LM39:
	bw.lwz   	r7,-804913140(r0)	    # movsi load
.L38:
	.stabn	68,0,114,.LM40-.LFBB2
.LM40:
	bw.lwz   	r7,-536731648(r0)	    # movsi load
	b.andi  	r7,r7,32768
	b.bnei  	r7,0,.L38
.L75:
	.stabn	68,0,115,.LM41-.LFBB2
.LM41:
	bw.lwz   	r7,-536731648(r0)	    # movsi load
	b.andi  	r7,r7,32768
	b.beqi  	r7,0,.L75
.L76:
	.stabn	68,0,116,.LM42-.LFBB2
.LM42:
	bw.lwz   	r7,-536731648(r0)	    # movsi load
	b.andi  	r7,r7,32768
	b.bnei  	r7,0,.L76
	.stabn	68,0,117,.LM43-.LFBB2
.LM43:
	b.ori  	r3,r0,-804913152	  # movsi imm i
	b.ori  	r4,r0,-2147483648	  # movsi imm i
	b.jal  	_I2S_RegSet
	.stabn	68,0,118,.LM44-.LFBB2
.LM44:
	b.ori  	r3,r0,32768	  # movsi imm i
	b.jal  	_GPIOIntDisable
	.stabn	68,0,119,.LM45-.LFBB2
.LM45:
	b.addi 	r3,r0,2048	  # movsi imm I
	b.jal  	_IntDisable
	b.j    	.L74
.L35:
.LBE2:
	.stabn	68,0,126,.LM46-.LFBB2
.LM46:
	b.andi  	r7,r6,65536
	b.beqi  	r7,0,.L42
	.stabn	68,0,128,.LM47-.LFBB2
.LM47:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-65537
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L42:
	.stabn	68,0,131,.LM48-.LFBB2
.LM48:
	b.andi  	r7,r6,131072
	b.beqi  	r7,0,.L44
	.stabn	68,0,133,.LM49-.LFBB2
.LM49:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-131073
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L44:
	.stabn	68,0,136,.LM50-.LFBB2
.LM50:
	b.andi  	r7,r6,262144
	b.beqi  	r7,0,.L46
	.stabn	68,0,138,.LM51-.LFBB2
.LM51:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-262145
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L46:
	.stabn	68,0,141,.LM52-.LFBB2
.LM52:
	b.andi  	r7,r6,524288
	b.beqi  	r7,0,.L48
	.stabn	68,0,143,.LM53-.LFBB2
.LM53:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-524289
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L48:
	.stabn	68,0,146,.LM54-.LFBB2
.LM54:
	b.andi  	r7,r6,1048576
	b.beqi  	r7,0,.L50
	.stabn	68,0,148,.LM55-.LFBB2
.LM55:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-1048577
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L50:
	.stabn	68,0,151,.LM56-.LFBB2
.LM56:
	b.andi  	r7,r6,2097152
	b.beqi  	r7,0,.L52
	.stabn	68,0,153,.LM57-.LFBB2
.LM57:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-2097153
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L52:
	.stabn	68,0,156,.LM58-.LFBB2
.LM58:
	b.andi  	r7,r6,4194304
	b.beqi  	r7,0,.L54
	.stabn	68,0,158,.LM59-.LFBB2
.LM59:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-4194305
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L54:
	.stabn	68,0,161,.LM60-.LFBB2
.LM60:
	b.andi  	r7,r6,8388608
	b.beqi  	r7,0,.L56
	.stabn	68,0,163,.LM61-.LFBB2
.LM61:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-8388609
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L56:
	.stabn	68,0,166,.LM62-.LFBB2
.LM62:
	b.andi  	r7,r6,16777216
	b.beqi  	r7,0,.L58
	.stabn	68,0,168,.LM63-.LFBB2
.LM63:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-16777217
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L58:
	.stabn	68,0,171,.LM64-.LFBB2
.LM64:
	b.andi  	r7,r6,33554432
	b.beqi  	r7,0,.L60
	.stabn	68,0,173,.LM65-.LFBB2
.LM65:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-33554433
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L60:
	.stabn	68,0,176,.LM66-.LFBB2
.LM66:
	b.andi  	r7,r6,67108864
	b.beqi  	r7,0,.L62
	.stabn	68,0,178,.LM67-.LFBB2
.LM67:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-67108865
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L62:
	.stabn	68,0,181,.LM68-.LFBB2
.LM68:
	b.andi  	r7,r6,134217728
	b.beqi  	r7,0,.L64
	.stabn	68,0,183,.LM69-.LFBB2
.LM69:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-134217729
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L64:
	.stabn	68,0,186,.LM70-.LFBB2
.LM70:
	b.andi  	r7,r6,268435456
	b.beqi  	r7,0,.L66
	.stabn	68,0,188,.LM71-.LFBB2
.LM71:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-268435457
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L66:
	.stabn	68,0,191,.LM72-.LFBB2
.LM72:
	b.andi  	r7,r6,536870912
	b.beqi  	r7,0,.L68
	.stabn	68,0,193,.LM73-.LFBB2
.LM73:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-536870913
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L68:
	.stabn	68,0,196,.LM74-.LFBB2
.LM74:
	b.andi  	r7,r6,1073741824
	b.beqi  	r7,0,.L70
	.stabn	68,0,198,.LM75-.LFBB2
.LM75:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,-1073741825
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L70:
	.stabn	68,0,201,.LM76-.LFBB2
.LM76:
	b.bgesi  	r6,0,.L72
	.stabn	68,0,203,.LM77-.LFBB2
.LM77:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	b.andi  	r7,r7,2147483647
	bw.sw    	-536731620(r0),r7	   # movsi store
	b.j    	.L74
.L72:
	.stabn	68,0,208,.LM78-.LFBB2
.LM78:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	bw.sw    	-536731620(r0),r0	   # movsi store
.L74:
	.stabn	68,0,211,.LM79-.LFBB2
.LM79:
	b.reti  	1,0
	.size	_IntHandlerGPIO, .-_IntHandlerGPIO
	.stabs	"gpio_int_flag:r(5,6)",64,0,29,5
	.stabn	192,0,0,.LFBB2-.LFBB2
	.stabn	224,0,0,.Lscope2-.LFBB2
.Lscope2:
	.stabs	"",36,0,0,.Lscope2-.LFBB2
	.stabd	78,0,0
.proc _GPIOIntEnable
	.stabs	"GPIOIntEnable:F(0,15)",36,0,6,_GPIOIntEnable
	.stabs	"type:P(5,6)",64,0,6,10
	.global _GPIOIntEnable
	.type	_GPIOIntEnable, @function
_GPIOIntEnable:
	.stabd	46,0,0
	.stabn	68,0,6,.LM80-.LFBB3
.LM80:
.LFBB3:
	b.entri 	2,0
	b.mov  	r10,r3	     # movsi
	.stabn	68,0,8,.LM81-.LFBB3
.LM81:
	b.jal  	_GPIOSetInput
	.stabn	68,0,10,.LM82-.LFBB3
.LM82:
	bw.lwz   	r7,-536731636(r0)	    # movsi load
	b.or    	r7,r10,r7
	bw.sw    	-536731636(r0),r7	   # movsi store
	.stabn	68,0,12,.LM83-.LFBB3
.LM83:
	b.movi 	r7,3	     # movsi imm P
	bw.sw    	-536731624(r0),r7	   # movsi store
	.stabn	68,0,14,.LM84-.LFBB3
.LM84:
	bw.lwz   	r7,-536731632(r0)	    # movsi load
	b.or    	r10,r10,r7
	bw.sw    	-536731632(r0),r10	   # movsi store
	.stabn	68,0,16,.LM85-.LFBB3
.LM85:
	bw.lwz   	r7,-536731620(r0)	    # movsi load
	bw.sw    	-536731620(r0),r0	   # movsi store
	.stabn	68,0,18,.LM86-.LFBB3
.LM86:
	b.reti  	2,0
	.size	_GPIOIntEnable, .-_GPIOIntEnable
.Lscope3:
	.stabs	"",36,0,0,.Lscope3-.LFBB3
	.stabd	78,0,0
	.comm	_pEventExternalTaskDone,4,4
	.stabs	"pEventExternalTaskDone:G(4,14)",32,0,15,0
	.stabs	"",100,0,0,.Letext0
.Letext0:
	.ident	"GCC: (GNU) 4.2.1"
