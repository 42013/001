#ifndef __REALAYS_H
#define __REALAYS_H
#include "sys.h"

#define ROPEN   PBout(1)
#define LOPEN   PBout(0)

void Electromagnets(void);
void open_left(void);
void close_left(void);
void open_right(void);
void close_right(void);

#endif
