#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//int xy(int x)
//{
//	if (x < 1)
//	{
//		return x;
//	}
//	else if(1 <= x && 10 >= x)
//	{
//		return 2 * x - 1;
//	}
//	else
//	{
//		return 3 * x - 11;
//	}
//}
//int main()
//{
//	int x;
//	scanf("%d", &x);
//	printf("%d\n", xy(x));
//	return 0;
//}

//#include <stdio.h>
//char get(int x)
//{
//	if (x >= 90)
//	{
//		return 'A';
//	}
//	else if (x >= 80 && x < 90)
//	{
//		return 'B';
//	}
//	else if (x >= 70 && x < 80)
//	{
//		return 'C';
//	}
//	else if (x >= 60 && x < 70)
//	{
//		return 'D';
//	}
//	else
//	{
//		return 'E';
//	}
//}
//int main()
//{
//	int x;
//	scanf("%d", &x);
//	printf("%c\n", get(x));
//	return 0;
//}

//#include<stdio.h>
//int fx(int n, int r)
//{
//	if (r == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return fx(n, r - 1) * (n - r + 1) / r;
//	}
//}
//int main()
//{
//	int n, r;
//	while (scanf("%d %d", &n, &r) != EOF)
//	{
//		if (n >= r)
//		{
//			if (n == 0 && r == 0)
//			{
//				return 0;
//			}
//			printf("%d\n", fx(n, r));
//		}
//		else
//		{
//			printf("error!\n");
//		}
//	}
//	return 0;
//}

////黑猫的牌面http://scpc.fun/problem/1016
//#include <stdio.h>
//int main()
//{
//	int arr[4][32] = { 0 }, n = 0, size = 0, list[130] = { 0 }, add = 0;
//	//size 表示list中数字的个数 add是需要加的牌数量
//	for (int i = 0; i < 4; i++)
//	{
//		scanf("%d", &n);
//		arr[i][0] = n;
//		for(int j = 1; j<= n; j++)
//		{
//			if (i == 0)
//			{
//				scanf("%d", &list[size]);
//				arr[i][j] = list[size];
//				size++;
//			}
//			else
//			{
//				scanf("%d", &arr[i][j]);
//				for (int k = 0; k < size; k++)
//				{
//					if (arr[i][j] == list[k])
//					{
//						break;
//					}
//					if (k == size - 1)
//					{
//						list[size] = arr[i][j];
//						size++;
//					}
//				}
//			}
//		}
//	}
//	for (int num = 0; num < 4; num++)
//	{
//		add += (size - arr[num][0]);
//	}
//	printf("%d\n", add);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char x;
//	scanf("%c", &x);
//	if (x >= 'c' && x <= 'l' || x >= 'C' && x <= 'L')
//	{
//		printf("To be precise, this seems to be the C problem of the warm-up match on the night of October 23, 2020.\n");
//	}
//	else
//	{
//		printf("Just this?\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int n, k, arr[102];
//	scanf("%d %d", &n, &k);
//	for (int i = 0; i< n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (int i = n- 1; i > 0; i--)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (arr[j] < arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//	int add = 0;
//	for (int i = 0; i < k; i++)
//	{
//		add += arr[i];
//	}
//	printf("%d\n", add);
//	return 0;
//}


//#include<stdio.h>
//#include<string.h>
//int ifzixulie(char* s, int m, char* t, int n)
//{
//	int i = 0, j = 0;
//	while (i < n)
//	{
//		if (s[j] == t[i])
//		{
//			i++;
//			j++;
//			if (i != n && j == m)
//				return 0;
//		}
//		else
//		{
//			j++;
//			if (j == m)
//				return 0;
//		}
//	}
//	return 1;
//}
//
//int main()
//{
//	char s[1000], t[1000];
//	int m, n;
//	scanf("%s", s);
//	scanf("%s", t);
//	m = strlen(s);
//	n = strlen(t);
//	if (ifzixulie(s, m, t, n) == 0)
//		printf("La revolt y victoria\n");
//	else
//		printf("Y estamos furiosos\n");
//}

//#include<stdio.h>
//#include<string.h>
//int main()
//{
//    char a[12] = { 'v','i','v','a','l','a','r','e','v','o','l','t' };
//    char s[10005];
//    scanf("%s", s);
//    int len = strlen(s);
//    int x = 0;
//    for (int i = 0; i < len; i++)
//    {
//        if (s[i] == a[x])
//        {
//            x++;
//        }
//        if (x == 12)
//        {
//            break;
//        }
//    }
//    if (x == 12)
//    {
//        printf("Y estamos furiosos");
//    }
//    else
//    {
//        printf("La revolt y victoria");
//    }
//}

//#include <stdio.h>
//
//int main()
//{
//	int n, l;
//	scanf("%d", &n);
//	while (n--)
//	{
//		scanf("%d", &l);
//		int arr[100005], re = 0;
//		for (int i = 0; i < l; i++)
//		{
//			scanf("%d", &arr[i]);
//		}
//		for (int i = 0; i < l; i++)
//		{
//			for (int j = i; j < l; j++)
//			{
//				if (i != j)
//				{
//					if (arr[i] == arr[j])
//					{
//						re++;
//						continue;
//					}
//				}
//			}
//		}
//		printf("%d\n", l-re);
//	}
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//    int T;
//    cin >> T;
//    while (T--) 
//    {
//        int n;
//        cin >> n;
//        int arr[10000]{ 0 };
//        for (int i = 0; i < n; i++)
//        {
//            cin >> arr[i];
//        }
//        sort(arr, arr + n);
//        int add = 0;
//        for (int i = 0; i < n; i++)
//        {
//            if (a[i] == n)
//            {
//                break;
//            }
//            if (a[i] != a[i + 1])
//            {
//                x++;
//            }
//
//        }
//        printf("%d\n", x);
//        x = 1;
//    }
//}

//#include<stdio.h>
//int main()
//{
//	int n,t = 2;
//	scanf("%d", &n);
//	if (n == 0)
//	{
//		printf("1\n");
//	}
//	else
//	{
//		while (t--)
//		{
//			printf("5");
//			for (int i = 0; i < n-1; i++)
//			{
//				printf("0");
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int n, i;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		int x, arr[50] = { 0 }, time = 0, key = 0, add = 0;
//		scanf("%d", &x);//x是一共断的次数
//		if (x == 0)//没断过
//		{
//			printf("60\n");
//		}
//		else//断过
//		{
//			for (int j = 0; j < x; j++)
//			{
//				scanf("%d", &arr[j]);
//			}
//			if (arr[x-1] + x * 3 < 60)//最后一次断后时间还在60秒之内
//			{
//				printf("%d\n", (60 - (x * 3)));
//			}
//			else
//			{
//				for (int k = 0; k < x; k++)
//				{//k+1 是断的次数
//					if (arr[k] + (k + 1) * 3 >= 60 && arr[k] + (k + 1) * 3 <= 62)//60秒时断了
//					{
//						add = arr[k];
//						printf("%d\n", add);
//						break;
//					}
//					else//60s时没断并且60s之后还在断
//					{
//						if (arr[k] + (k + 1) * 3 >62)
//						{
//							printf("%d\n", 60 - k * 3);
//						}
//					}
//				}
//			}
//			
//		}
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int m, n, arr[102], add = 0, t = 0;
//	scanf("%d %d", &m, &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (add + arr[i] > m)
//		{
//			break;
//		}
//		add += arr[i];
//		t++;
//	}
//	printf("%d\n", t);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 1; i < n; i++)
//	{
//		if (i % 7 == 0)
//			if (i % 6 == 5)
//				if (i % 5 == 4)
//					if (i % 3 == 2)
//						printf("%d\n", i);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include<string.h>
//struct P
//{
//	int n;
//}arr[3];
//int main()
//{
//	int t = 5;
//	char name[10];;
//	for (int i = 0; i < 3; i++)
//	{
//		arr[i].n = 0;
//	}
//	while (t--)
//	{
//		scanf("%s", name);
//		if (strcmp(name, "Li") == 0)
//		{
//			arr[0].n++;
//		}
//		else if (strcmp(name, "Sun") == 0)
//		{
//			arr[2].n++;
//		}
//		else
//		{
//			arr[1].n++;
//		}
//	}
//	printf("Li:%d\n", arr[0].n);
//	printf("Zhang:%d\n", arr[1].n);
//	printf("Sun:%d\n", arr[2].n);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a, b, n, a1, a2, a3 = 0, b1, b2, b3 = 0;
//	scanf("%d %d %d", &a, &b, &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
//		if (a2 == a1 + b1 && b2 == a1 + b1)
//		{
//			continue;
//		}
//		if (a2 == a1 + b1)
//		{
//			a3++;
//		}
//		if (b2 == a1 + b1)
//		{
//			b3++;
//		}
//		if (a3 > a)
//		{
//			printf("A\n");
//			printf("%d\n",b3);
//			break;
//		}
//		if (b3 > b)
//		{
//			printf("B\n");
//			printf("%d\n", a3);
//			break;
//		}
//	}
//	return 0;
//}