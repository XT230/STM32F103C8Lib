#include "BlueTooth.h"

BlueTooth::BlueTooth(USART_TypeDef *USARTx, uint32_t baudRate, GPIOPin cmdPin, GPIOPin statePin, Buffer *buf) : 
USART(USARTx, baudRate, buf)
{
    this->cmdGPIO = GetGPIOx(cmdPin);
    this->stateGPIO = GetGPIOx(statePin);
    this->cmdPin = GetGPIOPin(cmdPin);
    this->statePin = GetGPIOPin(statePin);
    init();
}

void BlueTooth::init()
{
    GPIO_InitTypeDef GPIOInit;

    RCC_APB2PeriphClockCmd(GPIOClock(cmdGPIO) | GPIOClock(stateGPIO), ENABLE);

    // 初始化引脚
    GPIOInit.GPIO_Pin = cmdPin;
    GPIOInit.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIOInit.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(cmdGPIO, &GPIOInit);
    GPIO_SetBits(cmdGPIO, cmdPin);

    GPIOInit.GPIO_Pin = statePin;
    GPIOInit.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIOInit.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(stateGPIO, &GPIOInit);

}

void BlueTooth::writeCmd(const char *cmd)
{
    GPIO_ResetBits(cmdGPIO, cmdPin);
    write(cmd);
    GPIO_SetBits(cmdGPIO, cmdPin);
}

void BlueTooth::write(const char *str)
{
    while(*str != '\0')
    {
        sendByte(*str);
        str++;
    }
}