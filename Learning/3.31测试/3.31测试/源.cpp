#define _CRT_SECURE_NO_WARNINGS 1

//#include <bits/stdc++.h>
//using namespace std;

//int main()
//{
//	int n;
//	vector<int>v;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		v.push_back(x);
//	}
//	int k, num;
//	cin >> k >> num;
//	if (k >= n || k < 1)
//	{
//		cout << "error!";
//		return 0;
//	}
//	v.insert(v.begin()+k-1, num);
//	for (int i = 0; i < n + 1; i++)
//	{
//		cout << v[i] << " ";
//	}
//	return 0;
//}

//int main()
//{
//	int n;
//	cin >> n;
//	vector<int>v;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		v.push_back(x);
//	}
//	int k;
//	cin >> k;
//	if (k <= 1 || k > n + 1)
//	{
//		cout << "error!";
//		return 0;
//	}
//	v.erase(v.begin() + k - 2);
//	for (int i = 0; i < n - 1; i++)
//	{
//		printf("%d ", v[i]);
//	}
//	return 0;
//}

//typedef struct list
//{
//	struct list* next;
//	char data;
//}L;
//
//L* ListInit()
//{
//	L* newnode = (L*)malloc(sizeof(char));
//	newnode->next = NULL;
//	return newnode;
//}
//
//void ListPushBack(L* sl, char x)
//{
//	L* newnode = (L*)malloc(sizeof(char));
//	while (sl->next != NULL)
//	{
//		sl = sl->next;
//	}
//	sl->next = newnode;
//	newnode->data = x;
//	newnode->next = NULL;
//}
//void ListPrint(L* sl)
//{
//	sl = sl->next;
//	while (sl != NULL)
//	{
//		cout << sl->data << " ";
//		sl = sl->next;
//	}
//}
//int main()
//{
//	int a, b;
//	char x;
//	L* head = ListInit();
//	cin >> a;
//	for (int i = 0; i < a; i++)
//	{
//		cin >> x;
//		ListPushBack(head, x);
//	}
//	cin >> b;
//	for (int i = 0; i < b; i++)
//	{
//		cin >> x;
//		ListPushBack(head, x);
//	}
//	ListPrint(head);
//	return 0;
//}

//int main()
//{
//	int n, k, t;
//	cin >> n >> k;
//	t = k;
//	vector<int>v;
//	for (int i = 1; i <= n; i++)
//	{
//		v.push_back(i);
//	}
//	while (v.size() != 1)
//	{
//		v.erase(v.begin() + t - 1);
//		t += k - 1;
//		while (t > v.size())
//		{
//			t -= v.size();
//		}
//	}
//	cout << v[0];
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//int main()
//{
//	char arr[10000];
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		scanf(" %c", &arr[i]);
//	}
//	for (int i = n - 1; i >= 0; i--)
//	{
//		cout << arr[i] << " ";
//	}
//	return 0;
//}

#include <bits/stdc++.h>
using namespace std;

typedef struct List
{
	struct List* next;
	struct List* prev;
	int data;
}L;

L* ListInit()
{
	L* newnode = (L*)malloc(sizeof(int));
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

void ListPushBack(L* sl, char x)
{
	L* newnode = (L*)malloc(sizeof(int));
	while (sl->next != NULL)
	{
		sl = sl->next;
	}
	sl->next = newnode;
	newnode->data = x;
	newnode->prev = sl;
	newnode->next = NULL;
}

void ListPrint(L* sl)
{
	sl = sl->next;
	while (sl != NULL)
	{
		printf("%d ", sl->data);
		sl = sl->next;
	}
}

int main()
{
	L* head = ListInit();
	int n;
	scanf(" %d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf(" %d", &x);
		ListPushBack(head, x);
	}
	ListPrint(head);
	return 0;
}