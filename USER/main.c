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
/*
ע�� 2018 10.16
*/
 extern u8 SPO2_FLAG;
 /*******************************************************************************
  * @��������	main
  * @����˵��   ������ ע�������ж�������ƫ��
  * @�������   ��
  * @�������   ��
  * @���ز���   ��
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

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�жϷ�������
	 
	 
  USART1_DMA_Init(USART1_BaudRate);	
	USART2_DMA_Init(USART2_BaudRate);		
  USART3_DMA_Init(USART3_BaudRate);	
	UART5_Init(USART5_BaudRate);
	ADC_Sensor_Init();
	 
	 
	u16 Send_Size =5;
	u8 Send_Date[Send_Size];
	Send_Date[0]=0x01;
	Send_Date[1]=0x03;
	Send_Date[2]=0x0C;
	Send_Date[3]=0x0D;
	Send_Date[4]=0x0A;	 
	SPI2_Init();
  Hall_Senor_Init();
//  PWM_Init_Default();
//  Set_PWM_CH4_Duty_Cycle(30);
//  delay_ms(1000);
	USART3_DMA_Send_Once_Data(Send_Date,Send_Size);  //���Ե�ʱ���ҵ�����3

//  UART5_Send_Once_Data(Send_Date,Send_Size); 
//	USART2_DMA_Send_Once_Data(Send_Date,Send_Size);  //���Ե�ʱ���ҵ�����2
	while(1)
	{
		//ѭ�����Ѫ����Ϣ�Ƿ���Ҫ����
    if(SPO2_FLAG==1)  //��Ҫ����Ѫ����Ϣ UART5û��DMA����ռ����Դ����
		{
			SPO2_Response();
		}
	}
 }

