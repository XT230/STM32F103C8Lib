#ifndef _LEG_H_
#define _LEG_H_

#include "stm32f10x.h"
#include "I2C.h"

#define PWM_BASE (0x06)
#define AngleMap(angle) ((uint16_t)(angle * 2.2756 + 102.4))

class LEG
{
private:
    uint8_t PWM_Channel;
    uint8_t addr;

public:
    LEG(uint8_t addr, uint8_t PWM_Channel);
    void init();
    void setAngle(uint8_t A_Angle, uint8_t B_Angle, uint8_t C_Angle);
    bool isSleep();
};

#endif