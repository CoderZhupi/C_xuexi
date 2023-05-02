#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("****************** 1.play ********************\n");
	printf("****************** 2.exit ********************\n");

}
void game()
{
	char ret = 0;
	//创建数组
	char arr[ROW][COL];
	//数组空格化
	kong(arr, ROW, COL);
	//打印棋格
	printboard(arr, ROW, COL);
	while (1)
	{
		//玩家下棋
		playermove(arr, ROW, COL);
		printboard(arr, ROW, COL);
		ret = iswin(arr, ROW, COL);
		if (ret != 'B')
			break;
		//电脑下棋
		commove(arr, ROW, COL);
		printboard(arr, ROW, COL);
		ret = iswin(arr, ROW, COL);
		if (ret != 'B')
			break;

	}
	if (ret == '*')
		printf("玩家赢了\n");
	else if (ret == '#')
		printf("电脑赢了\n");
	else if (ret == 'A')
		printf("平局\n");
	printboard(arr, ROW, COL);



}


int main()
{

	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("请输入:");
		int a = 0;
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			game();
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;

		}
		if (a == 2)
			break;

	} while (1);



	return 0;
}