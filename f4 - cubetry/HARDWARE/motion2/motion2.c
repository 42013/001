#include "inmotion.h"

int D1coordinate(char step)//center5
{
   if(stage==-1){
	Ra=Ras;
	La=Las;
	stepconversion(step);	
    stage = 0;		
	}	
   while(stage==0&&Step=='1'){
	   cubesolve2(step,14,17,14); //14，17，14
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve1(step,11,11,24); //11，11，24
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve3(step,3,3,3); //3，3，3
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve6(step,5,5,5); //5，5，5
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve5(step,5,5,5); //5，5，5
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve4(step,1,1,1); //1，1，1
   }
	return center;	
}

//出现字符混乱暂忽略，后统一格式
int D2coordinate(char step)//center6
{
  if(stage==-1){
	Ra=Ras;
	La=Las;
	stepconversion(step);	
    stage = 0;		
	}
   while(stage==0&&Step=='1'){
	   cubesolve2(step,18,21,18); //18，21，18
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve1(step,15,15,12); //15，15，12
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve4(step,4,4,4); //4，4，4
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve4(step,2,2,2); //2，2，2
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve6(step,6,6,6); //6，6，6
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve5(step,6,6,6); //6，6，6
   }
	return center;	
}

int D3coordinate(char step)//center7
{
   if(stage==-1){
	Ra=Ras;
	La=Las;
	stepconversion(step);	
    stage = 0;		
	}
   while(stage==0&&Step=='1'){
	   cubesolve2(step,22,9,22); //22，9，22
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve1(step,19,19,16); //19，19，16
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve5(step,7,7,7); //7，7，7
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve4(step,3,3,3); //3，3，3
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve3(step,1,1,1); //1，1，1
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve6(step,7,7,7); //7，7，7
   }
	return center;	
}


 int D4coordinate(char step)//center8
{
   if(stage==-1){
	Ra=Ras;
	La=Las;
	stepconversion(step);	
    stage = 0;		
	}
    while(stage==0&&Step=='1'){
	  cubesolve2(step,10,13,10); //10，13，10
   }
   
   
   while(stage==0&&Step=='2'){
	   cubesolve1(step,23,23,20); //23，23，20
   }
   
   while(stage==0&&Step=='3'){
	   cubesolve6(step,8,8,8); //7，7，7
   }
   
   while(stage==0&&Step=='4'){
	   cubesolve5(step,8,8,8); //8，8，8
   }
   
   while(stage==0&&Step=='5'){
	   cubesolve4(step,2,2,2); //2，2，2
   }
   
   while(stage==0&&Step=='6'){
	   cubesolve3(step,4,4,4); //4，4，4
   }
	return center;	
}
	
