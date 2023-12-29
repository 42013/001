#ifndef __MOTION_H_
#define __MOTION_H_

extern int Rstage;
extern int Lstage;
extern int stage;
extern int center;
extern int Las;
extern int Ras;
extern char Step;
extern char ste;	




//电磁铁开合系列
void LcRo(void);
void RcLo(void);
void RcLc(void);
void RoLo(void);
void RcLc0(void);
void RoLo0(void);
//机械臂转体加复位系列
void LRoute1(void);
void LRoute2(void);
void LRoute3(void);
void RRoute1(void);
void RRoute2(void);
void RRoute3(void);
//机械臂转体无复位系列
void Lrouter1(void);
void Lrouter3(void);
void Rrouter1(void);
void Rrouter3(void);
//机械臂转面系列
void Lturn1(void);
void Lturn2(void);
void Lturn3(void);
void Rturn1(void);
void Rturn2(void);
void Rturn3(void);
//机械臂归步系列
void RHoming(void);
void LHoming(void);
//坐标判断函数
void invokecenter(int CENTER,char steps);
//步骤归类函数
char stepconversion(char step);
//魔方坐标系函数
int U1coordinate(char step);
int U2coordinate(char step);
int U3coordinate(char step);
int U4coordinate(char step);
//魔方解法归类函数
void cubesolve1(char steps,int center1,int center2,int center3);
void cubesolve2(char steps,int center1,int center2,int center3);
void cubesolve3(char steps,int center1,int center2,int center3);
void cubesolve4(char steps,int center1,int center2,int center3);
void cubesolve5(char steps,int center1,int center2,int center3);
void cubesolve6(char steps,int center1,int center2,int center3);

#endif 
