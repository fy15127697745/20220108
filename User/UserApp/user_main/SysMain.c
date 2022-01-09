#include "stm32f10x.h"
#include "delay.h"
#include "usart.h"
#include "timer.h"
#include "led.h"
#include "iap.h"
#include "usart.h"
#include "delay.h"
int main( void )
{
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	uart_init(115200);
	TIM3_Int_Init(10000, 7200);
	LED_Init();
	delay_init();
	LED0 = 0;
	while(1){
		if(gcTimRxFlag == 1){
			gcTimRxFlag = 0;
				TIM_ITConfig(TIM3,TIM_IT_Update,DISABLE );
			if(((*(vu32*)(0X20001000+4))&0xFF000000)==0x08000000) 
				iap_write_appbin(FLASH_APP1_ADDR,USART_RX_BUF,USART_RX_CNT);//更新FLASH代码   
			
			if(((*(vu32*)(FLASH_APP1_ADDR+4))&0xFF000000)==0x08000000){	
				iap_load_app(FLASH_APP1_ADDR);//执行FLASH APP代码					
				
			}
		}
	}
}
	






