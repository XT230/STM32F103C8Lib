#ifndef _USART_H_
#define _USART_H_

#include "stm32f10x.h"
#include "tools.h"

class USART
{
private:
    USART_TypeDef *USARTx;
    GPIO_TypeDef *GPIOx;
    uint32_t baudRate;
    uint16_t TX;
    uint16_t RX;
    Buffer *buf;
public:
    USART(USART_TypeDef *USARTx, uint32_t baudRate, Buffer *buf);
    void init();
    void sendByte(uint16_t data);
    uint8_t readByte();
    bool available();
    void setBaudRate(uint32_t baudRate);
};

#endif