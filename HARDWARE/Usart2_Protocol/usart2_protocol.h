#ifndef __USART2_PROTOCOL_H
#define __USART2_PROTOCOL_H 


#include "sys.h"


void USART2_Sensor_Init();
/* �������� */

void BP_Measurement_Start();  //MASTER ����BP����
void BP_Measurement_Stop();
void Get_BP_Measurement_Result();
void Get_BP_Cuff_Pressure();
void BP_Cuff_Start();
u8 BP_Sleep_Mode(u8 SleepMode);
void BP_Reset();  //��λģ�鴦����
void BP_Status(); //ģ��״̬���

/* �ӻ����� */

u8 Is_O_Packet(u8 *USART_RECEIVE_DATA);
u8 Is_K_Packet(u8 *USART_RECEIVE_DATA);
u8 Is_B_Packet(u8 *USART_RECEIVE_DATA);
u8 Is_A_Packet(u8 *USART_RECEIVE_DATA);
u8 Is_S_Packet(u8 *USART_RECEIVE_DATA);

#endif