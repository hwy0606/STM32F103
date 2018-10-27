//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//系统外设时钟初始化
//驱动层
//HWY 2018 09 28
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	
#include "sys.h" 
#include "rcc.h"
#include "project_config.h"

void RCC_Init()
{
	/*串口接口*/
	#ifdef USE_USART1_DMA
	RCC_APB2PeriphClockCmd(USART1_GPIO_RCC, ENABLE);  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);  	  //打开串口对应的外设时钟
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);  		//启动DMA时钟 
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);  
	#endif
	
	#ifdef USE_USART2_DMA
	RCC_APB2PeriphClockCmd(USART2_GPIO_RCC, ENABLE); 
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);  	  //打开串口对应的外设时钟
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);  		//启动DMA时钟  	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE); 
	#endif
	
	#ifdef USE_USART3_DMA
	RCC_APB2PeriphClockCmd(USART3_GPIO_RCC, ENABLE);  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);  	  //打开串口对应的外设时钟 
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);  		//启动DMA时钟 
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);  
	#endif
	
	#ifdef USE_USART5_DMA
	RCC_APB2PeriphClockCmd(USART5_GPIO_RCC, ENABLE);  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART5, ENABLE);  	  //打开串口对应的外设时钟 
	#endif
	
	/*霍尔传感器接口 */
	#ifdef USE_PC0_HALL_IPD
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//开启GPIOA时钟
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//外部中断，需要使能AFIO时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);  			//使能TIM2时钟
	#endif
	
	/*PWM输出接口*/
	#ifdef USE_PWM_CH3
	RCC_APB1PeriphClockCmd(PWM_TIM_RCC, ENABLE);
 	RCC_APB2PeriphClockCmd(PWM_GPIO_RCC|PWM_AFIO_RCC,ENABLE);  //使能GPIO外设时钟使能 
	#endif
	#ifdef USE_PWM_CH4
	RCC_APB1PeriphClockCmd(PWM_TIM_RCC, ENABLE);
 	RCC_APB2PeriphClockCmd(PWM_GPIO_RCC|PWM_AFIO_RCC,ENABLE);  //使能GPIO外设时钟使能  
	#endif
	
	/*按键接口*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC,ENABLE);// GPIOB GPIOC 时钟
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//外部中断，需要使能AFIO时钟
	
	/*GPIO OUTPUT*/	
	#ifdef USE_INTERNET_GPIO
	RCC_APB2PeriphClockCmd(INTERNET_GPIO_RCC,ENABLE);	 //使能PA端口时钟
	#endif
	
	#ifdef USE_BP_GPIO
	RCC_APB2PeriphClockCmd(BP_GPIO_RCC,ENABLE);	 //使能PA端口时钟
	#endif
	
	#ifdef USE_SPO2_GPIO
	RCC_APB2PeriphClockCmd(SPO2_GPIO_RCC,ENABLE);	 //使能PA端口时钟
	#endif
	
	#ifdef USE_BACKUP_GPIO
  RCC_APB2PeriphClockCmd(BACKUP_GPIO_RCC,ENABLE);	 //使能PA PB端口时钟
  #endif
	
	#ifdef USE_MOTOR_GPIO
	RCC_APB2PeriphClockCmd(MOTOR_GPIO_RCC,ENABLE);	 //使能PA PB端口时钟
  #endif
	
  #ifdef USE_MOTOR_GPIO
  RCC_APB2PeriphClockCmd(LED_GPIO_RCC,ENABLE);	 //使能PB端口时钟
	#endif
	
	#ifdef USE_ACTUATOR_GPIO
	RCC_APB2PeriphClockCmd(ACTUATOR_GPIO_RCC,ENABLE);	 //使能PB端口时钟
	#endif
	
	#ifdef USE_OE_GPIO
	RCC_APB2PeriphClockCmd(OE_GPIO_RCC,ENABLE);	 //使能PC端口时钟
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
	
	/* 任务更新 TIM3 */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	#endif
}	
	
