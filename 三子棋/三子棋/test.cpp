#define _CRT_SECURE_NO_WARNINGS 1
 
#include"game.h"
int judje = 0;
void menu()
{
	printf("**********************************\n");
	printf("***����1��ʼ��Ϸ ����0�˳���Ϸ****\n");
	printf("**********************************\n");
}
void game()
{
	//����Ϣ������������
	char board[ROW][COL] = { 0 };
	//�ȳ�ʼ������
	Boardbegin(board, ROW, COL);
	//��ӡ����
	Boardprint(board, ROW, COL);
	//����Ϸ
 
	while (1)
	{
		char ret = 0;
		//����ƶ�
		Playermove(board, ROW, COL);
		system("cls");
		Boardprint(board, ROW, COL);
		//���Ӯ��
		Isfull(board, ROW, COL);
		//Iswin(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		//����������ʤ���ж�
		if (ret != 'C')
		{
			if (ret == '*')
			{
				printf("���Ӯ\n");
				printf("x");
				judje = 1;
				//��Ϸ�������������ѭ��
				break;
			}
			else if (ret == '#')
			{
				printf("����Ӯ\n");
				judje = 0;
				break;
			}
			else
			{
				printf("ƽ��\n");
				judje = 0;
				break;
			}
		}
		//�����ƶ�
		Computermove(board, ROW, COL);
		Boardprint(board, ROW, COL);
		//����Ӯ��
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			if (ret == '*')
			{
				printf("���Ӯ\n");
				printf("y");
				judje = 1;
				break;
			}
			else if (ret == '#')
			{
				printf("����Ӯ\n");
				judje = 0;
				break;
			}
			else
			{
				printf("ƽ��\n");
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
			printf("�˳���Ϸ��\n");
			break;
		default:
			if (judje == 1) {
				printf("�Ƿ����,��������1\n");
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