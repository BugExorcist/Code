#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

struct type
{
	char name[100];
	int last, now, cha;
};
int main()
{
	struct type all[100];
	struct type temp;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", &all[i].name);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &all[i].last);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &all[i].now);
		all[i].cha = all[i].now - all[i].last;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (all[j - 1].cha < all[j].cha && all[j].cha != 0 || all[j - 1].cha == 0)
			{
				temp = all[j - 1];
				all[j - 1] = all[j];
				all[j] = temp;
			}
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (all[i].cha == all[i + 1].cha)
		{
			if (strcmp(all[i].name, all[i + 1].name) > 0)
			{
				temp = all[i];
				all[i] = all[i + 1];
				all[i + 1] = temp;
				i = 0;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d %s\n", all[i].cha, all[i].name);
	}
	return 0;
}