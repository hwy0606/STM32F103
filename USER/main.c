#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart1_dma.h"
#include "usart2_dma.h"
#include "usart3_dma.h"
#include "pwm.h"
#include "key.h"
#include "usart1_protocol.h"
/*
◊¢ Õ
*/
 int main(void)
 { 
	delay_init();	    	 	  
	LED_Init();	
	KEY_Init(); 
	USART1_Key_Init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//÷–∂œ∑÷◊È≈‰÷√
  USART1_DMA_Init(115200);	
//	USART2_DMA_Init(115200);		
//  USART3_DMA_Init(115200);	
	PWM_Init_Default();
  Set_PWM_CH1_Duty_Cycle(80);		 
	Set_PWM_CH2_Duty_Cycle(80);	
	 
	u32 Send_Size =5;
	u8 Send_Date[Send_Size];
	Send_Date[0]=0x00;
	Send_Date[1]=0x01;
	Send_Date[2]=0x02;
	Send_Date[3]=0x0D;
	Send_Date[4]=0x0A;
	 
  LED0=0;
	LED1=0;
	
	while(1)
	{
//	  USART1_DMA_Send_Once_Data(Send_Date,Send_Size);	
//		USART2_DMA_Send_Once_Data(Send_Date,Send_Size);	
//		USART3_DMA_Send_Once_Data(Send_Date,Send_Size);	
		delay_ms(1000);		 
	}
 }

