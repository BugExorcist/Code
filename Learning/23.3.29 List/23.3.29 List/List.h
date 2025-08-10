#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

ListNode* ListInit();

void ListPushFront(ListNode* phead, LTDataType x);
void ListPushBack(ListNode* phead, LTDataType x);
void ListPopFront(ListNode* phead);
void ListPopBack(ListNode* phead);
void ListPrint(ListNode* phead);

ListNode* ListFind(ListNode* phesd, LTDataType x);
void ListInsert(ListNode* phead, ListNode* pos, LTDataType x);
void ListErase(ListNode* phead, ListNode* pos);

void ListDestory(ListNode* phead);


