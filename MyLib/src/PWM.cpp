#include "PWM.h"

/**
 * @brief Construct a new PWM::PWM object
 * 
 * @param period 周期
 * @param prescaler 预分频
 * @param pin PWM输出引脚
 * @param pulse 脉冲宽度
 */
PWM::PWM(uint16_t period, uint16_t prescaler, GPIOPin pin, uint16_t pulse)
{
    this->period = period;
    this->prescaler = prescaler;
    if(pulse > period)pulse = period;
    this->pulse = pulse;
    this->GPIOx = GetGPIOx(pin);
    this->TIMx = GetTIM(pin);
    this->pin = GetGPIOPin(pin);
    init();
}

/**
 * @brief 初始化PWM
 * 
 */
void PWM::init()
{
    TIM_TimeBaseInitTypeDef TIMInit;
    TIM_OCInitTypeDef TIMOCInit;
    GPIO_InitTypeDef GPIOInit;

    // 使能对应外设的时钟
    if(TIMx == TIM1)RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
    else RCC_APB1PeriphClockCmd(TIMClock(TIMx), ENABLE);
    RCC_APB2PeriphClockCmd(GPIOClock(GPIOx), ENABLE);

    // 初始化引脚
    GPIOInit.GPIO_Pin = pin;
    GPIOInit.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIOInit.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOx, &GPIOInit);

    // 初始化时基单元
    TIMInit.TIM_Period = period;
    TIMInit.TIM_Prescaler = prescaler;
    TIMInit.TIM_CounterMode = TIM_CounterMode_Up;
    TIMInit.TIM_ClockDivision = 0;
    TIMInit.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIMx, &TIMInit);

    // 设置为输出比较模式
    TIMOCInit.TIM_Pulse = pulse;
    TIMOCInit.TIM_OCMode = TIM_OCMode_PWM1;
    TIMOCInit.TIM_OutputState = ENABLE;
    TIMOCInit.TIM_OCPolarity = TIM_OCPolarity_High;
    if(pin % 4 == 0)TIM_OC1Init(TIMx, &TIMOCInit);
    else if(pin % 4 == 1)TIM_OC2Init(TIMx, &TIMOCInit);
    else if(pin % 4 == 2)TIM_OC3Init(TIMx, &TIMOCInit);
    else if(pin % 4 == 3)TIM_OC4Init(TIMx, &TIMOCInit);

    if(TIMx == TIM1)TIM_CtrlPWMOutputs(TIM1, ENABLE);
    
    // 使能预装载功能
    if(pin % 4 == 0)TIM_OC1PreloadConfig(TIMx, ENABLE);
    else if(pin % 4 == 1)TIM_OC2PreloadConfig(TIMx, ENABLE);
    else if(pin % 4 == 2)TIM_OC3PreloadConfig(TIMx, ENABLE);
    else if(pin % 4 == 3)TIM_OC4PreloadConfig(TIMx, ENABLE);
    TIM_ARRPreloadConfig(TIMx, ENABLE);

    // 开启PWM输出
    TIM_Cmd(TIMx, ENABLE);
}

void PWM::setPulse(uint16_t pulse)
{
    // 设置脉冲宽度
    if(pin % 4 == 0)TIM_SetCompare1(TIMx, pulse);
    else if(pin % 4 == 1)TIM_SetCompare2(TIMx, pulse);
    else if(pin % 4 == 2)TIM_SetCompare3(TIMx, pulse);
    else if(pin % 4 == 3)TIM_SetCompare4(TIMx, pulse);
}