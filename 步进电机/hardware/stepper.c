#include "stm32f10x.h"      // Device header
#include "stepper.h" 
#include "math.h"
#include "Delay.h" 
#include "sys.h"


int Ra = 0;      // 右机械臂奇偶校验
int La = 0;      // 左机械臂奇偶校验
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
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_Initstructure;
	
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Initstructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;
	GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_Initstructure);
}

void en_Init(void){
	Rbujin_en = 0;	//使能
	Lbujin_en = 0;	//使能
	bujin_Init();
	counter1_Init();	
	counter2_Init();	
}

void counter1_Init(void)	//脉冲计数中断pwm调速口右A6
{
	//********************************gpio
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	//pwm信号线
	GPIO_InitTypeDef GPIO_Initstructure;
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Initstructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;
	GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_Initstructure);
	TIM_InternalClockConfig(TIM3);
	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = TIM_PERIOD;   
	TIM_TimeBaseInitStructure.TIM_Prescaler = TIM_PRESCALER;//910us进一次中断  
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);
	//*******************************定时器配置输出比较
	TIM_OCInitTypeDef  TIM_OCInitStruct;
	TIM_OCStructInit(&TIM_OCInitStruct);
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCNPolarity_High;
	TIM_OCInitStruct.TIM_OutputState =  TIM_OutputState_Enable;
	TIM_OCInitStruct.TIM_Pulse = 0;     //CCR
	TIM_OC1Init(TIM3,&TIM_OCInitStruct);
	TIM_OC2Init(TIM3,&TIM_OCInitStruct);
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);  //使能TIM3在CCR2上的预装载寄存器
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);  //使能TIM3在CCR2上的预装载寄存器
	
	//中断优先级分组
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStructure);

	TIM_ClearFlag(TIM3, TIM_FLAG_Update);
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);//定时器中断使能口
	
	TIM_Cmd(TIM3, DISABLE);//定时器使能
}

void counter2_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	
	GPIO_InitTypeDef GPIO_Initstructure;
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Initstructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;
	GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_Initstructure);
	TIM_InternalClockConfig(TIM4);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = TIM_PERIOD;
	TIM_TimeBaseInitStructure.TIM_Prescaler = TIM_PRESCALER;
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseInitStructure);
	
	TIM_OCInitTypeDef  TIM_OCInitStruct;
	TIM_OCStructInit(&TIM_OCInitStruct);
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCNPolarity_High;
	TIM_OCInitStruct.TIM_OutputState =  TIM_OutputState_Enable;
	TIM_OCInitStruct.TIM_Pulse = 0;     //CCR
	TIM_OC1Init(TIM4,&TIM_OCInitStruct);
	TIM_OC2Init(TIM4,&TIM_OCInitStruct);
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);  //使能TIM4在CCR1上的预装载寄存器
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);  //使能TIM4在CCR2上的预装载寄存器
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_ClearFlag(TIM4, TIM_FLAG_Update);
	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);//定时器中断使能口
	
    TIM_Cmd(TIM4,DISABLE);     
}

//左右机械臂调速
//A6
void  Rspeed(uint16_t compare)
{
	TIM_SetCompare1(TIM3,compare);
}
//B7
void  Lspeed(uint16_t compare)
{
	TIM_SetCompare2(TIM4,compare);
}



//参数一使能     参数二方向
void Rbujincontral(int en, int motor_dir){
	if(en==1){
		Rbujin_en = 1;
		TIM_Cmd(TIM3, ENABLE);//定时器使能	
	}else{
		Rbujin_en = 0;
		Rcounter = 0;
		TIM_Cmd(TIM3, DISABLE);//定时器关闭使能	
	}
	if(motor_dir==1)
	{
		Rbujin_dir =0;	
		Rspeed(200);//40	
	}
	else
	{
		Rbujin_dir = 1;
		Rspeed(200);
	}
}

void Lbujincontral(int en, int motor_dir){
	if(en==1){	
		Lbujin_en = 1;
		TIM_Cmd(TIM4, ENABLE);//定时器使能	
	}else{
		Lbujin_en = 0;
		Lcounter = 0;
		TIM_Cmd(TIM4, DISABLE);//定时器关闭使能	
	}
	if(motor_dir==1)
	{
		Lbujin_dir =0;	
		Lspeed(200);//40	
	}
	else
	{
		Lbujin_dir = 1;
		Lspeed(200);//40
	}
}

//获取奇偶相位
void Rphase(int aspect){
	if(aspect!=0&&flag==0){
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
void solidposition(void){

	if(La%2==0&&Ra%2==0){
	Lphase(1);
	}else{
	Rphase(0);
	Lphase(0);	
	}
}


//预设目标值调速
void Rpulse_get(int x)
{
	if(x==1||x==-1)
	{
	Ncountertarget=Ncountertarget1;
	}
	if(x==2)
	{	
	Ncountertarget=Ncountertarget2;
	}
	flag=1;
}

void Lpulse_get(int y)
{
	if(y==1||y==-1)
	{
	Ncountertarget=Ncountertarget1;
	}
	if(y==2)
	{	
	Ncountertarget=Ncountertarget2;
	}
	flag=1;
}
	

//中断执行以上的数值转换
void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update) != RESET)
	{
		Rcounter += 1;
		if(!Rbujin_dir){
		if(Rcounter == Ncountertarget1&&Ncountertarget==Ncountertarget1)//678拨上100为90度
		{
			Rcounter=0;
			Rslip=1;
		}	
		if(Rcounter == Ncountertarget2&&Ncountertarget==Ncountertarget2)//678拨上100为90度
		{
			Rcounter=0;
			Rslip=2;
		}	
		}else{
		if(Rcounter ==Ncountertarget1)//678拨上100为90度
		{
			Rcounter=0;
			Rslip=-1;
		}	
		}
		Ncounter+=1;
	    if(Ncounter<Ncountertarget){
		   if(Ncountertarget==Ncountertarget1){
			if(Ncounter<40){
			Delay_us((int)(161.5-Ncounter*1.5)); 
			}else if(Ncounter>=40&&Ncounter<=60){
			Delay_us(100);
			}else if(60<Ncounter&&Ncounter<100){
			Delay_us((int)(100+(Ncounter-60)*1.5)); 
			}
		   }else if(Ncountertarget==Ncountertarget2){
			 if(Ncounter<80){
			Delay_us((int)(122.5-Ncounter*0.9)); 
			}else if(Ncounter>=80&&Ncounter<=120){
			Delay_us(50);
			}else if(120<Ncounter&&Ncounter<200){
			Delay_us((int)(50+(Ncounter-120)*0.9)); 
			}
		   }
		   else{
			Ncounter = 0;
			Ncountertarget = 0;	
		   }
		}
	}
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
	TIM_ClearFlag(TIM3, TIM_FLAG_Update);
}

void TIM4_IRQHandler(void){
	if(TIM_GetITStatus(TIM4,TIM_IT_Update) != RESET)
	{
		Lcounter += 1;	
		if(!Lbujin_dir){
		if(Lcounter == Ncountertarget1&&Ncountertarget==Ncountertarget1)//678拨上100为90度
		{
			Lcounter=0;
			Lslip=1;
		}
		if(Lcounter == Ncountertarget2&&Ncountertarget==Ncountertarget2){
			Lcounter=0;
			Lslip=2;
		}		
		}else{
		if(Lcounter == Ncountertarget1)//678拨上100为90度
		{
			Lcounter=0;
			Lslip=-1;
		}	
		}
			Ncounter+=1;
	    if(Ncounter<Ncountertarget){
		   if(Ncountertarget==Ncountertarget1){
			if(Ncounter<40){
			Delay_us((int)(161.5-Ncounter*1.5)); 
			}else if(Ncounter>=40&&Ncounter<=60){
			Delay_us(100);
			}else if(60<Ncounter&&Ncounter<100){
			Delay_us((int)(100+(Ncounter-60)*1.5)); 
			}
		   }else if(Ncountertarget==Ncountertarget2){
			 if(Ncounter<80){
			Delay_us((int)(122.5-Ncounter*0.9)); 
			}else if(Ncounter>=80&&Ncounter<=120){
			Delay_us(50);
			}else if(120<Ncounter&&Ncounter<200){
			Delay_us((int)(50+(Ncounter-120)*0.9)); 
			}
		   }
		   else{
			Ncounter = 0;
			Ncountertarget = 0;	
		   }
		}
	}
	TIM_ClearITPendingBit(TIM4,TIM_IT_Update);
	TIM_ClearFlag(TIM4, TIM_FLAG_Update);
}
