#define  _CRT_SECURE_NO_WARNINGS\

#include "game.h"

void menu()
{
	printf("*************************\n");
	printf("*************************\n");
	printf("*************************\n");
	printf("*****欢迎来到扫雷游戏****\n");
	printf("*****1.play   0.exit*****\n");
	printf("*************************\n");
	printf("*************************\n");
	printf("*************************\n");
}
void explain()
{
	printf("*******************************\n");
	printf("***********这里是解释**********\n");
	printf("**最后的棋盘1表示的是雷的位置**\n");
	printf("**游玩过程中出现的数字表示*****\n");
	printf("**这个位置周围的8个位置有几颗雷\n");
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
		printf("请输入你的选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			explain();
			game();
			break;
		case 0:
			printf("退出游戏");
			Sleep(1000);
			break;
		default:
			printf("选择错误，请重新选择\n");
		}
	} while (input);
	return 0;
}
