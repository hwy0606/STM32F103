#ifndef __FLASH_H
#define __FLASH_H
#include "sys.h"
#include "project_config.h"

u16  STMFLASH_ReadHalfWord(u32 faddr);		  //��������  
void STMFLASH_Write(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite);		//��ָ����ַ��ʼд��ָ�����ȵ�����
void STMFLASH_Read(u32 ReadAddr,u16 *pBuffer,u16 NumToRead);   		//��ָ����ַ��ʼ����ָ�����ȵ�����
void Flash_Buffer_Init();
void Set_Flash_Buffer();
void Get_Flash_Buffer();
#endif



