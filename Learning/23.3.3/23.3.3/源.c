                          #define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//int main()
//{
//	int n, a[26] = { 0 }, d;
//	char arr[102], list[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
//	scanf("%d %s", &n, arr);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < 26; j++)
//		{
//			if (arr[i] == list[j])
//			{
//				a[j]++;
//				break;
//			}
//		}
//	}
//	int max = 0, p = 0;
//	for (int i = 0; i < 26; i++)
//	{
//		if (a[i] > max)
//		{
//			max = a[i];
//			p = i;
//		}
//	}
//	printf("%c\n", list[p]);
//	return 0;
//}

//#include<stdio.h>
//void swop(int arr[], int n) //从大到小选择排序
//{
//	int t;
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			if (arr[i] < arr[j])
//			{
//				t = arr[i];
//				arr[i] = arr[j];
//				arr[j] = t;
//			}
//		}
//	}
//}
//int find(int arr[], int key, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		if (arr[i] == key)
//		{
//			return i + 1; //返回名次
//		}
//		if (arr[i] < key)
//		{
//			return 0;
//		}
//	}
//}
//int main()
//{
//	int n, arr[51], key;
//	while(~scanf("%d", &n))
//	{
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d", &arr[i]);
//		}
//		swop(arr, n);
//		for (int i = 0; i < n; i++)
//		{
//			if (i == n - 1)
//			{
//				printf("%d\n", arr[i]);
//			}
//			else if (i % 10 != 9)
//			{
//				printf("%d ",arr[i]);
//			}
//			else
//			{
//				printf("%d\n", arr[i]);
//			}
//		}
//		scanf("%d", &key);
//		if (find(arr, key, n) == 0)
//		{
//			printf("no this score!\n");
//		}
//		else
//		{
//			printf("%d\n", find(arr, key, n));
//		}
//	}
//	return 0;
//}