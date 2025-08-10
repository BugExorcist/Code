#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>
void    ReadScore(float score[], int n);
int	    GetFail(float score[], int n);
float   GetAver(float score[], int n);
int  	GetAboveAver(float score[], int n);
void    DataSort(float score[], int n);
void    PrintScore(float score[], int n);
int    Menu();
int main()
{
	int n, fail, aboveAver, choose; 
	float score[30];
	printf("Please input student number:\n");
	scanf("%d", &n);

	while (1)
	{
		choose = Menu();
		if (choose < 0 || choose>4)
			break;
		switch (choose)
		{
		case 1: ReadScore(score, n);
			break;
		case 2:fail = GetFail(score, n);
			printf("Fail students = %d\n", fail);
			break;
		case 3:aboveAver = GetAboveAver(score, n);
			printf("Above aver students = %d\n", aboveAver);
			break;
		case 4: 	DataSort(score, n);
			PrintScore(score, n);
			break;
		case 0:  printf("end of program");
			exit(0);

		}
	}

	return 0;
}


int Menu()
{

	int choose;
	printf("management for students' score\n");
	printf("\t\t1.输入成绩:\n");
	printf("\t\t2.统计不及格人数:\n");
	printf("\t\t3.高于平均分人数:\n");
	printf("\t\t4.排序:\n");
	printf("\t\t0. 退出\n");
	scanf("%d", &choose);
	return choose;
}

/*函数功能：从键盘输入n个学生成绩
函数参数： 实型数组score，存放学生成绩
函数返回值：void */



void ReadScore(float score[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		scanf("%f", &score[i]);
}

/*函数功能：统计不及格人数
函数参数：实型数组score，存放学生成绩
整型变量n，存放学生总数
函数返回值：不及格人数
*/
int GetFail(float score[], int n)
{
	int TheNumber = 0;
	for (int i = 0; i < n; i++)
	{
		if (score[i] < 60)
		{
			TheNumber++;
		}
	}
	return TheNumber;
}

/*函数功能：计算全班平均分
函数参数：实型数组score，存放学生成绩
整型变量n，存放学生总数
函数返回值：平均分
*/
float GetAver(float score[], int n)
{
	float GetAll = 0;
	for (int i = 0; i < n; i++)
	{
		GetAll += score[i];
	}
	return (GetAll / n);
}

/*函数功能：统计成绩在全班平均分及平均分之上的学生人数
函数参数：
实型数组score，存放学生成绩
整型变量n，存放学生总数
函数返回值：成绩在全班平均分及平均分之上的学生人数
*/
int GetAboveAver(float score[], int n)
{
	float GetAll = 0;
	for (int i = 0; i < n; i++)
	{
		GetAll += score[i];
	}
	int AveScore =  GetAll / n;
	int TheNumber = 0;
	for (int i = 0; i < n; i++)
	{
		if (score[i] >= AveScore)
		{
			TheNumber++;
		}
	}
	return TheNumber;
}

/* 函数功能，按冒泡排序法 将数组score 数组中元素 按从高到低排序。*/
void   DataSort(float score[], int n)
{
	for (int i = n; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (score[j] < score[j + 1])
			{
				int tmp = score[j];
				score[j] = score[j + 1];
				score[j + 1] = tmp;
			}
		}
	}
}

/* 函数功能 打印学生成绩*/
void PrintScore(float score[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%f ", score[i]);
	}
}