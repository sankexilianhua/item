#define  _CRT_SECURE_NO_WARNINGS
#define  _CRT_SECURE_NO_WARNINGS
#include"game.h"
//˵����
//*������ߵ�����
//#�ǵ����ߵ�����
void menu()
{
	printf("*****************\n");
	printf("**1,play 0,exit**\n");
	printf("*****************\n");
	printf("��ѡ��");
}
void game()
{
	char win = 'c';
	char board[ROW][COL] = { 0 };//��������
	Initialboard(board, ROW, COL);//��ʼ������
	Displayboard(board, ROW, COL);//��ӡ�����̵���Ϣ
	while (1)
	{
		//�����
		printf("�����\n");
		playermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		win = Isfull(board, ROW, COL);
		win = Iswin(board, ROW, COL);
		if (win != 'c')
			break;
		//������
		printf("������\n");
		computermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		win = Isfull(board, ROW, COL);
		win = Iswin(board, ROW, COL);
		if (win != 'c')
			break;
	}
	if (win == 'e')
		printf("ƽ��\n");
	else if (win == '*')
		printf("���Ӯ\n");
	else if (win == '#')
		printf("����Ӯ\n");
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		//�˵������û�ѡ��
		menu();
		scanf("%d", &input);
		if (input != 0)
		{
			printf("��Ϸ��ʼ\n");
			game();//��Ϸ����

		}

		else
		{
			printf("�˳���Ϸ\n");
			break;
		}
	} while (input);

	return 0;
}