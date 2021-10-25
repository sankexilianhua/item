#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ROW 5
#define COL 5
void Initialboard(char board[ROW][COL], int row, int col);
void Displayboard(char board[ROW][COL], int row, int col);
void playeremove(char board[ROW][COL], int row, int col);
void computermove(char board[ROW][COL], int  row, int col);
char Iswin(char board[ROW][COL], int  row, int col);
char Isfull(char board[ROW][COL], int row, int col);