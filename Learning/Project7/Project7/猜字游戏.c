#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void menu()
{
	printf("****** ��һ��1 - 100֮�������******\n");
	printf("******        1. play         ******\n");
	printf("******        0. exit         ******\n");
	printf("************************************\n");
}
void game()
{
	printf("������һ������:>");
	int key;
	int a = rand() % 100 + 1;//���������
	while (1)
	{
		scanf("%d", &key);
		if (key > a) {
			printf("�´���\n");
			continue;
		}
		if (key < a) {
			printf("��С��\n");
			continue;
		}
		if (key = a) {
			printf("��ϲ�㣬�¶���\n");
			break;
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));//������������
	int choice;
	do
	{
		menu();
		scanf("%d", &choice);
		switch(choice)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("������ѡ��\n");
			break;
		}

	} while (choice);
	return 0;
}