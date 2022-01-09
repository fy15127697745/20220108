#include "system.h"
#include "timer.h"
#include "sys.h"
#define TASKNUM (sizeof(stTaskCompone)/sizeof(stTaskCompone[0]))
uint8_t gbWatchDogEnable = TRUE;

stTaskComponent stTaskCompone[1];


//任务计数   开启定时器中断计数
uint8_t funApiTaskProce(void)
{
	uint32_t bLoop;
	for(bLoop=0; bLoop<TASKNUM; bLoop++)	{
		if(!stTaskCompone[bLoop].TackReady){
			if(stTaskCompone[bLoop].TimerSlice){
				stTaskCompone[bLoop].TimerSlice--;
				if(stTaskCompone[bLoop].TimerSlice==0){
					stTaskCompone[bLoop].TackReady = 1;
					stTaskCompone[bLoop].TimerSlice = stTaskCompone[bLoop].SliceNumber;
				}
			}
		}
	}
		return 0;
}


//任务运行   主函数循环判断任务是否就绪
uint8_t funAppTaskRun(void)
{
	uint32_t bLoop;
	for(bLoop=0; bLoop<TASKNUM; bLoop++){
		if(stTaskCompone[bLoop].TackReady){
			stTaskCompone[bLoop].TackPoin();
			stTaskCompone[bLoop].TackReady = 0;
		}
	}	
	return 0;
}

void IWDG_Init(u8 prer,u16 rlr) 
{	
 	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);  
	IWDG_SetPrescaler(prer);  
	IWDG_SetReload(rlr);  
	IWDG_ReloadCounter();  
	IWDG_Enable(); 
}


void funFeedIWDG(void)
{
	if(gbWatchDogEnable == TRUE){
		IWDG_ReloadCounter();							
	}
}









