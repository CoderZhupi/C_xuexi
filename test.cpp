#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void game()
{
	//��������
	char Mine[ROWS][COLS] = { 0 };
	char Show[ROWS][COLS] = { 0 };
	//��ʼ������
	Intiboard(Mine, ROWS, COLS, '0');
	Intiboard(Show, ROWS, COLS, '*');
	//��ӡ����
	displayboard(Show, ROW, COL);
	//������
	setMine(Mine, ROW, COL);
	displayboard(Mine, ROW, COL);
	//�Ų���
	find(Mine, Show, ROW, COL);

}





int main()
{
	srand((unsigned int)time(NULL));
	int a = 0;
	do
	{
		menu();
		printf("������=>");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			game();
			break;
		case 0 :
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;

		}



	} while (a);



	return 0;
}
