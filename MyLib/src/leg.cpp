#include "leg.h"

LEG::LEG(uint8_t addr, uint8_t PWM_Channel) 
{
    this->PWM_Channel = PWM_Channel;
    this->addr = addr;

    I2C_BUSInit();

    if(isSleep())
    {
        // 设置周期
        I2C_Start();
        I2C_WriteByte(this->addr << 1);
        I2C_WaitAck();
        I2C_WriteByte(0xFE);
        I2C_WaitAck();
        I2C_WriteByte(121);
        I2C_WaitAck();
        I2C_Stop();

        // 开始工作
        I2C_Start();
        I2C_WriteByte(this->addr << 1);
        I2C_WaitAck();
        I2C_WriteByte(0x00);
        I2C_WaitAck();
        I2C_WriteByte(0x21);
        I2C_WaitAck();
        I2C_Stop();

        delay_us(500);  // 等待PC9685内部时钟稳定
    }
    init();
}

bool LEG::isSleep()
{
    I2C_Start();
    I2C_WriteByte(this->addr << 1);
    I2C_WaitAck();
    I2C_WriteByte(0x00);
    I2C_WaitAck();
    I2C_Start();
    I2C_WriteByte((this->addr << 1) + 1);
    I2C_WaitAck();
    uint8_t data = I2C_ReadByte();
    I2C_NACK();
    I2C_Stop();
    return ((data & 0x10) >> 4);
}

void LEG::setAngle(uint8_t A_Angle, uint8_t B_Angle, uint8_t C_Angle)
{
    I2C_Start();
    I2C_WriteByte(this->addr << 1);
    I2C_WaitAck();
    I2C_WriteByte(PWM_BASE + PWM_Channel * 4);
    I2C_WaitAck();

    I2C_WriteByte(0);
    I2C_WaitAck();
    I2C_WriteByte(0);
    I2C_WaitAck();
    I2C_WriteByte(AngleMap(A_Angle) & 0xff);
    I2C_WaitAck();
    I2C_WriteByte(AngleMap(A_Angle) >> 8);
    I2C_WaitAck();

    I2C_WriteByte(1);
    I2C_WaitAck();
    I2C_WriteByte(0);
    I2C_WaitAck();
    I2C_WriteByte(AngleMap(B_Angle) & 0xff);
    I2C_WaitAck();
    I2C_WriteByte(AngleMap(B_Angle) >> 8);
    I2C_WaitAck();

    I2C_WriteByte(1);
    I2C_WaitAck();
    I2C_WriteByte(0);
    I2C_WaitAck();
    I2C_WriteByte(AngleMap(C_Angle) & 0xff);
    I2C_WaitAck();
    I2C_WriteByte(AngleMap(C_Angle) >> 8);
    I2C_WaitAck();
    
    I2C_Stop();
}

void LEG::init()
{
    setAngle(90, 55, 75);
}