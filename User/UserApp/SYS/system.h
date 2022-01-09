#ifndef _SYSTEM_H
#define _SYSTEM_H

#include "stm32f10x.h"

#define TRUE			1
#define FALSE		0

typedef void (*TaskPointer)(void);

typedef struct taskComponent
{
	uint8_t TackReady;    //������־
	uint16_t TimerSlice;   //����
	uint16_t SliceNumber;  //��λ����ֵ
	TaskPointer TackPoin;	//����	
}stTaskComponent; 


uint8_t funAppTaskRun(void);  //��������
uint8_t funApiTaskProce(void);//����������� 
void IWDG_Init(u8 prer,u16 rlr);
void funFeedIWDG(void);
#endif //_USER_SYSDRV_H




