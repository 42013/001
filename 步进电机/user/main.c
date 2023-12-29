#include "inmotion.h" 


uint8_t RxData = 0;
char received_data[256];
int length = 0;
int i=0,j=1;
int Flag =-1;
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
	serial_Init();
	JDQ_Init();
	en_Init();	
	while(1)
	{
//	if(Flag==-1)
//	{
//	RcLc0();
//	}	
//	if(serial_GetRxFlag()==1)
//	{
//		Flag=1;
//		RxData=serial_GetRxFlag();
//		RxData=USART_ReceiveData(USART1);           
//	}	
//	if(RxData==0x01){
//	U1coordinate('F');
//	Flag=2;
//	}
//	if(Flag==2)
//	{
//	RoLo();
//	}	
//	if(RxData==0x02){
//	//Rphase(2);
//	Lphase(2);
//	}
//	if(RxData==0x03){
//	//Rphase(-1);
//	Lphase(-1);	
//	}

	
	
	
	if(Flag ==-1){
	RcLc0();	
	}
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

