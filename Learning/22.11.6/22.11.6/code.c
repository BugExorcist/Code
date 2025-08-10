#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int n, arr[100][2], min, sec;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i][0]);
//		getchar();
//		scanf("%d", &arr[i][1]);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (arr[i][1] + 15 >= 60)
//		{
//			arr[i][1] = arr[i][1] + 15 - 60;
//			arr[i][0] += 1;
//		}
//		else
//		{
//			arr[i][1] += 15;
//		}
//		if (arr[i][0] + 13 >= 24)
//		{
//			arr[i][0] = (arr[i][0] + 13) % 24;
//		}
//		else
//		{
//			arr[i][0] += 13;
//		}
//		printf("%d:%d\n", arr[i][0], arr[i][1]);
//	}
//	return 0;
//}

#include<stdio.h>
struct Student
{
	float a, b, c, ave;
	char ID[9], clase[20], name[20];
};
int main()
{
	int n;
	scanf("%d", &n);
	struct Student all[100];
	struct Student max;
	for (int i = 0; i < n; i++)
	{
		scanf("%s %s %s %f %f %f", &all[i].ID, &all[i].clase, &all[i].name, &all[i].a, &all[i].b, &all[i].c);
		all[i].ave = (all[i].a + all[i].b + all[i].c) / 3;
	}
	max = all[0];
	for (int i = 0; i < n; i++)
	{
		printf("%s %.1f\n", all[i].name, all[i].ave);
		if (all[i].ave > max.ave)
		{
			max = all[i];
		}
	}
	printf("%s %s %s %.1f %.1f %.1f %.1f\n", max.ID, max.clase, max.name, max.a, max.b, max.c,max.ave);
	return 0;
}

