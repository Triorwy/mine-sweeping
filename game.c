#include"game.h"

void InitBoard(char board[ROWS][COLS], int row, int col,char set)//初始化棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisPlayBoard(char board[ROWS][COLS], int row, int col)//打印棋盘
{
	system("cls");
	printf("    排雷棋盘图\n");
	int i = 0;
	int j = 0;
	printf("   ");
	for (j = 1; j <= col; j++)//打印列坐标
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%2d ", i);//打印行坐标
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void SetMine(char mine[ROWS][COLS], int count, int row, int col)//布雷
{
	int x = 0;
	int y = 0;
	while (count)
	{
		x = rand() % row + 1;
	    y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}	
	}
}
int GetMineCount(char mine[ROWS][COLS], int x, int y)//统计周围雷的个数
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] +
		   mine[x][y - 1] + mine[x][y + 1] +
		   mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';

}
void ExpandMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int *num)//展开雷区
{
	int i = 0;
	int j = 0;
	if (show[x][y] == '*')//表示此处没有排过，可以排雷
	{
		(*num)++;
		int count = GetMineCount(mine, x, y);
		if (count != 0)//周围有雷，不能扩展
		{
			show[x][y] = count + '0';//做标记表示该处排过
		}
		else
		{
			show[x][y] = '0';//该位置显示为字符0，并开始扩展
			for (i = -1; i <= 1; i++)
			{			
				for (j = -1; j <= 1; j++)
				{
					if (x + i >= 1 && x + i <= ROW && y + j >= 1 && y + j <= COL)
					{
						if (i != 0 || j != 0)
						{
							ExpandMine(mine, show, x + i, y + j, num);
						}
					}
				}
			}
		}

	}
}
void SignMine(char show[ROWS][COLS], int x, int y)//标记雷
{
	if (show[x][y] == '*')
	{
		show[x][y] = '#';
	}
}
void UnsignMine(char show[ROWS][COLS], int x, int y)//取消标记
{
	if (show[x][y] == '#')
	{
		show[x][y] = '*';
	}
}
