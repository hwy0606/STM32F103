#ifndef __USART2_PROTOCOL_H
#define __USART2_PROTOCOL_H 


#include "sys.h"


void USART2_Sensor_Init();
/* 主机函数 */

void BP_Measurement();  //MASTER 成人BP测量



/* 从机函数 */

u8 Is_O_Packet(u8 *USART_RECEIVE_DATA);
u8 Is_K_Packet(u8 *USART_RECEIVE_DATA);
u8 Is_B_Packet(u8 *USART_RECEIVE_DATA);
#endif