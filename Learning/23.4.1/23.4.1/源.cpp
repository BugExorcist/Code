#define _CRT_SECURE_NO_WARNINGS 1

//#include<bits/stdc++.h>
//using namespace std;
//
//typedef struct List
//{
//	struct List* next;
//	struct List* prev;
//	int data;
//}SL;
//
//SL* ListInit()
//{
//	SL* newnode = (SL*)malloc(sizeof(SL));
//	newnode->next = NULL;
//	newnode->prev = NULL;
//	return newnode;
//}
//
//void ListPushBack(SL* sl, int x)
//{
//	SL* newnode = (SL*)malloc(sizeof(SL));
//	while (sl->next != NULL)
//	{
//		sl = sl->next;
//	}
//	newnode->data = x;
//	newnode->prev = sl;
//	newnode->next = NULL;
//	sl->next = newnode;
//}
//
//void ListPrint(SL* sl)
//{
//	sl = sl->next;
//	while (sl != NULL)
//	{
//		cout << sl->data << " ";
//		sl = sl->next;
//	}
//}
//
//void MySort(SL* sl,int n)
//{
//	SL* key = sl->next;
//
//	for (int i = n; i > 0; i--)
//	{
//		for (int j = 0; j < i - 1; j++)
//		{
//			if ((key->data) > ((key->next)->data))
//			{
//				int tmp = key->data;
//				key->data = key->next->data;
//				key->next->data = tmp;
//			}
//			key = key->next;
//		}
//		key = sl->next;
//	}
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	SL* l = ListInit();
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		scanf(" %d", &x);
//		ListPushBack(l, x);
//	}
//	MySort(l, n);
//	ListPrint(l);
//	return 0;
//}

//typedef struct Stark
//{
//	int* a;
//	int top;
//	int capacity;
//}S;
//
//void StarkInit(S* s)
//{
//	s->a = (int*)malloc(sizeof(int) * 4);
//	s->top = 0;
//	s->capacity = 4;
//}
//
//void StarkPush(S* s, int x)
//{
//	if (s->top == s->capacity)
//	{
//		int* newcapacity = (int*)realloc(s->a,sizeof(int) * 2 * s->capacity);
//		s->a = newcapacity;
//		s->capacity *= 2;
//	}
//	s->a[s->top] = x;
//	s->top++;
//}
//void Print(S* s)
//{
//	cout << s->a[s->top];
//}
//
//void StarkPop(S* s)
//{
//	s->top--;
//}
//int StarkSize(S* s)
//{
//	return s->top;
//}
//
//int main()
//{
//	S SL;
//	StarkInit(&SL);
//	int n, x;
//	cin >> n;
//	while (n != 0)
//	{
//		x = n % 2;
//		n /= 2;
//		StarkPush(&SL, x);
//	}
//	while(StarkSize(&SL) != 0)
//	{
//		StarkPop(&SL);
//		Print(&SL);
//	}
//	return 0;
//}

//
//typedef struct Stack
//{
//	int *a;
//	int top;
//}SN;
//
//void StackInit(SN* sn)
//
//{
//	sn->a = (int*)malloc(sizeof(int) * 100);
//	sn->top = 0;
//}
//
//void StackPush(SN* sn, int x)
//{
//	sn->a[sn->top] = x;
//	sn->top++;
//}
//
//void StackPop(SN* sn)
//{
//	sn->top--;
//}
//
//void StackChack(SN* sn, char x)
//{
//	if (sn->a[sn->top-1] == '[' && x == ']')
//	{
//		StackPop(sn);
//	}
//	else if (sn->a[sn->top-1] == '(' && x == ')')
//	{
//		StackPop(sn);
//	}
//	else
//	{
//		cout << "NO";
//		exit(-1);
//	}
//}
//
//int SyackSize(SN* s)
//{
//	return s->top;
//}
//
//int main()
//{
//	SN s;
//	StackInit(&s);
//	char arr[100];
//	cin >> arr;
//	for (int i = 0; i < strlen(arr); i++)
//	{
//		if (arr[i] == '(' || arr[i] == '[')
//		{
//			StackPush(&s, arr[i]);
//		}
//		else if (arr[i] == ')' || arr[i] == ']')
//		{
//			StackChack(&s,arr[i]);
//		}
//	}
//	if (SyackSize(&s) != 0)
//	{
//		cout << "NO";
//		return 0;
//	}
//	cout << "YES";
//	return 0;
//}

#include<bits/stdc++.h>
using namespace std;

typedef struct person
{
	struct person* next;
	char name;
}P;

typedef struct lest
{
	P* head;
	P* tail;
}L;

void Init(L* l)
{
	l->head = l->tail = NULL;
}

void Push(L* l, char x)
{
	P* newnode = (P*)malloc(sizeof(P));
	newnode->next = NULL;
	newnode->name = x;
	if (l->head == NULL)
	{
		l->head = l->tail = newnode;
	}
	else
	{
		l->tail->next = newnode;
		l->tail = newnode;
	}
}

void Pop(L* l)
{
	if (l->head->next == NULL)
	{
		free(l->head);
		l->head = l->tail = NULL;
	}
	else
	{
		P* next = l->head->next;
		free(l->head);
		l->head = next;
	}
}

char Front(L* l)
{
	return l->head->name;
}

int main()
{
	L man, woman;
	Init(&man);
	Init(&woman);
	int m, w, t;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		char x;
		cin >> x;
		Push(&man, x);
	}
	cin >> w;
	for (int i = 0; i < w; i++)
	{
		char x;
		cin >> x;
		Push(&woman, x);
	}
	cin >> t;
	for (int i = 0; i < t - 1; i++)
	{
		char mn = Front(&man);
		char wn = Front(&woman);
		Pop(&man);
		Pop(&woman);
		Push(&man, mn);
		Push(&woman,wn);
	}
	cout << Front(&man) << " " << Front(&woman);
	return 0;
}