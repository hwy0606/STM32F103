#include "delay.h"
#include "sys.h"
#include "usart1_dma.h"
#include "usart2_dma.h"
#include "usart3_dma.h"
#include "usart5_dma.h"
#include "pwm.h"
#include "key.h"
#include "motor_control.h"
//#include "usart1_protocol.h"
#include "usart2_protocol.h"
#include "usart3_protocol.h"
#include "usart5_protocol.h"
#include "encoder.h"
#include "rcc.h"
#include "adc.h"
#include "spi.h"
#include "flash.h"
#include "malloc.h"
#include "tim3.h"
/*
注释 2018 10.17 
SRAM 48K
FLASH 256K
*/
 extern u8 SPO2_FLAG;
 extern u8 SEAT_FLAG;
 extern u8 FLASH_FLAG;
 extern u8 TIM3_FLAG;
 /*******************************************************************************
  * @函数名称	main
  * @函数说明   主函数 注意设置中断向量表偏移
  * @输入参数   无
  * @输出参数   无
  * @返回参数   无
*******************************************************************************/
 int main(void)
 { 
	 
	SCB->VTOR = FLASH_BASE | 0x10000; /* Vector Table Relocation in Internal FLASH. */	 
	delay_init();	    	 	  
  RCC_Init();
	KEY_Init(); 
	USART2_Key_Init();
	USART2_Speed_Init();
	UART5_Sensor_Init();	 

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//中断分组配置
	 
	 
  USART1_DMA_Init(USART1_BaudRate);	
	USART2_DMA_Init(USART2_BaudRate);		
  USART3_DMA_Init(USART3_BaudRate);	
	UART5_Init(USART5_BaudRate);
	 	 
	ADC_Sensor_Init();	 
	Flash_Buffer_Init(); 
	SPI2_Init();
  Hall_Senor_Init();
	
	u16 Send_Size =5;
	u8 Send_Date[Send_Size];
	Send_Date[0]=0x01;
	Send_Date[1]=0x03;
	Send_Date[2]=0x0C;
	Send_Date[3]=0x0D;
	Send_Date[4]=0x0A;	 


	USART3_DMA_Send_Once_Data(Send_Date,Send_Size);  //测试的时候找到串口3

	
	mem_init(); //初始化内存管理 目前可供管理空间为20K 后期进一步优化
		
	delay_ms(1000); //等待1S使系统稳定下来
  Get_Flash_Buffer(); //更新掉电信息 （座椅高度信息）
	
	TIM3_Init();
	while(1)
	{
		
		//循环检测血氧信息是否需要更新
    if(SPO2_FLAG==1)  //需要更新血氧信息 UART5没用DMA所以占用资源过多 采用更新发送
		{
			SPO2_Response();
			SPO2_FLAG=0x00;
		}
		
		FLASH_FLAG=SEAT_FLAG || 0x01; //判断FLASH掉电信息是否需要保存 所有FLAG位或运算
		if(FLASH_FLAG==1)  //座椅高度更新 OR 其他需要掉电保存的信息更新 
		{
			Set_Flash_Buffer();
			SEAT_FLAG=0x00;
			FLASH_FLAG=0x00;
		}
		
		if(TIM3_FLAG==1)
		{
			/*发送相关数据给上位机 */
			
			
			
			/*发送完成后重新开启计时*/
			TIM3_FLAG=0x00;
			TIM3_ENABLE();
		}
	}
 }

