#ifndef _LCD1602_H_
#define _LCD1602_H_

#include "stm32f10x.h"
#include "GPIO.h"

class LCD1602
{
private:
	GPIO Data;
	GPIO RS, RW, E;
	uint8_t row;
	uint8_t column;

public:
	LCD1602(GPIO_TypeDef *GPIOx, GPIOPin RS, GPIOPin RW, GPIOPin E);
	void clear();
	uint8_t isBusy();
	uint8_t charAt(uint8_t row, uint8_t column);
	void setPos(uint8_t row, uint8_t column);
	void print(const char* s);
	void print(const char c){while(isBusy()); writeByte(c);};

private:
	void writeCmd(uint8_t cmd);
	void writeByte(uint8_t data);
	uint8_t readByte();
	void init();

};

#endif