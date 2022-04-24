#include "USART.h"

/**
 * @brief Construct a new USART::USART object
 * 
 * @param USARTx 选择串口，可以是以下参数之一：
 *      @arg USART1
 *      @arg USART2
 *      @arg USART3
 * @param baudRate 传输波特率
 */
USART::USART(USART_TypeDef *USARTx, uint32_t baudRate, Buffer *buf)
{
    this->USARTx = USARTx;
    this->baudRate = baudRate;
    this->buf = buf;
    if(USARTx == USART1)
    {
        GPIOx = GPIOA;
        TX = GPIO_Pin_9;
        RX = GPIO_Pin_10;
    }
    else if(USARTx == USART2)
    {
        GPIOx = GPIOA;
        TX = GPIO_Pin_2;
        RX = GPIO_Pin_3;
    }
    else if(USARTx == USART3)
    {
        GPIOx = GPIOB;
        TX = GPIO_Pin_10;
        RX = GPIO_Pin_11;
    }
    init();
}

/**
 * @brief 初始化串口
 * 
 */
void USART::init()
{
    GPIO_InitTypeDef GPIOInit;
    USART_InitTypeDef USARTInit;
    NVIC_InitTypeDef NVICInit;

    // 使能对应的时钟
    if(USARTx == USART1)RCC_APB2PeriphClockCmd(USARTClock(USARTx), ENABLE);
    else RCC_APB1PeriphClockCmd(USARTClock(USARTx), ENABLE);
    RCC_APB2PeriphClockCmd(GPIOClock(GPIOx), ENABLE);

    // 初始化对应的引脚
    GPIOInit.GPIO_Pin = RX;
    GPIOInit.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIOInit.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOx, &GPIOInit);

    GPIOInit.GPIO_Pin = TX;
    GPIOInit.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIOInit.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOx, &GPIOInit);

    // 初始化串口
    USART_DeInit(USARTx);
    USARTInit.USART_BaudRate = baudRate;
    USARTInit.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USARTInit.USART_WordLength = USART_WordLength_8b;
    USARTInit.USART_StopBits = USART_StopBits_1;
    USARTInit.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USARTInit.USART_Parity = USART_Parity_No;
    USART_Init(USARTx, &USARTInit);

    // 初始化串口中断
    NVICInit.NVIC_IRQChannel = USARTIRQn(USARTx);
    NVICInit.NVIC_IRQChannelPreemptionPriority = 3;
    NVICInit.NVIC_IRQChannelSubPriority = 3;
    NVICInit.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVICInit);

    // 使能串口中断
    USART_ITConfig(USARTx, USART_IT_RXNE, ENABLE);
    USART_Cmd(USARTx, ENABLE);

}

/**
 * @brief 传输一字节数据
 * 
 * @param data 要传输的数据(0~255)
 */
void USART::sendByte(uint16_t data)
{
    USART_SendData(USARTx, data);
    while(USART_GetFlagStatus(USARTx, USART_FLAG_TC) != SET);
    USART_ClearFlag(USARTx, USART_FLAG_TC);
}

/**
 * @brief 读取一字节数据
 * 
 * @return uint8_t : 读取的数据
 */
uint8_t USART::readByte()
{
    uint8_t data = buf->data[buf->readIndex];
    buf->readIndex++;
    buf->size--;
    if(buf->readIndex >= BufferSize)buf->readIndex = 0;
    return data;
}

/**
 * @brief 判断缓冲区是否有数据
 * 
 * @return bool : 有数据(true), 无数据(false)
 */
bool USART::available()
{
    if(buf->size > 0)return true;
    else return false;
}

/**
 * @brief 设置传输波特率
 * 
 * @param baudRate 波特率
 */
void USART::setBaudRate(uint32_t baudRate)
{
    
}