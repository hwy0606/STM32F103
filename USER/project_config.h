/////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//工程配置文件
//HWY 2018 09 13
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
//LED调试
#define USE_LED0
#define USE_LED1

//串口DMA
#define USE_USART1_DMA
#define USE_USART2_DMA
#define USE_USART3_DMA

//PWM 默认TIM4
#define USE_PWM_CH1
#define USE_PWM_CH2
//#define USE_PWM_CH3
//#define USE_PWM_CH4


//CRC校验方法 默认只能定义一种 可使用硬件CRC 或者 查表法软件CRC
#define USE_CRC_HARDWARE
#define USE_CRC_SOFTWARE

//按键8个 预留两个 总共驱动10个按键引脚
#define USE_PA0_KEY
#define USE_PA1_KEY
#define USE_PD2_KEY
#define USE_PB3_KEY
#define USE_PB4_KEY
#define USE_PB5_KEY

#define USE_PC8_KEY
#define USE_PC9_KEY

//数码管