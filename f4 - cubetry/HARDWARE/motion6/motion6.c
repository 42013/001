#include "inmotion.h"

int R1coordinate(char step)		//center 21
{
   if(stage==-1){
	Ra=Ras;
	La=Las;
	stepconversion(step);	
    stage = 0;		
	}
   while(stage==0&&Step=='1'){
	   cubesolve5(step,21,21,21); //21£¬21£¬21
   }
   while(stage==0&&Step=='2'){
	   cubesolve3(step,15,15,15); //15£¬15£¬15
   }
   while(stage==0&&Step=='3'){
	   cubesolve4(step,13,13,13); //13£¬13£¬13
   }
   while(stage==0&&Step=='4'){
	   cubesolve2(step,17,2,17); //17£¬2£¬17
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve6(step,21,21,21); //21£¬21£¬21
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve1(step,6,6,9); //6£¬6£¬9
   }
	return center;	
}


int R2coordinate(char step)		//center 22
{
  if(stage==-1){
	Ra=Ras;
	La=Las;
	stepconversion(step);	
    stage = 0;		
	}
    while(stage==0&&Step=='1'){
	  cubesolve6(step,22,22,22); //22£¬22£¬22	
   }
   while(stage==0&&Step=='2'){
	   cubesolve4(step,16,16,16); //16£¬16£¬16
   }
   while(stage==0&&Step=='3'){
	   cubesolve5(step,22,22,22); //22£¬22£¬22
   }
   while(stage==0&&Step=='4'){
	   cubesolve2(step,3,10,3); //3£¬10£¬3
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve3(step,14,14,14); //14£¬14£¬14
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve1(step,18,18,18); //18£¬18£¬18
   }
	return center;	
}

int R3coordinate(char step)		//center 23
{
   if(stage==-1){
	Ra=Ras;
	La=Las;
	stepconversion(step);	
    stage = 0;		
	}
    while(stage==0&&Step=='1'){
		cubesolve3(step,13,13,13); //13£¬13£¬13
   }
   while(stage==0&&Step=='2'){
	   cubesolve5(step,23,23,23); //23£¬23£¬23
   } 
   while(stage==0&&Step=='3'){
	   cubesolve6(step,23,23,23); //23£¬23£¬23
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve2(step,11,8,11); //11£¬8£¬11
   }
   while(stage==0&&Step=='5'){
	   cubesolve4(step,15,15,15); //15£¬15£¬15
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve1(step,4,4,19); //4£¬4£¬19
   }
	return center;	
}


int R4coordinate(char step)		//center 24
{
   if(stage==-1){
	Ra=Ras;
	La=Las;
	stepconversion(step);	
    stage = 0;		
	}
    while(stage==0&&Step=='1'){
	  cubesolve4(step,14,14,14); //14£¬14£¬14
   }
   while(stage==0&&Step=='2'){
	   cubesolve6(step,24,24,24); //24£¬24£¬24
   }
   while(stage==0&&Step=='3'){
	   cubesolve3(step,16,16,16); //16£¬16£¬16
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve2(step,5,20,5); //5£¬20£¬5
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve5(step,24,24,24); //24£¬24£¬24
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve1(step,12,12,1); //12£¬12£¬1
   }
	return center;	
}

