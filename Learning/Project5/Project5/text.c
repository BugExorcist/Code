#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
////���庯��
//int Add(int a, int b)
//{
//	int z = 0;
//	z = a + b;
//	return z;
//}
//
//int main()
//{
//	int a = 0, b = 0;
//	printf("�����������ֽ��мӷ�����\n");
//	scanf("%d %d", &a,&b);
//	int sum = Add(a, b);
//	printf("sum=%d\n", sum);
//
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	char arr[5] = "abcd";
//	int i = 0;
//		while (i < 5)
//		{
//			printf("%c\n", arr[i]);
//			i++;
//		}
//	return 0;
//}

////define�����
//
//#define ADD(x,y) ((x)+(y))
//#include<stdio.h>
//int main()
//{
//	int sum = ADD(9, 1);
//	printf("%d", sum);
//	return 0;
//}

//�����������α�����ֵ��������ֵ�����ݽ��н���
//�ٴ�����ʱ����

//#include<stdio.h>
//int main()
//{
//	int a = 0, b = 0;
//	scanf("%d%d", &a, &b);
//	int y = 0;
//	y = b;
//	b = a;
//	a = y;
//	printf("a=%d b=%d\n", a,b);
//	return 0;
//}

//�ڲ���������ʱ����������������������

//#include<stdio.h>
//
//int main()
//{
//	int a = 0, b = 0;
//	scanf("%d %d", &a, &b);
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	printf("a=%d b=%d", a, b);
//	return 0;
//}


//��10�����������ֵ
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int MAX = 0;
//	int arr[10]={-2,10,6,24,3,5,14,6,-11,24};
//	for (i = 0 ;i <= 10; i++)
//	{
//		if (MAX<arr[i])
//		MAX = arr[i];
//	}
//	printf("MAX=%d\n", MAX);
//	return 0;
//}

//
//#include<stdio.h>
//int main(){
//	printf("����������10������\n");
//	int i = 0;
//	int arr[10] = { 0 };
//	int MAX = 0;
//	for (i = 0; i <= 9; i++){
//		printf("�����%d������>",i+1);
//		scanf("%d", &arr[i]);
//		if (i <1 ) {
//			MAX = arr[i];
//		}
//		else {
//			if (MAX < arr[i])
//				MAX = arr[i];
//		}
//	}
//	printf("MAX=%d\n", MAX);
//	return 0;
//}

//�����������Ӵ�С���
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	int a, b, c, x;
//	printf("������3����ͬ������");
//	scanf("%d%d%d",&a,&b,&c);
//	x = a;
//	if (a < b)
//	{
//		a = b;
//		b = x;
//	}
//	x = a;
//	if (a < c)
//	{
//		a = c;
//		c = x;
//	}
//	x = b;
//	if (b < c)
//	{
//		b = c;
//		c = x;
//	}
//	printf("%d>%d>%d", a, b, c);
//	return 0;
//}

//�������������Լ��
//#include<stdio.h>
//int main()
//{
//	printf("�����������������Լ��\n");
//	int a =0, b =0,x =0,i =0;
//	scanf("%d%d", &a, &b);
//	if (a < b)//��a>=b
//	{
//		x = a;
//		a = b;
//		b = x;
//	}
//	for (i = 1; i <= b; i++)
//		if (a % i == 0 && b % i == 0)//ʹi��a��b�Ĺ�Լ��
//		x = i;//i���εݼӣ�x�������һ�������i�����Լ��
//	printf("���Լ����%d",x);
//	return 0;
//}

////�Ƚ��������ֵĴ�С
//#include <stdio.h>
//int Max(int x, int y)
//{
//	x >= y ? x : y;
//}
//int main()
//{
//	int a=0, b=0;
//	printf("��������������\n");
//	scanf("%d %d", &a,& b);
//	int c = Max(a, b);
//	printf("%d", c);
//	return 0;
//}

#include <stdio.h>
int add(int a, int b)
{
    int c=0;
    c = a + b;
    return c;
}
int main()
{
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    int sum=add(a, b);
    printf("%d", sum);
    return 0;
}