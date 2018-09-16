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


void BP_Measurement()  //MASTER 成人BP测量
{
	BP_SEND_DATA[1]=0x20;
	BP_SEND_DATA[2]=usart2_checkout_master(&BP_SEND_DATA[0],BP_Measurement_LEN-1);//获取主机发送校验码  A6
	USART2_DMA_Send_Once_Data(BP_SEND_DATA,BP_Measurement_LEN);
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
		if((unsigned short)USART_RECEIVE_DATA[2]==0x42) //'P'
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