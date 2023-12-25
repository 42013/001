
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
void Boardbegin(char board[ROW][COL], int row, int col);//初始化棋盘
void Boardprint(char board[ROW][COL], int row, int col);//打印棋盘
void Playermove(char board[ROW][COL], int row, int col);//玩家移动
void Computermove(char board[ROW][COL], int row, int col);//电脑移动
char Iswin(char board[ROW][COL], int row, int col);//判断输赢标准
int Isfull(char board[ROW][COL], int row, int col);//判断平局标准
//这里全都是函数声明
