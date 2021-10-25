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
void menu2()
{
	printf("*****************\n");
	printf("**请选择对战方式*\n");
	printf("**1,人机 0,人人**\n");
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
void game2()
{
	char win = 'c';
	char board[ROW][COL] = { 0 };//创建棋盘
	Initialboard(board, ROW, COL);//初始化棋盘
	Displayboard(board, ROW, COL);//打印出棋盘的信息
	while (1)
	{
		//玩家1走
		printf("玩家1走\n");
		playermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		win = Isfull(board, ROW, COL);
		win = Iswin(board, ROW, COL);
		if (win != 'c')
			break;
		//玩家2走
		printf("玩家2走\n");
		player2move(board, ROW, COL);
		Displayboard(board, ROW, COL);
		win = Isfull(board, ROW, COL);
		win = Iswin(board, ROW, COL);
		if (win != 'c')
			break;
	}
	if (win == 'e')
		printf("平局\n");
	else if (win == '*')
		printf("玩家1赢\n");
	else if (win == '#')
		printf("玩家2赢\n");
}
int main()
{

	int input = 0;
	int count = 0;
	srand((unsigned int)time(NULL));
	char arr1[20] = { 0 };
	char arr2[20] = { 0 };
	char arr3[20] = { 0 };
	char arr4[20] = { 0 };
	do
	{
			//菜单，让用户选择
			menu();
			scanf("%d", &input);
			if (input != 0)
			{
				//登录系统
				if (count == 0)
				{
					printf("请设置你的账号：");
					scanf("%s", &arr1);
					printf("请设置你的密码：");
					scanf("%s", &arr2);
				}
					printf("请输入你的账号：");
					scanf("%s", &arr3);
					printf("请输入你的密码：");
					scanf("%s", &arr4);
				if (strcmp(arr1, arr3) == 0 && strcmp(arr3, arr4) == 0)
				{
					int i = 0;
		again:
					menu2();
					scanf("%d",&i);
					switch (i)
				{
					case 1:
						{
							printf("游戏开始\n");
							game();//游戏主体
						}
					case 0:
					{
							  printf("游戏开始\n");
							  game2();//游戏主体
					}
					default:
					{
							   printf("选择错误，请重新选择\n");
						goto again;
					}
				}	
				count++;	
				}
				else
					printf("账号或密码错误。\n");

			}

			else
			{
				printf("退出游戏\n");
				break;
			}
		} while (input);
	    
	return 0;
}