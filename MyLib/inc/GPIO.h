#ifndef _GPIO_H_
#define _GPIO_H_

#include "stm32f10x.h"
#include "tools.h"


class GPIO
{
private:
    GPIO_TypeDef *GPIOx;        // select GPIOA ~ GPIOE
    uint16_t pin;               // select one pin of the selected GPIOx
    GPIOMode_TypeDef mode;      // select GPIOx's work mode
    GPIOSpeed_TypeDef speed;	// select GPIOx's work speed
	uint8_t pinWidth;
	friend class Range;   

public:
	GPIO(GPIOPin pin, GPIOMode_TypeDef mode, GPIOSpeed_TypeDef speed = GPIO_Speed_50MHz);
	GPIO(GPIO_TypeDef *GPIOx, uint8_t pinWidth);
	GPIO(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIOMode_TypeDef mode, GPIOSpeed_TypeDef speed);
	void init();
	void setMode(GPIOMode_TypeDef mode);
	uint8_t operator=(uint16_t status);
	operator uint16_t();

};

#endif