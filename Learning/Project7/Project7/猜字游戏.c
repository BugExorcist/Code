#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void menu()
{
	printf("****** 猜一个1 - 100之间的数字******\n");
	printf("******        1. play         ******\n");
	printf("******        0. exit         ******\n");
	printf("************************************\n");
}
void game()
{
	printf("请输入一个数字:>");
	int key;
	int a = rand() % 100 + 1;//设置随机数
	while (1)
	{
		scanf("%d", &key);
		if (key > a) {
			printf("猜大了\n");
			continue;
		}
		if (key < a) {
			printf("猜小了\n");
			continue;
		}
		if (key = a) {
			printf("恭喜你，猜对了\n");
			break;
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));//设置随机数起点
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
			printf("退出游戏\n");
			break;
		default:
			printf("清重新选择\n");
			break;
		}

	} while (choice);
	return 0;
}