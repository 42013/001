#include "inmotion.h"

int L1coordinate(char step)		//center 13
{
   if(stage==-1){
	Ra=Ras;
	La=Las;
	stepconversion(step);	
    stage = 0;		
	}
   while(stage==0&&Step=='1'){
	   cubesolve5(step,13,13,13); //13£¬13£¬13
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve3(step,23,23,23); //23£¬23£¬23
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve6(step,13,13,13); //13£¬13£¬13
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve1(step,2,2,17); //2£¬2£¬17
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve4(step,21,21,21); //21£¬21£¬21
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve2(step,9,4,9); //9£¬4£¬9
   }
	return center;	
}


int L2coordinate(char step)		//center 14
{
  if(stage==-1){
	Ra=Ras;
	La=Las;
	stepconversion(step);	
    stage = 0;		
	}
    while(stage==0&&Step=='1'){
		cubesolve6(step,14,14,14); //14£¬14£¬14
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve4(step,24,24,24); //24£¬24£¬24
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve3(step,22,22,22); //22£¬22£¬22
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve6(step,10,10,5); //10£¬10£¬5
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve5(step,14,14,14); //14£¬14£¬14
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve2(step,1,18,1); //1£¬18£¬1
   }
	return center;	
}

int L3coordinate(char step)		//center 15
{
   if(stage==-1){
	Ra=Ras;
	La=Las;
	stepconversion(step);	
    stage = 0;		
	}
    while(stage==0&&Step=='1'){
		cubesolve3(step,21,21,21); //21£¬21£¬21
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve5(step,15,15,15); //15£¬15£¬15
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve4(step,23,23,23); //23£¬23£¬23
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve1(step,2,2,11); //2£¬2£¬11
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve6(step,15,15,15); //15£¬15£¬15
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve2(step,19,6,19); //19£¬6£¬19
   }
	return center;	
}


int L4coordinate(char step)		//center 16
{
   if(stage==-1){
	Ra=Ras;
	La=Las;
	stepconversion(step);	
    stage = 0;		
	}
    while(stage==0&&Step=='1'){
		cubesolve4(step,22,22,22); //22£¬22£¬22
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve6(step,16,16,16); //16£¬16£¬16
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve5(step,16,16,16); //16£¬16£¬16
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve1(step,20,20,3); //20£¬20£¬3
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve3(step,24,24,24); //24£¬24£¬24
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve2(step,7,12,7); //7£¬12£¬7
   }
	return center;	
}

