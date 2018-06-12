#define  _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu1()
{
	printf("*******************************\n");
	printf("****   1.新游戏   0.退出   ****\n");
	printf("*******************************\n");

}
void menu2()
{
	printf("***********************************\n");
	printf("****   0.返回上层 1.继续排雷   ****\n");
	printf("****   2.标记     3.取消标记   ****\n");
	printf("***********************************\n");
}
void game()
{
	int x = 0;
	int y = 0;
	int win = 0;
	char show[ROWS][COLS] = { 0 };//显示数组
	char mine[ROWS][COLS] = { 0 };//布雷数组
	InitBoard(show, ROWS, COLS,'*');//排雷结果棋盘
	InitBoard(mine, ROWS, COLS, '0');//排雷显示棋盘
	SetMine(mine, EASY_COUNT, ROW, COL);//布雷函数
	DisPlayBoard(show, ROW, COL);//打印函数
	//DisPlayBoard(mine, ROW, COL);
	while (win < (ROW*COL-EASY_COUNT))
	{
		int n = 0;
		DisPlayBoard(show, ROW, COL);
		menu2();
		printf("请选择->");
		scanf("%d", &n);
		fflush(stdin);//清空输入缓冲区
		if (n == 1)
		{
			printf("请输入坐标->");
			scanf("%d%d", &x, &y);
			fflush(stdin);
			if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
			{
				if (mine[x][y] == '1')
				{
					if (win == 0)//第一次就踩到雷
					{
						printf("                   哇，第一次你就踩着雷了，看你天赋异禀，老夫给你把雷换了\n");
						Sleep(2000);
						mine[x][y] = '0';
						SetMine(mine, 1, ROW, COL);//重新布一个雷
						ExpandMine(mine, show, x, y, &win);
					}
					else//不是第一次踩雷
					{
						printf("你被炸死了，继续修炼扫雷秘籍吧\n");
						DisPlayBoard(mine, ROW, COL);
						return;
					}

				}
				else
				{
					ExpandMine(mine, show, x, y, &win);
				}
			}
			else
			{
				printf("输入坐标不合法，请重新输入\n");
			}
		}
		else if (2 == n)
		{
			printf("请输入坐标->");
			scanf("%d%d", &x, &y);
			SignMine(show, x, y);
			DisPlayBoard(show, ROW, COL);
		}
		else if (3 == n)
		{
			printf("请输入坐标->");
			scanf("%d%d", &x, &y);
			UnsignMine(show, x, y);
			DisPlayBoard(show, ROW, COL);
		}
		else if (0 == n)
		{
			return;
		}
		else
		{
			printf("输入错误，请重新输入\n");
			continue;

		}

	}
	if (win >= (ROW*COL - EASY_COUNT))
	{
		DisPlayBoard(mine, ROW, COL);//显示雷函数
		printf("恭喜你，排雷成功\n");
		Sleep(5000);
	}

	
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do{
			system("cls");
			menu1();
			printf("请选择->");
			scanf("%d", &input);
			switch (input)
			{
			case Game:
				game();
				break;
			case Exit:
				break;
			default:
				printf("输入错误，请重新输入\n");
				break;
			}
	  } while (input);
	
}
int main()
{
	test();
	system("pause");
	return 0;
}
