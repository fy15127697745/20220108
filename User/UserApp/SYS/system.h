#ifndef _SYSTEM_H
#define _SYSTEM_H

#include "stm32f10x.h"

#define TRUE			1
#define FALSE		0

typedef void (*TaskPointer)(void);

typedef struct taskComponent
{
	uint8_t TackReady;    //就绪标志
	uint16_t TimerSlice;   //计数
	uint16_t SliceNumber;  //复位计数值
	TaskPointer TackPoin;	//任务	
}stTaskComponent; 


uint8_t funAppTaskRun(void);  //任务运行
uint8_t funApiTaskProce(void);//任务计数管理 
void IWDG_Init(u8 prer,u16 rlr);
void funFeedIWDG(void);
#endif //_USER_SYSDRV_H




