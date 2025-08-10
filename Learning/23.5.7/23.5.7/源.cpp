#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define MAX 100
int main()
{

	return 0;
}





//int main()//插入排序
//{
//	int n, arr[MAX];
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	for (int i = 1; i < n; i++)
//	{
//		int tmp = arr[i];
//		for (int j = i - 1; j >= 0; j--)
//		{
//			if (arr[j] > tmp)
//			{
//				arr[j + 1] = arr[j];
//				if (j == 0)
//				{
//					arr[0] = tmp;
//				}
//			}
//			if (arr[j] < tmp)
//			{
//				arr[j + 1] = tmp;
//				break;
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	return 0;
//}

//typedef struct tree
//{
//	tree* left;
//	tree* right;
//	char data;
//}T;
//T* spanning_tree()
//{
//	T* t;
//	char x;
//	cin >> x;
//	if (x == '#')
//	{
//		t = NULL;
//	}
//	else
//	{
//		t = (T*)malloc(sizeof(T));
//		t->data = x;
//		t->left = spanning_tree();
//		t->right = spanning_tree();
//	}
//	return t;
//}
//void print(T* t)
//{
//	if (t->left == NULL && t->right == NULL)
//	{
//		cout << "0";
//	}
//	else if (t->left != NULL && t->right != NULL)
//	{
//		cout << "2";
//	}
//	else
//	{
//		cout << "1";
//	}
//}
//void findt(T* t, char x)
//{
//	if (t != NULL)
//	{
//		if (t->data == x)
//		{
//			print(t);
//		}
//		else
//		{
//			findt(t->left, x);
//			findt(t->right, x);
//		}
//	}
//}
//int main()
//{
//	T* t = spanning_tree();
//	char x;
//	cin >> x;
//	findt(t, x);
//	return 0;
//}


//int main()
//{
//	int n;
//	cin >> n;
//	int arr[MAX];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	for (int j = 0; j < n - 1; j++)
//	{
//		if (arr[j] > arr[j + 1])
//		{
//			int tmp = arr[j];
//			arr[j] = arr[j + 1];
//			arr[j + 1] = tmp;
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	return 0;
//}


//int main()
//{
//	int n, u, arr[MAX][MAX]{ 0 };
//	cin >> n >> u;
//	for (int i = 0; i < u; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		arr[a][b] = 1;
//	}
//	for (int i = 0; i < u; i++)//对于每一个点
//	{
//		for (int j = 0; j < u; j++)//有n个点可以指向i
//		{
//			for (int k = 0; k < u; k++)//对于每种j指向i的情况有n种i指向k的情况
//			{
//				if (arr[j][i] == 1 && arr[i][k] == 1)
//				{
//					arr[j][k] = 1;
//				}
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (arr[i][j] == 0)
//			{
//				cout << "no";
//				return 0;
//			}
//		}
//	}
//	cout << "yes";
//	return 0;
//}


//int pre[MAX];
//int find(int x)
//{
//	if (pre[x] != x)
//	{
//		return find(pre[x]);
//	}
//	else
//	{
//		return x;
//	}
//}
//void join(int x, int y)
//{
//	pre[x] = find(pre[y]);
//}
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		pre[i] = i;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			int x;
//			cin >> x;
//			if (x == 1)
//			{
//				join(i, j);
//			}
//		}
//	}
//	int count = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (pre[i] == i)
//		{
//			count++;
//		}
//	}
//	cout << count;
//	return 0;
//}

//#define MAX 100
//int main()
//{
//	int n, a, b, arr[MAX][MAX];
//	cin >> n >> a >> b;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> arr[i][j];
//		}
//	}
//	if (arr[a][b] == 1)
//	{
//		cout << "yes";
//	}
//	else
//	{
//		cout << "no";
//	}
//	return 0;
//}

//#define MAX 100
//int main()
//{
//	int n, arr[MAX][MAX]{ 0 };
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> arr[i][j];
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (arr[i][j] == 1)
//			{
//				cout << j;
//			}
//		}
//		cout << endl;
//	}
//	return 0;
//}

//int main()
//{
//	int n;
//	cin >> n;
//	getchar();
//	int arr[100][100]{ 0 };
//	for (int i = 0; i < n; i++)
//	{
//		while (1)
//		{
//			char ch;
//			scanf("%c", &ch);
//			if (ch == '\n')
//			{
//				break;
//			}
//			else if (ch == ' ')
//			{
//				continue;
//			}
//			else
//			{
//				arr[i][ch - '0'] = 1;
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cout << arr[i][j];
//		}
//		cout << endl;
//	}
//	return 0;
//}

//int main()
//{
//	int n, t;
//	cin >> n >> t;
//	int arr[100]{ 0 };
//	for (int i = 0; i < t; i++)
//	{
//		int x;
//		cin >> x;
//		arr[x]++;
//		cin >> x;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i] <<endl;
//	}
//	return 0;
//}

//int main()
//{
//	int n, x, max = 0;
//	cin >> n;
//	int deg[100]{ 0 };
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> x;
//			if (x == 1)
//			{
//				deg[i]++;
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (max < deg[i])
//		{
//			max = deg[i];
//		}
//	}
//	cout << max << endl;
//	for (int i = 0; i < n; i++)
//	{
//		if (deg[i] == max)
//		{
//			cout << i;
//		}
//	}
//	return 0;
//}