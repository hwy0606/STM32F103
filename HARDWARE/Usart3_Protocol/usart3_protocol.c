//////////////////////////////////////////////////
//STM32F103RCT6
//����3ͨ��Э��
//Ѫѹģ��
//HWY 2018 9 15
//All rights reserved									  
//////////////////////////////////////////////////
/*�°汾ͨ��Э�� */
/* ��Ҫ��ת���Ĺ��� 
1.������2�յ�����Ϣת��������3
2.������3�յ�����Ϣת��������2
*/
#include "usart3_protocol.h"
#include "project_config.h"
#include "usart3_dma.h"

/* ��ȡ����2�յ���Ѫѹָ��͸�����3   0x02����������*/ 
/* ע���ж����ݳ���*/
/*
֡ͷ 0xA5
���ݳ��� 0xFF
���������� 0X02
��Ч���� 
CRC У���� �ߵ�λ 
*/

u8 USART3_BP_DATA[32];


void BP_Order_USART3(u8 *USART_RECEIVE_DATA)
{
	u16 USART3_BP_DATA_LEN =USART_RECEIVE_DATA[1]-0x05;  //��Ч���ݸ���
	for(u8 i=0;i<USART2_DATA_LEN;i++)
	{
		USART3_BP_DATA[i]=USART_RECEIVE_DATA[i+0x03];
	}
	USART3_DMA_Send_Once_Data(USART3_BP_DATA,USART3_BP_DATA_LEN);
}	
	
	





