#include "gpio.h"

//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//GPIO驱动
//驱动层+硬件层
//HWY 2018 9 15
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	    
#ifdef USE_INTERNET_GPIO
void Internet_GPIO_Init()
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = CFG_GPIO_PA1;				 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
  GPIO_Init(INTERNET_GPIO, &GPIO_InitStructure);					 
	
	GPIO_InitStructure.GPIO_Pin = RST_GPIO_PA4;				 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
  GPIO_Init(INTERNET_GPIO, &GPIO_InitStructure);					 
}
#endif

#ifdef USE_BP_GPIO
void BP_RESET_Init()
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = RESET_GPIO_PA14;				 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
  GPIO_Init(BP_GPIO, &GPIO_InitStructure);	
}
#endif

#ifdef USE_SPO2_GPIO
void SPO2_SLEEP_Init()
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = SLEEP_GPIO_PA15;				 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
  GPIO_Init(SPO2_GPIO, &GPIO_InitStructure);	
}
#endif

#ifdef USE_BACKUP_GPIO
void BACKUP_GPIO_Init()
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = BACKUP_GPIO_PB3;				 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
  GPIO_Init(BACKUP_IN1_GPIO, &GPIO_InitStructure);	
	
	GPIO_InitStructure.GPIO_Pin = BACKUP_GPIO_PA13;				 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
  GPIO_Init(BACKUP_IN2_GPIO, &GPIO_InitStructure);	
}
#endif

#ifdef USE_MOTOR_GPIO
void MOTOR_GPIO_Init()
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = MOTOR_GPIO_PB4;				 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
  GPIO_Init(MOTOR_GPIO, &GPIO_InitStructure);	
}
#endif

#ifdef USE_LED_GPIO
void LED_GPIO_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 GPIO_InitStructure.GPIO_Pin = LED_GPIO_PB5;				 //GPIO-->PB.5 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(LED_GPIO, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.5
}
#endif



#ifdef USE_ACTUATOR_GPIO
void ACTUATOR_GPIO_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;	
 GPIO_InitStructure.GPIO_Pin = ACTUATOR_GPIO_PB6;				 
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
 GPIO_Init(ACTUATOR_GPIO, &GPIO_InitStructure);					 

 GPIO_InitStructure.GPIO_Pin = ACTUATOR_GPIO_PB7;				 
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
 GPIO_Init(ACTUATOR_GPIO, &GPIO_InitStructure);					 

}
#endif


#ifdef USE_OE_GPIO
void OE_GPIO_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;	
 GPIO_InitStructure.GPIO_Pin = OE_GPIO_PC2;				 
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
 GPIO_Init(OE_GPIO, &GPIO_InitStructure);		
}
#endif


