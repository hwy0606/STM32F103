//////////////////////////////////////////////////
//STM32F103RCT6
//串口2校验程序
//HWY 2018 9 16
//All rights reserved									  
//////////////////////////////////////////////////

#include "usart2_checkout.h"
/*主机发送校验程序 */
/*	校验和字节=0x100~以256为模（开始字节+命令字节+数据字节）
包中所有字节以256为模（包括校验和字节）必须总计达0*/

u8 usart2_checkout_master(u8 *usart2_data,u16 usart2_size)
{
	u16 usart2_sum=0x0000;
	for(int i=0;i<usart2_size;i++)
	{
		usart2_sum=(unsigned short) usart2_data[i]+usart2_sum;
	}
	return (0x100-(usart2_sum % 256) );
}

/*从机发送校验程序 */
/*校验和字节 = 0x100 - 模256（起始字节+数据包字节+数据字节）。
数据包中所有字节的模256求和（包括校验和）必须加起来为零。*/
u8 usart2_checkout_slave(u8 *usart2_data,u16 usart2_size)
{
	u16 usart2_sum=0x0000;
	for(int i=0;i<usart2_size;i++)
	{
		usart2_sum=(unsigned short) usart2_data[i]+usart2_sum;
	}
	return (0x100-(256 % usart2_sum) );
}