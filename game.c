#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void kong(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			arr[i][j] = ' ';
		}
	}


}

void printboard(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int n = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}

void playermove(char arr[ROW][COL], int row, int col)
{
	while (1)
	{
		printf("玩家下棋\n");
		printf("请输入坐标:");
		int i = 0;
		int j = 0;
		scanf("%d %d", &i, &j);
		if (i >= 1 && i <= row && j >= 1 && j <= col)
		{
			if (arr[i - 1][j - 1] == ' ')
			{
				arr[i - 1][j - 1] = '*';
				break;
			}
			else
				printf("坐标被占用，请重新输入\n");
		}
		else
			printf("输入非法，请重新输入\n");

	}


}

void commove(char arr[ROW][COL], int row, int col)
{
	printf("电脑下棋\n");
	while (1)
	{
		int i = rand() % row;
		int j = rand() % col;
		if (arr[i][j] == ' ')
		{
			arr[i][j] = '#';
			break;
		}
	}   
}


char iswin(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ')
			return arr[i][0];
	}
	for (j = 0; j < col; j++)
	{
		if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j] && arr[0][j] != ' ')
			return arr[0][j];
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ')
		return arr[0][0];
	if (arr[3][1] == arr[2][2] && arr[2][2] == arr[1][3] && arr[1][3] != ' ')
		return arr[3][1];
	int ret = isfull(arr, ROW, COL);

	if (ret == 1)
	{
		return 'A';
	}
	else if (ret == 0)
	{
		return 'B';
	}


}
int isfull(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			arr[i][j] == ' ';
			return 0;
		}
		return 1;
	}
}