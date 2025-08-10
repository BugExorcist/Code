#include "List.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

void ListPrint(ListNode* phead)
{
	ListNode* cur = phead->next ;
	while (cur !=  phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

void ListPushBack(ListNode* phead, LTDataType x)
{
	/*assert(phead);
	
	ListNode* tail = phead->prev;
	ListNode* newnode = BuyListNode(x);
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;*/

	ListInsert(phead, phead->prev, x);
}

void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);

	/*ListNode* first = phead->next;
	ListNode* newnode = BuyListNode(x);
	first->prev = newnode;
	newnode->next = first;
	phead->next = newnode;
	newnode->prev = phead;*/

	ListInsert(phead, phead->next, x);
}

void ListPopFront(ListNode* phead)
{
	//assert(phead);
	//assert(phead->next != phead);

	//ListNode* first = phead->next;
	//first->next->prev = phead;
	//phead->next = first->next;
	//free(first);
	//first = NULL;

	ListErase(phead, phead->next);
}

void ListPopBack(ListNode* phead)
{
	//assert(phead);
	//assert(phead->next != phead);

	//ListNode* tail = phead->prev;
	//tail->prev->next = phead;
	//phead->prev = tail->prev;
	//free(tail);
	//tail = NULL;

	ListErase(phead, phead->prev);
}

ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void ListInsert(ListNode* phead, ListNode* pos, LTDataType x)
{
	assert(phead);

	ListNode* newnode = BuyListNode(x);
	ListNode* left = pos->prev;
	left->next = newnode;
	newnode->prev = left;
	newnode->next = pos;
	pos->prev = newnode;
}
void ListErase(ListNode* phead, ListNode* pos)
{
	assert(phead);
	
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;

}

void ListDestory(ListNode* phead)
{
	assert(phead);

	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}
