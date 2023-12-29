#include "stm32f10x.h"      // Device header
#include "inmotion.h"


int L1coordinate(char step)		//center 13
{
   if(stage==-1){
	Ras=Ra;
	Las=La;
	ste=stepconversion(step);		
    stage = 0;		
	}
   while(stage==0&&Step=='1'){
	   cubesolve5(ste,13,13,13); //13£¬13£¬13
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve3(ste,23,23,23); //23£¬23£¬23
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve6(ste,13,13,13); //13£¬13£¬13
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve1(ste,6,6,17); //6£¬6£¬17
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve4(ste,21,21,21); //21£¬21£¬21
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve2(ste,9,4,9); //9£¬4£¬9
   }
	return center;	
}


int L2coordinate(char step)		//center 14
{
  if(stage==-1){
	Ras=Ra;
	Las=La;
	ste=stepconversion(step);	
    stage = 0;		
	}
    while(stage==0&&Step=='1'){
		cubesolve6(ste,14,14,14); //14£¬14£¬14
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve4(ste,24,24,24); //24£¬24£¬24
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve3(ste,22,22,22); //22£¬22£¬22
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve1(ste,10,10,5); //10£¬10£¬5
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve5(ste,14,14,14); //14£¬14£¬14
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve2(ste,1,18,1); //1£¬18£¬1
   }
	return center;	
}

int L3coordinate(char step)		//center 15
{
   if(stage==-1){
	Ras=Ra;
	Las=La;
	ste=stepconversion(step);		
    stage = 0;		
	}
    while(stage==0&&Step=='1'){
		cubesolve3(ste,21,21,21); //21£¬21£¬21
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve5(ste,15,15,15); //15£¬15£¬15
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve4(ste,23,23,23); //23£¬23£¬23
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve1(ste,2,2,11); //2£¬2£¬11
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve6(ste,15,15,15); //15£¬15£¬15
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve2(ste,19,6,19); //19£¬6£¬19
   }
	return center;	
}


int L4coordinate(char step)		//center 16
{
   if(stage==-1){
	Ras=Ra;
	Las=La;
	stepconversion(step);	
    stage = 0;		
	}
    while(stage==0&&Step=='1'){
		cubesolve4(ste,22,22,22); //22£¬22£¬22
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve6(ste,16,16,16); //16£¬16£¬16
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve5(ste,16,16,16); //16£¬16£¬16
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve1(ste,20,20,3); //20£¬20£¬3
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve3(ste,24,24,24); //24£¬24£¬24
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve2(ste,7,12,7); //7£¬12£¬7
   }
	return center;	
}

