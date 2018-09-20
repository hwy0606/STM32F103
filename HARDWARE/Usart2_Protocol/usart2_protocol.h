#ifndef __USART2_PROTOCOL_H
#define __USART2_PROTOCOL_H 


#include "sys.h"


void USART2_Sensor_Init();
/* 主机函数 */

void BP_Measurement_Start();  //MASTER 成人BP测量
void BP_Measurement_Stop();
void Get_BP_Measurement_Result();
void Get_BP_Cuff_Pressure();
void BP_Cuff_Start();
u8 BP_Sleep_Mode(u8 SleepMode);
void BP_Reset();  //复位模块处理器
void BP_Status(); //模块状态监测

/* 从机函数 */

u8 Is_O_Packet(u8 *USART_RECEIVE_DATA);
u8 Is_K_Packet(u8 *USART_RECEIVE_DATA);
u8 Is_B_Packet(u8 *USART_RECEIVE_DATA);
u8 Is_A_Packet(u8 *USART_RECEIVE_DATA);
u8 Is_S_Packet(u8 *USART_RECEIVE_DATA);

#endif