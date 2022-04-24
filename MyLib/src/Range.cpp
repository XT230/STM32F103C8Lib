#include "Range.h"

Range::Range(GPIOPin trig, GPIOPin echo) : 
trig(trig, GPIO_Mode_Out_PP), echo(echo, GPIO_Mode_IPD), count(TIM3, 65535, 72)
{
	this->trig = 0;
	distance = 0;
	NVIC_InitTypeDef NVICInit;
	EXTI_InitTypeDef EXTIInit;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	GPIO_EXTILineConfig(echo / 16, echo % 16);
	EXTIInit.EXTI_Line = this->echo.pin;
	EXTIInit.EXTI_LineCmd = ENABLE;
	EXTIInit.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTIInit.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_Init(&EXTIInit);

	NVICInit.NVIC_IRQChannel = EXTIIRQn(echo);
	NVICInit.NVIC_IRQChannelPreemptionPriority = 0;
	NVICInit.NVIC_IRQChannelSubPriority = 3;
	NVICInit.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVICInit);
	
}

void Range::update()
{
	trig = 1;
	delay_us(15);
	trig = 0;
	// while(echo == RESET);
	// count.start();
	// while(echo == SET);
	// // delay_us(2000);
	// count.stop();
	// distance = uint16_t(count.getCounter() * 1.7f);
	// count.setCounter(0);
	// updated = true;
}

float Range::getDistance(uint8_t unit)
{
	updated = false;
	if(unit == UNIT_CM)return ((float)distance / 100);
	else return ((float)(distance / 1000));
}