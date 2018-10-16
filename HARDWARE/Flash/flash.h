#ifndef __FLASH_H
#define __FLASH_H
#include "sys.h"
#include "project_config.h"

u16  STMFLASH_ReadHalfWord(u32 faddr);		  //读出半字  
void STMFLASH_Write(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite);		//从指定地址开始写入指定长度的数据
void STMFLASH_Read(u32 ReadAddr,u16 *pBuffer,u16 NumToRead);   		//从指定地址开始读出指定长度的数据
void Flash_Buffer_Init();
void Set_Flash_Buffer();
void Get_Flash_Buffer();
#endif



