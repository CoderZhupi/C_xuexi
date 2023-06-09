#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("****************** 1.play ********************\n");
	printf("****************** 0.exit ********************\n");
}
void Intiboard(char board[ROWS][COLS], int rows, int cols, char set)
{

	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void displayboard(char board[ROWS][COLS], int row, int col)
{
	printf("---------------扫雷游戏--------------\n");
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void setMine(char board[ROWS][COLS], int row, int col)
{
	int count = 0;

	while (count < Count)
	{
		int i = rand() % row + 1;
		int j = rand() % col + 1;
		if (board[i][j] == '0')
		{
			board[i][j] = '1';
			count++;
		}
	}
}

void find(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	while (win < (row * col) - Count)
	{
		int i = 0;
		int j = 0;
		printf("请输入要排查的坐标=>");
		scanf("%d %d", &i, &j);
		if (i <= row && j <= col && i >= 1 && j >= 1)
		{
			if (mine[i][j] == '1')
			{
				displayboard(mine, ROW, COL);
				printf("游戏失败，您被炸死了\n");
				break;
			}
			else if (mine[i][j] = '0')
			{
				int count = get_mine_count(mine, i, j);
				show[i][j] = count + '0';
				displayboard(show, ROW, COL);
				win++;
			}
		}
		else
			printf("坐标输入错误，请重新输入\n");
	}
	if (win == (row * col) - Count)
	{
		displayboard(mine, ROW, COL);
		printf("恭喜你排查出所有的雷,获得了胜利\n");
	}
}

int get_mine_count(char mine[ROWS][COLS], int i, int j)
{
	return mine[i - 1][j - 1] +
		mine[i - 1][j] +
		mine[i - 1][j + 1] +
		mine[i][j - 1] +
		mine[i][j = 1] +
		mine[i + 1][j - 1] +
		mine[i + 1][j] +
		mine[i + 1][j + 1] - 8 * '0';
}