#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include<string.h>
//int main()
//{
//	char arr[100];
//	while (~scanf("%s", arr))
//	{
//		int len = strlen(arr);
//		for (int i = 0; i < len; i++)
//		{
//			if (arr[i] >= 'a' && arr[i] <= 'y' || arr[i] >= 'A' && arr[i] <= 'Y')
//			{
//				printf("%c", (arr[i] + 1));
//			}
//			else if (arr[i] == 'z')
//			{
//				printf("a");
//			}
//			else if (arr[i] == 'Z')
//			{
//				printf("A");
//			}
//			else
//			{
//				printf("%c", arr[i]);
//			}
//		}
//		printf("\r\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//struct shuiwang
//{
//	char name[22];
//	int num;
//};
//int main()
//{
//	int n, a[103], x;
//	struct shuiwang all[103];
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%s %d", &all[i].name, &all[i].num);
//		a[i] = i;
//	}
//	
//	for (int i = n; i > 0; i--) //从大到小排序
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (all[j].num < all[j + 1].num)
//			{
//				all[102] = all[j];
//				all[j] = all[j + 1];
//				all[j + 1] = all[102];
//				x = a[i];
//				a[i] = a[i + 1];
//				a[i + 1] = x;
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)  //字典排序
//	{
//		while (all[i].num == all[i + 1].num)
//		{
//			if (strcmp(all[i].name, all[i + 1].name) > 0)
//			{
//				x = a[i];
//				a[i] = a[i + 1];
//				a[i + 1] = x;
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		printf("%s\n", all[a[i]].name);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a, b;
//	while (~scanf("%d %d", &a, &b))
//	{
//		printf("%d %d\n", sizeof(int), sizeof(char));
//		printf("%c %c\n", a, b);
//	}
//	return 0;
//}

//#include <stdio.h>
//int C(int n, int r)
//{
//	if (r == 0)
//		return 1;
//	else
//		return C(n, r - 1) * (n - r + 1) / r;
//}
//int main()
//{
//	int n, r, add;
//	while (scanf("%d %d", &n, &r) != EOF)
//	{
//		if (r == 0 && n == 0)
//		{
//			break;
//		}
//		else if (n < r)
//		{
//			printf("error!\n");
//		}
//		else
//		{
//			printf("%d\n", C(n, r));
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//int f(int x)
//{
//	if (x == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return (f(x - 1) + (x * x));
//	}
//}
//int main()
//{
//	int n;
//	while (~scanf("%d", &n))
//	{
//		printf("%d\n", f(n));
//	}
//
//	return 0;
//}

#include<stdio.h>
int f(int n)
{
	if (n == 1 || n == 0)
	{
		return 1;
	}
	else
	{
		return (n * f(n - 1));
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", f(n));
	return 0;
}