#ifndef _DS18B20_H_
#define _DS18B20_H_

#include "stm32f10x.h"
#include "tools.h"

enum Precision
{
	Precision_9  = 0x1F,
	Precision_10 = 0x3F,
	Precision_11 = 0x5F,
	Precision_12 = 0x7F
};

#define DQ PA7
#define DQ_On GPIO_SetBits(GPIOA, GPIO_Pin_7)
#define DQ_Off GPIO_ResetBits(GPIOA, GPIO_Pin_7)
#define DQ_Read GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7)
#define DQ_IN {GPIOA->CRL &= 0X0FFFFFFF; GPIOA->CRL |= (u32)8<<28; GPIOA->BSRR = (0x01 << 7);}
#define DQ_OUT {GPIOA->CRL &= 0X0FFFFFFF; GPIOA->CRL |= (u32)3<<28;}

class DS18B20
{
private:
	uint64_t ROM;
	Precision precision;
	float temp;
	uint8_t updated;
	int8_t TH;
	int8_t TL;

public:
	DS18B20(Precision precision);
	float getTemp(){updated = false; return temp;}
	void update();
	uint8_t isUpdated(){return updated;}
	void setPrecision(Precision precision);
	// void setTH(int8_t TH);
	// void setTL(int8_t TL);

private:
	uint8_t start();
	void skipROM();
	void convert();
	uint16_t readTemp();
	uint8_t readByte();
	void writeByte(uint8_t data);

};

#endif