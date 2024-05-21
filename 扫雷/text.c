#include "game.h"
void menu()
{
	printf("*******************\n");
	printf("***** 1.play ******\n");
	printf("***** 0.exit ******\n");
	printf("*******************\n");
}
void game()
{
	char Mine[ROWS][COLS] = { 0 };
	char Show[ROWS][COLS] = { 0 };
	//初始化数组
	Initboard(Mine, ROWS, COLS,'0');
	Initboard(Show, ROWS, COLS,'*');
	//打印
	//printboard(Mine, ROW, COL);
	printboard(Show, ROW, COL);
	//埋雷
	Set_Mine(Mine, ROW, COL);
	//printboard(Mine, ROW, COL);
	//排雷
	Mine_sweep(Mine, Show, ROW, COL);

}
int main()
{
	srand((unsigned int)time(NULL));
	int intput = 0;
	do
	{
		menu();
		printf("请选择是否游戏:> ");
		scanf("%d", &intput);
		system("cls");
		switch (intput)
		{
		case 1:
		{
			game();
			break;
		}
		case 0:
		{
			printf("退出游戏\n");
			break;
		}
		default :
		{
			printf("选择错误，请重新选择\n");
		}
		}
	} while (intput);
	return 0;
}