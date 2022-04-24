#ifndef _TOOLS_H_
#define _TOOLS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f10x.h"

/**
 * @brief GPIO的引脚定义
 * 
 */
typedef enum _GPIOPin
{
	// GPIOA
	PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7, PA8, PA9, PA10, PA11, PA12, PA13, PA14, PA15,

	// GPIOB
	PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7, PB8, PB9, PB10, PB11, PB12, PB13, PB14, PB15,

	// GPIOC
	PC0, PC1, PC2, PC3, PC4, PC5, PC6, PC7, PC8, PC9, PC10, PC11, PC12, PC13, PC14, PC15
}GPIOPin;

#define BufferSize 128

// 缓存区
typedef struct _Buffer
{
	uint8_t data[BufferSize];
	uint8_t writeIndex;
	uint8_t readIndex;
	uint8_t size;
}Buffer;

uint32_t GPIOClock(GPIO_TypeDef* GPIOx);
uint32_t TIMClock(TIM_TypeDef* TIMx);
GPIO_TypeDef* GetGPIOx(GPIOPin pin);
uint16_t GetGPIOPin(GPIOPin pin);
uint8_t EXTIIRQn(GPIOPin pin);

// 获得串口所在的时钟总线
#define USARTClock(USARTx) \
		((USARTx == USART1) ? RCC_APB2Periph_USART1 : \
		((USARTx == USART2) ? RCC_APB1Periph_USART2 : \
		((USARTx == USART3) ? RCC_APB1Periph_USART3 : \
		(0))))

// 获取TIMx的中断通道
#define TIMIRQn(TIMx) \
		((TIMx == TIM1) ? TIM1_UP_IRQn 	: \
		((TIMx == TIM2) ? TIM2_IRQn 	: \
		((TIMx == TIM3) ? TIM3_IRQn 	: \
		((TIMx == TIM4) ? TIM4_IRQn 	: \
		(0)))))

// 获得串口的中断通道
#define USARTIRQn(USARTx) \
		((USARTx == USART1) ? USART1_IRQn : \
		((USARTx == USART2) ? USART2_IRQn : \
		((USARTx == USART3) ? USART3_IRQn : \
		(0))))

#define GetEXTILine(pin) GetGPIOPin(pin)
  
void delay_init(void);
void delay_us(u32 nus);
void delay_ms(u16 nms);

#ifdef __cplusplus
}
#endif

#endif