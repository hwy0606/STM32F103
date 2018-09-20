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


/*SLAVE-MASTER*/
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

#ifdef USE_PA0_KEY
inline void KEY0_Response()
{
	Send_Date_Key[3]=0x00; //��Ч����
	//����CRCУ��
	usMBCRC16(Send_Date_Key,Send_Size_Key-2);
	Send_Date_Key[4]=Get_ucCRCLo(); //CRCУ�����8λ
	Send_Date_Key[5]=Get_ucCRCHi(); //CRCУ�����8λ
	//��������
	USART1_DMA_Send_Once_Data(Send_Date_Key,Send_Size_Key);	
}
#endif

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

/*�������� Ѫ��ͨ��Э��*/
/*���ݳ��� 0x0A*/
/*���������� 0x03*/
extern u8 SPO2_DATA[SPO2_DATA_LEN]; //ֱ����ȫ�ֱ��� ������ַ
extern u8 SPO2_FLAG;
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
/*�ڶ����� Ѫѹͨ��Э��*/
/*���ݳ��� 0x*/
/*���������� 0x02*/


/*���Ĳ��� ״̬����Э��*/
/*���ݳ��� */
/*���������� 0x04*/
u8 STATUS_DATA[16];  //C99��׼�ɱ�����ֻ�ܶ����ں����� 
u16 STATUS_DATA_LEN;
void BP_O_response()
{
	STATUS_DATA_LEN=7;
	STATUS_DATA[0]=0x5A;
	STATUS_DATA[1]=0x05;
	STATUS_DATA[2]=0x04;
	STATUS_DATA[3]=0x4F;  //0x4F
	STATUS_DATA[4]=0x4F;  //0x4F
	usMBCRC16(STATUS_DATA,STATUS_DATA_LEN-2);
	STATUS_DATA[5]=Get_ucCRCLo();  //CRCУ�����8λ
	STATUS_DATA[6]=Get_ucCRCHi();  //CRCУ�����8λ
	USART1_DMA_Send_Once_Data(STATUS_DATA,STATUS_DATA_LEN);
	
}
void BP_K_response()
{
	STATUS_DATA_LEN=7;
	STATUS_DATA[0]=0x5A;
	STATUS_DATA[1]=0x05;
	STATUS_DATA[2]=0x04;
	STATUS_DATA[3]=0x4B;  
	STATUS_DATA[4]=0x4B;  
	usMBCRC16(STATUS_DATA,STATUS_DATA_LEN-2);
	STATUS_DATA[5]=Get_ucCRCLo();  //CRCУ�����8λ
	STATUS_DATA[6]=Get_ucCRCHi();  //CRCУ�����8λ
	USART1_DMA_Send_Once_Data(STATUS_DATA,STATUS_DATA_LEN);
}

void BP_Busy_response()
{
	STATUS_DATA_LEN=7;
	STATUS_DATA[0]=0x5A;
	STATUS_DATA[1]=0x05;
	STATUS_DATA[2]=0x04;
	STATUS_DATA[3]=0x42;  
	STATUS_DATA[4]=0x42;  
	usMBCRC16(STATUS_DATA,STATUS_DATA_LEN-2);
	STATUS_DATA[5]=Get_ucCRCLo();  //CRCУ�����8λ
	STATUS_DATA[6]=Get_ucCRCHi();  //CRCУ�����8λ
	USART1_DMA_Send_Once_Data(STATUS_DATA,STATUS_DATA_LEN);
}


void BP_Abort_response()
{
	STATUS_DATA_LEN=7;
	STATUS_DATA[0]=0x5A;
	STATUS_DATA[1]=0x05;
	STATUS_DATA[2]=0x04;
	STATUS_DATA[3]=0x41;  //0x4F
	STATUS_DATA[4]=0x41;  //0x4F
	usMBCRC16(STATUS_DATA,STATUS_DATA_LEN-2);
	STATUS_DATA[5]=Get_ucCRCLo();  //CRCУ�����8λ
	STATUS_DATA[6]=Get_ucCRCHi();  //CRCУ�����8λ
	USART1_DMA_Send_Once_Data(STATUS_DATA,STATUS_DATA_LEN);
}

void BP_Sleep_response()
{
	STATUS_DATA_LEN=7;
	STATUS_DATA[0]=0x5A;
	STATUS_DATA[1]=0x05;
	STATUS_DATA[2]=0x04;
	STATUS_DATA[3]=0x53;  //0x4F
	STATUS_DATA[4]=0x53;  //0x4F
	usMBCRC16(STATUS_DATA,STATUS_DATA_LEN-2);
	STATUS_DATA[5]=Get_ucCRCLo();  //CRCУ�����8λ
	STATUS_DATA[6]=Get_ucCRCHi();  //CRCУ�����8λ
	USART1_DMA_Send_Once_Data(STATUS_DATA,STATUS_DATA_LEN);
}

void BP_Status_response(u8 *USART2_RECEIVE_DATA)  //�Ѵ���2���յ��Ĵ�����봫����ͨ������1������λ��
{
	
}



/*MASTER-SLAVE*/
/* ͨ��Э�� */
/*֡ͷ0xA5*/
/*���ݳ���0xFF*/
/*��������0x01-0x04*/
/*��Ч����*/
/*CRCУ����*/


// MASTER�������ͺ��� �Ⱥ˶������������֡ͷ �ٽ�ȫ�ֱ�־λ��λ ÿ��ֻ�ܴ���һ��ģʽ 
//ÿ��ģʽ��ֻ�ܷ��͸���ģʽ�������ָ�� ������ܳ������벻���Ĵ���  ###############
//���������� 0x01
//��Ч����λ ����Ϊ0x01-0x04 ��Ӧ���б�־λ
/*��־λ����
0x01  ��ʼ����ģʽBPģʽ
0x02  ��ʼ�����ѹ�������ݱ���ĳ���ģʽBPģʽ
0x03  BP������״̬���ݼ��
0x04  ������Ϣ
*/

u8 USART1_Flag(u8 *USART1_RECEIVE_DATA)
{
	//�˴�ʡ��CRCУ�� ֻ�ж����������� �� ֡ͷ
	if(((unsigned short)USART1_RECEIVE_DATA[0]==0XA5))
	{
		if(((unsigned short)USART1_RECEIVE_DATA[2]==0X01))
		{
			return (unsigned short)USART1_RECEIVE_DATA[3];
		}
	}
}

//0x01ģʽ ��ʼ����ģʽBPģʽ
//���������� 0x02
//��Ч����0x01-0x04
/*
0x01 ��ʼ����BP����

0x02 ��ֹ����BP����

*/
u8 BP_Measurement(u8 *USART1_RECEIVE_DATA)
{
	//�˴�ʡ��CRCУ�� ֻ�ж����������� �� ֡ͷ
	if(((unsigned short)USART1_RECEIVE_DATA[0]==0XA5))
	{
		if(((unsigned short)USART1_RECEIVE_DATA[2]==0X02))
		{
			return (unsigned short)USART1_RECEIVE_DATA[3];
		}
	}
}




