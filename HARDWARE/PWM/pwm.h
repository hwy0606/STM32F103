#ifndef __PWM_H
#define __PWM_H
#include "sys.h"
#include "project_config.h"


void PWM_Init(u16 arr,u16 psc);


#ifdef USE_PWM_CH1 || USE_PWM_CH2 ||USE_PWM_CH3 ||USE_PWM_CH4
void PWM_Init_Default();
#endif

#ifdef USE_PWM_CH1
void Set_PWM_CH1_Duty_Cycle(int Duty_Cycle);
#endif

#ifdef USE_PWM_CH2
void Set_PWM_CH2_Duty_Cycle(int Duty_Cycle);
#endif

#ifdef USE_PWM_CH3
void Set_PWM_CH3_Duty_Cycle(int Duty_Cycle);
#endif

#ifdef USE_PWM_CH4
void Set_PWM_CH4_Duty_Cycle(int Duty_Cycle);
#endif

#endif
