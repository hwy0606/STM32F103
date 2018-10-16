#ifndef __MOTOR_CONTROL_H
#define __MOTOR_CONTROL_H
#include "sys.h"
#include "project_config.h"

#if defined (USE_ACTUATOR_CONTROL)  && defined(USE_PWM_CH3) && defined(USE_ACTUATOR_GPIO)
void Actuator_Init();
void Actuator_Break(void);
void Actuator_Positive(int Duty_Cycle); //占空比给1-100
void Actuator_Negative(int Duty_Cycle); //占空比给1-100
void Seat_High();
void Seat_Low();

#endif

#if defined (USE_BACKUP_CONTROL)  && defined(USE_PWM_CH4) && defined(USE_BACKUP_GPIO)
void Backup_Init();
void Backup_Break(void);
void Backup_Positive(int Duty_Cycle); //占空比给1-100
void Backup_Negative(int Duty_Cycle); //占空比给1-100

#endif
		 				    
u16 Get_Seat_Height();
void Set_Seat_Height(u16 height);

#endif