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
#define USART1_BaudRate 115200
#define USART2_BaudRate 115200
#define USART3_BaudRate 115200

/*USART1 相关宏定义 */
/* UART1 GPIO define. */            //宏定义
#define USART1_GPIO_TX       		   GPIO_Pin_9
#define USART1_GPIO_RX       		   GPIO_Pin_10
#define USART1_GPIO_TX_PinSource       GPIO_PinSource9
#define USART1_GPIO_RX_PinSource       GPIO_PinSource10
#define USART1_GPIO          		   GPIOA
#define USART1_GPIO_RCC      		   RCC_APB2Periph_GPIOA
#define USART1_DATA_LEN  64  //接收和发送数据的最大长度
/*USART2 相关宏定义 */
/* UART2 GPIO define. */
#define USART2_GPIO_TX       		   GPIO_Pin_2
#define USART2_GPIO_RX       		   GPIO_Pin_3
#define USART2_GPIO_TX_PinSource   GPIO_PinSource2
#define USART2_GPIO_RX_PinSource   GPIO_PinSource3
#define USART2_GPIO          		   GPIOA
#define USART2_GPIO_RCC      		   RCC_APB2Periph_GPIOA
#define USART2_DATA_LEN  64  //接收和发送数据的最大长度
/*USART3 相关宏定义 */
/* UART3 GPIO define. */
#define USART3_GPIO_TX       		   GPIO_Pin_10
#define USART3_GPIO_RX       		   GPIO_Pin_11
#define USART3_GPIO_TX_PinSource   GPIO_PinSource10
#define USART3_GPIO_RX_PinSource   GPIO_PinSource11
#define USART3_GPIO          		   GPIOB
#define USART3_GPIO_RCC      		   RCC_APB2Periph_GPIOB
#define USART3_DATA_LEN  64  //接收和发送数据的最大长度


//PWM 默认TIM4
#define USE_PWM_CH1
#define USE_PWM_CH2
//#define USE_PWM_CH3
//#define USE_PWM_CH4

/*PWM相关宏定义*/
#define PWM_CH1_GPIO     GPIO_Pin_6
#define PWM_CH2_GPIO     GPIO_Pin_7
#define PWM_CH3_GPIO     GPIO_Pin_8
#define PWM_CH4_GPIO     GPIO_Pin_9
#define PWM_GPIO_RCC     RCC_APB2Periph_GPIOB
#define PWM_TIM_RCC      RCC_APB1Periph_TIM4
#define PWM_AFIO_RCC     RCC_APB2Periph_AFIO
#define PWM_GPIO         GPIOB
#define PWM_TIM          TIM4

//默认使用PWM频率 100Khz
#define PWM_Frequency 100
#define PWM_ARR  (72000/PWM_Frequency)-1
#define PWM_PSC 0 //不分频

//CRC校验方法 默认只能定义一种 可使用硬件CRC 或者 查表法软件CRC

//ps: 目前只写了软件CRC方法 硬件CRC暂时不可用
//#define USE_CRC_HARDWARE
#define USE_CRC_SOFTWARE

//按键8个 预留两个 总共驱动10个按键引脚
#define USE_PA0_KEY
#define USE_PA1_KEY
//#define USE_PD2_KEY 
#define USE_PC3_KEY
#define USE_PC4_KEY
#define USE_PC5_KEY
#define USE_PC6_KEY
#define USE_PC7_KEY
//#define USE_PC8_KEY
//#define USE_PC9_KEY

//数码管

//上位机通信 USART1_PROTOCOL
/* 第一部分按键信号由按键中断直接发送*/

/* 第三部分血氧信息放在主循环中空闲时发送，更新频率1HZ，实际每次更新后连续发送两遍*/ 
//血压模块   USART2_PROTOCOL

//血氧模块   USARAT3_PROTOCOL
/* */
#define SPO2_DATA_LEN 10


