//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//ϵͳ����ʱ�ӳ�ʼ��
//������
//HWY 2018 09 28
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	
#include "sys.h" 
#include "rcc.h"
#include "project_config.h"

void RCC_Init()
{
	/*���ڽӿ�*/
	#ifdef USE_USART1_DMA
	RCC_APB2PeriphClockCmd(USART1_GPIO_RCC, ENABLE);  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);  	  //�򿪴��ڶ�Ӧ������ʱ��
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);  		//����DMAʱ�� 
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);  
	#endif
	
	#ifdef USE_USART2_DMA
	RCC_APB2PeriphClockCmd(USART2_GPIO_RCC, ENABLE); 
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);  	  //�򿪴��ڶ�Ӧ������ʱ��
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);  		//����DMAʱ��  	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE); 
	#endif
	
	#ifdef USE_USART3_DMA
	RCC_APB2PeriphClockCmd(USART3_GPIO_RCC, ENABLE);  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);  	  //�򿪴��ڶ�Ӧ������ʱ�� 
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);  		//����DMAʱ�� 
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);  
	#endif
	
	#ifdef USE_USART5_DMA
	RCC_APB2PeriphClockCmd(USART5_GPIO_RCC, ENABLE);  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART5, ENABLE);  	  //�򿪴��ڶ�Ӧ������ʱ�� 
	#endif
	
	/*�����������ӿ� */
	#ifdef USE_PC0_HALL_IPD
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//����GPIOAʱ��
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//�ⲿ�жϣ���Ҫʹ��AFIOʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);  			//ʹ��TIM2ʱ��
	#endif
	
	/*PWM����ӿ�*/
	#ifdef USE_PWM_CH3
	RCC_APB1PeriphClockCmd(PWM_TIM_RCC, ENABLE);
 	RCC_APB2PeriphClockCmd(PWM_GPIO_RCC|PWM_AFIO_RCC,ENABLE);  //ʹ��GPIO����ʱ��ʹ�� 
	#endif
	#ifdef USE_PWM_CH4
	RCC_APB1PeriphClockCmd(PWM_TIM_RCC, ENABLE);
 	RCC_APB2PeriphClockCmd(PWM_GPIO_RCC|PWM_AFIO_RCC,ENABLE);  //ʹ��GPIO����ʱ��ʹ��  
	#endif
	
	/*�����ӿ�*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC,ENABLE);// GPIOB GPIOC ʱ��
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//�ⲿ�жϣ���Ҫʹ��AFIOʱ��
	
	/*GPIO OUTPUT*/	
	#ifdef USE_INTERNET_GPIO
	RCC_APB2PeriphClockCmd(INTERNET_GPIO_RCC,ENABLE);	 //ʹ��PA�˿�ʱ��
	#endif
	
	#ifdef USE_BP_GPIO
	RCC_APB2PeriphClockCmd(BP_GPIO_RCC,ENABLE);	 //ʹ��PA�˿�ʱ��
	#endif
	
	#ifdef USE_SPO2_GPIO
	RCC_APB2PeriphClockCmd(SPO2_GPIO_RCC,ENABLE);	 //ʹ��PA�˿�ʱ��
	#endif
	
	#ifdef USE_BACKUP_GPIO
  RCC_APB2PeriphClockCmd(BACKUP_GPIO_RCC,ENABLE);	 //ʹ��PA PB�˿�ʱ��
  #endif
	
	#ifdef USE_MOTOR_GPIO
	RCC_APB2PeriphClockCmd(MOTOR_GPIO_RCC,ENABLE);	 //ʹ��PA PB�˿�ʱ��
  #endif
	
  #ifdef USE_MOTOR_GPIO
  RCC_APB2PeriphClockCmd(LED_GPIO_RCC,ENABLE);	 //ʹ��PB�˿�ʱ��
	#endif
	
	#ifdef USE_ACTUATOR_GPIO
	RCC_APB2PeriphClockCmd(ACTUATOR_GPIO_RCC,ENABLE);	 //ʹ��PB�˿�ʱ��
	#endif
	
	#ifdef USE_OE_GPIO
	RCC_APB2PeriphClockCmd(OE_GPIO_RCC,ENABLE);	 //ʹ��PC�˿�ʱ��
	#endif
	
	
	/* ADC PA0 */
	#ifdef USE_PA0_ADC1_IN0
	RCC_APB2PeriphClockCmd(ADC_RCC, ENABLE);   		
	RCC_AHBPeriphClockCmd(DMA_RCC,ENABLE);
	#endif
	
	
	/* SPI */
	#ifdef USE_SPI_7277
	RCC_APB2PeriphClockCmd(SPI_GPIO_RCC,ENABLE );	
	RCC_APB1PeriphClockCmd(SPI_RCC,ENABLE );	
	
	/* ������� TIM3 */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	#endif
}	
	
