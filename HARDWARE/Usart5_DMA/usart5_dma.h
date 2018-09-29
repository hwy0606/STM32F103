#ifndef __USART5_DMA_H
#define __USART5_DMA_H
#include "sys.h"
#include "project_config.h"

#ifdef USE_USART5_DMA
extern u8 UART5_TX_BUSY; //0£º¿ÕÏÐ 1:ÕýÔÚ·¢ËÍ
void UART5_Init(u32 baud) ;
void UART5_Send_Once_Data(uint8_t *data,uint16_t size)  ;

#endif				    
#endif
