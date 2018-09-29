STM32F103RCT6 Project






定时器资源 ：TIM2 TIM4


3.5版本的库函数 清除串口IDLE中断库函数有问题 用
USARTX->SR;
USARTX->DR; 									//清USART_IT_IDLE标志 
清中断