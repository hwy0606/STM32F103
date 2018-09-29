//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//UART���ͺͽ���
//����DMA��ԭ����UART5û��DMAͨ��
//�ļ��� ��Ϊ uart5
//���� PC12 TX PD2 RX
//������
//HWY 2017 10 18
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 
#include "usart5_dma.h"
#include "sys.h" 
#include <string.h> 	  
#include "project_config.h"
#include "stm32f10x_usart.h"
#include "usart5_protocol.h"
/*private*/
static u8 UART5_SEND_DATA[USART5_DATA_LEN];  
static u8 UART5_RECEIVE_DATA[USART5_DATA_LEN]; 
 u8 SPO2_DATA[SPO2_DATA_LEN];
 u8 SPO2_FLAG=0; //0-δ���� 1-����
/**
* @Description: uart5_��ʼ��
* @param baud - ���ڲ�����.    
*/ 
#ifdef USE_USART5_DMA
void UART5_Init(u32 baud) 
{  
  
    NVIC_InitTypeDef NVIC_InitStructure ;  	   		//�����жϽṹ��        
    GPIO_InitTypeDef GPIO_InitStructure;  			//����IO��ʼ���ṹ��       
    USART_InitTypeDef USART_InitStructure;    		//���崮�ڽṹ��    
    /* USART5 Tx��GPIO����Ϊ���츴��ģʽ */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;       //�ܽ�ģʽ:�����              //������������    
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //IO���ٶ�       
    GPIO_InitStructure.GPIO_Pin = USART5_GPIO_TX;  		   //�ܽ�ָ��     
    GPIO_Init(USART5_TX_GPIO, &GPIO_InitStructure);  		   //��ʼ�� 
      
    /* ��USART5 Rx��GPIO����Ϊ��������ģʽ  */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;       //�ܽ�ģʽ:�����     
 	  GPIO_InitStructure.GPIO_Pin = USART5_GPIO_RX;  	   //�ܽ�ָ��     
    GPIO_Init(USART5_RX_GPIO, &GPIO_InitStructure);  		   //��ʼ��  
    /* ��ʼ�����ڲ��� */   
    USART_InitStructure.USART_BaudRate = baud;  
	  USART_InitStructure.USART_WordLength = USART_WordLength_8b;    
    USART_InitStructure.USART_StopBits = USART_StopBits_1;    
    USART_InitStructure.USART_Parity = USART_Parity_No;    
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;    
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;               
    USART_Init(UART5,&USART_InitStructure);    				  //��ʼ������       
    /* �����ж����� */  
		/* �����ж����� �� �����ж����� */
    USART_ITConfig(UART5,USART_IT_TC,DISABLE);  
    USART_ITConfig(UART5,USART_IT_RXNE,ENABLE);  
    USART_ITConfig(UART5,USART_IT_TXE,DISABLE);  
    USART_ITConfig(UART5,USART_IT_IDLE,ENABLE);     		  	  //�򿪿����ж� �����ж�       
    NVIC_InitStructure.NVIC_IRQChannel = UART5_IRQn;             //ͨ������Ϊ�����ж�    
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;  //�ж�ռ�ȵȼ�  
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;         //�ж���Ӧ���ȼ�   
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;               //���ж�    
    NVIC_Init(&NVIC_InitStructure);     
    /* �������� */   
    USART_Cmd(UART5, ENABLE);      
	}
/**
	* @Description:uart5���ⷢ������ ȡ�����жϱ�־λ
 * @param data - �������ݴ�ŵ�ַ
 * @param size - ���������ֽ���    
 */  
void UART5_Send_Once_Data(uint8_t *data,uint16_t size)  
{     
    /* �������� */ 
    memcpy(UART5_SEND_DATA,data,size); 
		for(u8 i=0;i<size;i++) 
		{ 
			while(USART_GetFlagStatus(UART5,USART_FLAG_TC)==RESET);   //while�ȴ���һ֡������ ���DMA�˴��˷�ʱ��
    USART_SendData(UART5,UART5_SEND_DATA[i]); 
    }  

}     
/**
 * @Description: �����жϴ�����   ����ʹ�ñ��ļ������������ڰ����ŵ�stm32f4xx_it.c��
 */ 
u8 RxCounter=0; 
void UART5_IRQHandler(void) 		   
{ 	
    /* ��������жϴ��� */ 
	if(USART_GetITStatus(UART5, USART_IT_RXNE) != RESET)
	{
		UART5_RECEIVE_DATA[RxCounter++]=UART5->DR;
	}
	
	if(USART_GetITStatus(UART5, USART_IT_IDLE) != RESET)
	{ 		 
		RxCounter=0;
		UART5->SR;
    UART5->DR; 									//��USART_IT_IDLE��־ 
		/* ������һ֡���û������� */
		//�ж���ʵʱ���ݻ���״̬���� ʵʱ�������� ״̬���ݸ��Ƶ�SP02������
		if(Is_State_Date(&UART5_RECEIVE_DATA[0]))
		{	
			//�����״̬���� ��USART3_RECEIVE_DATA���鸴�Ƶ�SPO2������ ֻ����������Ϣ �˴�δ����У��� ���ڿ�����
				SPO2_DATA[3]=UART5_RECEIVE_DATA[6];//��Ч���ݵ�һλ SPO2������ 
	      SPO2_DATA[4]=UART5_RECEIVE_DATA[7];//��Ч���ݵڶ�λ ��עָ����8λ 
	      SPO2_DATA[5]=UART5_RECEIVE_DATA[8];//��Ч���ݵ���λ ��עָ����8λ 
				SPO2_DATA[6]=UART5_RECEIVE_DATA[11];//��Ч���ݵ���λ ״̬���� 
				SPO2_DATA[7]=UART5_RECEIVE_DATA[13];//��Ч���ݵ���λ SQI�ź����� 
			  SPO2_FLAG=1; //���µȴ�����
		}
		
	}  
}  
 
#endif
/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/






