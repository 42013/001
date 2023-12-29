#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"
#define Rbujin_en   PAout(0) 
#define Rbujin_dir  PAout(1)
#define Lbujin_en	PAout(2)
#define Lbujin_dir	PAout(3) 

#define TIM_PERIOD         0xFFFF

#define TIM_PRESCALER      0  

#define TIM7_PERIOD         50959  //50960

#define TIM7_PRESCALER      2  
 
extern int Ra;
extern int La;
extern int flag;

void bujin_Init(void);
void reposition(void);
void Rspeed(uint16_t compare);
void Lspeed(uint16_t compare);
void Rbujincontral(int en, int motor_dir);
void Lbujincontral(int en, int motor_dir);
void Rphase(int aspect);
void Lphase(int aspect);
void Rpulse_get(int x);
void Lpulse_get(int y);
void counter_Init(void);
void TIM7_Int_Init(u16 aRr,u16 pSc);
void open_timer7(void);
void close_timer7(void);


#endif























