#define  _CRT_SECURE_NO_WARNINGS
#include"game.h"
//初始化棋盘
void Initialboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//打印棋盘
//   |   |   
//---|---|—-
//   |   |   
//---|—-|---
//   |   |   
void Displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{   
		if (i == 0)
		{
			for (j = 0; j < col; j++)
			{
				if (j == 0)
					printf("  %d  ",j);
				else
					printf(" %d  ", j);
			}
			printf("\n");
		}
		printf("%d",i);
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < (col - 1))
			{
				printf("|");
			}
				
		}
		printf("\n");
		if (i<row - 1)
		{
			for (j = 0; j < col; j++)
			{
				if (j==0)
				printf(" ---");
				else
					printf("---");
				if (j < (col - 1))
					printf("|");
			}
		}
		printf("\n");
	}
}
//实现玩家下棋
void playermove(char board[ROW][COL], int row, int col)
{
	int i, j;
	printf("请根据图示输入要走的坐标：");
	while (1)
	{   
		scanf("%d%d",&i,&j);
		if (i >= 0 && i < 3 && j >= 0 && j <3 && board[i][j] == ' ')
		{
			board[i][j] = '*';
			break;
		}
		else
			printf("输入有误，请重新输入。");
	}
}

void computermove(char board[ROW][COL], int  row, int col)
{
	while (1)
	{
		int i = rand() % row;
		int j = rand() % col;
		if (board[i][j] == ' ')
		{
			board[i][j] = '#';
			break;
		}
	}
}

char Iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col - 2; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}
	for (j = 0; j < col; j++)
	{
		for (i = 0; i < row - 2; i++)
		{
			if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}
	for (i = 0, j = 0; i < row - 2 && j < col - 2; i++, j++)
	{
		if (board[i][j] == board[i + 1][j+1] && board[i + 1][j+1] == board[i + 2][j+2] && board[i][j] != ' ')
		{
			return board[i][j];
		}
	}
	for (i = row-1, j = 0; i >=0 && j < col-2; i--, j++)
	{
		if (board[i][j] == board[i -1][j + 1] && board[i - 1][j + 1] == board[i -2][j + 2] && board[i][j] != ' ')
		{
			return board[i][j];
		}
	}
	return 'c';
}
char Isfull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col;j++)
		{
			if (board[i][j] == ' ')
				return 'c';
		}
	}
	return 'e';
	 
}
