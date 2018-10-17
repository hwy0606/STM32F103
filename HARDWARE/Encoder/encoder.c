//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//Hall_Sensor驱动程序 
//引脚 PC0
//电机速度存储在float型变量motor_speed中
//HWY 2017 10 19
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 
#include "stm32f10x.h"
#include "encoder.h" 
#include "math.h"		
#include "project_config.h"

//使用T法测量速度 
//通过测量高速计数器计入相邻两个输入脉冲之间的时间来确定被测速度
static u32 count_now;//计数器当前值
static u32 count_last;//计数器上一次进中断计数值
static u32 count_diff;//计数器差值
float motor_speed=0.0;//电机转速

void PC0_Hall_IPD_Init(void)
{	
	#ifdef USE_PC0_HALL_IPD
	GPIO_InitTypeDef  GPIO_InitStructure;
	NVIC_InitTypeDef  NVIC_InitStructure;
	EXTI_InitTypeDef  EXTI_InitStructure;

	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;//下拉输入模式 
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource0);
  EXTI_InitStructure.EXTI_Line=EXTI_Line0;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);		//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;			//使能外部中断通道
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = PC0_HALL_PreemptionPriority;	//抢占优先级2 
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = PC0_HALL_SubPriority;					//子优先级1
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
  NVIC_Init(&NVIC_InitStructure);  	  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器
	#endif
}


#ifdef USE_PC0_HALL_IPD
void EXTI0_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line0)!=RESET)
	{	  
		//接用户操作函数
		 count_now= TIM_GetCounter(TIM2);	 //取当前时间  CNT寄存器值
		if(count_now>count_last) //考虑一次上溢 
	   {
		 count_diff=count_now-count_last;
		 }
    else
			{
		count_diff=count_now+65534-count_last; //0xFFFE
		  }  

	   motor_speed=HALL_SPEED_CONST/(float)(count_diff);            //单位 n/min
	   count_last=count_now;

	}
	EXTI_ClearITPendingBit(EXTI_Line0);  //清除EXTI0线路挂起位
}
#endif


/**
 * @Description: TIM2计数模式初始化
 * @note1： TIM2是16位定时器最大可计数到65535
 * @note2： 65535  
PS:STM32F4 对应的TIM2是32位计数器 
 */
void Timer2_Init(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    TIM_TimeBaseInitStructure.TIM_Period = 0xFFFF; 				//自动重装载值  65535
    TIM_TimeBaseInitStructure.TIM_Prescaler=7200-1;  					//定时器分频  减小分辨率扩大计时时间           
    TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; 	//向上计数模式
    TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 		//
    TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);				//初始化TIM
    TIM_ITConfig(TIM2,TIM_IT_Update,DISABLE); 						//禁止定时器更新中断
    TIM_Cmd(TIM2,ENABLE); 											//使能定时器	
}

//Hall_Sensor初始化
void Hall_Senor_Init(void)
{
	PC0_Hall_IPD_Init();
	Timer2_Init();	
}
