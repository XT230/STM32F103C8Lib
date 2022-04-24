#ifndef _I2C_H_
#define _I2C_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f10x.h"
#include "tools.h"

#define SDA PB7
#define SCL PB6
#define SDA_GPIO GetGPIOx(SDA)
#define SCL_GPIO GetGPIOx(SCL)
#define SDA_Pin GetGPIOPin(SDA)
#define SCL_Pin GetGPIOPin(SCL)
#define SCL_On_1 GPIO_SetBits(SCL_GPIO, SCL_Pin)
#define SCL_Off_0 GPIO_ResetBits(SCL_GPIO, SCL_Pin)
#define SDA_On_1 GPIO_SetBits(SDA_GPIO, SDA_Pin)
#define SDA_Off_0 GPIO_ResetBits(SDA_GPIO, SDA_Pin)
#define Read_SDA GPIO_ReadInputDataBit(SDA_GPIO, SDA_Pin)
#define ACK 0
#define NACK 1
#define SDA_IN()  {GPIOB->CRL&=0X0FFFFFFF;GPIOB->CRL|=(u32)8<<28;}
#define SDA_OUT() {GPIOB->CRL&=0X0FFFFFFF;GPIOB->CRL|=(u32)3<<28;}

void I2C_BUSInit();
void I2C_Start();
void I2C_Stop();
void I2C_ACK();
void I2C_NACK();
uint8_t I2C_WaitAck();
void I2C_WriteByte(uint8_t data);
uint8_t I2C_ReadByte();

#ifdef __cplusplus
}
#endif

#endif