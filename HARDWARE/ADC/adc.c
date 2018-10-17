#include "adc.h"
#include "delay.h"		
#include "project_config.h"
#include "stm32f10x_adc.h"
//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//DMA-AD采样驱动 VREF+采用板载的3.3V
//引脚 PA0
//结果存在adc_value数组中
//HWY 2017 10 20
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 
unsigned short int adc_value[ADC_BUF_LEN];  //结果数组

#ifdef USE_PA0_ADC1_IN0
void ADC_Sensor_Init(void)
{
	    
    //采样脚IO口设置     
    GPIO_InitTypeDef GPIO_InitStructure;  

	  GPIO_InitStructure.GPIO_Pin = ADC_GPIO_PA0; 			//管脚指定
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;        			//管脚模式:输入口  模拟输入    
    GPIO_Init(ADC_GPIO, &GPIO_InitStructure);  

	
	  
    //DMA设置  		
    DMA_InitTypeDef DMA_InitStructure;	     															   	
    DMA_DeInit(DMA1_Channel1);  											   //DMA通道配置   DMA2数据流3通道1   
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&ADC1->DR); 	   //外设地址 
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)adc_value; //内存地址   
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;  				//dma传输方向  外设到内存
    DMA_InitStructure.DMA_BufferSize = ADC_BUF_LEN;  						//设置DMA在传输时缓冲区的长度  
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable; 		//设置DMA的外设递增模式，一个外设   
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;    				//设置DMA的内存递增模式 数组自增 
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;  //外设数据字长   
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;     //内存数据字长 
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;  						//设置DMA的传输模式  循环传输  
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;    	    			//设置DMA的优先级别             
    DMA_InitStructure.DMA_M2M =  DMA_M2M_Disable; //禁止内存到内存的传输	              
    DMA_Init(DMA1_Channel1, &DMA_InitStructure); 							//配置DMA的通道       
    DMA_Cmd(DMA1_Channel1, ENABLE);   										//使能通道       
  
    //ADC配置      	
	  ADC_InitTypeDef ADC_InitStructure;   
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent; //独立ADC模式		    
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;     						  //扫描方式     
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;    					  //连续转换    
   	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;	//外部触发禁止，软件触发
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;    				  //数据右对齐   
    ADC_InitStructure.ADC_NbrOfChannel = 1;    				  //1个转换在规则序列中
    ADC_Init(ADC1, &ADC_InitStructure);	
   
		
		RCC_ADCCLKConfig(RCC_PCLK2_Div6);//配置ADC时钟，为PCLK2的6分频，即72/6=12MHZ		
    //规则模式通道配置 
		ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_55Cycles5);   
    //使能ADC的DMA    
		ADC_DMACmd(ADC1, ENABLE); 
    ADC_Cmd(ADC1, ENABLE);    												 //使能ADC1		
		ADC_ResetCalibration(ADC1);//复位校准寄存器	
		while(ADC_GetResetCalibrationStatus(ADC1));//等待校准寄存器复位完成 	
		ADC_StartCalibration(ADC1);//ADC校准	
		while(ADC_GetCalibrationStatus(ADC1));//等待校准完成


    //开启ADC1的软件转换  
		ADC_SoftwareStartConvCmd(ADC1,ENABLE);      
}
  
		  
u16 Average()
{
	u16 sum=0;
	u16 i;
	for(i=0;i<ADC_BUF_LEN;i++)	
	{
		sum+=adc_value[i];
	}
	sum/=(ADC_BUFx_LEN);//    取平均值   
	return sum;	
}


#endif



