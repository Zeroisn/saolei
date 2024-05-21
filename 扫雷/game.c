#include "game.h"
void Initboard(char board[ROWS][COLS], int rows, int cols, char ch)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < rows;i++)
	{
		for (j = 0;j < cols;j++)
		{
			board[i][j] = ch;
		}
	}
}
void printboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("--------------扫雷游戏-------------\n");
	for (i = 0;i <= row;i++)
	{
		if (i >= 10)
		{
			printf("%d", i);
		}
		else
		{
			printf("%2d", i);
		}
	}
	printf("\n");
	for (i = 1;i <= row;i++)
	{
		printf("%2d", i);
		for (j = 1;j <= col;j++)
		{
			printf(" %c", board[i][j]);
		}
		printf("\n");
		
	}
	printf("--------------扫雷游戏-------------\n");
}
void Set_Mine(char Mine[ROWS][COLS], int row, int col)
{
	
	int count = MINE;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (Mine[x][y] == '0')
		{
			Mine[x][y] = '1';
			count--;
		}
	}
}
int Around_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1]-8*'0';
}

void Around_mine_counts(char show[ROWS][COLS],char mine[ROWS][COLS],int x, int y ,int ret)
{
	if (x > 0 && x <= ROW && y > 0 && y <= COL)
	{
		int count = Around_mine_count(mine, x, y);
		show[x][y] = count + '0';
		if (count == 0)
		{
			Around_mine_counts(show, mine, x - 1, y - 1, ret);
			Around_mine_counts(show, mine, x - 1, y, ret);
			Around_mine_counts(show, mine, x - 1, y + 1, ret);
			Around_mine_counts(show, mine, x, y - 1, ret);
		}
		ret++;
	}
}
void get_mine_counts(char show[ROWS][COLS], char mine[ROWS][COLS],int x, int y, int ret)
{
	if (x > 0 && x <= ROW && y > 0 && y <= COL)
	{
		int count = Around_mine_count(mine, x, y);
		show[x][y] = count + '0';
		if (count == 0)
		{
			get_mine_counts(show, mine, x, y + 1, ret);
			get_mine_counts(show, mine, x + 1, y - 1, ret);
			get_mine_counts(show, mine, x + 1, y, ret);
			get_mine_counts(show, mine, x + 1, y + 1, ret);
			Around_mine_counts(show, mine, x, y + 1, ret);
			Around_mine_counts(show, mine, x + 1, y - 1, ret);
			Around_mine_counts(show, mine, x + 1, y, ret);
			Around_mine_counts(show, mine, x + 1, y + 1, ret);
		}
		ret++;
	}
}
void Mine_sweep(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int ret = 0;
	while (ret<(row*col-MINE))
	{
		printf("请输入要排查雷的坐标:> ");
		scanf("%d%d", &x, &y);
		system("cls");
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printboard(mine, ROW, COL);
				printf("游戏失败\n");
				Sleep(10000);
				system("cls");
				break;
			}
			else
			{
				Around_mine_counts(show,mine, x, y,ret);
				get_mine_counts(show, mine, x, y, ret);
				printboard(show, ROW, COL);
			}
		}
		else
		{
			printf("请重新输入要排查的坐标\n");
		}
	}
	if (ret == (row * col - MINE))
	{
		printboard(mine, ROW, COL);
		printf("游戏获胜\n");
	}
}