#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//输入 去之后剩下的数量
//返回 去之前的数量
int 哼哼哼啊啊啊啊啊啊啊啊(int num)
{
	int add = (num + 1) * 2;
	return add;
}
int main()
{
	int time, num;
	scanf("%d %d", &time, &num);
	while(time--)
	{
		num = 哼哼哼啊啊啊啊啊啊啊啊(num);
	}
	printf("%d", num);
	return 0;
}