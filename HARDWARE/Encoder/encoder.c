//////////////////////////////////////////////////////////////////////////////////	 
//STM32F407IGT6
//�������������� ŷķ��E6B2-CWZ6C �������� 1000��
//���� ��ɫA-PA6 ��ɫB-PA7 ��ɫZ-PC4
//����ٶȴ洢��float�ͱ���motor_speed��
//HWY 2017 10 19
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 
#include "stm32f4xx.h"
#include "encoder.h" 
#include "math.h"			
#define ENCODER_GPIO_PINA       GPIO_Pin_6
#define ENCODER_GPIO_PINB       GPIO_Pin_7
#define ENCODER_GPIO_PinSourceA GPIO_PinSource6
#define ENCODER_GPIO_PinSourceB GPIO_PinSource7
#define ENCODER_GPIO_RCC      	RCC_AHB1Periph_GPIOA
#define ENCODER_GPIO          	GPIOA
#define ENCODER_GPIO_AF_TIM		  GPIO_AF_TIM3

#define ENCODER_TIM  			  TIM3
#define ENCODER_TIM_RCC  		RCC_APB1Periph_TIM3
#define	ENCODER_TIM_IRQ			TIM3_IRQn

#define	ENCODER_PLUSES			1000

 u32 count_now;//��������ǰֵ
 u32 count_last;//��������һ�ν��жϼ���ֵ
 u32 count_diff;//��������ֵ
float motor_speed;//���ת��
void Timer3_Init(void)
{	
    GPIO_InitTypeDef         GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_ICInitTypeDef        TIM_ICInitStructure;
    NVIC_InitTypeDef         NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(ENCODER_TIM_RCC,ENABLE);								//����TIMxʱ��
    RCC_AHB1PeriphClockCmd(ENCODER_GPIO_RCC ,ENABLE);							//����GPIOʱ��

    GPIO_PinAFConfig(ENCODER_GPIO,ENCODER_GPIO_PinSourceA,ENCODER_GPIO_AF_TIM);	//PA6���Ÿ���
    GPIO_PinAFConfig(ENCODER_GPIO,ENCODER_GPIO_PinSourceB,ENCODER_GPIO_AF_TIM);	//PA7���ŷ���

	  //GPIO��������
    GPIO_InitStructure.GPIO_Pin = ENCODER_GPIO_PINA|ENCODER_GPIO_PINB;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP ;
    GPIO_Init(ENCODER_GPIO,&GPIO_InitStructure);
 
    //NVIC��������
    NVIC_InitStructure.NVIC_IRQChannel=ENCODER_TIM_IRQ; 		//��ʱ���ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3; 	//��ռ���ȼ�2
    NVIC_InitStructure.NVIC_IRQChannelSubPriority=3; 		//�����ȼ�2
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
    NVIC_Init(&NVIC_InitStructure);


    //TIMBaseStructure����
    TIM_TimeBaseStructure.TIM_Period = 4*ENCODER_PLUSES-1;    	//������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ   4��������
    TIM_TimeBaseStructure.TIM_Prescaler = 0; 					//����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  ����Ƶ
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; 	//����ʱ�ӷָ�:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //TIM���ϼ���ģʽ
    TIM_TimeBaseInit(ENCODER_TIM, &TIM_TimeBaseStructure);

    TIM_EncoderInterfaceConfig(ENCODER_TIM, TIM_EncoderMode_TI12,TIM_ICPolarity_BothEdge,TIM_ICPolarity_BothEdge);   //bothedge�����½���������һ���������ʹ�����
    
	  TIM_ICStructInit(&TIM_ICInitStructure);				        //����TIM_Channel = TIM_Channel_1;
    TIM_ICInitStructure.TIM_ICFilter = (u8) 6;  				//����TIM_Channel_1�����˲���	   ������˲���6/42M= 142ns
    TIM_ICInit(ENCODER_TIM, &TIM_ICInitStructure);
    
	  TIM_ICInitStructure.TIM_Channel = TIM_Channel_2;			//����TIM_Channel = TIM_Channel_2;
    TIM_ICInit(ENCODER_TIM, &TIM_ICInitStructure);		        //����TIM_Channel_2�����˲���
	
	  TIM_ClearFlag(ENCODER_TIM, TIM_FLAG_Update);  				//������б�־λ
    TIM_ITConfig(ENCODER_TIM, TIM_IT_Update, ENABLE); 			//��������жϸ���

	  TIM_ClearFlag(ENCODER_TIM,TIM_IT_CC1);					    //������벶��1�жϱ�־λ
    TIM_ITConfig(ENCODER_TIM, TIM_IT_CC1, ENABLE); 			    //����ͨ��1�����ж� ,
	  TIM_ClearFlag(ENCODER_TIM,TIM_IT_CC2);					    //������벶��2�жϱ�־λ
    TIM_ITConfig(ENCODER_TIM, TIM_IT_CC2, ENABLE); 			    //����ͨ��2�����ж� 
		
		//Reset counter
    ENCODER_TIM->CNT = 0;

    TIM_Cmd(ENCODER_TIM, ENABLE);  								//ʹ��TIM
}




/**
 * @Description: TIM2����ģʽ��ʼ��
 * @note1�� TIM2��32λ��ʱ�����ɼ�����4294967295
 * @note2�� 4294967295@21MHz������ʱ204.5s
 */
void Timer2_Init(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);  			//ʹ��TIMʱ��
    TIM_TimeBaseInitStructure.TIM_Period = 0xFFFFFFFE; 				//�Զ���װ��ֵ  4294967294+1
    TIM_TimeBaseInitStructure.TIM_Prescaler=4-1;  					//��ʱ����Ƶ            
    TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; 	//���ϼ���ģʽ
    TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 		//
    TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);				//��ʼ��TIM
    TIM_ITConfig(TIM2,TIM_IT_Update,DISABLE); 						//��ֹ��ʱ�������ж�
    TIM_Cmd(TIM2,ENABLE); 											//ʹ�ܶ�ʱ��
}




void Get_Motor_Speed(void)   //��ȡ����ٶȺ���,���ٶ�д��float��motor_speed����
{
	if(count_now>count_last) //��������
	{count_diff=count_now-count_last;}

   else{count_diff=count_now+4294967294.0-count_last;}  //0xFFFFFFFE

	 motor_speed=1260000000.0/(float)(count_diff);            //��λ n/min
	 count_last=count_now;
}
/**
 * @Description: �������жϺ���           �����ж�
 */


void TIM3_IRQHandler(void)
{
    /* enter interrupt */
	  count_now= TIM2->CNT;	 //ȡ��ǰʱ��
   if(TIM_GetITStatus (ENCODER_TIM,TIM_IT_Update)!=RESET)//���ж�
	 {
		 Get_Motor_Speed();
		 TIM_ClearITPendingBit (ENCODER_TIM,TIM_IT_Update );//����жϱ�־λ	 
	 }	 
}

void Encoder_Init()
{
	Timer2_Init();
	Timer3_Init();
}




		



