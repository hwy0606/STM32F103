#include "crc_16.h"
#include "project_config.h"	 
//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//CRC-16 ���У�� �ٶȿ죬��ռ��Դ 
//ÿ�β�ѯ�� ��ԭʼ״̬
//HWY 2017 12 29
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////
#ifdef USE_CRC_SOFTWARE
static u8 ucCRCHi;
static u8 ucCRCLo;
void CRC16_Init()
{
	
}

//*pucFrame ��У�������׵�ַ,usLen ��У�����ݳ��� ����У���� u16
void usMBCRC16( u8 * pucFrame, u8 usLen )
{
    int iIndex;
    ucCRCHi=0xFF ;
    ucCRCLo=0XFF ;
    while( usLen-- )
    {

        iIndex = ucCRCLo ^ *( pucFrame++ );

        ucCRCLo = ( u8 )( ucCRCHi ^ aucCRCHi[iIndex] );

        ucCRCHi = aucCRCLo[iIndex];
						
    }
}
u8 Get_ucCRCHi()//��ȡ��8λ
{
	return ucCRCHi;
}

u8 Get_ucCRCLo()//��ȡ��8λ
{
	return ucCRCLo;
}

#endif



#ifdef USE_CRC_HARDWARE
#include "stm32f10x_crc.h"
//���Ӳ��CRC������ ����׼CRC��һ����Ĭ�ϻ���֧��4�ֽڶ��� ���Ƽ�ʹ��
void usMBCRC16( u8 * pucFrame, u8 usLen )
{
	CRC_ResetDR(); //���¿���һ��CRC����
	CRC_CalcBlockCRC(pucFrame, usLen);
}
void CRC16_Init()
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_CRC, ENABLE);
	CRC_ResetDR();
}

u8 Get_ucCRCHi()//��ȡ��8λ
{
	return 0x00;
}

u8 Get_ucCRCLo()//��ȡ��8λ
{
	return 0x00;
}



#endif

/* Ӳ��CRCģ�麯�� */
/*CRC_ResetDR(void) 
������λCRCģ�顣

uint32_t CRC_CalcCRC(uint32_t Data)
��һ������д��CRC_DR�Ĵ���������ֵΪ��������

uint32_t CRC_CalcBlockCRC(uint32_t pBuffer[], uint32_t BufferLength)
����һ�������CRC ֵ��

uint32_t CRC_GetCRC(void)
��ȡCRC_DR�Ĵ����Ľ����

���⣬CRC ģ���л��и��������ݼĴ���(CRC_IDR)��
���Ǹ����ֽڵļĴ�����������ʱ���1�ֽڵ����ݣ����ܸ�λ����Ӱ�졣��Ӧ�Ĳ���������������

void CRC_SetIDRegister(uint8_t IDValue)
uint8_t CRC_GetIDRegister(void)
�ֱ���дCRC_IDR�Ͷ� CRC_IDR �Ĵ�����
 */


