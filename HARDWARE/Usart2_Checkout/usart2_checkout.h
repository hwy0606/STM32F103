#ifndef __USART2_CHECKOUT_H
#define __USART2_CHECKOUT_H 


#include "sys.h"
#include "project_config.h"
u8 usart2_checkout_master(u8 *usart2_data,u16 usart2_size);
u8 usart2_checkout_slave(u8 *usart2_data,u16 usart2_size);
#endif