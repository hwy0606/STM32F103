#ifndef __GPIO_H
#define __GPIO_H	 
#include "sys.h"
#include "project_config.h"


#ifdef USE_MOTOR_GPIO
void Motor_GPIO_Init(void);
#endif

#ifdef USE_LED_GPIO
void LED_GPIO_Init(void);
#endif
		 				    
#endif