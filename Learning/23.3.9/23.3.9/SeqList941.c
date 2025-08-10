#define _CRT_SECURE_NO_WARNINGS 1

/*####### 941: ����˳���ĺϲ�������ʵ�� #######*/
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100//��̬�ռ�
typedef int SQDateType;//������������ ���ӳ����ά����

typedef struct SeqList
{
	int arr[MAX_SIZE];
	int size;
}SL;

//�ӿ�����
void SeqListInit(SL* psl);//��ʼ��
//void SeqListPushBack(SL* psl, SQDateType x);//β��
void SeqListPushFront(SL* psl, SQDateType x);//ͷ��
//void SeqListPopBack(SL* psl);//βɾ
//void SeqListPophFront(SL* psl);//ͷɾ
void MixSqeList(SL* psl1, SL* psl2, SL* psl3);//������Ա�
void PrintList(SL* psl);//��ӡ

void SeqListInit(SL* psl)//��ʼ�����Ա�
{
	memset(psl->arr, 0, sizeof(int) * MAX_SIZE);
	psl->size = 0;
}

void SeqListPushFront(SL* psl, SQDateType x)//ͷ��
{
	psl->arr[psl->size] = x;
	psl->size++;
}

void MixSqeList(SL* psl1, SL* psl2, SL* psl3)//������Ա�
{
	int x1 = 0, x2 = 0;
	while (x1 < psl1->size && x2 < psl2->size)
	{//��L1 L2�ж�����û����L3ʱ
		if (psl1->arr[x1] < psl2->arr[x2])
		{//��L�е���С�Ͱ�L1�е�������L3
			psl3->arr[psl3->size] = psl1->arr[x1];
			x1++;
			psl3->size++;
		}
		else
		{//�����L2�е�������L3
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
	int n = 0, num, time = 2;//���Ա��� ���������
	SL L1, L2, L3;
	SeqListInit(&L1);//��ʼ���������Ա�
	SeqListInit(&L2);
	SeqListInit(&L3);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		SeqListPushFront(&L1, num);//ͷ��L1
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		SeqListPushFront(&L2, num);//ͷ��L2
	}
	MixSqeList(&L1, &L2, &L3);//����������Ա�
	PrintList(&L3);//��ӡ
	return 0;
}
