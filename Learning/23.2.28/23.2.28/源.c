#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//int main()
//{
//	float d, p;
//	while (scanf("%f", &p) != EOF)
//	{
//		if (p < 1000)
//		{
//			d = 1;
//		}
//		else if (p >= 1000 && p < 2000)
//		{
//			d = 0.95;
//		}
//		else if (p >= 2000 && p < 3000)
//		{
//			d = 0.9;
//		}
//		else if (p >= 3000 && p < 5000)
//		{
//			d = 0.85;
//		}
//		else
//		{
//			d = 0.8;
//		}
//		printf("discount=%g,pay=%g\n",d, (p * d));
//	}
//
//	return 0;
//}

#include <stdio.h>
int main()
{
	int num = 0, n2, arr[10000];
	while (scanf("%d", &num) != EOF)
	{
		int i = 0, a = num;
		while (a >= 2)
		{
			if (a >= 2)
			{
				arr[i] = (a % 2);
				a = a / 2;
				i++;
			}
		}
		if (a != 0)
		{
			printf("%d", a);
		}
		for (int j = i - 1; j >= 0; j--)
		{
			printf("%d", arr[j]);
		}
		printf("\n%o\n", num);
	}
	return 0;
}