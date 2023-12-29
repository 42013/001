#include "inmotion.h" 

uint8_t RxData = 0;
char received_data[256];
int length = 0;
int i=0,j=1;
int Flag =0;
int save = 0;

void process_received_data(const char *data, int length)
{
	if(j<length){
	if(stage==-1){
    invokecenter(center,received_data[j]);
	}
	if(stage==1){
	j+=1;	
	stage=-1;
	}
	}else{
	RoLo();	
	Flag = 1;
	}
}

int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);    //初始化延时函数
	uart_init(9600);	//初始化串口波特率为9600
	bujin_Init();               //步进初始化
	counter_Init();
	Electromagnets();
	TIM7_Int_Init(TIM7_PERIOD,TIM7_PRESCALER);
	Rbujin_en = 0;
	Lbujin_en = 0;
	while(1)
	{ 
    if(serial_GetRxFlag()==1){	
     RxData=USART_ReceiveData(USART1);
     if(Flag==2&&RxData==0x01){
	 reposition();
	 Flag = 3;	 
	 } 		
     if (RxData == 0xFF)
        {
			save =0;
			Flag = 0;
            // 接收数据直到帧尾
            do
            {   
	            RxData=USART_ReceiveData(USART1);		
                if (RxData != 0xFE&&RxData !=0xFF)
                {
					if(save==0){
                    received_data[length++] = RxData;
					//serial_Sendbyte(RxData);	
					save =1;	
					}
                }
            }while (RxData != 0xFE&&save == 0);
				
            // 处理接收到的数据包	
	}
	}else{
		if(length==received_data[0]+1&&Flag==0){
		process_received_data(received_data, length);			
		}
	}
	if(Flag==1){
		serial_Sendbyte(0x01);
        Flag = 2;		
	 }		
	}
}




