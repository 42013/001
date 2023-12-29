#include "Relays.h"
#include "stm32f4xx.h"                  // Device header

void Electromagnets(void){
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);//使能GPIOF时钟

	//GPIOB8初始化设置
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;//LED0和LED1对应IO口
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIO

	GPIO_ResetBits(GPIOB,GPIO_Pin_0);//GPIOB8,B9设置高，灯灭
	GPIO_ResetBits(GPIOB,GPIO_Pin_1);//GPIOB8,B9设置高，灯灭
}

void open_left()
{
	LOPEN = 0;
}

void close_left()	
{
	LOPEN = 1;
}

void open_right()
{
	ROPEN = 0;
}

void close_right()	
{
	ROPEN = 1;
}
