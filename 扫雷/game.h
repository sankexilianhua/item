#pragma once
#define  _CRT_SECURE_NO_WARNINGS
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define Easy_count 10

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void Initboard(char board[ROWS][COLS], int rows, int cols, char set);

void Displayboard(char board[ROWS][COLS], int row, int col);

void setmine(char board[ROWS][COLS], int row, int col);

void fine_mine(char mine[ROWS][COLS],char board[ROWS][COLS],int row, int col);

int get_mine_count(char board[ROWS][COLS], int row, int col);

void boom_broad(char mine[ROWS][COLS], char board[ROWS][COLS], int row, int col,int x,int y);