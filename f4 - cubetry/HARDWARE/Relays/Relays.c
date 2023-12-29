#include "Relays.h"
#include "stm32f4xx.h"                  // Device header

void Electromagnets(void){
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);//ʹ��GPIOFʱ��

	//GPIOB8��ʼ������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;//LED0��LED1��ӦIO��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIO

	GPIO_ResetBits(GPIOB,GPIO_Pin_0);//GPIOB8,B9���øߣ�����
	GPIO_ResetBits(GPIOB,GPIO_Pin_1);//GPIOB8,B9���øߣ�����
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
