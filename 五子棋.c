#define  _CRT_SECURE_NO_WARNINGS
#define  _CRT_SECURE_NO_WARNINGS
#include"game.h"
//说明：
//*是玩家走的棋子
//#是电脑走的棋子
void menu()
{
	printf("*****************\n");
	printf("**1,play 0,exit**\n");
	printf("*****************\n");
	printf("请选择：");
}
void game()
{
	char win = 'c';
	char board[ROW][COL] = { 0 };//创建棋盘
	Initialboard(board, ROW, COL);//初始化棋盘
	Displayboard(board, ROW, COL);//打印出棋盘的信息
	while (1)
	{
		//玩家走
		printf("玩家走\n");
		playermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		win = Isfull(board, ROW, COL);
		win = Iswin(board, ROW, COL);
		if (win != 'c')
			break;
		//电脑走
		printf("电脑走\n");
		computermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		win = Isfull(board, ROW, COL);
		win = Iswin(board, ROW, COL);
		if (win != 'c')
			break;
	}
	if (win == 'e')
		printf("平局\n");
	else if (win == '*')
		printf("玩家赢\n");
	else if (win == '#')
		printf("电脑赢\n");
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		//菜单，让用户选择
		menu();
		scanf("%d", &input);
		if (input != 0)
		{
			printf("游戏开始\n");
			game();//游戏主体

		}

		else
		{
			printf("退出游戏\n");
			break;
		}
	} while (input);

	return 0;
}