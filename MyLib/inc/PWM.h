#ifndef _PWM_H_
#define _PWM_H_

#include "stm32f10x.h"
#include "tools.h"

/**
 * @brief PWM输出引脚
 * 
TIM1 :
    PA8, PA9, PA10, PA11
TIM2 :
    PA0, PA1, PA2 , PA3
TIM3 :
    PA6, PA7, PB0 , PB1
TIM4 :
    PB6, PB7, PB8 , PB9 
 * 
 */

    



#define GetTIM(pin) \
        (((pin >=  8) && (pin <= 11)) ? TIM1 : \
        (((pin >=  0) && (pin <=  3)) ? TIM2 : \
        (((pin >= 22) && (pin <= 25)) ? TIM4 : \
        (TIM3))))


/**
 * @brief PWM
 * 
 */
class PWM
{
private:
    uint16_t prescaler;
    uint16_t period;
    uint16_t pulse;
    GPIO_TypeDef *GPIOx;
    TIM_TypeDef *TIMx;
    uint16_t pin;
public:
    PWM(uint16_t period, uint16_t prescaler, GPIOPin pin, uint16_t pulse = 0);
    void init();
    void setPulse(uint16_t pulse);
};

#endif