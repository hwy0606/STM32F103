#ifndef __GPIO_H
#define __GPIO_H	 

#include "sys.h"
#include "project_config.h"


#ifdef USE_INTERNET_GPIO
void Internet_GPIO_Init();
#endif

#ifdef USE_BP_GPIO
void BP_RESET_Init();
#endif

#ifdef USE_SPO2_GPIO
void SPO2_SLEEP_Init();
#endif

#ifdef USE_BACKUP_GPIO
void BACKUP_GPIO_Init();
#endif

#ifdef USE_MOTOR_GPIO
void MOTOR_GPIO_Init();
#endif

#ifdef USE_LED_GPIO
void LED_GPIO_Init(void);
#endif

#ifdef USE_ACTUATOR_GPIO
void ACTUATOR_GPIO_Init(void);
#endif

#ifdef USE_OE_GPIO
void OE_GPIO_Init(void);
#endif

#endif