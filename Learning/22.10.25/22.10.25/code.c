#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//int main()
//{
//	int arr1[3][3] = { 0 }, arr2[3][3] = { 0 }, arr3[3][3] = { 0 }, time = 0;
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			scanf("%d", &arr1[i][j]);
//		}
//
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			scanf("%d", &arr2[i][j]);
//		}
//
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			for (int t = 0; t < 3; t++)
//			{
//				arr3[i][j] += arr1[i][t] * arr2[t][j];
//			}
//		}
//
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			printf("%d ", arr3[i][j]);
//			time++;
//			if (time == 3)
//			{
//				printf("\n");
//				time = 0;
//			}
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int swap(char a[])
//{
//	if (strcmp(a, "one") == 0)
//		return 1;
//	if (strcmp(a, "two") == 0)
//		return 2;
//	if (strcmp(a, "three") == 0)
//		return 3;
//	if (strcmp(a, "four") == 0)
//		return 4;
//	if (strcmp(a, "five") == 0)
//		return 5;
//	if (strcmp(a, "six") == 0)
//		return 6;
//	if (strcmp(a, "seven") == 0)
//		return 7;
//	if (strcmp(a, "eight") == 0)
//		return 8;
//	if (strcmp(a, "nine") == 0)
//		return 9;
//	if (strcmp(a, "zero") == 0)
//		return 0;
//}
//int main()
//{
//	char a[25] = { 0 };
//	int num1, num2;
//	while (1)
//	{
//		scanf("%s", &a);
//		num1 = swap (a);
//		scanf("%s", &a);
//		if (strcmp(a, "+") != 0)
//		{
//			num1 = num1 * 10 + swap(a);
//			scanf("%s", &a);
//		}
//		scanf("%s", &a);
//		num2 = swap(a);
//		scanf("%s", &a);
//		if (strcmp(a, "=") != 0)
//		{
//			num2 = num2 * 10 + swap(a);
//			scanf("%s", &a);
//		}
//		if (num1 == 0 && num2 == 0)
//			return 0;
//		printf("%d\n", num1 + num2);
//	}
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	int n, b[26] = { 0 }, max_num, max = 0;
//	char arr[100] = { 0 }, a[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
//	scanf("%d %s", &n, &arr);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < 26; j++)
//		{
//			if (arr[i] == a[j])
//			{
//				b[j]++;
//				break;
//			}
//		}
//	}
//	for (int i = 0; i < 26; i++)
//	{
//		if (max < b[i])
//		{
//			max = b[i];
//			max_num = i;
//		}
//	}
//	printf("%c\n", a[max_num]);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int n, arr[50] = { 0 },enter = 0;
//	scanf("%d", &n);
//	for(int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = n - 2; j >= i; j--)
//		{
//			if (arr[j] < arr[j + 1])
//			{
//				int swap = arr[j + 1];
//				arr[j + 1] = arr[j];
//				arr[j] = swap;
//			}
//		}
//	}
//	int aim, no_ = 1, d = 0;
//	scanf("%d", &aim);
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//		enter++;
//		if (aim < arr[i])
//		{
//			no_++;
//		}
//		if (aim == arr[i])
//		{
//			d = 1;
//		}
//		if (enter == 10)
//		{
//			printf("\n");
//			enter = 0;
//		}
//	}
//	if (d == 1)
//	{
//		printf("\n%d\n", no_);
//	}
//	else if (d != 1)
//	{
//		printf("\nno this score!\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int n, arr[50] = { 0 }, enter = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = n - 2; j >= i; j--)
//		{
//			if (arr[j] < arr[j + 1])
//			{
//				int swap = arr[j + 1];
//				arr[j + 1] = arr[j];
//				arr[j] = swap;
//			}
//		}
//	}
//	int aim, no_ = 1, d = 0;
//	scanf("%d", &aim);
//	for (int i = 0; i < n; i++)
//	{
//		if (aim == arr[i])//判断aim存在
//		{
//			d = 1;
//		}
//		if (aim < arr[i])//计算名次
//		{
//			no_++;
//		}
//		if ((i + 1) % 10 == 0 || i == n - 1)
//		{
//			printf("%d\n", arr[i]);
//			continue;
//		}
//		printf("%d ", arr[i]);
//	}
//	if (d == 1)
//	{
//		printf("%d\n", no_);
//	}
//	else if (d != 1)
//	{
//		printf("no this score!\n");
//	}
//	return 0;
//}

#include<stdio.h>
int main()
{
	int n;

	return 0;
}