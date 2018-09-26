//////////////////////////////////////////////////
//STM32F103RCT6
//串口1通信协议
//HWY 2018 9 14
//All rights reserved									  
////////////////////////////////////////////////// 
#include "usart1_protocol.h"
#include "usart1_dma.h"
#include "crc_16.h"
#include "project_config.h"
/*
总体通信协议框架
帧头：0x5A; 1位
数据长度： 一个数据包的总长度；1位
数据类型码：0x01-0x03; 1位
有效数据：n位
校验码：CRC16校验；2位
*/
/*第一部分 按键通信协议*/
/*数据长度 0x07*/
/*数据类型码 0x01*/
/*有效数据 0x01-0x0A*/ 
#define Send_Size_Key  6
u8 Send_Date_Key[Send_Size_Key];

void USART1_Key_Init()
{
  Send_Date_Key[0]=0x5A; //帧头
	Send_Date_Key[1]=0x06; //数据长度
	Send_Date_Key[2]=0x01; //数据类型码
	Send_Date_Key[3]=0xFF; //有效数据
	Send_Date_Key[4]=0x00; //CRC校验码低8位
	Send_Date_Key[5]=0x00; //CRC校验码高8位
}


#ifdef USE_PA1_KEY
inline void KEY1_Response()
{
	Send_Date_Key[3]=0x01; //有效数据
	//启动CRC校验
	usMBCRC16(Send_Date_Key,Send_Size_Key-2);
	Send_Date_Key[4]=Get_ucCRCLo(); //CRC校验码低8位
	Send_Date_Key[5]=Get_ucCRCHi(); //CRC校验码高8位
	//启动传输
	USART1_DMA_Send_Once_Data(Send_Date_Key,Send_Size_Key);	
}
#endif

#ifdef USE_PD2_KEY
void KEY2_Response()
{
	Send_Date_Key[3]=0x02; //有效数据
	//启动CRC校验
	usMBCRC16(Send_Date_Key,Send_Size_Key-2);
	Send_Date_Key[4]=Get_ucCRCLo(); //CRC校验码低8位
	Send_Date_Key[5]=Get_ucCRCHi(); //CRC校验码高8位
	//启动传输
	USART1_DMA_Send_Once_Data(Send_Date_Key,Send_Size_Key);	
}
#endif

#ifdef USE_PC3_KEY
void KEY3_Response()
{
	Send_Date_Key[3]=0x03; //有效数据
	//启动CRC校验
	usMBCRC16(Send_Date_Key,Send_Size_Key-2);
	Send_Date_Key[4]=Get_ucCRCLo(); //CRC校验码低8位
	Send_Date_Key[5]=Get_ucCRCHi(); //CRC校验码高8位
	//启动传输
	USART1_DMA_Send_Once_Data(Send_Date_Key,Send_Size_Key);	
}
#endif

#ifdef USE_PC4_KEY
void KEY4_Response()
{
	Send_Date_Key[3]=0x04; //有效数据
	//启动CRC校验
	usMBCRC16(Send_Date_Key,Send_Size_Key-2);
	Send_Date_Key[4]=Get_ucCRCLo(); //CRC校验码低8位
	Send_Date_Key[5]=Get_ucCRCHi(); //CRC校验码高8位
	//启动传输
	USART1_DMA_Send_Once_Data(Send_Date_Key,Send_Size_Key);	
}
#endif

#ifdef USE_PC5_KEY
void KEY5_Response()
{
	Send_Date_Key[3]=0x05; //有效数据
	//启动CRC校验
	usMBCRC16(Send_Date_Key,Send_Size_Key-2);
	Send_Date_Key[4]=Get_ucCRCLo(); //CRC校验码低8位
	Send_Date_Key[5]=Get_ucCRCHi(); //CRC校验码高8位
	//启动传输
	USART1_DMA_Send_Once_Data(Send_Date_Key,Send_Size_Key);	
}
#endif

#ifdef USE_PC6_KEY
void KEY6_Response()
{
	Send_Date_Key[3]=0x06; //有效数据
	//启动CRC校验
	usMBCRC16(Send_Date_Key,Send_Size_Key-2);
	Send_Date_Key[4]=Get_ucCRCLo(); //CRC校验码低8位
	Send_Date_Key[5]=Get_ucCRCHi(); //CRC校验码高8位
	//启动传输
	USART1_DMA_Send_Once_Data(Send_Date_Key,Send_Size_Key);	
}
#endif

#ifdef USE_PC7_KEY
void KEY7_Response()
{
	Send_Date_Key[3]=0x07; //有效数据
	//启动CRC校验
	usMBCRC16(Send_Date_Key,Send_Size_Key-2);
	Send_Date_Key[4]=Get_ucCRCLo(); //CRC校验码低8位
	Send_Date_Key[5]=Get_ucCRCHi(); //CRC校验码高8位
	//启动传输
	USART1_DMA_Send_Once_Data(Send_Date_Key,Send_Size_Key);	
}
#endif

#ifdef USE_PC8_KEY
void KEY8_Response()
{
	Send_Date_Key[3]=0x08; //有效数据
	//启动CRC校验
	usMBCRC16(Send_Date_Key,Send_Size_Key-2);
	Send_Date_Key[4]=Get_ucCRCLo(); //CRC校验码低8位
	Send_Date_Key[5]=Get_ucCRCHi(); //CRC校验码高8位
	//启动传输
	USART1_DMA_Send_Once_Data(Send_Date_Key,Send_Size_Key);	
}
#endif

#ifdef USE_PC9_KEY
void KEY9_Response()
{
	Send_Date_Key[3]=0x09; //有效数据
	//启动CRC校验
	usMBCRC16(Send_Date_Key,Send_Size_Key-2);
	Send_Date_Key[4]=Get_ucCRCLo(); //CRC校验码低8位
	Send_Date_Key[5]=Get_ucCRCHi(); //CRC校验码高8位
	//启动传输
	USART1_DMA_Send_Once_Data(Send_Date_Key,Send_Size_Key);	
}
#endif

/*第二部分 血压通信协议*/
/*数据长度 0x*/
/*数据类型码 0x02*/
//所有收到的数据原封不动的转发 收到信息立刻转发
u8 Is_BP_Order(u8 *USART_RECEIVE_DATA) //判断是不是血压指令 帧头和0x02数据类型码 不做CRC校验了
{
	if(((unsigned short)USART_RECEIVE_DATA[2]==0X02)) //数据类型码
	{
	if(((unsigned short)USART_RECEIVE_DATA[0]==0XA5))
	{
		return 1;
	}
	}
	return 0;
}
/*将串口2收到的数据 原封不动的通过串口1发送回去 */
extern u8 USART2_BP_DATA[32];

void USART1_BP_Response(u8 *USART1_RECEIVE_DATA,u16 DATA_LEN)
{
	USART2_BP_DATA[0]=0x5A;
	USART2_BP_DATA[1]=DATA_LEN+0x05;
	USART2_BP_DATA[2]=0X02;
	for(int i=0;i<DATA_LEN;i++)
	{
		USART2_BP_DATA[3+i]=USART1_RECEIVE_DATA[i];
	}
	//启动CRC校验
	usMBCRC16(USART2_BP_DATA,DATA_LEN+0x03);
	USART2_BP_DATA[DATA_LEN+0x03]=Get_ucCRCLo(); //CRC校验码低8位
	USART2_BP_DATA[DATA_LEN+0x04]=Get_ucCRCHi(); //CRC校验码高8位	
	USART1_DMA_Send_Once_Data(USART2_BP_DATA,DATA_LEN+0x05);	
}


/*第三部分 血氧通信协议*/
/*数据长度 0x0A*/
/*数据类型码 0x03*/
extern u8 SPO2_DATA[SPO2_DATA_LEN]; //直接用全局变量 不做传址
extern u8 SPO2_FLAG; //血氧信息更新标志位
void SPO2_Response()
{ 
	//此处做一个CRC校验然后发送，发送完成后复位SPO2_FLAG标志位
	usMBCRC16(SPO2_DATA,SPO2_DATA_LEN-2);
  SPO2_DATA[8]=Get_ucCRCLo();//CRC校验码低8位
	SPO2_DATA[9]=Get_ucCRCHi(); //CRC校验码高8位	
	//发送两遍
	USART1_DMA_Send_Once_Data(SPO2_DATA,SPO2_DATA_LEN);
	USART1_DMA_Send_Once_Data(SPO2_DATA,SPO2_DATA_LEN);
  SPO2_FLAG=0;	
}

/*第四部分 速度通信协议*/
/*数据长度 0x07*/ 
/*有效数据 2位 */
/*数据类型码 0x04*/
extern float motor_speed;//速度
u8 SPEED_DATA[SPEED_DATA_LEN];
void USART1_Speed_Init()
{
	SPEED_DATA[0]=0x5A;
	SPEED_DATA[1]=SPEED_DATA_LEN;	
	SPEED_DATA[2]=0x04;
	
}
void Speed_Response()
{
	SPEED_DATA[3]=(unsigned char)(((u16)(motor_speed) & 0xFF00)>>8);	
	SPEED_DATA[4]=(unsigned char)(u16)(motor_speed)&0x00FF;
	usMBCRC16(SPEED_DATA,SPEED_DATA_LEN-2);
  SPEED_DATA[5]=Get_ucCRCLo();//CRC校验码低8位
	SPEED_DATA[6]=Get_ucCRCHi(); //CRC校验码高8位
	USART1_DMA_Send_Once_Data(SPEED_DATA,SPEED_DATA_LEN);	
}
u8 Is_Speed_Order(u8 *USART_RECEIVE_DATA) //判断是不是速度指令 帧头和0x02数据类型码 不做CRC校验了
{
	if(((unsigned short)USART_RECEIVE_DATA[2]==0X04)) //数据类型码
	{
	if(((unsigned short)USART_RECEIVE_DATA[0]==0XA5))
	{
		return 1;
	}
	}
	return 0;
}
