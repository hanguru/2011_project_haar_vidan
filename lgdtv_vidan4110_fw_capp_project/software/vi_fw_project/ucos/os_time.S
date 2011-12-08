	.file	"os_time.c"
	.stabs	"/home/hanguru/2011_project_original/lgdtv_vidan4110_fw_capp_project/software/vi_fw_project/",100,0,2,.Ltext0
	.stabs	"ucos/os_time.c",100,0,2,.Ltext0
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
.proc _OSTimeGet
	.stabs	"OSTimeGet:F(2,6)",36,0,209,_OSTimeGet
	.global _OSTimeGet
	.type	_OSTimeGet, @function
_OSTimeGet:
	.stabd	46,0,0
	.stabn	68,0,209,.LM0-.LFBB1
.LM0:
.LFBB1:
.LBB2:
	.stabn	68,0,216,.LM1-.LFBB1
.LM1:
	b.ori  	r6,r0,17	  # movsi imm J
	l.mfspr r6,r6,0
.LBE2:
	b.ori  	r5,r0,17	  # movsi imm J
	b.andi  	r7,r6,-7
	l.mtspr r5,r7,0
	.stabn	68,0,217,.LM2-.LFBB1
.LM2:
	bw.lwz   	r3,(_OSTime)(r0)	    # movsi load
	.stabn	68,0,218,.LM3-.LFBB1
.LM3:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r6,0
	.stabn	68,0,220,.LM4-.LFBB1
.LM4:
	b.jr    	r9
	.size	_OSTimeGet, .-_OSTimeGet
	.stabs	"ticks:r(2,6)",64,0,210,3
	.stabn	192,0,0,.LFBB1-.LFBB1
	.stabs	"val:r(0,4)",64,0,216,6
	.stabn	192,0,0,.LBB2-.LFBB1
	.stabn	224,0,0,.LBE2-.LFBB1
	.stabn	224,0,0,.Lscope1-.LFBB1
.Lscope1:
	.stabs	"",36,0,0,.Lscope1-.LFBB1
	.stabd	78,0,0
.proc _OSTimeSet
	.stabs	"OSTimeSet:F(0,15)",36,0,237,_OSTimeSet
	.stabs	"ticks:P(2,6)",64,0,236,3
	.global _OSTimeSet
	.type	_OSTimeSet, @function
_OSTimeSet:
	.stabd	46,0,0
	.stabn	68,0,237,.LM5-.LFBB2
.LM5:
.LFBB2:
.LBB3:
	.stabn	68,0,243,.LM6-.LFBB2
.LM6:
	b.ori  	r6,r0,17	  # movsi imm J
	l.mfspr r6,r6,0
.LBE3:
	b.ori  	r5,r0,17	  # movsi imm J
	b.andi  	r7,r6,-7
	l.mtspr r5,r7,0
	.stabn	68,0,244,.LM7-.LFBB2
.LM7:
	bw.sw    	(_OSTime)(r0),r3	   # movsi store
	.stabn	68,0,245,.LM8-.LFBB2
.LM8:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r6,0
	.stabn	68,0,246,.LM9-.LFBB2
.LM9:
	b.jr    	r9
	.size	_OSTimeSet, .-_OSTimeSet
	.stabs	"val:r(0,4)",64,0,243,6
	.stabn	192,0,0,.LBB3-.LFBB2
	.stabn	224,0,0,.LBE3-.LFBB2
.Lscope2:
	.stabs	"",36,0,0,.Lscope2-.LFBB2
	.stabd	78,0,0
.proc _OSTimeDlyResume
	.stabs	"OSTimeDlyResume:F(2,2)",36,0,150,_OSTimeDlyResume
	.stabs	"prio:P(2,2)",64,0,149,3
	.global _OSTimeDlyResume
	.type	_OSTimeDlyResume, @function
_OSTimeDlyResume:
	.stabd	46,0,0
	.stabn	68,0,150,.LM10-.LFBB3
.LM10:
.LFBB3:
	b.entri 	1,0
	.stabn	68,0,157,.LM11-.LFBB3
.LM11:
	b.ori  	r7,r0,42	  # movsi imm J
	b.bgtui  	r3,5,.L8
.LBB4:
	.stabn	68,0,160,.LM12-.LFBB3
.LM12:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r5,r7,0
.LBE4:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r5,-7
	l.mtspr r6,r7,0
	.stabn	68,0,161,.LM13-.LFBB3
.LM13:
	b.slli  	r7,r3,2
	b.addi  	r7,r7,_OSTCBPrioTbl
	b.lwz   	r3,0(r7)	    # movsi load
	.stabn	68,0,162,.LM14-.LFBB3
.LM14:
	b.bnei  	r3,0,.L9
	.stabn	68,0,163,.LM15-.LFBB3
.LM15:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	b.ori  	r7,r0,11	  # movsi imm J
	b.j    	.L8
.L9:
	.stabn	68,0,166,.LM16-.LFBB3
.LM16:
	b.bnei  	r3,1,.L11
	.stabn	68,0,167,.LM17-.LFBB3
.LM17:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	b.ori  	r7,r0,11	  # movsi imm J
	b.j    	.L8
.L11:
	.stabn	68,0,170,.LM18-.LFBB3
.LM18:
	b.lhz   	r7,32(r3)
	b.bnei  	r7,0,.L13
	.stabn	68,0,171,.LM19-.LFBB3
.LM19:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	b.ori  	r7,r0,80	  # movsi imm J
	b.j    	.L8
.L13:
	.stabn	68,0,175,.LM20-.LFBB3
.LM20:
	b.sh    	32(r3),r0	   # movhi store
	.stabn	68,0,176,.LM21-.LFBB3
.LM21:
	b.lbz   	r6,34(r3)
	b.andi  	r7,r6,55
	b.beqi  	r7,0,.L15
	.stabn	68,0,177,.LM22-.LFBB3
.LM22:
	b.andi  	r7,r6,-56
	b.sb    	34(r3),r7	   # movqi store
	.stabn	68,0,178,.LM23-.LFBB3
.LM23:
	b.movi  	r7,1	    # movqi imm P
	b.sb    	35(r3),r7	   # movqi store
	b.j    	.L17
.L15:
	.stabn	68,0,180,.LM24-.LFBB3
.LM24:
	b.sb    	35(r3),r0	   # movqi store
.L17:
	.stabn	68,0,182,.LM25-.LFBB3
.LM25:
	b.lbz   	r7,34(r3)
	b.andi  	r7,r7,8
	b.bnei  	r7,0,.L18
	.stabn	68,0,183,.LM26-.LFBB3
.LM26:
	bw.lbz   	r4,(_OSRdyGrp)(r0)
	b.lbz   	r6,40(r3)
	b.or    	r7,r4,r6
	bw.sb    	(_OSRdyGrp)(r0),r7	   # movqi store
	.stabn	68,0,184,.LM27-.LFBB3
.LM27:
	b.lbz   	r7,38(r3)
	b.addi  	r7,r7,_OSRdyTbl
	b.lbz   	r4,0(r7)
	b.lbz   	r3,39(r3)
	b.or    	r6,r4,r3
	b.sb    	0(r7),r6	   # movqi store
	.stabn	68,0,185,.LM28-.LFBB3
.LM28:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	.stabn	68,0,186,.LM29-.LFBB3
.LM29:
	b.jal  	_OS_Sched
	b.movi 	r7,0	     # movsi imm P
	b.j    	.L8
.L18:
	.stabn	68,0,188,.LM30-.LFBB3
.LM30:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	b.movi 	r7,0	     # movsi imm P
.L8:
	.stabn	68,0,191,.LM31-.LFBB3
.LM31:
	b.mov  	r3,r7	     # movsi
	b.reti  	1,0
	.size	_OSTimeDlyResume, .-_OSTimeDlyResume
	.stabs	"ptcb:r(0,16)=*(1,15)",64,0,151,3
	.stabn	192,0,0,.LFBB3-.LFBB3
	.stabs	"val:r(0,4)",64,0,160,5
	.stabn	192,0,0,.LBB4-.LFBB3
	.stabn	224,0,0,.LBE4-.LFBB3
	.stabn	224,0,0,.Lscope3-.LFBB3
.Lscope3:
	.stabs	"",36,0,0,.Lscope3-.LFBB3
	.stabd	78,0,0
.proc _OSTimeDly
	.stabs	"OSTimeDly:F(0,15)",36,0,36,_OSTimeDly
	.stabs	"ticks:P(2,4)",64,0,36,3
	.global _OSTimeDly
	.type	_OSTimeDly, @function
_OSTimeDly:
	.stabd	46,0,0
	.stabn	68,0,36,.LM32-.LFBB4
.LM32:
.LFBB4:
	b.entri 	1,0
	.stabn	68,0,43,.LM33-.LFBB4
.LM33:
	b.beqi  	r3,0,.L26
.LBB5:
	.stabn	68,0,44,.LM34-.LFBB4
.LM34:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r4,r7,0
.LBE5:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r4,-7
	l.mtspr r6,r7,0
	.stabn	68,0,45,.LM35-.LFBB4
.LM35:
	bw.lwz   	r5,(_OSTCBCur)(r0)	    # movsi load
	.stabn	68,0,46,.LM36-.LFBB4
.LM36:
	b.lbz   	r6,38(r5)
	b.addi  	r6,r6,_OSRdyTbl
	b.lbz   	r7,39(r5)
	b.nand  	r7,r7,r7
	b.lbz   	r23,0(r6)
	b.and   	r7,r7,r23
	b.extbs 	r7,r7
	b.sb    	0(r6),r7	   # movqi store
	.stabn	68,0,47,.LM37-.LFBB4
.LM37:
	b.bnei  	r7,0,.L24
	.stabn	68,0,48,.LM38-.LFBB4
.LM38:
	b.lbz   	r7,40(r5)
	b.nand  	r7,r7,r7
	bw.lbz   	r6,(_OSRdyGrp)(r0)
	b.and   	r7,r6,r7
	bw.sb    	(_OSRdyGrp)(r0),r7	   # movqi store
.L24:
	.stabn	68,0,50,.LM39-.LFBB4
.LM39:
	b.sh    	32(r5),r3	   # movhi store
	.stabn	68,0,51,.LM40-.LFBB4
.LM40:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r4,0
	.stabn	68,0,52,.LM41-.LFBB4
.LM41:
	b.jal  	_OS_Sched
.L26:
	.stabn	68,0,54,.LM42-.LFBB4
.LM42:
	b.reti  	1,0
	.size	_OSTimeDly, .-_OSTimeDly
	.stabs	"val:r(0,4)",64,0,44,4
	.stabn	192,0,0,.LBB5-.LFBB4
	.stabn	224,0,0,.LBE5-.LFBB4
.Lscope4:
	.stabs	"",36,0,0,.Lscope4-.LFBB4
	.stabd	78,0,0
.proc _OSTimeDlyHMSM
	.stabs	"OSTimeDlyHMSM:F(2,2)",36,0,83,_OSTimeDlyHMSM
	.stabs	"hours:P(2,2)",64,0,82,24
	.stabs	"minutes:P(2,2)",64,0,82,4
	.stabs	"seconds:P(2,2)",64,0,82,23
	.stabs	"milli:P(2,4)",64,0,82,6
	.global _OSTimeDlyHMSM
	.type	_OSTimeDlyHMSM, @function
_OSTimeDlyHMSM:
	.stabd	46,0,0
	.stabn	68,0,83,.LM43-.LFBB5
.LM43:
.LFBB5:
	b.entri 	2,0
	b.mov  	r24,r3	     # movsi
	b.mov  	r23,r5	     # movsi
	.stabn	68,0,88,.LM44-.LFBB5
.LM44:
	b.bnei  	r3,0,.L28
	.stabn	68,0,89,.LM45-.LFBB5
.LM45:
	b.bnei  	r4,0,.L28
	.stabn	68,0,90,.LM46-.LFBB5
.LM46:
	b.bnei  	r5,0,.L31
	.stabn	68,0,91,.LM47-.LFBB5
.LM47:
	b.ori  	r3,r0,84	  # movsi imm J
	b.beqi  	r6,0,.L35
	b.j    	.L33
.L28:
	.stabn	68,0,97,.LM48-.LFBB5
.LM48:
	b.ori  	r3,r0,81	  # movsi imm J
	b.ori  	r7,r0,59	  # movsi imm J
	b.bgtu   	r4,r7,.L35
.L31:
	.stabn	68,0,100,.LM49-.LFBB5
.LM49:
	b.ori  	r3,r0,82	  # movsi imm J
	b.ori  	r7,r0,59	  # movsi imm J
	b.bgtu   	r23,r7,.L35
.L33:
	.stabn	68,0,103,.LM50-.LFBB5
.LM50:
	b.ori  	r3,r0,83	  # movsi imm J
	b.addi 	r7,r0,999	  # movsi imm I
	b.bgtu   	r6,r7,.L35
	.stabn	68,0,109,.LM51-.LFBB5
.LM51:
	b.ori  	r5,r0,20	  # movsi imm J
	b.mul   	r3,r6,r5
	b.addi  	r3,r3,500
	b.addi 	r7,r0,1000	  # movsi imm I
	b.divu  	r3,r3,r7
	b.ori  	r7,r0,60	  # movsi imm J
	b.mul   	r7,r4,r7
	b.add   	r7,r7,r23
	b.addi 	r6,r0,3600	  # movsi imm I
	b.mul   	r6,r24,r6
	b.add   	r7,r7,r6
	b.mul   	r7,r7,r5
	b.add   	r3,r3,r7
	.stabn	68,0,111,.LM52-.LFBB5
.LM52:
	b.srli  	r10,r3,16
	.stabn	68,0,113,.LM53-.LFBB5
.LM53:
	b.exthz 	r3,r3
	b.jal  	_OSTimeDly
	.stabn	68,0,114,.LM54-.LFBB5
.LM54:
	b.beqi  	r10,0,.L40
.L43:
	.stabn	68,0,115,.LM55-.LFBB5
.LM55:
	b.ori  	r3,r0,32768	  # movsi imm i
	b.jal  	_OSTimeDly
	.stabn	68,0,116,.LM56-.LFBB5
.LM56:
	b.ori  	r3,r0,32768	  # movsi imm i
	b.jal  	_OSTimeDly
	.stabn	68,0,117,.LM57-.LFBB5
.LM57:
	b.addi  	r7,r10,-1
	b.exthz 	r10,r7
	.stabn	68,0,114,.LM58-.LFBB5
.LM58:
	b.bnei  	r10,0,.L43
.L40:
	b.movi 	r3,0	     # movsi imm P
.L35:
	.stabn	68,0,120,.LM59-.LFBB5
.LM59:
	b.reti  	2,0
	.size	_OSTimeDlyHMSM, .-_OSTimeDlyHMSM
	.stabs	"ticks:r(2,6)",64,0,84,3
	.stabs	"loops:r(2,4)",64,0,85,10
	.stabn	192,0,0,.LFBB5-.LFBB5
	.stabn	224,0,0,.Lscope5-.LFBB5
.Lscope5:
	.stabs	"",36,0,0,.Lscope5-.LFBB5
	.stabd	78,0,0
	.stabs	"",100,0,0,.Letext0
.Letext0:
	.ident	"GCC: (GNU) 4.2.1"
