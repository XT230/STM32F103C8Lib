#include "OLED.h"

/**
 * @brief 创建一个OLED实例
 * 
 * @param addressingMode 设置SSD1306的内存寻址模式
 */
OLED::OLED(uint8_t address, AddressingMode addressingMode)
{
	this->addressingMode = addressingMode;
	this->address = address;
	pPage = 0;
	pCol = 0;
	init();
}

/**
 * @brief 初始化OLED
 * 
 */
void OLED::init()
{
	I2C_BUSInit();		// 初始化I2C总线

	display(OFF);		// 关闭显示

	writeCmd(0xD5);		// 设置时钟分频和时钟频率
	writeCmd(0x80);		

	writeCmd(0xA8);		// 设置多路复用
	writeCmd(0x3F);

	writeCmd(0xD3);		// 设置显示偏移
	writeCmd(0x00);

	writeCmd(0x40);		// 设置显示起始行

	writeCmd(0xA1);		// 设置段映射

	writeCmd(0xC8);		// 设置扫描方向

	writeCmd(0xDA);		// Set Com Pins Hardware Configuration
	writeCmd(0x12);

	setContrast(0x66);	// 设置对比度

	writeCmd(0xD9);		// 设置预充电周期
	writeCmd(0xF1);

	writeCmd(0xDB);		// Set VCOMH Deselect Level
	writeCmd(0x30);

	writeCmd(0xA4);		// 设置显示方式(全亮或根据RAM显示)

	Inverse(DISABLE); 	// 取消反显

	writeCmd(0x20);		// 设置内存寻址模式
	writeCmd(addressingMode);

	clear();			// 清屏

	writeCmd(0x8D);		// set Charge Pump
	writeCmd(0x14);

	display(ON);		// 打开显示

	delay_us(100000);

}

void OLED::setPage(uint8_t start, uint8_t width)
{
	writeCmd(0x22);		// 设置页地址
	writeCmd(start);	// 页起始地址
	writeCmd(start + width - 1);		// 页结束地址
}

void OLED::setCol(uint8_t start, uint8_t width)
{
	writeCmd(0x21);		// 设置列地址
	writeCmd(start);	// 列起始地址
	writeCmd(start + width - 1);		// 列结束地址
}

void OLED::setPixel(uint8_t x, uint8_t y)
{
	uint8_t col = x;
	uint8_t page = uint8_t(y / 8);
	uint8_t offest = y % 8;

	setCol(col, 1);		// 设置列地址
	setPage(page, 1);	// 设置页地址

	writeByte(0x01 << offest);
}

void OLED::print(const char c)
{
	if(pCol >= 128)
	{
		pCol = 0;
		pPage += 2;
		if(pPage >= 8)pPage = 0;
	}
	setPage(pPage, 2);
	setCol(pCol, 8);
	for(uint8_t j = 0; j < 16; j++)
	{
		writeByte(bits[c - 0x20][j]);
	}
	pCol += 8;
	
}

void OLED::print(const char *s)
{
	uint8_t i = 0;
	while(s[i] != '\0')
	{
		print(s[i]);
		i++;
	}
}

void OLED::print(float n, int8_t precision)
{
	uint8_t nums[10];
	uint8_t lens = 0, j = 0, flag = 0;
	int16_t z = n, i = 0;
	n -= z;
	if(z < 0)
	{
		z = -z;
		print('-');
	}
	do
	{	
		nums[lens] = z % 10;
		z /= 10;
		lens++;
	} while (z != 0);
	for(i = lens - 1; i >= 0; i--)
	{
		print((char)(nums[i] + '0'));
	}
	if(precision == -1)flag = 1; 
	if(precision == -1 || precision > 6)precision = 6;
	for(i = 0; i < precision; i++)
	{
		nums[i] = n * 10;
		if(nums[i] == 0)j++;
		else j = 0;
		n *= 10;
		n -= nums[i];
	}
	if(flag)lens = 6 - j;
	else lens = precision;
	if(lens > 0)print('.');
	for(i = 0; i < lens; i++)
	{
		print((char)(nums[i] + '0'));
	}
	
}

void OLED::display(uint8_t mode)
{
	if(mode == OFF)
	{
		writeCmd(0xAE);		// 关闭显示
	}
	else if(mode == ON)
	{
		writeCmd(0xAF);
	}
}

void OLED::clear()
{
	setCol(0, 128);		// 设置列地址
	setPage(0, 8);	// 设置页地址

	for(uint8_t i = 0; i < 128; i++)
	{
		for(uint8_t j = 0; j < 8; j++)
		{
			writeByte(0x00);
		}
	}
}

void OLED::setContrast(uint8_t contrast)
{
	writeCmd(0x81);
	writeCmd(contrast);
}

void OLED::Inverse(uint8_t mode)
{
	if(mode == ENABLE)
	{
		writeCmd(0xA7);
	}
	else if(mode == DISABLE)
	{
		writeCmd(0xA6);
	}
}

void OLED::writeCmd(uint8_t cmd)
{
	I2C_Start();
	I2C_WriteByte(address << 1);
	I2C_WaitAck();
	I2C_WriteByte(0x00);
	I2C_WaitAck();
	I2C_WriteByte(cmd);
	I2C_WaitAck();
	I2C_Stop();
}

void OLED::writeByte(uint8_t data)
{
	I2C_Start();
	I2C_WriteByte(address << 1);
	I2C_WaitAck();
	I2C_WriteByte(0x40);
	I2C_WaitAck();
	I2C_WriteByte(data);
	I2C_WaitAck();
	I2C_Stop();
}