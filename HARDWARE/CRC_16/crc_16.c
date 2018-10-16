#include "crc_16.h"
#include "project_config.h"	 
//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//CRC-16 查表法校验 速度快，不占资源 
//每次查询完 到原始状态
//HWY 2017 12 29
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////
#ifdef USE_CRC_SOFTWARE
static u8 ucCRCHi;
static u8 ucCRCLo;
void CRC16_Init()
{
	
}

//*pucFrame 待校验数据首地址,usLen 待校验数据长度 返回校验结果 u16
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
u8 Get_ucCRCHi()//获取高8位
{
	return ucCRCHi;
}

u8 Get_ucCRCLo()//获取低8位
{
	return ucCRCLo;
}

#endif



#ifdef USE_CRC_HARDWARE
#include "stm32f10x_crc.h"
//这个硬件CRC很智障 跟标准CRC不一样，默认还不支持4字节对齐 不推荐使用
void usMBCRC16( u8 * pucFrame, u8 usLen )
{
	CRC_ResetDR(); //重新开启一次CRC运算
	CRC_CalcBlockCRC(pucFrame, usLen);
}
void CRC16_Init()
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_CRC, ENABLE);
	CRC_ResetDR();
}

u8 Get_ucCRCHi()//获取高8位
{
	return 0x00;
}

u8 Get_ucCRCLo()//获取低8位
{
	return 0x00;
}



#endif

/* 硬件CRC模块函数 */
/*CRC_ResetDR(void) 
用来复位CRC模块。

uint32_t CRC_CalcCRC(uint32_t Data)
将一个数据写入CRC_DR寄存器，返回值为计算结果。

uint32_t CRC_CalcBlockCRC(uint32_t pBuffer[], uint32_t BufferLength)
计算一个数组的CRC 值。

uint32_t CRC_GetCRC(void)
读取CRC_DR寄存器的结果。

另外，CRC 模块中还有个独立数据寄存器(CRC_IDR)。
这是个单字节的寄存器，用于临时存放1字节的数据，不受复位操作影响。相应的操作函数有两个。

void CRC_SetIDRegister(uint8_t IDValue)
uint8_t CRC_GetIDRegister(void)
分别是写CRC_IDR和读 CRC_IDR 寄存器。
 */


