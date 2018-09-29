#include "spi.h"
#include "stm32f10x_spi.h"
#include "project_config.h"
//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//SPI2
//SS-PB12 SCK-PB13 MISO-PB14 MOSI-PB14
//HWY 2018 09 29
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 
 

//以下是SPI模块的初始化代码，配置成主机模式				  
//SPI2初始化


void SPI2_Init(void)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = SPI_CS;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   //CS为GPIO普通输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(SPI_GPIO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = SPI_SCK;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;   //SCK为复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(SPI_GPIO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = SPI_MISO;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;   //MISO为上拉输入
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(SPI_GPIO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = SPI_MOSI;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;   //MOSI为复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(SPI_GPIO, &GPIO_InitStructure);
	
	GPIO_SetBits(SPI_GPIO,SPI_CS); //CS设置为高电平 片选信号低电平有效

	SPI_InitTypeDef  SPI_InitStructure;
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;  //设置SPI单向或者双向的数据模式:SPI设置为双线双向全双工
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;		//设置SPI工作模式:设置为主SPI
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_16b;		//设置SPI的数据大小:SPI发送接收16位帧结构
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;		//选择了串行时钟的稳态: CLK空闲高电平
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;	//数据捕获于第二个时钟沿
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;		//NSS信号由硬件（NSS管脚）还是软件（使用SSI位）管理:内部NSS信号有SSI位控制
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;		//定义波特率预分频的值:波特率预分频值为256
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;	//指定数据传输从MSB位还是LSB位开始:数据传输从MSB位开始
	SPI_InitStructure.SPI_CRCPolynomial = 7;	//CRC值计算的多项式
	SPI_Init(SPI2, &SPI_InitStructure);  //根据SPI_InitStruct中指定的参数初始化外设SPIx寄存器
 
	SPI_Cmd(SPI2, ENABLE); //使能SPI外设
	
	SPI2_Send(0xffff);//启动传输		 
}   


//SPIx 读写一个字节
//TxData:要写入的字节
//返回值:读取到的字节
u8 SPI2_Send(u16 Data)
{	
	CS=0;
	u8 retry=0;		//防止被卡死		 	
	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET) //检查指定的SPI标志位设置与否:发送缓存空标志位
		{
		retry++;
		if(retry>200)return 0;
		}			  
	SPI_I2S_SendData(SPI2, Data); //通过外设SPIx发送一个数据
	retry=0;
	CS=1;   
}
































