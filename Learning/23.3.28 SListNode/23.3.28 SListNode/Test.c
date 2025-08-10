#include "SListNote.h"

void TestList1()
{
	SLN* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 4);
	SListPrint(&plist);

	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(&plist);

	SListPopBack(&plist);
	SListPrint(&plist);

}

void TestList2()
{
	SLN* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(&plist);

	SLN* pos = SListFind(plist, 1);
	SListInsert(&plist, pos, 666);
	SListPrint(&plist);
}
void TestList4()
{
	SLN* plist = NULL;

	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(&plist);

	SLN* pos = SListFind(plist, 2);
	SListErase(&plist, pos);
	SListPrint(&plist);
}

int main()
{
	TestList4();

	return 0;
}