#include "motor_control.h"
#include "pwm.h"
#include "gpio.h"
//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//电机控制相关程序
//驱动层
//HWY 2018 9 15
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	    
static u16 seat_height; //座椅高度
u8 SEAT_FLAG=0x00; //座椅高度更新信息
u16 Get_Seat_Height()
{
	return seat_height;
}
void Set_Seat_Height(u16 height)
{
	seat_height=height;
}
/*
电机驱动控制板1 电动推杆使用
IN1 IN2 PWM 输出
 0   0   ×  刹车
 1   0  PWM 正转
 0   1  PWM 反转
*/ 

/*请支持C99标准 */
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
	Set_PWM_CH3_Duty_Cycle(5);//占空比随机			
}

void Actuator_Positive(int Duty_Cycle) //占空比给1-100
{
  ACTUATOR_IN1=1;
	ACTUATOR_IN2=0;
	Set_PWM_CH3_Duty_Cycle(Duty_Cycle);

}

void Actuator_Negative(int Duty_Cycle) //占空比给1-100
{
  ACTUATOR_IN1=0;
	ACTUATOR_IN2=1;
	Set_PWM_CH3_Duty_Cycle(Duty_Cycle);
}

void Seat_High()
{
	//座椅高度增加 实测



	//更新seat_height变量
	if(seat_height<0xFFFF)
	{
	seat_height=seat_height+0x01;
	}	
	//写入FLASH
	SEAT_FLAG=0x01;
}

void Seat_Low()
{
	//座椅高度降低  实测



	//更新seat_height变量
	if(seat_height>0x0000)
	{
	seat_height=seat_height-0x01;
	}
	//写入FLASH
	SEAT_FLAG=0x01;
}
#endif

/*
电机驱动控制板2  备用控制器使用
IN1 IN2 PWM 输出
 0   0   ×  刹车
 1   0  PWM 正转
 0   1  PWM 反转
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
	Set_PWM_CH4_Duty_Cycle(5);//占空比随机		
	
}

void Backup_Positive(int Duty_Cycle) //占空比给1-100
{
  BACKUP_IN1=1;
	BACKUP_IN2=0;
	Set_PWM_CH4_Duty_Cycle(Duty_Cycle);
}

void Backup_Negative(int Duty_Cycle) //占空比给1-100
{
  BACKUP_IN1=0;
	BACKUP_IN2=1;
	Set_PWM_CH4_Duty_Cycle(Duty_Cycle);
}

#endif