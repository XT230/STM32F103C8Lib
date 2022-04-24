#include "LCD1602.h"

LCD1602::LCD1602(GPIO_TypeDef *GPIOx, GPIOPin RS, GPIOPin RW, GPIOPin E) : 
Data(GPIOx, 8), RS(RS, GPIO_Mode_Out_PP), RW(RW, GPIO_Mode_Out_PP), E(E, GPIO_Mode_Out_PP)
{
	this->E = 0;
	row = 0;
	column = 0;
	init();
}

void LCD1602::init()
{
	while(isBusy());
	writeCmd(0x3c);		// 8位数据总线, 两行显示, 5x7
	while(isBusy());
	writeCmd(0x0F);		// 打开显示, 有光标, 光标闪烁
	while(isBusy());
	writeCmd(0x06);		// 写入后光标自动右移
	clear();			// 清屏
	while(isBusy());
	writeCmd(0x80);

}

void LCD1602::clear()
{
	uint8_t count = 0;
	while(isBusy())
	{
		count++;
		if(count > 200)return;
	}
	writeCmd(0x01);
}

uint8_t LCD1602::charAt(uint8_t row, uint8_t column)
{
	setPos(row, column);
	uint8_t data = readByte();
	setPos(this->row, this->column);
	return data;
}

void LCD1602::print(const char *s)
{
	while(*s != '\0')
	{
		while(isBusy());
		writeByte(*s);
		s++;
		column++;
		if(column >= 16)
		{
			column = 0;
			row++;
			if(row >= 2)row = 0;
			setPos(row, column);
		}
	}
}

void LCD1602::setPos(uint8_t row, uint8_t column)
{
	uint8_t cmd = column;
	if(row == 0)cmd += 0x80;
	else if(row == 1)cmd += 0xC0;

	while(isBusy());
	writeCmd(cmd);
}

uint8_t LCD1602::isBusy()
{
	Data.setMode(GPIO_Mode_IN_FLOATING);
	RS = 0;			// 指向指令寄存器
	RW = 1;			// 读操作
	E = 1;			// 使能
	uint8_t data = Data;
	E = 0;

	if((data & 0x80) != 0)return true;
	else return false;
}

void LCD1602::writeCmd(uint8_t cmd)
{
	Data.setMode(GPIO_Mode_Out_PP);
	RS = 0;			// 指向指令寄存器
	RW = 0;			// 写操作
	E = 0;
	Data = cmd;
	E = 1;			// 使能
	E = 0;
}

void LCD1602::writeByte(uint8_t data)
{
	Data.setMode(GPIO_Mode_Out_PP);
	RS = 1;
	RW = 0;
	E = 0; 
	Data = data;
	// delay_ms(1);
	E = 1;
	// delay_ms(10);
	E = 0;
}

uint8_t LCD1602::readByte()
{
	Data.setMode(GPIO_Mode_IN_FLOATING);
	RS = 1;
	RW = 1;
	E = 1;
	delay_us(100);
	uint8_t data = Data;
	E = 0;
	return data;
}