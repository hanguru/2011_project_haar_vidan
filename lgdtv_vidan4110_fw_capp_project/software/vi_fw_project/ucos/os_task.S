	.file	"os_task.c"
	.stabs	"/home/hanguru/2011_project_original/lgdtv_vidan4110_fw_capp_project/software/vi_fw_project/",100,0,2,.Ltext0
	.stabs	"ucos/os_task.c",100,0,2,.Ltext0
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
.proc _OSTaskDelReq
	.stabs	"OSTaskDelReq:F(2,2)",36,0,508,_OSTaskDelReq
	.stabs	"prio:P(2,2)",64,0,507,3
	.global _OSTaskDelReq
	.type	_OSTaskDelReq, @function
_OSTaskDelReq:
	.stabd	46,0,0
	.stabn	68,0,508,.LM0-.LFBB1
.LM0:
.LFBB1:
	.stabn	68,0,517,.LM1-.LFBB1
.LM1:
	b.ori  	r7,r0,61	  # movsi imm J
	b.beqi  	r3,6,.L4
	.stabn	68,0,520,.LM2-.LFBB1
.LM2:
	b.bleui  	r3,5,.L5
	.stabn	68,0,521,.LM3-.LFBB1
.LM3:
	b.ori  	r7,r0,42	  # movsi imm J
	b.ori  	r6,r0,255	  # movsi imm J
	b.bne   	r3,r6,.L4
	b.j    	.L7
.L5:
	.stabn	68,0,526,.LM4-.LFBB1
.LM4:
	b.ori  	r7,r0,255	  # movsi imm J
	b.bne   	r3,r7,.L9
.L7:
.LBB2:
	.stabn	68,0,527,.LM5-.LFBB1
.LM5:
	b.ori  	r6,r0,17	  # movsi imm J
	l.mfspr r6,r6,0
.LBE2:
	b.ori  	r5,r0,17	  # movsi imm J
	b.andi  	r7,r6,-7
	l.mtspr r5,r7,0
	.stabn	68,0,529,.LM6-.LFBB1
.LM6:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r6,0
	.stabn	68,0,530,.LM7-.LFBB1
.LM7:
	bw.lwz   	r7,(_OSTCBCur)(r0)	    # movsi load
	b.lbz   	r7,41(r7)
	b.j    	.L4
.L9:
.LBB3:
	.stabn	68,0,532,.LM8-.LFBB1
.LM8:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r5,r7,0
.LBE3:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r5,-7
	l.mtspr r6,r7,0
	.stabn	68,0,533,.LM9-.LFBB1
.LM9:
	b.slli  	r7,r3,2
	b.addi  	r7,r7,_OSTCBPrioTbl
	b.lwz   	r3,0(r7)	    # movsi load
	.stabn	68,0,534,.LM10-.LFBB1
.LM10:
	b.bnei  	r3,0,.L10
	.stabn	68,0,535,.LM11-.LFBB1
.LM11:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	b.ori  	r7,r0,11	  # movsi imm J
	b.j    	.L4
.L10:
	.stabn	68,0,538,.LM12-.LFBB1
.LM12:
	b.bnei  	r3,1,.L12
	.stabn	68,0,539,.LM13-.LFBB1
.LM13:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	b.ori  	r7,r0,60	  # movsi imm J
	b.j    	.L4
.L12:
	.stabn	68,0,542,.LM14-.LFBB1
.LM14:
	b.ori   	r7,r0,62	 # movqi imm J
	b.sb    	41(r3),r7	   # movqi store
	.stabn	68,0,543,.LM15-.LFBB1
.LM15:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	b.movi 	r7,0	     # movsi imm P
.L4:
	.stabn	68,0,545,.LM16-.LFBB1
.LM16:
	b.mov  	r3,r7	     # movsi
	b.jr    	r9
	.size	_OSTaskDelReq, .-_OSTaskDelReq
	.stabs	"ptcb:r(0,16)=*(1,15)",64,0,510,3
	.stabn	192,0,0,.LFBB1-.LFBB1
	.stabs	"val:r(0,4)",64,0,527,6
	.stabn	192,0,0,.LBB2-.LFBB1
	.stabn	224,0,0,.LBE2-.LFBB1
	.stabs	"val:r(0,4)",64,0,532,5
	.stabn	192,0,0,.LBB3-.LFBB1
	.stabn	224,0,0,.LBE3-.LFBB1
	.stabn	224,0,0,.Lscope1-.LFBB1
.Lscope1:
	.stabs	"",36,0,0,.Lscope1-.LFBB1
	.stabd	78,0,0
.proc _OSTaskStkChk
	.stabs	"OSTaskStkChk:F(2,2)",36,0,774,_OSTaskStkChk
	.stabs	"prio:P(2,2)",64,0,773,3
	.stabs	"p_stk_data:P(0,17)=*(1,10)",64,0,773,4
	.global _OSTaskStkChk
	.type	_OSTaskStkChk, @function
_OSTaskStkChk:
	.stabd	46,0,0
	.stabn	68,0,774,.LM17-.LFBB2
.LM17:
.LFBB2:
	.stabn	68,0,785,.LM18-.LFBB2
.LM18:
	b.bleui  	r3,6,.L16
	.stabn	68,0,786,.LM19-.LFBB2
.LM19:
	b.ori  	r7,r0,42	  # movsi imm J
	b.ori  	r6,r0,255	  # movsi imm J
	b.bne   	r3,r6,.L19
.L16:
	.stabn	68,0,791,.LM20-.LFBB2
.LM20:
	b.sw    	0(r4),r0	   # movsi store
	.stabn	68,0,792,.LM21-.LFBB2
.LM21:
	b.sw    	4(r4),r0	   # movsi store
.LBB4:
	.stabn	68,0,793,.LM22-.LFBB2
.LM22:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r5,r7,0
.LBE4:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r5,-7
	l.mtspr r6,r7,0
	.stabn	68,0,794,.LM23-.LFBB2
.LM23:
	b.ori  	r7,r0,255	  # movsi imm J
	b.bne   	r3,r7,.L20
	.stabn	68,0,795,.LM24-.LFBB2
.LM24:
	bw.lwz   	r7,(_OSTCBCur)(r0)	    # movsi load
	b.lbz   	r3,36(r7)
.L20:
	.stabn	68,0,797,.LM25-.LFBB2
.LM25:
	b.slli  	r7,r3,2
	b.addi  	r7,r7,_OSTCBPrioTbl
	b.lwz   	r3,0(r7)	    # movsi load
	.stabn	68,0,798,.LM26-.LFBB2
.LM26:
	b.bnei  	r3,0,.L22
	.stabn	68,0,799,.LM27-.LFBB2
.LM27:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	b.ori  	r7,r0,11	  # movsi imm J
	b.j    	.L19
.L22:
	.stabn	68,0,802,.LM28-.LFBB2
.LM28:
	b.bnei  	r3,1,.L24
	.stabn	68,0,803,.LM29-.LFBB2
.LM29:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	b.ori  	r7,r0,11	  # movsi imm J
	b.j    	.L19
.L24:
	.stabn	68,0,806,.LM30-.LFBB2
.LM30:
	b.lhz   	r7,16(r3)
	b.andi  	r7,r7,1
	b.bnei  	r7,0,.L26
	.stabn	68,0,807,.LM31-.LFBB2
.LM31:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	b.ori  	r7,r0,130	  # movsi imm J
	b.j    	.L19
.L26:
	.stabn	68,0,811,.LM32-.LFBB2
.LM32:
	b.lwz   	r23,12(r3)	    # movsi load
	.stabn	68,0,812,.LM33-.LFBB2
.LM33:
	b.lwz   	r3,8(r3)	    # movsi load
	.stabn	68,0,813,.LM34-.LFBB2
.LM34:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	.stabn	68,0,815,.LM35-.LFBB2
.LM35:
	b.lwz   	r7,0(r3)	    # movsi load
	b.movi 	r6,0	     # movsi imm P
	b.bnei  	r7,0,.L30
	b.addi  	r3,r3,4
	b.movi 	r6,0	     # movsi imm P
.L31:
	.stabn	68,0,816,.LM36-.LFBB2
.LM36:
	b.addi  	r6,r6,1
	.stabn	68,0,815,.LM37-.LFBB2
.LM37:
	b.lwz   	r7,0(r3)	    # movsi load
	b.addi  	r3,r3,4
	b.beqi  	r7,0,.L31
.L30:
	.stabn	68,0,823,.LM38-.LFBB2
.LM38:
	b.slli  	r7,r6,2
	b.sw    	0(r4),r7	   # movsi store
	.stabn	68,0,824,.LM39-.LFBB2
.LM39:
	b.sub   	r7,r23,r6
	b.slli  	r7,r7,2
	b.sw    	4(r4),r7	   # movsi store
	b.movi 	r7,0	     # movsi imm P
.L19:
	.stabn	68,0,826,.LM40-.LFBB2
.LM40:
	b.mov  	r3,r7	     # movsi
	b.jr    	r9
	.size	_OSTaskStkChk, .-_OSTaskStkChk
	.stabs	"ptcb:r(0,16)",64,0,775,3
	.stabs	"pchk:r(1,12)",64,0,776,3
	.stabs	"free:r(2,6)",64,0,777,6
	.stabs	"size:r(2,6)",64,0,778,23
	.stabn	192,0,0,.LFBB2-.LFBB2
	.stabs	"val:r(0,4)",64,0,793,5
	.stabn	192,0,0,.LBB4-.LFBB2
	.stabn	224,0,0,.LBE4-.LFBB2
	.stabn	224,0,0,.Lscope2-.LFBB2
.Lscope2:
	.stabs	"",36,0,0,.Lscope2-.LFBB2
	.stabd	78,0,0
.proc _OS_TaskStkClr
	.stabs	"OS_TaskStkClr:F(0,15)",36,0,983,_OS_TaskStkClr
	.stabs	"pbos:P(1,12)",64,0,982,3
	.stabs	"size:P(2,6)",64,0,982,4
	.stabs	"opt:P(2,4)",64,0,982,5
	.global _OS_TaskStkClr
	.type	_OS_TaskStkClr, @function
_OS_TaskStkClr:
	.stabd	46,0,0
	.stabn	68,0,983,.LM41-.LFBB3
.LM41:
.LFBB3:
	.stabn	68,0,984,.LM42-.LFBB3
.LM42:
	b.andi  	r7,r5,1
	b.beqi  	r7,0,.L39
	.stabn	68,0,985,.LM43-.LFBB3
.LM43:
	b.andi  	r7,r5,2
	b.beqi  	r7,0,.L39
	.stabn	68,0,987,.LM44-.LFBB3
.LM44:
	b.beqi  	r4,0,.L39
.L40:
	.stabn	68,0,988,.LM45-.LFBB3
.LM45:
	b.addi  	r4,r4,-1
	.stabn	68,0,989,.LM46-.LFBB3
.LM46:
	b.sw    	0(r3),r0	   # movsi store
	b.addi  	r3,r3,4
	.stabn	68,0,987,.LM47-.LFBB3
.LM47:
	b.bnei  	r4,0,.L40
.L39:
	.stabn	68,0,999,.LM48-.LFBB3
.LM48:
	b.jr    	r9
	.size	_OS_TaskStkClr, .-_OS_TaskStkClr
.Lscope3:
	.stabs	"",36,0,0,.Lscope3-.LFBB3
	.stabd	78,0,0
.proc _OSTaskQuery
	.stabs	"OSTaskQuery:F(2,2)",36,0,925,_OSTaskQuery
	.stabs	"prio:P(2,2)",64,0,924,3
	.stabs	"p_task_data:P(0,16)",64,0,924,5
	.global _OSTaskQuery
	.type	_OSTaskQuery, @function
_OSTaskQuery:
	.stabd	46,0,0
	.stabn	68,0,925,.LM49-.LFBB4
.LM49:
.LFBB4:
	b.entri 	2,0
	b.mov  	r5,r4	     # movsi
	.stabn	68,0,933,.LM50-.LFBB4
.LM50:
	b.bleui  	r3,6,.L43
	.stabn	68,0,934,.LM51-.LFBB4
.LM51:
	b.ori  	r7,r0,42	  # movsi imm J
	b.ori  	r6,r0,255	  # movsi imm J
	b.bne   	r3,r6,.L46
.L43:
.LBB5:
	.stabn	68,0,939,.LM52-.LFBB4
.LM52:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r10,r7,0
.LBE5:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r10,-7
	l.mtspr r6,r7,0
	.stabn	68,0,940,.LM53-.LFBB4
.LM53:
	b.ori  	r7,r0,255	  # movsi imm J
	b.bne   	r3,r7,.L47
	.stabn	68,0,941,.LM54-.LFBB4
.LM54:
	bw.lwz   	r7,(_OSTCBCur)(r0)	    # movsi load
	b.lbz   	r3,36(r7)
.L47:
	.stabn	68,0,943,.LM55-.LFBB4
.LM55:
	b.slli  	r7,r3,2
	b.addi  	r7,r7,_OSTCBPrioTbl
	b.lwz   	r4,0(r7)	    # movsi load
	.stabn	68,0,944,.LM56-.LFBB4
.LM56:
	b.bnei  	r4,0,.L49
	.stabn	68,0,945,.LM57-.LFBB4
.LM57:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r10,0
	b.ori  	r7,r0,41	  # movsi imm J
	b.j    	.L46
.L49:
	.stabn	68,0,948,.LM58-.LFBB4
.LM58:
	b.bnei  	r4,1,.L51
	.stabn	68,0,949,.LM59-.LFBB4
.LM59:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r10,0
	b.ori  	r7,r0,11	  # movsi imm J
	b.j    	.L46
.L51:
	.stabn	68,0,953,.LM60-.LFBB4
.LM60:
	b.mov  	r3,r5	     # movsi
	b.ori  	r5,r0,96	  # movsi imm J
	b.jal  	_OS_MemCopy
	.stabn	68,0,954,.LM61-.LFBB4
.LM61:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r10,0
	b.movi 	r7,0	     # movsi imm P
.L46:
	.stabn	68,0,956,.LM62-.LFBB4
.LM62:
	b.mov  	r3,r7	     # movsi
	b.reti  	2,0
	.size	_OSTaskQuery, .-_OSTaskQuery
	.stabs	"ptcb:r(0,16)",64,0,926,4
	.stabn	192,0,0,.LFBB4-.LFBB4
	.stabs	"val:r(0,4)",64,0,939,10
	.stabn	192,0,0,.LBB5-.LFBB4
	.stabn	224,0,0,.LBE5-.LFBB4
	.stabn	224,0,0,.Lscope4-.LFBB4
.Lscope4:
	.stabs	"",36,0,0,.Lscope4-.LFBB4
	.stabd	78,0,0
.proc _OSTaskSuspend
	.stabs	"OSTaskSuspend:F(2,2)",36,0,854,_OSTaskSuspend
	.stabs	"prio:P(2,2)",64,0,853,3
	.global _OSTaskSuspend
	.type	_OSTaskSuspend, @function
_OSTaskSuspend:
	.stabd	46,0,0
	.stabn	68,0,854,.LM63-.LFBB5
.LM63:
.LFBB5:
	b.entri 	1,0
	.stabn	68,0,864,.LM64-.LFBB5
.LM64:
	b.ori  	r7,r0,91	  # movsi imm J
	b.beqi  	r3,6,.L57
	.stabn	68,0,867,.LM65-.LFBB5
.LM65:
	b.bleui  	r3,5,.L58
	.stabn	68,0,868,.LM66-.LFBB5
.LM66:
	b.ori  	r7,r0,42	  # movsi imm J
	b.ori  	r6,r0,255	  # movsi imm J
	b.bne   	r3,r6,.L57
.L58:
.LBB6:
	.stabn	68,0,873,.LM67-.LFBB5
.LM67:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r4,r7,0
.LBE6:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r4,-7
	l.mtspr r6,r7,0
	.stabn	68,0,874,.LM68-.LFBB5
.LM68:
	b.ori  	r7,r0,255	  # movsi imm J
	b.bne   	r3,r7,.L61
	.stabn	68,0,875,.LM69-.LFBB5
.LM69:
	bw.lwz   	r7,(_OSTCBCur)(r0)	    # movsi load
	b.lbz   	r7,36(r7)
	b.movi 	r23,1	     # movsi imm P
	b.j    	.L63
.L61:
	.stabn	68,0,877,.LM70-.LFBB5
.LM70:
	bw.lwz   	r7,(_OSTCBCur)(r0)	    # movsi load
	b.lbz   	r7,36(r7)
	b.movi 	r23,1	     # movsi imm P
	b.beq   	r7,r3,.L63
	b.mov  	r7,r3	     # movsi
	b.movi 	r23,0	     # movsi imm P
.L63:
	.stabn	68,0,882,.LM71-.LFBB5
.LM71:
	b.slli  	r7,r7,2
	b.addi  	r7,r7,_OSTCBPrioTbl
	b.lwz   	r5,0(r7)	    # movsi load
	.stabn	68,0,883,.LM72-.LFBB5
.LM72:
	b.bnei  	r5,0,.L66
	.stabn	68,0,884,.LM73-.LFBB5
.LM73:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r4,0
	b.ori  	r7,r0,90	  # movsi imm J
	b.j    	.L57
.L66:
	.stabn	68,0,887,.LM74-.LFBB5
.LM74:
	b.bnei  	r5,1,.L68
	.stabn	68,0,888,.LM75-.LFBB5
.LM75:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r4,0
	b.ori  	r7,r0,11	  # movsi imm J
	b.j    	.L57
.L68:
	.stabn	68,0,892,.LM76-.LFBB5
.LM76:
	b.lbz   	r6,38(r5)
	b.addi  	r6,r6,_OSRdyTbl
	b.lbz   	r7,39(r5)
	b.nand  	r7,r7,r7
	b.lbz   	r24,0(r6)
	b.and   	r7,r7,r24
	b.extbs 	r7,r7
	b.sb    	0(r6),r7	   # movqi store
	.stabn	68,0,893,.LM77-.LFBB5
.LM77:
	b.bnei  	r7,0,.L70
	.stabn	68,0,894,.LM78-.LFBB5
.LM78:
	b.lbz   	r7,40(r5)
	b.nand  	r7,r7,r7
	bw.lbz   	r6,(_OSRdyGrp)(r0)
	b.and   	r7,r6,r7
	bw.sb    	(_OSRdyGrp)(r0),r7	   # movqi store
.L70:
	.stabn	68,0,896,.LM79-.LFBB5
.LM79:
	b.lbz   	r24,34(r5)
	b.ori   	r7,r24,8
	b.sb    	34(r5),r7	   # movqi store
	.stabn	68,0,897,.LM80-.LFBB5
.LM80:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r4,0
	.stabn	68,0,898,.LM81-.LFBB5
.LM81:
	b.movi 	r7,0	     # movsi imm P
	b.bnei  	r23,1,.L57
	.stabn	68,0,899,.LM82-.LFBB5
.LM82:
	b.jal  	_OS_Sched
	b.movi 	r7,0	     # movsi imm P
.L57:
	.stabn	68,0,902,.LM83-.LFBB5
.LM83:
	b.mov  	r3,r7	     # movsi
	b.reti  	1,0
	.size	_OSTaskSuspend, .-_OSTaskSuspend
	.stabs	"self:r(2,1)",64,0,855,23
	.stabs	"ptcb:r(0,16)",64,0,856,5
	.stabn	192,0,0,.LFBB5-.LFBB5
	.stabs	"val:r(0,4)",64,0,873,4
	.stabn	192,0,0,.LBB6-.LFBB5
	.stabn	224,0,0,.LBE6-.LFBB5
	.stabn	224,0,0,.Lscope5-.LFBB5
.Lscope5:
	.stabs	"",36,0,0,.Lscope5-.LFBB5
	.stabd	78,0,0
.proc _OSTaskResume
	.stabs	"OSTaskResume:F(2,2)",36,0,711,_OSTaskResume
	.stabs	"prio:P(2,2)",64,0,710,3
	.global _OSTaskResume
	.type	_OSTaskResume, @function
_OSTaskResume:
	.stabd	46,0,0
	.stabn	68,0,711,.LM84-.LFBB6
.LM84:
.LFBB6:
	b.entri 	1,0
	.stabn	68,0,719,.LM85-.LFBB6
.LM85:
	b.ori  	r7,r0,42	  # movsi imm J
	b.bgtui  	r3,5,.L78
.LBB7:
	.stabn	68,0,723,.LM86-.LFBB6
.LM86:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r5,r7,0
.LBE7:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r5,-7
	l.mtspr r6,r7,0
	.stabn	68,0,724,.LM87-.LFBB6
.LM87:
	b.slli  	r7,r3,2
	b.addi  	r7,r7,_OSTCBPrioTbl
	b.lwz   	r3,0(r7)	    # movsi load
	.stabn	68,0,725,.LM88-.LFBB6
.LM88:
	b.bnei  	r3,0,.L79
	.stabn	68,0,726,.LM89-.LFBB6
.LM89:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	b.ori  	r7,r0,100	  # movsi imm J
	b.j    	.L78
.L79:
	.stabn	68,0,729,.LM90-.LFBB6
.LM90:
	b.bnei  	r3,1,.L81
	.stabn	68,0,730,.LM91-.LFBB6
.LM91:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	b.ori  	r7,r0,11	  # movsi imm J
	b.j    	.L78
.L81:
	.stabn	68,0,733,.LM92-.LFBB6
.LM92:
	b.lbz   	r6,34(r3)
	b.andi  	r7,r6,8
	b.beqi  	r7,0,.L83
	.stabn	68,0,734,.LM93-.LFBB6
.LM93:
	b.andi  	r7,r6,247
	b.sb    	34(r3),r7	   # movqi store
	.stabn	68,0,735,.LM94-.LFBB6
.LM94:
	b.bnei  	r7,0,.L85
	.stabn	68,0,736,.LM95-.LFBB6
.LM95:
	b.lhz   	r7,32(r3)
	b.bnei  	r7,0,.L87
	.stabn	68,0,737,.LM96-.LFBB6
.LM96:
	bw.lbz   	r4,(_OSRdyGrp)(r0)
	b.lbz   	r6,40(r3)
	b.or    	r7,r4,r6
	bw.sb    	(_OSRdyGrp)(r0),r7	   # movqi store
	.stabn	68,0,738,.LM97-.LFBB6
.LM97:
	b.lbz   	r7,38(r3)
	b.addi  	r7,r7,_OSRdyTbl
	b.lbz   	r4,0(r7)
	b.lbz   	r3,39(r3)
	b.or    	r6,r4,r3
	b.sb    	0(r7),r6	   # movqi store
	.stabn	68,0,739,.LM98-.LFBB6
.LM98:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	.stabn	68,0,740,.LM99-.LFBB6
.LM99:
	b.jal  	_OS_Sched
	b.movi 	r7,0	     # movsi imm P
	b.j    	.L78
.L87:
	.stabn	68,0,742,.LM100-.LFBB6
.LM100:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	b.movi 	r7,0	     # movsi imm P
	b.j    	.L78
.L85:
	.stabn	68,0,745,.LM101-.LFBB6
.LM101:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	b.movi 	r7,0	     # movsi imm P
	b.j    	.L78
.L83:
	.stabn	68,0,749,.LM102-.LFBB6
.LM102:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	b.ori  	r7,r0,101	  # movsi imm J
.L78:
	.stabn	68,0,751,.LM103-.LFBB6
.LM103:
	b.mov  	r3,r7	     # movsi
	b.reti  	1,0
	.size	_OSTaskResume, .-_OSTaskResume
	.stabs	"ptcb:r(0,16)",64,0,712,3
	.stabn	192,0,0,.LFBB6-.LFBB6
	.stabs	"val:r(0,4)",64,0,723,5
	.stabn	192,0,0,.LBB7-.LFBB6
	.stabn	224,0,0,.LBE7-.LFBB6
	.stabn	224,0,0,.Lscope6-.LFBB6
.Lscope6:
	.stabs	"",36,0,0,.Lscope6-.LFBB6
	.stabd	78,0,0
.proc _OSTaskChangePrio
	.stabs	"OSTaskChangePrio:F(2,2)",36,0,43,_OSTaskChangePrio
	.stabs	"oldprio:P(2,2)",64,0,42,3
	.stabs	"newprio:P(2,2)",64,0,42,4
	.global _OSTaskChangePrio
	.type	_OSTaskChangePrio, @function
_OSTaskChangePrio:
	.stabd	46,0,0
	.stabn	68,0,43,.LM104-.LFBB7
.LM104:
.LFBB7:
	b.entri 	1,0
	.stabn	68,0,59,.LM105-.LFBB7
.LM105:
	b.bleui  	r3,5,.L91
	.stabn	68,0,60,.LM106-.LFBB7
.LM106:
	b.ori  	r6,r0,255	  # movsi imm J
	b.bne   	r3,r6,.L93
.L91:
	.stabn	68,0,64,.LM107-.LFBB7
.LM107:
	b.bgtui  	r4,5,.L93
.LBB8:
	.stabn	68,0,68,.LM108-.LFBB7
.LM108:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r5,r7,0
.LBE8:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r5,-7
	l.mtspr r6,r7,0
	.stabn	68,0,69,.LM109-.LFBB7
.LM109:
	b.mov  	r23,r4	     # movsi
	b.slli  	r7,r4,2
	b.addi  	r7,r7,_OSTCBPrioTbl
	b.lwz   	r7,0(r7)	    # movsi load
	b.beqi  	r7,0,.L95
	.stabn	68,0,70,.LM110-.LFBB7
.LM110:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	b.ori  	r3,r0,40	  # movsi imm J
	b.j    	.L97
.L95:
	.stabn	68,0,73,.LM111-.LFBB7
.LM111:
	b.ori  	r7,r0,255	  # movsi imm J
	b.bne   	r3,r7,.L98
	.stabn	68,0,74,.LM112-.LFBB7
.LM112:
	bw.lwz   	r7,(_OSTCBCur)(r0)	    # movsi load
	b.lbz   	r3,36(r7)
.L98:
	.stabn	68,0,76,.LM113-.LFBB7
.LM113:
	b.slli  	r7,r3,2
	b.addi  	r7,r7,_OSTCBPrioTbl
	b.lwz   	r25,0(r7)	    # movsi load
	.stabn	68,0,77,.LM114-.LFBB7
.LM114:
	b.bnei  	r25,0,.L100
	.stabn	68,0,78,.LM115-.LFBB7
.LM115:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	b.ori  	r3,r0,41	  # movsi imm J
	b.j    	.L97
.L100:
	.stabn	68,0,81,.LM116-.LFBB7
.LM116:
	b.bnei  	r25,1,.L102
	.stabn	68,0,82,.LM117-.LFBB7
.LM117:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	b.ori  	r3,r0,11	  # movsi imm J
	b.j    	.L97
.L102:
	.stabn	68,0,85,.LM118-.LFBB7
.LM118:
	b.srli  	r29,r4,3
	.stabn	68,0,86,.LM119-.LFBB7
.LM119:
	b.mov  	r31,r29	     # movsi
	b.ori  	r7,r0,_OSMapTbl	  # movsi imm i
	b.add   	r6,r29,r7
	b.lbz   	r27,0(r6)
	.stabn	68,0,87,.LM120-.LFBB7
.LM120:
	b.andi  	r30,r4,7
	.stabn	68,0,88,.LM121-.LFBB7
.LM121:
	b.add   	r7,r7,r30
	b.lbz   	r28,0(r7)
	.stabn	68,0,89,.LM122-.LFBB7
.LM122:
	b.ori  	r6,r0,_OSTCBPrioTbl	  # movsi imm i
	b.slli  	r7,r3,2
	b.add   	r7,r7,r6
	b.sw    	0(r7),r0	   # movsi store
	.stabn	68,0,90,.LM123-.LFBB7
.LM123:
	b.slli  	r7,r23,2
	b.add   	r7,r7,r6
	b.sw    	0(r7),r25	   # movsi store
	.stabn	68,0,92,.LM124-.LFBB7
.LM124:
	b.lbz   	r26,38(r25)
	b.addi  	r23,r26,_OSRdyTbl
	b.lbz   	r6,0(r23)
	b.lbz   	r24,39(r25)
	b.and   	r7,r6,r24
	b.beqi  	r7,0,.L104
	.stabn	68,0,93,.LM125-.LFBB7
.LM125:
	b.nand  	r7,r24,r24
	b.and   	r7,r6,r7
	b.extbs 	r7,r7
	b.sb    	0(r23),r7	   # movqi store
	.stabn	68,0,94,.LM126-.LFBB7
.LM126:
	b.bnei  	r7,0,.L106
	.stabn	68,0,95,.LM127-.LFBB7
.LM127:
	b.lbz   	r7,40(r25)
	b.nand  	r7,r7,r7
	bw.lbz   	r23,(_OSRdyGrp)(r0)
	b.and   	r7,r23,r7
	bw.sb    	(_OSRdyGrp)(r0),r7	   # movqi store
.L106:
	.stabn	68,0,97,.LM128-.LFBB7
.LM128:
	bw.lbz   	r24,(_OSRdyGrp)(r0)
	b.or    	r7,r27,r24
	bw.sb    	(_OSRdyGrp)(r0),r7	   # movqi store
	.stabn	68,0,98,.LM129-.LFBB7
.LM129:
	b.addi  	r6,r31,_OSRdyTbl
	b.lbz   	r23,0(r6)
	b.or    	r7,r28,r23
	b.sb    	0(r6),r7	   # movqi store
	b.j    	.L108
.L104:
	.stabn	68,0,101,.LM130-.LFBB7
.LM130:
	b.lwz   	r23,28(r25)	    # movsi load
	.stabn	68,0,102,.LM131-.LFBB7
.LM131:
	b.beqi  	r23,0,.L108
	.stabn	68,0,103,.LM132-.LFBB7
.LM132:
	b.add   	r6,r23,r26
	b.nand  	r7,r24,r24
	b.lbz   	r24,8(r6)
	b.and   	r7,r7,r24
	b.extbs 	r7,r7
	b.sb    	8(r6),r7	   # movqi store
	.stabn	68,0,104,.LM133-.LFBB7
.LM133:
	b.bnei  	r7,0,.L110
	.stabn	68,0,105,.LM134-.LFBB7
.LM134:
	b.lbz   	r7,40(r25)
	b.nand  	r7,r7,r7
	b.lbz   	r6,1(r23)
	b.and   	r7,r6,r7
	b.sb    	1(r23),r7	   # movqi store
.L110:
	.stabn	68,0,107,.LM135-.LFBB7
.LM135:
	b.lbz   	r24,1(r23)
	b.or    	r7,r27,r24
	b.sb    	1(r23),r7	   # movqi store
	.stabn	68,0,108,.LM136-.LFBB7
.LM136:
	b.add   	r6,r23,r31
	b.lbz   	r23,8(r6)
	b.or    	r7,r28,r23
	b.sb    	8(r6),r7	   # movqi store
.L108:
	.stabn	68,0,112,.LM137-.LFBB7
.LM137:
	b.sb    	36(r25),r4	   # movqi store
	.stabn	68,0,113,.LM138-.LFBB7
.LM138:
	b.sb    	38(r25),r29	   # movqi store
	.stabn	68,0,114,.LM139-.LFBB7
.LM139:
	b.sb    	37(r25),r30	   # movqi store
	.stabn	68,0,115,.LM140-.LFBB7
.LM140:
	b.sb    	40(r25),r27	   # movqi store
	.stabn	68,0,116,.LM141-.LFBB7
.LM141:
	b.sb    	39(r25),r28	   # movqi store
	.stabn	68,0,117,.LM142-.LFBB7
.LM142:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	.stabn	68,0,118,.LM143-.LFBB7
.LM143:
	b.jal  	_OS_Sched
	b.movi 	r3,0	     # movsi imm P
	b.j    	.L97
.L93:
	.stabn	68,0,119,.LM144-.LFBB7
.LM144:
	b.ori  	r3,r0,42	  # movsi imm J
.L97:
	.stabn	68,0,120,.LM145-.LFBB7
.LM145:
	b.reti  	1,0
	.size	_OSTaskChangePrio, .-_OSTaskChangePrio
	.stabs	"pevent:r(1,14)",64,0,45,23
	.stabs	"ptcb:r(0,16)",64,0,47,25
	.stabs	"x:r(2,2)",64,0,48,30
	.stabs	"y:r(2,2)",64,0,49,29
	.stabs	"bitx:r(2,2)",64,0,50,28
	.stabs	"bity:r(2,2)",64,0,51,27
	.stabn	192,0,0,.LFBB7-.LFBB7
	.stabs	"val:r(0,4)",64,0,68,5
	.stabn	192,0,0,.LBB8-.LFBB7
	.stabn	224,0,0,.LBE8-.LFBB7
	.stabn	224,0,0,.Lscope7-.LFBB7
.Lscope7:
	.stabs	"",36,0,0,.Lscope7-.LFBB7
	.stabd	78,0,0
.proc _OSTaskNameSet
	.stabs	"OSTaskNameSet:F(0,15)",36,0,643,_OSTaskNameSet
	.stabs	"prio:P(2,2)",64,0,642,3
	.stabs	"pname:P(0,18)=*(0,2)",64,0,642,12
	.stabs	"err:P(0,19)=*(2,2)",64,0,642,13
	.global _OSTaskNameSet
	.type	_OSTaskNameSet, @function
_OSTaskNameSet:
	.stabd	46,0,0
	.stabn	68,0,643,.LM146-.LFBB8
.LM146:
.LFBB8:
	b.entri 	5,0
	b.mov  	r12,r4	     # movsi
	b.mov  	r13,r5	     # movsi
	.stabn	68,0,652,.LM147-.LFBB8
.LM147:
	b.bleui  	r3,6,.L114
	.stabn	68,0,653,.LM148-.LFBB8
.LM148:
	b.ori  	r7,r0,255	  # movsi imm J
	b.beq   	r3,r7,.L114
	.stabn	68,0,654,.LM149-.LFBB8
.LM149:
	b.ori   	r7,r0,42	 # movqi imm J
	b.sb    	0(r5),r7	   # movqi store
	b.j    	.L128
.L114:
	.stabn	68,0,658,.LM150-.LFBB8
.LM150:
	b.bnei  	r12,0,.L118
	.stabn	68,0,659,.LM151-.LFBB8
.LM151:
	b.ori   	r7,r0,15	 # movqi imm J
	b.sb    	0(r13),r7	   # movqi store
	b.j    	.L128
.L118:
.LBB9:
	.stabn	68,0,663,.LM152-.LFBB8
.LM152:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r11,r7,0
.LBE9:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r11,-7
	l.mtspr r6,r7,0
	.stabn	68,0,664,.LM153-.LFBB8
.LM153:
	b.ori  	r7,r0,255	  # movsi imm J
	b.bne   	r3,r7,.L120
	.stabn	68,0,665,.LM154-.LFBB8
.LM154:
	bw.lwz   	r7,(_OSTCBCur)(r0)	    # movsi load
	b.lbz   	r3,36(r7)
.L120:
	.stabn	68,0,667,.LM155-.LFBB8
.LM155:
	b.slli  	r7,r3,2
	b.addi  	r7,r7,_OSTCBPrioTbl
	b.lwz   	r10,0(r7)	    # movsi load
	.stabn	68,0,668,.LM156-.LFBB8
.LM156:
	b.bnei  	r10,0,.L122
	.stabn	68,0,669,.LM157-.LFBB8
.LM157:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r11,0
	.stabn	68,0,670,.LM158-.LFBB8
.LM158:
	b.ori   	r7,r0,11	 # movqi imm J
	b.sb    	0(r13),r7	   # movqi store
	b.j    	.L128
.L122:
	.stabn	68,0,673,.LM159-.LFBB8
.LM159:
	b.bnei  	r10,1,.L124
	.stabn	68,0,674,.LM160-.LFBB8
.LM160:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r11,0
	.stabn	68,0,675,.LM161-.LFBB8
.LM161:
	b.ori   	r7,r0,11	 # movqi imm J
	b.sb    	0(r13),r7	   # movqi store
	b.j    	.L128
.L124:
	.stabn	68,0,678,.LM162-.LFBB8
.LM162:
	b.mov  	r3,r12	     # movsi
	b.jal  	_OS_StrLen
	.stabn	68,0,679,.LM163-.LFBB8
.LM163:
	b.ori  	r7,r0,31	  # movsi imm J
	b.bleu   	r3,r7,.L126
	.stabn	68,0,680,.LM164-.LFBB8
.LM164:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r11,0
	.stabn	68,0,681,.LM165-.LFBB8
.LM165:
	b.ori   	r7,r0,14	 # movqi imm J
	b.sb    	0(r13),r7	   # movqi store
	b.j    	.L128
.L126:
	.stabn	68,0,684,.LM166-.LFBB8
.LM166:
	b.addi  	r3,r10,64
	b.mov  	r4,r12	     # movsi
	b.jal  	_OS_StrCopy
	.stabn	68,0,685,.LM167-.LFBB8
.LM167:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r11,0
	.stabn	68,0,686,.LM168-.LFBB8
.LM168:
	b.sb    	0(r13),r0	   # movqi store
.L128:
	.stabn	68,0,687,.LM169-.LFBB8
.LM169:
	b.reti  	5,0
	.size	_OSTaskNameSet, .-_OSTaskNameSet
	.stabs	"ptcb:r(0,16)",64,0,645,10
	.stabn	192,0,0,.LFBB8-.LFBB8
	.stabs	"val:r(0,4)",64,0,663,11
	.stabn	192,0,0,.LBB9-.LFBB8
	.stabn	224,0,0,.LBE9-.LFBB8
	.stabn	224,0,0,.Lscope8-.LFBB8
.Lscope8:
	.stabs	"",36,0,0,.Lscope8-.LFBB8
	.stabd	78,0,0
.proc _OSTaskNameGet
	.stabs	"OSTaskNameGet:F(2,2)",36,0,573,_OSTaskNameGet
	.stabs	"prio:P(2,2)",64,0,572,3
	.stabs	"pname:P(0,18)",64,0,572,23
	.stabs	"err:P(0,19)",64,0,572,11
	.global _OSTaskNameGet
	.type	_OSTaskNameGet, @function
_OSTaskNameGet:
	.stabd	46,0,0
	.stabn	68,0,573,.LM170-.LFBB9
.LM170:
.LFBB9:
	b.entri 	3,0
	b.mov  	r23,r4	     # movsi
	b.mov  	r11,r5	     # movsi
	.stabn	68,0,582,.LM171-.LFBB9
.LM171:
	b.bleui  	r3,6,.L130
	.stabn	68,0,583,.LM172-.LFBB9
.LM172:
	b.ori  	r7,r0,255	  # movsi imm J
	b.beq   	r3,r7,.L130
	.stabn	68,0,584,.LM173-.LFBB9
.LM173:
	b.ori   	r7,r0,42	 # movqi imm J
	b.sb    	0(r5),r7	   # movqi store
	b.movi 	r3,0	     # movsi imm P
	b.j    	.L133
.L130:
	.stabn	68,0,588,.LM174-.LFBB9
.LM174:
	b.bnei  	r23,0,.L134
	.stabn	68,0,589,.LM175-.LFBB9
.LM175:
	b.ori   	r7,r0,15	 # movqi imm J
	b.sb    	0(r11),r7	   # movqi store
	b.movi 	r3,0	     # movsi imm P
	b.j    	.L133
.L134:
.LBB10:
	.stabn	68,0,593,.LM176-.LFBB9
.LM176:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r10,r7,0
.LBE10:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r10,-7
	l.mtspr r6,r7,0
	.stabn	68,0,594,.LM177-.LFBB9
.LM177:
	b.ori  	r7,r0,255	  # movsi imm J
	b.bne   	r3,r7,.L136
	.stabn	68,0,595,.LM178-.LFBB9
.LM178:
	bw.lwz   	r7,(_OSTCBCur)(r0)	    # movsi load
	b.lbz   	r3,36(r7)
.L136:
	.stabn	68,0,597,.LM179-.LFBB9
.LM179:
	b.slli  	r7,r3,2
	b.addi  	r7,r7,_OSTCBPrioTbl
	b.lwz   	r4,0(r7)	    # movsi load
	.stabn	68,0,598,.LM180-.LFBB9
.LM180:
	b.bnei  	r4,0,.L138
	.stabn	68,0,599,.LM181-.LFBB9
.LM181:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r10,0
	.stabn	68,0,600,.LM182-.LFBB9
.LM182:
	b.ori   	r7,r0,11	 # movqi imm J
	b.sb    	0(r11),r7	   # movqi store
	b.movi 	r3,0	     # movsi imm P
	b.j    	.L133
.L138:
	.stabn	68,0,603,.LM183-.LFBB9
.LM183:
	b.bnei  	r4,1,.L140
	.stabn	68,0,604,.LM184-.LFBB9
.LM184:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r10,0
	.stabn	68,0,605,.LM185-.LFBB9
.LM185:
	b.ori   	r7,r0,11	 # movqi imm J
	b.sb    	0(r11),r7	   # movqi store
	b.movi 	r3,0	     # movsi imm P
	b.j    	.L133
.L140:
	.stabn	68,0,608,.LM186-.LFBB9
.LM186:
	b.mov  	r3,r23	     # movsi
	b.addi  	r4,r4,64
	b.jal  	_OS_StrCopy
	.stabn	68,0,609,.LM187-.LFBB9
.LM187:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r10,0
	.stabn	68,0,610,.LM188-.LFBB9
.LM188:
	b.sb    	0(r11),r0	   # movqi store
.L133:
	.stabn	68,0,612,.LM189-.LFBB9
.LM189:
	b.reti  	3,0
	.size	_OSTaskNameGet, .-_OSTaskNameGet
	.stabs	"ptcb:r(0,16)",64,0,574,4
	.stabs	"len:r(2,2)",64,0,575,3
	.stabn	192,0,0,.LFBB9-.LFBB9
	.stabs	"val:r(0,4)",64,0,593,10
	.stabn	192,0,0,.LBB10-.LFBB9
	.stabn	224,0,0,.LBE10-.LFBB9
	.stabn	224,0,0,.Lscope9-.LFBB9
.Lscope9:
	.stabs	"",36,0,0,.Lscope9-.LFBB9
	.stabd	78,0,0
.proc _OSTaskDel
	.stabs	"OSTaskDel:F(2,2)",36,0,366,_OSTaskDel
	.stabs	"prio:P(2,2)",64,0,365,3
	.global _OSTaskDel
	.type	_OSTaskDel, @function
_OSTaskDel:
	.stabd	46,0,0
	.stabn	68,0,366,.LM190-.LFBB10
.LM190:
.LFBB10:
	b.entri 	4,0
	.stabn	68,0,380,.LM191-.LFBB10
.LM191:
	bw.lbz   	r7,(_OSIntNesting)(r0)
	b.ori  	r6,r0,63	  # movsi imm J
	b.bnei  	r7,0,.L146
	.stabn	68,0,384,.LM192-.LFBB10
.LM192:
	b.ori  	r6,r0,61	  # movsi imm J
	b.beqi  	r3,6,.L146
	.stabn	68,0,387,.LM193-.LFBB10
.LM193:
	b.bleui  	r3,5,.L149
	.stabn	68,0,388,.LM194-.LFBB10
.LM194:
	b.ori  	r6,r0,42	  # movsi imm J
	b.ori  	r4,r0,255	  # movsi imm J
	b.bne   	r3,r4,.L146
.L149:
.LBB11:
	.stabn	68,0,393,.LM195-.LFBB10
.LM195:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r5,r7,0
.LBE11:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r5,-7
	l.mtspr r6,r7,0
	.stabn	68,0,394,.LM196-.LFBB10
.LM196:
	b.ori  	r6,r0,255	  # movsi imm J
	b.bne   	r3,r6,.L152
	.stabn	68,0,395,.LM197-.LFBB10
.LM197:
	bw.lwz   	r7,(_OSTCBCur)(r0)	    # movsi load
	b.lbz   	r3,36(r7)
.L152:
	.stabn	68,0,397,.LM198-.LFBB10
.LM198:
	b.mov  	r11,r3	     # movsi
	b.slli  	r7,r3,2
	b.addi  	r7,r7,_OSTCBPrioTbl
	b.lwz   	r10,0(r7)	    # movsi load
	.stabn	68,0,398,.LM199-.LFBB10
.LM199:
	b.bnei  	r10,0,.L154
	.stabn	68,0,399,.LM200-.LFBB10
.LM200:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	b.ori  	r6,r0,60	  # movsi imm J
	b.j    	.L146
.L154:
	.stabn	68,0,402,.LM201-.LFBB10
.LM201:
	b.bnei  	r10,1,.L156
	.stabn	68,0,403,.LM202-.LFBB10
.LM202:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	b.ori  	r6,r0,11	  # movsi imm J
	b.j    	.L146
.L156:
	.stabn	68,0,407,.LM203-.LFBB10
.LM203:
	b.lbz   	r23,38(r10)
	b.addi  	r6,r23,_OSRdyTbl
	b.lbz   	r7,39(r10)
	b.nand  	r7,r7,r7
	b.lbz   	r4,0(r6)
	b.and   	r7,r7,r4
	b.extbs 	r7,r7
	b.sb    	0(r6),r7	   # movqi store
	.stabn	68,0,408,.LM204-.LFBB10
.LM204:
	b.bnei  	r7,0,.L158
	.stabn	68,0,409,.LM205-.LFBB10
.LM205:
	b.lbz   	r7,40(r10)
	b.nand  	r7,r7,r7
	bw.lbz   	r6,(_OSRdyGrp)(r0)
	b.and   	r7,r6,r7
	bw.sb    	(_OSRdyGrp)(r0),r7	   # movqi store
.L158:
	.stabn	68,0,412,.LM206-.LFBB10
.LM206:
	b.lwz   	r4,28(r10)	    # movsi load
	.stabn	68,0,413,.LM207-.LFBB10
.LM207:
	b.beqi  	r4,0,.L160
	.stabn	68,0,414,.LM208-.LFBB10
.LM208:
	b.add   	r6,r4,r23
	b.lbz   	r7,39(r10)
	b.nand  	r7,r7,r7
	b.lbz   	r23,8(r6)
	b.and   	r7,r7,r23
	b.extbs 	r7,r7
	b.sb    	8(r6),r7	   # movqi store
	.stabn	68,0,415,.LM209-.LFBB10
.LM209:
	b.bnei  	r7,0,.L160
	.stabn	68,0,416,.LM210-.LFBB10
.LM210:
	b.lbz   	r7,40(r10)
	b.nand  	r7,r7,r7
	b.lbz   	r6,1(r4)
	b.and   	r7,r6,r7
	b.sb    	1(r4),r7	   # movqi store
.L160:
	.stabn	68,0,426,.LM211-.LFBB10
.LM211:
	b.sh    	32(r10),r0	   # movhi store
	.stabn	68,0,427,.LM212-.LFBB10
.LM212:
	b.sb    	34(r10),r0	   # movqi store
	.stabn	68,0,428,.LM213-.LFBB10
.LM213:
	b.sb    	35(r10),r0	   # movqi store
	.stabn	68,0,429,.LM214-.LFBB10
.LM214:
	bw.lbz   	r7,(_OSLockNesting)(r0)
	b.ori  	r23,r0,255	  # movsi imm J
	b.beq   	r7,r23,.L163
	.stabn	68,0,430,.LM215-.LFBB10
.LM215:
	b.addi  	r7,r7,1
	bw.sb    	(_OSLockNesting)(r0),r7	   # movqi store
.L163:
	.stabn	68,0,432,.LM216-.LFBB10
.LM216:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	.stabn	68,0,433,.LM217-.LFBB10
.LM217:
	b.jal  	_OS_Dummy
.LBB12:
	.stabn	68,0,434,.LM218-.LFBB10
.LM218:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r12,r7,0
.LBE12:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r12,-7
	l.mtspr r6,r7,0
	.stabn	68,0,435,.LM219-.LFBB10
.LM219:
	bw.lbz   	r7,(_OSLockNesting)(r0)
	b.beqi  	r7,0,.L165
	.stabn	68,0,436,.LM220-.LFBB10
.LM220:
	b.addi  	r7,r7,-1
	bw.sb    	(_OSLockNesting)(r0),r7	   # movqi store
.L165:
	.stabn	68,0,438,.LM221-.LFBB10
.LM221:
	b.mov  	r3,r10	     # movsi
	b.jal  	_OSTaskDelHook
	.stabn	68,0,439,.LM222-.LFBB10
.LM222:
	bw.lbz   	r7,(_OSTaskCtr)(r0)
	b.addi  	r7,r7,-1
	bw.sb    	(_OSTaskCtr)(r0),r7	   # movqi store
	.stabn	68,0,440,.LM223-.LFBB10
.LM223:
	b.slli  	r7,r11,2
	b.addi  	r7,r7,_OSTCBPrioTbl
	b.sw    	0(r7),r0	   # movsi store
	.stabn	68,0,441,.LM224-.LFBB10
.LM224:
	b.lwz   	r6,24(r10)	    # movsi load
	b.bnei  	r6,0,.L167
	.stabn	68,0,442,.LM225-.LFBB10
.LM225:
	b.lwz   	r7,20(r10)	    # movsi load
	b.sw    	24(r7),r0	   # movsi store
	.stabn	68,0,443,.LM226-.LFBB10
.LM226:
	bw.sw    	(_OSTCBList)(r0),r7	   # movsi store
	b.j    	.L169
.L167:
	.stabn	68,0,445,.LM227-.LFBB10
.LM227:
	b.lwz   	r7,20(r10)	    # movsi load
	b.sw    	20(r6),r7	   # movsi store
	.stabn	68,0,446,.LM228-.LFBB10
.LM228:
	b.mlwz  	r6,20(r10),0
	b.sw    	24(r6),r7	   # movsi store
.L169:
	.stabn	68,0,448,.LM229-.LFBB10
.LM229:
	bw.lwz   	r7,(_OSTCBFreeList)(r0)	    # movsi load
	b.sw    	20(r10),r7	   # movsi store
	.stabn	68,0,449,.LM230-.LFBB10
.LM230:
	bw.sw    	(_OSTCBFreeList)(r0),r10	   # movsi store
	.stabn	68,0,451,.LM231-.LFBB10
.LM231:
	b.ori   	r7,r0,63	 # movqi imm J
	b.sb    	64(r10),r7	   # movqi store
	.stabn	68,0,452,.LM232-.LFBB10
.LM232:
	b.sb    	65(r10),r0	   # movqi store
	.stabn	68,0,454,.LM233-.LFBB10
.LM233:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r12,0
	.stabn	68,0,455,.LM234-.LFBB10
.LM234:
	b.jal  	_OS_Sched
	b.movi 	r6,0	     # movsi imm P
.L146:
	.stabn	68,0,457,.LM235-.LFBB10
.LM235:
	b.mov  	r3,r6	     # movsi
	b.reti  	4,0
	.size	_OSTaskDel, .-_OSTaskDel
	.stabs	"pevent:r(1,14)",64,0,368,4
	.stabs	"ptcb:r(0,16)",64,0,373,10
	.stabn	192,0,0,.LFBB10-.LFBB10
	.stabs	"val:r(0,4)",64,0,393,5
	.stabn	192,0,0,.LBB11-.LFBB10
	.stabn	224,0,0,.LBE11-.LFBB10
	.stabs	"val:r(0,4)",64,0,434,12
	.stabn	192,0,0,.LBB12-.LFBB10
	.stabn	224,0,0,.LBE12-.LFBB10
	.stabn	224,0,0,.Lscope10-.LFBB10
.Lscope10:
	.stabs	"",36,0,0,.Lscope10-.LFBB10
	.stabd	78,0,0
.proc _OSTaskCreateExt
	.stabs	"OSTaskCreateExt:F(2,2)",36,0,285,_OSTaskCreateExt
	.stabs	"task:P(0,20)=*(0,21)=f(0,15)",64,0,276,12
	.stabs	"p_arg:P(1,2)",64,0,277,13
	.stabs	"ptos:P(1,12)",64,0,278,14
	.stabs	"prio:P(2,2)",64,0,279,10
	.stabs	"id:P(2,4)",64,0,280,16
	.stabs	"pbos:P(1,12)",64,0,281,15
	.stabs	"stk_size:p(2,6)",160,0,282,44
	.stabs	"pext:p(1,2)",160,0,283,48
	.stabs	"opt:p(2,4)",160,0,284,54
	.global _OSTaskCreateExt
	.type	_OSTaskCreateExt, @function
_OSTaskCreateExt:
	.stabd	46,0,0
	.stabn	68,0,285,.LM236-.LFBB11
.LM236:
.LFBB11:
	b.entri 	9,2
	b.mov  	r12,r3	     # movsi
	b.mov  	r13,r4	     # movsi
	b.mov  	r14,r5	     # movsi
	b.mov  	r10,r6	     # movsi
	b.mov  	r16,r7	     # movsi
	b.mov  	r15,r8	     # movsi
	b.lhz   	r11,54(r1)
	.stabn	68,0,294,.LM237-.LFBB11
.LM237:
	b.ori  	r3,r0,42	  # movsi imm J
	b.bgtui  	r6,6,.L174
.LBB13:
	.stabn	68,0,298,.LM238-.LFBB11
.LM238:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r5,r7,0
.LBE13:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r5,-7
	l.mtspr r6,r7,0
	.stabn	68,0,299,.LM239-.LFBB11
.LM239:
	bw.lbz   	r7,(_OSIntNesting)(r0)
	b.beqi  	r7,0,.L175
	.stabn	68,0,300,.LM240-.LFBB11
.LM240:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	b.ori  	r3,r0,16	  # movsi imm J
	b.j    	.L174
.L175:
	.stabn	68,0,303,.LM241-.LFBB11
.LM241:
	b.mov  	r17,r10	     # movsi
	b.slli  	r7,r10,2
	b.addi  	r6,r7,_OSTCBPrioTbl
	b.lwz   	r7,0(r6)	    # movsi load
	b.bnei  	r7,0,.L177
	.stabn	68,0,304,.LM242-.LFBB11
.LM242:
	b.movi 	r7,1	     # movsi imm P
	b.sw    	0(r6),r7	   # movsi store
	.stabn	68,0,306,.LM243-.LFBB11
.LM243:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	.stabn	68,0,308,.LM244-.LFBB11
.LM244:
	b.mov  	r3,r8	     # movsi
	b.lwz   	r4,44(r1)	    # movsi load
	b.mov  	r5,r11	     # movsi
	b.jal  	_OS_TaskStkClr
	.stabn	68,0,310,.LM245-.LFBB11
.LM245:
	b.mov  	r3,r12	     # movsi
	b.mov  	r4,r13	     # movsi
	b.mov  	r5,r14	     # movsi
	b.mov  	r6,r11	     # movsi
	b.jal  	_OSTaskStkInit
	b.mov  	r4,r3	     # movsi
	.stabn	68,0,311,.LM246-.LFBB11
.LM246:
	b.sw    	0(r1),r11	   # movsi store
	b.mov  	r3,r10	     # movsi
	b.mov  	r5,r15	     # movsi
	b.mov  	r6,r16	     # movsi
	b.mlwz  	r7,44(r1),0
	b.jal  	_OS_TCBInit
	b.mov  	r10,r3	     # movsi
	.stabn	68,0,312,.LM247-.LFBB11
.LM247:
	b.bnei  	r3,0,.L179
	.stabn	68,0,313,.LM248-.LFBB11
.LM248:
	bw.lbz   	r7,(_OSRunning)(r0)
	b.bnei  	r7,1,.L181
	.stabn	68,0,314,.LM249-.LFBB11
.LM249:
	b.jal  	_OS_Sched
	b.j    	.L181
.L179:
.LBB14:
	.stabn	68,0,317,.LM250-.LFBB11
.LM250:
	b.ori  	r6,r0,17	  # movsi imm J
	l.mfspr r6,r6,0
.LBE14:
	b.ori  	r5,r0,17	  # movsi imm J
	b.andi  	r7,r6,-7
	l.mtspr r5,r7,0
	.stabn	68,0,318,.LM251-.LFBB11
.LM251:
	b.slli  	r7,r17,2
	b.addi  	r7,r7,_OSTCBPrioTbl
	b.sw    	0(r7),r0	   # movsi store
	.stabn	68,0,319,.LM252-.LFBB11
.LM252:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r6,0
.L181:
	.stabn	68,0,321,.LM253-.LFBB11
.LM253:
	b.mov  	r3,r10	     # movsi
	b.j    	.L174
.L177:
	.stabn	68,0,323,.LM254-.LFBB11
.LM254:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	b.ori  	r3,r0,40	  # movsi imm J
.L174:
	.stabn	68,0,325,.LM255-.LFBB11
.LM255:
	b.reti  	9,2
	.size	_OSTaskCreateExt, .-_OSTaskCreateExt
	.stabs	"psp:r(1,12)",64,0,286,4
	.stabs	"err:r(2,2)",64,0,287,10
	.stabs	"opt:r(2,4)",64,0,284,11
	.stabn	192,0,0,.LFBB11-.LFBB11
	.stabs	"val:r(0,4)",64,0,298,5
	.stabn	192,0,0,.LBB13-.LFBB11
	.stabn	224,0,0,.LBE13-.LFBB11
	.stabs	"val:r(0,4)",64,0,317,6
	.stabn	192,0,0,.LBB14-.LFBB11
	.stabn	224,0,0,.LBE14-.LFBB11
	.stabn	224,0,0,.Lscope11-.LFBB11
.Lscope11:
	.stabs	"",36,0,0,.Lscope11-.LFBB11
	.stabd	78,0,0
.proc _OSTaskCreate
	.stabs	"OSTaskCreate:F(2,2)",36,0,165,_OSTaskCreate
	.stabs	"task:P(0,20)",64,0,164,24
	.stabs	"p_arg:P(1,2)",64,0,164,4
	.stabs	"ptos:P(1,12)",64,0,164,5
	.stabs	"prio:P(2,2)",64,0,164,10
	.global _OSTaskCreate
	.type	_OSTaskCreate, @function
_OSTaskCreate:
	.stabd	46,0,0
	.stabn	68,0,165,.LM256-.LFBB12
.LM256:
.LFBB12:
	b.entri 	3,2
	b.mov  	r24,r3	     # movsi
	b.mov  	r10,r6	     # movsi
	.stabn	68,0,174,.LM257-.LFBB12
.LM257:
	b.ori  	r3,r0,42	  # movsi imm J
	b.bgtui  	r6,6,.L187
.LBB15:
	.stabn	68,0,178,.LM258-.LFBB12
.LM258:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r23,r7,0
.LBE15:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r23,-7
	l.mtspr r6,r7,0
	.stabn	68,0,179,.LM259-.LFBB12
.LM259:
	bw.lbz   	r7,(_OSIntNesting)(r0)
	b.beqi  	r7,0,.L188
	.stabn	68,0,180,.LM260-.LFBB12
.LM260:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r23,0
	b.ori  	r3,r0,16	  # movsi imm J
	b.j    	.L187
.L188:
	.stabn	68,0,183,.LM261-.LFBB12
.LM261:
	b.mov  	r11,r10	     # movsi
	b.slli  	r7,r10,2
	b.addi  	r6,r7,_OSTCBPrioTbl
	b.lwz   	r7,0(r6)	    # movsi load
	b.bnei  	r7,0,.L190
	.stabn	68,0,184,.LM262-.LFBB12
.LM262:
	b.movi 	r7,1	     # movsi imm P
	b.sw    	0(r6),r7	   # movsi store
	.stabn	68,0,186,.LM263-.LFBB12
.LM263:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r23,0
	.stabn	68,0,187,.LM264-.LFBB12
.LM264:
	b.mov  	r3,r24	     # movsi
	b.movi 	r6,0	     # movsi imm P
	b.jal  	_OSTaskStkInit
	b.mov  	r4,r3	     # movsi
	.stabn	68,0,188,.LM265-.LFBB12
.LM265:
	b.sw    	0(r1),r0	   # movsi store
	b.mov  	r3,r10	     # movsi
	b.movi 	r5,0	     # movsi imm P
	b.movi 	r6,0	     # movsi imm P
	b.movi 	r7,0	     # movsi imm P
	b.movi 	r8,0	     # movsi imm P
	b.jal  	_OS_TCBInit
	b.mov  	r10,r3	     # movsi
	.stabn	68,0,189,.LM266-.LFBB12
.LM266:
	b.bnei  	r3,0,.L192
	.stabn	68,0,190,.LM267-.LFBB12
.LM267:
	bw.lbz   	r7,(_OSRunning)(r0)
	b.bnei  	r7,1,.L194
	.stabn	68,0,191,.LM268-.LFBB12
.LM268:
	b.jal  	_OS_Sched
	b.j    	.L194
.L192:
.LBB16:
	.stabn	68,0,194,.LM269-.LFBB12
.LM269:
	b.ori  	r6,r0,17	  # movsi imm J
	l.mfspr r6,r6,0
.LBE16:
	b.ori  	r5,r0,17	  # movsi imm J
	b.andi  	r7,r6,-7
	l.mtspr r5,r7,0
	.stabn	68,0,195,.LM270-.LFBB12
.LM270:
	b.slli  	r7,r11,2
	b.addi  	r7,r7,_OSTCBPrioTbl
	b.sw    	0(r7),r0	   # movsi store
	.stabn	68,0,196,.LM271-.LFBB12
.LM271:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r6,0
.L194:
	.stabn	68,0,198,.LM272-.LFBB12
.LM272:
	b.mov  	r3,r10	     # movsi
	b.j    	.L187
.L190:
	.stabn	68,0,200,.LM273-.LFBB12
.LM273:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r23,0
	b.ori  	r3,r0,40	  # movsi imm J
.L187:
	.stabn	68,0,202,.LM274-.LFBB12
.LM274:
	b.reti  	3,2
	.size	_OSTaskCreate, .-_OSTaskCreate
	.stabs	"psp:r(1,12)",64,0,166,4
	.stabs	"err:r(2,2)",64,0,167,10
	.stabn	192,0,0,.LFBB12-.LFBB12
	.stabs	"val:r(0,4)",64,0,178,23
	.stabn	192,0,0,.LBB15-.LFBB12
	.stabn	224,0,0,.LBE15-.LFBB12
	.stabs	"val:r(0,4)",64,0,194,6
	.stabn	192,0,0,.LBB16-.LFBB12
	.stabn	224,0,0,.LBE16-.LFBB12
	.stabn	224,0,0,.Lscope12-.LFBB12
.Lscope12:
	.stabs	"",36,0,0,.Lscope12-.LFBB12
	.stabd	78,0,0
	.stabs	"",100,0,0,.Letext0
.Letext0:
	.ident	"GCC: (GNU) 4.2.1"
