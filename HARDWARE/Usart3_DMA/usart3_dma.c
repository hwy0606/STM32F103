//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//USART+DMA���ͺͽ���
//���� PA2 TX PA3 RX
//������
//HWY 2017 10 18
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 
#include "usart3_dma.h"
#include "sys.h" 
#include <string.h> 	  
#include "delay.h"
#include "project_config.h"
/* UART GPIO define. */
#define USART3_GPIO_TX       		   GPIO_Pin_10
#define USART3_GPIO_RX       		   GPIO_Pin_11
#define USART3_GPIO_TX_PinSource   GPIO_PinSource10
#define USART3_GPIO_RX_PinSource   GPIO_PinSource11
#define USART3_GPIO          		   GPIOB
#define USART3_GPIO_RCC      		   RCC_APB2Periph_GPIOB
#define USART3_DATA_LEN  64  //���պͷ������ݵ���󳤶�
/*private*/
u8 USART3_SEND_DATA[USART3_DATA_LEN];  
u8 USART3_RECEIVE_DATA[USART3_DATA_LEN]; 
u8 USART3_TX_BUSY=0; //0������ 1:���ڷ���
/*public*/
struct uart3_buffer uart3_rx,uart3_tx;
	  

/**
* @Description: UART3_DMA��ʼ��
* @param baud - ���ڲ�����.    
*/ 
#ifdef USE_USART3_DMA
void USART3_DMA_Init(u32 baud) 
{  
  
    NVIC_InitTypeDef NVIC_InitStructure ;  	   		//�����жϽṹ��        
    GPIO_InitTypeDef GPIO_InitStructure;  			//����IO��ʼ���ṹ��       
    USART_InitTypeDef USART_InitStructure;    		//���崮�ڽṹ��    
    DMA_InitTypeDef DMA_InitStructure;  	   		//����DMA�ṹ��  
  
/* ��1��������IO���� */       
    RCC_APB2PeriphClockCmd(USART3_GPIO_RCC, ENABLE);   
 
  
    /* USART3 Tx��GPIO����Ϊ���츴��ģʽ */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;       //�ܽ�ģʽ:�����              //������������    
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //IO���ٶ�       
    GPIO_InitStructure.GPIO_Pin = USART3_GPIO_TX;  		   //�ܽ�ָ��     
    GPIO_Init(USART3_GPIO, &GPIO_InitStructure);  		   //��ʼ�� 
      
    /* ��USART3 Rx��GPIO����Ϊ��������ģʽ  */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;       //�ܽ�ģʽ:�����     
 	  GPIO_InitStructure.GPIO_Pin = USART3_GPIO_RX;  	   //�ܽ�ָ��     
    GPIO_Init(USART3_GPIO, &GPIO_InitStructure);  		   //��ʼ��

/* ��2�����������ڲ������� */   

      
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);  	  //�򿪴��ڶ�Ӧ������ʱ��  
    /* ��ʼ�����ڲ��� */   
    USART_InitStructure.USART_BaudRate = baud;  
	  USART_InitStructure.USART_WordLength = USART_WordLength_8b;    
    USART_InitStructure.USART_StopBits = USART_StopBits_1;    
    USART_InitStructure.USART_Parity = USART_Parity_No;    
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;    
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;               
    USART_Init(USART3,&USART_InitStructure);    				  //��ʼ������  
      
    /* �����ж����� */  
    USART_ITConfig(USART3,USART_IT_TC,DISABLE);  
    USART_ITConfig(USART3,USART_IT_RXNE,DISABLE);  
    USART_ITConfig(USART3,USART_IT_TXE,DISABLE);  
    USART_ITConfig(USART3,USART_IT_IDLE,ENABLE);     		  	  //�򿪿����ж�
       
    NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;             //ͨ������Ϊ�����ж�    
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;  //�ж�ռ�ȵȼ�  
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;         //�ж���Ӧ���ȼ�   
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;               //���ж�    
    NVIC_Init(&NVIC_InitStructure);     
          
    /* Enable USART3 DMA Rx Tx request */
    USART_DMACmd(USART3,USART_DMAReq_Tx,ENABLE);  
    USART_DMACmd(USART3,USART_DMAReq_Rx,ENABLE);  
    
    /* �������� */   
    USART_Cmd(USART3, ENABLE);      
//	  USART_HalfDuplexCmd(USART3, ENABLE);//ʹ�ܻ���ʧ��USART��˫��ģʽ
	
    /* ��3�������ڷ���DMA���� */ 	 
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);  		//����DMAʱ�� 
    /* DMA�����ж����� */ 
    NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel2_IRQn;  		
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  		
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;  			
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  				
    NVIC_Init(&NVIC_InitStructure);  								
     
    DMA_DeInit(DMA1_Channel2);  									//DMAͨ������   				   
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&USART3->DR); //�����ַ      
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)USART3_SEND_DATA; //�ڴ��ַ     
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;  			//dma���䷽��     
    DMA_InitStructure.DMA_BufferSize = USART3_DATA_LEN;  				//����DMA�ڴ���ʱ�������ĳ���     
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;  	//����DMA���������ģʽ��һ������      
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;  			//����DMA���ڴ����ģʽ     
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte; //���������ֳ�      
    DMA_InitStructure.DMA_MemoryDataSize = DMA_PeripheralDataSize_Byte; //�ڴ������ֳ�      
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;  						//����DMA�Ĵ���ģʽ    
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;  				//����DMA�����ȼ���          
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;      
    DMA_Init(DMA1_Channel2, &DMA_InitStructure);    						//����DMA2��ͨ��      
    DMA_ITConfig(DMA1_Channel2,DMA_IT_TC,ENABLE);     					//ʹ���ж� 

/* ��3�������ڽ���DMA���� */     
     																    //����DMAʱ��
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);  
     
    DMA_DeInit(DMA1_Channel3);   					 //DMAͨ������     
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&USART3->DR);  //�����ַ      
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)USART3_RECEIVE_DATA;//�ڴ��ַ      
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;  			 //dma���䷽��    
    DMA_InitStructure.DMA_BufferSize = USART3_DATA_LEN;  				 //����DMA�ڴ���ʱ�������ĳ���   
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;  	 //����DMA���������ģʽ��һ������    
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;  			 //����DMA���ڴ����ģʽ    
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte; //���������ֳ�       
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;  	 //�ڴ������ֳ�     
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;  						 //����DMA�Ĵ���ģʽ  
    DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;  			 //����DMA�����ȼ���         
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;            
    DMA_Init(DMA1_Channel3, &DMA_InitStructure);    						 //����DMA2��ͨ��  
    
    DMA_Cmd(DMA1_Channel3,ENABLE);  										 //ʹ��ͨ��  
} 

/**
 * @Description:UART3_DMA���ⷢ������
 * @param data - �������ݴ�ŵ�ַ
 * @param size - ���������ֽ���    
 */  
void USART3_DMA_Send_Once_Data(uint8_t *data,uint16_t size)  
{  
    /* �ȴ����� */ 
    while (USART3_TX_BUSY);  
    USART3_TX_BUSY = 1;  
    /* �������� */ 
    memcpy(USART3_SEND_DATA,data,size);
	  /* �ı�datasizeǰ��Ҫ��ֹͨ������ */ 
	  DMA_Cmd(DMA1_Channel2,DISABLE);  
    /* ���ô������ݳ���  */
    DMA_SetCurrDataCounter(DMA1_Channel2,size);  
    /* ��DMA,��ʼ���� */ 
    DMA_Cmd(DMA1_Channel2,ENABLE);  
}  

  
/**
* @Description:���ڴ����������ж� 
* @param  buf - ���յ����� 
* @return len - ���յ����ݳ���   
*/   
uint8_t USART3_RX_Finish_IRQ(uint8_t *buf)
{
    uint16_t len = 0;

    USART3->SR;
    USART3->DR; 									//��USART_IT_IDLE��־   
    DMA_Cmd(DMA1_Channel3, DISABLE);				    //�ر�DMA   
    DMA_ClearFlag(DMA1_FLAG_TC3);	//�����־λ

    /* ��ý���֡֡�� */
    len = USART3_DATA_LEN - DMA_GetCurrDataCounter(DMA1_Channel3);
    memcpy(buf, USART3_RECEIVE_DATA, len);
    /* ���ô������ݳ��� */
    DMA_SetCurrDataCounter(DMA1_Channel3, USART3_DATA_LEN);
    /* ��DMA */
    DMA_Cmd(DMA1_Channel3, ENABLE);
    return len;

}

/**
 * @Description: USARTʹ��DMA�������жϷ������ 
 */
void DMA1_Channel2_IRQHandler(void) 	  
{  
    if(DMA_GetITStatus(DMA1_IT_TC2) != RESET)   
    {  
        /* �����־λ */ 
        DMA_ClearFlag(DMA1_FLAG_TC2);  
        /* �ر�DMA */ 
        DMA_Cmd(DMA1_Channel2,DISABLE);  
        /* �򿪷�������ж�,������������ֽ� */ 
        USART_ITConfig(USART3,USART_IT_TC,ENABLE);  
    }  
}  
     
/**
 * @Description: �����жϴ�����   ����ʹ�ñ��ļ������������ڰ����ŵ�stm32f4xx_it.c��
 */ 
void USART3_IRQHandler(void) 		   
{  
      
    /* ��������жϴ��� */ 
    if(USART_GetITStatus(USART3, USART_IT_TC)!= RESET)  
    {  
        /* �رշ�������ж� */ 
        USART_ITConfig(USART3,USART_IT_TC,DISABLE);  
        /* ������� */ 
        USART3_TX_BUSY = 0; 			
    }   
      
    /* ��������жϴ��� */ 
	if(USART_GetITStatus(USART3, USART_IT_IDLE) != RESET)
	{ 
    	uart3_rx.len = USART3_RX_Finish_IRQ(uart3_rx.buf);	 
	}  
}  
 
#endif
/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/






