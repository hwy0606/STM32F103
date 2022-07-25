#include "led.h"

//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//LED����
//���� LED0-PA8 LED1-PD2  
//�������� LED0-PC0 LED1-PC1
//������+Ӳ����
//HWY 2017 10 18
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	    

	    
//LED IO��ʼ��
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOD, ENABLE);	 //ʹ��PB,PE�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;				 //LED0-->PB.5 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOB.5
 GPIO_SetBits(GPIOA,GPIO_Pin_8);						 //PB.5 �����

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;	    		 //LED1-->PE.5 �˿�����, �������
 GPIO_Init(GPIOD, &GPIO_InitStructure);	  				 //������� ��IO���ٶ�Ϊ50MHz
 GPIO_SetBits(GPIOD,GPIO_Pin_2); 						 //PE.5 ����� 
}
 