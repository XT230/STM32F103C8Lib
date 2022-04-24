#ifndef _BLUETOOTH_H_
#define _BLUETOOTH_H_

#include "stm32f10x.h"
#include "USART.h"
#include "tools.h"

class BlueTooth : public USART
{
private:
    GPIO_TypeDef *cmdGPIO;
    GPIO_TypeDef *stateGPIO;
    uint16_t cmdPin;
    uint16_t statePin;

public:
    BlueTooth(USART_TypeDef *USARTx, uint32_t baudRate, GPIOPin cmdPin, GPIOPin statePin, Buffer *buf);
    void init();
    void writeCmd(const char *cmd);
    void write(const char *str);
};

#endif