#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//int main()
//{
//	int n, i, arr[2002] = { 0 };
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int a, j, times = 0;
//	for (j = n; j > 1; j--)
//	{
//		for (i = 1; i < n; i++)
//		{
//			if (arr[i] > arr[i + 1])
//			{
//				a = arr[i];
//				arr[i] = arr[i + 1];
//				arr[i + 1] = a;
//				times+= 1;
//			}
//		}
//	}
//	printf("%d\n",times);
//	return 0;
//}

//#include<stdio.h>
//long long arr[100005];
//long long add(int x, int y, long long k)
//{
//	for (int i = x; i <= y; i++)
//	{
//		arr[i] += k;
//	}
//	return 0;
//}
//long long sum(int x, int y)
//{
//	long long ad = 0;
//	for (int i = x; i <= y; i++)
//	{
//		ad += arr[i];
//	}
//	return ad;
//}
//long long max(int x, int y)
//{
//	long long m = arr[x];
//	for (int i = x; i <= y; i++)
//	{
//		if (m < arr[i])
//		{
//			m = arr[i];
//		}
//	}
//	return m;
//}
//int main()
//{
//	int m, n;
//	scanf("%d %d", &n, &m);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	while (m--)
//	{
//		long long a, k; int x, y;
//		scanf("%lld %lld %lld", &a, &x, &y);
//		if (a == 1) {
//			scanf("%lld", &k);
//			add(x, y, k);
//		}
//		else if (a == 2)
//		{
//			long long dd = sum(x, y);
//			printf("%lld\n", dd);
//		}
//		else if (a == 3)
//		{
//			long long xc = max(x, y);
//			printf("%lld\n", xc);
//		}
//	}
//	return 0;
//}
//
//#include<stdio.h>
//int arr[1000006];
//int main()
//{
//	int n, i, b;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		scanf("%d", &b);
//		arr[b]++;
//	}
//	for (i = 1; i <= 1000000; i++)
//	{
//		if (arr[i] == 0)
//			continue;
//			while (arr[i]--)
//			printf("%d ", i);
//	}
//	return 0;
//}

////´óÐ¡Ð´»¥»»
//#include<stdio.h>
//#include <string.h>
//int main()
//{
//	char s[101] = { 0 };
//	scanf("%s", &s);
//	int siz = strlen( s );
//	for (int i = 0; i < siz; i++)
//	{
//		if(s[i]>=65 && s[i] <= 90)
//		printf("%c", (s[i] + 32));
//		else if (s[i] >= 97 && s[i] <= 122)
//		printf("%c", (s[i] - 32));
//		else
//		printf("%c", s[i]);
//	}
//	printf("\n");
//	return 0;
//}

/*
#include<stdio.h>
#include<string.h>
int main()
{
	int t = 0, add = 0;
	char arr[100005] = { 0 };
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", &arr);
		for (int i = 0; i < strlen(arr); i++)
		{
			if (arr[i] == 120)
			{
				if (arr[i + 1] == 121)
				{
					add += 1;
					i += 1;
				}

			}
			else if (arr[i] == 121)
			{
				if (arr[i + 1] == 120)
				{
					add += 1;
					i += 1;
				}

			}
		}
		printf("%d\n", add);
		add = 0;
	}
	return 0;
}
*/

#include<stdio.h>
struct student
{
	int No;
	char name[15];
	char ID[10];
	int age;
};
struct student a[55];
struct student b;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i].No);
		scanf("%s", &a[i].name);
		scanf("%s", &a[i].ID);
		scanf("%d", &a[i].age);
	}
	for (int i = n; i > 1; i--)
	{
		for (int j = 1; j < i; j++)
		{
			if (a[j].No > a[j + 1].No)
			{
				b = a[j];
				a[j] = a[j + 1];
				a[j + 1] = b;
			}
		}
	}
	for (int i = 1 ; i <= n; i++)
	{
		printf("%d ", a[i].No);
		printf("%s ", a[i].name);
		printf("%s ", a[i].ID);
		printf("%d\n",a[i].age);
	}
	return 0;
}

