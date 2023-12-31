#include "stm32f10x.h"                  // Device header
#include "stdio.h"
#include <stdarg.h>

uint8_t serial_RxData;
uint8_t serial_RxFlag;

void serial_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	 
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate=9600;
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode=USART_Mode_Tx|USART_Mode_Rx;
	USART_InitStructure.USART_Parity=USART_Parity_No;
	USART_InitStructure.USART_StopBits=USART_StopBits_1;
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
	USART_Init(USART1,&USART_InitStructure);
	
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStructure);
	
	USART_Cmd(USART1,ENABLE);
}

void serial_Sendbyte(uint8_t Byte)
{
	USART_SendData(USART1,Byte);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
} 

void serial_Sendarray(uint8_t *array,uint16_t lengh)
{
	uint16_t i;
	for(i=0;i<=lengh;i++)
	{
	serial_Sendbyte(array[i]);
	}
}

void serial_Sendstring(char *string)
{
	uint8_t i;
	for(i=0;string[i]!=0;i++)
	{
	serial_Sendbyte(string[i]);
	}
}

uint32_t serial_pow(uint32_t X,uint32_t Y)
{
	uint32_t Result=1;
	while(Y--)
	{
		Result*=X;
	}	
	return Result;
}

void serial_Sendnumber(uint32_t number,uint16_t lengh)
{
	uint8_t i;
	for(i=0;i<=lengh;i++)
	{
	serial_Sendbyte(number/serial_pow(10,lengh-i-1)%10+'0');
	}
}

int fputc(int ch,FILE *f)
{
	serial_Sendbyte(ch);
	return ch;
}//printf移植

/*{
            RxData=USART_ReceiveData(USART1);           
			serial_Sendbyte(RxData);
        }*/
uint8_t serial_GetRxFlag(void)
{
	if(serial_RxFlag==1)
	{
	serial_RxFlag=0;
		return 1;
	}
	return 0;
}
void Serial_Printf(char *format, ...)
{
	char String[100];
	va_list arg;
	va_start(arg, format);
	vsprintf(String, format, arg);
	va_end(arg);
	serial_Sendstring(String);
}



//if(USART_GetFlagStatus(USART1,USART_FLAG_RXNE)==SET)//0 循环等待 1 可以接收数据
//			{ 
//		{
//            RxData=USART_ReceiveData(USART1);           
//			serial_Sendbyte(RxData);
//        }	
////        for(j=0;str[j]!=0;j++)
////		{
////			str[j]=USART_ReceiveData(USART1);
////		serial_Sendbyte(str[j]);
////		}
//	}
uint8_t serial_GetRxData(void)
{
	return serial_RxData;
}
void USART1_IRQHandler(void)
{
if(USART_GetFlagStatus(USART1,USART_IT_RXNE)==SET)
{
	serial_RxData=USART_ReceiveData(USART1);
	serial_RxFlag=1;
	USART_ClearITPendingBit(USART1, USART_IT_RXNE);
}
}//中断
