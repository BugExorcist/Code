#include "SListNote.h"

void SListPrint(SLN** pphead)//��ӡ
{
	SLN* cur = *pphead;
	while (cur != NULL)
	{
		printf("%d\n", cur->date);
		cur = cur->next;
	}
	printf("\n");
}
SLN* BuySListNode(SLNDataTape x)
{
	SLN* new = (SLN*)malloc(sizeof(SLN));
	new->date = x;
	new->next = NULL;

	return new;
}
void SListPushBack(SLN** pphead, SLNDataTape x)//β��
{
	SLN* tail = *pphead;
	SLN* new = BuySListNode(x);
	if (tail == NULL)
	{
		*pphead = new;
	}
	else
	{
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = new;//β�ڵ������½ڵ�
	}
}

void SListPushFront(SLN** pphead, SLNDataTape x)//ͷ��
{
	SLN* new = BuySListNode(x);
	new->next = *pphead;
	*pphead = new;
}

void SListPopBack(SLN** pphead)//βɾ
{
	if (*pphead == NULL)//����Ϊ��
	{
		return;
	}
	else if ((*pphead)->next == NULL)//һ���ڵ�
	{
		free(*pphead);
		*pphead = NULL;
	}
	SLN* tail = *pphead;//����һ���ڵ�
	SLN* prev = NULL;
	while (tail->next != NULL)
	{
		prev = tail;
		tail = tail->next;
	}
	free(tail);
	prev->next = NULL;
}

void SListPopFront(SLN** pphead)
{
	SLN* next = (*pphead)->next;
	//* �� ->����һ�ֽ����ã���������ȼ���ͬ����Ҫ������
	free(*pphead);
	*pphead = next;
}

SLN* SListFind(SLN* phead, SLNDataTape x)//����
{
	SLN* cur = phead;
	while (cur)
	{
		if (cur->date == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SListInsert(SLN** pphead, SLN* pos, SLNDataTape x)//�������
{
	/*SLN* prev = NULL;
	SLN* cur = *pphead;
	while (cur != pos)
	{
		prev = cur;
		cur = cur->next;
	}
	����:
	*/
	if (*pphead == pos)
	{
		SListPushFront(pphead, x);
		return;
	}
	SLN* prev = *pphead;
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	SLN* new = BuySListNode(x);
	new->next = prev->next;
	prev->next = new;
}

void SListErase(SLN** pphead, SLN* pos)
{
	if (*pphead == pos)
	{
		*pphead = (*pphead)->next;
		free(pos);
		return;
	}
	SLN * prev = *pphead;
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	prev->next = pos->next;
	free(pos);
}

