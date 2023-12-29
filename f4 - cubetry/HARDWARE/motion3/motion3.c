#include "stm32f10x.h"      // Device header
#include "inmotion.h"


int B1coordinate(char step)   //center 9
{
  if(stage==-1){
	Ras=Ra;
	Las=La;
	ste=stepconversion(step);	
    stage = 0;		
	}
   while(stage==0&&Step=='1'){
	   cubesolve5(ste,9,9,9); //9£¬9£¬9
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve3(ste,19,19,19); //19£¬19£¬19
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve1(ste,7,7,13); //7£¬7£¬13
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve4(ste,17,17,17); //17£¬17£¬17
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve2(ste,21,1,21); //21£¬1£¬21
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve6(ste,9,9,9); //9£¬9£¬9
   }
	return center;	
}


int B2coordinate(char step)		//center 10
{
  if(stage==-1){
	Ras=Ra;
	Las=La;
	ste=stepconversion(step);	
    stage = 0;		
	}
    while(stage==0&&Step=='1'){
		cubesolve6(ste,10,10,10); //10£¬10£¬10
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve4(ste,20,20,20); //20£¬20£¬20
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve1(ste,22,22,8); //22£¬22£¬8
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve5(ste,10,10,10); //10£¬10£¬10
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve2(ste,2,14,2); //2£¬14£¬2
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve3(ste,18,18,18); //18£¬18£¬18
   }
	return center;	
}

int B3coordinate(char step)		//center 11
{
   if(stage==-1){
	Ras=Ra;
	Las=La;
	ste=stepconversion(step);		
    stage = 0;		
	}
    while(stage==0&&Step=='1'){
		cubesolve3(ste,17,17,17); //17£¬17£¬17
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve5(ste,11,11,11); //11£¬11£¬11
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve1(ste,3,3,23); //3£¬3£¬23
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve6(ste,11,11,11); //11£¬11£¬11
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve2(ste,15,5,15); //15£¬5£¬15
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve4(ste,19,19,19); //19£¬19£¬19
   }
	return center;	
}


int B4coordinate(char step)		//center 12
{
   if(stage==-1){
	Ras=Ra;
	Las=La;
	ste=stepconversion(step);
    stage = 0;		
	}
    while(stage==0&&Step=='1'){
		cubesolve4(ste,18,18,18); //18£¬18£¬18
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve6(ste,12,12,12); //12£¬12£¬12
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve1(ste,16,16,4); //16£¬16£¬4
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve3(ste,20,20,20); //20£¬20£¬20
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve2(ste,6,24,6); //6£¬24£¬6
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve5(ste,12,12,12); //12£¬12£¬12
   }
	return center;	
}

