//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//USART+DMA���ͺͽ���
//���� PA9 TX PA10 RX
//������
//HWY 2017 10 18
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 

#include "usart1_dma.h"
#include "project_config.h"
#include "sys.h" 
#include <string.h> 	  
#include "stm32f10x_dma.h"	

/* UART GPIO define. */            //�궨��
#define USART1_GPIO_TX       		   GPIO_Pin_9
#define USART1_GPIO_RX       		   GPIO_Pin_10
#define USART1_GPIO_TX_PinSource       GPIO_PinSource9
#define USART1_GPIO_RX_PinSource       GPIO_PinSource10
#define USART1_GPIO          		   GPIOA
#define USART1_GPIO_RCC      		   RCC_APB2Periph_GPIOA
#define USART1_DATA_LEN  64  //���պͷ������ݵ���󳤶�
/*private*/
u8 USART1_SEND_DATA[USART1_DATA_LEN];  // ��������
u8 USART1_RECEIVE_DATA[USART1_DATA_LEN]; //��������
u8 USART1_TX_BUSY=0; //0������ 1:���ڷ���
/*public*/
struct uart1_buffer uart1_rx,uart1_tx;
	  

/**
* @Description: USART1_DMA��ʼ��
* @param baud - ���ڲ�����.    
*/ 
#ifdef  USE_USART1_DMA
void USART1_DMA_Init(u32 baud) 
{  
  
    NVIC_InitTypeDef NVIC_InitStructure ;  	   		//�����жϽṹ��        
    GPIO_InitTypeDef GPIO_InitStructure;  			//����IO��ʼ���ṹ��       
    USART_InitTypeDef USART_InitStructure;    		//���崮�ڽṹ��    
    DMA_InitTypeDef DMA_InitStructure;  	   		//����DMA�ṹ��  
  
/* ��1��������IO���� */       
    RCC_APB2PeriphClockCmd(USART1_GPIO_RCC, ENABLE);  

  
    /* USART Tx��GPIO����Ϊ���츴��ģʽ */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;       //�ܽ�ģʽ:�����                
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //IO���ٶ�       
    GPIO_InitStructure.GPIO_Pin = USART1_GPIO_TX;  		   //�ܽ�ָ��     
    GPIO_Init(USART1_GPIO, &GPIO_InitStructure);  		   //��ʼ�� 
      
    /* ��USART1 Rx��GPIO����Ϊ��������ģʽ  */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;       //�ܽ�ģʽ:�����           
 	  GPIO_InitStructure.GPIO_Pin = USART1_GPIO_RX;  	   //�ܽ�ָ��     
    GPIO_Init(USART1_GPIO, &GPIO_InitStructure);  		   //��ʼ��
		
		
		

/* ��2�����������ڲ������� */   
   
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);  	  //�򿪴��ڶ�Ӧ������ʱ��  
    /* ��ʼ�����ڲ��� */   
    USART_InitStructure.USART_BaudRate = baud;                   //������
	  USART_InitStructure.USART_WordLength = USART_WordLength_8b;    
    USART_InitStructure.USART_StopBits = USART_StopBits_1;    
    USART_InitStructure.USART_Parity = USART_Parity_No;    
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������    
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;  //�շ�ģʽ              
    USART_Init(USART1,&USART_InitStructure);    				  //��ʼ������  
      
    /* �����ж����� */  
    USART_ITConfig(USART1,USART_IT_TC,DISABLE);  
    USART_ITConfig(USART1,USART_IT_RXNE,DISABLE);  
    USART_ITConfig(USART1,USART_IT_TXE,DISABLE);  
    USART_ITConfig(USART1,USART_IT_IDLE,ENABLE);     		  	  //�򿪿����ж� �������ղ���������
       
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;             //ͨ������Ϊ�����ж�    
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //�ж�ռ�ȵȼ�  
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;         //�ж���Ӧ���ȼ�   
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;               //���ж�    
    NVIC_Init(&NVIC_InitStructure);     
          
    /* Enable USART1 DMA Rx Tx request */            //ʹ�ܴ����շ�
    USART_DMACmd(USART1,USART_DMAReq_Tx,ENABLE);  
    USART_DMACmd(USART1,USART_DMAReq_Rx,ENABLE);  
    
    /* �������� */   
    USART_Cmd(USART1, ENABLE);      
	
	
/* ��3�������ڷ���DMA���� */ 	 
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);  		//����DMA2ʱ�� 
    /* DMA�����ж����� */ 
		
		
    NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel4_IRQn;  		
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  		
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;  			
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  				
    NVIC_Init(&NVIC_InitStructure);  								
     
		 
		 
    DMA_DeInit(DMA1_Channel4);  									//DMAͨ������  DMAͨ��4				   
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&USART1->DR); //�����ַ      
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)USART1_SEND_DATA; //�ڴ��ַ     
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;  			//dma���䷽��  �ڴ浽����   
    DMA_InitStructure.DMA_BufferSize = USART1_DATA_LEN;  				//����DMA�ڴ���ʱ�������ĳ���     
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;  	//����DMA���������ģʽ��һ������  ������    
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;  			//����DMA���ڴ����ģʽ    �ڴ治����
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte; //���������ֳ�      
    DMA_InitStructure.DMA_MemoryDataSize = DMA_PeripheralDataSize_Byte; //�ڴ������ֳ�      
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;  						//����DMA�Ĵ���ģʽ    
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;  				//����DMA�����ȼ���  �߼���                          
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable; 
    DMA_Init(DMA1_Channel4, &DMA_InitStructure);    						//����DMA��ͨ��      
    DMA_ITConfig(DMA1_Channel4,DMA_IT_TC,ENABLE);     					//ʹ���ж� 

/* ��3�������ڽ���DMA���� */     
     																    //����DMAʱ��
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);  
     
    DMA_DeInit(DMA1_Channel5);  
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&USART1->DR);  //�����ַ      
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)USART1_RECEIVE_DATA;//�ڴ��ַ      
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;  			 //dma���䷽��    ���赽�ڴ�
    DMA_InitStructure.DMA_BufferSize = USART1_DATA_LEN;  				 //����DMA�ڴ���ʱ�������ĳ���   
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;  	 //����DMA���������ģʽ��һ������    
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;  			 //����DMA���ڴ����ģʽ    
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte; //���������ֳ�       
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;  	 //�ڴ������ֳ�     
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;  						 //����DMA�Ĵ���ģʽ  
    DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;  			 //����DMA�����ȼ���         
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;      		                      
    DMA_Init(DMA1_Channel5, &DMA_InitStructure);    						 //����DMA1��ͨ��    
    DMA_Cmd(DMA1_Channel5,ENABLE);  										 //ʹ��ͨ��  
} 

/**
 * @Description:UART1_DMA���ⷢ������
 * @param data - �������ݴ�ŵ�ַ
 * @param size - ���������ֽ���    
 */  
void USART1_DMA_Send_Once_Data(uint8_t *data,uint16_t size)  //�������ݺ���
{ 
	/* ���ͼ��ѭ�����׿���*/	
//    /* �ȴ����� */ 
//    while (USART1_TX_BUSY);  
//    USART1_TX_BUSY = 1;  //������
	
    /* �������� */ 
    memcpy(USART1_SEND_DATA,data,size);
	/* �ı�datasizeǰ��Ҫ��ֹͨ������ */ 
	DMA_Cmd(DMA1_Channel4,DISABLE);  
    /* ���ô������ݳ���  */
    DMA_SetCurrDataCounter(DMA1_Channel4,size);  
    /* ��DMA,��ʼ���� */ 
    DMA_Cmd(DMA1_Channel4,ENABLE);  
}  

  
/**
* @Description:���ڴ����������ж� 
* @param  buf - ���յ����� 
* @return len - ���յ����ݳ���   
*/   
uint8_t USART1_RX_Finish_IRQ(uint8_t *buf)
{
    uint16_t len = 0;

    USART1->SR;
    USART1->DR; 									//��USART_IT_IDLE��־   
    DMA_Cmd(DMA1_Channel5, DISABLE);				    //�ر�DMA   
    DMA_ClearFlag(DMA1_FLAG_TC5);	//�����־λ

    /* ��ý���֡֡�� */
    len = USART1_DATA_LEN - DMA_GetCurrDataCounter(DMA1_Channel5);
    memcpy(buf, USART1_RECEIVE_DATA, len);
    /* ���ô������ݳ��� */
    DMA_SetCurrDataCounter(DMA1_Channel5, USART1_DATA_LEN);
    /* ��DMA */
    DMA_Cmd(DMA1_Channel5, ENABLE);
    return len;

}

/**
 * @Description: USARTʹ��DMA�������жϷ������ 
 */
void DMA1_Channel4_IRQHandler(void) 	  
{  
    if(DMA_GetITStatus(DMA1_IT_TC4) != RESET)   
    {  
        /* �����־λ */ 
        DMA_ClearFlag(DMA1_FLAG_TC4);  
        /* �ر�DMA */ 
        DMA_Cmd(DMA1_Channel4,DISABLE);  
        /* �򿪷�������ж�,������������ֽ� */ 
        USART_ITConfig(USART1,USART_IT_TC,ENABLE);  
    }  
}  
     
/**
 * @Description: �����жϴ�����   
 */ 
void USART1_IRQHandler(void) 		   
{  
      
    /* ��������жϴ��� */ 
    if(USART_GetITStatus(USART1, USART_IT_TC) != RESET)  
    {  
        /* �رշ�������ж� */ 
        USART_ITConfig(USART1,USART_IT_TC,DISABLE);  
        /* ������� */ 
        USART1_TX_BUSY = 0;  
    }   
      
    /* ��������жϴ��� */ 
	if(USART_GetITStatus(USART1, USART_IT_IDLE) != RESET)
	{ 
    	uart1_rx.len = USART1_RX_Finish_IRQ(uart1_rx.buf);
	}  
}  
 

#endif




/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/






