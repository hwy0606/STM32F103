//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//USART+DMA发送和接收
//引脚 PA9 TX PA10 RX
//驱动层
//HWY 2017 10 18
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 

#include "usart1_dma.h"
#include "project_config.h"
#include "sys.h" 
#include <string.h> 	  
#include "stm32f10x_dma.h"	
#include "usart2_protocol.h"

/*private*/
static u8 USART1_SEND_DATA[USART1_DATA_LEN];  // 发送数组
static u8 USART1_RECEIVE_DATA[USART1_DATA_LEN]; //接收数组
static u8 USART1_TX_BUSY=0; //0：空闲 1:正在发送
/*public*/
struct uart1_buffer uart1_rx,uart1_tx;
 u8 USART_RECEIVE_MODE; 

/**
* @Description: USART1_DMA初始化
* @param baud - 串口波特率.    
*/ 
#ifdef  USE_USART1_DMA
void USART1_DMA_Init(u32 baud) 
{  
  
    NVIC_InitTypeDef NVIC_InitStructure ;  	   		//定义中断结构体        
    GPIO_InitTypeDef GPIO_InitStructure;  			//定义IO初始化结构体       
    USART_InitTypeDef USART_InitStructure;    		//定义串口结构体    
    DMA_InitTypeDef DMA_InitStructure;  	   		//定义DMA结构体  
  
/* 第1步：串口IO设置 */       
    RCC_APB2PeriphClockCmd(USART1_GPIO_RCC, ENABLE);  

  
    /* USART Tx的GPIO配置为推挽复用模式 */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;       //管脚模式:输出口                
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //IO口速度       
    GPIO_InitStructure.GPIO_Pin = USART1_GPIO_TX;  		   //管脚指定     
    GPIO_Init(USART1_GPIO, &GPIO_InitStructure);  		   //初始化 
      
    /* 将USART1 Rx的GPIO配置为浮空输入模式  */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;       //管脚模式:输入口           
 	  GPIO_InitStructure.GPIO_Pin = USART1_GPIO_RX;  	   //管脚指定     
    GPIO_Init(USART1_GPIO, &GPIO_InitStructure);  		   //初始化
		
		
		

/* 第2步：基本串口参数设置 */   
   
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);  	  //打开串口对应的外设时钟  
    /* 初始化串口参数 */   
    USART_InitStructure.USART_BaudRate = baud;                   //波特率
	  USART_InitStructure.USART_WordLength = USART_WordLength_8b;    
    USART_InitStructure.USART_StopBits = USART_StopBits_1;    
    USART_InitStructure.USART_Parity = USART_Parity_No;    
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制    
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;  //收发模式              
    USART_Init(USART1,&USART_InitStructure);    				  //初始化串口  
      
    /* 串口中断配置 */  
    USART_ITConfig(USART1,USART_IT_TC,DISABLE);  
    USART_ITConfig(USART1,USART_IT_RXNE,DISABLE);  
    USART_ITConfig(USART1,USART_IT_TXE,DISABLE);  
    USART_ITConfig(USART1,USART_IT_IDLE,ENABLE);     		  	  //打开空闲中断 用来接收不定长数据
       
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;             //通道设置为串口中断    
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //中断占先等级  
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;         //中断响应优先级   
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;               //打开中断    
    NVIC_Init(&NVIC_InitStructure);     
          
    /* Enable USART1 DMA Rx Tx request */            //使能串口收发
    USART_DMACmd(USART1,USART_DMAReq_Tx,ENABLE);  
    USART_DMACmd(USART1,USART_DMAReq_Rx,ENABLE);  
    
    /* 启动串口 */   
    USART_Cmd(USART1, ENABLE);      
	
	
/* 第3步：串口发送DMA配置 */ 	 
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);  		//启动DMA2时钟 
    /* DMA发送中断设置 */ 
		
		
    NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel4_IRQn;  		
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  		
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;  			
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  				
    NVIC_Init(&NVIC_InitStructure);  								
     
		 
		 
    DMA_DeInit(DMA1_Channel4);  									//DMA通道配置  DMA通道4				   
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&USART1->DR); //外设地址      
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)USART1_SEND_DATA; //内存地址     
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;  			//dma传输方向  内存到外设   
    DMA_InitStructure.DMA_BufferSize = USART1_DATA_LEN;  				//设置DMA在传输时缓冲区的长度     
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;  	//设置DMA的外设递增模式，一个外设  不递增    
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;  			//设置DMA的内存递增模式    内存不递增
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte; //外设数据字长      
    DMA_InitStructure.DMA_MemoryDataSize = DMA_PeripheralDataSize_Byte; //内存数据字长      
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;  						//设置DMA的传输模式    
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;  				//设置DMA的优先级别  高级别                          
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable; 
    DMA_Init(DMA1_Channel4, &DMA_InitStructure);    						//配置DMA的通道      
    DMA_ITConfig(DMA1_Channel4,DMA_IT_TC,ENABLE);     					//使能中断 

/* 第3步：串口接收DMA配置 */     
     																    //启动DMA时钟
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);  
     
    DMA_DeInit(DMA1_Channel5);  
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&USART1->DR);  //外设地址      
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)USART1_RECEIVE_DATA;//内存地址      
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;  			 //dma传输方向    外设到内存
    DMA_InitStructure.DMA_BufferSize = USART1_DATA_LEN;  				 //设置DMA在传输时缓冲区的长度   
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;  	 //设置DMA的外设递增模式，一个外设    
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;  			 //设置DMA的内存递增模式    
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte; //外设数据字长       
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;  	 //内存数据字长     
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;  						 //设置DMA的传输模式  
    DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;  			 //设置DMA的优先级别         
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;      		                      
    DMA_Init(DMA1_Channel5, &DMA_InitStructure);    						 //配置DMA1的通道    
    DMA_Cmd(DMA1_Channel5,ENABLE);  										 //使能通道  
} 

/**
 * @Description:UART1_DMA向外发送数据
 * @param data - 发送数据存放地址
 * @param size - 发送数据字节数    
 */  
void USART1_DMA_Send_Once_Data(uint8_t *data,uint16_t size)  //发送数据函数
{ 
	/* 发送检测循环容易卡死*/	
//    /* 等待空闲 */ 
//    while (USART1_TX_BUSY);  
//    USART1_TX_BUSY = 1;  //发送中
	
    /* 复制数据 */ 
    memcpy(USART1_SEND_DATA,data,size);
	/* 改变datasize前先要禁止通道工作 */ 
	DMA_Cmd(DMA1_Channel4,DISABLE);  
    /* 设置传输数据长度  */
    DMA_SetCurrDataCounter(DMA1_Channel4,size);  
    /* 打开DMA,开始发送 */ 
    DMA_Cmd(DMA1_Channel4,ENABLE);  
}  

  
/**
* @Description:串口处理接收完成中断 
* @param  buf - 接收的数据 
* @return len - 接收的数据长度   
*/   
uint8_t USART1_RX_Finish_IRQ(uint8_t *buf)
{
    uint16_t len = 0;

    USART1->SR;
    USART1->DR; 									//清USART_IT_IDLE标志   
    DMA_Cmd(DMA1_Channel5, DISABLE);				    //关闭DMA   
    DMA_ClearFlag(DMA1_FLAG_TC5);	//清除标志位

    /* 获得接收帧帧长 */
    len = USART1_DATA_LEN - DMA_GetCurrDataCounter(DMA1_Channel5);
    memcpy(buf, USART1_RECEIVE_DATA, len);
    /* 设置传输数据长度 */
    DMA_SetCurrDataCounter(DMA1_Channel5, USART1_DATA_LEN);
    /* 打开DMA */
    DMA_Cmd(DMA1_Channel5, ENABLE);
    return len;

}

/**
 * @Description: USART使用DMA发数据中断服务程序 
 */
void DMA1_Channel4_IRQHandler(void) 	  
{  
    if(DMA_GetITStatus(DMA1_IT_TC4) != RESET)   
    {  
        /* 清除标志位 */ 
        DMA_ClearFlag(DMA1_FLAG_TC4);  
        /* 关闭DMA */ 
        DMA_Cmd(DMA1_Channel4,DISABLE);  
        /* 打开发送完成中断,发送最后两个字节 */ 
        USART_ITConfig(USART1,USART_IT_TC,ENABLE);  
    }  
}  
     
/**
 * @Description: 串口中断处理函数   
 */ 
void USART1_IRQHandler(void) 		   
{  
      
    /* 发送完成中断处理 */ 
    if(USART_GetITStatus(USART1, USART_IT_TC) != RESET)  
    {  
        /* 关闭发送完成中断 */ 
        USART_ITConfig(USART1,USART_IT_TC,DISABLE);  
        /* 发送完成 */ 
        USART1_TX_BUSY = 0;  
    }   
      
    /* 接收完成中断处理 */ 
	if(USART_GetITStatus(USART1, USART_IT_IDLE) != RESET)
	{ 
    	uart1_rx.len = USART1_RX_Finish_IRQ(uart1_rx.buf);	
		/* 用户处理函数 */ 
		USART_RECEIVE_MODE=USART1_Flag(&USART1_RECEIVE_DATA[0]);
		switch (USART_RECEIVE_MODE){
			case 0x01: //开始成人模式BP
      {
				switch (BP_Measurement(&USART1_RECEIVE_DATA[0]))
				{
					case 0x01:
					{
						BP_Measurement_Start(); //串口2发送开始BP测量相关指令
					}
					case 0x02:
					{
						BP_Measurement_Stop(); //串口2发送中止BP测量相关指令
					}
				}
				
				
				
			  break;
			}
		  case 0x02:
      {
				
				
				
			  break;
			}
			case 0x03:
      {
				
				
				
			  break;
			}
			
			case 0x04:
      {
				
				
				
			  break;
			}
		
		
		
		
		
		
	 }  
  } 
}	
 

#endif




/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/






