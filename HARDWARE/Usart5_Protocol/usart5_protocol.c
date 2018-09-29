//////////////////////////////////////////////////
//STM32F103RCT6
//����5ͨ��Э��
//Ѫ��ģ�� 
//HWY 2018 9 15
//All rights reserved									  
////////////////////////////////////////////////// 
//���Բ����� 115200 ʵ�ʸ���Ϊ9600 n 8 1
//ͨ�Ÿ�ʽ�� 
//FE 08 01 83 39 00 0F CC   62HZ  ʵʱ���ݲ�ʹ�� ��λ����Ӵ���������ĵ�����

//FE 10 01 84 4B   00 60 B8 0B 00   00 03 03 64 00 5D   1HZ
/*
FE ֡ͷ
10 ֡����
01 ��������
84 ID
11���ֽڵ���������
Char1��	PR(����)���������ֽڣ�
Char2��	PR���������ֽڣ�
Char3��	SP02��������*** //Ψһ��������
Char4��	��עָ����8λ��
Char5��	��עָ����8λ��
Char6��	Ԥ����
Char7��	Ԥ����
Char8��	״̬����1;
Char9��	���������
Char10��	SQI�ź�����
Char11��	������������

5D  У��ͣ�����������͡�ID�������������������ݵ��ۻ��ͣ�ȡ��λ��һ���ֽڣ� 


*/
#include "usart5_protocol.h"
#include "usart5_dma.h"
#include "project_config.h"

extern u8 SPO2_DATA[SPO2_DATA_LEN];
void UART5_Sensor_Init()
{
	SPO2_DATA[0]=0X5A;//֡ͷ
	SPO2_DATA[1]=0X0A;//���ݳ���
	SPO2_DATA[2]=0X03;//����������
	SPO2_DATA[3]=0XFF;//��Ч���ݵ�һλ SPO2������ ���·���USART3_DMA�ļ���
	SPO2_DATA[4]=0XFF;//��Ч���ݵڶ�λ ��עָ����8λ ���·���USART3_DMA�ļ���
	SPO2_DATA[5]=0XFF;//��Ч���ݵ���λ ��עָ����8λ ���·���USART3_DMA�ļ���
	SPO2_DATA[6]=0XFF;//��Ч���ݵ���λ ״̬���� ���·���USART3_DMA�ļ���
	SPO2_DATA[7]=0XFF;//��Ч���ݵ���λ SQI�ź����� ���·���USART3_DMA�ļ���
	SPO2_DATA[8]=0XFF;//CRCУ�����8λ
	SPO2_DATA[9]=0XFF;//CRCУ�����8λ	
}

u8 Is_State_Date(u8 *USART_RECEIVE_DATA)
{
	if(((unsigned short)USART_RECEIVE_DATA[3]==0X84))
	{
		if(((unsigned short)USART_RECEIVE_DATA[2]==0X01))
		{
			if(((unsigned short)USART_RECEIVE_DATA[1]==0X10))
			{
				if(((unsigned short)USART_RECEIVE_DATA[0]==0XFE))
				{
						return 1;
				}
			}
		}
	}
	return 0;
}



