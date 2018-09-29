/////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//工程配置文件
//HWY 2018 09 13
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////////////////// 
//串口DMA S使用和配置 
#define USE_USART1_DMA
#define USE_USART2_DMA
#define USE_USART3_DMA
#define USE_USART5_DMA
#define USART1_BaudRate 115200
#define USART2_BaudRate 115200
#define USART3_BaudRate 115200
#define USART5_BaudRate 115200
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
#define USART3_GPIO          		   GPIOC
#define USART3_GPIO_RCC      		   RCC_APB2Periph_GPIOC
#define USART3_DATA_LEN  64  //接收和发送数据的最大长度
/*USART5 相关宏定义 */
/* UART5 GPIO define. */
#define USART5_GPIO_TX       		   GPIO_Pin_12
#define USART5_GPIO_RX       		   GPIO_Pin_2
#define USART5_GPIO_TX_PinSource   GPIO_PinSource12
#define USART5_GPIO_RX_PinSource   GPIO_PinSource2
#define USART5_TX_GPIO          		GPIOC
#define USART5_RX_GPIO          		GPIOD
#define USART5_GPIO_RCC      		   RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD
#define USART5_DATA_LEN  64  //接收和发送数据的最大长度

//////////////////////////////////////////////////////////////////////////////////
//PWM 默认TIM4

#define USE_PWM_CH3
#define USE_PWM_CH4

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

//默认使用PWM频率 100Khz 更改PWM占空比后需要修改Set_PWM_CHx_Duty_Cycle函数
#define PWM_Frequency 100
#define PWM_ARR  (72000/PWM_Frequency)-1
#define PWM_PSC 0 //不分频

//500HZ频率测试
//#define PWM_ARR  20000-1
//#define PWM_PSC  10000-1

//CRC校验方法 默认只能定义一种 可使用硬件CRC 或者 查表法软件CRC

//ps: 目前只写了软件CRC方法 硬件CRC暂时不可用
//#define USE_CRC_HARDWARE
#define USE_CRC_SOFTWARE

//按键8个  PB2按键可能有点问题，BOOT1引脚 
#define USE_PB1_KEY
//#define USE_PB2_KEY 
#define USE_PC6_KEY
#define USE_PC7_KEY
#define USE_PC8_KEY
#define USE_PC9_KEY
#define USE_PB10_KEY
#define USE_PB11_KEY


//GPIO OUTPUT
/*所有输出通过sys.h文件定义位带操作*/
/*以太网模块*/
/* CFG-PA1 RST-PA4*/
#define USE_INTERNET_GPIO
/*血压模块*/
/*RESET-PA14*/
#define USE_BP_GPIO
/*血氧模块*/
/*SLEEP-PA15*/
#define USE_SPO2_GPIO
/*备用控制器*/
/* IN1-PB3 IN2-PA13*/
#define USE_BACKUP_GPIO
/*MOTOR控制 PB4*/
#define USE_MOTOR_GPIO
/*LED PB5*/
#define USE_LED_GPIO
/*电动推杆 */
/*IN1-PB6 IN2-PB7*/
#define USE_ACTUATOR_GPIO

/*245输出使能 PC2 低电平有效*/
#define USE_OE_GPIO

#ifdef USE_INTERNET_GPIO
#define  INTERNET_GPIO_RCC RCC_APB2Periph_GPIOA
#define  CFG_GPIO_PA1 GPIO_Pin_1
#define  RST_GPIO_PA4 GPIO_Pin_4
#define  INTERNET_GPIO         GPIOA
#define  INTERNET_CFG PAout(1)	// PA1
#define  INTERNET_RST PAout(4)	// PA4
#endif

#ifdef USE_BP_GPIO
#define BP_GPIO_RCC RCC_APB2Periph_GPIOA
#define RESET_GPIO_PA14 GPIO_Pin_14
#define BP_GPIO         GPIOA
#define BP_RESET PAout(14)	// PA14
#endif

#ifdef USE_SPO2_GPIO
#define SPO2_GPIO_RCC RCC_APB2Periph_GPIOA
#define SLEEP_GPIO_PA15 GPIO_Pin_15
#define SPO2_GPIO         GPIOA
#define SPO2_SLEEP PAout(15)	// PA15
#endif


#ifdef USE_BACKUP_GPIO
#define BACKUP_GPIO_RCC RCC_APB2Periph_GPIOA |RCC_APB2Periph_GPIOB
#define BACKUP_GPIO_PB3 GPIO_Pin_3
#define BACKUP_GPIO_PA13 GPIO_Pin_13
#define BACKUP_IN1_GPIO         GPIOB
#define BACKUP_IN2_GPIO         GPIOA
#define BACKUP_IN1 PBout(3)	  // PB3
#define BACKUP_IN2 PAout(13)	// PA13
#endif

#ifdef USE_MOTOR_GPIO
#define MOTOR_GPIO_RCC RCC_APB2Periph_GPIOB
#define MOTOR_GPIO_PB4 GPIO_Pin_4
#define MOTOR_GPIO         GPIOB
#define MOTOR PBout(4)	  // PB4
#endif

#ifdef USE_LED_GPIO
#define  LED_GPIO_RCC RCC_APB2Periph_GPIOB
#define  LED_GPIO_PB5 GPIO_Pin_5
#define  LED_GPIO         GPIOB
#define LED PBout(5)	// PB5
#endif

#ifdef USE_ACTUATOR_GPIO
#define ACTUATOR_GPIO_RCC RCC_APB2Periph_GPIOB
#define ACTUATOR_GPIO_PB6 GPIO_Pin_6
#define ACTUATOR_GPIO_PB7 GPIO_Pin_7
#define ACTUATOR_GPIO         GPIOB
#define ACTUATOR_IN1 PBout(6)	  // PB6
#define ACTUATOR_IN2 PBout(7)	  // PB7
#endif

#ifdef USE_OE_GPIO
#define  OE_GPIO_RCC RCC_APB2Periph_GPIOC
#define  OE_GPIO_PC2 GPIO_Pin_2
#define  OE_GPIO         GPIOC
#define  OE PCout(2)	// PC2
#endif

//电机控制板驱动
#define USE_ACTUATOR_CONTROL
#define USE_BACKUP_CONTROL

//上位机通信 USART1_PROTOCOL
/* 第一部分按键信号由按键中断直接发送*/
/* 第三部分血氧信息放在主循环中空闲时发送，更新频率1HZ，实际每次更新发送*/ 
//血氧模块   USARAT5_PROTOCOL
/* */
#define SPO2_DATA_LEN 10


//Hall_Sensor
#define USE_PC0_HALL_IPD
#define HALL_MAGNET_AMOUNT 3
#define HALL_SPEED_CONST 60*10000/HALL_MAGNET_AMOUNT
#define SPEED_DATA_LEN  0x07

//ADC 转矩输入
/*注意选择采样时间 牺牲转换速率 */
/*可供选择采样时间 55.5 71.5 239.5 */
#define USE_PA0_ADC1_IN0
#define ADC_RCC RCC_APB2Periph_GPIOA | RCC_APB2Periph_ADC1 
#define DMA_RCC RCC_AHBPeriph_DMA1
#define ADC_GPIO_PA0 GPIO_Pin_0
#define ADC_GPIO GPIOA
#define ADC_BUFx_LEN		      7
#define ADC_BUF_LEN         1*ADC_BUFx_LEN 		

//数码管  SPI 7277芯片
/*   BC727X驱动使用SPI2口      */
/*   PB12 --- CS                */
/*   PB13 --- SCK               */
/*   PB14 --- MISO              */
/*   PB15 --- MOSI              */

/* BC727X 指令（寄存器地址）*/
#define SEG_BLINK_CTL       0x10    // 断闪烁控制寄存器起始地址
#define DIG_BLINK_CTL_L     0x18    // 0-7位闪烁控制寄存器起始地址
#define DIG_BLINK_CTL_H     0x19    // 8-15位闪烁控制寄存器起始地址
#define BLINK_SPEED         0x1A    // 闪烁速度控制寄存器地址
#define DECODE_HEX          0x1b    // 16进制显示译码寄存器地址
#define DECODE_SEG          0x1c    // 段寻址译码寄存器地址
#define WRITE_ALL           0x1d    // 全局操作寄存器地址
#define DUMMY_CMD           0xff    // 假指令

#define USE_SPI_7277
#define SPI_GPIO_RCC  RCC_APB2Periph_GPIOB
#define SPI_RCC RCC_APB1Periph_SPI2
#define SPI_GPIO GPIOB
#define SPI_CS GPIO_Pin_12
#define SPI_SCK GPIO_Pin_13
#define SPI_MISO GPIO_Pin_14
#define SPI_MOSI GPIO_Pin_15
#define CS PBout(12)	// PB12