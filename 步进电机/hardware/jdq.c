#include "jdq.h" 

//电磁铁 IO初始化
void JDQ_Init(void)
{    	 
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //使能PB端口时钟

	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_0;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);	
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



