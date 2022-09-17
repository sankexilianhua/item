#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<conio.h>


#define ROW 10
#define COL 10
void Initialboard(char board[ROW][COL], int row, int col);
void Displayboard(char board[ROW][COL], int row, int col);
void playeremove(char board[ROW][COL], int row, int col);
void computermove(char board[ROW][COL], int  row, int col);
char Iswin(char board[ROW][COL], int  row, int col);
char Isfull(char board[ROW][COL], int row, int col);
void player2move(char board[ROW][COL], int row, int col);