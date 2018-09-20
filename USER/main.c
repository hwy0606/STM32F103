#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart1_dma.h"
#include "usart2_dma.h"
#include "usart3_dma.h"
#include "key.h"
#include "motor_control.h"
#include "usart1_protocol.h"
#include "usart2_protocol.h"
#include "usart3_protocol.h"
/*
注释
*/
 extern u8 SPO2_FLAG;
 int main(void)
 { 
	delay_init();	    	 	  
	LED_Init();	
	KEY_Init(); 
	USART1_Key_Init();
	USART2_Sensor_Init();
	USART3_Sensor_Init();
	
	
	Motor_Init(); 
	 
	 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//中断分组配置
	 
	 
  USART1_DMA_Init(USART1_BaudRate);	
	USART2_DMA_Init(USART2_BaudRate);		
  USART3_DMA_Init(USART3_BaudRate);	
	
	 
	u32 Send_Size =5;
	u8 Send_Date[Send_Size];
	Send_Date[0]=0x00;
	Send_Date[1]=0x01;
	Send_Date[2]=0x02;
	Send_Date[3]=0x0D;
	Send_Date[4]=0x0A;	 
  TEST_LED0=1;
	TEST_LED1=1;
  
 USART1_DMA_Send_Once_Data(Send_Date,Send_Size);
 

	while(1)
	{
		//循环检测血氧信息是否需要更新
    if(SPO2_FLAG==1)  //需要更新血氧信息
		{
			SPO2_Response();
		}
	}
 }
 

