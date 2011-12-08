	.file	"stack_chk.c"
	.stabs	"/home/hanguru/2011_project_original/lgdtv_vidan4110_fw_capp_project/software/vi_fw_project/",100,0,2,.Ltext0
	.stabs	"ucos/stack_chk.c",100,0,2,.Ltext0
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
	.stabs	"ucos/task_manage.h",130,0,0,0
	.stabs	"ucos/ucos_ii.h",130,0,0,0
	.stabs	"ucos/os_cpu.h",130,0,0,0
	.stabs	"BOOLEAN:t(3,1)=(0,11)",128,0,9,0
	.stabs	"INT8U:t(3,2)=(0,11)",128,0,10,0
	.stabs	"INT8S:t(3,3)=(0,2)",128,0,11,0
	.stabs	"INT16U:t(3,4)=(0,9)",128,0,12,0
	.stabs	"INT16S:t(3,5)=(0,8)",128,0,13,0
	.stabs	"INT32U:t(3,6)=(0,5)",128,0,14,0
	.stabs	"INT32S:t(3,7)=(0,3)",128,0,15,0
	.stabs	"VBOOLEAN:t(3,8)=(3,9)=B(0,11)",128,0,16,0
	.stabs	"OS_STK:t(3,10)=(0,4)",128,0,17,0
	.stabs	"OS_CPU_SR:t(3,11)=(0,4)",128,0,18,0
	.stabn	162,0,0,0
	.stabs	"ucos/os_cfg.h",130,0,0,0
	.stabs	"OS_FLAGS:t(4,1)=(3,4)",128,0,112,0
	.stabn	162,0,0,0
	.stabs	"os_event:T(2,1)=s44OSEventType:(3,2),0,8;OSEventGrp:(3,2),8,8;OSEventCnt:(3,4),16,16;OSEventPtr:(2,2)=*(0,15),32,32;OSEventTbl:(2,3)=ar(2,4)=r(2,4);0;037777777777;;0;0;(3,2),64,8;OSEventName:(2,5)=ar(2,4);0;31;(0,2),72,256;;",128,0,0,0
	.stabs	"OS_EVENT:t(2,6)=(2,1)",128,0,257,0
	.stabs	"os_sem_data:T(2,7)=s4OSCnt:(3,4),0,16;OSEventTbl:(2,3),16,8;OSEventGrp:(3,2),24,8;;",128,0,0,0
	.stabs	"OS_SEM_DATA:t(2,8)=(2,7)",128,0,387,0
	.stabs	"os_stk_data:T(2,9)=s8OSFree:(3,6),0,32;OSUsed:(3,6),32,32;;",128,0,0,0
	.stabs	"OS_STK_DATA:t(2,10)=(2,9)",128,0,400,0
	.stabs	"os_tcb:T(2,11)=s96OSTCBStkPtr:(2,12)=*(3,10),0,32;OSTCBExtPtr:(2,2),32,32;OSTCBStkBottom:(2,12),64,32;OSTCBStkSize:(3,6),96,32;OSTCBOpt:(3,4),128,16;OSTCBId:(3,4),144,16;OSTCBNext:(2,13)=*(2,11),160,32;OSTCBPrev:(2,13),192,32;OSTCBEventPtr:(2,14)=*(2,6),224,32;OSTCBDly:(3,4),256,16;OSTCBStat:(3,2),272,8;OSTCBPendTO:(3,1),280,8;OSTCBPrio:(3,2),288,8;OSTCBX:(3,2),296,8;OSTCBY:(3,2),304,8;OSTCBBitX:(3,2),312,8;OSTCBBitY:(3,2),320,8;OSTCBDelReq:(3,2),328,8;OSTCBCtxSwCtr:(3,6),352,32;OSTCBCyclesTot:(3,6),384,32;OSTCBCyclesStart:(3,6),416,32;OSTCBStkBase:(2,12),448,32;OSTCBStkUsed:(3,6),480,32;OSTCBTaskName:(2,5),512,256;;",128,0,0,0
	.stabs	"OS_TCB:t(2,15)=(2,11)",128,0,464,0
	.stabn	162,0,0,0
	.stabn	162,0,0,0
.proc _stkChk
	.stabs	"stkChk:F(0,15)",36,0,3,_stkChk
	.stabs	"fmt:P(0,16)=*(0,17)=k(0,2)",64,0,3,3
	.global _stkChk
	.type	_stkChk, @function
_stkChk:
	.stabd	46,0,0
	.stabn	68,0,3,.LM0-.LFBB1
.LM0:
.LFBB1:
	b.entri 	1,2
	.stabn	68,0,7,.LM1-.LFBB1
.LM1:
	b.ori  	r3,r0,255	  # movsi imm J
	b.mov  	r4,r1	     # movsi
	b.jal  	_OSTaskStkChk
	.stabn	68,0,21,.LM2-.LFBB1
.LM2:
	b.reti  	1,2
	.size	_stkChk, .-_stkChk
	.stabs	"stk_data:(2,10)",128,0,4,0
	.stabn	192,0,0,.LFBB1-.LFBB1
	.stabn	224,0,0,.Lscope1-.LFBB1
.Lscope1:
	.stabs	"",36,0,0,.Lscope1-.LFBB1
	.stabd	78,0,0
	.comm	_pEventExternalTaskDone,4,4
	.stabs	"pEventExternalTaskDone:G(2,14)",32,0,15,0
	.stabs	"",100,0,0,.Letext0
.Letext0:
	.ident	"GCC: (GNU) 4.2.1"
