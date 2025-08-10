#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//int main()
//{
//	int x = 5;
//	scanf("%d", &x);
//	if (x-- < 5)
//		printf("%d", x);
//	else
//		printf("%d", x++);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	float time, wages;
//	while (scanf("%f %f", &time, &wages) != EOF)
//	{
//		if (time < 0 || time > 168)
//		{
//			printf("input is wrong!\n");
//		}
//		else if (time >= 0 && time <= 40)
//		{
//			printf("%g\n", time * wages);
//		}
//		else if (time > 40 && time <= 60)
//		{
//			printf("%g\n", ((40 * wages) + ((time - 40) * wages * 1.5)));
//		}
//		else
//		{
//			printf("%g\n", ((40 * wages) + (20 * wages * 1.5) + ((time - 60) * wages * 3)));
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
////判断闰年，如果是闰年返回1,否则返回0
//int run_year(int x)
//{
//	if (x % 4 == 0 && x % 100 != 0 || x % 400 == 0)
//	{
//		return 1;
//	}
//	return 0;
//}
////返回月份 - 1对应的天数
//int month_day(int month, int year)
//{
//	int add;
//	if (month == 1)
//	{
//		add = 0;
//	}
//	else if (month == 2)
//		add = 31;
//	else
//	{
//		add = 31 + 28 + run_year(year) + ((month - 3) * 31) - ((month - 3) / 2);
//	}
//	return add;
//}
//
//int main()
//{
//	int year, month, day, run = 0, all;
//	while (scanf("%d %d %d", &year, &month, &day) != EOF)
//	{
//		for (int i = 1; i < year; i++)
//		{
//			if (run_year(i))
//				run++;
//		}
//		all = run * 366 + ((year - run - 1) * 365) + month_day(month, year) + day;
//		//打印
//		switch (all % 7)
//		{
//		case 1:
//			printf("Monday\n");
//			break;
//		case 2:
//			printf("Tuesday\n");
//			break;
//		case 3:
//			printf("Wednesday\n");
//			break;
//		case 4:
//			printf("Thursday\n");
//			break;
//		case 5:
//			printf("Friday\n");
//			break;
//		case 6:
//			printf("Saturday\n");
//			break;
//		case 0:
//			printf("Sunday\n");
//			break;
//		}
//		run = 0;
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int num1, num2, answer;
//	char op;
//	while (scanf("%d%c%d", &num1, &op, &num2) != EOF)
//	{
//		if (op == '+')
//			answer = num1 + num2;
//		if (op == '-')
//			answer = num1 - num2;
//		if (op == '*')
//			answer = num1 * num2;
//		if (op == '/')
//			answer = num1 / num2;
//		printf("%d%c%d=%d\n", num1, op, num2, answer);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int n, add = 0;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			if (j == i)
//				continue;
//			for (int k = 1; k <= n; k++)
//			{
//				if (k == i ||k == j)
//				continue;
//				printf("A:%d B:%d C:%d\n", i, j, k);
//				add++;
//			}
//		}
//	}
//	printf("%d", add);
//	return 0;
//}

//#include <stdio.h>
////判断素数 是返回1
//int sushu(int x)
//{
//	for (int i = 2; i < x; i++)
//	{
//		if (x % i == 0)
//			return 0;
//	}
//	return 1;
//}
//
//int main()
//{
//	int n1, n2, time = 5;
//	scanf("%d %d", &n1, &n2);
//	for (int i = n1; i <= n2; i++)
//	{
//		if (sushu(i))
//		{
//			printf("%d ", i);
//			time--;
//		}
//		if (time == 0)
//		{
//			printf("\n");
//			time = 5;
//		}
//	}
//	return 0;
//}
//
//#include <stdio.h>
//int main()
//{
//	int a, b, c,money;//c是三只小鸡
//	for (a = 0; a <= 20; a++)
//	{
//		for (b = 0; b <= 33; b++)
//		{
//			for (c = 0; c <= 100; c++)
//			{
//				if ((a + b + 3 * c) == 100 && (5 * a + 3 * b + c) == 100)
//				{
//					printf("公鸡：%d 母鸡：%d 小鸡：%d\n", a, b, 3 * c);
//				}
//			}
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	float f, c;
//	scanf("%f", &f);
//	c = ((f - 32) * 5 / 9);
//	printf("%.3f", c);
//	return 0;
//}

