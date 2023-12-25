//game.c文件
#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
void Boardbegin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void Boardprint(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)//第三行没有---
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void Playermove(char board[ROW][COL], int row, int col)//这里数组是传址调用记得把[ROW][COL]加上不然就被认为是传过来一个字符char类型
{
	int xy = 0;
	int x = 0;
	int y = 0;
	printf("玩家走：>\n");
	printf("输入你要下的坐标：>");
	while (1)
	{
		scanf_s("%d", &xy);
		x = xy / 10;
		y = xy % 10;
		//判断x，y坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用\n");
			}
		}
		else {
			printf("该坐标不合法请重新输入！\n");
			}
	}
}
void Computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走：>\n");
	while (1)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
char Iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (; i < row; i++)//判断行是否相等
	{
		if (board[i][0] == board[i][1] && board[i][2] == board[i][1] && board[i][0] != ' ')
			return board[i][1];
	}
	for (; j < col; j++)//判断是否列相等
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] != ' ')
			return board[0][j];
	}
	//判断斜线处是否相等
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	if (Isfull(board, ROW, COL) == 1)
	{
		return	'Q';//平局
	}
	return  'C';//表示继续没满继续下棋
}
//平局
int Isfull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//没满
			}
		}
		//return 1;//满了
	}
	return 1;//满了——已更改
}