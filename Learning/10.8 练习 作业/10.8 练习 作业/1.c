#define _CRT_SECURE_NO_WARNINGS

//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	if ((a * b) % 2 == 1)
//		printf("wxd");
//	else
//		printf("jjy")
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	char arr[3] = { 0 };
//	for (int i = 0; i < 3; i++)
//	{
//		scanf("%c", &arr[i]);
//	}
//	for (int i = 2; i >= 0; i--)
//	{
//		printf("%c", arr[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int number, b;
//	scanf("%d", &a);
//	int num1 = number % 10;
//	int num10 = (number / 10) % 10;
//	int num100 = (number / 100) % 10;
//	b = num100 + (num10 * 10) + (num1 * 100);
//	printf("%d", b);
//	return 0;
////}
//
//#include <stdio.h>
//int main()
//{
//	int r = 1;
//	double arr [2],PI = 3.14;
//	arr[0] = 2 * PI * r;
//	arr[1] = PI * r * r;
//	return arr;
//}

//#include<stdio.h>
//int main()
//{
//	printf("she\n");
//	printf("shi\n");
//	printf("yi\n");
//	printf("dao\n");
//	printf("qian\n");
//	printf("dao\n");
//	printf("ti\n");
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a, b;
//	for (b = 1; b < 10; b++)
//	{
//		for (a = 1; a <= b; a++)
//		{
//			printf("%d*%d=", a, b);
//			if (a * b < 10)
//			{
//				printf(" %d ", a * b);
//			}
//			else
//			{
//				printf("%d ", a * b);
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	printf("printf(\"Hello world!\\%c\");\n",'n');
//	printf("cout << \"Hello world!\" << endl;\n");
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	float p ,a, b;
//	scanf("%d %d", &a, &b);
//	p = ((b / a)*100);
//	printf("%.3f%c", p,'%');
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	printf("\"Genius is 1%c inspiration and 99%c perspiration.\"", '%', '%');
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a;
//	scanf("%d",&a);
//	if (a < 7)
//	{
//		printf("%d", (a + 1));
//	}
//	else
//		printf("1");
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int x, n;
//	scanf("%d %d", &x, &n);
//	int a = (x + (n % 7));
//		if (a > 7)
//			printf("%d", (a - 7));
//		else
//			printf("%d", a);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	char arr[] = { "hello world"};
//	for (int i = 0; i < 11; i++)
//	{
//		printf("%c", arr[i] + 1);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a[4];
//	for (int i = 0; i < 4; i++)
//	{
//		a[i] = getchar();
//	}
//	for (int i = 3; i >= 0; i--)
//	{
//		printf("%c", a[i]);
//	}
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int arr[5], add = 0;
//	for (int i = 0; i < 5; i++)
//	{
//		scanf("%d", &arr[i]);
//		add = add + arr[i];
//	}
//	float answer = (add / 5.0);
//	printf("%.1f", answer);
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	float a, b, c, s, p;
//	scanf ("%f %f %f", &a, &b, &c);
//	p = (a + b + c) / 2;
//	s = sqrt(p * (p - a) * (p - b) * (p - c));
//	printf("circumference=%.2f area=%.2f", (a + b + c), s);
//}

//#include<stdio.h>
//#define year 3156
//int main()
//{
//	int age;
//	scanf("%d", &age);
//	printf("%lld0000", (age * year));
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	if (a >= 3600)
//	{
//		printf("%d ", a / 3600);
//	}
//	else
//		printf("0 ");
//	if (a >= 60)
//		printf("%d ", (a % 3600) / 60);
//	else
//		printf("0 ");
//	if (a >= 0)
//		printf("%d ", (a % 60));
//	else
//		printf("0 ");
//	return 0;
//}