#ifndef __USART3_DMA_H
#define __USART3_DMA_H
#include "sys.h"
#include "project_config.h"

#ifdef USE_USART3_DMA
struct uart3_buffer
{
	unsigned char  len;   //���ݳ���
	unsigned char  buf[128];  //�������ݻ�����
};
extern struct uart3_buffer uart3_rx,uart3_tx;

extern u8 USART3_TX_BUSY; //0������ 1:���ڷ���
void USART3_DMA_Init(u32 baud) ;
void USART3_DMA_Send_Once_Data(uint8_t *data,uint16_t size)  ;
uint8_t USART3_RX_Finish_IRQ(uint8_t *buf)  ;
#endif				    
#endif
