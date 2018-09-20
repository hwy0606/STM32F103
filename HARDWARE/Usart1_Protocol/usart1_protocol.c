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

#ifdef USE_PA0_KEY
inline void KEY0_Response()
{
	Send_Date_Key[3]=0x00; //有效数据
	//启动CRC校验
	usMBCRC16(Send_Date_Key,Send_Size_Key-2);
	Send_Date_Key[4]=Get_ucCRCLo(); //CRC校验码低8位
	Send_Date_Key[5]=Get_ucCRCHi(); //CRC校验码高8位
	//启动传输
	USART1_DMA_Send_Once_Data(Send_Date_Key,Send_Size_Key);	
}
#endif

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
//所有收到的数据原封不动的转发



/*第三部分 血氧通信协议*/
/*数据长度 0x0A*/
/*数据类型码 0x03*/
extern u8 SPO2_DATA[SPO2_DATA_LEN]; //直接用全局变量 不做传址
extern u8 SPO2_FLAG;
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
