#line 1 "user\\main.c"




















 
 
#line 1 ".\\CM3\\stm32f10x.h"







































 



 



 
    
#line 56 ".\\CM3\\stm32f10x.h"
  


 
  


 

#line 75 ".\\CM3\\stm32f10x.h"


















 





#line 107 ".\\CM3\\stm32f10x.h"







            
#line 122 ".\\CM3\\stm32f10x.h"





 






 
#line 143 ".\\CM3\\stm32f10x.h"



 



 



 
#line 162 ".\\CM3\\stm32f10x.h"




 
typedef enum IRQn
{
 
  NonMaskableInt_IRQn         = -14,     
  MemoryManagement_IRQn       = -12,     
  BusFault_IRQn               = -11,     
  UsageFault_IRQn             = -10,     
  SVCall_IRQn                 = -5,      
  DebugMonitor_IRQn           = -4,      
  PendSV_IRQn                 = -2,      
  SysTick_IRQn                = -1,      

 
  WWDG_IRQn                   = 0,       
  PVD_IRQn                    = 1,       
  TAMPER_IRQn                 = 2,       
  RTC_IRQn                    = 3,       
  FLASH_IRQn                  = 4,       
  RCC_IRQn                    = 5,       
  EXTI0_IRQn                  = 6,       
  EXTI1_IRQn                  = 7,       
  EXTI2_IRQn                  = 8,       
  EXTI3_IRQn                  = 9,       
  EXTI4_IRQn                  = 10,      
  DMA1_Channel1_IRQn          = 11,      
  DMA1_Channel2_IRQn          = 12,      
  DMA1_Channel3_IRQn          = 13,      
  DMA1_Channel4_IRQn          = 14,      
  DMA1_Channel5_IRQn          = 15,      
  DMA1_Channel6_IRQn          = 16,      
  DMA1_Channel7_IRQn          = 17,      

#line 221 ".\\CM3\\stm32f10x.h"

#line 242 ".\\CM3\\stm32f10x.h"

#line 270 ".\\CM3\\stm32f10x.h"

#line 296 ".\\CM3\\stm32f10x.h"


  ADC1_2_IRQn                 = 18,      
  USB_HP_CAN1_TX_IRQn         = 19,      
  USB_LP_CAN1_RX0_IRQn        = 20,      
  CAN1_RX1_IRQn               = 21,      
  CAN1_SCE_IRQn               = 22,      
  EXTI9_5_IRQn                = 23,      
  TIM1_BRK_IRQn               = 24,      
  TIM1_UP_IRQn                = 25,      
  TIM1_TRG_COM_IRQn           = 26,      
  TIM1_CC_IRQn                = 27,      
  TIM2_IRQn                   = 28,      
  TIM3_IRQn                   = 29,      
  TIM4_IRQn                   = 30,      
  I2C1_EV_IRQn                = 31,      
  I2C1_ER_IRQn                = 32,      
  I2C2_EV_IRQn                = 33,      
  I2C2_ER_IRQn                = 34,      
  SPI1_IRQn                   = 35,      
  SPI2_IRQn                   = 36,      
  USART1_IRQn                 = 37,      
  USART2_IRQn                 = 38,      
  USART3_IRQn                 = 39,      
  EXTI15_10_IRQn              = 40,      
  RTCAlarm_IRQn               = 41,      
  USBWakeUp_IRQn              = 42,      
  TIM8_BRK_IRQn               = 43,      
  TIM8_UP_IRQn                = 44,      
  TIM8_TRG_COM_IRQn           = 45,      
  TIM8_CC_IRQn                = 46,      
  ADC3_IRQn                   = 47,      
  FSMC_IRQn                   = 48,      
  SDIO_IRQn                   = 49,      
  TIM5_IRQn                   = 50,      
  SPI3_IRQn                   = 51,      
  UART4_IRQn                  = 52,      
  UART5_IRQn                  = 53,      
  TIM6_IRQn                   = 54,      
  TIM7_IRQn                   = 55,      
  DMA2_Channel1_IRQn          = 56,      
  DMA2_Channel2_IRQn          = 57,      
  DMA2_Channel3_IRQn          = 58,      
  DMA2_Channel4_5_IRQn        = 59       


#line 381 ".\\CM3\\stm32f10x.h"

#line 426 ".\\CM3\\stm32f10x.h"

#line 472 ".\\CM3\\stm32f10x.h"
} IRQn_Type;



 

#line 1 ".\\CM3\\core_cm3.h"
 




















 





































 

 
 
 
 
 
 
 
 








 











#line 1 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
 
 





 









     
#line 27 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
     











#line 46 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"





 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     




typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;


     
typedef   signed     long long intmax_t;
typedef unsigned     long long uintmax_t;




     

     





     





     





     

     





     





     





     

     





     





     





     

     






     






     






     

     


     


     


     

     
#line 216 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     



     






     
    
 



#line 241 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     







     










     











#line 305 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"






 
#line 91 ".\\CM3\\core_cm3.h"

















 

#line 117 ".\\CM3\\core_cm3.h"





 


 





 
typedef struct
{
  volatile uint32_t ISER[8];                       
       uint32_t RESERVED0[24];                                   
  volatile uint32_t ICER[8];                       
       uint32_t RSERVED1[24];                                    
  volatile uint32_t ISPR[8];                       
       uint32_t RESERVED2[24];                                   
  volatile uint32_t ICPR[8];                       
       uint32_t RESERVED3[24];                                   
  volatile uint32_t IABR[8];                       
       uint32_t RESERVED4[56];                                   
  volatile uint8_t  IP[240];                       
       uint32_t RESERVED5[644];                                  
  volatile  uint32_t STIR;                          
}  NVIC_Type;                                               
   





 
typedef struct
{
  volatile const  uint32_t CPUID;                         
  volatile uint32_t ICSR;                          
  volatile uint32_t VTOR;                          
  volatile uint32_t AIRCR;                         
  volatile uint32_t SCR;                           
  volatile uint32_t CCR;                           
  volatile uint8_t  SHP[12];                       
  volatile uint32_t SHCSR;                         
  volatile uint32_t CFSR;                          
  volatile uint32_t HFSR;                          
  volatile uint32_t DFSR;                          
  volatile uint32_t MMFAR;                         
  volatile uint32_t BFAR;                          
  volatile uint32_t AFSR;                          
  volatile const  uint32_t PFR[2];                        
  volatile const  uint32_t DFR;                           
  volatile const  uint32_t ADR;                           
  volatile const  uint32_t MMFR[4];                       
  volatile const  uint32_t ISAR[5];                       
} SCB_Type;                                                

 












 






























 






 





















 









 


















 
































                                     









 









 









 














   





 
typedef struct
{
  volatile uint32_t CTRL;                          
  volatile uint32_t LOAD;                          
  volatile uint32_t VAL;                           
  volatile const  uint32_t CALIB;                         
} SysTick_Type;

 












 



 



 








   





 
typedef struct
{
  volatile  union  
  {
    volatile  uint8_t    u8;                        
    volatile  uint16_t   u16;                       
    volatile  uint32_t   u32;                       
  }  PORT [32];                                
       uint32_t RESERVED0[864];                                 
  volatile uint32_t TER;                           
       uint32_t RESERVED1[15];                                  
  volatile uint32_t TPR;                           
       uint32_t RESERVED2[15];                                  
  volatile uint32_t TCR;                           
       uint32_t RESERVED3[29];                                  
  volatile uint32_t IWR;                           
  volatile uint32_t IRR;                           
  volatile uint32_t IMCR;                          
       uint32_t RESERVED4[43];                                  
  volatile uint32_t LAR;                           
  volatile uint32_t LSR;                           
       uint32_t RESERVED5[6];                                   
  volatile const  uint32_t PID4;                          
  volatile const  uint32_t PID5;                          
  volatile const  uint32_t PID6;                          
  volatile const  uint32_t PID7;                          
  volatile const  uint32_t PID0;                          
  volatile const  uint32_t PID1;                          
  volatile const  uint32_t PID2;                          
  volatile const  uint32_t PID3;                          
  volatile const  uint32_t CID0;                          
  volatile const  uint32_t CID1;                          
  volatile const  uint32_t CID2;                          
  volatile const  uint32_t CID3;                          
} ITM_Type;                                                

 



 
























 



 



 



 








   





 
typedef struct
{
       uint32_t RESERVED0;
  volatile const  uint32_t ICTR;                          



       uint32_t RESERVED1;

} InterruptType_Type;

 



 








   


#line 614 ".\\CM3\\core_cm3.h"





 
typedef struct
{
  volatile uint32_t DHCSR;                         
  volatile  uint32_t DCRSR;                         
  volatile uint32_t DCRDR;                         
  volatile uint32_t DEMCR;                         
} CoreDebug_Type;

 




































 






 






































   


 
#line 721 ".\\CM3\\core_cm3.h"

#line 728 ".\\CM3\\core_cm3.h"






   




 





#line 758 ".\\CM3\\core_cm3.h"


 


 




#line 783 ".\\CM3\\core_cm3.h"


 
 
 
 








 
extern uint32_t __get_PSP(void);








 
extern void __set_PSP(uint32_t topOfProcStack);








 
extern uint32_t __get_MSP(void);








 
extern void __set_MSP(uint32_t topOfMainStack);








 
extern uint32_t __REV16(uint16_t value);








 
extern int32_t __REVSH(int16_t value);


#line 933 ".\\CM3\\core_cm3.h"





 








 
static __inline uint32_t  __get_BASEPRI(void)
{
  register uint32_t __regBasePri         __asm("basepri");
  return(__regBasePri);
}







 
static __inline void __set_BASEPRI(uint32_t basePri)
{
  register uint32_t __regBasePri         __asm("basepri");
  __regBasePri = (basePri & 0xff);
}







 
static __inline uint32_t __get_PRIMASK(void)
{
  register uint32_t __regPriMask         __asm("primask");
  return(__regPriMask);
}







 
static __inline void __set_PRIMASK(uint32_t priMask)
{
  register uint32_t __regPriMask         __asm("primask");
  __regPriMask = (priMask);
}







 
static __inline uint32_t __get_FAULTMASK(void)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  return(__regFaultMask);
}







 
static __inline void __set_FAULTMASK(uint32_t faultMask)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  __regFaultMask = (faultMask & 1);
}







 
static __inline uint32_t __get_CONTROL(void)
{
  register uint32_t __regControl         __asm("control");
  return(__regControl);
}







 
static __inline void __set_CONTROL(uint32_t control)
{
  register uint32_t __regControl         __asm("control");
  __regControl = control;
}





#line 1445 ".\\CM3\\core_cm3.h"







 
 

 











 
static __inline void NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  uint32_t reg_value;
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);                          
  
  reg_value  =  ((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR;                                                    
  reg_value &= ~((0xFFFFul << 16) | (7ul << 8));              
  reg_value  =  (reg_value                       |
                (0x5FA << 16) | 
                (PriorityGroupTmp << 8));                                      
  ((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR =  reg_value;
}








 
static __inline uint32_t NVIC_GetPriorityGrouping(void)
{
  return ((((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR & (7ul << 8)) >> 8);    
}








 
static __inline void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ISER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}








 
static __inline void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ICER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}









 
static __inline uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  return((uint32_t) ((((NVIC_Type *) ((0xE000E000) + 0x0100))->ISPR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0));  
}








 
static __inline void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ISPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}








 
static __inline void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ICPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}









 
static __inline uint32_t NVIC_GetActive(IRQn_Type IRQn)
{
  return((uint32_t)((((NVIC_Type *) ((0xE000E000) + 0x0100))->IABR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0));  
}












 
static __inline void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if(IRQn < 0) {
    ((SCB_Type *) ((0xE000E000) + 0x0D00))->SHP[((uint32_t)(IRQn) & 0xF)-4] = ((priority << (8 - 4)) & 0xff); }  
  else {
    ((NVIC_Type *) ((0xE000E000) + 0x0100))->IP[(uint32_t)(IRQn)] = ((priority << (8 - 4)) & 0xff);    }         
}















 
static __inline uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{

  if(IRQn < 0) {
    return((uint32_t)(((SCB_Type *) ((0xE000E000) + 0x0D00))->SHP[((uint32_t)(IRQn) & 0xF)-4] >> (8 - 4)));  }  
  else {
    return((uint32_t)(((NVIC_Type *) ((0xE000E000) + 0x0100))->IP[(uint32_t)(IRQn)]           >> (8 - 4)));  }  
}
















 
static __inline uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);           
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7 - PriorityGroupTmp) > 4) ? 4 : 7 - PriorityGroupTmp;
  SubPriorityBits     = ((PriorityGroupTmp + 4) < 7) ? 0 : PriorityGroupTmp - 7 + 4;
 
  return (
           ((PreemptPriority & ((1 << (PreemptPriorityBits)) - 1)) << SubPriorityBits) |
           ((SubPriority     & ((1 << (SubPriorityBits    )) - 1)))
         );
}
















 
static __inline void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* pPreemptPriority, uint32_t* pSubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);           
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7 - PriorityGroupTmp) > 4) ? 4 : 7 - PriorityGroupTmp;
  SubPriorityBits     = ((PriorityGroupTmp + 4) < 7) ? 0 : PriorityGroupTmp - 7 + 4;
  
  *pPreemptPriority = (Priority >> SubPriorityBits) & ((1 << (PreemptPriorityBits)) - 1);
  *pSubPriority     = (Priority                   ) & ((1 << (SubPriorityBits    )) - 1);
}



 












 
static __inline uint32_t SysTick_Config(uint32_t ticks)
{ 
  if (ticks > (0xFFFFFFul << 0))  return (1);             
                                                               
  ((SysTick_Type *) ((0xE000E000) + 0x0010))->LOAD  = (ticks & (0xFFFFFFul << 0)) - 1;       
  NVIC_SetPriority (SysTick_IRQn, (1<<4) - 1);   
  ((SysTick_Type *) ((0xE000E000) + 0x0010))->VAL   = 0;                                           
  ((SysTick_Type *) ((0xE000E000) + 0x0010))->CTRL  = (1ul << 2) | 
                   (1ul << 1)   | 
                   (1ul << 0);                     
  return (0);                                                   
}






 





 
static __inline void NVIC_SystemReset(void)
{
  ((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR  = ((0x5FA << 16)      | 
                 (((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR & (7ul << 8)) | 
                 (1ul << 2));                    
  __dsb(0);                                                                    
  while(1);                                                     
}

   



 






 
 

extern volatile int ITM_RxBuffer;                     












 
static __inline uint32_t ITM_SendChar (uint32_t ch)
{
  if ((((CoreDebug_Type *) (0xE000EDF0))->DEMCR & (1ul << 24))  &&       
      (((ITM_Type *) (0xE0000000))->TCR & (1ul << 0))                  &&       
      (((ITM_Type *) (0xE0000000))->TER & (1ul << 0)        )                    )      
  {
    while (((ITM_Type *) (0xE0000000))->PORT[0].u32 == 0);
    ((ITM_Type *) (0xE0000000))->PORT[0].u8 = (uint8_t) ch;
  }  
  return (ch);
}










 
static __inline int ITM_ReceiveChar (void) {
  int ch = -1;                                

  if (ITM_RxBuffer != 0x5AA55AA5) {
    ch = ITM_RxBuffer;
    ITM_RxBuffer = 0x5AA55AA5;        
  }
  
  return (ch); 
}









 
static __inline int ITM_CheckChar (void) {

  if (ITM_RxBuffer == 0x5AA55AA5) {
    return (0);                                  
  } else {
    return (1);                                  
  }
}

   






   



 
#line 479 ".\\CM3\\stm32f10x.h"
#line 1 ".\\CM3\\system_stm32f10x.h"



















 



 



   
  


 









 



 




 

extern uint32_t SystemCoreClock;           



 



 



 



 



 



 
  
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);


 









 
  


   
 
#line 480 ".\\CM3\\stm32f10x.h"
#line 481 ".\\CM3\\stm32f10x.h"



   

 
typedef int32_t  s32;
typedef int16_t s16;
typedef int8_t  s8;

typedef const int32_t sc32;   
typedef const int16_t sc16;   
typedef const int8_t sc8;    

typedef volatile int32_t  vs32;
typedef volatile int16_t  vs16;
typedef volatile int8_t   vs8;

typedef volatile const int32_t vsc32;   
typedef volatile const int16_t vsc16;   
typedef volatile const int8_t vsc8;    

typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

typedef const uint32_t uc32;   
typedef const uint16_t uc16;   
typedef const uint8_t uc8;    

typedef volatile uint32_t  vu32;
typedef volatile uint16_t vu16;
typedef volatile uint8_t  vu8;

typedef volatile const uint32_t vuc32;   
typedef volatile const uint16_t vuc16;   
typedef volatile const uint8_t vuc8;    


typedef enum {FALSE = 0, TRUE = !FALSE} bool;


typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;

typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;


typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;

 





 



    



 

typedef struct
{
  volatile uint32_t SR;
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SMPR1;
  volatile uint32_t SMPR2;
  volatile uint32_t JOFR1;
  volatile uint32_t JOFR2;
  volatile uint32_t JOFR3;
  volatile uint32_t JOFR4;
  volatile uint32_t HTR;
  volatile uint32_t LTR;
  volatile uint32_t SQR1;
  volatile uint32_t SQR2;
  volatile uint32_t SQR3;
  volatile uint32_t JSQR;
  volatile uint32_t JDR1;
  volatile uint32_t JDR2;
  volatile uint32_t JDR3;
  volatile uint32_t JDR4;
  volatile uint32_t DR;
} ADC_TypeDef;



 

typedef struct
{
  uint32_t  RESERVED0;
  volatile uint16_t DR1;
  uint16_t  RESERVED1;
  volatile uint16_t DR2;
  uint16_t  RESERVED2;
  volatile uint16_t DR3;
  uint16_t  RESERVED3;
  volatile uint16_t DR4;
  uint16_t  RESERVED4;
  volatile uint16_t DR5;
  uint16_t  RESERVED5;
  volatile uint16_t DR6;
  uint16_t  RESERVED6;
  volatile uint16_t DR7;
  uint16_t  RESERVED7;
  volatile uint16_t DR8;
  uint16_t  RESERVED8;
  volatile uint16_t DR9;
  uint16_t  RESERVED9;
  volatile uint16_t DR10;
  uint16_t  RESERVED10; 
  volatile uint16_t RTCCR;
  uint16_t  RESERVED11;
  volatile uint16_t CR;
  uint16_t  RESERVED12;
  volatile uint16_t CSR;
  uint16_t  RESERVED13[5];
  volatile uint16_t DR11;
  uint16_t  RESERVED14;
  volatile uint16_t DR12;
  uint16_t  RESERVED15;
  volatile uint16_t DR13;
  uint16_t  RESERVED16;
  volatile uint16_t DR14;
  uint16_t  RESERVED17;
  volatile uint16_t DR15;
  uint16_t  RESERVED18;
  volatile uint16_t DR16;
  uint16_t  RESERVED19;
  volatile uint16_t DR17;
  uint16_t  RESERVED20;
  volatile uint16_t DR18;
  uint16_t  RESERVED21;
  volatile uint16_t DR19;
  uint16_t  RESERVED22;
  volatile uint16_t DR20;
  uint16_t  RESERVED23;
  volatile uint16_t DR21;
  uint16_t  RESERVED24;
  volatile uint16_t DR22;
  uint16_t  RESERVED25;
  volatile uint16_t DR23;
  uint16_t  RESERVED26;
  volatile uint16_t DR24;
  uint16_t  RESERVED27;
  volatile uint16_t DR25;
  uint16_t  RESERVED28;
  volatile uint16_t DR26;
  uint16_t  RESERVED29;
  volatile uint16_t DR27;
  uint16_t  RESERVED30;
  volatile uint16_t DR28;
  uint16_t  RESERVED31;
  volatile uint16_t DR29;
  uint16_t  RESERVED32;
  volatile uint16_t DR30;
  uint16_t  RESERVED33; 
  volatile uint16_t DR31;
  uint16_t  RESERVED34;
  volatile uint16_t DR32;
  uint16_t  RESERVED35;
  volatile uint16_t DR33;
  uint16_t  RESERVED36;
  volatile uint16_t DR34;
  uint16_t  RESERVED37;
  volatile uint16_t DR35;
  uint16_t  RESERVED38;
  volatile uint16_t DR36;
  uint16_t  RESERVED39;
  volatile uint16_t DR37;
  uint16_t  RESERVED40;
  volatile uint16_t DR38;
  uint16_t  RESERVED41;
  volatile uint16_t DR39;
  uint16_t  RESERVED42;
  volatile uint16_t DR40;
  uint16_t  RESERVED43;
  volatile uint16_t DR41;
  uint16_t  RESERVED44;
  volatile uint16_t DR42;
  uint16_t  RESERVED45;    
} BKP_TypeDef;
  


 

typedef struct
{
  volatile uint32_t TIR;
  volatile uint32_t TDTR;
  volatile uint32_t TDLR;
  volatile uint32_t TDHR;
} CAN_TxMailBox_TypeDef;



 
  
typedef struct
{
  volatile uint32_t RIR;
  volatile uint32_t RDTR;
  volatile uint32_t RDLR;
  volatile uint32_t RDHR;
} CAN_FIFOMailBox_TypeDef;



 
  
typedef struct
{
  volatile uint32_t FR1;
  volatile uint32_t FR2;
} CAN_FilterRegister_TypeDef;



 
  
typedef struct
{
  volatile uint32_t MCR;
  volatile uint32_t MSR;
  volatile uint32_t TSR;
  volatile uint32_t RF0R;
  volatile uint32_t RF1R;
  volatile uint32_t IER;
  volatile uint32_t ESR;
  volatile uint32_t BTR;
  uint32_t  RESERVED0[88];
  CAN_TxMailBox_TypeDef sTxMailBox[3];
  CAN_FIFOMailBox_TypeDef sFIFOMailBox[2];
  uint32_t  RESERVED1[12];
  volatile uint32_t FMR;
  volatile uint32_t FM1R;
  uint32_t  RESERVED2;
  volatile uint32_t FS1R;
  uint32_t  RESERVED3;
  volatile uint32_t FFA1R;
  uint32_t  RESERVED4;
  volatile uint32_t FA1R;
  uint32_t  RESERVED5[8];

  CAN_FilterRegister_TypeDef sFilterRegister[14];



} CAN_TypeDef;



 
typedef struct
{
  volatile uint32_t CFGR;
  volatile uint32_t OAR;
  volatile uint32_t PRES;
  volatile uint32_t ESR;
  volatile uint32_t CSR;
  volatile uint32_t TXD;
  volatile uint32_t RXD;  
} CEC_TypeDef;



 

typedef struct
{
  volatile uint32_t DR;
  volatile uint8_t  IDR;
  uint8_t   RESERVED0;
  uint16_t  RESERVED1;
  volatile uint32_t CR;
} CRC_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t SWTRIGR;
  volatile uint32_t DHR12R1;
  volatile uint32_t DHR12L1;
  volatile uint32_t DHR8R1;
  volatile uint32_t DHR12R2;
  volatile uint32_t DHR12L2;
  volatile uint32_t DHR8R2;
  volatile uint32_t DHR12RD;
  volatile uint32_t DHR12LD;
  volatile uint32_t DHR8RD;
  volatile uint32_t DOR1;
  volatile uint32_t DOR2;



} DAC_TypeDef;



 

typedef struct
{
  volatile uint32_t IDCODE;
  volatile uint32_t CR;	
}DBGMCU_TypeDef;



 

typedef struct
{
  volatile uint32_t CCR;
  volatile uint32_t CNDTR;
  volatile uint32_t CPAR;
  volatile uint32_t CMAR;
} DMA_Channel_TypeDef;

typedef struct
{
  volatile uint32_t ISR;
  volatile uint32_t IFCR;
} DMA_TypeDef;



 

typedef struct
{
  volatile uint32_t MACCR;
  volatile uint32_t MACFFR;
  volatile uint32_t MACHTHR;
  volatile uint32_t MACHTLR;
  volatile uint32_t MACMIIAR;
  volatile uint32_t MACMIIDR;
  volatile uint32_t MACFCR;
  volatile uint32_t MACVLANTR;              
       uint32_t RESERVED0[2];
  volatile uint32_t MACRWUFFR;              
  volatile uint32_t MACPMTCSR;
       uint32_t RESERVED1[2];
  volatile uint32_t MACSR;                  
  volatile uint32_t MACIMR;
  volatile uint32_t MACA0HR;
  volatile uint32_t MACA0LR;
  volatile uint32_t MACA1HR;
  volatile uint32_t MACA1LR;
  volatile uint32_t MACA2HR;
  volatile uint32_t MACA2LR;
  volatile uint32_t MACA3HR;
  volatile uint32_t MACA3LR;                
       uint32_t RESERVED2[40];
  volatile uint32_t MMCCR;                  
  volatile uint32_t MMCRIR;
  volatile uint32_t MMCTIR;
  volatile uint32_t MMCRIMR;
  volatile uint32_t MMCTIMR;                
       uint32_t RESERVED3[14];
  volatile uint32_t MMCTGFSCCR;             
  volatile uint32_t MMCTGFMSCCR;
       uint32_t RESERVED4[5];
  volatile uint32_t MMCTGFCR;
       uint32_t RESERVED5[10];
  volatile uint32_t MMCRFCECR;
  volatile uint32_t MMCRFAECR;
       uint32_t RESERVED6[10];
  volatile uint32_t MMCRGUFCR;
       uint32_t RESERVED7[334];
  volatile uint32_t PTPTSCR;
  volatile uint32_t PTPSSIR;
  volatile uint32_t PTPTSHR;
  volatile uint32_t PTPTSLR;
  volatile uint32_t PTPTSHUR;
  volatile uint32_t PTPTSLUR;
  volatile uint32_t PTPTSAR;
  volatile uint32_t PTPTTHR;
  volatile uint32_t PTPTTLR;
       uint32_t RESERVED8[567];
  volatile uint32_t DMABMR;
  volatile uint32_t DMATPDR;
  volatile uint32_t DMARPDR;
  volatile uint32_t DMARDLAR;
  volatile uint32_t DMATDLAR;
  volatile uint32_t DMASR;
  volatile uint32_t DMAOMR;
  volatile uint32_t DMAIER;
  volatile uint32_t DMAMFBOCR;
       uint32_t RESERVED9[9];
  volatile uint32_t DMACHTDR;
  volatile uint32_t DMACHRDR;
  volatile uint32_t DMACHTBAR;
  volatile uint32_t DMACHRBAR;
} ETH_TypeDef;



 

typedef struct
{
  volatile uint32_t IMR;
  volatile uint32_t EMR;
  volatile uint32_t RTSR;
  volatile uint32_t FTSR;
  volatile uint32_t SWIER;
  volatile uint32_t PR;
} EXTI_TypeDef;



 

typedef struct
{
  volatile uint32_t ACR;
  volatile uint32_t KEYR;
  volatile uint32_t OPTKEYR;
  volatile uint32_t SR;
  volatile uint32_t CR;
  volatile uint32_t AR;
  volatile uint32_t RESERVED;
  volatile uint32_t OBR;
  volatile uint32_t WRPR;
#line 924 ".\\CM3\\stm32f10x.h"
} FLASH_TypeDef;



 
  
typedef struct
{
  volatile uint16_t RDP;
  volatile uint16_t USER;
  volatile uint16_t Data0;
  volatile uint16_t Data1;
  volatile uint16_t WRP0;
  volatile uint16_t WRP1;
  volatile uint16_t WRP2;
  volatile uint16_t WRP3;
} OB_TypeDef;



 

typedef struct
{
  volatile uint32_t BTCR[8];   
} FSMC_Bank1_TypeDef; 



 
  
typedef struct
{
  volatile uint32_t BWTR[7];
} FSMC_Bank1E_TypeDef;



 
  
typedef struct
{
  volatile uint32_t PCR2;
  volatile uint32_t SR2;
  volatile uint32_t PMEM2;
  volatile uint32_t PATT2;
  uint32_t  RESERVED0;   
  volatile uint32_t ECCR2; 
} FSMC_Bank2_TypeDef;  



 
  
typedef struct
{
  volatile uint32_t PCR3;
  volatile uint32_t SR3;
  volatile uint32_t PMEM3;
  volatile uint32_t PATT3;
  uint32_t  RESERVED0;   
  volatile uint32_t ECCR3; 
} FSMC_Bank3_TypeDef; 



 
  
typedef struct
{
  volatile uint32_t PCR4;
  volatile uint32_t SR4;
  volatile uint32_t PMEM4;
  volatile uint32_t PATT4;
  volatile uint32_t PIO4; 
} FSMC_Bank4_TypeDef; 



 

typedef struct
{
  volatile uint32_t CRL;
  volatile uint32_t CRH;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t BRR;
  volatile uint32_t LCKR;
} GPIO_TypeDef;



 

typedef struct
{
  volatile uint32_t EVCR;
  volatile uint32_t MAPR;
  volatile uint32_t EXTICR[4];
  uint32_t RESERVED0;
  volatile uint32_t MAPR2;  
} AFIO_TypeDef;


 

typedef struct
{
  volatile uint16_t CR1;
  uint16_t  RESERVED0;
  volatile uint16_t CR2;
  uint16_t  RESERVED1;
  volatile uint16_t OAR1;
  uint16_t  RESERVED2;
  volatile uint16_t OAR2;
  uint16_t  RESERVED3;
  volatile uint16_t DR;
  uint16_t  RESERVED4;
  volatile uint16_t SR1;
  uint16_t  RESERVED5;
  volatile uint16_t SR2;
  uint16_t  RESERVED6;
  volatile uint16_t CCR;
  uint16_t  RESERVED7;
  volatile uint16_t TRISE;
  uint16_t  RESERVED8;
} I2C_TypeDef;



 

typedef struct
{
  volatile uint32_t KR;
  volatile uint32_t PR;
  volatile uint32_t RLR;
  volatile uint32_t SR;
} IWDG_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CSR;
} PWR_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CFGR;
  volatile uint32_t CIR;
  volatile uint32_t APB2RSTR;
  volatile uint32_t APB1RSTR;
  volatile uint32_t AHBENR;
  volatile uint32_t APB2ENR;
  volatile uint32_t APB1ENR;
  volatile uint32_t BDCR;
  volatile uint32_t CSR;










} RCC_TypeDef;



 

typedef struct
{
  volatile uint16_t CRH;
  uint16_t  RESERVED0;
  volatile uint16_t CRL;
  uint16_t  RESERVED1;
  volatile uint16_t PRLH;
  uint16_t  RESERVED2;
  volatile uint16_t PRLL;
  uint16_t  RESERVED3;
  volatile uint16_t DIVH;
  uint16_t  RESERVED4;
  volatile uint16_t DIVL;
  uint16_t  RESERVED5;
  volatile uint16_t CNTH;
  uint16_t  RESERVED6;
  volatile uint16_t CNTL;
  uint16_t  RESERVED7;
  volatile uint16_t ALRH;
  uint16_t  RESERVED8;
  volatile uint16_t ALRL;
  uint16_t  RESERVED9;
} RTC_TypeDef;



 

typedef struct
{
  volatile uint32_t POWER;
  volatile uint32_t CLKCR;
  volatile uint32_t ARG;
  volatile uint32_t CMD;
  volatile const uint32_t RESPCMD;
  volatile const uint32_t RESP1;
  volatile const uint32_t RESP2;
  volatile const uint32_t RESP3;
  volatile const uint32_t RESP4;
  volatile uint32_t DTIMER;
  volatile uint32_t DLEN;
  volatile uint32_t DCTRL;
  volatile const uint32_t DCOUNT;
  volatile const uint32_t STA;
  volatile uint32_t ICR;
  volatile uint32_t MASK;
  uint32_t  RESERVED0[2];
  volatile const uint32_t FIFOCNT;
  uint32_t  RESERVED1[13];
  volatile uint32_t FIFO;
} SDIO_TypeDef;



 

typedef struct
{
  volatile uint16_t CR1;
  uint16_t  RESERVED0;
  volatile uint16_t CR2;
  uint16_t  RESERVED1;
  volatile uint16_t SR;
  uint16_t  RESERVED2;
  volatile uint16_t DR;
  uint16_t  RESERVED3;
  volatile uint16_t CRCPR;
  uint16_t  RESERVED4;
  volatile uint16_t RXCRCR;
  uint16_t  RESERVED5;
  volatile uint16_t TXCRCR;
  uint16_t  RESERVED6;
  volatile uint16_t I2SCFGR;
  uint16_t  RESERVED7;
  volatile uint16_t I2SPR;
  uint16_t  RESERVED8;  
} SPI_TypeDef;



 

typedef struct
{
  volatile uint16_t CR1;
  uint16_t  RESERVED0;
  volatile uint16_t CR2;
  uint16_t  RESERVED1;
  volatile uint16_t SMCR;
  uint16_t  RESERVED2;
  volatile uint16_t DIER;
  uint16_t  RESERVED3;
  volatile uint16_t SR;
  uint16_t  RESERVED4;
  volatile uint16_t EGR;
  uint16_t  RESERVED5;
  volatile uint16_t CCMR1;
  uint16_t  RESERVED6;
  volatile uint16_t CCMR2;
  uint16_t  RESERVED7;
  volatile uint16_t CCER;
  uint16_t  RESERVED8;
  volatile uint16_t CNT;
  uint16_t  RESERVED9;
  volatile uint16_t PSC;
  uint16_t  RESERVED10;
  volatile uint16_t ARR;
  uint16_t  RESERVED11;
  volatile uint16_t RCR;
  uint16_t  RESERVED12;
  volatile uint16_t CCR1;
  uint16_t  RESERVED13;
  volatile uint16_t CCR2;
  uint16_t  RESERVED14;
  volatile uint16_t CCR3;
  uint16_t  RESERVED15;
  volatile uint16_t CCR4;
  uint16_t  RESERVED16;
  volatile uint16_t BDTR;
  uint16_t  RESERVED17;
  volatile uint16_t DCR;
  uint16_t  RESERVED18;
  volatile uint16_t DMAR;
  uint16_t  RESERVED19;
} TIM_TypeDef;



 
 
typedef struct
{
  volatile uint16_t SR;
  uint16_t  RESERVED0;
  volatile uint16_t DR;
  uint16_t  RESERVED1;
  volatile uint16_t BRR;
  uint16_t  RESERVED2;
  volatile uint16_t CR1;
  uint16_t  RESERVED3;
  volatile uint16_t CR2;
  uint16_t  RESERVED4;
  volatile uint16_t CR3;
  uint16_t  RESERVED5;
  volatile uint16_t GTPR;
  uint16_t  RESERVED6;
} USART_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CFR;
  volatile uint32_t SR;
} WWDG_TypeDef;



 
  


 











 




#line 1316 ".\\CM3\\stm32f10x.h"

#line 1339 ".\\CM3\\stm32f10x.h"



#line 1358 ".\\CM3\\stm32f10x.h"




















 
  


   

#line 1458 ".\\CM3\\stm32f10x.h"



 



 
  
  

 
    
 
 
 

 
 
 
 
 

 



 



 


 
 
 
 
 

 











 
#line 1519 ".\\CM3\\stm32f10x.h"




 





 
 
 
 
 

 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 





 



 






 
 
 
 
 

 
#line 1695 ".\\CM3\\stm32f10x.h"

#line 1702 ".\\CM3\\stm32f10x.h"

 
 








 








 






#line 1738 ".\\CM3\\stm32f10x.h"

 











 











 













 






#line 1854 ".\\CM3\\stm32f10x.h"




#line 1874 ".\\CM3\\stm32f10x.h"

 





#line 1887 ".\\CM3\\stm32f10x.h"

 
#line 1906 ".\\CM3\\stm32f10x.h"

#line 1915 ".\\CM3\\stm32f10x.h"

 
#line 1923 ".\\CM3\\stm32f10x.h"



















#line 1948 ".\\CM3\\stm32f10x.h"












 













#line 1980 ".\\CM3\\stm32f10x.h"





#line 1994 ".\\CM3\\stm32f10x.h"

#line 2001 ".\\CM3\\stm32f10x.h"

#line 2011 ".\\CM3\\stm32f10x.h"











 


















#line 2047 ".\\CM3\\stm32f10x.h"

 
#line 2055 ".\\CM3\\stm32f10x.h"



















#line 2080 ".\\CM3\\stm32f10x.h"












 













#line 2112 ".\\CM3\\stm32f10x.h"





#line 2126 ".\\CM3\\stm32f10x.h"

#line 2133 ".\\CM3\\stm32f10x.h"

#line 2143 ".\\CM3\\stm32f10x.h"











 








 








   
#line 2182 ".\\CM3\\stm32f10x.h"

#line 2277 ".\\CM3\\stm32f10x.h"

#line 2304 ".\\CM3\\stm32f10x.h"
 
 
 
 
 
 

 




































































 




































































 
#line 2466 ".\\CM3\\stm32f10x.h"

 
#line 2484 ".\\CM3\\stm32f10x.h"

 
#line 2502 ".\\CM3\\stm32f10x.h"

#line 2519 ".\\CM3\\stm32f10x.h"

 
#line 2537 ".\\CM3\\stm32f10x.h"

 
#line 2556 ".\\CM3\\stm32f10x.h"

 

 






 
#line 2583 ".\\CM3\\stm32f10x.h"






 








 









 








 








 









 










 




#line 2658 ".\\CM3\\stm32f10x.h"

 










#line 2689 ".\\CM3\\stm32f10x.h"

 





 
#line 2704 ".\\CM3\\stm32f10x.h"

 
#line 2713 ".\\CM3\\stm32f10x.h"

   
#line 2722 ".\\CM3\\stm32f10x.h"

 
#line 2731 ".\\CM3\\stm32f10x.h"

 





 
#line 2746 ".\\CM3\\stm32f10x.h"

 
#line 2755 ".\\CM3\\stm32f10x.h"

   
#line 2764 ".\\CM3\\stm32f10x.h"

 
#line 2773 ".\\CM3\\stm32f10x.h"

 





 
#line 2788 ".\\CM3\\stm32f10x.h"

 
#line 2797 ".\\CM3\\stm32f10x.h"

   
#line 2806 ".\\CM3\\stm32f10x.h"

 
#line 2815 ".\\CM3\\stm32f10x.h"

 





 
#line 2830 ".\\CM3\\stm32f10x.h"

 
#line 2839 ".\\CM3\\stm32f10x.h"

   
#line 2848 ".\\CM3\\stm32f10x.h"

 
#line 2857 ".\\CM3\\stm32f10x.h"

#line 2866 ".\\CM3\\stm32f10x.h"

#line 2875 ".\\CM3\\stm32f10x.h"

#line 2885 ".\\CM3\\stm32f10x.h"

 
 
 
 
 

 





 


 


 




 
 
 
 
 

 
#line 2949 ".\\CM3\\stm32f10x.h"

 
#line 2984 ".\\CM3\\stm32f10x.h"

 
#line 3019 ".\\CM3\\stm32f10x.h"

 
#line 3054 ".\\CM3\\stm32f10x.h"

 
#line 3089 ".\\CM3\\stm32f10x.h"

 





 





 





 





 





 





 





 





 






 
#line 3156 ".\\CM3\\stm32f10x.h"

 



 









 
#line 3180 ".\\CM3\\stm32f10x.h"




 




 
#line 3196 ".\\CM3\\stm32f10x.h"

 





 
#line 3218 ".\\CM3\\stm32f10x.h"

 
 





 
#line 3233 ".\\CM3\\stm32f10x.h"
 
#line 3240 ".\\CM3\\stm32f10x.h"

 




 






 


 


 


 
 
 
 
 

 
#line 3289 ".\\CM3\\stm32f10x.h"

 
#line 3311 ".\\CM3\\stm32f10x.h"

 
#line 3333 ".\\CM3\\stm32f10x.h"

 
#line 3355 ".\\CM3\\stm32f10x.h"

 
#line 3377 ".\\CM3\\stm32f10x.h"

 
#line 3399 ".\\CM3\\stm32f10x.h"

 
 
 
 
 

 
#line 3435 ".\\CM3\\stm32f10x.h"

 
#line 3465 ".\\CM3\\stm32f10x.h"

 
#line 3475 ".\\CM3\\stm32f10x.h"















 
#line 3499 ".\\CM3\\stm32f10x.h"















 
#line 3523 ".\\CM3\\stm32f10x.h"















 
#line 3547 ".\\CM3\\stm32f10x.h"















 
#line 3571 ".\\CM3\\stm32f10x.h"















 
#line 3595 ".\\CM3\\stm32f10x.h"















 
#line 3619 ".\\CM3\\stm32f10x.h"















 


 


 


 


 


 


 


 


 


 



 


 


 



 


 


 


 



 


 


 


 


 
 
 
 
 

 






 
#line 3720 ".\\CM3\\stm32f10x.h"

#line 3729 ".\\CM3\\stm32f10x.h"















  
 
#line 3752 ".\\CM3\\stm32f10x.h"


















 








































 


















































 


 


 


 


 


 


 
#line 3887 ".\\CM3\\stm32f10x.h"

#line 3894 ".\\CM3\\stm32f10x.h"

#line 3901 ".\\CM3\\stm32f10x.h"

#line 3908 ".\\CM3\\stm32f10x.h"







 
#line 3922 ".\\CM3\\stm32f10x.h"

#line 3929 ".\\CM3\\stm32f10x.h"

#line 3936 ".\\CM3\\stm32f10x.h"

#line 3943 ".\\CM3\\stm32f10x.h"

#line 3950 ".\\CM3\\stm32f10x.h"

#line 3957 ".\\CM3\\stm32f10x.h"

 
#line 3965 ".\\CM3\\stm32f10x.h"

#line 3972 ".\\CM3\\stm32f10x.h"

#line 3979 ".\\CM3\\stm32f10x.h"

#line 3986 ".\\CM3\\stm32f10x.h"

#line 3993 ".\\CM3\\stm32f10x.h"

#line 4000 ".\\CM3\\stm32f10x.h"

 
#line 4008 ".\\CM3\\stm32f10x.h"

#line 4015 ".\\CM3\\stm32f10x.h"

#line 4022 ".\\CM3\\stm32f10x.h"

#line 4029 ".\\CM3\\stm32f10x.h"





 


 


 


 


 



 
 
 
 
 

 









































 



 


 


 


 


 


 


 



 



 



 


 


 



 
 
 
 
 
 





 






 


 
#line 4171 ".\\CM3\\stm32f10x.h"

 
#line 4181 ".\\CM3\\stm32f10x.h"

 


 


 
 
 
 
 

 
















 









#line 4229 ".\\CM3\\stm32f10x.h"

 

























 
#line 4272 ".\\CM3\\stm32f10x.h"

 
#line 4286 ".\\CM3\\stm32f10x.h"

 
#line 4296 ".\\CM3\\stm32f10x.h"

 




























 





















 




























 





















 
#line 4415 ".\\CM3\\stm32f10x.h"

 


 


 


 


 


 


 


 


 
#line 4450 ".\\CM3\\stm32f10x.h"





#line 4461 ".\\CM3\\stm32f10x.h"

 
#line 4469 ".\\CM3\\stm32f10x.h"

#line 4476 ".\\CM3\\stm32f10x.h"

 


 
 
 
 
 

 




 
#line 4498 ".\\CM3\\stm32f10x.h"

 


 


 


 


 


 


 


 


 
 
 
 
 

 


 





 


 



 
 
 
 
 

 
#line 4560 ".\\CM3\\stm32f10x.h"



 
#line 4572 ".\\CM3\\stm32f10x.h"







 


 
 
 
 
 

 











#line 4610 ".\\CM3\\stm32f10x.h"

 











#line 4633 ".\\CM3\\stm32f10x.h"

 











#line 4656 ".\\CM3\\stm32f10x.h"

 











#line 4679 ".\\CM3\\stm32f10x.h"

 








































 








































 








































 








































 


































 


































 


































 


































 



























 



























 



























 
#line 5076 ".\\CM3\\stm32f10x.h"

 
#line 5085 ".\\CM3\\stm32f10x.h"

 
#line 5094 ".\\CM3\\stm32f10x.h"

 
#line 5105 ".\\CM3\\stm32f10x.h"

#line 5115 ".\\CM3\\stm32f10x.h"

#line 5125 ".\\CM3\\stm32f10x.h"

#line 5135 ".\\CM3\\stm32f10x.h"

 
#line 5146 ".\\CM3\\stm32f10x.h"

#line 5156 ".\\CM3\\stm32f10x.h"

#line 5166 ".\\CM3\\stm32f10x.h"

#line 5176 ".\\CM3\\stm32f10x.h"

 
#line 5187 ".\\CM3\\stm32f10x.h"

#line 5197 ".\\CM3\\stm32f10x.h"

#line 5207 ".\\CM3\\stm32f10x.h"

#line 5217 ".\\CM3\\stm32f10x.h"

 
#line 5228 ".\\CM3\\stm32f10x.h"

#line 5238 ".\\CM3\\stm32f10x.h"

#line 5248 ".\\CM3\\stm32f10x.h"

#line 5258 ".\\CM3\\stm32f10x.h"

 
#line 5269 ".\\CM3\\stm32f10x.h"

#line 5279 ".\\CM3\\stm32f10x.h"

#line 5289 ".\\CM3\\stm32f10x.h"

#line 5299 ".\\CM3\\stm32f10x.h"

 
#line 5310 ".\\CM3\\stm32f10x.h"

#line 5320 ".\\CM3\\stm32f10x.h"

#line 5330 ".\\CM3\\stm32f10x.h"

#line 5340 ".\\CM3\\stm32f10x.h"

 
#line 5351 ".\\CM3\\stm32f10x.h"

#line 5361 ".\\CM3\\stm32f10x.h"

#line 5371 ".\\CM3\\stm32f10x.h"

#line 5381 ".\\CM3\\stm32f10x.h"

 


 


 
 
 
 
 

 




 












 


 






#line 5429 ".\\CM3\\stm32f10x.h"

 


 


 


 


 


 


 


 


 
















 


 
#line 5499 ".\\CM3\\stm32f10x.h"

 
#line 5514 ".\\CM3\\stm32f10x.h"

 
#line 5540 ".\\CM3\\stm32f10x.h"

 


 


 
 
 
 
 

 
 























 























 























 























 























 























 























 























 
 
#line 5761 ".\\CM3\\stm32f10x.h"

 
#line 5773 ".\\CM3\\stm32f10x.h"

 






 
#line 5790 ".\\CM3\\stm32f10x.h"



     


 
 


 


 


 


 


 


 


 


 

 


 


 


 


 


 


 


 


 

 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 

 


 


 


 


 


 


 


 


 

 


#line 5934 ".\\CM3\\stm32f10x.h"



 


#line 5946 ".\\CM3\\stm32f10x.h"



 


#line 5958 ".\\CM3\\stm32f10x.h"



 


#line 5970 ".\\CM3\\stm32f10x.h"



 


#line 5982 ".\\CM3\\stm32f10x.h"



 


#line 5994 ".\\CM3\\stm32f10x.h"



 


#line 6006 ".\\CM3\\stm32f10x.h"



 


#line 6018 ".\\CM3\\stm32f10x.h"



 

 


#line 6032 ".\\CM3\\stm32f10x.h"



 


#line 6044 ".\\CM3\\stm32f10x.h"



 


#line 6056 ".\\CM3\\stm32f10x.h"



 


#line 6068 ".\\CM3\\stm32f10x.h"



 


#line 6080 ".\\CM3\\stm32f10x.h"



 


#line 6092 ".\\CM3\\stm32f10x.h"



 


#line 6104 ".\\CM3\\stm32f10x.h"



 


#line 6116 ".\\CM3\\stm32f10x.h"



 


#line 6128 ".\\CM3\\stm32f10x.h"



 


#line 6140 ".\\CM3\\stm32f10x.h"



 


#line 6152 ".\\CM3\\stm32f10x.h"



 


#line 6164 ".\\CM3\\stm32f10x.h"



 


#line 6176 ".\\CM3\\stm32f10x.h"



 


#line 6188 ".\\CM3\\stm32f10x.h"



 


#line 6200 ".\\CM3\\stm32f10x.h"



 


#line 6212 ".\\CM3\\stm32f10x.h"



 
 
 
 
 

 
 
#line 6232 ".\\CM3\\stm32f10x.h"

 
#line 6243 ".\\CM3\\stm32f10x.h"

 
#line 6261 ".\\CM3\\stm32f10x.h"











 





 





 
#line 6299 ".\\CM3\\stm32f10x.h"

 












 
#line 6320 ".\\CM3\\stm32f10x.h"

 
 






 




 





 





 






 




 





 





 






   




 





 





 





 




 





 





 





 




 





 





 
 


 
#line 6460 ".\\CM3\\stm32f10x.h"

 
#line 6477 ".\\CM3\\stm32f10x.h"

 
#line 6494 ".\\CM3\\stm32f10x.h"

 
#line 6511 ".\\CM3\\stm32f10x.h"

 
#line 6545 ".\\CM3\\stm32f10x.h"

 
#line 6579 ".\\CM3\\stm32f10x.h"

 
#line 6613 ".\\CM3\\stm32f10x.h"

 
#line 6647 ".\\CM3\\stm32f10x.h"

 
#line 6681 ".\\CM3\\stm32f10x.h"

 
#line 6715 ".\\CM3\\stm32f10x.h"

 
#line 6749 ".\\CM3\\stm32f10x.h"

 
#line 6783 ".\\CM3\\stm32f10x.h"

 
#line 6817 ".\\CM3\\stm32f10x.h"

 
#line 6851 ".\\CM3\\stm32f10x.h"

 
#line 6885 ".\\CM3\\stm32f10x.h"

 
#line 6919 ".\\CM3\\stm32f10x.h"

 
#line 6953 ".\\CM3\\stm32f10x.h"

 
#line 6987 ".\\CM3\\stm32f10x.h"

 
#line 7021 ".\\CM3\\stm32f10x.h"

 
#line 7055 ".\\CM3\\stm32f10x.h"

 
#line 7089 ".\\CM3\\stm32f10x.h"

 
#line 7123 ".\\CM3\\stm32f10x.h"

 
#line 7157 ".\\CM3\\stm32f10x.h"

 
#line 7191 ".\\CM3\\stm32f10x.h"

 
#line 7225 ".\\CM3\\stm32f10x.h"

 
#line 7259 ".\\CM3\\stm32f10x.h"

 
#line 7293 ".\\CM3\\stm32f10x.h"

 
#line 7327 ".\\CM3\\stm32f10x.h"

 
#line 7361 ".\\CM3\\stm32f10x.h"

 
#line 7395 ".\\CM3\\stm32f10x.h"

 
#line 7429 ".\\CM3\\stm32f10x.h"

 
#line 7463 ".\\CM3\\stm32f10x.h"

 
 
 
 
 

 









#line 7490 ".\\CM3\\stm32f10x.h"

 
#line 7498 ".\\CM3\\stm32f10x.h"

 
#line 7508 ".\\CM3\\stm32f10x.h"

 


 


 


 


 





















 




 
 
 
 
 

 
#line 7569 ".\\CM3\\stm32f10x.h"

 
#line 7578 ".\\CM3\\stm32f10x.h"







 



#line 7599 ".\\CM3\\stm32f10x.h"



 



 


 
#line 7624 ".\\CM3\\stm32f10x.h"

 
#line 7634 ".\\CM3\\stm32f10x.h"

 




 


 
 
 
 
 

 
#line 7660 ".\\CM3\\stm32f10x.h"

 


 



 
#line 7684 ".\\CM3\\stm32f10x.h"

 
#line 7693 ".\\CM3\\stm32f10x.h"







 
#line 7713 ".\\CM3\\stm32f10x.h"

 
#line 7724 ".\\CM3\\stm32f10x.h"



 
 
 
 
 

 


#line 7753 ".\\CM3\\stm32f10x.h"

 









#line 7787 ".\\CM3\\stm32f10x.h"

 
 
 
 
 

 









 


 


 





 
#line 7827 ".\\CM3\\stm32f10x.h"

 


 









 


 

 



 



 



 



 



 



 



 



#line 8291 ".\\CM3\\stm32f10x.h"



 

 

  

#line 1 ".\\FWlib\\inc\\stm32f10x_conf.h"


















 

 



 
 
 
 
 
 
 
 
 
 
 
 
#line 1 ".\\FWlib\\inc\\stm32f10x_gpio.h"




















 

 







 
#line 1 ".\\CM3\\stm32f10x.h"







































 



 



 
    
#line 8331 ".\\CM3\\stm32f10x.h"



 

  

 

 
#line 33 ".\\FWlib\\inc\\stm32f10x_gpio.h"



 



 



 

#line 53 ".\\FWlib\\inc\\stm32f10x_gpio.h"
                                     


 

typedef enum
{ 
  GPIO_Speed_10MHz = 1,
  GPIO_Speed_2MHz, 
  GPIO_Speed_50MHz
}GPIOSpeed_TypeDef;





 

typedef enum
{ GPIO_Mode_AIN = 0x0,
  GPIO_Mode_IN_FLOATING = 0x04,
  GPIO_Mode_IPD = 0x28,
  GPIO_Mode_IPU = 0x48,
  GPIO_Mode_Out_OD = 0x14,
  GPIO_Mode_Out_PP = 0x10,
  GPIO_Mode_AF_OD = 0x1C,
  GPIO_Mode_AF_PP = 0x18
}GPIOMode_TypeDef;








 

typedef struct
{
  uint16_t GPIO_Pin;             
 

  GPIOSpeed_TypeDef GPIO_Speed;  
 

  GPIOMode_TypeDef GPIO_Mode;    
 
}GPIO_InitTypeDef;




 

typedef enum
{ Bit_RESET = 0,
  Bit_SET
}BitAction;





 



 



 

#line 144 ".\\FWlib\\inc\\stm32f10x_gpio.h"



#line 163 ".\\FWlib\\inc\\stm32f10x_gpio.h"



 



 

#line 204 ".\\FWlib\\inc\\stm32f10x_gpio.h"







#line 217 ".\\FWlib\\inc\\stm32f10x_gpio.h"






#line 245 ".\\FWlib\\inc\\stm32f10x_gpio.h"
                              


  



 

#line 266 ".\\FWlib\\inc\\stm32f10x_gpio.h"

#line 274 ".\\FWlib\\inc\\stm32f10x_gpio.h"



 



 

#line 299 ".\\FWlib\\inc\\stm32f10x_gpio.h"

#line 316 ".\\FWlib\\inc\\stm32f10x_gpio.h"



 



  








                                                 


 



 



 



 

void GPIO_DeInit(GPIO_TypeDef* GPIOx);
void GPIO_AFIODeInit(void);
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);
void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct);
uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
uint16_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx);
uint8_t GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
uint16_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx);
void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal);
void GPIO_Write(GPIO_TypeDef* GPIOx, uint16_t PortVal);
void GPIO_PinLockConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_EventOutputConfig(uint8_t GPIO_PortSource, uint8_t GPIO_PinSource);
void GPIO_EventOutputCmd(FunctionalState NewState);
void GPIO_PinRemapConfig(uint32_t GPIO_Remap, FunctionalState NewState);
void GPIO_EXTILineConfig(uint8_t GPIO_PortSource, uint8_t GPIO_PinSource);
void GPIO_ETH_MediaInterfaceConfig(uint32_t GPIO_ETH_MediaInterface);








 



 



 

 
#line 38 ".\\FWlib\\inc\\stm32f10x_conf.h"
 
 
 
#line 1 ".\\FWlib\\inc\\stm32f10x_rcc.h"




















 

 







 
#line 33 ".\\FWlib\\inc\\stm32f10x_rcc.h"



 



 



 

typedef struct
{
  uint32_t SYSCLK_Frequency;   
  uint32_t HCLK_Frequency;     
  uint32_t PCLK1_Frequency;    
  uint32_t PCLK2_Frequency;    
  uint32_t ADCCLK_Frequency;   
}RCC_ClocksTypeDef;



 



 



 









  



 



#line 94 ".\\FWlib\\inc\\stm32f10x_rcc.h"



  



 
#line 126 ".\\FWlib\\inc\\stm32f10x_rcc.h"

#line 141 ".\\FWlib\\inc\\stm32f10x_rcc.h"


 



 
#line 175 ".\\FWlib\\inc\\stm32f10x_rcc.h"


 




 
#line 196 ".\\FWlib\\inc\\stm32f10x_rcc.h"


 

#line 283 ".\\FWlib\\inc\\stm32f10x_rcc.h"




 

#line 295 ".\\FWlib\\inc\\stm32f10x_rcc.h"


 



 

#line 317 ".\\FWlib\\inc\\stm32f10x_rcc.h"


  



 

#line 333 ".\\FWlib\\inc\\stm32f10x_rcc.h"


 



 

#line 347 ".\\FWlib\\inc\\stm32f10x_rcc.h"

#line 364 ".\\FWlib\\inc\\stm32f10x_rcc.h"




 




 








 
#line 396 ".\\FWlib\\inc\\stm32f10x_rcc.h"


#line 423 ".\\FWlib\\inc\\stm32f10x_rcc.h"
  



 

#line 435 ".\\FWlib\\inc\\stm32f10x_rcc.h"


 



 








 



 

#line 462 ".\\FWlib\\inc\\stm32f10x_rcc.h"


 



 







#line 489 ".\\FWlib\\inc\\stm32f10x_rcc.h"


 



 

#line 518 ".\\FWlib\\inc\\stm32f10x_rcc.h"




  



 

#line 553 ".\\FWlib\\inc\\stm32f10x_rcc.h"
 




 



 







#line 586 ".\\FWlib\\inc\\stm32f10x_rcc.h"



 



 

#line 606 ".\\FWlib\\inc\\stm32f10x_rcc.h"

#line 625 ".\\FWlib\\inc\\stm32f10x_rcc.h"




 



 



 



 



 

void RCC_DeInit(void);
void RCC_HSEConfig(uint32_t RCC_HSE);
ErrorStatus RCC_WaitForHSEStartUp(void);
void RCC_AdjustHSICalibrationValue(uint8_t HSICalibrationValue);
void RCC_HSICmd(FunctionalState NewState);
void RCC_PLLConfig(uint32_t RCC_PLLSource, uint32_t RCC_PLLMul);
void RCC_PLLCmd(FunctionalState NewState);





#line 666 ".\\FWlib\\inc\\stm32f10x_rcc.h"

void RCC_SYSCLKConfig(uint32_t RCC_SYSCLKSource);
uint8_t RCC_GetSYSCLKSource(void);
void RCC_HCLKConfig(uint32_t RCC_SYSCLK);
void RCC_PCLK1Config(uint32_t RCC_HCLK);
void RCC_PCLK2Config(uint32_t RCC_HCLK);
void RCC_ITConfig(uint8_t RCC_IT, FunctionalState NewState);


 void RCC_USBCLKConfig(uint32_t RCC_USBCLKSource);




void RCC_ADCCLKConfig(uint32_t RCC_PCLK2);






void RCC_LSEConfig(uint8_t RCC_LSE);
void RCC_LSICmd(FunctionalState NewState);
void RCC_RTCCLKConfig(uint32_t RCC_RTCCLKSource);
void RCC_RTCCLKCmd(FunctionalState NewState);
void RCC_GetClocksFreq(RCC_ClocksTypeDef* RCC_Clocks);
void RCC_AHBPeriphClockCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState);
void RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);
void RCC_APB1PeriphClockCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);





void RCC_APB2PeriphResetCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);
void RCC_APB1PeriphResetCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);
void RCC_BackupResetCmd(FunctionalState NewState);
void RCC_ClockSecuritySystemCmd(FunctionalState NewState);
void RCC_MCOConfig(uint8_t RCC_MCO);
FlagStatus RCC_GetFlagStatus(uint8_t RCC_FLAG);
void RCC_ClearFlag(void);
ITStatus RCC_GetITStatus(uint8_t RCC_IT);
void RCC_ClearITPendingBit(uint8_t RCC_IT);








 



 



  

 
#line 42 ".\\FWlib\\inc\\stm32f10x_conf.h"
 
 
 
 
 
 
    

 
 

 
 

 
#line 73 ".\\FWlib\\inc\\stm32f10x_conf.h"



 
#line 8302 ".\\CM3\\stm32f10x.h"




 

















 









 

  

 

 
#line 24 "user\\main.c"
#line 1 ".\\FWlib\\inc\\stm32f10x_adc.h"




















 

 







 
#line 33 ".\\FWlib\\inc\\stm32f10x_adc.h"



 



 



 



 

typedef struct
{
  uint32_t ADC_Mode;                      

 

  FunctionalState ADC_ScanConvMode;       

 

  FunctionalState ADC_ContinuousConvMode; 

 

  uint32_t ADC_ExternalTrigConv;          

 

  uint32_t ADC_DataAlign;                 
 

  uint8_t ADC_NbrOfChannel;               

 
}ADC_InitTypeDef;


 



 










 

#line 104 ".\\FWlib\\inc\\stm32f10x_adc.h"

#line 115 ".\\FWlib\\inc\\stm32f10x_adc.h"


 



 

#line 129 ".\\FWlib\\inc\\stm32f10x_adc.h"




#line 139 ".\\FWlib\\inc\\stm32f10x_adc.h"

#line 154 ".\\FWlib\\inc\\stm32f10x_adc.h"


 



 







 



 

#line 192 ".\\FWlib\\inc\\stm32f10x_adc.h"




#line 205 ".\\FWlib\\inc\\stm32f10x_adc.h"


 



 

#line 229 ".\\FWlib\\inc\\stm32f10x_adc.h"


 



 

















#line 266 ".\\FWlib\\inc\\stm32f10x_adc.h"


 



 

#line 282 ".\\FWlib\\inc\\stm32f10x_adc.h"


 



 

#line 297 ".\\FWlib\\inc\\stm32f10x_adc.h"

#line 305 ".\\FWlib\\inc\\stm32f10x_adc.h"


 



 











 



 

#line 338 ".\\FWlib\\inc\\stm32f10x_adc.h"


 



 





 



 





 



 





 



 





  




 




 



 





 



 





 



 



 



 



 

void ADC_DeInit(ADC_TypeDef* ADCx);
void ADC_Init(ADC_TypeDef* ADCx, ADC_InitTypeDef* ADC_InitStruct);
void ADC_StructInit(ADC_InitTypeDef* ADC_InitStruct);
void ADC_Cmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_DMACmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_ITConfig(ADC_TypeDef* ADCx, uint16_t ADC_IT, FunctionalState NewState);
void ADC_ResetCalibration(ADC_TypeDef* ADCx);
FlagStatus ADC_GetResetCalibrationStatus(ADC_TypeDef* ADCx);
void ADC_StartCalibration(ADC_TypeDef* ADCx);
FlagStatus ADC_GetCalibrationStatus(ADC_TypeDef* ADCx);
void ADC_SoftwareStartConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
FlagStatus ADC_GetSoftwareStartConvStatus(ADC_TypeDef* ADCx);
void ADC_DiscModeChannelCountConfig(ADC_TypeDef* ADCx, uint8_t Number);
void ADC_DiscModeCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_RegularChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel, uint8_t Rank, uint8_t ADC_SampleTime);
void ADC_ExternalTrigConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
uint16_t ADC_GetConversionValue(ADC_TypeDef* ADCx);
uint32_t ADC_GetDualModeConversionValue(void);
void ADC_AutoInjectedConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_InjectedDiscModeCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_ExternalTrigInjectedConvConfig(ADC_TypeDef* ADCx, uint32_t ADC_ExternalTrigInjecConv);
void ADC_ExternalTrigInjectedConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_SoftwareStartInjectedConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
FlagStatus ADC_GetSoftwareStartInjectedConvCmdStatus(ADC_TypeDef* ADCx);
void ADC_InjectedChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel, uint8_t Rank, uint8_t ADC_SampleTime);
void ADC_InjectedSequencerLengthConfig(ADC_TypeDef* ADCx, uint8_t Length);
void ADC_SetInjectedOffset(ADC_TypeDef* ADCx, uint8_t ADC_InjectedChannel, uint16_t Offset);
uint16_t ADC_GetInjectedConversionValue(ADC_TypeDef* ADCx, uint8_t ADC_InjectedChannel);
void ADC_AnalogWatchdogCmd(ADC_TypeDef* ADCx, uint32_t ADC_AnalogWatchdog);
void ADC_AnalogWatchdogThresholdsConfig(ADC_TypeDef* ADCx, uint16_t HighThreshold, uint16_t LowThreshold);
void ADC_AnalogWatchdogSingleChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel);
void ADC_TempSensorVrefintCmd(FunctionalState NewState);
FlagStatus ADC_GetFlagStatus(ADC_TypeDef* ADCx, uint8_t ADC_FLAG);
void ADC_ClearFlag(ADC_TypeDef* ADCx, uint8_t ADC_FLAG);
ITStatus ADC_GetITStatus(ADC_TypeDef* ADCx, uint16_t ADC_IT);
void ADC_ClearITPendingBit(ADC_TypeDef* ADCx, uint16_t ADC_IT);









 



 



 

 
#line 25 "user\\main.c"
#line 1 ".\\FWlib\\inc\\stm32f10x_dma.h"




















 

 







 
#line 33 ".\\FWlib\\inc\\stm32f10x_dma.h"



 



 



 



 

typedef struct
{
  uint32_t DMA_PeripheralBaseAddr;  

  uint32_t DMA_MemoryBaseAddr;      

  uint32_t DMA_DIR;                
 

  uint32_t DMA_BufferSize;         

 

  uint32_t DMA_PeripheralInc;      
 

  uint32_t DMA_MemoryInc;          
 

  uint32_t DMA_PeripheralDataSize; 
 

  uint32_t DMA_MemoryDataSize;     
 

  uint32_t DMA_Mode;               


 

  uint32_t DMA_Priority;           
 

  uint32_t DMA_M2M;                
 
}DMA_InitTypeDef;



 



 

#line 107 ".\\FWlib\\inc\\stm32f10x_dma.h"



 







 



 







 



 







 



 

#line 154 ".\\FWlib\\inc\\stm32f10x_dma.h"


 



 

#line 168 ".\\FWlib\\inc\\stm32f10x_dma.h"


 



 






 



 

#line 195 ".\\FWlib\\inc\\stm32f10x_dma.h"


 



 







 



 






#line 248 ".\\FWlib\\inc\\stm32f10x_dma.h"

#line 269 ".\\FWlib\\inc\\stm32f10x_dma.h"



#line 296 ".\\FWlib\\inc\\stm32f10x_dma.h"



 



 
#line 332 ".\\FWlib\\inc\\stm32f10x_dma.h"

#line 353 ".\\FWlib\\inc\\stm32f10x_dma.h"



#line 380 ".\\FWlib\\inc\\stm32f10x_dma.h"


 



 





 



 



 



 



 

void DMA_DeInit(DMA_Channel_TypeDef* DMAy_Channelx);
void DMA_Init(DMA_Channel_TypeDef* DMAy_Channelx, DMA_InitTypeDef* DMA_InitStruct);
void DMA_StructInit(DMA_InitTypeDef* DMA_InitStruct);
void DMA_Cmd(DMA_Channel_TypeDef* DMAy_Channelx, FunctionalState NewState);
void DMA_ITConfig(DMA_Channel_TypeDef* DMAy_Channelx, uint32_t DMA_IT, FunctionalState NewState);
void DMA_SetCurrDataCounter(DMA_Channel_TypeDef* DMAy_Channelx, uint16_t DataNumber); 
uint16_t DMA_GetCurrDataCounter(DMA_Channel_TypeDef* DMAy_Channelx);
FlagStatus DMA_GetFlagStatus(uint32_t DMAy_FLAG);
void DMA_ClearFlag(uint32_t DMAy_FLAG);
ITStatus DMA_GetITStatus(uint32_t DMAy_IT);
void DMA_ClearITPendingBit(uint32_t DMAy_IT);








 



 



 

 
#line 26 "user\\main.c"
#line 27 "user\\main.c"
#line 28 "user\\main.c"
#line 1 ".\\FWlib\\inc\\stm32f10x_usart.h"




















 

 







 
#line 33 ".\\FWlib\\inc\\stm32f10x_usart.h"



 



  



  



  
  
typedef struct
{
  uint32_t USART_BaudRate;            


 

  uint16_t USART_WordLength;          
 

  uint16_t USART_StopBits;            
 

  uint16_t USART_Parity;              




 
 
  uint16_t USART_Mode;                
 

  uint16_t USART_HardwareFlowControl; 

 
} USART_InitTypeDef;



  
  
typedef struct
{

  uint16_t USART_Clock;   
 

  uint16_t USART_CPOL;    
 

  uint16_t USART_CPHA;    
 

  uint16_t USART_LastBit; 

 
} USART_ClockInitTypeDef;



  



  
  
















  
  


                                    




  



  
  
#line 146 ".\\FWlib\\inc\\stm32f10x_usart.h"


  



  
  
#line 160 ".\\FWlib\\inc\\stm32f10x_usart.h"


  



  
  





  



  
#line 187 ".\\FWlib\\inc\\stm32f10x_usart.h"


  



  






  



 
  






  



 







 



 







  



 
  
#line 264 ".\\FWlib\\inc\\stm32f10x_usart.h"


 



 







  



 







 



 
  







 



 







  



 

#line 336 ".\\FWlib\\inc\\stm32f10x_usart.h"
                              
#line 344 ".\\FWlib\\inc\\stm32f10x_usart.h"



  



  



  



  



 

void USART_DeInit(USART_TypeDef* USARTx);
void USART_Init(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStruct);
void USART_StructInit(USART_InitTypeDef* USART_InitStruct);
void USART_ClockInit(USART_TypeDef* USARTx, USART_ClockInitTypeDef* USART_ClockInitStruct);
void USART_ClockStructInit(USART_ClockInitTypeDef* USART_ClockInitStruct);
void USART_Cmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_ITConfig(USART_TypeDef* USARTx, uint16_t USART_IT, FunctionalState NewState);
void USART_DMACmd(USART_TypeDef* USARTx, uint16_t USART_DMAReq, FunctionalState NewState);
void USART_SetAddress(USART_TypeDef* USARTx, uint8_t USART_Address);
void USART_WakeUpConfig(USART_TypeDef* USARTx, uint16_t USART_WakeUp);
void USART_ReceiverWakeUpCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_LINBreakDetectLengthConfig(USART_TypeDef* USARTx, uint16_t USART_LINBreakDetectLength);
void USART_LINCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_SendData(USART_TypeDef* USARTx, uint16_t Data);
uint16_t USART_ReceiveData(USART_TypeDef* USARTx);
void USART_SendBreak(USART_TypeDef* USARTx);
void USART_SetGuardTime(USART_TypeDef* USARTx, uint8_t USART_GuardTime);
void USART_SetPrescaler(USART_TypeDef* USARTx, uint8_t USART_Prescaler);
void USART_SmartCardCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_SmartCardNACKCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_HalfDuplexCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_OverSampling8Cmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_OneBitMethodCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_IrDAConfig(USART_TypeDef* USARTx, uint16_t USART_IrDAMode);
void USART_IrDACmd(USART_TypeDef* USARTx, FunctionalState NewState);
FlagStatus USART_GetFlagStatus(USART_TypeDef* USARTx, uint16_t USART_FLAG);
void USART_ClearFlag(USART_TypeDef* USARTx, uint16_t USART_FLAG);
ITStatus USART_GetITStatus(USART_TypeDef* USARTx, uint16_t USART_IT);
void USART_ClearITPendingBit(USART_TypeDef* USARTx, uint16_t USART_IT);








  



  



  

 
#line 29 "user\\main.c"
#line 1 ".\\FWlib\\inc\\stm32f10x_flash.h"




















 

 







 
#line 33 ".\\FWlib\\inc\\stm32f10x_flash.h"



 



 



 



 

typedef enum
{ 
  FLASH_BUSY = 1,
  FLASH_ERROR_PG,
  FLASH_ERROR_WRP,
  FLASH_COMPLETE,
  FLASH_TIMEOUT
}FLASH_Status;



 



 



 

#line 77 ".\\FWlib\\inc\\stm32f10x_flash.h"


 



 







 



 







 



 

 
#line 118 ".\\FWlib\\inc\\stm32f10x_flash.h"

 
#line 144 ".\\FWlib\\inc\\stm32f10x_flash.h"

 
#line 211 ".\\FWlib\\inc\\stm32f10x_flash.h"











 



 







 



 







 



 





#line 270 ".\\FWlib\\inc\\stm32f10x_flash.h"


 


 
#line 291 ".\\FWlib\\inc\\stm32f10x_flash.h"






 



 
#line 333 ".\\FWlib\\inc\\stm32f10x_flash.h"





 
#line 346 ".\\FWlib\\inc\\stm32f10x_flash.h"



 



 



 



 



 

 
void FLASH_SetLatency(uint32_t FLASH_Latency);
void FLASH_HalfCycleAccessCmd(uint32_t FLASH_HalfCycleAccess);
void FLASH_PrefetchBufferCmd(uint32_t FLASH_PrefetchBuffer);
void FLASH_Unlock(void);
void FLASH_Lock(void);
FLASH_Status FLASH_ErasePage(uint32_t Page_Address);
FLASH_Status FLASH_EraseAllPages(void);
FLASH_Status FLASH_EraseOptionBytes(void);
FLASH_Status FLASH_ProgramWord(uint32_t Address, uint32_t Data);
FLASH_Status FLASH_ProgramHalfWord(uint32_t Address, uint16_t Data);
FLASH_Status FLASH_ProgramOptionByteData(uint32_t Address, uint8_t Data);
FLASH_Status FLASH_EnableWriteProtection(uint32_t FLASH_Pages);
FLASH_Status FLASH_ReadOutProtection(FunctionalState NewState);
FLASH_Status FLASH_UserOptionByteConfig(uint16_t OB_IWDG, uint16_t OB_STOP, uint16_t OB_STDBY);
uint32_t FLASH_GetUserOptionByte(void);
uint32_t FLASH_GetWriteProtectionOptionByte(void);
FlagStatus FLASH_GetReadOutProtectionStatus(void);
FlagStatus FLASH_GetPrefetchBufferStatus(void);
void FLASH_ITConfig(uint32_t FLASH_IT, FunctionalState NewState);
FlagStatus FLASH_GetFlagStatus(uint32_t FLASH_FLAG);
void FLASH_ClearFlag(uint32_t FLASH_FLAG);
FLASH_Status FLASH_GetStatus(void);
FLASH_Status FLASH_WaitForLastOperation(uint32_t Timeout);

 
void FLASH_UnlockBank1(void);
void FLASH_LockBank1(void);
FLASH_Status FLASH_EraseAllBank1Pages(void);
FLASH_Status FLASH_GetBank1Status(void);
FLASH_Status FLASH_WaitForLastBank1Operation(uint32_t Timeout);

#line 408 ".\\FWlib\\inc\\stm32f10x_flash.h"








 



 



 

 
#line 30 "user\\main.c"
#line 1 ".\\FWlib\\inc\\misc.h"




















 

 







 
#line 33 ".\\FWlib\\inc\\misc.h"



 



 



 



 

typedef struct
{
  uint8_t NVIC_IRQChannel;                    


 

  uint8_t NVIC_IRQChannelPreemptionPriority;  

 

  uint8_t NVIC_IRQChannelSubPriority;         

 

  FunctionalState NVIC_IRQChannelCmd;         

    
} NVIC_InitTypeDef;
 


 



 
























 



 



 



 







 



 

#line 133 ".\\FWlib\\inc\\misc.h"


 



 

#line 151 ".\\FWlib\\inc\\misc.h"















 



 







 



 



 



 



 

void NVIC_PriorityGroupConfig(uint32_t NVIC_PriorityGroup);
void NVIC_Init(NVIC_InitTypeDef* NVIC_InitStruct);
void NVIC_SetVectorTable(uint32_t NVIC_VectTab, uint32_t Offset);
void NVIC_SystemLPConfig(uint8_t LowPowerMode, FunctionalState NewState);
void SysTick_CLKSourceConfig(uint32_t SysTick_CLKSource);









 



 



 

 
#line 31 "user\\main.c"
#line 1 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdarg.h"
 
 
 





 










#line 27 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdarg.h"








 

 
 
#line 57 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdarg.h"
    typedef struct __va_list { void *__ap; } va_list;

   






 


   










 


   















 




   

 


   




 



   





 







#line 138 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdarg.h"



#line 147 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdarg.h"

 

#line 32 "user\\main.c"








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








  
int main(void)
{	
	static  _Bool flag_ledtoogle=0;
  RCC_Configuration();	             
	LED_Configuration();
	KEY_Configuration();
  Usart1_Init();		             
  ADC_Configuration();				 
  USART_OUT(((USART_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x3800)),"\r\n USART1 print AD_value -------------------------- \r\n"); 
  while(1)
  {
  	 if (ticks++ >= 900000) 
		{        
			ticks   = 0;
			Clock1s = 1;
			flag_ledtoogle^=1;
		}
		if(flag_ledtoogle)
		{
				GPIO_ResetBits(((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x0C00)), ((uint16_t)0x0020));  
		}		
		else
		{
				GPIO_SetBits(((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x0C00)), ((uint16_t)0x0020));  
		}
	 if (Clock1s) 
		 {
				Clock1s = 0;   
					 
				USART_OUT(((USART_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x3800)),"The current AD value = %d \r\n", ADC_ConvertedValue);
     }  
		 
		 if (GPIO_ReadInputDataBit(((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x1000)),((uint16_t)0x0020))  == 0x00)
		 {
				iap_jump(0x08000000);
		 }
  }
}








void iap_jump(u32 iapxaddr)
{
	if(((*(vu32*)iapxaddr)&0x2FFE0000)==0x20000000)	
	{ 

		
		jump2iap=(iapfun)*(vu32*)(iapxaddr+4);		
	
		__set_MSP(*(volatile uint32_t*) iapxaddr);
		jump2iap();									
	}
	else
	{

	}
}






 
void KEY_Configuration(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(((uint32_t)0x00000010), ENABLE);

    
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = ((uint16_t)0x0020);
    GPIO_Init(((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x1000)), &GPIO_InitStructure);
}






 
void LED_Configuration(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    RCC_APB2PeriphClockCmd(((uint32_t)0x00000008) , ENABLE);
    
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  	
		GPIO_InitStructure.GPIO_Pin =  ((uint16_t)0x0020);
	  GPIO_Init(((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x0C00)), &GPIO_InitStructure);	
		GPIO_SetBits(((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x0C00)), ((uint16_t)0x0020));  
	
		RCC_APB2PeriphClockCmd(((uint32_t)0x00000020) , ENABLE);	
	  
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Pin =  ((uint16_t)0x0040) | ((uint16_t)0x0008);	 
		GPIO_Init(((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x1400)), &GPIO_InitStructure);			
  
    GPIO_SetBits(((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x1400)), ((uint16_t)0x0040) | ((uint16_t)0x0008));  
}








  
void ADC_Configuration(void)
{
	ADC_InitTypeDef ADC_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	DMA_InitTypeDef DMA_InitStructure;

    
  	GPIO_InitStructure.GPIO_Pin = ((uint16_t)0x0002);
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
  	GPIO_Init(((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x1000)), &GPIO_InitStructure);
	 
    RCC_AHBPeriphClockCmd(((uint32_t)0x00000001), ENABLE);

    
    RCC_APB2PeriphClockCmd(((uint32_t)0x00000200) , ENABLE);

  	 
	
	DMA_DeInit(((DMA_Channel_TypeDef *) ((((uint32_t)0x40000000) + 0x20000) + 0x0008)));
	DMA_InitStructure.DMA_PeripheralBaseAddr = ((u32)0x4001244C);			            
	DMA_InitStructure.DMA_MemoryBaseAddr = (u32)&ADC_ConvertedValue;	            
	DMA_InitStructure.DMA_DIR = ((uint32_t)0x00000000);					            
	DMA_InitStructure.DMA_BufferSize = 1;								            
	DMA_InitStructure.DMA_PeripheralInc = ((uint32_t)0x00000000);	 
	DMA_InitStructure.DMA_MemoryInc = ((uint32_t)0x00000080);				            
	DMA_InitStructure.DMA_PeripheralDataSize = ((uint32_t)0x00000100);		
	DMA_InitStructure.DMA_MemoryDataSize = ((uint32_t)0x00000400);				
	DMA_InitStructure.DMA_Mode = ((uint32_t)0x00000020);									
	DMA_InitStructure.DMA_Priority = ((uint32_t)0x00002000);
	DMA_InitStructure.DMA_M2M = ((uint32_t)0x00000000);
	DMA_Init(((DMA_Channel_TypeDef *) ((((uint32_t)0x40000000) + 0x20000) + 0x0008)), &DMA_InitStructure);
    
	 
	


	
	DMA_Cmd(((DMA_Channel_TypeDef *) ((((uint32_t)0x40000000) + 0x20000) + 0x0008)), ENABLE); 
  
  
	
	
 
	RCC_ADCCLKConfig(((uint32_t)0x00008000));                   

	ADC_InitStructure.ADC_Mode = ((uint32_t)0x00000000);	
	ADC_InitStructure.ADC_ScanConvMode = ENABLE;		
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;	
	ADC_InitStructure.ADC_ExternalTrigConv = ((uint32_t)0x000E0000);
	ADC_InitStructure.ADC_DataAlign = ((uint32_t)0x00000000);
	ADC_InitStructure.ADC_NbrOfChannel = 1;               
	ADC_Init(((ADC_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x2400)), &ADC_InitStructure);
	
	  

	
  	ADC_RegularChannelConfig(((ADC_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x2400)), ((uint8_t)0x0B), 1, ((uint8_t)0x05));	  
  	

	
	ADC_DMACmd(((ADC_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x2400)), ENABLE);
	
	ADC_Cmd(((ADC_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x2400)), ENABLE);	
	
	
	ADC_ResetCalibration(((ADC_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x2400)));
	
	while(ADC_GetResetCalibrationStatus(((ADC_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x2400))));
	
	
	ADC_StartCalibration(((ADC_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x2400)));
	
	while(ADC_GetCalibrationStatus(((ADC_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x2400))));
	
	
	ADC_SoftwareStartConvCmd(((ADC_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x2400)), ENABLE);	 
}







  
void RCC_Configuration(void){

  SystemInit(); 
  RCC_ADCCLKConfig(((uint32_t)0x00008000)); 
  RCC_APB2PeriphClockCmd(((uint32_t)0x00000001), ENABLE);
  RCC_AHBPeriphClockCmd(((uint32_t)0x00000001), ENABLE);
  RCC_APB2PeriphClockCmd(((uint32_t)0x00000200) , ENABLE);
  RCC_APB2PeriphClockCmd(((uint32_t)0x00000004) | ((uint32_t)0x00000008) | ((uint32_t)0x00000010) 
  						| ((uint32_t)0x00000020)| ((uint32_t)0x00000040) , ENABLE);
}








 
void Usart1_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure;
 
  RCC_APB2PeriphClockCmd( ((uint32_t)0x00004000) , ENABLE);	 

  GPIO_InitStructure.GPIO_Pin = ((uint16_t)0x2000); 			      
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x1400)), &GPIO_InitStructure);
  GPIO_ResetBits(((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x1400)), ((uint16_t)0x2000));			              

  GPIO_InitStructure.GPIO_Pin = ((uint16_t)0x0200);	         		 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;    		 
  GPIO_Init(((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x0800)), &GPIO_InitStructure);		    		 

  GPIO_InitStructure.GPIO_Pin = ((uint16_t)0x0400);	         	 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   	 
  GPIO_Init(((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x0800)), &GPIO_InitStructure);		         	 

  USART_InitStructure.USART_BaudRate = 9600;						
  USART_InitStructure.USART_WordLength = ((uint16_t)0x0000);		
  USART_InitStructure.USART_StopBits = ((uint16_t)0x0000);			
  USART_InitStructure.USART_Parity = ((uint16_t)0x0000);				
  USART_InitStructure.USART_HardwareFlowControl = ((uint16_t)0x0000);   
  USART_InitStructure.USART_Mode = ((uint16_t)0x0004) | ((uint16_t)0x0008);					

   
  USART_Init(((USART_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x3800)), &USART_InitStructure);							
    
  USART_Cmd(((USART_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x3800)), ENABLE);	
  
}









 
char *itoa(int value, char *string, int radix)
{
    int     i, d;
    int     flag = 0;
    char    *ptr = string;

     
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

     
    if (value < 0)
    {
        *ptr++ = '-';

         
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

     
    *ptr = 0;

    return string;

}  













 
void USART_OUT(USART_TypeDef* USARTx, uint8_t *Data,...){ 

	const char *s;
    int d;
   
    char buf[16];
    va_list ap;
    __va_start(ap, Data);

	while(*Data!=0){				                          
		if(*Data==0x5c){									  
			switch (*++Data){
				case 'r':							          
					USART_SendData(USARTx, 0x0d);	   

					Data++;
					break;
				case 'n':							          
					USART_SendData(USARTx, 0x0a);	
					Data++;
					break;
				
				default:
					Data++;
				    break;
			}
			
			 
		}
		else if(*Data=='%'){									  
			switch (*++Data){				
				case 's':										  
                	s = __va_arg(ap, const char *);
                	for ( ; *s; s++) {
                    	USART_SendData(USARTx,*s);
						while(USART_GetFlagStatus(USARTx, ((uint16_t)0x0040))==RESET);
                	}
					Data++;
                	break;
            	case 'd':										  
                	d = __va_arg(ap, int);
                	itoa(d, buf, 10);
                	for (s = buf; *s; s++) {
                    	USART_SendData(USARTx,*s);
						while(USART_GetFlagStatus(USARTx, ((uint16_t)0x0040))==RESET);
                	}
					Data++;
                	break;
				default:
					Data++;
				    break;
			}		 
		}
		else USART_SendData(USARTx, *Data++);
		while(USART_GetFlagStatus(USARTx, ((uint16_t)0x0040))==RESET);
	}
}
 

