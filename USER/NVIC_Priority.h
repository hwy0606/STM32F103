/////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//中断优先级配置
//HWY 2018 10 17
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 

/*USART1 串口1*/
#define USART1_IRQ_PreemptionPriority 1
#define USART1_IRQ_SubPriority        1
#define USART1_DMA_PreemptionPriority 1
#define USART1_DMA_SubPriority        1

/*USART2 串口2*/
#define USART2_IRQ_PreemptionPriority 1
#define USART2_IRQ_SubPriority        1
#define USART2_DMA_PreemptionPriority 1
#define USART2_DMA_SubPriority        1

/*USART3 串口3*/
#define USART3_IRQ_PreemptionPriority 1
#define USART3_IRQ_SubPriority        1
#define USART3_DMA_PreemptionPriority 1
#define USART3_DMA_SubPriority        1

/*UART5 串口5*/
#define USART5_IRQ_PreemptionPriority 1
#define USART5_IRQ_SubPriority        1

/*KEY 按键*/
#define PB1_KEY_PreemptionPriority 1
#define PB1_KEY_SubPriority        1

#define PB2_KEY_PreemptionPriority 1
#define PB2_KEY_SubPriority        1

#define ELSE_KEY_PreemptionPriority 1
#define ELSE_KEY_SubPriority        1

#define PB11_KEY_PreemptionPriority 1
#define PB11_KEY_SubPriority        1

/* Hall 霍尔传感器 */
#define PC0_HALL_PreemptionPriority 1
#define PC0_HALL_SubPriority        1

