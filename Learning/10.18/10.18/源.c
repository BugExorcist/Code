#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int C(int n, int r)
//{
//	if (r == 0)
//		return 1;
//	else
//	return C(n, r - 1) * (n - r + 1) / r;
//}
//int main()
//{
//	int n, r, add;
//	while (scanf("%d %d", &n, &r) != EOF)
//	{
//		if (r == 0 && n == 0)
//		{
//			return 0;
//		}
//		else if (n < r)
//		{
//			printf("error!\n");
//		}
//		else
//		{
//			printf("%d\n", C(n,r));
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//int han(int x, int y)
//{
//	return x - y;
//}
//int main()
//{
//	int h, u, d;
//	while (scanf("%d %d %d", &h, &u, &d) != EOF)
//	{
//		int add = 0, time = 0;
//		if (h == 0 && u == 0 && d == 0)
//		{
//			return 0;
//		}
//		else
//		{
//			while ((add + u) < h)
//			{
//				add += han(u, d);
//				time += 2;
//			}
//			if (add < h)
//				time++;
//		}
//		printf("%d\n", time);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int n, add = 1;
//	scanf("%d", &n);
//	if (n == 0)
//	{
//		printf("1\n");
//		return 0;
//	}
//	for (int i = n; i > 0; i--)
//	{
//		add *= i;
//	}
//	printf("%d\n", add);
//	return 0;
//}

//#include <stdio.h>
/*暴力写法

//输入 一个数字
//返回 这个数字的最大奇因数
int fn(int x)
{
	if (x % 2)
	{
		return x;
	}
	else
	{
		return fn(x / 2);
	}
}
int main()
{
	int n;
		while (scanf("%d", &n) != EOF)
		{
			long long gn = 0;
			for (int i = 1; i <= n; i++)
			{
				gn += fn(i);
			}
			printf("%lld\n", gn);
		}
	return 0;
}
*/

//#include <stdio.h>
//long long fn(long long n)
//{
//	if (n == 0)
//	{
//		return 0;
//	}
//	else if (n % 2 != 0)
//	{
//		return (n + 1) * (n + 1) / 4 + fn(n / 2);
//	}
//	else
//	{
//		return n * n / 4 + fn(n / 2);
//	}
//}
//int main()
//{
//	long long n;
//	while (scanf("%lld", &n) != EOF)
//	{
//		printf("%lld\n", fn(n));
//	}
//	return 0;
//}

#include <stdio.h>
int main()
{

	printf("aa3456789\n");
	printf("bb3456789\r\n");
	printf("cc3456789");
	printf("dd3456789\r");


	return 0;
}