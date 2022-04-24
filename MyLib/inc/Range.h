#ifndef _RANGE_H_
#define _RANGE_H_

#include "stm32f10x.h"
#include "GPIO.h"
#include "Timer.h"

#define UNIT_CM 0
#define UINT_M  1

class Range
{
private:
	GPIO trig;
	GPIO echo;
	Timer count;
	uint16_t distance;
	uint8_t updated;
	friend void EXTI9_5_IRQHandler();

public:
	Range(GPIOPin trig, GPIOPin echo);
	float getDistance(uint8_t unit = UNIT_CM);
	void update();
	uint8_t isUpdated(){return updated;}

private:

};

#endif