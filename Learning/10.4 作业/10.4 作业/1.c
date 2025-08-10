#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	char a;
//	while ((scanf ("%c",&a)) != EOF)
//	{
//		if (a < 32)
//			printf("This is a control character.");
//		else if (a >= 48 && a <= 57)
//			printf("This is a digit.");
//		else if (a >= 65 && a <= 90)
//			printf("This is a capital letter.");
//		else if (a >= 97 && a <= 122)
//			printf("This is a small letter.");
//		else
//			printf("This is an other character.");
//		getchar();
//	}
//	return 0;
//}
#include <stdio.h>
int main()
{
	int a;
	scanf("%d", &a);
	if (a % 2 == 1)
		printf("odd number");
	else 
		printf("even number");
	return 0;
}