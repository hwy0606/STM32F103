#include "key.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_exti.h"
#include "project_config.h"
#include "delay.h"
#include "usart2_protocol.h"
//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//KEY 驱动
//引脚 PB1 PB2 PC6 PC7 PC8 PC9 PB10 PB11
//所有按键接低电平 默认上拉 检测下降沿
//HWY 2017 10 17
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 	 		    

void KEY_Init(void)
{	
	
	GPIO_InitTypeDef  GPIO_InitStructure;
	NVIC_InitTypeDef  NVIC_InitStructure;
	EXTI_InitTypeDef  EXTI_InitStructure;
	
	#ifdef USE_PB1_KEY
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//上拉输入模式 
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource1);
  EXTI_InitStructure.EXTI_Line=EXTI_Line1;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);		//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;			//使能按键所在的外部中断通道
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = PB1_KEY_PreemptionPriority;	//抢占优先级1 
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = PB1_KEY_SubPriority;					//子优先级1
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
  NVIC_Init(&NVIC_InitStructure);  	  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器
	#endif
	
	#ifdef USE_PB2_KEY
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//上拉输入模式 
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource2);
  EXTI_InitStructure.EXTI_Line=EXTI_Line2;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);		//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;			//使能按键所在的外部中断通道
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = PB2_KEY_PreemptionPriority;	//抢占优先级2 
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = PB2_KEY_SubPriority;					//子优先级1
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
  NVIC_Init(&NVIC_InitStructure);  	  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器
	#endif
	
	
	#ifdef USE_PC6_KEY
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//上拉输入模式 
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource6);
  EXTI_InitStructure.EXTI_Line=EXTI_Line6;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);		//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//使能按键所在的外部中断通道
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = ELSE_KEY_PreemptionPriority;	//抢占优先级2 
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = ELSE_KEY_SubPriority;					//子优先级1
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
  NVIC_Init(&NVIC_InitStructure);  	  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器
	#endif
	
	#ifdef USE_PC7_KEY
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//上拉输入模式 
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource7);
  EXTI_InitStructure.EXTI_Line=EXTI_Line7;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);		//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//使能按键所在的外部中断通道
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = ELSE_KEY_PreemptionPriority;	//抢占优先级2 
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = ELSE_KEY_SubPriority;					//子优先级1
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
  NVIC_Init(&NVIC_InitStructure);  	  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器
	#endif
	
	#ifdef USE_PC8_KEY
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//上拉输入模式 
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource8);
  EXTI_InitStructure.EXTI_Line=EXTI_Line8;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);		//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//使能按键所在的外部中断通道
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = ELSE_KEY_PreemptionPriority;	//抢占优先级2 
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = ELSE_KEY_SubPriority;					//子优先级1
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
  NVIC_Init(&NVIC_InitStructure);  	  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器
	#endif
	
	#ifdef USE_PC9_KEY
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//上拉输入模式 
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource9);
  EXTI_InitStructure.EXTI_Line=EXTI_Line9;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);		//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//使能按键所在的外部中断通道
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = ELSE_KEY_PreemptionPriority;	//抢占优先级2 
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = ELSE_KEY_SubPriority;					//子优先级1
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
  NVIC_Init(&NVIC_InitStructure);  	  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器
	#endif

	#ifdef USE_PB10_KEY
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//上拉输入模式 
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource10);
  EXTI_InitStructure.EXTI_Line=EXTI_Line10;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);		//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;			//使能按键所在的外部中断通道
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = ELSE_KEY_PreemptionPriority;	//抢占优先级2 
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = ELSE_KEY_SubPriority;					//子优先级1
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
  NVIC_Init(&NVIC_InitStructure);  	  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器
	#endif
	
		#ifdef USE_PB11_KEY
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//上拉输入模式 
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource11);
  EXTI_InitStructure.EXTI_Line=EXTI_Line11;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);		//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;			//使能按键所在的外部中断通道
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = PB11_KEY_PreemptionPriority;	//抢占优先级2 
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = PB11_KEY_SubPriority;					//子优先级1
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
  NVIC_Init(&NVIC_InitStructure);  	  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器
	#endif
} 



#ifdef USE_PB1_KEY
void EXTI1_IRQHandler(void)
{
  delay_ms(2);    //消抖
	if(EXTI_GetITStatus(EXTI_Line1)!=RESET)
	{	   	
		//接用户操作函数
		KEY1_Response();	
	  EXTI_ClearITPendingBit(EXTI_Line1);  //清除EXTI1线路挂起位	
	}
	
}	
#endif

#ifdef USE_PB2_KEY
void EXTI2_IRQHandler(void)
{
  delay_ms(2);    //消抖
	if(EXTI_GetITStatus(EXTI_Line2)!=RESET)
	{	  
		//接用户操作函数
    KEY2_Response();	
	  EXTI_ClearITPendingBit(EXTI_Line2);  //清除EXTI2线路挂起位	
	}
	
}	
#endif




void EXTI9_5_IRQHandler(void)
{
  delay_ms(2);    //消抖
	
	#ifdef  USE_PC6_KEY
	if(EXTI_GetITStatus(EXTI_Line6)!=RESET)
	{	  
		//接用户操作函数
		KEY6_Response();
		EXTI_ClearITPendingBit(EXTI_Line6);  //清除EXTI6线路挂起位
	}
	#endif
	
	#ifdef  USE_PC7_KEY
	if(EXTI_GetITStatus(EXTI_Line7)!=RESET)
	{	  
		//接用户操作函数
		KEY7_Response();
		EXTI_ClearITPendingBit(EXTI_Line7);  //清除EXTI7线路挂起位
	}
	#endif
	
	#ifdef  USE_PC8_KEY
	if(EXTI_GetITStatus(EXTI_Line8)!=RESET)
	{	  
		//接用户操作函数
		KEY8_Response();
		EXTI_ClearITPendingBit(EXTI_Line8);  //清除EXTI8线路挂起位
	}
	#endif
	
	#ifdef  USE_PC9_KEY
	if(EXTI_GetITStatus(EXTI_Line9)!=RESET)
	{	  
		//接用户操作函数
		KEY9_Response();
		EXTI_ClearITPendingBit(EXTI_Line9);  //清除EXTI9线路挂起位
	}
	#endif
}	


void EXTI15_10_IRQHandler(void)
{
  delay_ms(2);    //消抖
	#ifdef  USE_PB10_KEY
	if(EXTI_GetITStatus(EXTI_Line10)!=RESET)
	{	  
		//接用户操作函数
		KEY10_Response();
		EXTI_ClearITPendingBit(EXTI_Line10);  //清除EXTI10线路挂起位
	}
	#ifdef  USE_PB11_KEY
	#endif
		if(EXTI_GetITStatus(EXTI_Line11)!=RESET)
	{	  
		//接用户操作函数
		KEY11_Response();
		EXTI_ClearITPendingBit(EXTI_Line11);  //清除EXTI11线路挂起位
	}
	#endif
}