#include "stm32f10x.h"      // Device header 
#include "inmotion.h"



int D1coordinate(char step)//center5
{
   if(stage==-1){
	Ras=Ra;
	Las=La;
	ste=stepconversion(step);	
    stage = 0;		
	}	
   while(stage==0&&Step=='1'){
	   cubesolve2(ste,14,17,14); //14，17，14
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve1(ste,11,11,24); //11，11，24
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve3(ste,3,3,3); //3，3，3
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve6(ste,5,5,5); //5，5，5
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve5(ste,5,5,5); //5，5，5
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve4(ste,1,1,1); //1，1，1
   }
	return center;	
}

//统一格式
int D2coordinate(char step)//center6
{
  if(stage==-1){
	Ras=Ra;
	Las=La;
	ste=stepconversion(step);	
    stage = 0;		
	}
   while(stage==0&&Step=='1'){
	   cubesolve2(ste,18,21,18); //18，21，18
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve1(ste,15,15,12); //15，15，12
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve4(ste,4,4,4); //4，4，4
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve3(ste,2,2,2); //2，2，2
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve6(ste,6,6,6); //6，6，6
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve5(ste,6,6,6); //6，6，6
   }
	return center;	
}

int D3coordinate(char step)//center7
{
   if(stage==-1){
	Ras=Ra;
	Las=La;
	ste=stepconversion(step);	
    stage = 0;		
	}
   while(stage==0&&Step=='1'){
	   cubesolve2(ste,22,9,22); //22，9，22
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve1(ste,19,19,16); //19，19，16
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve5(ste,7,7,7); //7，7，7
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve4(ste,3,3,3); //3，3，3
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve3(ste,1,1,1); //1，1，1
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve6(ste,7,7,7); //7，7，7
   }
	return center;	
}


 int D4coordinate(char step)//center8
{
   if(stage==-1){
	Ras=Ra;
	Las=La;
	ste=stepconversion(step);	
    stage = 0;		
	}
    while(stage==0&&Step=='1'){
	  cubesolve2(ste,10,13,10); //10，13，10
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve1(ste,23,23,20); //23，23，20
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve6(ste,8,8,8); //7，7，7
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve5(ste,8,8,8); //8，8，8
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve4(ste,2,2,2); //2，2，2
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve3(ste,4,4,4); //4，4，4
   }
	return center;	
}
	
