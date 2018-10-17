//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//д��оƬ����FLASH ���������Ϣ
//ÿ��д��16λ ���ֽ�
//����Flash_Buffer Ϊu16����
//��ʹ�ܺ궨������malloc�ڴ����
//Ŀǰ�����黹ֻ�����STMFLASH_BUF
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


#if STM32_FLASH_WREN	//���ʹ����д   
//������д��
//WriteAddr:��ʼ��ַ
//pBuffer:����ָ��
//NumToWrite:����(16λ)��   
void STMFLASH_Write_NoCheck(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite)   
{ 			 		 
	u16 i;
	for(i=0;i<NumToWrite;i++)
	{
		FLASH_ProgramHalfWord(WriteAddr,pBuffer[i]);
	    WriteAddr+=2;//��ַ����2.
	}  
} 


//��ָ����ַ��ʼд��ָ�����ȵ�����
//WriteAddr:��ʼ��ַ(�˵�ַ����Ϊ2�ı���!!)
//pBuffer:����ָ��
//NumToWrite:����(16λ)��(����Ҫд���16λ���ݵĸ���.)
#if STM32_FLASH_SIZE<256
#define STM_SECTOR_SIZE 1024 //�ֽ�
#else 
#define STM_SECTOR_SIZE	2048  //ÿҳ�ֽ���
#endif	


void STMFLASH_Write(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite)	
{
	u32 secpos;	   //������ַ
	u16 secoff;	   //������ƫ�Ƶ�ַ(16λ�ּ���)
	u16 secremain; //������ʣ���ַ(16λ�ּ���)	   
 	u16 i;    
	u32 offaddr;   //ȥ��0X08000000��ĵ�ַ
	if(WriteAddr<STM32_FLASH_BASE||(WriteAddr>=(STM32_FLASH_BASE+1024*STM32_FLASH_SIZE)))return;//�Ƿ���ַ
	FLASH_Unlock();						//����
	offaddr=WriteAddr-STM32_FLASH_BASE;		//ʵ��ƫ�Ƶ�ַ.
	secpos=offaddr/STM_SECTOR_SIZE;			//������ַ  0~127 for STM32F103RBT6
	secoff=(offaddr%STM_SECTOR_SIZE)/2;		//�������ڵ�ƫ��(2���ֽ�Ϊ������λ.)
	secremain=STM_SECTOR_SIZE/2-secoff;		//����ʣ��ռ��С   
	if(NumToWrite<=secremain)secremain=NumToWrite;//�����ڸ�������Χ
	
	/*�ж��Ƿ�ʹ���ڴ���� */
	#ifdef USE_MEM_MALLOC
  #include "malloc.h"
  u16 *STMFLASH_BUF=0;
  STMFLASH_BUF=mymalloc(STM_SECTOR_SIZE/2); //����2K�ֽڿռ�
  #else
  u16 STMFLASH_BUF[STM_SECTOR_SIZE/2];    //�����2K�ֽ�
  #endif
	
	while(1) 
	{	
		STMFLASH_Read(secpos*STM_SECTOR_SIZE+STM32_FLASH_BASE,STMFLASH_BUF,STM_SECTOR_SIZE/2);//������������������
		for(i=0;i<secremain;i++)//У������
		{
			if(STMFLASH_BUF[secoff+i]!=0XFFFF)break;//��Ҫ����  	  
		}
		if(i<secremain)//��Ҫ����
		{
			FLASH_ErasePage(secpos*STM_SECTOR_SIZE+STM32_FLASH_BASE);//�����������
			for(i=0;i<secremain;i++)//����
			{
				STMFLASH_BUF[i+secoff]=pBuffer[i];	  
			}
			STMFLASH_Write_NoCheck(secpos*STM_SECTOR_SIZE+STM32_FLASH_BASE,STMFLASH_BUF,STM_SECTOR_SIZE/2);//д����������  
		}else STMFLASH_Write_NoCheck(WriteAddr,pBuffer,secremain);//д�Ѿ������˵�,ֱ��д������ʣ������. 				   
		if(NumToWrite==secremain)break;//д�������
		else//д��δ����
		{
			secpos++;				//������ַ��1
			secoff=0;				//ƫ��λ��Ϊ0 	 
		   	pBuffer+=secremain;  	//ָ��ƫ��
			WriteAddr+=secremain;	//д��ַƫ��	   
		   	NumToWrite-=secremain;	//�ֽ�(16λ)���ݼ�
			if(NumToWrite>(STM_SECTOR_SIZE/2))secremain=STM_SECTOR_SIZE/2;//��һ����������д����
			else secremain=NumToWrite;//��һ����������д����
		}	 
	};	
	
	/*��ʹ���ڴ������������ͷ��ڴ�*/
	#ifdef USE_MEM_MALLOC
	myfree(STMFLASH_BUF);	//�ͷ��ڴ�
	STMFLASH_BUF=0;		//ָ��յ�ַ
	#endif
	FLASH_Lock();//����
}
#endif

//��ָ����ַ��ʼ����ָ�����ȵ�����
//ReadAddr:��ʼ��ַ
//pBuffer:����ָ��
//NumToWrite:����(16λ)��
void STMFLASH_Read(u32 ReadAddr,u16 *pBuffer,u16 NumToRead)   	
{
	u16 i;
	for(i=0;i<NumToRead;i++)
	{
		pBuffer[i]=STMFLASH_ReadHalfWord(ReadAddr);//��ȡ2���ֽ�.
		ReadAddr+=2;//ƫ��2���ֽ�.	
	}
}
/*Flash_Buffer ������ش��� */
void Flash_Buffer_Init()
{
	for(int i=0;i<Flash_Buffer_Size;i++)
	{
		Flash_Buffer[i]=0x00;
	}
}	


void Set_Flash_Buffer()
{
	Flash_Buffer[0]=0x5A;  //flash֡ͷУ����
	if(SEAT_FLAG==1)
	{
		Flash_Buffer[1]=Get_Seat_Height(); //�������θ߶�
	}

	//д��Flash
	STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)Flash_Buffer,Flash_Buffer_Size);
}	

/*�ϵ�����������*/
void Get_Flash_Buffer()
{
	u16 Read_Buffer[Flash_Buffer_Size]; //�����������
	STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)Read_Buffer,Flash_Buffer_Size);
	//���������Ϣ
	if(Read_Buffer[0]==0x5A)
	{
		//�������θ߶���Ϣ
		Set_Seat_Height(Read_Buffer[1]);
	}
	
}
