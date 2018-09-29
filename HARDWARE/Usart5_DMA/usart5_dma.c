//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//UART发送和接收
//不用DMA的原因是UART5没有DMA通道
//文件名 改为 uart5
//引脚 PC12 TX PD2 RX
//驱动层
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
 u8 SPO2_FLAG=0; //0-未更新 1-更新
/**
* @Description: uart5_初始化
* @param baud - 串口波特率.    
*/ 
#ifdef USE_USART5_DMA
void UART5_Init(u32 baud) 
{  
  
    NVIC_InitTypeDef NVIC_InitStructure ;  	   		//定义中断结构体        
    GPIO_InitTypeDef GPIO_InitStructure;  			//定义IO初始化结构体       
    USART_InitTypeDef USART_InitStructure;    		//定义串口结构体    
    /* USART5 Tx的GPIO配置为推挽复用模式 */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;       //管脚模式:输出口              //上拉下拉设置    
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //IO口速度       
    GPIO_InitStructure.GPIO_Pin = USART5_GPIO_TX;  		   //管脚指定     
    GPIO_Init(USART5_TX_GPIO, &GPIO_InitStructure);  		   //初始化 
      
    /* 将USART5 Rx的GPIO配置为浮空输入模式  */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;       //管脚模式:输入口     
 	  GPIO_InitStructure.GPIO_Pin = USART5_GPIO_RX;  	   //管脚指定     
    GPIO_Init(USART5_RX_GPIO, &GPIO_InitStructure);  		   //初始化  
    /* 初始化串口参数 */   
    USART_InitStructure.USART_BaudRate = baud;  
	  USART_InitStructure.USART_WordLength = USART_WordLength_8b;    
    USART_InitStructure.USART_StopBits = USART_StopBits_1;    
    USART_InitStructure.USART_Parity = USART_Parity_No;    
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;    
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;               
    USART_Init(UART5,&USART_InitStructure);    				  //初始化串口       
    /* 串口中断配置 */  
		/* 空闲中断配置 和 接收中断配置 */
    USART_ITConfig(UART5,USART_IT_TC,DISABLE);  
    USART_ITConfig(UART5,USART_IT_RXNE,ENABLE);  
    USART_ITConfig(UART5,USART_IT_TXE,DISABLE);  
    USART_ITConfig(UART5,USART_IT_IDLE,ENABLE);     		  	  //打开空闲中断 接收中断       
    NVIC_InitStructure.NVIC_IRQChannel = UART5_IRQn;             //通道设置为串口中断    
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;  //中断占先等级  
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;         //中断响应优先级   
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;               //打开中断    
    NVIC_Init(&NVIC_InitStructure);     
    /* 启动串口 */   
    USART_Cmd(UART5, ENABLE);      
	}
/**
	* @Description:uart5向外发送数据 取发送中断标志位
 * @param data - 发送数据存放地址
 * @param size - 发送数据字节数    
 */  
void UART5_Send_Once_Data(uint8_t *data,uint16_t size)  
{     
    /* 复制数据 */ 
    memcpy(UART5_SEND_DATA,data,size); 
		for(u8 i=0;i<size;i++) 
		{ 
			while(USART_GetFlagStatus(UART5,USART_FLAG_TC)==RESET);   //while等待上一帧发送完 相比DMA此处浪费时间
    USART_SendData(UART5,UART5_SEND_DATA[i]); 
    }  

}     
/**
 * @Description: 串口中断处理函数   单独使用本文件是用他，现在把他放到stm32f4xx_it.c中
 */ 
u8 RxCounter=0; 
void UART5_IRQHandler(void) 		   
{ 	
    /* 接收完成中断处理 */ 
	if(USART_GetITStatus(UART5, USART_IT_RXNE) != RESET)
	{
		UART5_RECEIVE_DATA[RxCounter++]=UART5->DR;
	}
	
	if(USART_GetITStatus(UART5, USART_IT_IDLE) != RESET)
	{ 		 
		RxCounter=0;
		UART5->SR;
    UART5->DR; 									//清USART_IT_IDLE标志 
		/* 接收完一帧后用户处理函数 */
		//判断是实时数据还是状态数据 实时数据则丢弃 状态数据复制到SP02数组中
		if(Is_State_Date(&UART5_RECEIVE_DATA[0]))
		{	
			//如果是状态数据 则将USART3_RECEIVE_DATA数组复制到SPO2数组中 只复制有用信息 此处未检验校验和 后期可完善
				SPO2_DATA[3]=UART5_RECEIVE_DATA[6];//有效数据第一位 SPO2计算结果 
	      SPO2_DATA[4]=UART5_RECEIVE_DATA[7];//有效数据第二位 灌注指数低8位 
	      SPO2_DATA[5]=UART5_RECEIVE_DATA[8];//有效数据第三位 灌注指数高8位 
				SPO2_DATA[6]=UART5_RECEIVE_DATA[11];//有效数据第四位 状态数据 
				SPO2_DATA[7]=UART5_RECEIVE_DATA[13];//有效数据第五位 SQI信号质量 
			  SPO2_FLAG=1; //更新等待发送
		}
		
	}  
}  
 
#endif
/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/






