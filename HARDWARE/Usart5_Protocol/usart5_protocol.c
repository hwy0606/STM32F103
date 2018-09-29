//////////////////////////////////////////////////
//STM32F103RCT6
//串口5通信协议
//血氧模块 
//HWY 2018 9 15
//All rights reserved									  
////////////////////////////////////////////////// 
//测试波特率 115200 实际更改为9600 n 8 1
//通信格式： 
//FE 08 01 83 39 00 0F CC   62HZ  实时数据不使用 上位机另接传感器检测心电数据

//FE 10 01 84 4B   00 60 B8 0B 00   00 03 03 64 00 5D   1HZ
/*
FE 帧头
10 帧长度
01 参数类型
84 ID
11个字节的数据内容
Char1：	PR(脉率)计算结果低字节；
Char2：	PR计算结果高字节；
Char3：	SP02计算结果；*** //唯一有用数据
Char4：	灌注指数低8位；
Char5：	灌注指数高8位；
Char6：	预留；
Char7：	预留；
Char8：	状态数据1;
Char9：	软件故障码
Char10：	SQI信号质量
Char11：	参数锁定次数

5D  校验和（计算参数类型、ID、数据内容三部分数据的累积和，取低位的一个字节） 


*/
#include "usart5_protocol.h"
#include "usart5_dma.h"
#include "project_config.h"

extern u8 SPO2_DATA[SPO2_DATA_LEN];
void UART5_Sensor_Init()
{
	SPO2_DATA[0]=0X5A;//帧头
	SPO2_DATA[1]=0X0A;//数据长度
	SPO2_DATA[2]=0X03;//数据类型码
	SPO2_DATA[3]=0XFF;//有效数据第一位 SPO2计算结果 更新放在USART3_DMA文件中
	SPO2_DATA[4]=0XFF;//有效数据第二位 灌注指数低8位 更新放在USART3_DMA文件中
	SPO2_DATA[5]=0XFF;//有效数据第三位 灌注指数高8位 更新放在USART3_DMA文件中
	SPO2_DATA[6]=0XFF;//有效数据第四位 状态数据 更新放在USART3_DMA文件中
	SPO2_DATA[7]=0XFF;//有效数据第五位 SQI信号质量 更新放在USART3_DMA文件中
	SPO2_DATA[8]=0XFF;//CRC校验码低8位
	SPO2_DATA[9]=0XFF;//CRC校验码高8位	
}

u8 Is_State_Date(u8 *USART_RECEIVE_DATA)
{
	if(((unsigned short)USART_RECEIVE_DATA[3]==0X84))
	{
		if(((unsigned short)USART_RECEIVE_DATA[2]==0X01))
		{
			if(((unsigned short)USART_RECEIVE_DATA[1]==0X10))
			{
				if(((unsigned short)USART_RECEIVE_DATA[0]==0XFE))
				{
						return 1;
				}
			}
		}
	}
	return 0;
}



