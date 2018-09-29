//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//USART+DMA���ͺͽ���
//���� PA2 TX PA3 RX
//������
//HWY 2017 10 18
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 
#include "usart2_dma.h"
#include "sys.h" 
#include <string.h> 	  
#include "delay.h"
#include "project_config.h"
#include "usart1_protocol.h"
#include "usart2_protocol.h"
#include "usart3_protocol.h"
#include "usart5_protocol.h"
/*private*/
static u8 USART2_SEND_DATA[USART2_DATA_LEN];  
static u8 USART2_RECEIVE_DATA[USART2_DATA_LEN]; 
static u8 USART2_TX_BUSY=0; //0������ 1:���ڷ���
/*public*/
struct uart2_buffer uart2_rx,uart2_tx;
	  

/**
* @Description: UART2_DMA��ʼ��
* @param baud - ���ڲ�����.    
*/ 
#ifdef USE_USART2_DMA
void USART2_DMA_Init(u32 baud) 
{  
  
    NVIC_InitTypeDef NVIC_InitStructure ;  	   		//�����жϽṹ��        
    GPIO_InitTypeDef GPIO_InitStructure;  			//����IO��ʼ���ṹ��       
    USART_InitTypeDef USART_InitStructure;    		//���崮�ڽṹ��    
    DMA_InitTypeDef DMA_InitStructure;  	   		//����DMA�ṹ��  
  
/* ��1��������IO���� */       
    
 
  
    /* USART Tx��GPIO����Ϊ���츴��ģʽ */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;       //�ܽ�ģʽ:�����              //������������    
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //IO���ٶ�       
    GPIO_InitStructure.GPIO_Pin = USART2_GPIO_TX;  		   //�ܽ�ָ��     
    GPIO_Init(USART2_GPIO, &GPIO_InitStructure);  		   //��ʼ�� 
      
    /* ��USART2 Rx��GPIO����Ϊ��������ģʽ  */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;       //�ܽ�ģʽ:�����     
 	  GPIO_InitStructure.GPIO_Pin = USART2_GPIO_RX;  	   //�ܽ�ָ��     
    GPIO_Init(USART2_GPIO, &GPIO_InitStructure);  		   //��ʼ��

/* ��2�����������ڲ������� */   

      
    
    /* ��ʼ�����ڲ��� */   
    USART_InitStructure.USART_BaudRate = baud;  
	  USART_InitStructure.USART_WordLength = USART_WordLength_8b;    
    USART_InitStructure.USART_StopBits = USART_StopBits_1;    
    USART_InitStructure.USART_Parity = USART_Parity_No;    
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;    
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;               
    USART_Init(USART2,&USART_InitStructure);    				  //��ʼ������  
      
    /* �����ж����� */  
    USART_ITConfig(USART2,USART_IT_TC,DISABLE);  
    USART_ITConfig(USART2,USART_IT_RXNE,DISABLE);  
    USART_ITConfig(USART2,USART_IT_TXE,DISABLE);  
    USART_ITConfig(USART2,USART_IT_IDLE,ENABLE);     		  	  //�򿪿����ж�
       
    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;             //ͨ������Ϊ�����ж�    
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;  //�ж�ռ�ȵȼ�  
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;         //�ж���Ӧ���ȼ�   
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;               //���ж�    
    NVIC_Init(&NVIC_InitStructure);     
          
    /* Enable USART2 DMA Rx Tx request */
    USART_DMACmd(USART2,USART_DMAReq_Tx,ENABLE);  
    USART_DMACmd(USART2,USART_DMAReq_Rx,ENABLE);  
    
    /* �������� */   
    USART_Cmd(USART2, ENABLE);      
//	  USART_HalfDuplexCmd(USART2, ENABLE);//ʹ�ܻ���ʧ��USART��˫��ģʽ
	
    /* ��3�������ڷ���DMA���� */ 	 
    
    /* DMA�����ж����� */ 
    NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel7_IRQn;  		
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  		
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;  			
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  				
    NVIC_Init(&NVIC_InitStructure);  								
     
    DMA_DeInit(DMA1_Channel7);  									//DMAͨ������   				   
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&USART2->DR); //�����ַ      
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)USART2_SEND_DATA; //�ڴ��ַ     
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;  			//dma���䷽��     
    DMA_InitStructure.DMA_BufferSize = USART2_DATA_LEN;  				//����DMA�ڴ���ʱ�������ĳ���     
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;  	//����DMA���������ģʽ��һ������      
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;  			//����DMA���ڴ����ģʽ     
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte; //���������ֳ�      
    DMA_InitStructure.DMA_MemoryDataSize = DMA_PeripheralDataSize_Byte; //�ڴ������ֳ�      
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;  						//����DMA�Ĵ���ģʽ    
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;  				//����DMA�����ȼ���          
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;      
    DMA_Init(DMA1_Channel7, &DMA_InitStructure);    						//����DMA2��ͨ��      
    DMA_ITConfig(DMA1_Channel7,DMA_IT_TC,ENABLE);     					//ʹ���ж� 

/* ��3�������ڽ���DMA���� */     
     																    //����DMAʱ��
     
     
    DMA_DeInit(DMA1_Channel6);   					 //DMAͨ������     
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&USART2->DR);  //�����ַ      
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)USART2_RECEIVE_DATA;//�ڴ��ַ      
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;  			 //dma���䷽��    
    DMA_InitStructure.DMA_BufferSize = USART2_DATA_LEN;  				 //����DMA�ڴ���ʱ�������ĳ���   
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;  	 //����DMA���������ģʽ��һ������    
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;  			 //����DMA���ڴ����ģʽ    
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte; //���������ֳ�       
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;  	 //�ڴ������ֳ�     
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;  						 //����DMA�Ĵ���ģʽ  
    DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;  			 //����DMA�����ȼ���         
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;            
    DMA_Init(DMA1_Channel6, &DMA_InitStructure);    						 //����DMA2��ͨ��  
    
    DMA_Cmd(DMA1_Channel6,ENABLE);  										 //ʹ��ͨ��  
} 

/**
 * @Description:UART1_DMA���ⷢ������
 * @param data - �������ݴ�ŵ�ַ
 * @param size - ���������ֽ���    
 */  
void USART2_DMA_Send_Once_Data(uint8_t *data,uint16_t size)  
{  
    /* �ȴ����� */ 
//    while (USART2_TX_BUSY);  
//    USART2_TX_BUSY = 1;  
    /* �������� */ 
    memcpy(USART2_SEND_DATA,data,size);
	  /* �ı�datasizeǰ��Ҫ��ֹͨ������ */ 
	  DMA_Cmd(DMA1_Channel7,DISABLE);  
    /* ���ô������ݳ���  */
    DMA_SetCurrDataCounter(DMA1_Channel7,size);  
    /* ��DMA,��ʼ���� */ 
    DMA_Cmd(DMA1_Channel7,ENABLE);  
}  

  
/**
* @Description:���ڴ����������ж� 
* @param  buf - ���յ����� 
* @return len - ���յ����ݳ���   
*/   
uint8_t USART2_RX_Finish_IRQ(uint8_t *buf)
{
    uint16_t len = 0;

    USART2->SR;
    USART2->DR; 									//��USART_IT_IDLE��־   
    DMA_Cmd(DMA1_Channel6, DISABLE);				    //�ر�DMA   
    DMA_ClearFlag(DMA1_FLAG_TC6);	//�����־λ

    /* ��ý���֡֡�� */
    len = USART2_DATA_LEN - DMA_GetCurrDataCounter(DMA1_Channel6);
    memcpy(buf, USART2_RECEIVE_DATA, len);
    /* ���ô������ݳ��� */
    DMA_SetCurrDataCounter(DMA1_Channel6, USART2_DATA_LEN);
    /* ��DMA */
    DMA_Cmd(DMA1_Channel6, ENABLE);
    return len;

}

/**
 * @Description: USARTʹ��DMA�������жϷ������ 
 */
void DMA1_Channel7_IRQHandler(void) 	  
{  
    if(DMA_GetITStatus(DMA1_IT_TC7) != RESET)   
    {  
        /* �����־λ */ 
        DMA_ClearFlag(DMA1_FLAG_TC7);  
        /* �ر�DMA */ 
        DMA_Cmd(DMA1_Channel7,DISABLE);  
        /* �򿪷�������ж�,������������ֽ� */ 
        USART_ITConfig(USART2,USART_IT_TC,ENABLE);  
    }  
}  
     
/**
 * @Description: �����жϴ�����   ����ʹ�ñ��ļ������������ڰ����ŵ�stm32f4xx_it.c��
 */ 
void USART2_IRQHandler(void) 		   
{  
      
    /* ��������жϴ��� */ 
    if(USART_GetITStatus(USART2, USART_IT_TC)!= RESET)  
    {  
        /* �رշ�������ж� */ 
        USART_ITConfig(USART2,USART_IT_TC,DISABLE);  
        /* ������� */ 
        USART2_TX_BUSY = 0; 			
    }   
      
    /* ��������жϴ��� */ 
	if(USART_GetITStatus(USART2, USART_IT_IDLE) != RESET)
	{ 
    	uart2_rx.len = USART2_RX_Finish_IRQ(uart2_rx.buf);	 
			/*�ж��ǲ���Ѫѹ����ָ�� ���ڿɸ���Ϊswitch�ṹ */
		if(Is_BP_Order(&USART2_RECEIVE_DATA[0])) 
		{
			BP_Order_USART3(&USART2_RECEIVE_DATA[0]);
		}
		
		if(Is_Speed_Order(&USART2_RECEIVE_DATA[0])) 
		{
			Speed_Response();
		}	
	}  
}  
 
#endif
/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/






