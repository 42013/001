#include "jdq.h" 

//����� IO��ʼ��
void JDQ_Init(void)
{    	 
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //ʹ��PB�˿�ʱ��

	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_0;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
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



