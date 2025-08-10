#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//	//字符数据类型(char)
//	char ch = 'a';//将字符“a”放进叫“ch”的载体
//	//整形
//	int age = 19;
//	//短整型
//	short int num = 10;
//	short nun = 11;//（或者）
// .0639+218STHYO、//	//单精度浮点
//	float weight = 55.4;
//	//双精度浮点
//	double a = 0.05;
//
//	//打印一个整数
//	printf("%d\n",100);
//	//sizeof-关键字- 操作符-计算类型或者变量所占大小(以整数呈现)
//	printf("%d\n", sizeof(char));
//
//	return 0;
//}


//int main()
//{
//	//手动设置一个变量
//	int age = 15;
//	double weight = 75.3;
//
//	age = age + 1;
//	weight = weight+0.51;
//	//打印一个整形 - %d 
//	//打印浮点数  float - %f double - %lf
//		printf("%d\n", age);
//		printf("%lf\n", weight);
//
//		return 0;
//}

//{局部变量}全局变量
int a = 95; //全局变量
//int main()
//{
//	int a = 10;//局部变量
//	printf("%d\n", a);
//	return 0;
//}

//求两个数的和
//scanf <输入>函数
int main()
{
	int m = 0;//可以不赋值，但不推荐
	int n = 0;
	int sum = 0;
	int 积 = 0;
	scanf("%d %d", &m, &n);//在命令窗输入	X X	对应值(m n)
	sum = m + n;
	积 = m * n;
	printf("sum=%d\n", sum);
	printf("积=%d\n", 积);
	return 0;
}