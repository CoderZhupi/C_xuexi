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
	//��������
	char arr[ROW][COL];
	//����ո�
	kong(arr, ROW, COL);
	//��ӡ���
	printboard(arr, ROW, COL);
	while (1)
	{
		//�������
		playermove(arr, ROW, COL);
		printboard(arr, ROW, COL);
		ret = iswin(arr, ROW, COL);
		if (ret != 'B')
			break;
		//��������
		commove(arr, ROW, COL);
		printboard(arr, ROW, COL);
		ret = iswin(arr, ROW, COL);
		if (ret != 'B')
			break;

	}
	if (ret == '*')
		printf("���Ӯ��\n");
	else if (ret == '#')
		printf("����Ӯ��\n");
	else if (ret == 'A')
		printf("ƽ��\n");
	printboard(arr, ROW, COL);



}


int main()
{

	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("������:");
		int a = 0;
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			game();
			break;
		case 2:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;

		}
		if (a == 2)
			break;

	} while (1);



	return 0;
}