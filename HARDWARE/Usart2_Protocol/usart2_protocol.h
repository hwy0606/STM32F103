#ifndef __USART2_PROTOCOL_H
#define __USART2_PROTOCOL_H 


#include "sys.h"


void USART2_Sensor_Init();
/* �������� */

void BP_Measurement();  //MASTER ����BP����



/* �ӻ����� */

u8 Is_O_Packet(u8 *USART_RECEIVE_DATA);
u8 Is_K_Packet(u8 *USART_RECEIVE_DATA);
u8 Is_B_Packet(u8 *USART_RECEIVE_DATA);
#endif