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








