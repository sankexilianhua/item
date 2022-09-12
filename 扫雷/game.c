#define  _CRT_SECURE_NO_WARNINGS
#include "game.h"

void Initboard(char board[ROWS][COLS], int row, int col, char set)
{
	int i = 0;
	int j = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = set;
		}
	}
}

void Displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= ROW; i++)
	{
		printf("%d ",i);
	}
	printf("\n");

	for (i = 1; i <= ROW; i++)
	{
		printf("%d ",i);

		for (j = 1; j<= COL; j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
}

void setmine(char board[ROWS][COLS], int row, int col)
{
	int count = Easy_count;
	int x = 0;
	int y = 0;
	while (count)
	{
		x = rand() % ROW + 1;
		y = rand() % ROW + 1;

		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char board[ROWS][COLS], int x, int y)
{
	return board[x - 1][y - 1] + board[x - 1][y]
		+ board[x - 1][y + 1] + board[x][y - 1]
		+ board[x][y + 1] + board[x + 1][y - 1]
		+ board[x + 1][y] + board[x + 1][y + 1]
		- (8 * '0');
}
void boom_broad(char mine[ROWS][COLS], char board[ROWS][COLS], int row, int col, int x, int y)
{
	if (x >= 1 && x <= ROW&&y >= 1 && y <= COL)
	{
		if (board[x][y] != '*'||mine[x][y]=='1')
			return;
		int ret = get_mine_count(mine, x, y);
		board[x][y] = ret+'0';
		
		if (ret == 0)
		{
			boom_broad(mine, board, row, col, x - 1, y - 1);
			boom_broad(mine, board, row, col, x - 1, y);
			boom_broad(mine, board, row, col, x - 1, y + 1);
			boom_broad(mine, board, row, col, x, y - 1);
			boom_broad(mine, board, row, col, x, y + 1);
			boom_broad(mine, board, row, col, x + 1, y - 1);
			boom_broad(mine, board, row, col, x + 1, y);
			boom_broad(mine, board, row, col, x + 1, y + 1);
		}

	}
	else
	{
		return;
	}
}

void fine_mine(char mine[ROWS][COLS], char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = ROW*COL - Easy_count;
	while(count)
	{
		printf("请输入排雷坐标:>");
		scanf("%d%d",&x,&y);
		if (x >= 1 && x <= ROW&&y >= 1 && y <= COL)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				printf("下面是雷的位置：\n");
				Displayboard(mine, ROW, COL);
				break;
			}
			else if (mine[x][y] != '1'&&board[x][y] != '*')
			{
				printf("已经扫过雷了，请重新选择排雷坐标\n");
			}
			else
			{
				//int ret = get_mine_count(mine, ROW, COL);
				//board[x][y] = ret + '0';
				//count--;
				boom_broad(mine, board, ROW, COL, x, y);
				Displayboard(board, ROW, COL);
			}
		}
		else
		{
			printf("坐标有误，请重新输入");
		}
	}
	if (count == 0)
	{
		printf("恭喜你，扫雷成功");
		printf("下面是雷的位置：\n");
		Displayboard(mine, ROW, COL);
	}
}