//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//Hall_Sensor�������� 
//���� PC0
//����ٶȴ洢��float�ͱ���motor_speed��
//HWY 2017 10 19
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 
#include "stm32f10x.h"
#include "encoder.h" 
#include "math.h"		
#include "project_config.h"

//ʹ��T�������ٶ� 
//ͨ���������ټ�������������������������֮���ʱ����ȷ�������ٶ�
static u32 count_now;//��������ǰֵ
static u32 count_last;//��������һ�ν��жϼ���ֵ
static u32 count_diff;//��������ֵ
float motor_speed=0.0;//���ת��

void PC0_Hall_IPD_Init(void)
{	
	#ifdef USE_PC0_HALL_IPD
	GPIO_InitTypeDef  GPIO_InitStructure;
	NVIC_InitTypeDef  NVIC_InitStructure;
	EXTI_InitTypeDef  EXTI_InitStructure;

	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;//��������ģʽ 
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource0);
  EXTI_InitStructure.EXTI_Line=EXTI_Line0;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);		//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;			//ʹ���ⲿ�ж�ͨ��
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = PC0_HALL_PreemptionPriority;	//��ռ���ȼ�2 
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = PC0_HALL_SubPriority;					//�����ȼ�1
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
  NVIC_Init(&NVIC_InitStructure);  	  //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���
	#endif
}


#ifdef USE_PC0_HALL_IPD
void EXTI0_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line0)!=RESET)
	{	  
		//���û���������
		 count_now= TIM_GetCounter(TIM2);	 //ȡ��ǰʱ��  CNT�Ĵ���ֵ
		if(count_now>count_last) //����һ������ 
	   {
		 count_diff=count_now-count_last;
		 }
    else
			{
		count_diff=count_now+65534-count_last; //0xFFFE
		  }  

	   motor_speed=HALL_SPEED_CONST/(float)(count_diff);            //��λ n/min
	   count_last=count_now;

	}
	EXTI_ClearITPendingBit(EXTI_Line0);  //���EXTI0��·����λ
}
#endif


/**
 * @Description: TIM2����ģʽ��ʼ��
 * @note1�� TIM2��16λ��ʱ�����ɼ�����65535
 * @note2�� 65535  
PS:STM32F4 ��Ӧ��TIM2��32λ������ 
 */
void Timer2_Init(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    TIM_TimeBaseInitStructure.TIM_Period = 0xFFFF; 				//�Զ���װ��ֵ  65535
    TIM_TimeBaseInitStructure.TIM_Prescaler=7200-1;  					//��ʱ����Ƶ  ��С�ֱ��������ʱʱ��           
    TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; 	//���ϼ���ģʽ
    TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 		//
    TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);				//��ʼ��TIM
    TIM_ITConfig(TIM2,TIM_IT_Update,DISABLE); 						//��ֹ��ʱ�������ж�
    TIM_Cmd(TIM2,ENABLE); 											//ʹ�ܶ�ʱ��	
}

//Hall_Sensor��ʼ��
void Hall_Senor_Init(void)
{
	PC0_Hall_IPD_Init();
	Timer2_Init();	
}
