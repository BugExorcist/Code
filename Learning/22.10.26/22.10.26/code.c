#include<stdio.h>
int main()
{
	int arr[10] = { 1,5,6,2,3,1,9,6,4,10 };
	for (int i = 1; i < 10; i++)
	{
		int key = arr[i];
		for (int j = i; j > 0; j--)
		{
			if (key < arr[j - 1])
			{
				break;
			}
			if (key > arr[j - 1])
			{
				arr[j] = arr[j - 1];
				arr[j - 1] = key;
			}
		}
	}
	for(int i =0;i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}