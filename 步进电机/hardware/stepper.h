#ifndef __STEPPER_H_
#define __STEPPER_H_


#define Rbujin_en   PAout(0) 
#define Rbujin_dir  PAout(1)
#define Lbujin_en	PAout(2)
#define Lbujin_dir	PAout(3) 

#define Ncountertarget1 100 
#define Ncountertarget2 200

#define TIM_PERIOD         65535

#define TIM_PRESCALER      0 


extern int Ra;
extern int La;
extern int flag;

void bujin_Init(void);
void counter1_Init(void);
void counter2_Init(void);
void en_Init(void);
void reposition(void);
void solidposition(void);
void Rspeed(uint16_t compare);
void Lspeed(uint16_t compare);
void Rbujincontral(int en, int motor_dir);
void Lbujincontral(int en, int motor_dir);
void Rphase(int aspect);
void Lphase(int aspect);
void Rpulse_get(int x);
void Lpulse_get(int y);


#endif 

