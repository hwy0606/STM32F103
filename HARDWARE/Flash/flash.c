//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//写入芯片板载FLASH 保存掉电信息
//每次写入16位 半字节
//所以Flash_Buffer 为u16数组
//可使能宏定义配置malloc内存管理
//目前大数组还只有这个STMFLASH_BUF
//HWY 2018 10 16
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////

#include "project_config.h"
#include "flash.h"
#include "stm32f10x_flash.h"
#include "motor_control.h"

u8 FLASH_FLAG=0x00;
extern u8 SEAT_FLAG;
#define Flash_Buffer_Size 2
static u16 Flash_Buffer[Flash_Buffer_Size];

u16 STMFLASH_ReadHalfWord(u32 faddr)
{
	return *(vu16*)faddr; 
}


#if STM32_FLASH_WREN	//如果使能了写   
//不检查的写入
//WriteAddr:起始地址
//pBuffer:数据指针
//NumToWrite:半字(16位)数   
void STMFLASH_Write_NoCheck(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite)   
{ 			 		 
	u16 i;
	for(i=0;i<NumToWrite;i++)
	{
		FLASH_ProgramHalfWord(WriteAddr,pBuffer[i]);
	    WriteAddr+=2;//地址增加2.
	}  
} 


//从指定地址开始写入指定长度的数据
//WriteAddr:起始地址(此地址必须为2的倍数!!)
//pBuffer:数据指针
//NumToWrite:半字(16位)数(就是要写入的16位数据的个数.)
#if STM32_FLASH_SIZE<256
#define STM_SECTOR_SIZE 1024 //字节
#else 
#define STM_SECTOR_SIZE	2048  //每页字节数
#endif	


void STMFLASH_Write(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite)	
{
	u32 secpos;	   //扇区地址
	u16 secoff;	   //扇区内偏移地址(16位字计算)
	u16 secremain; //扇区内剩余地址(16位字计算)	   
 	u16 i;    
	u32 offaddr;   //去掉0X08000000后的地址
	if(WriteAddr<STM32_FLASH_BASE||(WriteAddr>=(STM32_FLASH_BASE+1024*STM32_FLASH_SIZE)))return;//非法地址
	FLASH_Unlock();						//解锁
	offaddr=WriteAddr-STM32_FLASH_BASE;		//实际偏移地址.
	secpos=offaddr/STM_SECTOR_SIZE;			//扇区地址  0~127 for STM32F103RBT6
	secoff=(offaddr%STM_SECTOR_SIZE)/2;		//在扇区内的偏移(2个字节为基本单位.)
	secremain=STM_SECTOR_SIZE/2-secoff;		//扇区剩余空间大小   
	if(NumToWrite<=secremain)secremain=NumToWrite;//不大于该扇区范围
	
	/*判断是否使用内存管理 */
	#ifdef USE_MEM_MALLOC
  #include "malloc.h"
  u16 *STMFLASH_BUF=0;
  STMFLASH_BUF=mymalloc(STM_SECTOR_SIZE/2); //申请2K字节空间
  #else
  u16 STMFLASH_BUF[STM_SECTOR_SIZE/2];    //最多是2K字节
  #endif
	
	while(1) 
	{	
		STMFLASH_Read(secpos*STM_SECTOR_SIZE+STM32_FLASH_BASE,STMFLASH_BUF,STM_SECTOR_SIZE/2);//读出整个扇区的内容
		for(i=0;i<secremain;i++)//校验数据
		{
			if(STMFLASH_BUF[secoff+i]!=0XFFFF)break;//需要擦除  	  
		}
		if(i<secremain)//需要擦除
		{
			FLASH_ErasePage(secpos*STM_SECTOR_SIZE+STM32_FLASH_BASE);//擦除这个扇区
			for(i=0;i<secremain;i++)//复制
			{
				STMFLASH_BUF[i+secoff]=pBuffer[i];	  
			}
			STMFLASH_Write_NoCheck(secpos*STM_SECTOR_SIZE+STM32_FLASH_BASE,STMFLASH_BUF,STM_SECTOR_SIZE/2);//写入整个扇区  
		}else STMFLASH_Write_NoCheck(WriteAddr,pBuffer,secremain);//写已经擦除了的,直接写入扇区剩余区间. 				   
		if(NumToWrite==secremain)break;//写入结束了
		else//写入未结束
		{
			secpos++;				//扇区地址增1
			secoff=0;				//偏移位置为0 	 
		   	pBuffer+=secremain;  	//指针偏移
			WriteAddr+=secremain;	//写地址偏移	   
		   	NumToWrite-=secremain;	//字节(16位)数递减
			if(NumToWrite>(STM_SECTOR_SIZE/2))secremain=STM_SECTOR_SIZE/2;//下一个扇区还是写不完
			else secremain=NumToWrite;//下一个扇区可以写完了
		}	 
	};	
	
	/*如使用内存管理，则用完后释放内存*/
	#ifdef USE_MEM_MALLOC
	myfree(STMFLASH_BUF);	//释放内存
	STMFLASH_BUF=0;		//指向空地址
	#endif
	FLASH_Lock();//上锁
}
#endif

//从指定地址开始读出指定长度的数据
//ReadAddr:起始地址
//pBuffer:数据指针
//NumToWrite:半字(16位)数
void STMFLASH_Read(u32 ReadAddr,u16 *pBuffer,u16 NumToRead)   	
{
	u16 i;
	for(i=0;i<NumToRead;i++)
	{
		pBuffer[i]=STMFLASH_ReadHalfWord(ReadAddr);//读取2个字节.
		ReadAddr+=2;//偏移2个字节.	
	}
}
/*Flash_Buffer 更新相关代码 */
void Flash_Buffer_Init()
{
	for(int i=0;i<Flash_Buffer_Size;i++)
	{
		Flash_Buffer[i]=0x00;
	}
}	


void Set_Flash_Buffer()
{
	Flash_Buffer[0]=0x5A;  //flash帧头校验码
	if(SEAT_FLAG==1)
	{
		Flash_Buffer[1]=Get_Seat_Height(); //更新座椅高度
	}

	//写入Flash
	STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)Flash_Buffer,Flash_Buffer_Size);
}	

/*上电更新相关数据*/
void Get_Flash_Buffer()
{
	u16 Read_Buffer[Flash_Buffer_Size]; //定义接收数组
	STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)Read_Buffer,Flash_Buffer_Size);
	//更新相关信息
	if(Read_Buffer[0]==0x5A)
	{
		//更新座椅高度信息
		Set_Seat_Height(Read_Buffer[1]);
	}
	
}
