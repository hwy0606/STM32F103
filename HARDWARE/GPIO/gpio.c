#include "gpio.h"

//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//GPIO驱动
//引脚 4 PB12 PB13 PB14 PB15
//引脚 3 PC10 PC11 PC12
//驱动层+硬件层
//HWY 2018 9 15
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	    

#ifdef USE_MOTOR_GPIO
void Motor_GPIO_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 RCC_APB2PeriphClockCmd(MOTOR_GPIO_RCC,ENABLE);	 //使能PB端口时钟
	
 GPIO_InitStructure.GPIO_Pin = MOTOR_GPIO_PB12;				 //GPIO-->PB.12 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(MOTOR_GPIO, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.12

 GPIO_InitStructure.GPIO_Pin = MOTOR_GPIO_PB13;				 //GPIO-->PB.13 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(MOTOR_GPIO, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.13
	
 GPIO_InitStructure.GPIO_Pin = MOTOR_GPIO_PB14;				 //GPIO-->PB.14 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(MOTOR_GPIO, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.14
	
 GPIO_InitStructure.GPIO_Pin = MOTOR_GPIO_PB15;				 //GPIO-->PB.15 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(MOTOR_GPIO, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.15
}
#endif

#ifdef USE_LED_GPIO
void LED_GPIO_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 RCC_APB2PeriphClockCmd(LED_GPIO_RCC,ENABLE);	 //使能PB端口时钟
	
 GPIO_InitStructure.GPIO_Pin = LED_GPIO_PC10;				 //GPIO-->PC.10 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(LED_GPIO, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.12

 GPIO_InitStructure.GPIO_Pin = LED_GPIO_PC11;				 //GPIO-->PC.11 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(LED_GPIO, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.13
	
 GPIO_InitStructure.GPIO_Pin = LED_GPIO_PC12;				 //GPIO-->PC.12 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(LED_GPIO, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.14
}
#endif