#define _CRT_SECURE_NO_WARNINGS 1

////选择语句
//#include <stdio.h>
//int main()
//{
//	int choice = 0;
//	printf("你要好好学习吗？\n");
//	printf("YES/NO>");
//	scanf("%c", &choice);
//	if (choice ="YES")
//		printf("走上人生巅峰");
//	else printf("回家种地");
//	return 0;
//}

//循环语句
//#include <stdio.h>
////while循环
//int main()
//{
//	int code = 0;
//	while (code < 30000)
//	{
//		code++;
//		printf("写第%d行代码\n",code);
//	}
//	if (code >= 30000)
//	{
//		printf("Nice job.\n");
//	}
//	return 0;
//}

//函数
#include<stdio.h>
//定义函数
int Add(int a, int b)
{
	int z = 0;
	z = a + b;
	return z;
}

int main()
{
	int a = 0, b = 0;
	printf("输入两个数字进行加法运算\n");
		scanf("%d %d", a,b);
		int sum = Add(a, b);
			printf("sum=%d\n",sum);

	return 0;
}
