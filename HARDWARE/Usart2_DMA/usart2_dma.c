//////////////////////////////////////////////////////////////////////////////////	 
//STM32F407IGT6
//USART+DMA���ͺͽ���
//���� PA2 TX PA3 RX
//Э���
//HWY 2017 10 18
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 

#include "usart2_dma.h"
#include "sys.h" 
#include <string.h> 	  
#include "gpio.h"	
#include "delay.h"

/* UART GPIO define. */
#define USART2_GPIO_TX       		   GPIO_Pin_2
#define USART2_GPIO_RX       		   GPIO_Pin_3
#define USART2_GPIO_TX_PinSource   GPIO_PinSource2
#define USART2_GPIO_RX_PinSource   GPIO_PinSource3
#define USART2_GPIO          		   GPIOA
#define USART2_GPIO_RCC      		   RCC_AHB1Periph_GPIOA


#define USART2_DATA_LEN  64  //���պͷ������ݵ���󳤶�
/*private*/
u8 USART2_SEND_DATA[USART2_DATA_LEN];  
u8 USART2_RECEIVE_DATA[USART2_DATA_LEN]; 
u8 USART2_TX_BUSY=0; //0������ 1:���ڷ���
/*public*/
struct uart2_buffer uart2_rx,uart2_tx;
	  

/**
* @Description: UART2_DMA��ʼ��
* @param baud - ���ڲ�����.    
*/ 
void USART2_DMA_Init(u32 baud) 
{  
  
    NVIC_InitTypeDef NVIC_InitStructure ;  	   		//�����жϽṹ��        
    GPIO_InitTypeDef GPIO_InitStructure;  			//����IO��ʼ���ṹ��       
    USART_InitTypeDef USART_InitStructure;    		//���崮�ڽṹ��    
    DMA_InitTypeDef DMA_InitStructure;  	   		//����DMA�ṹ��  
  
/* ��1��������IO���� */       
    RCC_AHB1PeriphClockCmd(USART2_GPIO_RCC, ENABLE);   
    GPIO_PinAFConfig(USART2_GPIO,USART2_GPIO_RX_PinSource,GPIO_AF_USART2);    
    GPIO_PinAFConfig(USART2_GPIO,USART2_GPIO_TX_PinSource,GPIO_AF_USART2);  
  
    /* USART Tx��GPIO����Ϊ���츴��ģʽ */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;       //�ܽ�ģʽ:�����       
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;     //����:����ģʽ       
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;       //������������    
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; //IO���ٶ�       
    GPIO_InitStructure.GPIO_Pin = USART2_GPIO_TX;  		   //�ܽ�ָ��     
    GPIO_Init(USART2_GPIO, &GPIO_InitStructure);  		   //��ʼ�� 
      
    /* ��USART2 Rx��GPIO����Ϊ��������ģʽ  */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;       //�ܽ�ģʽ:�����    
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;   //������������         
 	GPIO_InitStructure.GPIO_Pin = USART2_GPIO_RX;  	   //�ܽ�ָ��     
    GPIO_Init(USART2_GPIO, &GPIO_InitStructure);  		   //��ʼ��

/* ��2�����������ڲ������� */   

      
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);  	  //�򿪴��ڶ�Ӧ������ʱ��  
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
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;  //�ж�ռ�ȵȼ�  
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
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);  		//����DMAʱ�� 
    /* DMA�����ж����� */ 
    NVIC_InitStructure.NVIC_IRQChannel = DMA1_Stream6_IRQn;  		
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  		
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;  			
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  				
    NVIC_Init(&NVIC_InitStructure);  								
     
    DMA_DeInit(DMA1_Stream6);  									//DMAͨ������ 
    DMA_InitStructure.DMA_Channel = DMA_Channel_4;   				   
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&USART2->DR); //�����ַ      
    DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)USART2_SEND_DATA; //�ڴ��ַ     
    DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;  			//dma���䷽��     
    DMA_InitStructure.DMA_BufferSize = USART2_DATA_LEN;  				//����DMA�ڴ���ʱ�������ĳ���     
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;  	//����DMA���������ģʽ��һ������      
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;  			//����DMA���ڴ����ģʽ     
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte; //���������ֳ�      
    DMA_InitStructure.DMA_MemoryDataSize = DMA_PeripheralDataSize_Byte; //�ڴ������ֳ�      
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;  						//����DMA�Ĵ���ģʽ    
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;  				//����DMA�����ȼ���          
    DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;      	    //ָ�����FIFOģʽ��ֱ��ģʽ������ָ������ �� ��ʹ��FIFOģʽ       
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;   //ָ����FIFO��ֵˮƽ              
    DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;         //ָ����Burstת�������ڴ洫��      
    DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single; //ָ����Burstת��������Χת��               
    DMA_Init(DMA1_Stream6, &DMA_InitStructure);    						//����DMA2��ͨ��      
    DMA_ITConfig(DMA1_Stream6,DMA_IT_TC,ENABLE);     					//ʹ���ж� 

/* ��3�������ڽ���DMA���� */     
     																    //����DMAʱ��
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);  
     
    DMA_DeInit(DMA1_Stream5);  
    DMA_InitStructure.DMA_Channel = DMA_Channel_4;  					 //DMAͨ������     
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&USART2->DR);  //�����ַ      
    DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)USART2_RECEIVE_DATA;//�ڴ��ַ      
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;  			 //dma���䷽��    
    DMA_InitStructure.DMA_BufferSize = USART2_DATA_LEN;  				 //����DMA�ڴ���ʱ�������ĳ���   
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;  	 //����DMA���������ģʽ��һ������    
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;  			 //����DMA���ڴ����ģʽ    
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte; //���������ֳ�       
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;  	 //�ڴ������ֳ�     
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;  						 //����DMA�Ĵ���ģʽ  
    DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;  			 //����DMA�����ȼ���         
    DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;      		 //ָ�����FIFOģʽ��ֱ��ģʽ������ָ������ �� ��ʹ��FIFOģʽ       
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;    //ָ����FIFO��ֵˮƽ              
    DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;          //ָ����Burstת�������ڴ洫��  
    DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;  //ָ����Burstת��������Χת��                   
    DMA_Init(DMA1_Stream5, &DMA_InitStructure);    						 //����DMA2��ͨ��  
    
    DMA_Cmd(DMA1_Stream5,ENABLE);  										 //ʹ��ͨ��  
} 

/**
 * @Description:UART1_DMA���ⷢ������
 * @param data - �������ݴ�ŵ�ַ
 * @param size - ���������ֽ���    
 */  
void USART2_DMA_Send_Once_Data(uint8_t *data,uint16_t size)  
{  
    /* �ȴ����� */ 
    while (USART2_TX_BUSY);  
    USART2_TX_BUSY = 1;  
    /* �������� */ 
    memcpy(USART2_SEND_DATA,data,size);
	  /* �ı�datasizeǰ��Ҫ��ֹͨ������ */ 
	  DMA_Cmd(DMA1_Stream6,DISABLE);  
    /* ���ô������ݳ���  */
    DMA_SetCurrDataCounter(DMA1_Stream6,size);  
    /* ��DMA,��ʼ���� */ 
    DMA_Cmd(DMA1_Stream6,ENABLE);  
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
    DMA_Cmd(DMA1_Stream5, DISABLE);				    //�ر�DMA   
    DMA_ClearFlag(DMA1_Stream5, DMA_FLAG_TCIF5);	//�����־λ

    /* ��ý���֡֡�� */
    len = USART2_DATA_LEN - DMA_GetCurrDataCounter(DMA1_Stream5);
    memcpy(buf, USART2_RECEIVE_DATA, len);
    /* ���ô������ݳ��� */
    DMA_SetCurrDataCounter(DMA1_Stream5, USART2_DATA_LEN);
    /* ��DMA */
    DMA_Cmd(DMA1_Stream5, ENABLE);
    return len;

}

/**
 * @Description: USARTʹ��DMA�������жϷ������ 
 */
void DMA1_Stream6_IRQHandler(void) 	  
{  
    if(DMA_GetITStatus(DMA1_Stream6,DMA_IT_TCIF6) != RESET)   
    {  
        /* �����־λ */ 
        DMA_ClearFlag(DMA1_Stream6,DMA_FLAG_TCIF6);  
        /* �ر�DMA */ 
        DMA_Cmd(DMA1_Stream6,DISABLE);  
        /* �򿪷�������ж�,������������ֽ� */ 
        USART_ITConfig(USART2,USART_IT_TC,ENABLE);  
    }  
}  
     
/**
 * @Description: �����жϴ�����   ����ʹ�ñ��ļ������������ڰ����ŵ�stm32f4xx_it.c��
 */ 

#define Receive_Size 17
extern u16 Date_len;
extern u8 Receive_Date[Receive_Size]; //��������ȫ����ѯ

 u16 Brake_Current_Vin; // ��ǰ�����ѹ �Ĵ�����ַ0x00 0x00 
 u16 Brake_Current_Vout; //��ǰ�����ѹ �Ĵ�����ַ0x00 0x01
 u16 Brake_Current_Iout;//��ǰ�������  �Ĵ�����ַ0x00 0x02
 u16 Brake_Set_Iout; //��ǰ����������� �Ĵ�����ַ0x00 0x03
 u16 Brake_Set_Vout; //��ǰ���������ѹ �Ĵ�����ַ0x00 0x04
 u16 Brake_Status; //��Դ״̬ �Ĵ�����ַ0x00 0x05  0x01 ���� 0x00 �ر�


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
//    	uart2_rx.len = USART2_RX_Finish_IRQ(uart2_rx.buf);
		
		
		 Date_len=USART2_RX_Finish_IRQ(Receive_Date);
		//ȡ��Ӧ���ݸ�ֵ
		 Brake_Current_Vin=(unsigned short)(Receive_Date[3]<<8 | Receive_Date[4]);
	   Brake_Current_Vout=(unsigned short)(Receive_Date[5]<<8 | Receive_Date[6]);
	   Brake_Current_Iout=(unsigned short)(Receive_Date[7]<<8 | Receive_Date[8]);
	   Brake_Set_Iout=(unsigned short)(Receive_Date[9]<<8 | Receive_Date[10]);
	   Brake_Set_Vout=(unsigned short)(Receive_Date[11]<<8 | Receive_Date[12]);
		 Brake_Status=(unsigned short)(Receive_Date[13]<<8 | Receive_Date[14]);		
		 
	
	}  
}  
 

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/






