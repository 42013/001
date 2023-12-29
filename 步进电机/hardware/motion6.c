#include "stm32f10x.h"      // Device header
#include "inmotion.h"


int R1coordinate(char step)		//center 21
{
   if(stage==-1){
	Ras=Ra;
	Las=La;
	ste=stepconversion(step);		
    stage = 0;		
	}
   while(stage==0&&Step=='1'){
	   cubesolve5(ste,21,21,21); //21£¬21£¬21
   }
   while(stage==0&&Step=='2'){
	   cubesolve3(ste,15,15,15); //15£¬15£¬15
   }
   while(stage==0&&Step=='3'){
	   cubesolve4(ste,13,13,13); //13£¬13£¬13
   }
   while(stage==0&&Step=='4'){
	   cubesolve2(ste,17,2,17); //17£¬2£¬17
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve6(ste,21,21,21); //21£¬21£¬21
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve1(ste,6,6,9); //6£¬6£¬9
   }
	return center;	
}


int R2coordinate(char step)		//center 22
{
  if(stage==-1){
	Ras=Ra;
	Las=La;
	ste=stepconversion(step);	
    stage = 0;		
	}
    while(stage==0&&Step=='1'){
	  cubesolve6(ste,22,22,22); //22£¬22£¬22	
   }
   while(stage==0&&Step=='2'){
	   cubesolve4(ste,16,16,16); //16£¬16£¬16
   }
   while(stage==0&&Step=='3'){
	   cubesolve5(ste,22,22,22); //22£¬22£¬22
   }
   while(stage==0&&Step=='4'){
	   cubesolve2(ste,3,10,3); //3£¬10£¬3
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve3(ste,14,14,14); //14£¬14£¬14
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve1(ste,18,18,7); //18£¬18£¬7
   }
	return center;	
}

int R3coordinate(char step)		//center 23
{
   if(stage==-1){
	Ras=Ra;
	Las=La;
	ste=stepconversion(step);	
    stage = 0;		
	}
    while(stage==0&&Step=='1'){
		cubesolve3(ste,13,13,13); //13£¬13£¬13
   }
   while(stage==0&&Step=='2'){
	   cubesolve5(ste,23,23,23); //23£¬23£¬23
   } 
   while(stage==0&&Step=='3'){
	   cubesolve6(ste,23,23,23); //23£¬23£¬23
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve2(ste,11,8,11); //11£¬8£¬11
   }
   while(stage==0&&Step=='5'){
	   cubesolve4(ste,15,15,15); //15£¬15£¬15
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve1(ste,4,4,19); //4£¬4£¬19
   }
	return center;	
}


int R4coordinate(char step)		//center 24
{
   if(stage==-1){
	Ras=Ra;
	Las=La;
	ste=stepconversion(step);	
    stage = 0;		
	}
    while(stage==0&&Step=='1'){
	  cubesolve4(ste,14,14,14); //14£¬14£¬14
   }
   while(stage==0&&Step=='2'){
	   cubesolve6(ste,24,24,24); //24£¬24£¬24
   }
   while(stage==0&&Step=='3'){
	   cubesolve3(ste,16,16,16); //16£¬16£¬16
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve2(ste,5,20,5); //5£¬20£¬5
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve5(ste,24,24,24); //24£¬24£¬24
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve1(ste,12,12,1); //12£¬12£¬1
   }
	return center;	
}

