#include "DS18B20.h"

/**
 * @brief 创建一个DS18B20实例
 * 
 * @param precision 温度转换精度(19, 10, 11, 12位)
 */
DS18B20::DS18B20(Precision precision)
{
	TH = 0;
	TL = 0;
	updated = false;
	temp = 0;

	RCC_APB2PeriphClockCmd(GPIOClock(GetGPIOx(DQ)), ENABLE);
	DQ_OUT;
	DQ_On;

	setPrecision(precision);
}

/**
 * @brief 更新温度数据
 * 
 * @return uint8_t 成功(true),失败(false)
 */
void DS18B20::update()
{
	convert();
	uint16_t t = readTemp();
	int8_t sign = (((t & 0xF800) != 0) ? -1 : 1);
	if(sign == -1) t = (~t + 0x01);
	temp = t * 0.0625 * sign;
	updated = true;
}

/**
 * @brief 开始信号
 * 
 * @return uint8_t 
 */
uint8_t DS18B20::start()
{
	DQ_OUT;
	DQ_Off;
	delay_us(750);
	DQ_On;
	DQ_IN;
	uint8_t i = 0;
	while(DQ_Read != RESET)
	{
		delay_us(10);
		i++;
		if(i > 12)return false;
	}
	while(DQ_Read == RESET);
	return true;
}

/**
 * @brief 发送温度转换命令
 * 
 * @return uint8_t 
 */
void DS18B20::convert()
{
	if(start())
	{
		skipROM();
		writeByte(0x44);
		DQ_IN;
		delay_us(50);
		while(DQ_Read == RESET);
		DQ_OUT;
	}
}

/**
 * @brief 设置转换精度
 * 
 * @param precision 转换精度
 */
void DS18B20::setPrecision(Precision precision)
{
	this->precision = precision;
	if(start())
	{
		skipROM();
		writeByte(0x4E);	// 写寄存器命令
		writeByte(TH);
		writeByte(TL);
		writeByte(precision);
	}
}

/**
 * @brief 发送跳过ROM指令
 * 
 */
void DS18B20::skipROM()
{
	writeByte(0xCC);
}

/**
 * @brief 读取温度寄存器的值
 * 
 * @return uint16_t 
 */
uint16_t DS18B20::readTemp()
{
	uint16_t data = 0;
	if(start())
	{
		skipROM();
		writeByte(0xBE);	// 发送读命令
		data = readByte();
		uint16_t tem = readByte();
		data += (tem << 8);
	}
	return data;
}

uint8_t DS18B20::readByte()
{
	DQ_OUT;
	uint8_t data = 0;
	for(uint8_t i = 0; i < 8; i++)
	{
		data >>= 1;
		DQ_Off;
		delay_us(2);
		DQ_On;
		DQ_IN;
		delay_us(20);
		if(DQ_Read != RESET)data |= 0x80;
		while(DQ_Read == RESET)
			;
		DQ_OUT;
		DQ_On;
	}
	return data;
}

void DS18B20::writeByte(uint8_t data)
{
	DQ_OUT;
	for(uint8_t i = 0; i < 8; i++)
	{
		if((data & 0x01) == 1)
		{
			DQ_Off;
			delay_us(2);
			DQ_On;
			delay_us(90);
		}
		else 
		{
			DQ_Off;
			delay_us(90);
			DQ_On;
			delay_us(2);
		}
		
		data >>= 1;
	}
}
