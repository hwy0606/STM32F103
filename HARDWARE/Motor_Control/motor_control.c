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
/*
������� IN1-MOTOR1_IN1-PB12 IN2-MOTOR1_IN2-PB13
         PWM-PWM_CH1_GPIO-PB6
*/

/*��֧��C99��׼ */
#if defined (USE_ACTUATOR_CONTROL)  && defined(USE_PWM_CH3) && defined(USE_ACTUATOR_GPIO)
void Motor_Init()
{
	Motor_GPIO_Init();
	PWM_Init_Default();
}
#endif 

#ifdef USE_MOTOR_CONTROL1
void BackUp_Init()
{
	
}
#endif 
#ifdef USE_MOTOR_CONTROL1
void Motor1_Break(void)
{
  MOTOR1_IN1=0;
	MOTOR1_IN2=0;
	Set_PWM_CH3_Duty_Cycle(5);//ռ�ձ����		
	
}

void Motor1_Positive(int Duty_Cycle) //ռ�ձȸ�1-100
{
  MOTOR1_IN1=1;
	MOTOR1_IN2=0;
	Set_PWM_CH3_Duty_Cycle(Duty_Cycle);
}

void Motor1_Negative(int Duty_Cycle) //ռ�ձȸ�1-100
{
  MOTOR1_IN1=0;
	MOTOR1_IN2=1;
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
/*
������� IN2-MOTOR2_IN1-PB14 IN2-MOTOR2_IN2-PB15
         PWM-PWM_CH2_GPIO-PB7
*/
#ifdef USE_MOTOR_CONTROL2
void Motor2_Break(void)
{
  MOTOR2_IN1=0;
	MOTOR2_IN2=0;
	Set_PWM_CH4_Duty_Cycle(5);//ռ�ձ����		
	
}

void Motor2_Positive(int Duty_Cycle) //ռ�ձȸ�1-100
{
  MOTOR2_IN1=1;
	MOTOR2_IN2=0;
	Set_PWM_CH4_Duty_Cycle(Duty_Cycle);
}

void Motor2_Negative(int Duty_Cycle) //ռ�ձȸ�1-100
{
  MOTOR2_IN1=0;
	MOTOR2_IN2=1;
	Set_PWM_CH4_Duty_Cycle(Duty_Cycle);
}

#endif