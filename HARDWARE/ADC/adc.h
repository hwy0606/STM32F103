#ifndef __ADC_H
#define __ADC_H	

#include "sys.h"
#include "project_config.h"

#ifdef USE_PA0_ADC1_IN0
void ADC_Sensor_Init(void);

u16 Average(); //取平均值函数

#endif
#endif 
