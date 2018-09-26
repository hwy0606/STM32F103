/****************************************************************************
* Copyright (C), 2013 奋斗嵌入式工作室 www.ourstm.net
*
* 本例程在 奋斗版STM32开发板V2,V2.1,V3,V5,MINI上调试通过           
* QQ: 9191274, 旺旺：sun68, Email: sun68@163.com 
* 淘宝店铺：ourstm.taobao.com  
*
* 文件名: main.c
* 内容简述:	
*       
*	演示通过串口1显示ADC1的11通道的测量结果
*	辅助软件：PC机上需要运行串口调试助手软件。
    
	基于MDK版本：        3.8
	基于官方外设库版本： 3.5	
*
* 文件历史:
* 版本号  日期       作者    说明
* v0.2    2011-7-28 sun68  创建该文件
*
*/
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"	   
#include "stm32f10x_adc.h"
#include "stm32f10x_dma.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"	 
#include "stm32f10x_flash.h"
#include "misc.h"		 
#include  <stdarg.h>

#define ADC1_DR_Address    ((u32)0x4001244C)	 
#define FLASH_IAP_ADDR		0x08000000  	//iap程序起始地址(存放在FLASH)

#define LED1   GPIO_Pin_5
#define LED2   GPIO_Pin_6
#define LED3   GPIO_Pin_3

static unsigned long ticks;
unsigned char Clock1s;


vu16 ADC_ConvertedValue;

typedef  void (*iapfun)(void);
iapfun jump2iap;

void RCC_Configuration(void);  
void ADC_Configuration(void); 
void Usart1_Init(void);
void USART_OUT(USART_TypeDef* USARTx, uint8_t *Data,...);
void LED_Configuration(void);
void KEY_Configuration(void);
void iap_jump(u32 iapxaddr);

/****************************************************************************
* 名    称：int main(void)
* 功    能：主函数
* 入口参数：无
* 出口参数：无
* 说    明：
* 调用方法：
****************************************************************************/ 
int main(void)
{	
	static  _Bool flag_ledtoogle=0;
  RCC_Configuration();	             //设置内部时钟及外设时钟使能
	LED_Configuration();
	KEY_Configuration();
  Usart1_Init();		             //串口1初始化  
  ADC_Configuration();				 //ADC初始化
  USART_OUT(USART1,"\r\n USART1 print AD_value -------------------------- \r\n"); 
  while(1)
  {
  	 if (ticks++ >= 900000) 
		{        //间隔时间显示转换结果
			ticks   = 0;
			Clock1s = 1;
			flag_ledtoogle^=1;
		}
		if(flag_ledtoogle)
		{
				GPIO_ResetBits(GPIOB, LED1);  //熄灭LED0-3	
		}		
		else
		{
				GPIO_SetBits(GPIOB, LED1);  //熄灭LED0-3	
		}
	 if (Clock1s) 
		 {
				Clock1s = 0;   
					 
				USART_OUT(USART1,"The current AD value = %d \r\n", ADC_ConvertedValue);
     }  
		 
		 if (GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5)  == 0x00)
		 {
				iap_jump(FLASH_IAP_ADDR);
		 }
  }
}
//=============================================================================================
//函数名称: void iap_jump(u32 iapxaddr)
//输入参数: appxaddr:用户代码起始地址.
//输出参数: 
//返回值  : 
//功能描述: 跳转到IAP
//注意事项: void
//=============================================================================================
void iap_jump(u32 iapxaddr)
{
	if(((*(vu32*)iapxaddr)&0x2FFE0000)==0x20000000)	//检查栈顶地址是否合法.0x20000000是sram的起始地址,也是程序的栈顶地址
	{ 
//		printf("ok\r\n");
		//Delay_Ms(10);
		jump2iap=(iapfun)*(vu32*)(iapxaddr+4);		//用户代码区第二个字为程序开始地址(复位地址)		
	//	MSR_MSP(*(vu32*)iapxaddr);					//初始化APP堆栈指针(用户代码区的第一个字用于存放栈顶地址)
		__set_MSP(*(__IO uint32_t*) iapxaddr);
		jump2iap();									//跳转到APP.
	}
	else
	{
//		printf("iap program loss,please check\r\n");
	}
}
/*******************************************************************************
  * @函数名称	KEY_Configuration
  * @函数说明   按键初始化
  * @输入参数   无
  * @输出参数   无
  * @返回参数   无
*******************************************************************************/
void KEY_Configuration(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    //配置按键
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}
/*******************************************************************************
  * @函数名称	LED_Configuration
  * @函数说明   配置使用LED
  * @输入参数   无
  * @输出参数   无
  * @返回参数   无
*******************************************************************************/
void LED_Configuration(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    //使能LED所在GPIO的时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
    //初始化LED的GPIO
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  	
		GPIO_InitStructure.GPIO_Pin =  LED1;
	  GPIO_Init(GPIOB, &GPIO_InitStructure);	
		GPIO_SetBits(GPIOB, LED1);  //熄灭LED0-3
	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD , ENABLE);	
	  //初始化LED的GPIO
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Pin =  LED2 | LED3;	 
		GPIO_Init(GPIOD, &GPIO_InitStructure);			
  
    GPIO_SetBits(GPIOD, LED2 | LED3);  //熄灭LED0-3
}

/****************************************************************************
* 名    称：void ADC_Configuration(void)
* 功    能：ADC 配置函数
* 入口参数：无
* 出口参数：无
* 说    明：
* 调用方法：
****************************************************************************/ 
void ADC_Configuration(void)
{
	ADC_InitTypeDef ADC_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	DMA_InitTypeDef DMA_InitStructure;

    //设置AD模拟输入端口为输入 1路AD 规则通道
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
  	GPIO_Init(GPIOC, &GPIO_InitStructure);
	/* Enable DMA clock */
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

   /* Enable ADC1 and GPIOC clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 , ENABLE);

  	/* DMA channel1 configuration ----------------------------------------------*/
	//使能DMA
	DMA_DeInit(DMA1_Channel1);
	DMA_InitStructure.DMA_PeripheralBaseAddr = ADC1_DR_Address;			            //DMA通道1的地址 
	DMA_InitStructure.DMA_MemoryBaseAddr = (u32)&ADC_ConvertedValue;	            //DMA传送地址
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;					            //传送方向
	DMA_InitStructure.DMA_BufferSize = 1;								            //传送内存大小，1个16位
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;	 
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;				            //传送内存地址递增
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;		//ADC1转换的数据是16位
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;				//传送的目的地址是16位宽度
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;									//循环
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	DMA_Init(DMA1_Channel1, &DMA_InitStructure);
    
	/* 允许DMA1通道1传输结束中断 */
	//DMA_ITConfig(DMA1_Channel1,DMA_IT_TC, ENABLE);


	//使能DMA通道1
	DMA_Cmd(DMA1_Channel1, ENABLE); 
  
  
	//ADC配置
	/* ADC转换时间： ─ STM32F103xx增强型产品：时钟为56MHz时为1μs(时钟为72MHz为1.17μs)
	ADC采样范围0-3.3V    */
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);                   //设置ADC的时钟为72MHZ/6=12M 

	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;	//ADC1工作在独立模式
	ADC_InitStructure.ADC_ScanConvMode = ENABLE;		//模数转换工作在扫描模式（多通道）还是单次（单通道）模式
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;	//模数转换工作在连续模式，还是单次模式
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;//转换由软件而不是外部触发启动
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//ADC数据右对齐
	ADC_InitStructure.ADC_NbrOfChannel = 1;               //规定了顺序进行规则转换的ADC通道的数目。这个数目的取值范围是1到16
	ADC_Init(ADC1, &ADC_InitStructure);
	
	/* ADC1 regular channels configuration [规则模式通道配置]*/ 

	//ADC1 规则通道配置
  	ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 1, ADC_SampleTime_55Cycles5);	  //通道11采样时间 55.5周期
  	

	//使能ADC1 DMA 
	ADC_DMACmd(ADC1, ENABLE);
	//使能ADC1
	ADC_Cmd(ADC1, ENABLE);	
	
	// 初始化ADC1校准寄存器
	ADC_ResetCalibration(ADC1);
	//检测ADC1校准寄存器初始化是否完成
	while(ADC_GetResetCalibrationStatus(ADC1));
	
	//开始校准ADC1
	ADC_StartCalibration(ADC1);
	//检测是否完成校准
	while(ADC_GetCalibrationStatus(ADC1));
	
	//ADC1转换启动
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);	 
}
/****************************************************************************
* 名    称：void RCC_Configuration(void)
* 功    能：系统时钟配置为72MHZ， 外设时钟配置
* 入口参数：无
* 出口参数：无
* 说    明：
* 调用方法：无 
****************************************************************************/ 
void RCC_Configuration(void){

  SystemInit(); 
  RCC_ADCCLKConfig(RCC_PCLK2_Div6); 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 , ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC 
  						| RCC_APB2Periph_GPIOD| RCC_APB2Periph_GPIOE , ENABLE);
}

/****************************************************************************
* 名    称：void Usart1_Init(void)
* 功    能：串口1初始化函数
* 入口参数：无
* 出口参数：无
* 说    明：
* 调用方法：无 
****************************************************************************/
void Usart1_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure;
 
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_USART1 , ENABLE);	 //使能串口1时钟

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13; 			      //LCD背光控制
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
  GPIO_ResetBits(GPIOD, GPIO_Pin_13);			              //LCD背光关闭	

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;	         		 //USART1 TX
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;    		 //复用推挽输出
  GPIO_Init(GPIOA, &GPIO_InitStructure);		    		 //A端口 

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;	         	 //USART1 RX
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   	 //复用开漏输入
  GPIO_Init(GPIOA, &GPIO_InitStructure);		         	 //A端口 

  USART_InitStructure.USART_BaudRate = 9600;						//速率115200bps
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;		//数据位8位
  USART_InitStructure.USART_StopBits = USART_StopBits_1;			//停止位1位
  USART_InitStructure.USART_Parity = USART_Parity_No;				//无校验位
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;   //无硬件流控
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;					//收发模式

  /* Configure USART1 */
  USART_Init(USART1, &USART_InitStructure);							//配置串口参数函数   
   /* Enable the USART1 */
  USART_Cmd(USART1, ENABLE);	
  
}
/******************************************************
		整形数据转字符串函数
        char *itoa(int value, char *string, int radix)
		radix=10 标示是10进制	非十进制，转换结果为0;  

	    例：d=-379;
		执行	itoa(d, buf, 10); 后
		
		buf="-379"							   			  
**********************************************************/
char *itoa(int value, char *string, int radix)
{
    int     i, d;
    int     flag = 0;
    char    *ptr = string;

    /* This implementation only works for decimal numbers. */
    if (radix != 10)
    {
        *ptr = 0;
        return string;
    }

    if (!value)
    {
        *ptr++ = 0x30;
        *ptr = 0;
        return string;
    }

    /* if this is a negative value insert the minus sign. */
    if (value < 0)
    {
        *ptr++ = '-';

        /* Make the value positive. */
        value *= -1;
    }

    for (i = 10000; i > 0; i /= 10)
    {
        d = value / i;

        if (d || flag)
        {
            *ptr++ = (char)(d + 0x30);
            value -= (d * i);
            flag = 1;
        }
    }

    /* Null terminate the string. */
    *ptr = 0;

    return string;

} /* NCL_Itoa */
/****************************************************************************
* 名    称：void USART_OUT(USART_TypeDef* USARTx, uint8_t *Data,...)
* 功    能：格式化串口输出函数
* 入口参数：USARTx:  指定串口
			Data：   发送数组
			...:     不定参数
* 出口参数：无
* 说    明：格式化串口输出函数
        	"\r"	回车符	   USART_OUT(USART1, "abcdefg\r")   
			"\n"	换行符	   USART_OUT(USART1, "abcdefg\r\n")
			"%s"	字符串	   USART_OUT(USART1, "字符串是：%s","abcdefg")
			"%d"	十进制	   USART_OUT(USART1, "a=%d",10)
* 调用方法：无 
****************************************************************************/
void USART_OUT(USART_TypeDef* USARTx, uint8_t *Data,...){ 

	const char *s;
    int d;
   
    char buf[16];
    va_list ap;
    va_start(ap, Data);

	while(*Data!=0){				                          //判断是否到达字符串结束符
		if(*Data==0x5c){									  //'\'
			switch (*++Data){
				case 'r':							          //回车符
					USART_SendData(USARTx, 0x0d);	   

					Data++;
					break;
				case 'n':							          //换行符
					USART_SendData(USARTx, 0x0a);	
					Data++;
					break;
				
				default:
					Data++;
				    break;
			}
			
			 
		}
		else if(*Data=='%'){									  //
			switch (*++Data){				
				case 's':										  //字符串
                	s = va_arg(ap, const char *);
                	for ( ; *s; s++) {
                    	USART_SendData(USARTx,*s);
						while(USART_GetFlagStatus(USARTx, USART_FLAG_TC)==RESET);
                	}
					Data++;
                	break;
            	case 'd':										  //十进制
                	d = va_arg(ap, int);
                	itoa(d, buf, 10);
                	for (s = buf; *s; s++) {
                    	USART_SendData(USARTx,*s);
						while(USART_GetFlagStatus(USARTx, USART_FLAG_TC)==RESET);
                	}
					Data++;
                	break;
				default:
					Data++;
				    break;
			}		 
		}
		else USART_SendData(USARTx, *Data++);
		while(USART_GetFlagStatus(USARTx, USART_FLAG_TC)==RESET);
	}
}
/******************* (C) COPYRIGHT 2013 奋斗STM32 *****END OF FILE****/

