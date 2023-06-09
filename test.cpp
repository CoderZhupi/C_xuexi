#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void game()
{
	//创建棋盘
	char Mine[ROWS][COLS] = { 0 };
	char Show[ROWS][COLS] = { 0 };
	//初始化棋盘
	Intiboard(Mine, ROWS, COLS, '0');
	Intiboard(Show, ROWS, COLS, '*');
	//打印棋盘
	displayboard(Show, ROW, COL);
	//布置雷
	setMine(Mine, ROW, COL);
	displayboard(Mine, ROW, COL);
	//排查雷
	find(Mine, Show, ROW, COL);

}





int main()
{
	srand((unsigned int)time(NULL));
	int a = 0;
	do
	{
		menu();
		printf("请输入=>");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			game();
			break;
		case 0 :
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;

		}



	} while (a);



	return 0;
}
