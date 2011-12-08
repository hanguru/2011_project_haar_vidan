#ifndef _TASK_MANAGE_H_
#define _TASK_MANAGE_H_

#include "ucos_ii.h"

//Task Create Parameter
//#define MAIN_TASK_STACK_SIZE	     0x600 //6K bytes
#define MAIN_TASK_STACK_SIZE	     0x1000 //6K bytes
#define MAIN_TASK_PRIO	           1

#define EXTERNAL_TASK_STACK_SIZE	  0x600 //6K bytes
#define EXTERNAL_TASK_PRIO	        0
extern void external_task(void *data);

OS_EVENT *pEventExternalTaskDone;

extern void stkChk(const char *fmt);

#endif
