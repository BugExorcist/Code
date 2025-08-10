#include "List.h"

void TestList1()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);
	ListPushFront(plist, 0);
	ListPushFront(plist, -1);
	ListPrint(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);
	ListPopBack(plist);
	ListPopBack(plist);

	ListPrint(plist);

	ListDestory(plist);

}
void TestList2()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPushBack(plist, 6);
	ListPrint(plist);
	ListNode* pos = ListFind(plist, 3);
	if (pos != NULL)
	{
		printf("’“µΩ\n");
	}
	else
	{
		printf("√ª’“µΩ\n");
	}
	ListInsert(plist, pos, 666);
	ListPrint(plist);

	ListErase(plist, pos);
	ListPrint(plist);

}

int main()
{
	TestList1();

	return 0;
}