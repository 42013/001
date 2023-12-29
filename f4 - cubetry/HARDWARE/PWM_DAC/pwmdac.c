#include "pwmdac.h"
#include "delay.h"
#include "usart.h"
#include "sys.h"
int Ra = 0;      // 右机械臂奇偶校验
int La = 0;      // 左机械臂奇偶校验
int choice = 0; //机械臂选择
int Lslip = 0;  //左机械臂计程
int Rslip = 0;  //右机械臂计程
int Ncounter = 0; //总脉冲计数调速
int Ncountertarget = 0;//总脉冲计数目标值
int Lcounter = 0; //左脉冲计数记录相位
int Rcounter = 0; //右脉冲计数记录相位
int flag = 0;	//获取状态标志位

//A0右使能
//A2左使能
//A1右方向
//A3左方向

void bujin_Init(void){
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//使能GPIOF时钟

	//GPIOB8初始化设置
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIO

	GPIO_ResetBits(GPIOA,GPIO_Pin_0);
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);
	GPIO_ResetBits(GPIOA,GPIO_Pin_3);
}

void counter_Init(void)
{		 					 
	//此部分需手动修改IO口设置
	
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);  	//TIM3时钟使能    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); 	//使能PORTF时钟	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource6,GPIO_AF_TIM3); //复用为定时器3
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource7,GPIO_AF_TIM3);
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource0,GPIO_AF_TIM3);//复用为定时器3
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource1,GPIO_AF_TIM3);//复用为定时器3

	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;      
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //上拉
	GPIO_Init(GPIOA,&GPIO_InitStructure);              //初始化PA
	   

	TIM_TimeBaseStructure.TIM_Prescaler=TIM_PRESCALER;  //定时器分频
	TIM_TimeBaseStructure.TIM_Period=TIM_PERIOD;   //自动重装载值	
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);//初始化定时器3
	
	//初始化TIM3 Channel1 PWM模式	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; //输出极性:TIM输出比较极性低
	
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);
	
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);  //使能TIM3在CCR1上的预装载寄存器
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
 
 	TIM_ARRPreloadConfig(TIM3,ENABLE);//ARPE使能 
	
	TIM_Cmd(TIM3, ENABLE);  //使能TIM3					  
}



void TIM7_Int_Init(u16 aRr,u16 pSc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure; 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7,ENABLE);  ///使能TIM7时钟  
	TIM_TimeBaseInitStructure.TIM_Period = aRr; 	//自动重装载值
	TIM_TimeBaseInitStructure.TIM_Prescaler=pSc;  //定时器分频
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	TIM_TimeBaseInit(TIM7,&TIM_TimeBaseInitStructure);//初始化TIM7
	TIM_ITConfig(TIM7,TIM_IT_Update,ENABLE); //允许定时器7更新中断
	TIM_Cmd(TIM7,ENABLE); //使能定时器7
}

void close_timer7(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=TIM7_IRQn; //定时器7中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; //抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03; //子优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd=DISABLE;
	NVIC_Init(&NVIC_InitStructure);
}
//使能
void open_timer7(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;	
	NVIC_InitStructure.NVIC_IRQChannel=TIM7_IRQn; //定时器7中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; //抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03; //子优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}


//左右机械臂调速
void  Rspeed(uint16_t compare)
{
	TIM_SetCompare1(TIM3,compare);
}

void  Lspeed(uint16_t compare)
{
	TIM_SetCompare2(TIM3,compare);
}



//参数一使能     参数二方向		变量choice为2时左机械臂，为1时右机械臂
void Rbujincontral(int en, int motor_dir){
	if(en==1){
		choice=	1;	
		Rbujin_en = 1;
		TIM_Cmd(TIM3, ENABLE);//定时器使能
        TIM_Cmd(TIM7, ENABLE);//定时器使能			
	}else{
		choice=	2;
		Rcounter = 0;
		Rbujin_en = 0;
		TIM_Cmd(TIM3, DISABLE);//定时器关闭使能
		TIM_Cmd(TIM7, DISABLE);//定时器关闭使能	
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
		TIM_Cmd(TIM3, ENABLE);//定时器使能
        TIM_Cmd(TIM7, ENABLE);//定时器使能			
	}else{
		choice=	1;	
		Lcounter = 0;
		Lbujin_en = 0;
		TIM_Cmd(TIM3, DISABLE);//定时器关闭使能	
		TIM_Cmd(TIM7, DISABLE);//定时器关闭使能	
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


//预设目标值调速
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


//获取奇偶相位
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
		if(Rcounter == 100)//678拨上100为90度
		{
			Rcounter=0;
			++Rslip;
		}	
		}else{
		if(Rcounter == 100)//678拨上100为90度
		{
			Rcounter=0;
			--Rslip;
		}	
		}
	}
		if (choice==2){
		Lcounter += 1;
		if(!Lbujin_dir){
		if(Lcounter == 100)//678拨上100为90度
		{
			Lcounter=0;
			++Lslip;
		}	
		}else{
		if(Lcounter == 100)//678拨上100为90度
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


