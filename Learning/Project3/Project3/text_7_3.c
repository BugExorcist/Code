#define _CRT_SECURE_NO_WARNINGS 1
////①字面常量
//int main()
//{
//	10000:
//	3.14;
//	"a";
//	return 0;
//}
//只是存在，没什么意义
//
////②const常变量
////只是把一个变量固定值，本质还是一个变量
////故不可在数组中使用
//
//int main()
//{
//	//创建包含10个元素的数组
//	int arr[10] = { 0 };
//	//↓错误↓
//	const int n = 10;
//	int arr2[n] = { 0 };
//	return 0;
//}
//
////③define定义标识符常量
//#include<stdio.h>
//#define MAX 10000;
//
//int main()
//{
//	int age = MAX;
//	printf("MAX=%d", age);
//	return 0;
//}
//
////④枚举常量
////可以一一列举的常量
////性别
//#include<stdio.h>
//enum Six
//{
//	//此处枚举的可能常量元素
//	MALE,//0
//	FEMALE,//1
//	SECRET,//2
//};
//int main()
//{
//	enum Six s = MALE;
//	printf(" % d", MALE);
//	printf(" % d", FEMALE);
//	printf(" % d", SECRET);
//	//打印出来就是 0 1 2
//	//枚举常量默认从0开始 且不可更改
//
//	return 0;
//}
////但可以更改赋初值
//enum Six2
//{
//	
//	MALE=5,//5
//	FEMALE,//6
//	SECRET,//7
//};
////打印出来就是 5 6 7

//打印100~200之间的素数

//#include<stdio.h>
//int main()
//{
//	int m, n;
//	printf("100到200之间的素数是：\n");
//	for (m = 100; m <= 200; m++)
//	{
//		for (n = 2; n < m; n++)
//		{
//			if (m % n == 0)//如果m/n的余数等于0，则可以被整除，不是素数，跳出循环
//			break;
//		}
//		{
//		if (m == n)//如果m不是素数，则n会小于m，不打印，如果m是素数，此时m==n，则打印m
//		printf("%d ", m);
//		}
//	}
//	return 0;
//}

//打印1000到2000年之间的闰年
//#include<stdio.h>
//
//int main()
//{
//	int a;
//	for (a = 2000; a <= 2500; a++)//输入年份范围
//	{
//		if (((a % 4 == 0 )&&(a%100!=0))||a%400==0)
//		{
//		printf("%d ", a);
//		}
//	}
//	return 0;
//}
//
//打印99乘法表
//#include<stdio.h>
//
//int main()
//{
//	int m = 0, n = 0;
//	for (m = 1; m <= 9; m++)//有9行，第二个数字每次+1
//	{
//		for (n = 1; n <= m; n++)//第一个数字从1开始乘直到和m相同时停止
//		{
//			printf("%d*%d=%d ", n, m, m * n);
//		}
//		printf("\n");//在打印完一行之后换行
//
//	}
//	return 0;
//}

//判断是否是闰年
//#include<stdio.h>
//
//int main()
//{
//	int n=0;
//	scanf("%d",& n);//输入年份
//	if (((n % 4 == 0) && (n % 100 != 0)) || (n % 400 == 0))
//	{//满足上面说的条件之一的打印是闰年
//		printf("%d是闰年", n);
//	}
//	else 
//	{//否则打印不是闰年
//		printf("%d不是闰年", n);
//	}
//
//	return 0;
//}

