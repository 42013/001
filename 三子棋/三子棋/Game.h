
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
void Boardbegin(char board[ROW][COL], int row, int col);//��ʼ������
void Boardprint(char board[ROW][COL], int row, int col);//��ӡ����
void Playermove(char board[ROW][COL], int row, int col);//����ƶ�
void Computermove(char board[ROW][COL], int row, int col);//�����ƶ�
char Iswin(char board[ROW][COL], int row, int col);//�ж���Ӯ��׼
int Isfull(char board[ROW][COL], int row, int col);//�ж�ƽ�ֱ�׼
//����ȫ���Ǻ�������
