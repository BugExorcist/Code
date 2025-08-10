#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//struct Student
//{
//	char ID[9];
//	float a, b, c, d, e, f;
//};
//int a[50], b[50], c[50], d[50], e[50], n;
//struct Student all[50];
//void average_student(struct Student all[])
//{
//	for (int i = 0; i < n; i++)
//	{
//		all[i].f = (all[i].a + all[i].b + all[i].c + all[i].d + all[i].e) / 5;
//	}
//}
//void average(float *ke)//输入一个成绩数组，返回成绩平均值
//{
//	for(int i = 0; i < n; i++)
//	{
//		ke[0] += a[i];
//		ke[1] += b[i];
//		ke[2] += c[i];
//		ke[3] += d[i];
//		ke[4] += e[i];
//	}
//	ke[0] /= n;
//	ke[1] /= n;
//	ke[2] /= n;
//	ke[3] /= n;
//	ke[4] /= n;
//}
//int main()
//{
//	float ke[5] ={ 0 };
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%s %f %f %f %f %f", &all[i].ID, &all[i].a, &all[i].b, &all[i].c, &all[i].d, &all[i].e);
//		a[i] = all[i].a;
//		b[i] = all[i].b;
//		c[i] = all[i].c;
//		d[i] = all[i].d;
//		e[i] = all[i].e;
//	}
//	average_student(all);
//	average(ke);
//	for (int i = 0; i < n; i++)
//	{
//		printf("%s %g %g %g %g %g %.1f\n", all[i].ID, all[i].a, all[i].b, all[i].c, all[i].d, all[i].e, all[i].f);
//	}
//	printf("%.1f %.1f %.1f %.1f %.1f\n", ke[0], ke[1], ke[2], ke[3], ke[4]);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int n, time[10000];
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &time[i]);
//	}
//	for (int i = n - 1; i > 0; i--)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (time[j + 1] < time[j])
//			{
//				int tmp = time[j + 1];
//				time[j + 1] = time[j];
//				time[j] = tmp;
//			}
//		}
//	}
//	float watetime = 0;
//	for (int i = n - 1; i > 0; i--)
//	{
//		watetime += time[n - i - 1] * i;
//		watetime += time[i];
//	}
//	watetime += time[0];
//	printf("%.2f\n", (watetime / n));
//	return 0;
//}

//#include<stdio.h>
//int year_(int x)
//{
//	if (x == 2007)
//		return 0;
//	if (x == 2008)
//		return 122;
//	if (x > 2008)
//		return 123 + (x-2008) * 365;
//}
//int month_(int x,int y)
//{
//	if (x == 2007)
//	{
//		if (y == 9)
//			return 0;
//		else if (y > 9)
//			return (y - 9) * 30 + (y - 9) / 2;
//	}
//	if (x == 2008)
//	{
//		if (y < 2)
//			return 0;
//		else if (y == 2)
//			return 31;
//		else if (y > 2 && y <= 8)
//			return 60 + (y - 3) * 30 + (y - 2) / 2;
//		else if (y > 8)
//			return 60 + (y - 3) * 30 + (y - 7) / 2 + 3;
//	}
//	if (x > 2008)
//	{
//		if (y < 2)
//			return 0;
//		else if (y == 2)
//			return 31;
//		else if (y > 2 && y <= 8)
//			return 59 + (y - 3) * 30 + (y - 2) / 2;
//		else if (y > 8)
//			return 59 + (y - 3) * 30 + (y - 7) / 2 + 3;
//	}
//}
//int main()
//{
//	int year, month, day, all;
//	while (scanf("%d %d %d", &year, &month, &day) != EOF)
//	{
//		all = year_(year) + month_(year, month) + day;
//		if ((all - 3) % 7 == 0)
//		{
//			printf("ALL\n");
//			continue;
//		}
//		else
//		{
//			if (all > 3)
//			{
//				all -= (all + 3) / 7;
//			}
//			int p = all % 4;
//			switch(p)
//			{
//			case 0:
//				printf("P\n");
//				break;
//			case 1:
//				printf("B\n");
//				break; 
//			case 2:
//				printf("X\n");
//				break;
//			case 3:
//				printf("H\n");
//				break;
//			}
//		}
//	}
//	return 0;
//}

