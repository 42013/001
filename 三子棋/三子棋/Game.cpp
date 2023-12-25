//game.c�ļ�
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
		if (i < row - 1)//������û��---
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

void Playermove(char board[ROW][COL], int row, int col)//���������Ǵ�ַ���üǵð�[ROW][COL]���ϲ�Ȼ�ͱ���Ϊ�Ǵ�����һ���ַ�char����
{
	int xy = 0;
	int x = 0;
	int y = 0;
	printf("����ߣ�>\n");
	printf("������Ҫ�µ����꣺>");
	while (1)
	{
		scanf_s("%d", &xy);
		x = xy / 10;
		y = xy % 10;
		//�ж�x��y����ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�����걻ռ��\n");
			}
		}
		else {
			printf("�����겻�Ϸ����������룡\n");
			}
	}
}
void Computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����ߣ�>\n");
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

	for (; i < row; i++)//�ж����Ƿ����
	{
		if (board[i][0] == board[i][1] && board[i][2] == board[i][1] && board[i][0] != ' ')
			return board[i][1];
	}
	for (; j < col; j++)//�ж��Ƿ������
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] != ' ')
			return board[0][j];
	}
	//�ж�б�ߴ��Ƿ����
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	if (Isfull(board, ROW, COL) == 1)
	{
		return	'Q';//ƽ��
	}
	return  'C';//��ʾ����û����������
}
//ƽ��
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
				return 0;//û��
			}
		}
		//return 1;//����
	}
	return 1;//���ˡ����Ѹ���
}