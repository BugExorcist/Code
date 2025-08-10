#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//struct student {
//	char ID[10], class[20], name[20];
//	float a, b, c, av;
//}all[100], temp;
//void input(int i)
//{
//	scanf("%s %s %s %f %f %f", &all[i].ID, &all[i].class, &all[i].name, &all[i].a, &all[i].b, &all[i].c);
//}
//void average(int i)
//{
//	all[i].av = (all[i].a + all[i].b + all[i].c) / 3;
//}
//int find(int n)
//{
//	float max = 0;
//	int	k;
//	for (int i = 0; i < n; i++)
//	{
//		if (all[i].av > max)
//		{
//			max = all[i].av;
//			k = i;
//		}
//	}
//	return k;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		input(i);
//		average(i);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		printf("%s %.1f\n", all[i].name, all[i].av);
//	}
//	int k = find(n);
//	printf("%s %s %s %.1f %.1f %.1f %.1f\n", all[k].ID, all[k].class, all[k].name, all[k].a, all[k].b, all[k].c, all[k].av);
//	return 0;
//}