//////////////////////////////////////////////////
//STM32F103RCT6
//串口2通信协议
//血压模块
//HWY 2018 9 15
//All rights reserved									  
//////////////////////////////////////////////////
/*新版本通信协议 */
/* 主要做转发的工作 
1.将串口1收到的信息转发到串口2
2.讲串口2收到的信息转到到串口1
*/




#include "usart2_protocol.h"
#include "project_config.h"
#include "usart2_dma.h"

/* 提取串口1收到的血压指令发送给串口2   0x02数据类型码*/ 
/* 注意判断数据长度*/
/*
帧头 0xA5
数据长度 0xFF
数据类型码 0X02
有效数据 
CRC 校验码 高低位 
*/

u8 USART2_BP_DATA[32];


void BP_Order_USART2(u8 *USART_RECEIVE_DATA)
{
	u16 USART2_BP_DATA_LEN =USART_RECEIVE_DATA[1]-0x05;  //有效数据个数
	for(u8 i=0;i<USART2_DATA_LEN;i++)
	{
		USART2_BP_DATA[i]=USART_RECEIVE_DATA[i+0x03];
	}
	USART2_DMA_Send_Once_Data(USART2_BP_DATA,USART2_BP_DATA_LEN);
}	
	
	





