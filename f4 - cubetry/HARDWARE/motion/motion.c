#include "stm32f10x.h"      // Device header 
#include "inmotion.h" 

//U1 B L U2 R B U3 F R U4 L F 1--4
//D1 B R D2 L B D3 F L D4 R F 5--8
//B1 D L B2 R D B3 U R B4 L U 9--12
//L1 D F L2 B D L3 U B L4 F U 13--16
//F1 D R F2 L D F3 U L F4 R U 17--20
//R1 D B R2 F D R3 U F R4 B U 21--24
//��е�۹�λ,��ת���Թ�λ��ת���ж���һ����λ
//����λ���֣�180��90��0��-90��-180�����λ������ע���м�ǰ׺L��R����
char Step='0';   //�������
int Rstage = 0;  //�һ�е��״̬��ȡ
int Lstage = 0;  //���е��״̬��ȡ
int stage = -1;	 //�ж��Ƿ����ת��״̬
int center = 1;  //�ж�����ϵ
int Las = 0;     //ת�������ж�ָ��
int Ras = 0;     //ת�������ж�ָ��
char ste;

//���צ���ƣ���ʱ100ms�г����꣬�����ٶȹ�����
void LcRo(void){
	close_left();	
	open_right();
	Delay_ms(100);
	flag = 0;
}

void RcLo(void){
	close_right();	
	open_left();
	Delay_ms(100);
	flag = 0;
} 

void RcLc(void){
	close_right();	
	close_left();
	Delay_ms(100);
	flag = 0;	
}

void RcLc0(void){
	close_right();	
	close_left();
	flag = 0;	
}

void RoLo(void){
	open_right();	
	open_left();
	Delay_ms(100);
	flag = 0;
}

void RoLo0(void){
	open_right();	
	Delay_ms(100);
	open_left();
	flag = 0;	
}


//����Ϊ������е��ת��Ӹ�λ
void LRoute1(void){
	LcRo();
	Lphase(1);
	RcLo();
	Lphase(-1);
	RcLc();
}

void LRoute2(void){
	LcRo();
	Lphase(2);
	RcLc();
}

void LRoute3(void){
	LcRo();
	Lphase(-1);
	RcLo();
	Lphase(1);
	RcLc();
}

void RRoute1(void){
	RcLo();
	Rphase(1);
	LcRo();
	Rphase(-1);
	RcLc();
}

void RRoute2(void){
	RcLo();
	Rphase(2);
	RcLc();
}

void RRoute3(void){
	RcLo();
	Rphase(-1);
	LcRo();
	Rphase(1);
	RcLc();
}

//����Ϊ������е��ת���޸�λ
void Lrouter1(void){
	LcRo();
	Lphase(1);
	RcLc();
}

void Lrouter3(void){
	LcRo();
	Lphase(-1);
	RcLc();
}

void Rrouter1(void){
	RcLo();
	Rphase(1);
	RcLc();
}

void Rrouter3(void){
	RcLo();
	Rphase(-1);
	RcLc();
}
//ת�溯��
void Lturn1(void){
	Lphase(1);
	RcLc();
}

void Lturn2(void){
	Lphase(2);
	RcLc();
}

void Lturn3(void){
	Lphase(-1);
	RcLc();
}

void Rturn1(void){
	Rphase(1);
	RcLc();
}

void Rturn2(void){
	Rphase(2); 
	RcLc();
}

void Rturn3(void){
	Rphase(-1);
	RcLc();
}

/*ת���λ���ҽ������е�ۻ��һ�е��Ϊ90��ʱ������һ��ת����Ҫʱ����*/
//�һ�е��ת���λ
void RHoming(void){
	LcRo();
	Rphase(-1);
	RcLc();
}

//���е��ת���λ
void LHoming(void){
	RcLo();
	Lphase(-1);
	RcLc();
}

//����ϵ����ִ��
void invokecenter(int CENTER,char steps)
{
	if(CENTER==1){
	U1coordinate(steps);
	}
	if(CENTER==2){
	U2coordinate(steps);
	}
	if(CENTER==3){
	U3coordinate(steps);
	}
	if(CENTER==4){
	U4coordinate(steps);
	}
	if(CENTER==5){
	D1coordinate(steps);
	}
	if(CENTER==6){
	D2coordinate(steps);
	}
	if(CENTER==7){
	D3coordinate(steps);
	}
	if(CENTER==8){
	D4coordinate(steps);
	}
	if(CENTER==9){
	B1coordinate(steps);
	}
	if(CENTER==10){
	B2coordinate(steps);
	}
	if(CENTER==11){
	B3coordinate(steps);
	}
	if(CENTER==12){
	B4coordinate(steps);
	}
	if(CENTER==13){
	L1coordinate(steps);
	}
	if(CENTER==14){
	L2coordinate(steps);
	}
	if(CENTER==15){
	L3coordinate(steps);
	}
	if(CENTER==16){
	L4coordinate(steps);
	}
	if(CENTER==17){
	F1coordinate(steps);
	}
	if(CENTER==18){
	F2coordinate(steps);
	}
	if(CENTER==19){
	F3coordinate(steps);
	}
	if(CENTER==20){
	F4coordinate(steps);
	}
	if(CENTER==21){
	R1coordinate(steps);
	}
	if(CENTER==22){
	R2coordinate(steps);
	}
	if(CENTER==23){
	R3coordinate(steps);
	}
	if(CENTER==24){
	R4coordinate(steps);
	}
}



//����ת��
char stepconversion(char step){
	char st;
	if(step=='U'||step=='u'||step=='Q'){
		Step='1';
		if(step=='U'){
		st ='1';
		}else if(step=='u'){
		st ='2';
		}else{
		st ='3';
		}
	}
	if(step=='D'||step=='d'||step=='W'){
		Step='2';
		if(step=='D'){
		st ='1';
		}else if(step=='d'){
		st ='2';
		}else{
		st ='3';
		}
	}
	if(step=='B'||step=='b'||step=='E'){
		Step='3';
		if(step=='B'){
		st ='1';
		}else if(step=='b'){
		st ='2';
		}else{
		st ='3';
		}
	}
	if(step=='L'||step=='l'||step=='A'){
		Step='4';
		if(step=='L'){
		st ='1';
		}else if(step=='l'){
		st ='2';
		}else{
		st ='3';
		}
	}
	if(step=='F'||step=='f'||step=='S'){
		Step='5';
		if(step=='F'){
		st ='1';
		}else if(step=='f'){
		st ='2';
		}else{
		st ='3';
		}
	}
	if(step=='R'||step=='r'||step=='Z'){
		Step='6';
		if(step=='R'){
		st ='1';
		}else if(step=='r'){
		st ='2';
		}else{
		st ='3';
		}
	}
	return st;
}


//cubesolvelϵ��ʵ��ת������
void cubesolve1(char steps,int center1,int center2,int center3){
	if (Ras%2==0)
	  {
		  if(Las%2==0){
			LRoute1();
			if(steps=='1') 
			{ 
			Rturn3();
			}else if(steps=='2'){
			Rturn2();
			}else if(steps=='3'){
			Rturn1();
			}
			center = center1;
			stage = 1;	
		  }else{
		  Lrouter1();
		  if(steps=='1') 
			{ 
			Rturn3();
			}else if(steps=='2'){
			Rturn2();
			}else if(steps=='3'){
			Rturn1();
			}
		  center = center2;
          stage = 1;			  
		  }
	  }else {
		  if(Las%2==0){
			Rrouter3();
			if(steps=='1') 
			{ 
			Lturn3();
			}else if(steps=='2'){
			Lturn2();
			}else if(steps=='3'){
			Lturn1();
			} 
			center = center3;
			stage = 1;	
			}
	  }
}

void cubesolve2(char steps,int center1,int center2,int center3){
	while(stage ==0){
	if (Ras%2==0)
	  {
		  if(Las%2==0){
			RRoute1();
			if(steps=='1') 
			{ 	
			Lturn3();	
			}else if(steps=='2'){
			Lturn2();	
			}else if(steps=='3'){
			Lturn1();	
			}
			center = center1;
			stage = 1;	
		  }else{
		  Lrouter3();
		  if(steps=='1') 
			{ 
			Rturn3();
			}else if(steps=='2'){
			Rturn2();
			}else if(steps=='3'){
			Rturn1();
			}
		  center = center2;
          stage = 1;			  
		  }
	  }else {
		  if(Las%2==0){
			Rrouter1();
			if(steps=='1') 
			{ 
			Lturn3();
			}else if(steps=='2'){
			Lturn2();
			}else if(steps=='3'){
			Lturn1();
			} 
			center = center3;
			stage = 1;	
			}
	  }
  }
}

void cubesolve3(char steps,int center1,int center2,int center3){
	if (Ras%2==0)
	  {
		  if(Las%2==0){
			LRoute2();
			if(steps=='1') 
			{ 
			Rturn3();
			}else if(steps=='2'){
			Rturn2();
			}else if(steps=='3'){
			Rturn1();
			}
			center = center1;
			stage = 1;	
		  }else{
		  LRoute2();
		  LHoming();  	  	  
		  if(steps=='1') 
			{ 
			Rturn3();
			}else if(steps=='2'){
			Rturn2();
			}else if(steps=='3'){
			Rturn1();
			}
		  center = center2;
          stage = 1;			  
		  }
	  }else {
		  if(Las%2==0){
			LRoute2();
			if(steps=='1') 
			{ 
			Rturn3();
			}else if(steps=='2'){
			Rturn2();
			}else if(steps=='3'){
			Rturn1();
			} 
			center = center3;
			stage = 1;	
			}
	  }
}

void cubesolve4(char steps,int center1,int center2,int center3){
	if (Ras%2==0)
	  {
		  if(Las%2==0){
			RRoute2();
			if(steps=='1') 
			{ 
			Lturn3();
			}else if(steps=='2'){
			Lturn2();
			}else if(steps=='3'){
			Lturn1();
			}
			center = center1;
			stage = 1;	
		  }else{
		  RRoute2();
		  if(steps=='1') 
			{ 
			Lturn3();
			}else if(steps=='2'){
			Lturn2();
			}else if(steps=='3'){
			Lturn1();	
			}
		  center = center2;
          stage = 1;			  
		  }
	  }else {
		  if(Las%2==0){
			RRoute2();
			RHoming();  
			if(steps=='1') 
			{ 
			Lturn3();
			}else if(steps=='2'){
			Lturn2();
			}else if(steps=='3'){
			Lturn1();
			} 
			center = center3;
			stage = 1;	
			}
	  }
}

void cubesolve5(char steps,int center1,int center2,int center3){
	if (Ras%2==0)
	  {
		  if(Las%2==0){
			if(steps=='1') 
			{ 
			Rturn3();
			}else if(steps=='2'){
			Rturn2();
			}else if(steps=='3'){
			Rturn1();
			}
			center = center1;
			stage = 1;	
		  }else{
		  if(steps=='1') 
			{ 
			Rturn3();
			}else if(steps=='2'){
			Rturn2();
			}else if(steps=='3'){
			Rturn1();	
			}
		  center = center2;
          stage = 1;			  
		  }
	  }else {
		  if(Las%2==0){
			if(steps=='1') 
			{ 
			Rturn3();
			}else if(steps=='2'){
			Rturn2();
			}else if(steps=='3'){
			Rturn1();
			} 
			center = center3;
			stage = 1;	
			}
	  }
}

void cubesolve6(char steps,int center1,int center2,int center3){
	if (Ras%2==0)
	  {
		  if(Las%2==0){
			if(steps=='1') 
			{ 
			Lturn3();
			}else if(steps=='2'){
			Lturn2();
			}else if(steps=='3'){
			Lturn1();
			}
			center = center1;
			stage = 1;	
		  }else{
		  if(steps=='1') 
			{ 
			Lturn3();
			}else if(steps=='2'){
			Lturn2();
			}else if(steps=='3'){
			Rturn1();	
			}
		  center = center2;
          stage = 1;			  
		  }
	  }else {
		  if(Las%2==0){
			if(steps=='1') 
			{ 
			Lturn3();
			}else if(steps=='2'){
			Lturn2();
			}else if(steps=='3'){
			Lturn1();
			} 
			center = center3;
			stage = 1;	
			}
	  }
}


int U1coordinate(char step)//center1
{
    if(stage==-1){
	Ras=Ra;
	Las=La;
	ste=stepconversion(step);	
    stage = 0;		
	}	
   while(stage==0&&Step=='1'){
	  cubesolve1(ste,9,9,14); //9��9��14
   }
   
   while(stage==0&&Step=='2'){
	   cubesolve2(ste,24,19,24); //24,19,24
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve3(ste,7,7,7); //7,7,7
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve4(ste,5,5,5); //5,5,5
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve5(ste,1,1,1); //1,1,1
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve6(ste,1,1,1); //1,1,1
   }
	return center;	
}


int U2coordinate(char step)//center2
{
  if(stage==-1){
	Ras=Ra;
	Las=La;
	ste=stepconversion(step);	
    stage = 0;		
	}	
   while(stage==0&&Step=='1'){
	   cubesolve1(ste,21,21,10); //21��21��10
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve2(ste,20,15,20); //20��15��20
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve4(ste,8,8,8); //8��8��8
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve5(ste,2,2,2); //2��2��2
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve6(ste,2,2,2); //2��2��2
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve3(ste,6,6,6); //2��2��2
   }
	return center;	
}

int U3coordinate(char step)//center3
{
   if(stage==-1){
	Ras=Ra;
	Las=La;
	ste=stepconversion(step);	
    stage = 0;		
	}	
   while(stage==0&&Step=='1'){
	    cubesolve1(ste,17,17,22); //17��17��22
   }
   
   
   while(stage==0&&Step=='2'){
	    cubesolve2(ste,16,11,16); //16��11��16
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve5(ste,3,3,3); //3��3��3
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve6(ste,3,3,3); //3��3��3
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve3(ste,5,5,5); //5��5��5
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve4(ste,7,7,7); //7��7��7
   }
	return center;	
}


int U4coordinate(char step)//center4
{
   if(stage==-1){
	Ras=Ra;
	Las=La;
	ste=stepconversion(step);		
    stage = 0;		
	}	
   while(stage==0&&Step=='1'){
	   cubesolve1(ste,13,13,18); //13��13��18
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve2(ste,12,23,12); //12��23��12
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve6(ste,4,4,4); //4��4��4
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve3(ste,8,8,8); //8��8��8
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve4(ste,6,6,6); //6��6��6
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve5(ste,4,4,4); //4, 4, 4
   }
	return center;	
}

