////////////////////////////////////////////////////////	 
//STM32F103RCT6
//TIM3 驱动程序
//HWY 2018 10 27
//All rights reserved									  
///////////////////////////////////////////////////////
#include "tim3.h"
#include "stm32f10x_tim.h"
#include "project_config.h"
/*输入时钟频率为 72M */
void TIM3_Init()
{
	 TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	 NVIC_InitTypeDef NVIC_InitStructure;
   TIM_TimeBaseInitStructure.TIM_Period = TIM3_ARR; 				//自动重装载值  65535
   TIM_TimeBaseInitStructure.TIM_Prescaler=TIM3_PSC;  					//定时器分频  减小分辨率扩大计时时间           
   TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; 	//向上计数模式
   TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 		//
   TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);				//初始化TIM
   
	 TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE); 						//使能定时器更新中断
	 NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn;
	 NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=TIM3_IRQ_PreemptionPriority;
	 NVIC_InitStructure.NVIC_IRQChannelSubPriority=TIM3_IRQ_SubPriority;
	 NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	 NVIC_Init(&NVIC_InitStructure);
	
   TIM_Cmd(TIM3,ENABLE); 											//使能定时器	
	
}

void TIM3_ENABLE()
{
	TIM_Cmd(TIM3,ENABLE); 	
}

void TIM3_DISABLE()
{
	TIM_Cmd(TIM3,DISABLE); 
}

u8 TIM3_FLAG=0; //更新标志位
void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)!=RESET)
	{
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
		TIM3_FLAG=1;
	  TIM3_DISABLE();
	}
}