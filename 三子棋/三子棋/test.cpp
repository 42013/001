#define _CRT_SECURE_NO_WARNINGS 1
 
#include"game.h"
int judje = 0;
void menu()
{
	printf("**********************************\n");
	printf("***输入1开始游戏 输入0退出游戏****\n");
	printf("**********************************\n");
}
void game()
{
	//将信息储存在棋盘中
	char board[ROW][COL] = { 0 };
	//先初始化棋盘
	Boardbegin(board, ROW, COL);
	//打印棋盘
	Boardprint(board, ROW, COL);
	//玩游戏
 
	while (1)
	{
		char ret = 0;
		//玩家移动
		Playermove(board, ROW, COL);
		system("cls");
		Boardprint(board, ROW, COL);
		//玩家赢了
		Isfull(board, ROW, COL);
		//Iswin(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		//玩家走完进行胜利判断
		if (ret != 'C')
		{
			if (ret == '*')
			{
				printf("玩家赢\n");
				printf("x");
				judje = 1;
				//游戏结果出来后跳出循环
				break;
			}
			else if (ret == '#')
			{
				printf("电脑赢\n");
				judje = 0;
				break;
			}
			else
			{
				printf("平局\n");
				judje = 0;
				break;
			}
		}
		//电脑移动
		Computermove(board, ROW, COL);
		Boardprint(board, ROW, COL);
		//电脑赢了
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			if (ret == '*')
			{
				printf("玩家赢\n");
				printf("y");
				judje = 1;
				break;
			}
			else if (ret == '#')
			{
				printf("电脑赢\n");
				judje = 0;
				break;
			}
			else
			{
				printf("平局\n");
				judje = 0;
				break;
			}
		}
	}
}


int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	menu();
	scanf_s("%d", &input);
	do
	{
		switch (input)
		{
		case 1:
		{
			game();
			input = 2;
			break;
		}
		case 0:
			printf("退出游戏：\n");
			break;
		default:
			if (judje == 1) {
				printf("是否继续,继续输入1\n");
				scanf_s("%d", &input);
				judje = 0;
			}
			else {
				break;
			}
			break;
		}
	} while (input);
	return 0;
}