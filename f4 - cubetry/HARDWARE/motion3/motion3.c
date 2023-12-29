#include "inmotion.h"

int B1coordinate(char step)   //center 9
{
  if(stage==-1){
	Ra=Ras;
	La=Las;
	stepconversion(step);	
    stage = 0;		
	}
   while(stage==0&&Step=='1'){
	   cubesolve5(step,9,9,9); //9£¬9£¬9
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve3(step,19,19,19); //19£¬19£¬19
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve1(step,7,7,13); //7£¬7£¬13
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve4(step,17,17,17); //17£¬17£¬17
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve2(step,21,1,21); //21£¬1£¬21
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve6(step,9,9,9); //9£¬9£¬9
   }
	return center;	
}


int B2coordinate(char step)		//center 10
{
  if(stage==-1){
	Ra=Ras;
	La=Las;
	stepconversion(step);	
    stage = 0;		
	}
    while(stage==0&&Step=='1'){
		cubesolve6(step,10,10,10); //10£¬10£¬10
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve4(step,20,20,20); //20£¬20£¬20
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve1(step,22,22,8); //22£¬22£¬8
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve5(step,10,10,10); //10£¬10£¬10
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve2(step,2,14,2); //2£¬14£¬2
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve3(step,18,18,18); //18£¬18£¬18
   }
	return center;	
}

int B3coordinate(char step)		//center 11
{
   if(stage==-1){
	Ra=Ras;
	La=Las;
	stepconversion(step);	
    stage = 0;		
	}
    while(stage==0&&Step=='1'){
		cubesolve3(step,17,17,17); //17£¬17£¬17
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve5(step,11,11,11); //11£¬11£¬11
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve1(step,3,3,23); //3£¬3£¬23
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve6(step,11,11,11); //11£¬11£¬11
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve2(step,15,5,15); //15£¬5£¬15
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve4(step,19,19,19); //19£¬19£¬19
   }
	return center;	
}


int B4coordinate(char step)		//center 12
{
   if(stage==-1){
	Ra=Ras;
	La=Las;
	stepconversion(step);	
    stage = 0;		
	}
    while(stage==0&&Step=='1'){
		cubesolve4(step,18,18,18); //18£¬18£¬18
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve6(step,12,12,12); //12£¬12£¬12
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve1(step,16,16,4); //16£¬16£¬4
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve3(step,20,20,20); //20£¬20£¬20
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve2(step,6,24,6); //6£¬24£¬6
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve5(step,12,12,12); //12£¬12£¬12
   }
	return center;	
}

