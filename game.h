#ifndef _GAME_H_
#define _GAME_H_

#include<stdio.h>
#include<windows.h>
#include<time.h>
#include <stdlib.h>


#define ROW 10
#define COL 10

#define ROWS ROW + 2
#define COLS COL + 2

#define EASY_COUNT 10 //雷的个数

enum
{
	Exit,
	Game

};
void DisPlayBoard(char board[ROWS][COLS],int row,int col);//打印棋盘
void InitBoard(char board[ROWS][COLS],int row,int col,char set);//初始化棋盘
void SetMine(char mine[ROWS][COLS], int count, int row, int col);//放雷
int GetMineCount(char mine[ROWS][COLS], int x, int y);//统计周围雷的个数
void ExpandMine(char mine[ROWS][COLS],char show[ROWS][COLS],int x,int y,int *num);//展开无雷区
void SignMine(char show[ROWS][COLS], int x, int y);//标记雷
void UnsignMine(char show[ROWS][COLS], int x, int y);//取消标记
#endif//_GAME_H_
