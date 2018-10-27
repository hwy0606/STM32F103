STM32F103RCT6 Project


2018 10 17 11:00

内存管理 目前 MEM_MAX_SIZE			20*1024  						//最大管理内存 20K 
后期可进一步优化到42K的内存管理 

完成中断优先级的归整

2018 10 27 14:00
新建定时器 更新
确定每个按键的可能


定时器资源 ：TIM2 TIM4


3.5版本的库函数 清除串口IDLE中断库函数有问题 用
USARTX->SR;
USARTX->DR; 									//清USART_IT_IDLE标志 
清中断