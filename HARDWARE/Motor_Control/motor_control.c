#include "motor_control.h"
#include "pwm.h"
#include "gpio.h"
//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//���������س���
//������
//HWY 2018 9 15
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	    

/*
����������ư�1 �綯�Ƹ�ʹ��
IN1 IN2 PWM ���
 0   0   ��  ɲ��
 1   0  PWM ��ת
 0   1  PWM ��ת
*/ 

/*��֧��C99��׼ */
#if defined (USE_ACTUATOR_CONTROL)  && defined(USE_PWM_CH3) && defined(USE_ACTUATOR_GPIO)
void Actuator_Init()
{
	ACTUATOR_GPIO_Init();
	PWM_Init_Default();
}

void Actuator_Break(void)
{
  ACTUATOR_IN1=0;
	ACTUATOR_IN2=0;
	Set_PWM_CH3_Duty_Cycle(5);//ռ�ձ����		
	
}

void Actuator_Positive(int Duty_Cycle) //ռ�ձȸ�1-100
{
  ACTUATOR_IN1=1;
	ACTUATOR_IN2=0;
	Set_PWM_CH3_Duty_Cycle(Duty_Cycle);
}

void Actuator_Negative(int Duty_Cycle) //ռ�ձȸ�1-100
{
  ACTUATOR_IN1=0;
	ACTUATOR_IN2=1;
	Set_PWM_CH3_Duty_Cycle(Duty_Cycle);
}
#endif


/*
����������ư�2  ���ÿ�����ʹ��
IN1 IN2 PWM ���
 0   0   ��  ɲ��
 1   0  PWM ��ת
 0   1  PWM ��ת
*/ 


#if defined (USE_BACKUP_CONTROL)  && defined(USE_PWM_CH4) && defined(USE_BACKUP_GPIO)
void Backup_Init()
{
	BACKUP_GPIO_Init();
	PWM_Init_Default();
}
void Backup_Break(void)
{
  BACKUP_IN1=0;
	BACKUP_IN2=0;
	Set_PWM_CH4_Duty_Cycle(5);//ռ�ձ����		
	
}

void Backup_Positive(int Duty_Cycle) //ռ�ձȸ�1-100
{
  BACKUP_IN1=1;
	BACKUP_IN2=0;
	Set_PWM_CH4_Duty_Cycle(Duty_Cycle);
}

void Backup_Negative(int Duty_Cycle) //ռ�ձȸ�1-100
{
  BACKUP_IN1=0;
	BACKUP_IN2=1;
	Set_PWM_CH4_Duty_Cycle(Duty_Cycle);
}

#endif