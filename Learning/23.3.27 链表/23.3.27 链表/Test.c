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

	/*SLN* pos = SListFind(&plist, 3);
	SListInsert(&plist, pos, 666);
	SListPrint(&plist);*/

}

int main()
{
	TestList2();

	return 0;
}
