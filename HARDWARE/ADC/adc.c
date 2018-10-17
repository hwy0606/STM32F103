#include "adc.h"
#include "delay.h"		
#include "project_config.h"
#include "stm32f10x_adc.h"
//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//DMA-AD�������� VREF+���ð��ص�3.3V
//���� PA0
//�������adc_value������
//HWY 2017 10 20
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 
unsigned short int adc_value[ADC_BUF_LEN];  //�������

#ifdef USE_PA0_ADC1_IN0
void ADC_Sensor_Init(void)
{
	    
    //������IO������     
    GPIO_InitTypeDef GPIO_InitStructure;  

	  GPIO_InitStructure.GPIO_Pin = ADC_GPIO_PA0; 			//�ܽ�ָ��
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;        			//�ܽ�ģʽ:�����  ģ������    
    GPIO_Init(ADC_GPIO, &GPIO_InitStructure);  

	
	  
    //DMA����  		
    DMA_InitTypeDef DMA_InitStructure;	     															   	
    DMA_DeInit(DMA1_Channel1);  											   //DMAͨ������   DMA2������3ͨ��1   
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&ADC1->DR); 	   //�����ַ 
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)adc_value; //�ڴ��ַ   
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;  				//dma���䷽��  ���赽�ڴ�
    DMA_InitStructure.DMA_BufferSize = ADC_BUF_LEN;  						//����DMA�ڴ���ʱ�������ĳ���  
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable; 		//����DMA���������ģʽ��һ������   
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;    				//����DMA���ڴ����ģʽ �������� 
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;  //���������ֳ�   
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;     //�ڴ������ֳ� 
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;  						//����DMA�Ĵ���ģʽ  ѭ������  
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;    	    			//����DMA�����ȼ���             
    DMA_InitStructure.DMA_M2M =  DMA_M2M_Disable; //��ֹ�ڴ浽�ڴ�Ĵ���	              
    DMA_Init(DMA1_Channel1, &DMA_InitStructure); 							//����DMA��ͨ��       
    DMA_Cmd(DMA1_Channel1, ENABLE);   										//ʹ��ͨ��       
  
    //ADC����      	
	  ADC_InitTypeDef ADC_InitStructure;   
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent; //����ADCģʽ		    
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;     						  //ɨ�跽ʽ     
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;    					  //����ת��    
   	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;	//�ⲿ������ֹ���������
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;    				  //�����Ҷ���   
    ADC_InitStructure.ADC_NbrOfChannel = 1;    				  //1��ת���ڹ���������
    ADC_Init(ADC1, &ADC_InitStructure);	
   
		
		RCC_ADCCLKConfig(RCC_PCLK2_Div6);//����ADCʱ�ӣ�ΪPCLK2��6��Ƶ����72/6=12MHZ		
    //����ģʽͨ������ 
		ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_55Cycles5);   
    //ʹ��ADC��DMA    
		ADC_DMACmd(ADC1, ENABLE); 
    ADC_Cmd(ADC1, ENABLE);    												 //ʹ��ADC1		
		ADC_ResetCalibration(ADC1);//��λУ׼�Ĵ���	
		while(ADC_GetResetCalibrationStatus(ADC1));//�ȴ�У׼�Ĵ�����λ��� 	
		ADC_StartCalibration(ADC1);//ADCУ׼	
		while(ADC_GetCalibrationStatus(ADC1));//�ȴ�У׼���


    //����ADC1�����ת��  
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
	sum/=(ADC_BUFx_LEN);//    ȡƽ��ֵ   
	return sum;	
}


#endif



