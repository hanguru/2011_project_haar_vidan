	.file	"os_core.c"
	.stabs	"/home/hanguru/2011_project_original/lgdtv_vidan4110_fw_capp_project/software/vi_fw_project/",100,0,2,.Ltext0
	.stabs	"ucos/os_core.c",100,0,2,.Ltext0
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
	.stabs	"ucos/ucos_ii.h",130,0,0,0
	.stabs	"ucos/os_cpu.h",130,0,0,0
	.stabs	"BOOLEAN:t(2,1)=(0,11)",128,0,9,0
	.stabs	"INT8U:t(2,2)=(0,11)",128,0,10,0
	.stabs	"INT8S:t(2,3)=(0,2)",128,0,11,0
	.stabs	"INT16U:t(2,4)=(0,9)",128,0,12,0
	.stabs	"INT16S:t(2,5)=(0,8)",128,0,13,0
	.stabs	"INT32U:t(2,6)=(0,5)",128,0,14,0
	.stabs	"INT32S:t(2,7)=(0,3)",128,0,15,0
	.stabs	"VBOOLEAN:t(2,8)=(2,9)=B(0,11)",128,0,16,0
	.stabs	"OS_STK:t(2,10)=(0,4)",128,0,17,0
	.stabs	"OS_CPU_SR:t(2,11)=(0,4)",128,0,18,0
	.stabn	162,0,0,0
	.stabs	"ucos/os_cfg.h",130,0,0,0
	.stabs	"OS_FLAGS:t(3,1)=(2,4)",128,0,112,0
	.stabn	162,0,0,0
	.stabs	"os_event:T(1,1)=s44OSEventType:(2,2),0,8;OSEventGrp:(2,2),8,8;OSEventCnt:(2,4),16,16;OSEventPtr:(1,2)=*(0,15),32,32;OSEventTbl:(1,3)=ar(1,4)=r(1,4);0;037777777777;;0;0;(2,2),64,8;OSEventName:(1,5)=ar(1,4);0;31;(0,2),72,256;;",128,0,0,0
	.stabs	"OS_EVENT:t(1,6)=(1,1)",128,0,257,0
	.stabs	"os_sem_data:T(1,7)=s4OSCnt:(2,4),0,16;OSEventTbl:(1,3),16,8;OSEventGrp:(2,2),24,8;;",128,0,0,0
	.stabs	"OS_SEM_DATA:t(1,8)=(1,7)",128,0,387,0
	.stabs	"os_stk_data:T(1,9)=s8OSFree:(2,6),0,32;OSUsed:(2,6),32,32;;",128,0,0,0
	.stabs	"OS_STK_DATA:t(1,10)=(1,9)",128,0,400,0
	.stabs	"os_tcb:T(1,11)=s96OSTCBStkPtr:(1,12)=*(2,10),0,32;OSTCBExtPtr:(1,2),32,32;OSTCBStkBottom:(1,12),64,32;OSTCBStkSize:(2,6),96,32;OSTCBOpt:(2,4),128,16;OSTCBId:(2,4),144,16;OSTCBNext:(1,13)=*(1,11),160,32;OSTCBPrev:(1,13),192,32;OSTCBEventPtr:(1,14)=*(1,6),224,32;OSTCBDly:(2,4),256,16;OSTCBStat:(2,2),272,8;OSTCBPendTO:(2,1),280,8;OSTCBPrio:(2,2),288,8;OSTCBX:(2,2),296,8;OSTCBY:(2,2),304,8;OSTCBBitX:(2,2),312,8;OSTCBBitY:(2,2),320,8;OSTCBDelReq:(2,2),328,8;OSTCBCtxSwCtr:(2,6),352,32;OSTCBCyclesTot:(2,6),384,32;OSTCBCyclesStart:(2,6),416,32;OSTCBStkBase:(1,12),448,32;OSTCBStkUsed:(2,6),480,32;OSTCBTaskName:(1,5),512,256;;",128,0,0,0
	.stabs	"OS_TCB:t(1,15)=(1,11)",128,0,464,0
	.stabn	162,0,0,0
.proc _OSIntEnter
	.stabs	"OSIntEnter:F(0,15)",36,0,294,_OSIntEnter
	.global _OSIntEnter
	.type	_OSIntEnter, @function
_OSIntEnter:
	.stabd	46,0,0
	.stabn	68,0,294,.LM0-.LFBB1
.LM0:
.LFBB1:
	.stabn	68,0,295,.LM1-.LFBB1
.LM1:
	bw.lbz   	r7,(_OSRunning)(r0)
	b.bnei  	r7,1,.L5
	.stabn	68,0,296,.LM2-.LFBB1
.LM2:
	bw.lbz   	r7,(_OSIntNesting)(r0)
	b.ori  	r6,r0,255	  # movsi imm J
	b.beq   	r7,r6,.L5
	.stabn	68,0,297,.LM3-.LFBB1
.LM3:
	b.addi  	r7,r7,1
	bw.sb    	(_OSIntNesting)(r0),r7	   # movqi store
.L5:
	.stabn	68,0,300,.LM4-.LFBB1
.LM4:
	b.jr    	r9
	.size	_OSIntEnter, .-_OSIntEnter
.Lscope1:
	.stabs	"",36,0,0,.Lscope1-.LFBB1
	.stabd	78,0,0
.proc _OSSchedLock
	.stabs	"OSSchedLock:F(0,15)",36,0,369,_OSSchedLock
	.global _OSSchedLock
	.type	_OSSchedLock, @function
_OSSchedLock:
	.stabd	46,0,0
	.stabn	68,0,369,.LM5-.LFBB2
.LM5:
.LFBB2:
	.stabn	68,0,375,.LM6-.LFBB2
.LM6:
	bw.lbz   	r7,(_OSRunning)(r0)
	b.bnei  	r7,1,.L11
.LBB2:
	.stabn	68,0,376,.LM7-.LFBB2
.LM7:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r5,r7,0
.LBE2:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r5,-7
	l.mtspr r6,r7,0
	.stabn	68,0,377,.LM8-.LFBB2
.LM8:
	bw.lbz   	r7,(_OSLockNesting)(r0)
	b.ori  	r6,r0,255	  # movsi imm J
	b.beq   	r7,r6,.L9
	.stabn	68,0,378,.LM9-.LFBB2
.LM9:
	b.addi  	r7,r7,1
	bw.sb    	(_OSLockNesting)(r0),r7	   # movqi store
.L9:
	.stabn	68,0,380,.LM10-.LFBB2
.LM10:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
.L11:
	.stabn	68,0,382,.LM11-.LFBB2
.LM11:
	b.jr    	r9
	.size	_OSSchedLock, .-_OSSchedLock
	.stabs	"val:r(0,4)",64,0,376,5
	.stabn	192,0,0,.LBB2-.LFBB2
	.stabn	224,0,0,.LBE2-.LFBB2
.Lscope2:
	.stabs	"",36,0,0,.Lscope2-.LFBB2
	.stabd	78,0,0
.proc _OSVersion
	.stabs	"OSVersion:F(2,4)",36,0,603,_OSVersion
	.global _OSVersion
	.type	_OSVersion, @function
_OSVersion:
	.stabd	46,0,0
	.stabn	68,0,603,.LM12-.LFBB3
.LM12:
.LFBB3:
	.stabn	68,0,605,.LM13-.LFBB3
.LM13:
	b.addi 	r3,r0,277	  # movsi imm I
	b.jr    	r9
	.size	_OSVersion, .-_OSVersion
.Lscope3:
	.stabs	"",36,0,0,.Lscope3-.LFBB3
	.stabd	78,0,0
.proc _OS_Dummy
	.stabs	"OS_Dummy:F(0,15)",36,0,622,_OS_Dummy
	.global _OS_Dummy
	.type	_OS_Dummy, @function
_OS_Dummy:
	.stabd	46,0,0
	.stabn	68,0,622,.LM14-.LFBB4
.LM14:
.LFBB4:
	.stabn	68,0,623,.LM15-.LFBB4
.LM15:
	b.jr    	r9
	.size	_OS_Dummy, .-_OS_Dummy
.Lscope4:
	.stabs	"",36,0,0,.Lscope4-.LFBB4
	.stabd	78,0,0
.proc _OS_EventTaskRdy
	.stabs	"OS_EventTaskRdy:F(2,2)",36,0,650,_OS_EventTaskRdy
	.stabs	"pevent:P(1,14)",64,0,649,3
	.stabs	"msg:P(1,2)",64,0,649,4
	.stabs	"msk:P(2,2)",64,0,649,27
	.global _OS_EventTaskRdy
	.type	_OS_EventTaskRdy, @function
_OS_EventTaskRdy:
	.stabd	46,0,0
	.stabn	68,0,650,.LM16-.LFBB5
.LM16:
.LFBB5:
	b.mov  	r27,r5	     # movsi
	.stabn	68,0,658,.LM17-.LFBB5
.LM17:
	b.lbz   	r7,1(r3)
	b.ori  	r5,r0,_OSUnMapTbl	  # movsi imm i
	b.add   	r7,r7,r5
	b.lbz   	r23,0(r7)
	.stabn	68,0,659,.LM18-.LFBB5
.LM18:
	b.mov  	r24,r23	     # movsi
	b.ori  	r6,r0,_OSMapTbl	  # movsi imm i
	b.add   	r7,r23,r6
	b.lbz   	r26,0(r7)
	.stabn	68,0,660,.LM19-.LFBB5
.LM19:
	b.add   	r4,r23,r3
	b.lbz   	r7,8(r4)
	b.add   	r5,r5,r7
	b.lbz   	r5,0(r5)
	.stabn	68,0,661,.LM20-.LFBB5
.LM20:
	b.add   	r6,r6,r5
	b.lbz   	r25,0(r6)
	.stabn	68,0,663,.LM21-.LFBB5
.LM21:
	b.nand  	r6,r25,r25
	b.and   	r7,r7,r6
	b.extbs 	r7,r7
	b.sb    	8(r4),r7	   # movqi store
	.stabn	68,0,664,.LM22-.LFBB5
.LM22:
	b.bnei  	r7,0,.L17
	.stabn	68,0,665,.LM23-.LFBB5
.LM23:
	b.nand  	r7,r26,r26
	b.lbz   	r6,1(r3)
	b.and   	r7,r6,r7
	b.sb    	1(r3),r7	   # movqi store
.L17:
	.stabn	68,0,667,.LM24-.LFBB5
.LM24:
	b.slli  	r7,r24,3
	b.add   	r7,r7,r5
	b.extbz 	r3,r7
	b.slli  	r7,r3,2
	b.addi  	r7,r7,_OSTCBPrioTbl
	b.lwz   	r6,0(r7)	    # movsi load
	.stabn	68,0,668,.LM25-.LFBB5
.LM25:
	b.sh    	32(r6),r0	   # movhi store
	.stabn	68,0,669,.LM26-.LFBB5
.LM26:
	b.sw    	28(r6),r0	   # movsi store
	.stabn	68,0,675,.LM27-.LFBB5
.LM27:
	b.sb    	35(r6),r0	   # movqi store
	.stabn	68,0,676,.LM28-.LFBB5
.LM28:
	b.nand  	r7,r27,r27
	b.lbz   	r5,34(r6)
	b.and   	r7,r7,r5
	b.extbs 	r7,r7
	b.sb    	34(r6),r7	   # movqi store
	.stabn	68,0,677,.LM29-.LFBB5
.LM29:
	b.bnei  	r7,0,.L19
	.stabn	68,0,678,.LM30-.LFBB5
.LM30:
	bw.lbz   	r6,(_OSRdyGrp)(r0)
	b.or    	r7,r26,r6
	bw.sb    	(_OSRdyGrp)(r0),r7	   # movqi store
	.stabn	68,0,679,.LM31-.LFBB5
.LM31:
	b.addi  	r6,r23,_OSRdyTbl
	b.lbz   	r5,0(r6)
	b.or    	r7,r25,r5
	b.sb    	0(r6),r7	   # movqi store
.L19:
	.stabn	68,0,682,.LM32-.LFBB5
.LM32:
	b.jr    	r9
	.size	_OS_EventTaskRdy, .-_OS_EventTaskRdy
	.stabs	"ptcb:r(0,16)=*(1,15)",64,0,651,6
	.stabs	"x:r(2,2)",64,0,652,5
	.stabs	"y:r(2,2)",64,0,653,24
	.stabs	"bitx:r(2,2)",64,0,654,25
	.stabs	"bity:r(2,2)",64,0,655,26
	.stabn	192,0,0,.LFBB5-.LFBB5
	.stabn	224,0,0,.Lscope5-.LFBB5
.Lscope5:
	.stabs	"",36,0,0,.Lscope5-.LFBB5
	.stabd	78,0,0
.proc _OS_EventTaskWait
	.stabs	"OS_EventTaskWait:F(0,15)",36,0,701,_OS_EventTaskWait
	.stabs	"pevent:P(1,14)",64,0,700,3
	.global _OS_EventTaskWait
	.type	_OS_EventTaskWait, @function
_OS_EventTaskWait:
	.stabd	46,0,0
	.stabn	68,0,701,.LM33-.LFBB6
.LM33:
.LFBB6:
	.stabn	68,0,704,.LM34-.LFBB6
.LM34:
	bw.lwz   	r7,(_OSTCBCur)(r0)	    # movsi load
	b.sw    	28(r7),r3	   # movsi store
	.stabn	68,0,705,.LM35-.LFBB6
.LM35:
	bw.lwz   	r5,(_OSTCBCur)(r0)	    # movsi load
	.stabn	68,0,706,.LM36-.LFBB6
.LM36:
	b.lbz   	r23,38(r5)
	b.lbz   	r4,39(r5)
	b.addi  	r6,r23,_OSRdyTbl
	b.nand  	r7,r4,r4
	b.lbz   	r24,0(r6)
	b.and   	r7,r7,r24
	b.extbs 	r7,r7
	b.sb    	0(r6),r7	   # movqi store
	.stabn	68,0,707,.LM37-.LFBB6
.LM37:
	b.bnei  	r7,0,.L23
	.stabn	68,0,708,.LM38-.LFBB6
.LM38:
	b.lbz   	r7,40(r5)
	b.nand  	r7,r7,r7
	bw.lbz   	r5,(_OSRdyGrp)(r0)
	b.and   	r7,r5,r7
	bw.sb    	(_OSRdyGrp)(r0),r7	   # movqi store
.L23:
	.stabn	68,0,710,.LM39-.LFBB6
.LM39:
	b.add   	r6,r23,r3
	b.lbz   	r24,8(r6)
	b.or    	r7,r4,r24
	b.sb    	8(r6),r7	   # movqi store
	.stabn	68,0,711,.LM40-.LFBB6
.LM40:
	bw.lwz   	r7,(_OSTCBCur)(r0)	    # movsi load
	b.lbz   	r5,1(r3)
	b.lbz   	r7,40(r7)
	b.or    	r7,r5,r7
	b.sb    	1(r3),r7	   # movqi store
	.stabn	68,0,712,.LM41-.LFBB6
.LM41:
	b.jr    	r9
	.size	_OS_EventTaskWait, .-_OS_EventTaskWait
.Lscope6:
	.stabs	"",36,0,0,.Lscope6-.LFBB6
	.stabd	78,0,0
.proc _OS_EventTO
	.stabs	"OS_EventTO:F(0,15)",36,0,731,_OS_EventTO
	.stabs	"pevent:P(1,14)",64,0,730,3
	.global _OS_EventTO
	.type	_OS_EventTO, @function
_OS_EventTO:
	.stabd	46,0,0
	.stabn	68,0,731,.LM42-.LFBB7
.LM42:
.LFBB7:
	.stabn	68,0,734,.LM43-.LFBB7
.LM43:
	bw.lwz   	r7,(_OSTCBCur)(r0)	    # movsi load
	.stabn	68,0,735,.LM44-.LFBB7
.LM44:
	b.lbz   	r6,38(r7)
	b.add   	r6,r6,r3
	b.lbz   	r7,39(r7)
	b.nand  	r7,r7,r7
	b.lbz   	r5,8(r6)
	b.and   	r7,r7,r5
	b.extbs 	r7,r7
	b.sb    	8(r6),r7	   # movqi store
	.stabn	68,0,736,.LM45-.LFBB7
.LM45:
	b.bnei  	r7,0,.L27
	.stabn	68,0,737,.LM46-.LFBB7
.LM46:
	bw.lwz   	r7,(_OSTCBCur)(r0)	    # movsi load
	b.lbz   	r7,40(r7)
	b.nand  	r7,r7,r7
	b.lbz   	r6,1(r3)
	b.and   	r7,r6,r7
	b.sb    	1(r3),r7	   # movqi store
.L27:
	.stabn	68,0,739,.LM47-.LFBB7
.LM47:
	bw.lwz   	r7,(_OSTCBCur)(r0)	    # movsi load
	b.sb    	35(r7),r0	   # movqi store
	.stabn	68,0,740,.LM48-.LFBB7
.LM48:
	bw.lwz   	r7,(_OSTCBCur)(r0)	    # movsi load
	b.sb    	34(r7),r0	   # movqi store
	.stabn	68,0,741,.LM49-.LFBB7
.LM49:
	bw.lwz   	r7,(_OSTCBCur)(r0)	    # movsi load
	b.sw    	28(r7),r0	   # movsi store
	.stabn	68,0,742,.LM50-.LFBB7
.LM50:
	b.jr    	r9
	.size	_OS_EventTO, .-_OS_EventTO
.Lscope7:
	.stabs	"",36,0,0,.Lscope7-.LFBB7
	.stabd	78,0,0
.proc _OS_EventWaitListInit
	.stabs	"OS_EventWaitListInit:F(0,15)",36,0,760,_OS_EventWaitListInit
	.stabs	"pevent:P(1,14)",64,0,759,3
	.global _OS_EventWaitListInit
	.type	_OS_EventWaitListInit, @function
_OS_EventWaitListInit:
	.stabd	46,0,0
	.stabn	68,0,760,.LM51-.LFBB8
.LM51:
.LFBB8:
	.stabn	68,0,763,.LM52-.LFBB8
.LM52:
	b.sb    	1(r3),r0	   # movqi store
	.stabn	68,0,767,.LM53-.LFBB8
.LM53:
	b.sb    	8(r3),r0	   # movqi store
	.stabn	68,0,797,.LM54-.LFBB8
.LM54:
	b.jr    	r9
	.size	_OS_EventWaitListInit, .-_OS_EventWaitListInit
.Lscope8:
	.stabs	"",36,0,0,.Lscope8-.LFBB8
	.stabd	78,0,0
.proc _OS_MemClr
	.stabs	"OS_MemClr:F(0,15)",36,0,1085,_OS_MemClr
	.stabs	"pdest:P(0,17)=*(2,2)",64,0,1085,3
	.stabs	"size:P(2,4)",64,0,1085,4
	.global _OS_MemClr
	.type	_OS_MemClr, @function
_OS_MemClr:
	.stabd	46,0,0
	.stabn	68,0,1085,.LM55-.LFBB9
.LM55:
.LFBB9:
	.stabn	68,0,1086,.LM56-.LFBB9
.LM56:
	b.beqi  	r4,0,.L35
.L36:
	.stabn	68,0,1087,.LM57-.LFBB9
.LM57:
	b.sb    	0(r3),r0	   # movqi store
	b.addi  	r3,r3,1
	.stabn	68,0,1088,.LM58-.LFBB9
.LM58:
	b.addi  	r7,r4,-1
	b.exthz 	r4,r7
	.stabn	68,0,1086,.LM59-.LFBB9
.LM59:
	b.bnei  	r4,0,.L36
.L35:
	.stabn	68,0,1090,.LM60-.LFBB9
.LM60:
	b.jr    	r9
	.size	_OS_MemClr, .-_OS_MemClr
.Lscope9:
	.stabs	"",36,0,0,.Lscope9-.LFBB9
	.stabd	78,0,0
.proc _OS_MemCopy
	.stabs	"OS_MemCopy:F(0,15)",36,0,1116,_OS_MemCopy
	.stabs	"pdest:P(0,17)",64,0,1116,3
	.stabs	"psrc:P(0,17)",64,0,1116,4
	.stabs	"size:P(2,4)",64,0,1116,5
	.global _OS_MemCopy
	.type	_OS_MemCopy, @function
_OS_MemCopy:
	.stabd	46,0,0
	.stabn	68,0,1116,.LM61-.LFBB10
.LM61:
.LFBB10:
	.stabn	68,0,1117,.LM62-.LFBB10
.LM62:
	b.beqi  	r5,0,.L41
.L42:
	.stabn	68,0,1118,.LM63-.LFBB10
.LM63:
	b.lbz   	r7,0(r4)
	b.sb    	0(r3),r7	   # movqi store
	b.addi  	r3,r3,1
	b.addi  	r4,r4,1
	.stabn	68,0,1119,.LM64-.LFBB10
.LM64:
	b.addi  	r7,r5,-1
	b.exthz 	r5,r7
	.stabn	68,0,1117,.LM65-.LFBB10
.LM65:
	b.bnei  	r5,0,.L42
.L41:
	.stabn	68,0,1121,.LM66-.LFBB10
.LM66:
	b.jr    	r9
	.size	_OS_MemCopy, .-_OS_MemCopy
.Lscope10:
	.stabs	"",36,0,0,.Lscope10-.LFBB10
	.stabd	78,0,0
.proc _OS_Sched
	.stabs	"OS_Sched:F(0,15)",36,0,1140,_OS_Sched
	.global _OS_Sched
	.type	_OS_Sched, @function
_OS_Sched:
	.stabd	46,0,0
	.stabn	68,0,1140,.LM67-.LFBB11
.LM67:
.LFBB11:
.LBB3:
	.stabn	68,0,1147,.LM68-.LFBB11
.LM68:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r4,r7,0
.LBE3:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r4,-7
	l.mtspr r6,r7,0
	.stabn	68,0,1148,.LM69-.LFBB11
.LM69:
	bw.lbz   	r7,(_OSIntNesting)(r0)
	b.bnei  	r7,0,.L45
	.stabn	68,0,1149,.LM70-.LFBB11
.LM70:
	bw.lbz   	r7,(_OSLockNesting)(r0)
	b.bnei  	r7,0,.L45
	.stabn	68,0,1150,.LM71-.LFBB11
.LM71:
	bw.lbz   	r7,(_OSRdyGrp)(r0)
	b.ori  	r5,r0,_OSUnMapTbl	  # movsi imm i
	b.add   	r7,r7,r5
	b.lbz   	r6,0(r7)
	.stabn	68,0,1151,.LM72-.LFBB11
.LM72:
	b.addi  	r7,r6,_OSRdyTbl
	b.lbz   	r7,0(r7)
	b.add   	r7,r7,r5
	b.slli  	r6,r6,3
	b.lbz   	r7,0(r7)
	b.add   	r6,r6,r7
	b.extbz 	r6,r6
	bw.sb    	(_OSPrioHighRdy)(r0),r6	   # movqi store
	.stabn	68,0,1152,.LM73-.LFBB11
.LM73:
	bw.lbz   	r7,(_OSPrioCur)(r0)
	b.beq   	r7,r6,.L45
	.stabn	68,0,1153,.LM74-.LFBB11
.LM74:
	b.slli  	r7,r6,2
	b.addi  	r7,r7,_OSTCBPrioTbl
	b.lwz   	r6,0(r7)	    # movsi load
	bw.sw    	(_OSTCBHighRdy)(r0),r6	   # movsi store
	.stabn	68,0,1155,.LM75-.LFBB11
.LM75:
	b.lwz   	r7,44(r6)	    # movsi load
	b.addi  	r7,r7,1
	b.sw    	44(r6),r7	   # movsi store
	.stabn	68,0,1157,.LM76-.LFBB11
.LM76:
	bw.lwz   	r7,(_OSCtxSwCtr)(r0)	    # movsi load
	b.addi  	r7,r7,1
	bw.sw    	(_OSCtxSwCtr)(r0),r7	   # movsi store
	.stabn	68,0,1158,.LM77-.LFBB11
.LM77:
	l.sys
l.nop 0

.L45:
	.stabn	68,0,1162,.LM78-.LFBB11
.LM78:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r4,0
	.stabn	68,0,1163,.LM79-.LFBB11
.LM79:
	b.jr    	r9
	.size	_OS_Sched, .-_OS_Sched
	.stabs	"y:r(2,2)",64,0,1141,6
	.stabn	192,0,0,.LFBB11-.LFBB11
	.stabs	"val:r(0,4)",64,0,1147,4
	.stabn	192,0,0,.LBB3-.LFBB11
	.stabn	224,0,0,.LBE3-.LFBB11
	.stabn	224,0,0,.Lscope11-.LFBB11
.Lscope11:
	.stabs	"",36,0,0,.Lscope11-.LFBB11
	.stabd	78,0,0
.proc _OSSchedUnlock
	.stabs	"OSSchedUnlock:F(0,15)",36,0,403,_OSSchedUnlock
	.global _OSSchedUnlock
	.type	_OSSchedUnlock, @function
_OSSchedUnlock:
	.stabd	46,0,0
	.stabn	68,0,403,.LM80-.LFBB12
.LM80:
.LFBB12:
	b.entri 	1,0
	.stabn	68,0,409,.LM81-.LFBB12
.LM81:
	bw.lbz   	r7,(_OSRunning)(r0)
	b.bnei  	r7,1,.L59
.LBB4:
	.stabn	68,0,410,.LM82-.LFBB12
.LM82:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r5,r7,0
.LBE4:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r5,-7
	l.mtspr r6,r7,0
	.stabn	68,0,411,.LM83-.LFBB12
.LM83:
	bw.lbz   	r7,(_OSLockNesting)(r0)
	b.beqi  	r7,0,.L53
	.stabn	68,0,412,.LM84-.LFBB12
.LM84:
	b.addi  	r7,r7,-1
	b.extbz 	r7,r7
	bw.sb    	(_OSLockNesting)(r0),r7	   # movqi store
	.stabn	68,0,413,.LM85-.LFBB12
.LM85:
	b.bnei  	r7,0,.L55
	.stabn	68,0,414,.LM86-.LFBB12
.LM86:
	bw.lbz   	r7,(_OSIntNesting)(r0)
	b.bnei  	r7,0,.L57
	.stabn	68,0,415,.LM87-.LFBB12
.LM87:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	.stabn	68,0,416,.LM88-.LFBB12
.LM88:
	b.jal  	_OS_Sched
	b.j    	.L59
.L57:
	.stabn	68,0,418,.LM89-.LFBB12
.LM89:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	b.j    	.L59
.L55:
	.stabn	68,0,421,.LM90-.LFBB12
.LM90:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	b.j    	.L59
.L53:
	.stabn	68,0,424,.LM91-.LFBB12
.LM91:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
.L59:
	.stabn	68,0,427,.LM92-.LFBB12
.LM92:
	b.reti  	1,0
	.size	_OSSchedUnlock, .-_OSSchedUnlock
	.stabs	"val:r(0,4)",64,0,410,5
	.stabn	192,0,0,.LBB4-.LFBB12
	.stabn	224,0,0,.LBE4-.LFBB12
.Lscope12:
	.stabs	"",36,0,0,.Lscope12-.LFBB12
	.stabd	78,0,0
.proc _OS_StrCopy
	.stabs	"OS_StrCopy:F(2,2)",36,0,1186,_OS_StrCopy
	.stabs	"pdest:P(0,18)=*(0,2)",64,0,1185,3
	.stabs	"psrc:P(0,18)",64,0,1185,4
	.global _OS_StrCopy
	.type	_OS_StrCopy, @function
_OS_StrCopy:
	.stabd	46,0,0
	.stabn	68,0,1186,.LM93-.LFBB13
.LM93:
.LFBB13:
	.stabn	68,0,1190,.LM94-.LFBB13
.LM94:
	b.lbz   	r7,0(r4)
	b.extbs 	r7,r7
	b.movi 	r6,0	     # movsi imm P
	b.beqi  	r7,0,.L63
	b.movi 	r6,0	     # movsi imm P
.L64:
	.stabn	68,0,1191,.LM95-.LFBB13
.LM95:
	b.sb    	0(r3),r7	   # movqi store
	b.addi  	r3,r3,1
	b.addi  	r4,r4,1
	.stabn	68,0,1192,.LM96-.LFBB13
.LM96:
	b.addi  	r7,r6,1
	b.extbz 	r6,r7
	.stabn	68,0,1190,.LM97-.LFBB13
.LM97:
	b.lbz   	r7,0(r4)
	b.extbs 	r7,r7
	b.bnei  	r7,0,.L64
.L63:
	.stabn	68,0,1194,.LM98-.LFBB13
.LM98:
	b.sb    	0(r3),r0	   # movqi store
	.stabn	68,0,1196,.LM99-.LFBB13
.LM99:
	b.mov  	r3,r6	     # movsi
	b.jr    	r9
	.size	_OS_StrCopy, .-_OS_StrCopy
	.stabs	"len:r(2,2)",64,0,1187,6
	.stabn	192,0,0,.LFBB13-.LFBB13
	.stabn	224,0,0,.Lscope13-.LFBB13
.Lscope13:
	.stabs	"",36,0,0,.Lscope13-.LFBB13
	.stabd	78,0,0
.proc _OSEventNameGet
	.stabs	"OSEventNameGet:F(2,2)",36,0,104,_OSEventNameGet
	.stabs	"pevent:P(1,14)",64,0,103,23
	.stabs	"pname:P(0,18)",64,0,103,3
	.stabs	"err:P(0,17)",64,0,103,11
	.global _OSEventNameGet
	.type	_OSEventNameGet, @function
_OSEventNameGet:
	.stabd	46,0,0
	.stabn	68,0,104,.LM100-.LFBB14
.LM100:
.LFBB14:
	b.entri 	3,0
	b.mov  	r23,r3	     # movsi
	b.mov  	r3,r4	     # movsi
	b.mov  	r11,r5	     # movsi
.LBB5:
	.stabn	68,0,111,.LM101-.LFBB14
.LM101:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r10,r7,0
.LBE5:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r10,-7
	l.mtspr r6,r7,0
	.stabn	68,0,113,.LM102-.LFBB14
.LM102:
	b.bnei  	r23,0,.L68
	.stabn	68,0,114,.LM103-.LFBB14
.LM103:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r10,0
	.stabn	68,0,115,.LM104-.LFBB14
.LM104:
	b.movi  	r7,4	    # movqi imm P
	b.sb    	0(r5),r7	   # movqi store
	b.movi 	r3,0	     # movsi imm P
	b.j    	.L70
.L68:
	.stabn	68,0,118,.LM105-.LFBB14
.LM105:
	b.bnei  	r4,0,.L71
	.stabn	68,0,119,.LM106-.LFBB14
.LM106:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r10,0
	.stabn	68,0,120,.LM107-.LFBB14
.LM107:
	b.ori   	r7,r0,15	 # movqi imm J
	b.sb    	0(r5),r7	   # movqi store
	b.j    	.L70
.L71:
	.stabn	68,0,124,.LM108-.LFBB14
.LM108:
	b.lbz   	r7,0(r23)
	b.addi  	r7,r7,-1
	b.bleui  	r7,3,.L74
	.stabn	68,0,132,.LM109-.LFBB14
.LM109:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r10,0
	.stabn	68,0,133,.LM110-.LFBB14
.LM110:
	b.movi  	r7,1	    # movqi imm P
	b.sb    	0(r5),r7	   # movqi store
	b.movi 	r3,0	     # movsi imm P
	b.j    	.L70
.L74:
	.stabn	68,0,136,.LM111-.LFBB14
.LM111:
	b.addi  	r4,r23,9
	b.jal  	_OS_StrCopy
	.stabn	68,0,137,.LM112-.LFBB14
.LM112:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r10,0
	.stabn	68,0,138,.LM113-.LFBB14
.LM113:
	b.sb    	0(r11),r0	   # movqi store
.L70:
	.stabn	68,0,140,.LM114-.LFBB14
.LM114:
	b.reti  	3,0
	.size	_OSEventNameGet, .-_OSEventNameGet
	.stabs	"len:r(2,2)",64,0,105,3
	.stabn	192,0,0,.LFBB14-.LFBB14
	.stabs	"val:r(0,4)",64,0,111,10
	.stabn	192,0,0,.LBB5-.LFBB14
	.stabn	224,0,0,.LBE5-.LFBB14
	.stabn	224,0,0,.Lscope14-.LFBB14
.Lscope14:
	.stabs	"",36,0,0,.Lscope14-.LFBB14
	.stabd	78,0,0
.proc _OS_StrLen
	.stabs	"OS_StrLen:F(2,2)",36,0,1217,_OS_StrLen
	.stabs	"psrc:P(0,18)",64,0,1216,3
	.global _OS_StrLen
	.type	_OS_StrLen, @function
_OS_StrLen:
	.stabd	46,0,0
	.stabn	68,0,1217,.LM115-.LFBB15
.LM115:
.LFBB15:
	.stabn	68,0,1221,.LM116-.LFBB15
.LM116:
	b.movi 	r7,0	     # movsi imm P
	b.lbz   	r6,0(r3)
	b.beqi  	r6,0,.L79
	b.movi 	r7,0	     # movsi imm P
.L80:
	.stabn	68,0,1222,.LM117-.LFBB15
.LM117:
	b.addi  	r3,r3,1
	.stabn	68,0,1223,.LM118-.LFBB15
.LM118:
	b.addi  	r7,r7,1
	b.extbz 	r7,r7
	.stabn	68,0,1221,.LM119-.LFBB15
.LM119:
	b.lbz   	r6,0(r3)
	b.bnei  	r6,0,.L80
.L79:
	.stabn	68,0,1226,.LM120-.LFBB15
.LM120:
	b.mov  	r3,r7	     # movsi
	b.jr    	r9
	.size	_OS_StrLen, .-_OS_StrLen
	.stabs	"len:r(2,2)",64,0,1218,7
	.stabn	192,0,0,.LFBB15-.LFBB15
	.stabn	224,0,0,.Lscope15-.LFBB15
.Lscope15:
	.stabs	"",36,0,0,.Lscope15-.LFBB15
	.stabd	78,0,0
.proc _OSEventNameSet
	.stabs	"OSEventNameSet:F(0,15)",36,0,172,_OSEventNameSet
	.stabs	"pevent:P(1,14)",64,0,171,11
	.stabs	"pname:P(0,18)",64,0,171,12
	.stabs	"err:P(0,17)",64,0,171,13
	.global _OSEventNameSet
	.type	_OSEventNameSet, @function
_OSEventNameSet:
	.stabd	46,0,0
	.stabn	68,0,172,.LM121-.LFBB16
.LM121:
.LFBB16:
	b.entri 	5,0
	b.mov  	r11,r3	     # movsi
	b.mov  	r12,r4	     # movsi
	b.mov  	r13,r5	     # movsi
.LBB6:
	.stabn	68,0,179,.LM122-.LFBB16
.LM122:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r10,r7,0
.LBE6:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r10,-7
	l.mtspr r6,r7,0
	.stabn	68,0,181,.LM123-.LFBB16
.LM123:
	b.bnei  	r3,0,.L84
	.stabn	68,0,182,.LM124-.LFBB16
.LM124:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r10,0
	.stabn	68,0,183,.LM125-.LFBB16
.LM125:
	b.movi  	r7,4	    # movqi imm P
	b.sb    	0(r5),r7	   # movqi store
	b.j    	.L93
.L84:
	.stabn	68,0,186,.LM126-.LFBB16
.LM126:
	b.bnei  	r4,0,.L87
	.stabn	68,0,187,.LM127-.LFBB16
.LM127:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r10,0
	.stabn	68,0,188,.LM128-.LFBB16
.LM128:
	b.ori   	r7,r0,15	 # movqi imm J
	b.sb    	0(r5),r7	   # movqi store
	b.j    	.L93
.L87:
	.stabn	68,0,192,.LM129-.LFBB16
.LM129:
	b.lbz   	r7,0(r3)
	b.addi  	r7,r7,-1
	b.bleui  	r7,3,.L90
	.stabn	68,0,200,.LM130-.LFBB16
.LM130:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r10,0
	.stabn	68,0,201,.LM131-.LFBB16
.LM131:
	b.movi  	r7,1	    # movqi imm P
	b.sb    	0(r5),r7	   # movqi store
	b.j    	.L93
.L90:
	.stabn	68,0,204,.LM132-.LFBB16
.LM132:
	b.mov  	r3,r4	     # movsi
	b.jal  	_OS_StrLen
	.stabn	68,0,205,.LM133-.LFBB16
.LM133:
	b.ori  	r7,r0,31	  # movsi imm J
	b.bleu   	r3,r7,.L91
	.stabn	68,0,206,.LM134-.LFBB16
.LM134:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r10,0
	.stabn	68,0,207,.LM135-.LFBB16
.LM135:
	b.ori   	r7,r0,12	 # movqi imm J
	b.sb    	0(r13),r7	   # movqi store
	b.j    	.L93
.L91:
	.stabn	68,0,210,.LM136-.LFBB16
.LM136:
	b.addi  	r3,r11,9
	b.mov  	r4,r12	     # movsi
	b.jal  	_OS_StrCopy
	.stabn	68,0,211,.LM137-.LFBB16
.LM137:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r10,0
	.stabn	68,0,212,.LM138-.LFBB16
.LM138:
	b.sb    	0(r13),r0	   # movqi store
.L93:
	.stabn	68,0,213,.LM139-.LFBB16
.LM139:
	b.reti  	5,0
	.size	_OSEventNameSet, .-_OSEventNameSet
	.stabs	"val:r(0,4)",64,0,179,10
	.stabn	192,0,0,.LBB6-.LFBB16
	.stabn	224,0,0,.LBE6-.LFBB16
.Lscope16:
	.stabs	"",36,0,0,.Lscope16-.LFBB16
	.stabd	78,0,0
.proc _OS_TCBInit
	.stabs	"OS_TCBInit:F(2,2)",36,0,1416,_OS_TCBInit
	.stabs	"prio:P(2,2)",64,0,1415,11
	.stabs	"ptos:P(1,12)",64,0,1415,4
	.stabs	"pbos:P(1,12)",64,0,1415,5
	.stabs	"id:P(2,4)",64,0,1415,26
	.stabs	"stk_size:P(2,6)",64,0,1416,24
	.stabs	"pext:P(1,2)",64,0,1416,8
	.stabs	"opt:p(2,4)",160,0,1416,14
	.global _OS_TCBInit
	.type	_OS_TCBInit, @function
_OS_TCBInit:
	.stabd	46,0,0
	.stabn	68,0,1416,.LM140-.LFBB17
.LM140:
.LFBB17:
	b.entri 	3,0
	b.mov  	r11,r3	     # movsi
	b.mov  	r26,r6	     # movsi
	b.mov  	r24,r7	     # movsi
	b.lhz   	r25,14(r1)
.LBB7:
	.stabn	68,0,1423,.LM141-.LFBB17
.LM141:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r23,r7,0
.LBE7:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r23,-7
	l.mtspr r6,r7,0
	.stabn	68,0,1424,.LM142-.LFBB17
.LM142:
	bw.lwz   	r10,(_OSTCBFreeList)(r0)	    # movsi load
	.stabn	68,0,1425,.LM143-.LFBB17
.LM143:
	b.beqi  	r10,0,.L95
	.stabn	68,0,1426,.LM144-.LFBB17
.LM144:
	b.lwz   	r7,20(r10)	    # movsi load
	bw.sw    	(_OSTCBFreeList)(r0),r7	   # movsi store
	.stabn	68,0,1427,.LM145-.LFBB17
.LM145:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r23,0
	.stabn	68,0,1428,.LM146-.LFBB17
.LM146:
	b.sw    	0(r10),r4	   # movsi store
	.stabn	68,0,1429,.LM147-.LFBB17
.LM147:
	b.sb    	36(r10),r3	   # movqi store
	.stabn	68,0,1430,.LM148-.LFBB17
.LM148:
	b.sb    	34(r10),r0	   # movqi store
	.stabn	68,0,1431,.LM149-.LFBB17
.LM149:
	b.sb    	35(r10),r0	   # movqi store
	.stabn	68,0,1432,.LM150-.LFBB17
.LM150:
	b.sh    	32(r10),r0	   # movhi store
	.stabn	68,0,1435,.LM151-.LFBB17
.LM151:
	b.sw    	4(r10),r8	   # movsi store
	.stabn	68,0,1436,.LM152-.LFBB17
.LM152:
	b.sw    	12(r10),r24	   # movsi store
	.stabn	68,0,1437,.LM153-.LFBB17
.LM153:
	b.sw    	8(r10),r5	   # movsi store
	.stabn	68,0,1438,.LM154-.LFBB17
.LM154:
	b.sh    	16(r10),r25	   # movhi store
	.stabn	68,0,1439,.LM155-.LFBB17
.LM155:
	b.sh    	18(r10),r26	   # movhi store
	.stabn	68,0,1449,.LM156-.LFBB17
.LM156:
	b.sb    	41(r10),r0	   # movqi store
	.stabn	68,0,1452,.LM157-.LFBB17
.LM157:
	b.srli  	r7,r3,3
	b.sb    	38(r10),r7	   # movqi store
	.stabn	68,0,1453,.LM158-.LFBB17
.LM158:
	b.ori  	r6,r0,_OSMapTbl	  # movsi imm i
	b.add   	r7,r7,r6
	b.lbz   	r7,0(r7)
	b.sb    	40(r10),r7	   # movqi store
	.stabn	68,0,1454,.LM159-.LFBB17
.LM159:
	b.andi  	r7,r3,7
	b.sb    	37(r10),r7	   # movqi store
	.stabn	68,0,1455,.LM160-.LFBB17
.LM160:
	b.add   	r7,r7,r6
	b.lbz   	r7,0(r7)
	b.sb    	39(r10),r7	   # movqi store
	.stabn	68,0,1458,.LM161-.LFBB17
.LM161:
	b.sw    	28(r10),r0	   # movsi store
	.stabn	68,0,1470,.LM162-.LFBB17
.LM162:
	b.sw    	44(r10),r0	   # movsi store
	.stabn	68,0,1471,.LM163-.LFBB17
.LM163:
	b.sw    	52(r10),r0	   # movsi store
	.stabn	68,0,1472,.LM164-.LFBB17
.LM164:
	b.sw    	48(r10),r0	   # movsi store
	.stabn	68,0,1473,.LM165-.LFBB17
.LM165:
	b.sw    	56(r10),r0	   # movsi store
	.stabn	68,0,1474,.LM166-.LFBB17
.LM166:
	b.sw    	60(r10),r0	   # movsi store
	.stabn	68,0,1478,.LM167-.LFBB17
.LM167:
	b.ori   	r7,r0,63	 # movqi imm J
	b.sb    	64(r10),r7	   # movqi store
	.stabn	68,0,1479,.LM168-.LFBB17
.LM168:
	b.sb    	65(r10),r0	   # movqi store
	.stabn	68,0,1483,.LM169-.LFBB17
.LM169:
	b.mov  	r3,r10	     # movsi
	b.jal  	_OSTCBInitHook
	.stabn	68,0,1486,.LM170-.LFBB17
.LM170:
	b.mov  	r3,r10	     # movsi
	b.jal  	_OSTaskCreateHook
.LBB8:
	.stabn	68,0,1488,.LM171-.LFBB17
.LM171:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r5,r7,0
.LBE8:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r5,-7
	l.mtspr r6,r7,0
	.stabn	68,0,1489,.LM172-.LFBB17
.LM172:
	b.slli  	r7,r11,2
	b.addi  	r7,r7,_OSTCBPrioTbl
	b.sw    	0(r7),r10	   # movsi store
	.stabn	68,0,1490,.LM173-.LFBB17
.LM173:
	bw.lwz   	r7,(_OSTCBList)(r0)	    # movsi load
	b.sw    	20(r10),r7	   # movsi store
	.stabn	68,0,1491,.LM174-.LFBB17
.LM174:
	b.sw    	24(r10),r0	   # movsi store
	.stabn	68,0,1492,.LM175-.LFBB17
.LM175:
	bw.lwz   	r7,(_OSTCBList)(r0)	    # movsi load
	b.beqi  	r7,0,.L97
	.stabn	68,0,1493,.LM176-.LFBB17
.LM176:
	b.sw    	24(r7),r10	   # movsi store
.L97:
	.stabn	68,0,1495,.LM177-.LFBB17
.LM177:
	bw.sw    	(_OSTCBList)(r0),r10	   # movsi store
	.stabn	68,0,1496,.LM178-.LFBB17
.LM178:
	bw.lbz   	r4,(_OSRdyGrp)(r0)
	b.lbz   	r6,40(r10)
	b.or    	r7,r4,r6
	bw.sb    	(_OSRdyGrp)(r0),r7	   # movqi store
	.stabn	68,0,1497,.LM179-.LFBB17
.LM179:
	b.lbz   	r7,38(r10)
	b.addi  	r7,r7,_OSRdyTbl
	b.lbz   	r4,0(r7)
	b.lbz   	r10,39(r10)
	b.or    	r6,r4,r10
	b.sb    	0(r7),r6	   # movqi store
	.stabn	68,0,1498,.LM180-.LFBB17
.LM180:
	bw.lbz   	r7,(_OSTaskCtr)(r0)
	b.addi  	r7,r7,1
	bw.sb    	(_OSTaskCtr)(r0),r7	   # movqi store
	.stabn	68,0,1499,.LM181-.LFBB17
.LM181:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	b.movi 	r3,0	     # movsi imm P
	b.j    	.L99
.L95:
	.stabn	68,0,1502,.LM182-.LFBB17
.LM182:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r23,0
	b.ori  	r3,r0,70	  # movsi imm J
.L99:
	.stabn	68,0,1504,.LM183-.LFBB17
.LM183:
	b.reti  	3,0
	.size	_OS_TCBInit, .-_OS_TCBInit
	.stabs	"ptcb:r(0,16)",64,0,1417,10
	.stabs	"opt:r(2,4)",64,0,1416,25
	.stabn	192,0,0,.LFBB17-.LFBB17
	.stabs	"val:r(0,4)",64,0,1423,23
	.stabn	192,0,0,.LBB7-.LFBB17
	.stabn	224,0,0,.LBE7-.LFBB17
	.stabs	"val:r(0,4)",64,0,1488,5
	.stabn	192,0,0,.LBB8-.LFBB17
	.stabn	224,0,0,.LBE8-.LFBB17
	.stabn	224,0,0,.Lscope17-.LFBB17
.Lscope17:
	.stabs	"",36,0,0,.Lscope17-.LFBB17
	.stabd	78,0,0
.proc _OS_TaskIdle
	.stabs	"OS_TaskIdle:F(0,15)",36,0,1250,_OS_TaskIdle
	.stabs	"parg:P(1,2)",64,0,1250,3
	.global _OS_TaskIdle
	.type	_OS_TaskIdle, @function
_OS_TaskIdle:
	.stabd	46,0,0
	.stabn	68,0,1250,.LM184-.LFBB18
.LM184:
.LFBB18:
	b.entri 	1,0
.L102:
.LBB9:
	.stabn	68,0,1258,.LM185-.LFBB18
.LM185:
	b.ori  	r6,r0,17	  # movsi imm J
	l.mfspr r6,r6,0
.LBE9:
	b.ori  	r5,r0,17	  # movsi imm J
	b.andi  	r7,r6,-7
	l.mtspr r5,r7,0
	.stabn	68,0,1259,.LM186-.LFBB18
.LM186:
	bw.lwz   	r7,(_OSIdleCtr)(r0)	    # movsi load
	b.addi  	r7,r7,1
	bw.sw    	(_OSIdleCtr)(r0),r7	   # movsi store
	.stabn	68,0,1260,.LM187-.LFBB18
.LM187:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r6,0
	.stabn	68,0,1261,.LM188-.LFBB18
.LM188:
	b.jal  	_OSTaskIdleHook
	b.j    	.L102
	.size	_OS_TaskIdle, .-_OS_TaskIdle
	.stabs	"val:r(0,4)",64,0,1258,6
	.stabn	192,0,0,.LBB9-.LFBB18
	.stabn	224,0,0,.LBE9-.LFBB18
.Lscope18:
	.stabs	"",36,0,0,.Lscope18-.LFBB18
	.stabd	78,0,0
.proc _OSTimeTick
	.stabs	"OSTimeTick:F(0,15)",36,0,520,_OSTimeTick
	.global _OSTimeTick
	.type	_OSTimeTick, @function
_OSTimeTick:
	.stabd	46,0,0
	.stabn	68,0,520,.LM189-.LFBB19
.LM189:
.LFBB19:
	b.entri 	1,0
	.stabn	68,0,531,.LM190-.LFBB19
.LM190:
	b.jal  	_OSTimeTickHook
.LBB10:
	.stabn	68,0,534,.LM191-.LFBB19
.LM191:
	b.ori  	r6,r0,17	  # movsi imm J
	l.mfspr r6,r6,0
.LBE10:
	b.ori  	r5,r0,17	  # movsi imm J
	b.andi  	r7,r6,-7
	l.mtspr r5,r7,0
	.stabn	68,0,535,.LM192-.LFBB19
.LM192:
	bw.lwz   	r7,(_OSTime)(r0)	    # movsi load
	b.addi  	r7,r7,1
	bw.sw    	(_OSTime)(r0),r7	   # movsi store
	.stabn	68,0,536,.LM193-.LFBB19
.LM193:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r6,0
	.stabn	68,0,539,.LM194-.LFBB19
.LM194:
	bw.lbz   	r6,(_OSRunning)(r0)
	b.bnei  	r6,1,.L118
	.stabn	68,0,541,.LM195-.LFBB19
.LM195:
	bw.lbz   	r7,(_OSTickStepState)(r0)
	b.beqi  	r7,1,.L118
	b.bltui  	r7,1,.L108
	.stabn	68,0,552,.LM196-.LFBB19
.LM196:
	b.sfeqi 	r7,2
	b.cmov  	r7,r6,r0
	bw.sb    	(_OSTickStepState)(r0),r7	   # movqi store
	b.j    	.L108
.L119:
.LBB11:
	.stabn	68,0,566,.LM197-.LFBB19
.LM197:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r4,r7,0
.LBE11:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r4,-7
	l.mtspr r6,r7,0
	.stabn	68,0,567,.LM198-.LFBB19
.LM198:
	b.lhz   	r7,32(r5)
	b.beqi  	r7,0,.L111
	.stabn	68,0,568,.LM199-.LFBB19
.LM199:
	b.addi  	r7,r7,-1
	b.exthz 	r7,r7
	b.sh    	32(r5),r7	   # movhi store
	b.bnei  	r7,0,.L111
	.stabn	68,0,570,.LM200-.LFBB19
.LM200:
	b.lbz   	r6,34(r5)
	b.andi  	r7,r6,55
	b.beqi  	r7,0,.L114
	.stabn	68,0,571,.LM201-.LFBB19
.LM201:
	b.andi  	r7,r6,-56
	b.sb    	34(r5),r7	   # movqi store
	.stabn	68,0,572,.LM202-.LFBB19
.LM202:
	b.movi  	r7,1	    # movqi imm P
	b.sb    	35(r5),r7	   # movqi store
	b.j    	.L116
.L114:
	.stabn	68,0,574,.LM203-.LFBB19
.LM203:
	b.sb    	35(r5),r0	   # movqi store
.L116:
	.stabn	68,0,577,.LM204-.LFBB19
.LM204:
	b.lbz   	r7,34(r5)
	b.andi  	r7,r7,8
	b.bnei  	r7,0,.L111
	.stabn	68,0,578,.LM205-.LFBB19
.LM205:
	bw.lbz   	r6,(_OSRdyGrp)(r0)
	b.lbz   	r24,40(r5)
	b.or    	r7,r6,r24
	bw.sb    	(_OSRdyGrp)(r0),r7	   # movqi store
	.stabn	68,0,579,.LM206-.LFBB19
.LM206:
	b.lbz   	r7,38(r5)
	b.add   	r7,r7,r23
	b.lbz   	r25,0(r7)
	b.lbz   	r24,39(r5)
	b.or    	r6,r25,r24
	b.sb    	0(r7),r6	   # movqi store
.L111:
	.stabn	68,0,583,.LM207-.LFBB19
.LM207:
	b.lwz   	r5,20(r5)	    # movsi load
	.stabn	68,0,584,.LM208-.LFBB19
.LM208:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r4,0
	.stabn	68,0,565,.LM209-.LFBB19
.LM209:
	b.lbz   	r7,36(r5)
	b.beqi  	r7,6,.L118
	b.j    	.L119
.L108:
	.stabn	68,0,564,.LM210-.LFBB19
.LM210:
	bw.lwz   	r5,(_OSTCBList)(r0)	    # movsi load
	.stabn	68,0,565,.LM211-.LFBB19
.LM211:
	b.lbz   	r7,36(r5)
	.stabn	68,0,579,.LM212-.LFBB19
.LM212:
	b.ori  	r23,r0,_OSRdyTbl	  # movsi imm i
	.stabn	68,0,565,.LM213-.LFBB19
.LM213:
	b.bnei  	r7,6,.L119
.L118:
	.stabn	68,0,587,.LM214-.LFBB19
.LM214:
	b.reti  	1,0
	.size	_OSTimeTick, .-_OSTimeTick
	.stabs	"ptcb:r(0,16)",64,0,521,5
	.stabn	192,0,0,.LFBB19-.LFBB19
	.stabs	"val:r(0,4)",64,0,534,6
	.stabn	192,0,0,.LBB10-.LFBB19
	.stabn	224,0,0,.LBE10-.LFBB19
	.stabs	"val:r(0,4)",64,0,566,4
	.stabn	192,0,0,.LBB11-.LFBB19
	.stabn	224,0,0,.LBE11-.LFBB19
	.stabn	224,0,0,.Lscope19-.LFBB19
.Lscope19:
	.stabs	"",36,0,0,.Lscope19-.LFBB19
	.stabd	78,0,0
.proc _OSStart
	.stabs	"OSStart:F(0,15)",36,0,451,_OSStart
	.global _OSStart
	.type	_OSStart, @function
_OSStart:
	.stabd	46,0,0
	.stabn	68,0,451,.LM215-.LFBB20
.LM215:
.LFBB20:
	b.entri 	1,0
	.stabn	68,0,455,.LM216-.LFBB20
.LM216:
	bw.lbz   	r7,(_OSRunning)(r0)
	b.bnei  	r7,0,.L124
	.stabn	68,0,456,.LM217-.LFBB20
.LM217:
	bw.lbz   	r7,(_OSRdyGrp)(r0)
	b.ori  	r5,r0,_OSUnMapTbl	  # movsi imm i
	b.add   	r7,r7,r5
	b.lbz   	r7,0(r7)
	.stabn	68,0,458,.LM218-.LFBB20
.LM218:
	b.addi  	r6,r7,_OSRdyTbl
	b.lbz   	r6,0(r6)
	b.add   	r6,r6,r5
	b.slli  	r7,r7,3
	b.lbz   	r6,0(r6)
	b.add   	r7,r7,r6
	b.extbz 	r7,r7
	bw.sb    	(_OSPrioHighRdy)(r0),r7	   # movqi store
	.stabn	68,0,459,.LM219-.LFBB20
.LM219:
	bw.sb    	(_OSPrioCur)(r0),r7	   # movqi store
	.stabn	68,0,460,.LM220-.LFBB20
.LM220:
	b.slli  	r7,r7,2
	b.addi  	r7,r7,_OSTCBPrioTbl
	b.lwz   	r7,0(r7)	    # movsi load
	bw.sw    	(_OSTCBHighRdy)(r0),r7	   # movsi store
	.stabn	68,0,461,.LM221-.LFBB20
.LM221:
	bw.sw    	(_OSTCBCur)(r0),r7	   # movsi store
	.stabn	68,0,462,.LM222-.LFBB20
.LM222:
	b.jal  	_OSStartHighRdy
.L124:
	.stabn	68,0,464,.LM223-.LFBB20
.LM223:
	b.reti  	1,0
	.size	_OSStart, .-_OSStart
	.stabs	"y:r(2,2)",64,0,452,7
	.stabn	192,0,0,.LFBB20-.LFBB20
	.stabn	224,0,0,.Lscope20-.LFBB20
.Lscope20:
	.stabs	"",36,0,0,.Lscope20-.LFBB20
	.stabd	78,0,0
.proc _OSIntExit
	.stabs	"OSIntExit:F(0,15)",36,0,321,_OSIntExit
	.global _OSIntExit
	.type	_OSIntExit, @function
_OSIntExit:
	.stabd	46,0,0
	.stabn	68,0,321,.LM224-.LFBB21
.LM224:
.LFBB21:
	b.entri 	2,0
	.stabn	68,0,328,.LM225-.LFBB21
.LM225:
	bw.lbz   	r7,(_OSRunning)(r0)
	b.bnei  	r7,1,.L133
.LBB12:
	.stabn	68,0,329,.LM226-.LFBB21
.LM226:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r10,r7,0
.LBE12:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r10,-7
	l.mtspr r6,r7,0
	.stabn	68,0,330,.LM227-.LFBB21
.LM227:
	bw.lbz   	r7,(_OSIntNesting)(r0)
	b.beqi  	r7,0,.L128
	.stabn	68,0,331,.LM228-.LFBB21
.LM228:
	b.addi  	r7,r7,-1
	b.extbz 	r7,r7
	bw.sb    	(_OSIntNesting)(r0),r7	   # movqi store
	.stabn	68,0,333,.LM229-.LFBB21
.LM229:
	b.bnei  	r7,0,.L130
.L128:
	.stabn	68,0,334,.LM230-.LFBB21
.LM230:
	bw.lbz   	r7,(_OSLockNesting)(r0)
	b.bnei  	r7,0,.L130
	.stabn	68,0,335,.LM231-.LFBB21
.LM231:
	bw.lbz   	r7,(_OSRdyGrp)(r0)
	b.ori  	r5,r0,_OSUnMapTbl	  # movsi imm i
	b.add   	r7,r7,r5
	b.lbz   	r6,0(r7)
	.stabn	68,0,336,.LM232-.LFBB21
.LM232:
	b.addi  	r7,r6,_OSRdyTbl
	b.lbz   	r7,0(r7)
	b.add   	r7,r7,r5
	b.slli  	r6,r6,3
	b.lbz   	r7,0(r7)
	b.add   	r6,r6,r7
	b.extbz 	r6,r6
	bw.sb    	(_OSPrioHighRdy)(r0),r6	   # movqi store
	.stabn	68,0,337,.LM233-.LFBB21
.LM233:
	bw.lbz   	r7,(_OSPrioCur)(r0)
	b.beq   	r7,r6,.L130
	.stabn	68,0,338,.LM234-.LFBB21
.LM234:
	b.slli  	r7,r6,2
	b.addi  	r7,r7,_OSTCBPrioTbl
	b.lwz   	r6,0(r7)	    # movsi load
	bw.sw    	(_OSTCBHighRdy)(r0),r6	   # movsi store
	.stabn	68,0,340,.LM235-.LFBB21
.LM235:
	b.lwz   	r7,44(r6)	    # movsi load
	b.addi  	r7,r7,1
	b.sw    	44(r6),r7	   # movsi store
	.stabn	68,0,342,.LM236-.LFBB21
.LM236:
	bw.lwz   	r7,(_OSCtxSwCtr)(r0)	    # movsi load
	b.addi  	r7,r7,1
	bw.sw    	(_OSCtxSwCtr)(r0),r7	   # movsi store
	.stabn	68,0,343,.LM237-.LFBB21
.LM237:
	b.jal  	_OSIntCtxSw
.L130:
	.stabn	68,0,347,.LM238-.LFBB21
.LM238:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r10,0
.L133:
	.stabn	68,0,349,.LM239-.LFBB21
.LM239:
	b.reti  	2,0
	.size	_OSIntExit, .-_OSIntExit
	.stabs	"y:r(2,2)",64,0,322,6
	.stabn	192,0,0,.LFBB21-.LFBB21
	.stabs	"val:r(0,4)",64,0,329,10
	.stabn	192,0,0,.LBB12-.LFBB21
	.stabn	224,0,0,.LBE12-.LFBB21
	.stabn	224,0,0,.Lscope21-.LFBB21
.Lscope21:
	.stabs	"",36,0,0,.Lscope21-.LFBB21
	.stabd	78,0,0
.proc _OSInit
	.stabs	"OSInit:F(0,15)",36,0,230,_OSInit
	.global _OSInit
	.type	_OSInit, @function
_OSInit:
	.stabd	46,0,0
	.stabn	68,0,230,.LM240-.LFBB22
.LM240:
.LFBB22:
	b.entri 	1,4
	.stabn	68,0,232,.LM241-.LFBB22
.LM241:
	b.jal  	_OSInitHookBegin
.LBB23:
.LBB24:
	.stabn	68,0,869,.LM242-.LFBB22
.LM242:
	bw.sw    	(_OSTime)(r0),r0	   # movsi store
	.stabn	68,0,872,.LM243-.LFBB22
.LM243:
	bw.sb    	(_OSIntNesting)(r0),r0	   # movqi store
	.stabn	68,0,873,.LM244-.LFBB22
.LM244:
	bw.sb    	(_OSLockNesting)(r0),r0	   # movqi store
	.stabn	68,0,875,.LM245-.LFBB22
.LM245:
	bw.sb    	(_OSTaskCtr)(r0),r0	   # movqi store
	.stabn	68,0,877,.LM246-.LFBB22
.LM246:
	bw.sb    	(_OSRunning)(r0),r0	   # movqi store
	.stabn	68,0,879,.LM247-.LFBB22
.LM247:
	bw.sw    	(_OSCtxSwCtr)(r0),r0	   # movsi store
	.stabn	68,0,880,.LM248-.LFBB22
.LM248:
	bw.sw    	(_OSIdleCtr)(r0),r0	   # movsi store
.LBE24:
.LBE23:
.LBB25:
.LBB26:
	.stabn	68,0,906,.LM249-.LFBB22
.LM249:
	bw.sb    	(_OSRdyGrp)(r0),r0	   # movqi store
	.stabn	68,0,909,.LM250-.LFBB22
.LM250:
	bw.sb    	(_OSRdyTbl)(r0),r0	   # movqi store
	.stabn	68,0,912,.LM251-.LFBB22
.LM251:
	bw.sb    	(_OSPrioCur)(r0),r0	   # movqi store
	.stabn	68,0,913,.LM252-.LFBB22
.LM252:
	bw.sb    	(_OSPrioHighRdy)(r0),r0	   # movqi store
	.stabn	68,0,915,.LM253-.LFBB22
.LM253:
	bw.sw    	(_OSTCBHighRdy)(r0),r0	   # movsi store
	.stabn	68,0,916,.LM254-.LFBB22
.LM254:
	bw.sw    	(_OSTCBCur)(r0),r0	   # movsi store
.LBE26:
.LBE25:
.LBB27:
.LBB28:
	.stabn	68,0,1042,.LM255-.LFBB22
.LM255:
	b.ori  	r3,r0,_OSTCBTbl	  # movsi imm i
	b.addi 	r4,r0,384	  # movsi imm I
	b.jal  	_OS_MemClr
	.stabn	68,0,1043,.LM256-.LFBB22
.LM256:
	b.ori  	r3,r0,_OSTCBPrioTbl	  # movsi imm i
	b.ori  	r4,r0,28	  # movsi imm J
	b.jal  	_OS_MemClr
	b.ori  	r7,r0,_OSTCBTbl+96	  # movsi imm i
	.stabn	68,0,230,.LM257-.LFBB22
.LM257:
	b.ori  	r23,r0,_OSTCBTbl	  # movsi imm i
	.stabn	68,0,1047,.LM258-.LFBB22
.LM258:
	b.ori  	r4,r0,_OSTCBTbl+384	  # movsi imm i
.L135:
	.stabn	68,0,1048,.LM259-.LFBB22
.LM259:
	bg.sw    	-76(r7),r7	   # movsi store
	.stabn	68,0,1050,.LM260-.LFBB22
.LM260:
	b.ori   	r5,r0,63	 # movqi imm J
	bg.sb    	-32(r7),r5	   # movqi store
	.stabn	68,0,1051,.LM261-.LFBB22
.LM261:
	bg.sb    	-31(r7),r0	   # movqi store
	.stabn	68,0,1054,.LM262-.LFBB22
.LM262:
	b.addi  	r7,r7,96
	.stabn	68,0,1047,.LM263-.LFBB22
.LM263:
	b.bne   	r7,r4,.L135
	.stabn	68,0,1056,.LM264-.LFBB22
.LM264:
	bw.sw    	(_OSTCBTbl+308)(r0),r0	   # movsi store
	.stabn	68,0,1058,.LM265-.LFBB22
.LM265:
	bw.sb    	(_OSTCBTbl+352)(r0),r5	   # movqi store
	.stabn	68,0,1059,.LM266-.LFBB22
.LM266:
	bw.sb    	(_OSTCBTbl+353)(r0),r0	   # movqi store
	.stabn	68,0,1061,.LM267-.LFBB22
.LM267:
	bw.sw    	(_OSTCBList)(r0),r0	   # movsi store
	.stabn	68,0,1062,.LM268-.LFBB22
.LM268:
	bw.sw    	(_OSTCBFreeList)(r0),r23	   # movsi store
.LBE28:
.LBE27:
.LBB29:
.LBB30:
	.stabn	68,0,821,.LM269-.LFBB22
.LM269:
	b.ori  	r3,r0,_OSEventTbl	  # movsi imm i
	b.addi 	r4,r0,440	  # movsi imm I
	b.jal  	_OS_MemClr
	b.ori  	r7,r0,_OSEventTbl+44	  # movsi imm i
	.stabn	68,0,230,.LM270-.LFBB22
.LM270:
	b.ori  	r23,r0,_OSEventTbl	  # movsi imm i
	.stabn	68,0,825,.LM271-.LFBB22
.LM271:
	b.ori  	r4,r0,_OSEventTbl+440	  # movsi imm i
.L137:
	.stabn	68,0,826,.LM272-.LFBB22
.LM272:
	bg.sb    	-44(r7),r0	   # movqi store
	.stabn	68,0,827,.LM273-.LFBB22
.LM273:
	bg.sw    	-40(r7),r7	   # movsi store
	.stabn	68,0,829,.LM274-.LFBB22
.LM274:
	b.ori   	r5,r0,63	 # movqi imm J
	bg.sb    	-35(r7),r5	   # movqi store
	.stabn	68,0,830,.LM275-.LFBB22
.LM275:
	bg.sb    	-34(r7),r0	   # movqi store
	.stabn	68,0,833,.LM276-.LFBB22
.LM276:
	b.addi  	r7,r7,44
	.stabn	68,0,825,.LM277-.LFBB22
.LM277:
	b.bne   	r7,r4,.L137
	.stabn	68,0,835,.LM278-.LFBB22
.LM278:
	bw.sb    	(_OSEventTbl+396)(r0),r0	   # movqi store
	.stabn	68,0,836,.LM279-.LFBB22
.LM279:
	bw.sw    	(_OSEventTbl+400)(r0),r0	   # movsi store
	.stabn	68,0,838,.LM280-.LFBB22
.LM280:
	bw.sb    	(_OSEventTbl+405)(r0),r5	   # movqi store
	.stabn	68,0,839,.LM281-.LFBB22
.LM281:
	bw.sb    	(_OSEventTbl+406)(r0),r0	   # movqi store
	.stabn	68,0,841,.LM282-.LFBB22
.LM282:
	bw.sw    	(_OSEventFreeList)(r0),r23	   # movsi store
.LBE30:
.LBE29:
.LBB31:
.LBB32:
	.stabn	68,0,936,.LM283-.LFBB22
.LM283:
	b.ori  	r7,r0,64	  # movsi imm J
	b.sw    	0(r1),r7	   # movsi store
	b.sw    	4(r1),r0	   # movsi store
	b.movi 	r7,3	     # movsi imm P
	b.sw    	8(r1),r7	   # movsi store
	b.ori  	r3,r0,_OS_TaskIdle	  # movsi imm i
	b.movi 	r4,0	     # movsi imm P
	b.ori  	r5,r0,_OSTaskIdleStk+252	  # movsi imm i
	b.movi 	r6,6	     # movsi imm P
	b.ori  	r7,r0,65535	  # movsi imm i
	b.ori  	r8,r0,_OSTaskIdleStk	  # movsi imm i
	b.jal  	_OSTaskCreateExt
.LBE32:
.LBE31:
	.stabn	68,0,261,.LM284-.LFBB22
.LM284:
	b.jal  	_OSInitHookEnd
	.stabn	68,0,267,.LM285-.LFBB22
.LM285:
	b.reti  	1,4
	.size	_OSInit, .-_OSInit
.Lscope22:
	.stabs	"",36,0,0,.Lscope22-.LFBB22
	.stabd	78,0,0
	.global _OSMapTbl
	.section	.rodata
	.type	_OSMapTbl, @object
	.size	_OSMapTbl, 8
_OSMapTbl:
	.byte	1
	.byte	2
	.byte	4
	.byte	8
	.byte	16
	.byte	32
	.byte	64
	.byte	-128
	.global _OSUnMapTbl
	.type	_OSUnMapTbl, @object
	.size	_OSUnMapTbl, 256
_OSUnMapTbl:
	.byte	0
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	3
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	4
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	3
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	5
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	3
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	4
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	3
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	6
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	3
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	4
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	3
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	5
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	3
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	4
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	3
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	7
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	3
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	4
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	3
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	5
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	3
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	4
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	3
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	6
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	3
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	4
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	3
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	5
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	3
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	4
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.byte	3
	.byte	0
	.byte	1
	.byte	0
	.byte	2
	.byte	0
	.byte	1
	.byte	0
	.comm	_OSCtxSwCtr,4,4
	.comm	_OSEventFreeList,4,4
	.comm	_OSEventTbl,440,4
	.comm	_OSIntNesting,1,1
	.comm	_OSLockNesting,1,1
	.comm	_OSPrioCur,1,1
	.comm	_OSPrioHighRdy,1,1
	.comm	_OSRdyGrp,1,1
	.comm	_OSRdyTbl,1,1
	.comm	_OSRunning,1,1
	.comm	_OSTaskCtr,1,1
	.comm	_OSIdleCtr,4,4
	.comm	_OSTaskIdleStk,256,4
	.comm	_OSTCBCur,4,4
	.comm	_OSTCBFreeList,4,4
	.comm	_OSTCBHighRdy,4,4
	.comm	_OSTCBList,4,4
	.comm	_OSTCBPrioTbl,28,4
	.comm	_OSTCBTbl,384,4
	.comm	_OSTickStepState,1,1
	.comm	_OSTime,4,4
	.stabs	"OSCtxSwCtr:G(2,6)",32,0,472,0
	.stabs	"OSEventFreeList:G(1,14)",32,0,474,0
	.stabs	"OSEventTbl:G(0,19)=ar(1,4);0;9;(1,6)",32,0,475,0
	.stabs	"OSIntNesting:G(2,2)",32,0,491,0
	.stabs	"OSLockNesting:G(2,2)",32,0,492,0
	.stabs	"OSPrioCur:G(2,2)",32,0,493,0
	.stabs	"OSPrioHighRdy:G(2,2)",32,0,494,0
	.stabs	"OSRdyGrp:G(2,2)",32,0,495,0
	.stabs	"OSRdyTbl:G(1,3)",32,0,496,0
	.stabs	"OSRunning:G(2,1)",32,0,497,0
	.stabs	"OSTaskCtr:G(2,2)",32,0,498,0
	.stabs	"OSIdleCtr:G(0,20)=B(2,6)",32,0,499,0
	.stabs	"OSTaskIdleStk:G(0,21)=ar(1,4);0;63;(2,10)",32,0,500,0
	.stabs	"OSTCBCur:G(0,16)",32,0,501,0
	.stabs	"OSTCBFreeList:G(0,16)",32,0,502,0
	.stabs	"OSTCBHighRdy:G(0,16)",32,0,503,0
	.stabs	"OSTCBList:G(0,16)",32,0,504,0
	.stabs	"OSTCBPrioTbl:G(0,22)=ar(1,4);0;6;(0,16)",32,0,505,0
	.stabs	"OSTCBTbl:G(0,23)=ar(1,4);0;3;(1,15)",32,0,506,0
	.stabs	"OSTickStepState:G(2,2)",32,0,509,0
	.stabs	"OSTime:G(0,20)",32,0,523,0
	.stabs	"OSMapTbl:G(0,24)=ar(1,4);0;7;(0,25)=k(2,2)",32,0,31,0
	.stabs	"OSUnMapTbl:G(0,26)=ar(1,4);0;255;(0,25)",32,0,42,0
.section .internalrom, "ax"
	.stabs	"",100,0,0,.Letext0
.Letext0:
	.ident	"GCC: (GNU) 4.2.1"
