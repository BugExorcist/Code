#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	int a = 0,b = 0,c = 0;
//	scanf("%d %d", &a, &b);
//	c = a + b;
//	printf("%d\n", c);
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	int a = 0, b = 0, c = 0,d = 0;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a < b)
//		a = b;
//	if (a < c)
//		a = c;
//	printf("%d", a);
//	return 0;
//}

//#include <stdio.h>
//int Gn(int x)
//{
//	int i = 0, k = 0;
//	for (i = 1; i <= x; i++) {
//		if ((x % i == 0) && (i % 2 != 0))
//			k = i;
//			}
//	return k;
//}
//int main()
//{
//	int a = 0, b = 0, c = 0,d = 0;
//	scanf("%d", &a);
//	for (b = 1; b <= a; b++) {
//		d = Gn(b);
//		c = c + d;
//		}
//	printf("%d\n", c);
//	return 0;
//}

//±©Á¦½â·¨
//#include<stdio.h>
//int g(int x)
//{
//int i = 0, k = 0;
//for (i = 1; i <= x; i++) {
//	if ((x % i == 0) && (i % 2 != 0))
//		k = i;
//}
//return k;
//}
//int main()
//{
//	int a = 0, b = 0, c = 0;
//while (scanf("%d", &a) != EOF) {
//	for (b = 1; b <= a; b++) {
//		c = c + g(b);
//	}
//	printf("%d\n", c);
//	c = 0;
//}
//return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char a ,b;
//	a=getchar();
//	b = a - 32;
//	printf("%c\n", b);
//	
//	return 0;
//}


//#include<stdio.h>
//int g(int x)
//{
//	while (x % 2 == 0) {
//			x = x / 2;
//	}
//	return x;
//}
//int main()
//{
//	int a = 0, b = 0, c = 0;
//	while (scanf("%d", &a) != EOF) {
//		for (b = 1; b <= a; b++) {
//			c = c + g(b);
//		}
//		printf("%d\n", c);
//		c = 0;
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	while (a <= 100)
//	{
//		if (a % 2 == 1)
//		{
//			printf("%d ", a);
//		}
//		a++;
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a;
//	while ((a = getchar()) != EOF)
//	{
//		if (a >= 97 && a <= 122)
//		{
//			putchar(a - 32);
//			printf("\n");
//		}
//	}
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	double b = 0, c = 0;
//	scanf("%d", &a);
//	while (a--)
//	{
//		scanf("%lf %lf", &b, &c);
//		printf("%lf\n", b - c);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	if (n == 0)
//		printf("123456\n");
//	else if (n == 1)
//		printf("789101112\n");
//	else if (n == 2)
//		printf("131415161718\n");
//	else if (n == 3)
//		printf("192021222324\n");
//	else if (n == 4)
//		printf("252627282930\n");
//	else if (n == 5)
//		printf("313233343536\n");
//	else if (n == 6)
//		printf("373839404142\n");
//	else if (n == 7)
//		printf("434445464748\n");
//	else if (n == 8)
//		printf("495051525354\n");
//	else if (n == 9)
//		printf("555657585960\n");
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	long long a = 0;
//	scanf("%lld", &a);
//	if (a % 2 == 0)
//	{
//		printf("2");
//		if (a % 3 == 0)
//		{
//			printf(" 3");
//			if (a % 5 == 0)
//			{
//				printf(" 5");
//			}
//		}
//		else if (a % 5 == 0)
//		{
//			printf(" 5");
//		}
//	}
//	else if (a % 3 == 0)
//	{
//		printf("3");
//		if (a % 5 == 0)
//		{
//			printf(" 5");
//		}
//	}
//	else if(a % 5 == 0)
//	{
//		printf("5");
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a, b, c, d, e;
//	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
//		if (c > a && c > b)
//			printf("YES\n");
//		else
//			printf("NO\n");
//		if(c>a||c>b)
//			printf("YES\n");
//		else
//			printf("NO\n");
//		if(d!=e)
//			printf("YES\n");
//		else
//			printf("NO\n");
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a, b, c;
//	scanf("%d", & a);
//	while (a--)
//	{
//		scanf("%d", &b);
//		while (b--)
//		{
//			c = b+1;
//			while (c--)
//			{
//				printf("X");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//int a = 0, b = 0, c = 0,d = 0;
//scanf("%d", &a);
//while (a--)
//{
//	scanf("%d", &b);
//	while (b--)
//	{
//		scanf("%d", &c);
//		d = d + c;
//	}
//	printf("%d\n", d);
//	d = 0;
//}
//return 0;
//}


//#include<stdio.h>
//int main()
//{
//	long long sum = 0, n = 0, a = 0, b = 0;
//	scanf("%lld", &sum);
//	while (sum--)
//	{
//		scanf("%lld %lld %lld", &n, &a, &b);
//			if (n % 2 == 0)
//			{
//				if (b / 2 < a)
//				{
//					printf("%lld\n",( n / 2 * b));
//				}
//				else if(b / 2 >= a)
//				{
//					printf("%lld\n", (n * a));
//				}
//			}
//			else if (n % 2 != 0)
//			{
//				if (b / 2 < a)
//				{
//					printf("%lld\n",( (n - 1) / 2 * b + a));
//				}
//				else if(b / 2 >= a)
//				{
//					printf("%lld\n", (n * a));
//				}
//			}
//	}
//	return 0;
//}

//
//#include<stdio.h>
//int main(){
//	int a = 0, b = 0;
//	while (scanf("%d %d", &a, &b) != EOF)
//	if (a >= (30 * b))
//		printf("YES\n");
//	else
//		printf("NO\n");
//	return 0;
//}

//#include<stdio.h>
//int main() {
//	int a, b, n, sum = 0, x, t, i;
//	scanf("%d", &a);
//	while (a--)
//	{
//		scanf("%d %d", &n, &t);
//		int arr[100005] = { 0 };
//		for (i = 0; i < n; i++)
//		{
//			scanf("%d", &arr[i]);
//		}
//		while (t--)
//		{
//			scanf("%d", &x);
//			for (i = 0; i < n; i++)
//			{
//				if (x == arr[i])
//				{
//					sum += 1;
//				}
//			}
//			printf("%d\n", sum);
//			sum = 0;
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int n, s[555], i, t, a, b, c;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		scanf("%d", &s[i]);
//	}
//	scanf("%d", &t);
//	while (t--)
//	{
//		scanf("%d %d %d", &a, &b, &c);
//		if(s[a] > c)
//		{
//			s[a] -= c;
//			s[b] += c;
//		}
//		else
//		{
//			s[b] += s[a];
//			s[a] = 0;
//		}
//	}
//	for (i = 1; i <= n; i++)
//	{
//		printf("%d ", s[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int n, m, arr[251][251], i, j ,x ,y;
//	scanf("%d %d", &n, &m);
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	scanf("%d %d", &x, &y);
//	for (i = 0; i < m; i++)
//		printf("%d ", arr[x-1][i]);
//		printf("\n");
//		for (i = 0; i < n; i++)
//			printf("%d ", arr[i][y-1]);
//		printf("\n");
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int m, n, i, j, arr[1003][1003];
//	scanf("%d %d", &m, &n);
//	for (i = 1; i <= m; i++)
//	{
//		for (j = 1; j <= n; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	for (j = 1; j <= n; j++)
//	{
//		for (i = 1; i <= m; i++)
//		{
//			printf("%d ",arr[j][i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}