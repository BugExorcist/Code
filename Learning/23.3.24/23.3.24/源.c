#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//int main()
//{
//	float b, i, x;//本金 利息 t
//	int year;
//	scanf("%f %d", &b, &year);
//	switch (year)
//	{
//	case 1:
//		i = b * 300;
//		break;
//	case 2:
//		i = b * 330;
//		break;
//	case 3:
//		i = b * 380; 
//		break;
//	case 4:
//		i = b * 400;
//		break;
//	default:
//		i = b * 420;
//		break;
//	}
//	x = b * 10000 + i;
//	printf("interest=%.2f, total=%.2f\n", i/10000.0, x/10000.0);
//	return 0;
//}
 
 
#include<stdio.h>
//int main()
//{
//	double b, i, x;//本金 利息 t
//	int year;
//	scanf("%lf %d", &b, &year);
//	switch (year)
//	{
//	case 1:
//		i = b * 300;
//		break;
//	case 2:
//		i = b * 330;
//		break;
//	case 3:
//		i = b * 380;
//		break;
//	case 4:
//		i = b * 400;
//		break;
//	default:
//		i = b * 420;
//		break;
//	}
//	printf("%f\n", i);
//	x = (b * 10000) + i;
//	printf("interest=%.2lf, total=%.2lf\n", i / 10000.0, x / 10000.0);
//	return 0;
//}
//int main()
//{
//	double b, y;
//	scanf("%lf %lf", &b, &y);
//	double sum = 0, interest = 0;
//	if (y == 1)
//	{
//		sum += b * 1.03;
//	}
//	if (y == 2)
//	{
//		sum += (b * 1.033) * 1.033;
//	}
//	if (y == 3)
//	{
//		sum += b * 1.038 * 1.038 * 1.038;
//	}
//	if (y == 4)
//	{
//		sum += b * 1.04 * 1.04 * 1.04 * 1.04;
//	}
//	if (y >= 5)
//	{
//		double ans = b, res = 0;
//		while (y--)
//		{
//			ans *= 1.042;
//		}
//		res = ans - b;
//		printf("interest=%.2lf, total=%.2lf", res, ans);
//		return 0;
//	}
//	interest = sum - b;
//	printf("interest=%.2lf, total=%.2lf", interest, sum);
//	return 0;
//}

//#include <stdio.h>
//#include<string.h>
//void Print(int x)
//{
//	if (x >= 90)
//	{
//		printf("VERY_SECURE\n");
//	}
//	else if (x >= 80)
//	{
//		printf("SECURE\n");
//	}
//	else if (x >= 70)
//	{
//		printf("VERY_STRONG\n");
//	}
//	else if (x >= 60)
//	{
//		printf("STRONG\n");
//	}
//	else if (x >= 50)
//	{
//		printf("AVERAGE\n");
//	}
//	else if (x >= 25)
//	{
//		printf("WEAK\n");
//	}
//	else
//	{
//		printf("VERY_WEAK\n");
//	}
//}
//int main()
//{
//	int score = 0;
//	char arr[50];
//	scanf("%s", &arr);
//	int len = strlen(arr);
//	if (len <= 4)//密码长度
//	{
//		score += 5;
//	}
//	else if (len >= 8)
//	{
//		score += 25;
//	}
//	else
//	{
//		score += 10;
//	}
//	int z1 = 0, z2 = 0, n1 = 0, f1 = 0;
//	for (int i = 0; i < len; i++)
//	{
//		if (arr[i] >= 'a' && arr[i] <= 'z')
//		{
//			z1 = 1;
//		}
//		else if (arr[i] >= 'A' && arr[i] <= 'Z')
//		{
//			z2 = 1;
//		}
//		else if (arr[i] >= '0' && arr[i] <= '9')
//		{
//			n1++;
//		}
//		else
//		{
//			f1++;
//		}
//	}
//	score += (z1 + z2) * 10;//字母
//	if (n1 == 1)//数字
//	{
//		score += 10;
//	}
//	else if (n1 > 1)
//	{
//		score += 20;
//	}
//	if (f1 == 1)//符号
//	{
//		score += 10;
//	}
//	else if (f1 > 1)
//	{
//		score += 25;
//	}
//	奖励
//	if (z1 == 1 && z2 == 1 && n1 >= 1 && f1 >= 1)
//	{
//		score += 5;
//	}
//	if (z1 == 1 && n1 >= 1 && f1 >= 1 || z2 == 1 && n1 >= 1 && f1 >= 1)
//	{
//		score += 3;
//	}
//	if (z1 == 1 && n1 >= 1 || z2 == 1 && n1 >= 1)
//	{
//		score += 2;
//	}
//	Print(score);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int n, k;
//	while (scanf("%d", &n) != EOF)
//	{
//		if (n == 0)
//		{
//			printf("1\n");
//			continue;
//		}
//		k = n % 4;
//		switch (k)
//		{
//		case 0:
//			printf("6\n");
//			break;
//		case 1:
//			printf("2\n");
//			break;
//		case 2:
//			printf("4\n");
//			break;
//		case 3:
//			printf("8\n");
//			break;
//		}
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char m;
//	int min, hou;
//	scanf("%d%c%d", &hou, &m, &min);
//	if (hou >= 0 && hou <= 11)
//	{
//		printf("%d:%d AM", hou, min);
//	}
//	else
//	{
//		printf("%d:%d PM", hou - 12, min);
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char list[10] = { '0','1','2','3','4','5','6','7','8','9' };
//	char arr[50];
//	while (scanf("%s", &arr) != EOF)
//	{
//		int count[10] = { 0 };
//		int len = strlen(arr);
//		for (int i = 0; i < len; i++)
//		{
//			if (arr[i] >= '0' && arr[i] <= '9')
//			{
//				for (int j = 0; j < 10; j++)
//				{
//					if (arr[i] == list[j])
//					{
//						count[j]++;
//					}
//				}
//			}
//		}
//		for (int i = 0; i < 10; i++)
//		{
//			if (count[i] != 0)
//			{
//				printf("%c:%d\n", list[i], count[i]);
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr[50];
//	scanf("%s", &arr);
//	int len = strlen(arr);
//	for (int i = 0; i < len; i++)
//	{
//		if (arr[i] == '-')
//		{
//			printf("fu");
//		}
//		if (arr[i] == '0')
//		{
//			printf("ling");
//		}
//		if (arr[i] == '1')
//		{
//			printf("yi");
//		}
//		if (arr[i] == '2')
//		{
//			printf("er");
//		}
//		if (arr[i] == '3')
//		{
//			printf("san");
//		}
//		if (arr[i] == '4')
//		{
//			printf("si");
//		}
//		if (arr[i] == '5')
//		{
//			printf("wu");
//		}
//		if (arr[i] == '6')
//		{
//			printf("liu");
//		}
//		if (arr[i] == '7')
//		{
//			printf("qi");
//		}
//		if (arr[i] == '8')
//		{
//			printf("ba");
//		}
//		if (arr[i] == '9')
//		{
//			printf("jiu");
//		}
//		if (i != len - 1)
//		{
//			printf(" ");
//		}
//	}
//	printf("\n");
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int n;
//	float d = 1, p;
//	while (~scanf("%d", &n))
//	{
//		if (n >= 5000)
//		{
//			d = 0.8;
//		}
//		else if (n >= 3000)
//		{
//			d = 0.85;
//		}
//		else if (n >= 2000)
//		{
//			d = 0.9;
//		}
//		else if (n >= 1000)
//		{
//			d = 0.95;
//		}
//		printf("discount=%g,pay=%g\n", d, n * d);
//	}
//	return 0;
//}

//#include<stdio.h>
//struct student
//{
//	int ID;
//	char name[20];
//	float c;
//}arr[50],tmp;
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d%s%f", &arr[i].ID ,&arr[i].name ,&arr[i].c );
//	}
//	for (int i = n - 1; i > 0; i--)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (arr[j].c < arr[j + 1].c)
//			{
//				tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d %s %g\n", arr[i].ID, arr[i].name, arr[i].c);
//	}
//	return 0;
//}

//#include<stdio.h>
//#define PI 3.14159
//
//int main()
//{
//	float r, h;
//	scanf("%f %f", &r, &h);
//	printf("radius:%.3f\n", r);
//	printf("high:%.3f\n", h);
//	printf("The volume is:%.3f\n", PI * r * r * h);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int n, a, b, c;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d%d%d", &a, &b, &c);
//		if (a >= 0 && b >= 0 && c < 0 || a < 0 && b < 0 && c >= 0)
//		{
//			printf("Case #%d: true\n", i + 1);
//		}
//		else if (a >= 0 && b >= 0 && c >= 0 || a < 0 && b < 0 && c < 0)
//		{
//			if (b > c - a)
//			{
//				printf("Case #%d: true\n", i + 1);
//			}
//			else
//			{
//				printf("Case #%d: false\n", i + 1);
//			}
//		}
//		else
//		{
//			if (a + b > c)
//			{
//				printf("Case #%d: true\n", i + 1);
//			}
//			else
//			{
//				printf("Case #%d: false\n", i + 1);
//			}
//		}
//	}
//	return 0;
//}


//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	double a, b, c, tmp;
//	scanf("%lf %lf %lf", &a, &b, &c);
//	if (a > b)
//	{
//		tmp = a; a = b; b = tmp;
//	}
//	if (a > c)
//	{
//		tmp = a; a = c; c = tmp;
//	}
//	if (b > c)
//	{
//		tmp = b; b = c; c = tmp;
//	}
//	if (a + b <= c)
//	{
//		printf("This isn’t a triangle.\n");
//	}
//	else
//	{
//		if (a * a + b * b == c * c)
//		{
//			printf("This is a Right triangle.\n");
//		}
//		else if (c * c > a * a + b * b)
//		{
//			printf("This is a Obtuse triangle.\n");
//		}
//		else
//		{
//			printf("This is a Acute triangle.\n");
//		}
//		double p = (a + b + c) / 2;
//		double S = sqrt(p * (p - a) * (p - b) * (p - c));
//		printf("Area=%.3lf\n", S);
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int T,all =0,x ,y;
//	scanf("%d", &T);
//	while (T--)
//	{
//		scanf("%d%d", &x, &y);
//		all -= y;
//		if (all < 0)
//		{
//			all = 0;
//		}
//		all += x;
//	}
//	printf("%d\n", all);
//	return 0;
//}

//#include <stdio.h>
//#include<math.h>
//int main()
//{
//	double h, all = 0, l;
//	scanf("%lf", &h);
//	all += h;
//	for (int i = 1; i < 10; i++)
//	{
//		all += 2 * (h * pow(0.5, i));
//	}
//	l = h * pow(0.5, 10);
//	printf("%g\n%g\n", all, l);
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//struct xuanju
//{
//	char a[10];
//	int count;
//}arr[3];
//
//void toupiao(struct xuanju stu[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%s", &stu[i].a);
//	}
//}
//void jishu(struct xuanju stu[], int n)
//{
//	for (int i = 0; i < 5; i++)
//	{
//		char tmp[50];
//		scanf("%s", &tmp);
//		if (strcmp(tmp, "Li") == 0)
//		{
//			stu[0].count ++;
//		}
//		else if (strcmp(tmp, "Sun") == 0)
//		{
//			stu[2].count++;
//		}
//		else
//		{
//			stu[1].count++;
//		}
//	}
//}
//int main()
//{
//	int n = 5;
//	for (int i = 0; i < 3; i++)
//	{
//		arr[i].count = 0;
//	}
//	jishu(arr, n);
//	printf("LI:%d\nZhang:%d\nSun:%d\n", arr[0].count ,arr[1].count ,arr[2].count );
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int n;
//	int arr[21][21];
//	while (scanf("%d", &n) != EOF)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j <= i; j++)
//			{
//				if (j == 0 || j == i)
//				{
//					arr[i][j] = 1;
//					continue;
//				}
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j <= i; j++)
//			{
//				if (j == i)
//				{
//					printf("%d\n", arr[i][j]);
//					continue;
//				}
//				printf("%d ", arr[i][j]);
//			}
//		}
//	}
//	return 0;
//}

