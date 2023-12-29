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
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);    //��ʼ����ʱ����
	uart_init(9600);	//��ʼ�����ڲ�����Ϊ9600
	bujin_Init();               //������ʼ��
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
            // ��������ֱ��֡β
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
				
            // ������յ������ݰ�	
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




