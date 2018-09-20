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
ֱ�ӷ��ء���3E 04 4F 6F
Ȼ��ͣ�������ѹ������3E 07 01 8E 00 00 2C
���У�8E 00 00Ϊ���ѹ��142mmHg,��λ��ǰ
��ɺ󷵻ء���3E 04 4B 73
Ȼ�󷵻�BP���ݡ���3E 19 03 ���� У����
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


/*��ʼ����BP���� */
void BP_Measurement_Start()   //����BP���� 0x20ָ��
{
	u8 BP_Measurement_LEN =3;
	BP_SEND_DATA[1]=0X20;
	BP_SEND_DATA[2]=0XA6;//��ȡ��������У����  A6
	USART2_DMA_Send_Once_Data(BP_SEND_DATA,BP_Measurement_LEN);
}
/*��ֹ��ǰ���� */
void BP_Measurement_Stop()   //�����һ��BP�������  0x79 0x01 0x00ָ��
{
	u8 BP_Measurement_LEN =5;
	BP_SEND_DATA [1]=0X79;
	BP_SEND_DATA [2]=0X01;
	BP_SEND_DATA [3]=0X00;
	BP_SEND_DATA [4]=0X4C;
	USART2_DMA_Send_Once_Data(BP_SEND_DATA,BP_Measurement_LEN);
}	
/*�����һ��BP�������*/
void Get_BP_Measurement_Result()  //�����һ��BP�������  0x79 0x03 0x00ָ��
{
	u8 BP_Measurement_LEN =5;
	BP_SEND_DATA [1]=0X79;
	BP_SEND_DATA [2]=0X03;
	BP_SEND_DATA [3]=0X00;
	BP_SEND_DATA [4]=0X4A;
	USART2_DMA_Send_Once_Data(BP_SEND_DATA,BP_Measurement_LEN);
}
/*��õ�ǰ���ѹ��*/
void Get_BP_Cuff_Pressure()  //��õ�ǰ���ѹ�� 0x79 0x05 0x00ָ��
{
	u8 BP_Measurement_LEN =5;
	BP_SEND_DATA [1]=0X79;
	BP_SEND_DATA [2]=0X05;
	BP_SEND_DATA [3]=0X00;
	BP_SEND_DATA [4]=0X48;
	USART2_DMA_Send_Once_Data(BP_SEND_DATA,BP_Measurement_LEN);
}

void BP_Cuff_Start()   //�����ѹ�������ݱ��濪ʼ����ģʽBP 0x56ָ�� 
{
	u8 BP_Measurement_LEN =3;
	BP_SEND_DATA[1]=0X56;
	BP_SEND_DATA[2]=0X70;//��ȡ��������У����  70
	USART2_DMA_Send_Once_Data(BP_SEND_DATA,BP_Measurement_LEN);
}

u8 BP_Sleep_Mode(u8 SleepMode) // 0X01��������ģʽ 0X00�˳�����ģʽ  0x81ָ��
{
	u8 BP_Measurement_LEN =7;
	BP_SEND_DATA [1]=0X81;
	BP_SEND_DATA [2]=0X00;
	BP_SEND_DATA [3]=0X00;
	BP_SEND_DATA [4]=0X00;
	BP_SEND_DATA [5]=SleepMode;
	BP_SEND_DATA [6]=usart2_checkout_master(&BP_SEND_DATA[0],BP_Measurement_LEN-1);
	USART2_DMA_Send_Once_Data(BP_SEND_DATA,BP_Measurement_LEN);
}

void BP_Reset()  //��λģ�鴦����
{
	u8 BP_Measurement_LEN =3;
	BP_SEND_DATA [1]=0X8A;
	BP_SEND_DATA [2]=0X3C;
}

void BP_Status() //ģ��״̬���
{
	u8 BP_Measurement_LEN =5;
	BP_SEND_DATA [1]=0X79;
	BP_SEND_DATA [2]=0X11;
	BP_SEND_DATA [2]=0X00;
	BP_SEND_DATA [2]=0X3C;
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
		if((unsigned short)USART_RECEIVE_DATA[2]==0x42) //'B'
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
/*����Ƿ�ΪA-packet */
u8 Is_A_Packet(u8 *USART_RECEIVE_DATA)
{
	if((unsigned short)USART_RECEIVE_DATA[3]==0x7D) //���У���
	{
		if((unsigned short)USART_RECEIVE_DATA[2]==0x41) //'A'
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
/*����Ƿ�ΪS-packet */
u8 Is_S_Packet(u8 *USART_RECEIVE_DATA)
{
	if((unsigned short)USART_RECEIVE_DATA[3]==0x6B) //���У���
	{
		if((unsigned short)USART_RECEIVE_DATA[2]==0x53) //'S'
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

