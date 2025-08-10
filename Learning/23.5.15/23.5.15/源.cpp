#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <queue>
using namespace std;

int n, arr[50][50], cnt[50]{ 0 };
char node[50];
queue<int>x;
void DFS(int i)
{
	cout << node[i];
	cnt[i] = 1;
	for (int j = 0; j < n; j++)
	{
		if (arr[i][j] != 0 && cnt[j] == 0)
		{
			DFS(j);
		}
	}
}
void BFS(int k)
{
	cout << node[k];
	x.pop();
	for (int i = 0; i < n; i++)
	{
		if (arr[k][i] != 0 && cnt[i] == 0)
		{
			x.push(i);
			cnt[i] = 1;
		}
	}
	if (!x.empty())
	{
		BFS(x.front());
	}
}
int main()
{
	cin >> n;
	cin >> node;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	char head;
	int num;
	cin >> head;
	for (int i = 0; i < n; i++)
	{
		if (node[i] == head)
		{
			x.push(i);
			cnt[i] = 1;
			BFS(i);
			break;
		}
	}
	return 0;
}
//typedef struct
//{
//    int data;
//    int len, n;
//}HashTable;
//HashTable ha[101], Ha;
//void InsertHT()
//{
//    int adr, k, cur = 0;
//    cin >> k;
//    adr = k % Ha.len;
//    if (ha[adr].data == -1)
//        ha[adr].data = k;
//    else
//    {
//        while (ha[adr].data != -1 && cur < Ha.len)
//        {
//            adr = (adr + 1) % Ha.len;
//            cur++;
//        }
//        ha[adr].data = k;
//    }
//}
//void CreateHT(int len, int n)
//{
//    int i;
//    Ha.len = len, Ha.n = n;
//    for (i = 0; i < n; i++)
//        ha[i].data = -1;
//    for (i = 0; i < n; i++)
//        InsertHT();
//}
//void Search(int x)
//{
//    int adr = x % Ha.len;
//    int cnt = 1; int k = 0;
//    while (ha[adr].data != -1 && ha[adr].data != x && k < Ha.len)
//    {
//        cnt++;
//        adr = (adr + 1) % Ha.len;
//        k++;
//    }
//    if (ha[adr].data == x)
//        cout << adr << ',' << cnt;
//    else
//        cout << -1;
//}
//int main()
//{
//    int len, n, x;
//    cin >> len >> n;
//    CreateHT(len, n);
//    cin >> x;
//    Search(x);
//    return 0;
//}


//struct node
//{
//	int data;
//	node* next;
//};
//
//struct head
//{
//	node* head;
//}Head[100];
//
//void CreatHaxi(head Head[], int m, int x)
//{
//	int t = x % m;
//	node* p;
//	p = (node*)malloc(sizeof(node));
//	p->data = x;
//	p->next = NULL;
//	if (Head[t].head  == NULL)
//	{
//		Head[t].head = p;
//	}
//	else
//	{
//		node* tmp = Head[t].head;
//		while (tmp->next != NULL)
//		{
//			tmp = tmp->next;
//		}
//		tmp->next = p;
//	}
//}
//void search(head Head[], int key, int m)
//{
//	int t = key % m;
//	node* p = Head[t].head;
//	int times = 0;
//	while (1)
//	{
//		times++;
//		if (p == NULL)
//		{
//			cout << "-1";
//			break;
//		}
//		else if (p->data == key)
//		{
//			cout << t << "," << times;
//			break;
//		}
//		p = p->next;
//	}
//}
//int main()
//{
//	int m, n;
//	cin >> m >> n;
//	for (int i = 0; i < m; i++)
//	{
//		Head[i].head = NULL;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		CreatHaxi(Head, m, x);
//	}
//	int key;
//	cin >> key;
//	search(Head, key, m);
//	return 0;
//}

//typedef struct tree
//{
//	int daat;
//	tree* left;
//	tree* right;
//}T;
//void spanning_tree(T*& t, int node)
//{
//	if (t == NULL)
//	{
//		t = (T*)malloc(sizeof(T));
//		t->daat = node;
//		t->left = NULL;
//		t->right = NULL;
//	}
//	else if (node > t->daat)
//	{
//		spanning_tree(t->right, node);
//	}
//	else if (node < t->daat)
//	{
//		spanning_tree(t->left, node);
//	}
//}
//int cnt = 0;
//void find(T*& t, int k)
//{
//	cnt++;
//	if (t == NULL)
//	{
//		cout << "-1";
//		return;
//	}
//	if (k == t->daat)
//	{
//		cout << cnt;
//		return;
//	}
//	else if (k < t->daat)
//	{
//		find(t->left, k);
//	}
//	else if (k > t->daat)
//	{
//		find(t->right, k);
//	}
//}
//int main()
//{
//	T* t = NULL;
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int node;
//		cin >> node;
//		spanning_tree(t, node);
//	}
//	int k;
//	cin >> k;
//	find(t, k);
//	return 0;
//}


//╤яее
//void Swap(int arr[], int a, int b)
//{
//	int tmp = arr[a];
//	arr[a] = arr[b];
//	arr[b] = tmp;
//}
//
//void Heapfly(int arr[], int n, int parent)
//{
//	if (parent < n)
//	{
//		int root = parent;
//		int left = 2 * root + 1;
//		int right = 2 * root + 2;
//		if (arr[left] > arr[root] && left < n) 
//		{
//			root = left;
//		}
//		if (arr[right] > arr[root] && right < n)
//		{
//			root = right;
//		}
//		if (root != parent)
//		{
//			Swap(arr, root, parent);
//			Heapfly(arr, n, root);
//		}
//	}
//}
//
//void HeapSort(int arr[], int n)
//{
//	int last = n - 1;
//	int parent = last / 2;
//	for (int i = parent; i >= 0; i--)
//	{
//		Heapfly(arr, n, i);
//	}
//	for (int i = last; i >= 0; i--)
//	{
//		Swap(arr, i, 0);
//		Heapfly(arr, i, 0);
//	}
//}
//
//
//int main()
//{
//	int n, arr[100];
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	HeapSort(arr, n);
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	return 0;
//}

//OJ 1015
//void Swap(int arr[], int a, int b)
//{
//	int tmp = arr[a];
//	arr[a] = arr[b];
//	arr[b] = tmp;
//}
//
//void Heapfly(int arr[], int n, int parent)
//{
//	if (parent < n)
//	{
//		int root = parent;
//		int left = 2 * root + 1;
//		int right = 2 * root + 2;
//		if (arr[left] < arr[root] && left < n)
//		{
//			root = left;
//		}
//		if (arr[right] < arr[root] && right < n)
//		{
//			root = right;
//		}
//		if (root != parent)
//		{
//			Swap(arr, root, parent);
//			Heapfly(arr, n, root);
//		}
//	}
//}
//
//void HeapSort(int arr[], int n)
//{
//	int last = n - 1;
//	int parent = last / 2;
//	for (int i = parent; i >= 0; i--)
//	{
//		Heapfly(arr, n, i);
//	}
//	/*for (int i = last; i >= 0; i--)
//	{
//		Swap(arr, i, 0);
//		Heapfly(arr, i, 0);
//	}*/
//}
//
//
//int main()
//{
//	int n, arr[100];
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	HeapSort(arr, n);
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	return 0;
//}