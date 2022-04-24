#include "I2C.h"

void I2C_BUSInit()
{
    delay_init();
    GPIO_InitTypeDef GPIOInit;
    
    RCC_APB2PeriphClockCmd(GPIOClock(SDA_GPIO), ENABLE);
    RCC_APB2PeriphClockCmd(GPIOClock(SCL_GPIO), ENABLE);

    GPIOInit.GPIO_Pin = SDA_Pin;
    GPIOInit.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIOInit.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(SDA_GPIO, &GPIOInit);
    SDA_On_1;
    

    GPIOInit.GPIO_Pin = SCL_Pin;
    GPIOInit.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIOInit.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(SCL_GPIO, &GPIOInit);
    SCL_On_1;
    
}

void I2C_Start()
{
    SDA_OUT();
    SDA_On_1;
    SCL_On_1;
    delay_us(4);
    SDA_Off_0;
    delay_us(4);
    SCL_Off_0;
}

void I2C_Stop()
{
    SDA_OUT();
    SCL_Off_0;
    SDA_Off_0;
    delay_us(4);
    SCL_On_1;
    SDA_On_1;
    delay_us(4);
}

void I2C_ACK()
{
    SCL_Off_0;
    SDA_OUT();
    SDA_Off_0;
    delay_us(2);
    SCL_On_1;
    delay_us(2);
    SCL_Off_0;
}

void I2C_NACK()
{
    SCL_Off_0;
    SDA_OUT();
    SDA_On_1;
    delay_us(2);
    SCL_On_1;
    delay_us(2);
    SCL_Off_0;
}

uint8_t I2C_WaitAck()
{
    uint16_t errorCnt = 0;
    SDA_IN();
    SDA_On_1;
    delay_us(1);
    SCL_On_1;
    delay_us(1);
    while(Read_SDA != RESET)
    {
        errorCnt++;
        if(errorCnt > 128)return NACK;
    }
    SCL_Off_0;
    return ACK;
}

void I2C_WriteByte(uint8_t data)
{
    SDA_OUT();
    SCL_Off_0;
    for(uint8_t i = 0; i < 8; i++)
    {
        if((data & 0x80) >> 7)SDA_On_1;
        else SDA_Off_0;
        delay_us(2);
        SCL_On_1;
        delay_us(2);
        data <<= 1;
        SCL_Off_0;
        delay_us(2);
    }
}

uint8_t I2C_ReadByte()
{
    uint8_t data = 0;
    SDA_IN();
    delay_us(2);
    for(uint8_t i = 0; i < 8; i++)
    {
        SCL_Off_0;
        delay_us(2);
        SCL_On_1;
        data <<= 1;
        data |= Read_SDA;
        delay_us(2);
        // SCL_Off_0;
        // delay_us(2);
    }
    return data;
}