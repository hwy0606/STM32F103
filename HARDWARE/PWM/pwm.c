#include "pwm.h"
#include "project_config.h"
//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//四路PWM输出 
//引脚 TIM4 通用定时器 CH1-PB6  CH2-PB7 CH3-PB8 CH4-PB9
//此处有个BUG 使用串口DMA则不能使用高级定时器 暂时未解决
//驱动层
//HWY 2018 09 11
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
/**
* @Description: PWM输出初始化
* @param arr：自动重装值
         psc：时钟预分频数  
*/ 

void PWM_Init(u16 arr,u16 psc)
{ 
  GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
#ifdef USE_PWM_CH1
	//CH1通道初始化	
	RCC_APB1PeriphClockCmd(PWM_TIM_RCC, ENABLE);
 	RCC_APB2PeriphClockCmd(PWM_GPIO_RCC|PWM_AFIO_RCC,ENABLE);  //使能GPIO外设时钟使能                                                                     	
	GPIO_InitStructure.GPIO_Pin = PWM_CH1_GPIO; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PWM_GPIO, &GPIO_InitStructure);	
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 80K
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值  不分频
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(PWM_TIM, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_Pulse = 0; //设置待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
	TIM_OC1Init(PWM_TIM, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
  TIM_CtrlPWMOutputs(PWM_TIM,ENABLE);	//MOE 主输出使能	
	TIM_OC1PreloadConfig(PWM_TIM, TIM_OCPreload_Enable);  
	TIM_ARRPreloadConfig(PWM_TIM, ENABLE); //使能TIMx在ARR上的预装载寄存器
	TIM_Cmd(PWM_TIM, ENABLE);  //使能TIM
#endif
	//CH2通道初始化
#ifdef USE_PWM_CH2
	RCC_APB1PeriphClockCmd(PWM_TIM_RCC, ENABLE);
 	RCC_APB2PeriphClockCmd(PWM_GPIO_RCC|PWM_AFIO_RCC,ENABLE);  //使能GPIO外设时钟使能                                                                     	
	GPIO_InitStructure.GPIO_Pin = PWM_CH2_GPIO; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PWM_GPIO, &GPIO_InitStructure);	
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 80K
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值  不分频
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(PWM_TIM, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_Pulse = 0; //设置待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
	TIM_OC2Init(PWM_TIM, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
  TIM_CtrlPWMOutputs(PWM_TIM,ENABLE);	//MOE 主输出使能	
	TIM_OC2PreloadConfig(PWM_TIM, TIM_OCPreload_Enable);  	 
	TIM_ARRPreloadConfig(PWM_TIM, ENABLE); //使能TIMx在ARR上的预装载寄存器
	TIM_Cmd(PWM_TIM, ENABLE);  //使能TIM
#endif
//CH3通道初始化
#ifdef USE_PWM_CH3
	RCC_APB1PeriphClockCmd(PWM_TIM_RCC, ENABLE);
 	RCC_APB2PeriphClockCmd(PWM_GPIO_RCC|PWM_AFIO_RCC,ENABLE);  //使能GPIO外设时钟使能                                                                     	
	GPIO_InitStructure.GPIO_Pin = PWM_CH3_GPIO; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PWM_GPIO, &GPIO_InitStructure);	
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 80K
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值  不分频
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(PWM_TIM, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_Pulse = 0; //设置待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
	TIM_OC3Init(PWM_TIM, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
  TIM_CtrlPWMOutputs(PWM_TIM,ENABLE);	//MOE 主输出使能	
	TIM_OC3PreloadConfig(PWM_TIM, TIM_OCPreload_Enable);  	 
	TIM_ARRPreloadConfig(PWM_TIM, ENABLE); //使能TIMx在ARR上的预装载寄存器
	TIM_Cmd(PWM_TIM, ENABLE);  //使能TIM
#endif
//CH4通道初始化
#ifdef USE_PWM_CH4
	RCC_APB1PeriphClockCmd(PWM_TIM_RCC, ENABLE);
 	RCC_APB2PeriphClockCmd(PWM_GPIO_RCC|PWM_AFIO_RCC,ENABLE);  //使能GPIO外设时钟使能                                                                     	
	GPIO_InitStructure.GPIO_Pin = PWM_CH4_GPIO; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PWM_GPIO, &GPIO_InitStructure);	
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 80K
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值  不分频
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(PWM_TIM, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_Pulse = 0; //设置待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
	TIM_OC4Init(PWM_TIM, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
  TIM_CtrlPWMOutputs(PWM_TIM,ENABLE);	//MOE 主输出使能	
	TIM_OC4PreloadConfig(PWM_TIM, TIM_OCPreload_Enable);  	 
	TIM_ARRPreloadConfig(PWM_TIM, ENABLE); //使能TIMx在ARR上的预装载寄存器
	TIM_Cmd(PWM_TIM, ENABLE);  //使能TIM
#endif
}


#ifdef USE_PWM_CH1 || USE_PWM_CH2 ||USE_PWM_CH3 ||USE_PWM_CH4

void PWM_Init_Default()
{
	PWM_Init(PWM_ARR,PWM_PSC);
}

#ifdef USE_PWM_CH1
/**
* @Description: 设定CH1占空比
* @param Duty_Cycle - 占空比   
*/ 
void Set_PWM_CH1_Duty_Cycle(int Duty_Cycle)
{
	if(Duty_Cycle>1 && Duty_Cycle<=100)
	{
		TIM_SetCompare1(PWM_TIM,720*(100-Duty_Cycle)/100);	
	}
}
#endif

#ifdef USE_PWM_CH2
/**
* @Description: 设定CH2占空比
* @param Duty_Cycle - 占空比   
*/ 
void Set_PWM_CH2_Duty_Cycle(int Duty_Cycle)
{
	if(Duty_Cycle>1 && Duty_Cycle<=100)
	{
		TIM_SetCompare2(PWM_TIM,720*(100-Duty_Cycle)/100);	
	}
}
#endif

#ifdef USE_PWM_CH3
/**
* @Description: 设定CH3占空比
* @param Duty_Cycle - 占空比   
*/ 
void Set_PWM_CH3_Duty_Cycle(int Duty_Cycle)
{
	if(Duty_Cycle>1 && Duty_Cycle<=100)
	{
		TIM_SetCompare3(PWM_TIM,720*(100-Duty_Cycle)/100);	
	}
}
#endif

#ifdef USE_PWM_CH4
/**
* @Description: 设定CH4占空比
* @param Duty_Cycle - 占空比   
*/ 
void Set_PWM_CH4_Duty_Cycle(int Duty_Cycle)
{
	if(Duty_Cycle>1 && Duty_Cycle<=100)
	{
		TIM_SetCompare4(PWM_TIM,720*(100-Duty_Cycle)/100);	
	}
}
#endif


#endif
