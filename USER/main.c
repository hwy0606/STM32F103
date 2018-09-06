#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart1_dma.h"
/*
本程序无注释 嘻嘻
*/
 int main(void)
 {
	 
	delay_init();	    	 	  
	LED_Init();	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//中断分组配置
	USART1_DMA_Init(115200);	 
	 u32 Send_Size =4;
	u8 Send_Date[Send_Size];
	 Send_Date[0]=0x00;
	 Send_Date[1]=0x01;
	 Send_Date[2]=0x02;
	 Send_Date[3]=0x03;
	while(1)
	{
		USART1_DMA_Send_Once_Data(Send_Date,Send_Size);		
		delay_ms(1000);		
	}
 }

