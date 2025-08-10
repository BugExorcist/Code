#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, b, c, d;
	scanf("%d %d %d %d", &a,&b,&c,&d);
	int arr[4] = {a,b,c,d};
	for (int i = 4; i > 1; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int f = arr[j];
				arr[j] = arr[j + 1];
				arr[j +1 ] = f;
			}
		}
	}
	int sum1 = (arr[0] + arr[3]), sum2 = (arr[1] + arr[2]);
	int e = (sum1 - sum2);
	if (e < 0)
		e = -e;
	printf("%d\n", e);
	return 0;
}

