#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//int main()
//{
//	int num = 0, n2, arr[10000];
//	while (scanf("%d", &num) != EOF)
//	{
//		int i = 0, a = num;
//		while (a >= 2)
//		{
//			if (a >= 2)
//			{
//				arr[i] = (a % 2);
//				a = a / 2;
//				i++;
//			}
//		}
//		printf("%d", a);
//		for (int j = i - 1; j >= 0; j--)
//		{
//			printf("%d", arr[j]);
//		}
//		printf("\n%o\n", num);
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//    int min = 0, max = 0, num;
//    while (scanf("%d %d", &min, &max) != EOF)
//    {
//    num = 0;
//    for (int i = min; i <= max; i++)
//    {
//        if (i == 2)
//        {
//            num++;
//        }
//        else if (i > 2)
//        {
//            for (int j = 2; j <= i - 1; j++)
//            {
//                if (i % j == 0)
//                {
//                    break;
//                }
//                if (i - 1 == j)
//                {
//                    num++;
//                }
//            }
//        }
//    }
//    printf("%d\n",num);
//    }
//    return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int n, num, max, min;
//	scanf("%d", &n);
//	while (n--)
//	{
//		scanf("%d", &num);
//		if (num % 2 == 1)
//		{
//			printf("0 0\n");
//		}
//		else
//		{
//			if (num % 4 == 2)
//			{
//				printf("%d ", (num / 4 + 1));
//			}
//			else
//			{
//				printf("%d ", (num / 4));
//			}
//			printf("%d\n",(num / 2));
//		}
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int arr[10], h, num = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	scanf("%d", &h);
//	int max = h + 30;
//	for (int j = 0; j < 10; j++)
//	{
//		if (arr[j] <= max)
//		{
//			num++;
//		}
//	}
//	printf("%d\n", num);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		int num = 1;
//		int time = n - 1;
//		while (time--)
//		{
//			num = (num + 1) * 2;
//		}
//		printf("%d\n", num);
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int arr[1000] = { 0 };
//	scanf("%s", arr);
//	int len = strlen(arr);
//	for (int i = len - 1; i >= 0; i--)
//	{
//		printf("%c", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr[100] = { 0 };
//	scanf("%s", arr);
//	int len = strlen(arr);
//	for (int i = 0; i < len; i++)
//	{
//		if (arr[i] <=90)
//		{
//			printf("%c", (arr[i] + 32));
//		}
//		if (arr[i] >= 97)
//		{
//			printf("%c", (arr[i] - 32));
//		}
//	}
//	printf("\n");
//	return 0;
//}

//#include <stdio.h>
//#include<string.h>
//int main()
//{
//	char arr[1000] = { 0 };
//	scanf("%s", arr);
//	int len = strlen(arr);
//
//	for (int i = 0; i < len; i++)
//	{
//		if (arr[i] >= 'A' && arr[i] <= 'Z' || arr[i] >= 'a' && arr[i] <= 'z')
//		{
//			printf("%c", arr[i]);
//		}
//	}
//	printf("\n");
//	for (int i = 0; i < len; i++)
//	{
//		if (arr[i] >= '0' && arr[i] <= '9')
//		{
//			printf("%c", arr[i]);
//		}
//	}
//	printf("\n");
//	for (int i = 0; i < len; i++)
//	{
//		if (arr[i] >= 'A' && arr[i] <= 'Z' || arr[i] >= 'a' && arr[i] <= 'z' || arr[i] >= '0' && arr[i] <= '9')
//		{
//			continue;
//		}
//		else
//		{
//			printf("%c", arr[i]);
//		}
//	}
//	printf("\n");
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char s[300];
//	while (~scanf("%s", s))
//	{
//		int n;
//		n = strlen(s);
//		char abc[300] = { 0 }, num[300] = { 0 }, op[300] = { 0 };
//		int ab = 0, nu = 0, o = 0;
//		for (int i = 0; i < n; i++)
//		{
//			if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z')
//			{
//				abc[ab] = s[i];
//				ab++;
//			}
//			else if (s[i] >= '0' && s[i] <= '9')
//			{
//				num[nu] = s[i];
//				nu++;
//			}
//			else
//			{
//				op[o] = s[i];
//				o++;
//			}
//		}
//		printf("%s\n%s\n%s\n", abc, num, op);
//	}
//	return 0;
//}

#include <stdio.h>
int main()
{
	int n, arr[1004];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int temp;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	float add = 0;
	for (int i = 0; i < n; i++)
	{
		add += (arr[i] * (n - i ));
	}
	printf("%.2f\n", (add / n));
	return 0;
}
