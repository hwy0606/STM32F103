#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart1_dma.h"
#include "usart2_dma.h"
#include "usart3_dma.h"
#include "pwm.h"
#include "key.h"
#include "motor_control.h"
#include "usart1_protocol.h"
#include "usart2_protocol.h"
#include "usart3_protocol.h"
#include "encoder.h"
#include "stm32f10x_tim.h"
/*
注释
*/
 extern u8 SPO2_FLAG;
 int main(void)
 { 
	 
	SCB->VTOR = FLASH_BASE | 0x10000; /* Vector Table Relocation in Internal FLASH. */	 
	delay_init();	    	 	  
	LED_Init();	
	KEY_Init(); 
	USART1_Key_Init();
	USART1_Speed_Init();
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
  
  USART1_DMA_Send_Once_Data(Send_Date,Send_Size);  //测试的时候找到串口1
  
  Hall_Senor_Init();
  PWM_Init_Default();
  Set_PWM_CH1_Duty_Cycle(30);
//  TIM_SetCompare1(TIM4,10000/2);
  delay_ms(1000);
	delay_ms(1000);
	delay_ms(1000);
	USART1_DMA_Send_Once_Data(Send_Date,Send_Size);  //测试的时候找到串口1
	while(1)
	{
		//循环检测血氧信息是否需要更新
    if(SPO2_FLAG==1)  //需要更新血氧信息
		{
			SPO2_Response();
		}
	}
 }

