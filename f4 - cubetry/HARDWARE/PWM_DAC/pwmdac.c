#include "pwmdac.h"
#include "delay.h"
#include "usart.h"
#include "sys.h"
int Ra = 0;      // �һ�е����żУ��
int La = 0;      // ���е����żУ��
int choice = 0; //��е��ѡ��
int Lslip = 0;  //���е�ۼƳ�
int Rslip = 0;  //�һ�е�ۼƳ�
int Ncounter = 0; //�������������
int Ncountertarget = 0;//���������Ŀ��ֵ
int Lcounter = 0; //�����������¼��λ
int Rcounter = 0; //�����������¼��λ
int flag = 0;	//��ȡ״̬��־λ

//A0��ʹ��
//A2��ʹ��
//A1�ҷ���
//A3����

void bujin_Init(void){
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//ʹ��GPIOFʱ��

	//GPIOB8��ʼ������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIO

	GPIO_ResetBits(GPIOA,GPIO_Pin_0);
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);
	GPIO_ResetBits(GPIOA,GPIO_Pin_3);
}

void counter_Init(void)
{		 					 
	//�˲������ֶ��޸�IO������
	
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);  	//TIM3ʱ��ʹ��    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); 	//ʹ��PORTFʱ��	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource6,GPIO_AF_TIM3); //����Ϊ��ʱ��3
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource7,GPIO_AF_TIM3);
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource0,GPIO_AF_TIM3);//����Ϊ��ʱ��3
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource1,GPIO_AF_TIM3);//����Ϊ��ʱ��3

	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;      
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
	GPIO_Init(GPIOA,&GPIO_InitStructure);              //��ʼ��PA
	   

	TIM_TimeBaseStructure.TIM_Prescaler=TIM_PRESCALER;  //��ʱ����Ƶ
	TIM_TimeBaseStructure.TIM_Period=TIM_PERIOD;   //�Զ���װ��ֵ	
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);//��ʼ����ʱ��3
	
	//��ʼ��TIM3 Channel1 PWMģʽ	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; //�������:TIM����Ƚϼ��Ե�
	
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 4OC1
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);
	
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);  //ʹ��TIM3��CCR1�ϵ�Ԥװ�ؼĴ���
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
 
 	TIM_ARRPreloadConfig(TIM3,ENABLE);//ARPEʹ�� 
	
	TIM_Cmd(TIM3, ENABLE);  //ʹ��TIM3					  
}



void TIM7_Int_Init(u16 aRr,u16 pSc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure; 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7,ENABLE);  ///ʹ��TIM7ʱ��  
	TIM_TimeBaseInitStructure.TIM_Period = aRr; 	//�Զ���װ��ֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler=pSc;  //��ʱ����Ƶ
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	TIM_TimeBaseInit(TIM7,&TIM_TimeBaseInitStructure);//��ʼ��TIM7
	TIM_ITConfig(TIM7,TIM_IT_Update,ENABLE); //����ʱ��7�����ж�
	TIM_Cmd(TIM7,ENABLE); //ʹ�ܶ�ʱ��7
}

void close_timer7(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=TIM7_IRQn; //��ʱ��7�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; //��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03; //�����ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd=DISABLE;
	NVIC_Init(&NVIC_InitStructure);
}
//ʹ��
void open_timer7(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;	
	NVIC_InitStructure.NVIC_IRQChannel=TIM7_IRQn; //��ʱ��7�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; //��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03; //�����ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}


//���һ�е�۵���
void  Rspeed(uint16_t compare)
{
	TIM_SetCompare1(TIM3,compare);
}

void  Lspeed(uint16_t compare)
{
	TIM_SetCompare2(TIM3,compare);
}



//����һʹ��     ����������		����choiceΪ2ʱ���е�ۣ�Ϊ1ʱ�һ�е��
void Rbujincontral(int en, int motor_dir){
	if(en==1){
		choice=	1;	
		Rbujin_en = 1;
		TIM_Cmd(TIM3, ENABLE);//��ʱ��ʹ��
        TIM_Cmd(TIM7, ENABLE);//��ʱ��ʹ��			
	}else{
		choice=	2;
		Rcounter = 0;
		Rbujin_en = 0;
		TIM_Cmd(TIM3, DISABLE);//��ʱ���ر�ʹ��
		TIM_Cmd(TIM7, DISABLE);//��ʱ���ر�ʹ��	
	}
	if(motor_dir)
	{
		Rbujin_dir =0;	
		Rspeed(30);//40	
	}
	else
	{
		Rbujin_dir = 1;
		Rspeed(30);
	}
}

void Lbujincontral(int en, int motor_dir){
	if(en==1){	
		choice=	2;	
		Lbujin_en = 1;
		TIM_Cmd(TIM3, ENABLE);//��ʱ��ʹ��
        TIM_Cmd(TIM7, ENABLE);//��ʱ��ʹ��			
	}else{
		choice=	1;	
		Lcounter = 0;
		Lbujin_en = 0;
		TIM_Cmd(TIM3, DISABLE);//��ʱ���ر�ʹ��	
		TIM_Cmd(TIM7, DISABLE);//��ʱ���ر�ʹ��	
	}
	if(motor_dir)
	{
		Lbujin_dir =0;	
		Lspeed(30);//40	
	}
	else
	{
		Lbujin_dir = 1;
		Lspeed(30);//40
	}
}


//Ԥ��Ŀ��ֵ����
void Rpulse_get(int x)
{
	if(x==1||x==-1)
	{
	Ncountertarget=100;
	}
	if(x==2)
	{	
	Ncountertarget=200;
	}
	flag=1;
}

void Lpulse_get(int y)
{
	if(y==1||y==-1)
	{
	Ncountertarget=100;
	}
	if(y==2)
	{	
	Ncountertarget=200;
	}
	flag=1;
}


//��ȡ��ż��λ
void Rphase(int aspect){
	if(flag==0){
	Ra += aspect;
	Rpulse_get(aspect);
	}
	if(aspect==1&&flag==1){
		while(Rslip!=1){
		Rbujincontral(1,1); 
		}
		Rbujincontral(0,0);
		Rslip = 0;	
		flag=2;	
	}
	if(aspect==2&&flag==1){
		while(Rslip!=2){
		Rbujincontral(1,1); 
		}
		Rbujincontral(0,0);
		Rslip = 0;	
		flag=2;		
	}
	if(aspect==-1&&flag==1){
		while(Rslip!=-1){
		Rbujincontral(1,0); 
		}
		Rbujincontral(0,0);
		Rslip = 0;	
		flag=2;		
	}
}



void Lphase(int aspect){
	if(aspect!=0&&flag==0){
	La += aspect;	
	Lpulse_get(aspect);
	}
	if(aspect==1&&flag==1){
		while(Lslip!=1){
		Lbujincontral(1,1); 
		}
		Lbujincontral(0,0);
		Lslip = 0;
		flag=2;
	}
	if(aspect==2&&flag==1){
		while(Lslip!=2){
		Lbujincontral(1,1); 
		}
		Lbujincontral(0,0);
		Lslip = 0;
		flag=2;
	}
	if(aspect==-1&&flag==1){
		while(Lslip!=-1)
		{
		Lbujincontral(1,0); 
		}
		Lbujincontral(0,0);
		Lslip = 0;
		flag=2;
	}
	
}

void reposition(void){

	if(La%2!=0){
	Lphase(1);
	}
	if(Ra%2!=0){
	Rphase(1);
	}
}




void TIM7_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM7, TIM_IT_Update) == SET)
	{
       if (choice==1){
		Rcounter += 1;
		if(!Rbujin_dir){
		if(Rcounter == 100)//678����100Ϊ90��
		{
			Rcounter=0;
			++Rslip;
		}	
		}else{
		if(Rcounter == 100)//678����100Ϊ90��
		{
			Rcounter=0;
			--Rslip;
		}	
		}
	}
		if (choice==2){
		Lcounter += 1;
		if(!Lbujin_dir){
		if(Lcounter == 100)//678����100Ϊ90��
		{
			Lcounter=0;
			++Lslip;
		}	
		}else{
		if(Lcounter == 100)//678����100Ϊ90��
		{
			Lcounter=0;
			--Lslip;
		}	
		}
	}
		Ncounter+=1;
	    if(Ncounter<Ncountertarget){
		   if(Ncountertarget==100){
		   if(Ncounter<40){
			delay_us(950-Ncounter*18.75); 
			}else if(Ncounter>=40&&Ncounter<=60){
			delay_us(200);
			}else if(60<Ncounter&&Ncounter<100){
			delay_us(200+(Ncounter-60)*18.75); 
			}
		   } 
		   if(Ncountertarget==200){
			 if(Ncounter<80){
			delay_us((int)(122.5-Ncounter*0.9)); 
			}else if(Ncounter>=80&&Ncounter<=120){
			delay_us(50);
			}else if(120<Ncounter&&Ncounter<200){
			delay_us((int)(50+(Ncounter-120)*0.9)); 
			}
		   }
		}else{
		 Ncounter = 0;
		 Ncountertarget = 0;		
		}
	}
	TIM_ClearITPendingBit(TIM7, TIM_IT_Update);
	TIM_ClearFlag(TIM7, TIM_FLAG_Update);
}


