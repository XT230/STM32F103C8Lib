#include "tools.h"

static u8  fac_us = 0;                            //us延时倍乘数               
static u16 fac_ms = 0;                            //ms延时倍乘数

//初始化延迟函数
//SYSTICK的时钟固定为HCLK时钟的1/8，即SYSTICK=SYSCLK/8
//SYSCLK:系统时钟
void delay_init()
{
    SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);    //选择外部时钟  HCLK/8

    fac_us=SystemCoreClock / 8000000;                          //SYSTICK时钟为9M（即8分频）时，fac_us=9，即SysTick倒数9个数，耗时1us
    fac_ms=(u16)fac_us*1000;                                 //非OS下,代表每个ms需要的systick时钟数   
}    

//查询SysTick->CTRL寄存器bit0是否为1，当为1时，说明倒计时时间到；
//整个延时方法中，不进入SysTick中断；
//延时nus
//nus为要延时的us数.                                               
void delay_us(u32 nus)
{        
    u32 temp;             
    SysTick->LOAD=nus*fac_us;                       //延时时间加载               
    SysTick->VAL=0x00;                              //清空计数器
    SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;        //开始倒数      
 
    //do while 判断就是 systick 使能（bit0）位为 1 且（bit16）为1的时候等待结束
    do
    {
        temp=SysTick->CTRL;
    }while((temp&0x01)&&!(temp&(1<<16)));           //等待时间到达
 
    SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;        //关闭计数器
    SysTick->VAL =0X00;                             //清空计数器     
}

void delay_ms(u16 nms)
{        
    u32 temp;             
    SysTick->LOAD=nms*fac_ms;                       //延时时间加载               
    SysTick->VAL=0x00;                              //清空计数器
    SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;        //开始倒数      
 
    //do while 判断就是 systick 使能（bit0）位为 1 且（bit16）为1的时候等待结束
    do
    {
        temp=SysTick->CTRL;
    }while((temp&0x01)&&!(temp&(1<<16)));           //等待时间到达
 
    SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;        //关闭计数器
    SysTick->VAL =0X00;                             //清空计数器     
}

/**
 * @brief 获得GPIOx对应的时钟
 * 
 * @param GPIOx 
 * @return uint32_t 
 */
uint32_t GPIOClock(GPIO_TypeDef* GPIOx)
{
	return  ((GPIOx == GPIOA) ? RCC_APB2Periph_GPIOA : \
			((GPIOx == GPIOB) ? RCC_APB2Periph_GPIOB : \
			((GPIOx == GPIOC) ? RCC_APB2Periph_GPIOC : \
			((GPIOx == GPIOD) ? RCC_APB2Periph_GPIOD : \
			((GPIOx == GPIOE) ? RCC_APB2Periph_GPIOE : \
			(0))))));
}

/**
 * @brief 获取TIMx所在的时钟总线
 * 
 * @param TIMx 
 * @return uint32_t 
 */
uint32_t TIMClock(TIM_TypeDef* TIMx)
{
	return  ((TIMx == TIM1) ? RCC_APB2Periph_TIM1 : \
			((TIMx == TIM2) ? RCC_APB1Periph_TIM2 : \
			((TIMx == TIM3) ? RCC_APB1Periph_TIM3 : \
			((TIMx == TIM4) ? RCC_APB1Periph_TIM4 : \
			(0)))));
}

GPIO_TypeDef* GetGPIOx(GPIOPin pin)
{
	return  ((pin < 16) ? GPIOA : \
			((pin < 32) ? GPIOB : \
			((GPIOC))));
}

uint16_t GetGPIOPin(GPIOPin pin)
{
	return ((uint16_t)((uint16_t)0x0001 << (pin % 16)));
}

/**
 * @brief 获取外部中断通道
 * 
 * @param pin 
 * @return uint8_t 
 */
uint8_t EXTIIRQn(GPIOPin pin)
{
	uint8_t a = pin % 16;
	return 	((a <= 4) ? a + 6 : \
			((a >= 5) && (a <= 9)) ? EXTI9_5_IRQn : \
			(EXTI15_10_IRQn)); 
}
