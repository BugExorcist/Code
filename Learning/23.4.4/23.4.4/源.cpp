
//int main()
//{
//	queue<int>q;
//	int capucity, times;
//	cin >> capucity >> times;
//	char a[4];
//	for (int i = 0; i < times; i++)
//	{
//		cin >> a;
//		if (strcmp(a, "in") == 0)
//		{
//			if (q.size() < capucity - 1)
//			{
//				int x;
//				cin >> x;
//				q.push(x);
//			}
//			else
//			{
//				int x;
//				cin >> x;
//			}
//		}
//		else if (strcmp(a, "out") == 0)
//		{
//			if (!q.empty())
//			{
//				q.pop();
//			}
//		}
//	}
//	while (!q.empty())
//	{
//		cout << q.front() << " ";
//		q.pop();
//	}
//	return 0;
//}

#include <bits/stdc++.h>
using namespace std;

#define MAXSIZA 100
int arr[MAXSIZA];

typedef char DataType;
typedef struct Tree
{
	DataType data;
	struct Tree* left;
	struct Tree* right;
}T;

T* build_tree()
{
	T* t;
	DataType x;
	cin >> x;
	if (x == '#')
	{
		t = NULL;
	}
	else
	{
		t = (T*)malloc(sizeof(T));
		t->data = x;
		t->left = build_tree();
		t->right = build_tree();
	}
	return t;
}

int get_deep(T* t)
{
	return t == NULL ? 0 : 1 + max(get_deep(t->left), get_deep(t->right));
}

int get_node(T* t)
{
	return t == NULL ? 0 : 1 + get_node(t->left) + get_node(t->right);
}

void get_width(T* t, int i)//统计树每层的宽度，保存在arr[]中，第一层从arr[1]开始
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		arr[i]++;
		get_width(t->left, i + 1);
		get_width(t->right, i + 1);
	}
}

int get_leaf(T* t)
{
	if (t == NULL)
	{
		return 0;
	}
	else if (t->right == NULL && t->left == NULL)
	{
		return 1;
	}
	else
	{
		return get_leaf(t->left) + get_leaf(t->right);
	}
}

int count_tree2 = 0;
void  _tree2(T* t)//count计数度为二的节点个数
{
	if (t == NULL)
	{
		return;
	}
	if (t->right != NULL && t->left != NULL)
	{
		count_tree2++;
	}
	_tree2(t->left);
	_tree2(t->right);
}

void print_tree(T* t)
{
	if (t == NULL)
	{
		return;
	}
	print_tree(t->left);
	cout << t->data;
	print_tree(t->right);
}

void printf_tree2(T* t)
{
	if (t == NULL)
	{
		return;
	}
	printf_tree2(t->left);
	printf_tree2(t->right);
	cout << t->data;
}

int main()
{
	T* t;
	t = build_tree();
	//get_width(t, 1);
	//int max = 0;
	//for (int i = 0; i < MAXSIZA; i++)
	//{
	//	if (max < arr[i])
	//	max = arr[i];
	//}
	//cout << max;
	printf_tree2(t);
	return 0;
}