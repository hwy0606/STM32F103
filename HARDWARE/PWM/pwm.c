#include "pwm.h"
#include "project_config.h"
//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//��·PWM��� 
//���� TIM4 ͨ�ö�ʱ�� CH3-PB8 CH4-PB9
//������
//HWY 2018 09 11
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
/**
* @Description: PWM�����ʼ��
* @param arr���Զ���װֵ
         psc��ʱ��Ԥ��Ƶ��  
*/ 

void PWM_Init(u16 arr,u16 psc)
{ 
  GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
#ifdef USE_PWM_CH3
	                                                                    	
	GPIO_InitStructure.GPIO_Pin = PWM_CH3_GPIO; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PWM_GPIO, &GPIO_InitStructure);	
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	 80K
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  ����Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(PWM_TIM, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse = 0; //���ô�װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
	TIM_OC3Init(PWM_TIM, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
  TIM_CtrlPWMOutputs(PWM_TIM,ENABLE);	//MOE �����ʹ��	
	TIM_OC3PreloadConfig(PWM_TIM, TIM_OCPreload_Enable);  	 
	TIM_ARRPreloadConfig(PWM_TIM, ENABLE); //ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���
	TIM_Cmd(PWM_TIM, ENABLE);  //ʹ��TIM
#endif
//CH4ͨ����ʼ��
#ifdef USE_PWM_CH4                                                                   	
	GPIO_InitStructure.GPIO_Pin = PWM_CH4_GPIO; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PWM_GPIO, &GPIO_InitStructure);	
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	 80K
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  ����Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(PWM_TIM, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse = 0; //���ô�װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
	TIM_OC4Init(PWM_TIM, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
  TIM_CtrlPWMOutputs(PWM_TIM,ENABLE);	//MOE �����ʹ��	
	TIM_OC4PreloadConfig(PWM_TIM, TIM_OCPreload_Enable);  	 
	TIM_ARRPreloadConfig(PWM_TIM, ENABLE); //ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���
	TIM_Cmd(PWM_TIM, ENABLE);  //ʹ��TIM
#endif
}

/*��֧��C99��׼ */
#if defined (USE_PWM_CH3) || defined (USE_PWM_CH4)

void PWM_Init_Default()
{
	PWM_Init(PWM_ARR,PWM_PSC);
}


#ifdef USE_PWM_CH3
/**
* @Description: �趨CH3ռ�ձ�
* @param Duty_Cycle - ռ�ձ�   
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
* @Description: �趨CH4ռ�ձ�
* @param Duty_Cycle - ռ�ձ�   
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
