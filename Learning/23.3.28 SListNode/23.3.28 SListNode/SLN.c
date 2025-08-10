#include "SListNote.h"

void SListPrint(SLN** pphead)//打印
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
void SListPushBack(SLN** pphead, SLNDataTape x)//尾插
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
		tail->next = new;//尾节点链接新节点
	}
}

void SListPushFront(SLN** pphead, SLNDataTape x)//头插
{
	SLN* new = BuySListNode(x);
	new->next = *pphead;
	*pphead = new;
}

void SListPopBack(SLN** pphead)//尾删
{
	if (*pphead == NULL)//链表为空
	{
		return;
	}
	else if ((*pphead)->next == NULL)//一个节点
	{
		free(*pphead);
		*pphead = NULL;
	}
	SLN* tail = *pphead;//大于一个节点
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
	//* 和 ->都是一种解引用，这里的优先级相同，需要打括号
	free(*pphead);
	*pphead = next;
}

SLN* SListFind(SLN* phead, SLNDataTape x)//查找
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

void SListInsert(SLN** pphead, SLN* pos, SLNDataTape x)//随机插入
{
	/*SLN* prev = NULL;
	SLN* cur = *pphead;
	while (cur != pos)
	{
		prev = cur;
		cur = cur->next;
	}
	或者:
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

