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
	printf("\t\t1.����ɼ�:\n");
	printf("\t\t2.ͳ�Ʋ���������:\n");
	printf("\t\t3.����ƽ��������:\n");
	printf("\t\t4.����:\n");
	printf("\t\t0. �˳�\n");
	scanf("%d", &choose);
	return choose;
}

/*�������ܣ��Ӽ�������n��ѧ���ɼ�
���������� ʵ������score�����ѧ���ɼ�
��������ֵ��void */



void ReadScore(float score[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		scanf("%f", &score[i]);
}

/*�������ܣ�ͳ�Ʋ���������
����������ʵ������score�����ѧ���ɼ�
���ͱ���n�����ѧ������
��������ֵ������������
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

/*�������ܣ�����ȫ��ƽ����
����������ʵ������score�����ѧ���ɼ�
���ͱ���n�����ѧ������
��������ֵ��ƽ����
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

/*�������ܣ�ͳ�Ƴɼ���ȫ��ƽ���ּ�ƽ����֮�ϵ�ѧ������
����������
ʵ������score�����ѧ���ɼ�
���ͱ���n�����ѧ������
��������ֵ���ɼ���ȫ��ƽ���ּ�ƽ����֮�ϵ�ѧ������
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

/* �������ܣ���ð������ ������score ������Ԫ�� ���Ӹߵ�������*/
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

/* �������� ��ӡѧ���ɼ�*/
void PrintScore(float score[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%f ", score[i]);
	}
}