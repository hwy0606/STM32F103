//////////////////////////////////////////////////
//STM32F103RCT6
//串口2通信协议
//血压模块
//HWY 2018 9 15
//All rights reserved									  
//////////////////////////////////////////////////
//测试波特率 115200 实际更改为9600 n 8 1 在project_config.h文件中更改
/*功能主要有两种 
1.成人BP测量 测量完成后发送命令读取数据 
2.带袖带压力的BP测量  测量过程中实时发送血压数据
*/

/*通信格式：
1.成人BP测量
主机发送 3A 20 A6
从机收到指令后返回  O-packet 3E 04 4F 6F  
从机完成指令后返回  K-packet 3E	04 4B	73
{如果从机返回忙指令 主机重新发送BP测量指令 B-packet 3E	04 42 7C}

*/

/*通信格式：
2.带袖带压力的成人BP测量
主机发送 3A 56 70
直接返回——3E 04 4F 6F
然后不停返回袖带压力——3E 07 01 8E 00 00 2C
其中：8E 00 00为袖带压力142mmHg,低位在前
完成后返回——3E 04 4B 73
然后返回BP数据——3E 19 03 数据 校验码
*/

#include "usart2_protocol.h"
#include "project_config.h"
#include "usart2_dma.h"
#include "usart2_checkout.h"
/*定义传输数组 主机发送指令共用 */
static u8 BP_SEND_DATA[BP_DATA_LEN];  
static u8 BP_RECEIVE_DATA[BP_DATA_LEN];
void USART2_Sensor_Init()
{
	BP_SEND_DATA[0]=0x3A; //每一个MASTER指令都已0x3A开头
}


/*开始成人BP测量 */
void BP_Measurement_Start()   //成人BP测量 0x20指令
{
	u8 BP_Measurement_LEN =3;
	BP_SEND_DATA[1]=0X20;
	BP_SEND_DATA[2]=0XA6;//获取主机发送校验码  A6
	USART2_DMA_Send_Once_Data(BP_SEND_DATA,BP_Measurement_LEN);
}
/*中止当前测量 */
void BP_Measurement_Stop()   //获得上一次BP测量结果  0x79 0x01 0x00指令
{
	u8 BP_Measurement_LEN =5;
	BP_SEND_DATA [1]=0X79;
	BP_SEND_DATA [2]=0X01;
	BP_SEND_DATA [3]=0X00;
	BP_SEND_DATA [4]=0X4C;
	USART2_DMA_Send_Once_Data(BP_SEND_DATA,BP_Measurement_LEN);
}	
/*获得上一次BP测量结果*/
void Get_BP_Measurement_Result()  //获得上一次BP测量结果  0x79 0x03 0x00指令
{
	u8 BP_Measurement_LEN =5;
	BP_SEND_DATA [1]=0X79;
	BP_SEND_DATA [2]=0X03;
	BP_SEND_DATA [3]=0X00;
	BP_SEND_DATA [4]=0X4A;
	USART2_DMA_Send_Once_Data(BP_SEND_DATA,BP_Measurement_LEN);
}
/*获得当前袖带压力*/
void Get_BP_Cuff_Pressure()  //获得当前袖带压力 0x79 0x05 0x00指令
{
	u8 BP_Measurement_LEN =5;
	BP_SEND_DATA [1]=0X79;
	BP_SEND_DATA [2]=0X05;
	BP_SEND_DATA [3]=0X00;
	BP_SEND_DATA [4]=0X48;
	USART2_DMA_Send_Once_Data(BP_SEND_DATA,BP_Measurement_LEN);
}

void BP_Cuff_Start()   //带袖带压力和数据报告开始成人模式BP 0x56指令 
{
	u8 BP_Measurement_LEN =3;
	BP_SEND_DATA[1]=0X56;
	BP_SEND_DATA[2]=0X70;//获取主机发送校验码  70
	USART2_DMA_Send_Once_Data(BP_SEND_DATA,BP_Measurement_LEN);
}

u8 BP_Sleep_Mode(u8 SleepMode) // 0X01进入休眠模式 0X00退出休眠模式  0x81指令
{
	u8 BP_Measurement_LEN =7;
	BP_SEND_DATA [1]=0X81;
	BP_SEND_DATA [2]=0X00;
	BP_SEND_DATA [3]=0X00;
	BP_SEND_DATA [4]=0X00;
	BP_SEND_DATA [5]=SleepMode;
	BP_SEND_DATA [6]=usart2_checkout_master(&BP_SEND_DATA[0],BP_Measurement_LEN-1);
	USART2_DMA_Send_Once_Data(BP_SEND_DATA,BP_Measurement_LEN);
}

void BP_Reset()  //复位模块处理器
{
	u8 BP_Measurement_LEN =3;
	BP_SEND_DATA [1]=0X8A;
	BP_SEND_DATA [2]=0X3C;
}

void BP_Status() //模块状态监测
{
	u8 BP_Measurement_LEN =5;
	BP_SEND_DATA [1]=0X79;
	BP_SEND_DATA [2]=0X11;
	BP_SEND_DATA [2]=0X00;
	BP_SEND_DATA [2]=0X3C;
}
/*从机指令检测*/
/*检测是否为O-packet */
u8 Is_O_Packet(u8 *USART_RECEIVE_DATA)
{
	if((unsigned short)USART_RECEIVE_DATA[3]==0x6F) //检测校验和
	{
		if((unsigned short)USART_RECEIVE_DATA[2]==0x4F) //'O'
		{
			if((unsigned short)USART_RECEIVE_DATA[1]==0x04) //数据字节
			{
				if((unsigned short)USART_RECEIVE_DATA[0]==0x3E) //帧头
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

/*检测是否为K-packet */
u8 Is_K_Packet(u8 *USART_RECEIVE_DATA)
{
	if((unsigned short)USART_RECEIVE_DATA[3]==0x73) //检测校验和
	{
		if((unsigned short)USART_RECEIVE_DATA[2]==0x4B) //'K'
		{
			if((unsigned short)USART_RECEIVE_DATA[1]==0x04) //数据字节
			{
				if((unsigned short)USART_RECEIVE_DATA[0]==0x3E) //帧头
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

/*检测是否为B-packet */
u8 Is_B_Packet(u8 *USART_RECEIVE_DATA)
{
	if((unsigned short)USART_RECEIVE_DATA[3]==0x7C) //检测校验和
	{
		if((unsigned short)USART_RECEIVE_DATA[2]==0x42) //'B'
		{
			if((unsigned short)USART_RECEIVE_DATA[1]==0x04) //数据字节
			{
				if((unsigned short)USART_RECEIVE_DATA[0]==0x3E) //帧头
				{
					return 1;
				}
			}
		}
	}
	return 0;
}
/*检测是否为A-packet */
u8 Is_A_Packet(u8 *USART_RECEIVE_DATA)
{
	if((unsigned short)USART_RECEIVE_DATA[3]==0x7D) //检测校验和
	{
		if((unsigned short)USART_RECEIVE_DATA[2]==0x41) //'A'
		{
			if((unsigned short)USART_RECEIVE_DATA[1]==0x04) //数据字节
			{
				if((unsigned short)USART_RECEIVE_DATA[0]==0x3E) //帧头
				{
					return 1;
				}
			}
		}
	}
	return 0;
}
/*检测是否为S-packet */
u8 Is_S_Packet(u8 *USART_RECEIVE_DATA)
{
	if((unsigned short)USART_RECEIVE_DATA[3]==0x6B) //检测校验和
	{
		if((unsigned short)USART_RECEIVE_DATA[2]==0x53) //'S'
		{
			if((unsigned short)USART_RECEIVE_DATA[1]==0x04) //数据字节
			{
				if((unsigned short)USART_RECEIVE_DATA[0]==0x3E) //帧头
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

