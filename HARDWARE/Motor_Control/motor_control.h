#ifndef __MOTOR_CONTROL_H
#define __MOTOR_CONTROL_H
#include "sys.h"
#include "project_config.h"

void Motor_Init();
#ifdef USE_MOTOR_CONTROL1
void Motor1_Break(void);
void Motor1_Positive(int Duty_Cycle); //占空比给1-100
void Motor1_Negative(int Duty_Cycle); //占空比给1-100
#endif

#ifdef USE_MOTOR_CONTROL2
void Motor2_Break(void);
void Motor2_Positive(int Duty_Cycle); //占空比给1-100
void Motor2_Negative(int Duty_Cycle); //占空比给1-100
#endif
		 				    
#endif