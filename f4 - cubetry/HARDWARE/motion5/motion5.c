#include "inmotion.h"

int F1coordinate(char step)		//center 17
{
   if(stage==-1){
	Ra=Ras;
	La=Las;
	stepconversion(step);	
    stage = 0;		
	}
   while(stage==0&&Step=='1'){
	   cubesolve5(step,17,17,17); //17£¬17£¬17
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve3(step,11,11,11); //11£¬11£¬11
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve2(step,13,3,13); //13£¬3£¬13
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve5(step,17,17,17); //17£¬17£¬17
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve1(step,5,5,21); //5£¬5£¬21
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve4(step,9,9,9); //9£¬9£¬9
   }
	return center;	
}


int F2coordinate(char step)		//center 18
{
  if(stage==-1){
	Ra=Ras;
	La=Las;
	stepconversion(step);	
    stage = 0;		
	}
    while(stage==0&&Step=='1'){
		cubesolve6(step,18,18,18); //18£¬18£¬18
	} 
   while(stage==0&&Step=='2'){
	   cubesolve4(step,12,12,12); //12£¬12£¬12
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve2(step,4,22,4); //4£¬22£¬4
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve3(step,10,10,10); //10£¬10£¬10
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve1(step,14,14,6); //14£¬14£¬6
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve5(step,18,18,18); //18£¬18£¬18
   }
	return center;	
}

int F3coordinate(char step)		//center 19
{
   if(stage==-1){
	Ra=Ras;
	La=Las;
	stepconversion(step);	
    stage = 0;		
	}
    while(stage==0&&Step=='1'){
	  cubesolve3(step,9,9,9); //9£¬9£¬9
   }
   while(stage==0&&Step=='2'){
	   cubesolve5(step,19,19,19); //19£¬19£¬19
   }  
   while(stage==0&&Step=='3'){
	   cubesolve2(step,23,7,23); //23£¬7£¬23
   }
   while(stage==0&&Step=='4'){
	   cubesolve4(step,11,11,11); //11£¬11£¬11
   }
   while(stage==0&&Step=='5'){
	   cubesolve1(step,1,1,15); //1£¬1£¬15
   }
   while(stage==0&&Step=='6'){
	   cubesolve6(step,19,19,19); //19£¬19£¬19
   }
	return center;	
}


int F4coordinate(char step)		//center 20
{
   if(stage==-1){
	Ra=Ras;
	La=Las;
	stepconversion(step);	
    stage = 0;		
	}
    while(stage==0&&Step=='1'){
		cubesolve4(step,10,10,10); //10£¬10£¬10
   }
   while(stage==0&&Step=='2'){
	   cubesolve6(step,20,20,20); //20£¬20£¬20
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve2(step,8,16,8); //8£¬16£¬8
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve5(step,20,20,20); //20£¬20£¬20
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve1(step,24,24,2); //24£¬24£¬2
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve3(step,12,12,12); //12£¬12£¬12
   }
	return center;	
}

	
