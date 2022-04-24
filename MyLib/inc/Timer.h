#ifndef _TIMER_H
#define _TIMER_H

#include "stm32f10x.h"
#include "tools.h"

/**
 * @brief 定时器
 * 
 */
class Timer
{
private:
    TIM_TypeDef *TIMx;
    uint16_t TIM_Prescaler;     
    uint16_t TIM_CounterMode;
    uint16_t TIM_Period;
    uint16_t TIM_ClockDivision; 
	uint8_t state;

public:
    Timer(TIM_TypeDef *TIMx, uint16_t TIM_Period, 
        uint16_t TIM_Prescaler = 0, uint16_t TIM_ClockDivision = TIM_CKD_DIV1, 
        uint16_t TIM_CounterMode = TIM_CounterMode_Up);
    void init();
	void start();
	void stop();
	void reverseState();
	uint16_t getCounter(){return TIM_GetCounter(TIMx);}
	void setCounter(uint16_t counter){TIM_SetCounter(TIMx, counter);}

};

#endif

