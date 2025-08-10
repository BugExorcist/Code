#define _CRT_SECURE_NO_WARNINGS 1

/*####### 941: 有序顺序表的合并操作的实现 #######*/
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100//静态空间
typedef int SQDateType;//定义类型名称 增加程序可维护性

typedef struct SeqList
{
	int arr[MAX_SIZE];
	int size;
}SL;

//接口声明
void SeqListInit(SL* psl);//初始化
//void SeqListPushBack(SL* psl, SQDateType x);//尾插
void SeqListPushFront(SL* psl, SQDateType x);//头插
//void SeqListPopBack(SL* psl);//尾删
//void SeqListPophFront(SL* psl);//头删
void MixSqeList(SL* psl1, SL* psl2, SL* psl3);//组合线性表
void PrintList(SL* psl);//打印

void SeqListInit(SL* psl)//初始化线性表
{
	memset(psl->arr, 0, sizeof(int) * MAX_SIZE);
	psl->size = 0;
}

void SeqListPushFront(SL* psl, SQDateType x)//头插
{
	psl->arr[psl->size] = x;
	psl->size++;
}

void MixSqeList(SL* psl1, SL* psl2, SL* psl3)//组合线性表
{
	int x1 = 0, x2 = 0;
	while (x1 < psl1->size && x2 < psl2->size)
	{//当L1 L2中都有数没放入L3时
		if (psl1->arr[x1] < psl2->arr[x2])
		{//若L中的数小就把L1中的数放入L3
			psl3->arr[psl3->size] = psl1->arr[x1];
			x1++;
			psl3->size++;
		}
		else
		{//否则把L2中的数放入L3
			psl3->arr[psl3->size] = psl2->arr[x2];
			x2++;
			psl3->size++;
		}
	}
	while (x1 < psl1->size)
	{
		psl3->arr[psl3->size] = psl1->arr[x1];
		x1++;
		psl3->size++;
	}
	while (x2 < psl2->size)
	{
		psl3->arr[psl3->size] = psl2->arr[x2];
		x2++;
		psl3->size++;
	}
}

void PrintList(SL* psl)
{
	for (int i = 0; i < psl->size; i++)
	{
		if (i != psl->size - 1)
		{
			printf("%d ", psl->arr[i]);
		}
		else
		{
			printf("%d", psl->arr[i]);
		}
	}
	printf("\n");
}

int main()
{
	int n = 0, num, time = 2;//线性表长度 待输入的数
	SL L1, L2, L3;
	SeqListInit(&L1);//初始化三个线性表
	SeqListInit(&L2);
	SeqListInit(&L3);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		SeqListPushFront(&L1, num);//头插L1
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		SeqListPushFront(&L2, num);//头插L2
	}
	MixSqeList(&L1, &L2, &L3);//组合两个线性表
	PrintList(&L3);//打印
	return 0;
}
