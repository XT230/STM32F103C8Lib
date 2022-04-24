#ifndef _OLED_H_
#define _OLED_H_

#include "stm32f10x.h"
#include "I2C.h"
#include "font.h"

#define ON  1
#define OFF 0

/**
 * @brief SSD1306的寻址模式
 * 
 */
enum AddressingMode 
{
	Horizontal_Addressing_Mode = 0x00,		// 水平寻址模式
	Vertical_Addressing_Mode = 0x01,		// 垂直寻址模式
	Page_Addressing_Mode = 0x02			// 页寻址模式(RESART)
};

class OLED 
{
private:
	AddressingMode addressingMode;
	uint8_t address;
	uint8_t buffer[8][128];
	uint8_t pPage;
	uint8_t pCol;

public:
	OLED(uint8_t address, AddressingMode addressingMode = Vertical_Addressing_Mode);
	void setContrast(uint8_t contrast);
	void setPixel(uint8_t x, uint8_t y);
	void Inverse(uint8_t mode);
	void clear();
	void display(uint8_t mode);
	void print(const char *s);
	void print(float n, int8_t precision = -1);
	void print(const char c);
	void setPos(uint8_t pPage, uint8_t pCol){this->pPage = pPage; this->pCol = pCol;}

private:
	void writeByte(uint8_t data);
	void writeCmd(uint8_t cmd);
	void setPage(uint8_t start, uint8_t width);
	void setCol(uint8_t start, uint8_t width);
	void init();
};

#endif