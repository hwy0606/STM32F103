#ifndef __USART1_PROTOCOL_H
#define __USART1_PROTOCOL_H 
#include "sys.h"
#include "project_config.h"

/*第一部分 按键通信协议*/
void USART1_Key_Init(); //按键传输协议初始化
//C99标准的可变数组只能在程序块定义 内存空间存储在栈空间中
#ifdef USE_PA0_KEY
void KEY0_Response();
#endif
#ifdef USE_PA1_KEY
void KEY1_Response();
#endif
#ifdef USE_PD2_KEY
void KEY2_Response();
#endif
#ifdef USE_PB3_KEY
void KEY3_Response();
#endif
#ifdef USE_PB4_KEY
void KEY4_Response();
#endif
#ifdef USE_PB5_KEY
void KEY5_Response();
#endif
#ifdef USE_PC6_KEY
void KEY6_Response();
#endif
#ifdef USE_PC7_KEY
void KEY7_Response();
#endif
#ifdef USE_PC8_KEY
void KEY8_Response();
#endif
#ifdef USE_PC9_KEY
void KEY9_Response();
#endif
void SPO2_Response();



void BP_O_response();
void BP_K_response();
void BP_Busy_response();
void BP_Abort_response();
void BP_Sleep_response();
void BP_Status_response(u8 *USART2_RECEIVE_DATA);
u8 BP_Measurement(u8 *USART1_RECEIVE_DATA);
#endif