#define  _CRT_SECURE_NO_WARNINGS\

#include "game.h"

void menu()
{
	printf("*************************\n");
	printf("*************************\n");
	printf("*************************\n");
	printf("*****��ӭ����ɨ����Ϸ****\n");
	printf("*****1.play   0.exit*****\n");
	printf("*************************\n");
	printf("*************************\n");
	printf("*************************\n");
}
void explain()
{
	printf("*******************************\n");
	printf("***********�����ǽ���**********\n");
	printf("**��������1��ʾ�����׵�λ��**\n");
	printf("**��������г��ֵ����ֱ�ʾ*****\n");
	printf("**���λ����Χ��8��λ���м�����\n");
	printf("*******************************\n");
	printf("*******************************\n");

}
void game()
{
	srand((unsigned int)time(NULL));
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	Initboard(mine, ROWS, COLS,'0');
	Initboard(show, ROWS, COLS, '*');
	Displayboard(show,ROW,COL);
	setmine(mine, ROW, COL);
	//Displayboard(mine, ROW, COL);
	fine_mine(mine, show, ROW, COL);
}
int main()
{
	int input = 0;
	do{
		menu();
		printf("���������ѡ��>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			explain();
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
			Sleep(1000);
			break;
		default:
			printf("ѡ�����������ѡ��\n");
		}
	} while (input);
	return 0;
}
