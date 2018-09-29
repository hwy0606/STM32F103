//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//USART+DMA发送和接收
//引脚 PA2 TX PA3 RX
//驱动层
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
static u8 USART2_TX_BUSY=0; //0：空闲 1:正在发送
/*public*/
struct uart2_buffer uart2_rx,uart2_tx;
	  

/**
* @Description: UART2_DMA初始化
* @param baud - 串口波特率.    
*/ 
#ifdef USE_USART2_DMA
void USART2_DMA_Init(u32 baud) 
{  
  
    NVIC_InitTypeDef NVIC_InitStructure ;  	   		//定义中断结构体        
    GPIO_InitTypeDef GPIO_InitStructure;  			//定义IO初始化结构体       
    USART_InitTypeDef USART_InitStructure;    		//定义串口结构体    
    DMA_InitTypeDef DMA_InitStructure;  	   		//定义DMA结构体  
  
/* 第1步：串口IO设置 */       
    
 
  
    /* USART Tx的GPIO配置为推挽复用模式 */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;       //管脚模式:输出口              //上拉下拉设置    
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //IO口速度       
    GPIO_InitStructure.GPIO_Pin = USART2_GPIO_TX;  		   //管脚指定     
    GPIO_Init(USART2_GPIO, &GPIO_InitStructure);  		   //初始化 
      
    /* 将USART2 Rx的GPIO配置为浮空输入模式  */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;       //管脚模式:输入口     
 	  GPIO_InitStructure.GPIO_Pin = USART2_GPIO_RX;  	   //管脚指定     
    GPIO_Init(USART2_GPIO, &GPIO_InitStructure);  		   //初始化

/* 第2步：基本串口参数设置 */   

      
    
    /* 初始化串口参数 */   
    USART_InitStructure.USART_BaudRate = baud;  
	  USART_InitStructure.USART_WordLength = USART_WordLength_8b;    
    USART_InitStructure.USART_StopBits = USART_StopBits_1;    
    USART_InitStructure.USART_Parity = USART_Parity_No;    
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;    
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;               
    USART_Init(USART2,&USART_InitStructure);    				  //初始化串口  
      
    /* 串口中断配置 */  
    USART_ITConfig(USART2,USART_IT_TC,DISABLE);  
    USART_ITConfig(USART2,USART_IT_RXNE,DISABLE);  
    USART_ITConfig(USART2,USART_IT_TXE,DISABLE);  
    USART_ITConfig(USART2,USART_IT_IDLE,ENABLE);     		  	  //打开空闲中断
       
    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;             //通道设置为串口中断    
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;  //中断占先等级  
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;         //中断响应优先级   
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;               //打开中断    
    NVIC_Init(&NVIC_InitStructure);     
          
    /* Enable USART2 DMA Rx Tx request */
    USART_DMACmd(USART2,USART_DMAReq_Tx,ENABLE);  
    USART_DMACmd(USART2,USART_DMAReq_Rx,ENABLE);  
    
    /* 启动串口 */   
    USART_Cmd(USART2, ENABLE);      
//	  USART_HalfDuplexCmd(USART2, ENABLE);//使能或者失能USART半双工模式
	
    /* 第3步：串口发送DMA配置 */ 	 
    
    /* DMA发送中断设置 */ 
    NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel7_IRQn;  		
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  		
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;  			
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  				
    NVIC_Init(&NVIC_InitStructure);  								
     
    DMA_DeInit(DMA1_Channel7);  									//DMA通道配置   				   
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&USART2->DR); //外设地址      
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)USART2_SEND_DATA; //内存地址     
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;  			//dma传输方向     
    DMA_InitStructure.DMA_BufferSize = USART2_DATA_LEN;  				//设置DMA在传输时缓冲区的长度     
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;  	//设置DMA的外设递增模式，一个外设      
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;  			//设置DMA的内存递增模式     
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte; //外设数据字长      
    DMA_InitStructure.DMA_MemoryDataSize = DMA_PeripheralDataSize_Byte; //内存数据字长      
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;  						//设置DMA的传输模式    
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;  				//设置DMA的优先级别          
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;      
    DMA_Init(DMA1_Channel7, &DMA_InitStructure);    						//配置DMA2的通道      
    DMA_ITConfig(DMA1_Channel7,DMA_IT_TC,ENABLE);     					//使能中断 

/* 第3步：串口接收DMA配置 */     
     																    //启动DMA时钟
     
     
    DMA_DeInit(DMA1_Channel6);   					 //DMA通道配置     
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&USART2->DR);  //外设地址      
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)USART2_RECEIVE_DATA;//内存地址      
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;  			 //dma传输方向    
    DMA_InitStructure.DMA_BufferSize = USART2_DATA_LEN;  				 //设置DMA在传输时缓冲区的长度   
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;  	 //设置DMA的外设递增模式，一个外设    
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;  			 //设置DMA的内存递增模式    
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte; //外设数据字长       
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;  	 //内存数据字长     
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;  						 //设置DMA的传输模式  
    DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;  			 //设置DMA的优先级别         
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;            
    DMA_Init(DMA1_Channel6, &DMA_InitStructure);    						 //配置DMA2的通道  
    
    DMA_Cmd(DMA1_Channel6,ENABLE);  										 //使能通道  
} 

/**
 * @Description:UART1_DMA向外发送数据
 * @param data - 发送数据存放地址
 * @param size - 发送数据字节数    
 */  
void USART2_DMA_Send_Once_Data(uint8_t *data,uint16_t size)  
{  
    /* 等待空闲 */ 
//    while (USART2_TX_BUSY);  
//    USART2_TX_BUSY = 1;  
    /* 复制数据 */ 
    memcpy(USART2_SEND_DATA,data,size);
	  /* 改变datasize前先要禁止通道工作 */ 
	  DMA_Cmd(DMA1_Channel7,DISABLE);  
    /* 设置传输数据长度  */
    DMA_SetCurrDataCounter(DMA1_Channel7,size);  
    /* 打开DMA,开始发送 */ 
    DMA_Cmd(DMA1_Channel7,ENABLE);  
}  

  
/**
* @Description:串口处理接收完成中断 
* @param  buf - 接收的数据 
* @return len - 接收的数据长度   
*/   
uint8_t USART2_RX_Finish_IRQ(uint8_t *buf)
{
    uint16_t len = 0;

    USART2->SR;
    USART2->DR; 									//清USART_IT_IDLE标志   
    DMA_Cmd(DMA1_Channel6, DISABLE);				    //关闭DMA   
    DMA_ClearFlag(DMA1_FLAG_TC6);	//清除标志位

    /* 获得接收帧帧长 */
    len = USART2_DATA_LEN - DMA_GetCurrDataCounter(DMA1_Channel6);
    memcpy(buf, USART2_RECEIVE_DATA, len);
    /* 设置传输数据长度 */
    DMA_SetCurrDataCounter(DMA1_Channel6, USART2_DATA_LEN);
    /* 打开DMA */
    DMA_Cmd(DMA1_Channel6, ENABLE);
    return len;

}

/**
 * @Description: USART使用DMA发数据中断服务程序 
 */
void DMA1_Channel7_IRQHandler(void) 	  
{  
    if(DMA_GetITStatus(DMA1_IT_TC7) != RESET)   
    {  
        /* 清除标志位 */ 
        DMA_ClearFlag(DMA1_FLAG_TC7);  
        /* 关闭DMA */ 
        DMA_Cmd(DMA1_Channel7,DISABLE);  
        /* 打开发送完成中断,发送最后两个字节 */ 
        USART_ITConfig(USART2,USART_IT_TC,ENABLE);  
    }  
}  
     
/**
 * @Description: 串口中断处理函数   单独使用本文件是用他，现在把他放到stm32f4xx_it.c中
 */ 
void USART2_IRQHandler(void) 		   
{  
      
    /* 发送完成中断处理 */ 
    if(USART_GetITStatus(USART2, USART_IT_TC)!= RESET)  
    {  
        /* 关闭发送完成中断 */ 
        USART_ITConfig(USART2,USART_IT_TC,DISABLE);  
        /* 发送完成 */ 
        USART2_TX_BUSY = 0; 			
    }   
      
    /* 接收完成中断处理 */ 
	if(USART_GetITStatus(USART2, USART_IT_IDLE) != RESET)
	{ 
    	uart2_rx.len = USART2_RX_Finish_IRQ(uart2_rx.buf);	 
			/*判断是不是血压操作指令 后期可更改为switch结构 */
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






