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
	//��ʼ������
	Initboard(Mine, ROWS, COLS,'0');
	Initboard(Show, ROWS, COLS,'*');
	//��ӡ
	//printboard(Mine, ROW, COL);
	printboard(Show, ROW, COL);
	//����
	Set_Mine(Mine, ROW, COL);
	//printboard(Mine, ROW, COL);
	//����
	Mine_sweep(Mine, Show, ROW, COL);

}
int main()
{
	srand((unsigned int)time(NULL));
	int intput = 0;
	do
	{
		menu();
		printf("��ѡ���Ƿ���Ϸ:> ");
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
			printf("�˳���Ϸ\n");
			break;
		}
		default :
		{
			printf("ѡ�����������ѡ��\n");
		}
		}
	} while (intput);
	return 0;
}