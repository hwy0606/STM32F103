//////////////////////////////////////////////////
//STM32F103RCT6
//����2ͨ��Э��
//Ѫѹģ��
//HWY 2018 9 15
//All rights reserved									  
//////////////////////////////////////////////////
//���Բ����� 115200 ʵ�ʸ���Ϊ9600 n 8 1 ��project_config.h�ļ��и���
/*������Ҫ������ 
1.����BP���� ������ɺ��������ȡ���� 
2.�����ѹ����BP����  ����������ʵʱ����Ѫѹ����
*/

/*ͨ�Ÿ�ʽ��
1.����BP����
�������� 3A 20 A6
�ӻ��յ�ָ��󷵻�  O-packet 3E 04 4F 6F  
�ӻ����ָ��󷵻�  K-packet 3E	04 4B	73
{����ӻ�����æָ�� �������·���BP����ָ�� B-packet 3E	04 42 7C}

*/

/*ͨ�Ÿ�ʽ��
2.�����ѹ���ĳ���BP����
�������� 3A 56 70
*/

#include "usart2_protocol.h"
#include "project_config.h"
#include "usart2_dma.h"
#include "usart2_checkout.h"
/*���崫������ ��������ָ��� */
static u8 BP_SEND_DATA[BP_DATA_LEN];  
static u8 BP_RECEIVE_DATA[BP_DATA_LEN];
void USART2_Sensor_Init()
{
	BP_SEND_DATA[0]=0x3A; //ÿһ��MASTERָ���0x3A��ͷ
}


void BP_Measurement()  //MASTER ����BP����
{
	BP_SEND_DATA[1]=0x20;
	BP_SEND_DATA[2]=usart2_checkout_master(&BP_SEND_DATA[0],BP_Measurement_LEN-1);//��ȡ��������У����  A6
	USART2_DMA_Send_Once_Data(BP_SEND_DATA,BP_Measurement_LEN);
}





/*�ӻ�ָ����*/
/*����Ƿ�ΪO-packet */
u8 Is_O_Packet(u8 *USART_RECEIVE_DATA)
{
	if((unsigned short)USART_RECEIVE_DATA[3]==0x6F) //���У���
	{
		if((unsigned short)USART_RECEIVE_DATA[2]==0x4F) //'O'
		{
			if((unsigned short)USART_RECEIVE_DATA[1]==0x04) //�����ֽ�
			{
				if((unsigned short)USART_RECEIVE_DATA[0]==0x3E) //֡ͷ
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

/*����Ƿ�ΪK-packet */
u8 Is_K_Packet(u8 *USART_RECEIVE_DATA)
{
	if((unsigned short)USART_RECEIVE_DATA[3]==0x73) //���У���
	{
		if((unsigned short)USART_RECEIVE_DATA[2]==0x4B) //'K'
		{
			if((unsigned short)USART_RECEIVE_DATA[1]==0x04) //�����ֽ�
			{
				if((unsigned short)USART_RECEIVE_DATA[0]==0x3E) //֡ͷ
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

/*����Ƿ�ΪB-packet */
u8 Is_B_Packet(u8 *USART_RECEIVE_DATA)
{
	if((unsigned short)USART_RECEIVE_DATA[3]==0x7C) //���У���
	{
		if((unsigned short)USART_RECEIVE_DATA[2]==0x42) //'P'
		{
			if((unsigned short)USART_RECEIVE_DATA[1]==0x04) //�����ֽ�
			{
				if((unsigned short)USART_RECEIVE_DATA[0]==0x3E) //֡ͷ
				{
					return 1;
				}
			}
		}
	}
	return 0;
}