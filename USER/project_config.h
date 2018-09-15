/////////////////////////////////////////////////////////////////////////////////	 
//STM32F103RCT6
//���������ļ�
//HWY 2018 09 13
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
//LED����
#define USE_LED0
#define USE_LED1

//����DMA 
#define USE_USART1_DMA
#define USE_USART2_DMA
#define USE_USART3_DMA
#define USART1_BaudRate 115200
#define USART2_BaudRate 115200
#define USART3_BaudRate 115200

/*USART1 ��غ궨�� */
/* UART1 GPIO define. */            //�궨��
#define USART1_GPIO_TX       		   GPIO_Pin_9
#define USART1_GPIO_RX       		   GPIO_Pin_10
#define USART1_GPIO_TX_PinSource       GPIO_PinSource9
#define USART1_GPIO_RX_PinSource       GPIO_PinSource10
#define USART1_GPIO          		   GPIOA
#define USART1_GPIO_RCC      		   RCC_APB2Periph_GPIOA
#define USART1_DATA_LEN  64  //���պͷ������ݵ���󳤶�
/*USART2 ��غ궨�� */
/* UART2 GPIO define. */
#define USART2_GPIO_TX       		   GPIO_Pin_2
#define USART2_GPIO_RX       		   GPIO_Pin_3
#define USART2_GPIO_TX_PinSource   GPIO_PinSource2
#define USART2_GPIO_RX_PinSource   GPIO_PinSource3
#define USART2_GPIO          		   GPIOA
#define USART2_GPIO_RCC      		   RCC_APB2Periph_GPIOA
#define USART2_DATA_LEN  64  //���պͷ������ݵ���󳤶�
/*USART3 ��غ궨�� */
/* UART3 GPIO define. */
#define USART3_GPIO_TX       		   GPIO_Pin_10
#define USART3_GPIO_RX       		   GPIO_Pin_11
#define USART3_GPIO_TX_PinSource   GPIO_PinSource10
#define USART3_GPIO_RX_PinSource   GPIO_PinSource11
#define USART3_GPIO          		   GPIOB
#define USART3_GPIO_RCC      		   RCC_APB2Periph_GPIOB
#define USART3_DATA_LEN  64  //���պͷ������ݵ���󳤶�

//PWM Ĭ��TIM4
#define USE_PWM_CH1
#define USE_PWM_CH2
//#define USE_PWM_CH3
//#define USE_PWM_CH4

/*PWM��غ궨��*/
#define PWM_CH1_GPIO     GPIO_Pin_6
#define PWM_CH2_GPIO     GPIO_Pin_7
#define PWM_CH3_GPIO     GPIO_Pin_8
#define PWM_CH4_GPIO     GPIO_Pin_9
#define PWM_GPIO_RCC     RCC_APB2Periph_GPIOB
#define PWM_TIM_RCC      RCC_APB1Periph_TIM4
#define PWM_AFIO_RCC     RCC_APB2Periph_AFIO
#define PWM_GPIO         GPIOB
#define PWM_TIM          TIM4

//Ĭ��ʹ��PWMƵ�� 100Khz
#define PWM_Frequency 100
#define PWM_ARR  (72000/PWM_Frequency)-1
#define PWM_PSC 0 //����Ƶ

//CRCУ�鷽�� Ĭ��ֻ�ܶ���һ�� ��ʹ��Ӳ��CRC ���� ������CRC

//ps: Ŀǰֻд�����CRC���� Ӳ��CRC��ʱ������
//#define USE_CRC_HARDWARE
#define USE_CRC_SOFTWARE

//����8�� Ԥ������ �ܹ�����10����������
#define USE_PA0_KEY
#define USE_PA1_KEY
//#define USE_PD2_KEY 
#define USE_PC3_KEY
#define USE_PC4_KEY
#define USE_PC5_KEY
#define USE_PC6_KEY
#define USE_PC7_KEY
//#define USE_PC8_KEY
//#define USE_PC9_KEY

//GPIO 4+3
//4�����Ƶ������ת 3������LED��
//ȫ������λ������
#define USE_MOTOR_GPIO
#define USE_LED_GPIO

#ifdef USE_MOTOR_GPIO
#define  MOTOR_GPIO_RCC RCC_APB2Periph_GPIOB
#define  MOTOR_GPIO_PB12 GPIO_Pin_12
#define  MOTOR_GPIO_PB13 GPIO_Pin_13
#define  MOTOR_GPIO_PB14 GPIO_Pin_14
#define  MOTOR_GPIO_PB15 GPIO_Pin_15
#define  MOTOR_GPIO         GPIOB
#define MOTOR1_IN1 PBout(12)	// PB12
#define MOTOR1_IN2 PBout(13)	// PB13
#define MOTOR2_IN1 PBout(14)	// PB14
#define MOTOR2_IN2 PBout(15)	// PB15
#endif

#ifdef USE_LED_GPIO
#define  LED_GPIO_RCC RCC_APB2Periph_GPIOC
#define  LED_GPIO_PC10 GPIO_Pin_10
#define  LED_GPIO_PC11 GPIO_Pin_11
#define  LED_GPIO_PC12 GPIO_Pin_12
#define  LED_GPIO         GPIOC
#define LED0 PCout(10)	// PC10
#define LED1 PCout(11)	// PC11
#define LED2 PCout(12)	// PC12
#endif
//�����


//�������
#define USE_MOTOR_CONTROL1

#define USE_MOTOR_CONTROL2





//��λ��ͨ�� USART1_PROTOCOL
/* ��һ���ְ����ź��ɰ����ж�ֱ�ӷ���*/

/* ��������Ѫ����Ϣ������ѭ���п���ʱ���ͣ�����Ƶ��1HZ��ʵ��ÿ�θ��º�������������*/ 
//Ѫѹģ��   USART2_PROTOCOL

//Ѫ��ģ��   USARAT3_PROTOCOL
/* */
#define SPO2_DATA_LEN 10


