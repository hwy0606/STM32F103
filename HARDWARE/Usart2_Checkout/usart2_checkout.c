//////////////////////////////////////////////////
//STM32F103RCT6
//����2У�����
//HWY 2018 9 16
//All rights reserved									  
//////////////////////////////////////////////////

#include "usart2_checkout.h"
/*��������У����� */
/*	У����ֽ�=0x100~��256Ϊģ����ʼ�ֽ�+�����ֽ�+�����ֽڣ�
���������ֽ���256Ϊģ������У����ֽڣ������ܼƴ�0*/

u8 usart2_checkout_master(u8 *usart2_data,u16 usart2_size)
{
	u16 usart2_sum=0x0000;
	for(int i=0;i<usart2_size;i++)
	{
		usart2_sum=(unsigned short) usart2_data[i]+usart2_sum;
	}
	return (0x100-(usart2_sum % 256) );
}

/*�ӻ�����У����� */
/*У����ֽ� = 0x100 - ģ256����ʼ�ֽ�+���ݰ��ֽ�+�����ֽڣ���
���ݰ��������ֽڵ�ģ256��ͣ�����У��ͣ����������Ϊ�㡣*/
u8 usart2_checkout_slave(u8 *usart2_data,u16 usart2_size)
{
	u16 usart2_sum=0x0000;
	for(int i=0;i<usart2_size;i++)
	{
		usart2_sum=(unsigned short) usart2_data[i]+usart2_sum;
	}
	return (0x100-(256 % usart2_sum) );
}