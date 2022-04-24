#include "Timer.h"

/**
 * @brief Construct a new Timer:: Timer object
 * 
 * @param TIMx 
 * @param TIM_Period 
 * @param TIM_Prescaler 
 * @param TIM_ClockDivision 
 * @param TIM_CounterMode 
 */
Timer::Timer(TIM_TypeDef *TIMx, uint16_t TIM_Period, 
        uint16_t TIM_Prescaler, uint16_t TIM_ClockDivision, 
        uint16_t TIM_CounterMode)
{
    this->TIMx = TIMx;
    this->TIM_Period = TIM_Period - 1;
    this->TIM_Prescaler = TIM_Prescaler - 1;
    this->TIM_ClockDivision = TIM_ClockDivision;
    this->TIM_CounterMode = TIM_CounterMode;
	state = DISABLE;
    init();
}

/**
 * @brief 初始化定时器
 * 
 * @param None 
 * 
 * @retval None  
 */
void Timer::init()
{
    TIM_TimeBaseInitTypeDef TIMxInit;
    NVIC_InitTypeDef NVICInit;
    
	TIM_DeInit(TIMx);
	TIM_Cmd(TIMx, DISABLE);

    if(TIMx == TIM1)RCC_APB2PeriphClockCmd(TIMClock(TIMx), ENABLE);
    else RCC_APB1PeriphClockCmd(TIMClock(TIMx), ENABLE);

    TIMxInit.TIM_Period = TIM_Period;
    TIMxInit.TIM_Prescaler = TIM_Prescaler;
    TIMxInit.TIM_CounterMode = TIM_CounterMode;
    TIMxInit.TIM_ClockDivision = TIM_ClockDivision;
    TIMxInit.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIMx, &TIMxInit);

    TIM_ITConfig(TIMx, TIM_IT_Update, ENABLE);

    NVICInit.NVIC_IRQChannel = TIMIRQn(TIMx);
    NVICInit.NVIC_IRQChannelPreemptionPriority = 0;
    NVICInit.NVIC_IRQChannelSubPriority = 3;
    NVICInit.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVICInit);

	
	TIM_SetCounter(TIMx, 0);
}

/**
 * @brief 启动定时器
 * 
 * @param None 
 * 
 * @retval None
 * 
 */
void Timer::start()
{
    TIM_Cmd(TIMx, ENABLE);
	state = ENABLE;
}

/**
 * @brief 停止定时器
 * 
 * @param None 
 * 
 * @retval None
 * 
 */
void Timer::stop()
{
    TIM_Cmd(TIMx, DISABLE);
	state = DISABLE;
}

void Timer::reverseState()
{
	if(state == ENABLE)TIM_Cmd(TIMx, ENABLE);
	else TIM_Cmd(TIMx, DISABLE);
	state = !state;
}
