#ifndef __MOTION_H_
#define __MOTION_H_

extern int Rstage;
extern int Lstage;
extern int stage;
extern int center;
extern int Las;
extern int Ras;
extern char Step;




//���������ϵ��
void LcRo(void);
void RcLo(void);
void RcLc(void);
void RoLo(void);
//��е��ת��Ӹ�λϵ��
void LRoute1(void);
void LRoute2(void);
void LRoute3(void);
void RRoute1(void);
void RRoute2(void);
void RRoute3(void);
//��е��ת���޸�λϵ��
void Lrouter1(void);
void Lrouter3(void);
void Rrouter1(void);
void Rrouter3(void);
//��е��ת��ϵ��
void Lturn1(void);
void Lturn2(void);
void Lturn3(void);
void Rturn1(void);
void Rturn2(void);
void Rturn3(void);
//��е�۹鲽ϵ��
void RHoming(void);
void LHoming(void);
//�����жϺ���
void invokecenter(int CENTER,char steps);
//������ຯ��
void stepconversion(char step);
//ħ������ϵ����
int U1coordinate(char step);
int U2coordinate(char step);
int U3coordinate(char step);
int U4coordinate(char step);
//ħ���ⷨ���ຯ��
void cubesolve1(char steps,int center1,int center2,int center3);
void cubesolve2(char steps,int center1,int center2,int center3);
void cubesolve3(char steps,int center1,int center2,int center3);
void cubesolve4(char steps,int center1,int center2,int center3);
void cubesolve5(char steps,int center1,int center2,int center3);
void cubesolve6(char steps,int center1,int center2,int center3);

#endif 
