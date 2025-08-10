#define _CRT_SECURE_NO_WARNINGS

//Å£¿ÍÍø 1037
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int n, a = 0;
//	scanf("%d", &a);
//	n = sqrt(a);
//	printf("%d", n);
//	return 0;
//}

//1038
//#include <stdio.h>
//int main()
//
//{
//	int a, b, c, x = 1, y = 1, z = 1;
//	scanf("%d %d %d", &a, &b, &c);
//	while (1)
//	{
//		y = a / x;
//		z = b / x;
//		if (x * y == a && x * z == b && y * z == c)
//		{
//			break;
//		}
//		else
//		{
//			x++;
//		}
//	}
//	printf("%d\n", (x + y + z) * 4);
//	return 0;
//}

//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int n;
//	float a = 1, b = 1, c = 1;
//	scanf("%d", &n);
//	a = pow(n,1/3.0);
//	printf("%.3f", (a * 3));
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	long long n;
//	scanf("%lld", &n);
//	int p = 2, k = 1, max = 0;
//	while (1)
//	{
//		if (pow(p, k) < n)
//		{
//			k++;
//			continue;
//		}
//		if (pow(p, k) == n)
//		{
//			if (max < p + k)
//			{
//				max = p + k;
//			}
//			p++;
//			k = 1;
//			continue;
//		}
//		if (p >= n)
//		{
//			break;
//		}
//		if (pow(p, k) > n)
//		{
//			p++;
//			k = 1;
//			continue;
//		}
//	}
//	printf("%d", max);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	long long n;
//	scanf("%lld", &n);
//	printf("%lld", (n + 1));
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int n, x = 0;
//	scanf("%d", &n);
//	if (n % 2 == 0)
//	{
//		x = n / 2;
//	}
//	else
//	{
//		x = (n / 2) + 1;
//	}
//	printf("%d\n", x);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a, b, c, d, e, f;
//	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
//	int win = 0;
//	if (a >= e)
//	{
//		win += e;
//	}
//	else if (a < e)
//	{
//		win += a;
//	}
//	if (b >= f)
//	{
//		win += f;
//	}
//	else if (b < f)
//	{
//		win += b;
//	}
//	if (c >= d)
//	{
//		win += d;
//	}
//	else if (c < d)
//	{
//		win += c;
//	}
//	printf("%d", win);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	long long n, day = 0;
//	scanf("%lld", &n);
//	int num = n % 3;
//	if (num == 1 || num == 2)
//	{
//		day++;
//	}
//	day += (n / 3) * 2;
//	printf("%lld", day);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	float p, f;
//	int n;
//	scanf("%f %d", &p, &n);
//	switch(n)
//	{
//		case 1:
//		case 2:
//		case 3:
//		case 4:
//		case 5:
//			f = 1;
//			break;
//		case 6:
//		case 7:
//		case 8:
//		case 9:
//		case 10:
//			f = 0.99;
//			break;
//		case 11:
//		case 12:
//		case 13:
//		case 14:
//		case 15:
//		case 16:
//		case 17:
//		case 18:
//		case 19:
//		case 20:
//			f = 0.98;
//			break;
//		case 21:
//		case 22:
//		case 23:
//		case 24:
//		case 25:
//		case 26:
//		case 27:
//		case 28:
//		case 29:
//		case 30:
//			f = 0.96;
//			break;
//		default:
//			f = 0.94;
//			break;
//	}
//	printf("%.2f\n", (n * f * p));
//	return 0;
//}

