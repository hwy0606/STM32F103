//////////////////////////////////////////////////
//STM32F103RCT6
//����1ͨ��Э��
//HWY 2018 9 14
//All rights reserved									  
////////////////////////////////////////////////// 
#include "usart1_protocol.h"
#include "usart1_dma.h"
#include "crc_16.h"
#include "project_config.h"
/*
����ͨ��Э����
֡ͷ��0x5A; 1λ
���ݳ��ȣ� һ�����ݰ����ܳ��ȣ�1λ
���������룺0x01-0x03; 1λ
��Ч���ݣ�nλ
У���룺CRC16У�飻2λ
*/
/*��һ���� ����ͨ��Э��*/
/*���ݳ��� 0x07*/
/*���������� 0x01*/
/*��Ч���� 0x01-0x0A*/ 
#define Send_Size_Key  6
u8 Send_Date_Key[Send_Size_Key];

void USART1_Key_Init()
{
  Send_Date_Key[0]=0x5A; //֡ͷ
	Send_Date_Key[1]=0x06; //���ݳ���
	Send_Date_Key[2]=0x01; //����������
	Send_Date_Key[3]=0xFF; //��Ч����
	Send_Date_Key[4]=0x00; //CRCУ�����8λ
	Send_Date_Key[5]=0x00; //CRCУ�����8λ
}


#ifdef USE_PA1_KEY
inline void KEY1_Response()
{
	Send_Date_Key[3]=0x01; //��Ч����
	//����CRCУ��
	usMBCRC16(Send_Date_Key,Send_Size_Key-2);
	Send_Date_Key[4]=Get_ucCRCLo(); //CRCУ�����8λ
	Send_Date_Key[5]=Get_ucCRCHi(); //CRCУ�����8λ
	//��������
	USART1_DMA_Send_Once_Data(Send_Date_Key,Send_Size_Key);	
}
#endif

#ifdef USE_PD2_KEY
void KEY2_Response()
{
	Send_Date_Key[3]=0x02; //��Ч����
	//����CRCУ��
	usMBCRC16(Send_Date_Key,Send_Size_Key-2);
	Send_Date_Key[4]=Get_ucCRCLo(); //CRCУ�����8λ
	Send_Date_Key[5]=Get_ucCRCHi(); //CRCУ�����8λ
	//��������
	USART1_DMA_Send_Once_Data(Send_Date_Key,Send_Size_Key);	
}
#endif

#ifdef USE_PC3_KEY
void KEY3_Response()
{
	Send_Date_Key[3]=0x03; //��Ч����
	//����CRCУ��
	usMBCRC16(Send_Date_Key,Send_Size_Key-2);
	Send_Date_Key[4]=Get_ucCRCLo(); //CRCУ�����8λ
	Send_Date_Key[5]=Get_ucCRCHi(); //CRCУ�����8λ
	//��������
	USART1_DMA_Send_Once_Data(Send_Date_Key,Send_Size_Key);	
}
#endif

#ifdef USE_PC4_KEY
void KEY4_Response()
{
	Send_Date_Key[3]=0x04; //��Ч����
	//����CRCУ��
	usMBCRC16(Send_Date_Key,Send_Size_Key-2);
	Send_Date_Key[4]=Get_ucCRCLo(); //CRCУ�����8λ
	Send_Date_Key[5]=Get_ucCRCHi(); //CRCУ�����8λ
	//��������
	USART1_DMA_Send_Once_Data(Send_Date_Key,Send_Size_Key);	
}
#endif

#ifdef USE_PC5_KEY
void KEY5_Response()
{
	Send_Date_Key[3]=0x05; //��Ч����
	//����CRCУ��
	usMBCRC16(Send_Date_Key,Send_Size_Key-2);
	Send_Date_Key[4]=Get_ucCRCLo(); //CRCУ�����8λ
	Send_Date_Key[5]=Get_ucCRCHi(); //CRCУ�����8λ
	//��������
	USART1_DMA_Send_Once_Data(Send_Date_Key,Send_Size_Key);	
}
#endif

#ifdef USE_PC6_KEY
void KEY6_Response()
{
	Send_Date_Key[3]=0x06; //��Ч����
	//����CRCУ��
	usMBCRC16(Send_Date_Key,Send_Size_Key-2);
	Send_Date_Key[4]=Get_ucCRCLo(); //CRCУ�����8λ
	Send_Date_Key[5]=Get_ucCRCHi(); //CRCУ�����8λ
	//��������
	USART1_DMA_Send_Once_Data(Send_Date_Key,Send_Size_Key);	
}
#endif

#ifdef USE_PC7_KEY
void KEY7_Response()
{
	Send_Date_Key[3]=0x07; //��Ч����
	//����CRCУ��
	usMBCRC16(Send_Date_Key,Send_Size_Key-2);
	Send_Date_Key[4]=Get_ucCRCLo(); //CRCУ�����8λ
	Send_Date_Key[5]=Get_ucCRCHi(); //CRCУ�����8λ
	//��������
	USART1_DMA_Send_Once_Data(Send_Date_Key,Send_Size_Key);	
}
#endif

#ifdef USE_PC8_KEY
void KEY8_Response()
{
	Send_Date_Key[3]=0x08; //��Ч����
	//����CRCУ��
	usMBCRC16(Send_Date_Key,Send_Size_Key-2);
	Send_Date_Key[4]=Get_ucCRCLo(); //CRCУ�����8λ
	Send_Date_Key[5]=Get_ucCRCHi(); //CRCУ�����8λ
	//��������
	USART1_DMA_Send_Once_Data(Send_Date_Key,Send_Size_Key);	
}
#endif

#ifdef USE_PC9_KEY
void KEY9_Response()
{
	Send_Date_Key[3]=0x09; //��Ч����
	//����CRCУ��
	usMBCRC16(Send_Date_Key,Send_Size_Key-2);
	Send_Date_Key[4]=Get_ucCRCLo(); //CRCУ�����8λ
	Send_Date_Key[5]=Get_ucCRCHi(); //CRCУ�����8λ
	//��������
	USART1_DMA_Send_Once_Data(Send_Date_Key,Send_Size_Key);	
}
#endif

/*�ڶ����� Ѫѹͨ��Э��*/
/*���ݳ��� 0x*/
/*���������� 0x02*/
//�����յ�������ԭ�ⲻ����ת�� �յ���Ϣ����ת��
u8 Is_BP_Order(u8 *USART_RECEIVE_DATA) //�ж��ǲ���Ѫѹָ�� ֡ͷ��0x02���������� ����CRCУ����
{
	if(((unsigned short)USART_RECEIVE_DATA[2]==0X02)) //����������
	{
	if(((unsigned short)USART_RECEIVE_DATA[0]==0XA5))
	{
		return 1;
	}
	}
	return 0;
}
/*������2�յ������� ԭ�ⲻ����ͨ������1���ͻ�ȥ */
extern u8 USART2_BP_DATA[32];

void USART1_BP_Response(u8 *USART1_RECEIVE_DATA,u16 DATA_LEN)
{
	USART2_BP_DATA[0]=0x5A;
	USART2_BP_DATA[1]=DATA_LEN+0x05;
	USART2_BP_DATA[2]=0X02;
	for(int i=0;i<DATA_LEN;i++)
	{
		USART2_BP_DATA[3+i]=USART1_RECEIVE_DATA[i];
	}
	//����CRCУ��
	usMBCRC16(USART2_BP_DATA,DATA_LEN+0x03);
	USART2_BP_DATA[DATA_LEN+0x03]=Get_ucCRCLo(); //CRCУ�����8λ
	USART2_BP_DATA[DATA_LEN+0x04]=Get_ucCRCHi(); //CRCУ�����8λ	
	USART1_DMA_Send_Once_Data(USART2_BP_DATA,DATA_LEN+0x05);	
}


/*�������� Ѫ��ͨ��Э��*/
/*���ݳ��� 0x0A*/
/*���������� 0x03*/
extern u8 SPO2_DATA[SPO2_DATA_LEN]; //ֱ����ȫ�ֱ��� ������ַ
extern u8 SPO2_FLAG; //Ѫ����Ϣ���±�־λ
void SPO2_Response()
{ 
	//�˴���һ��CRCУ��Ȼ���ͣ�������ɺ�λSPO2_FLAG��־λ
	usMBCRC16(SPO2_DATA,SPO2_DATA_LEN-2);
  SPO2_DATA[8]=Get_ucCRCLo();//CRCУ�����8λ
	SPO2_DATA[9]=Get_ucCRCHi(); //CRCУ�����8λ	
	//��������
	USART1_DMA_Send_Once_Data(SPO2_DATA,SPO2_DATA_LEN);
	USART1_DMA_Send_Once_Data(SPO2_DATA,SPO2_DATA_LEN);
  SPO2_FLAG=0;	
}

/*���Ĳ��� �ٶ�ͨ��Э��*/
/*���ݳ��� 0x07*/ 
/*��Ч���� 2λ */
/*���������� 0x04*/
extern float motor_speed;//�ٶ�
u8 SPEED_DATA[SPEED_DATA_LEN];
void USART1_Speed_Init()
{
	SPEED_DATA[0]=0x5A;
	SPEED_DATA[1]=SPEED_DATA_LEN;	
	SPEED_DATA[2]=0x04;
	
}
void Speed_Response()
{
	SPEED_DATA[3]=(unsigned char)(((u16)(motor_speed) & 0xFF00)>>8);	
	SPEED_DATA[4]=(unsigned char)(u16)(motor_speed)&0x00FF;
	usMBCRC16(SPEED_DATA,SPEED_DATA_LEN-2);
  SPEED_DATA[5]=Get_ucCRCLo();//CRCУ�����8λ
	SPEED_DATA[6]=Get_ucCRCHi(); //CRCУ�����8λ
	USART1_DMA_Send_Once_Data(SPEED_DATA,SPEED_DATA_LEN);	
}
u8 Is_Speed_Order(u8 *USART_RECEIVE_DATA) //�ж��ǲ����ٶ�ָ�� ֡ͷ��0x02���������� ����CRCУ����
{
	if(((unsigned short)USART_RECEIVE_DATA[2]==0X04)) //����������
	{
	if(((unsigned short)USART_RECEIVE_DATA[0]==0XA5))
	{
		return 1;
	}
	}
	return 0;
}
