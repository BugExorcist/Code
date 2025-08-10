//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <string.h>
//
//#define MAX 100
//
//typedef struct SeqList
//{
//	int arr[MAX];
//	int length;
//}SL;
//void SeqListInit(SL* psl)//��ʼ�����Ա�
//{
//	memset(psl->arr, 0, sizeof(int) * MAX);
//	psl->length = 0;
//}
//void SeqListPushBack(SL* psl, int x)//β��
//{
//	psl->arr[psl->length] = x;
//	psl->length++;
//}
//int SeqListFindItem(SL* psl, int item)//Ѱ��item
//{//����ҵ�����i��û�ҵ�����-1
//	for (int i = 0; i < psl->length - 1; i++)
//	{
//		if (psl->arr[i] == item)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//	void SeqListSwitch(SL * psl, int item)
//	{//����һ���ռ临�Ӷ�ΪO��1���ķ�����ͨ���������ý��в���
//		int left = item + 1, right = psl->length - 1;
//		while (left < right)
//		{
//			int tmp = psl->arr[left];
//			psl->arr[left] = psl->arr[right];
//			psl->arr[right] = tmp;
//			left++;
//			right--;
//		}
//	}
//	void SeqListPrint(SL * psl)
//	{
//		for (int i = 0; i < psl->length; i++)
//		{
//			if (i != psl->length - 1)
//				printf("%d ", psl->arr[i]);
//			else
//				printf("%d\n", psl->arr[i]);
//		}
//	}
//	int main()
//	{
//		int n, x, item, data;
//		SL L;
//		SeqListInit(&L);
//		scanf("%d", &n);
//		while (n--)
//		{
//			scanf("%d", &x);
//			SeqListPushBack(&L, x);
//		}
//		scanf("%d", &item);
//		scanf("%d", &data);
//		SeqListPushBack(&L, data);//�Ȱ�dataβ��
//		int k = SeqListFindItem(&L, item);
//		if (k != -1)
//		{
//			SeqListSwitch(&L, k - 1);
//			SeqListSwitch(&L, k);
//		}
//		SeqListPrint(&L);
//		return 0;
//	}

