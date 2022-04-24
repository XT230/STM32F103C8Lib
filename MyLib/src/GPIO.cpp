#include "GPIO.h"

GPIO::GPIO(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIOMode_TypeDef mode, GPIOSpeed_TypeDef speed)
{
	this->GPIOx = GPIOx;
    this->pin = GPIO_Pin;
    this->mode = mode;
    this->speed = speed;
	init();
}

GPIO::GPIO(GPIOPin pin, GPIOMode_TypeDef mode, GPIOSpeed_TypeDef speed) :
GPIO(GetGPIOx(pin), GetGPIOPin(pin), mode, speed)
{
	pinWidth = 1;
}

GPIO::GPIO(GPIO_TypeDef *GPIOx, uint8_t pinWidth)
{
	pin = 0x01;
	for(uint8_t i = 0; i < (pinWidth - 1); i++)
	{
		pin <<= 1;
		pin |= 0x01;
	}
	this->pinWidth = pinWidth;
	this->GPIOx = GPIOx;
    this->mode = GPIO_Mode_Out_PP;
    this->speed = GPIO_Speed_50MHz;
	init();
}

/**
 * @brief 初始化引脚
 * 
 */
void GPIO::init()
{
    GPIO_InitTypeDef GPIOInit;      // 初始化GPIO引脚的结构体

    RCC_APB2PeriphClockCmd(GPIOClock(GPIOx), ENABLE);       // 使能对应的时钟

    // 向结构体中写入对应的信息
    GPIOInit.GPIO_Pin = pin;
    GPIOInit.GPIO_Mode = mode;
    GPIOInit.GPIO_Speed = speed;

    GPIO_Init(GPIOx, &GPIOInit);        // 初始化GPIO
}

/**
 * @brief 设置引脚输出模式
 * 
 * @param mode 指定的模式
 */
void GPIO::setMode(GPIOMode_TypeDef mode)
{
	GPIO_InitTypeDef GPIOInit;

	GPIOInit.GPIO_Pin = pin;
    GPIOInit.GPIO_Mode = mode;
    GPIOInit.GPIO_Speed = speed;
	this->mode = mode;

	GPIO_Init(GPIOx, &GPIOInit);
}

/**
 * @brief 写数据
 * 
 * @param status 指定引脚状态
 * @return uint8_t 
 */
uint8_t GPIO::operator=(uint16_t status)
{
	if(pinWidth != 1)
	{
		uint16_t preStatus = GPIOx->ODR;
		preStatus &= (~pin);
		preStatus |= status;
		GPIOx->ODR = preStatus;
	}
	else 
	{
		if(status == 1)GPIO_SetBits(GPIOx, pin);
		else if(status == 0)GPIO_ResetBits(GPIOx, pin);
	}
	
	return status;
}

GPIO::operator std::uint16_t()
{
	uint16_t data = (GPIOx->IDR & pin);
	if(pinWidth != 1)
	{
		return data;
	}
	else
	{
		if(data == 0)return 0;
		else return 1;
	}
}
