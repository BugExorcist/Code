#include <iostream>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <stdbool.h>
#include <math.h>
using namespace std;

int main()
{
	char arr[100];
	cin >> arr;
	int a = 0, b = 0, c = 0, d = 0;
	char len = strlen(arr);
	for (int i = 0; i < len; i++)
	{
		if (arr[i] >= 'a' && arr[i] <= 'z')
		{
			a++;
		}
		else if (arr[i] >= 'A' && arr[i] <= 'Z')
		{
			a++;
		}
		else if (arr[i] >= '0' && arr[i] <= '9')
		{
			b++;
		}
		else if (arr[i] >= ' ')
		{
			c++;
		}
		else
		{
			d++;
		}
	}
	cout << a << " " << b << " " << c << " " << d << endl;
	return 0;
}


//typedef struct tree
//{
//	char data;
//	tree* left;
//	tree* right;
//}T;
//T* spanningTree()
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
//		t->left = spanningTree();
//		t->right = spanningTree();
//	}
//	return t;
//}
//void swap(T*& t)
//{
//	if (t != NULL)
//	{
//		T* tmp = t->left;
//		t->left = t->right;
//		t->right = tmp;
//		swap(t->left);
//		swap(t->right);
//	}
//}
//void printM(T*& t)
//{
//	if (t != NULL)
//	{
//		printM(t->left);
//		cout << t->data;
//		printM(t->right);
//	}
//}
//void printT(T*& t)
//{
//	if (t != NULL)
//	{
//		cout << t->data;
//		printT(t->left);
//		printT(t->right);
//	}
//}
//
//int main()
//{
//	T* t = spanningTree();
//	swap(t);
//	printM(t);
//	cout << endl;
//	printT(t);
//	return 0;
//}



//int main()
//{
//	int n, arr[100];
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	int gra = n / 2;
//	for (int i = gra; i < n; i++)
//	{
//		if (arr[i] < arr[i - gra])
//		{
//			int tmp = arr[i];
//			arr[i] = arr[i - gra];
//			arr[i - gra] = tmp;
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	return 0;
//}

//#define MAX 100
//int n, arr[MAX];
//int P(int x)
//{
//	if (x < n)
//	{
//		int l = 2 * x + 1;
//		int r = 2 * x + 2;
//		if (arr[x] > arr[l] && l < n)
//			return 0;
//		if (arr[x] > arr[r] && r < n)
//			return 0;
//	}
//}
//void heap(int arr[])
//{
//	int last = n - 1;
//	int parent = (last - 1) / 2;
//	for(int i = parent; i >= 0;i--)
//	{
//		if (!P(i))
//		{
//			cout << "No";
//			return;
//		}
//	}
//	cout << "Yes";
//}
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	heap(arr);
//	return 0;
//}

//typedef struct tree
//{
//	char deta;
//	tree* left;
//	tree* right;
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
//		t->deta = x;
//		t->left = spanning_tree();
//		t->right = spanning_tree();
//	}
//	return t;
//}
//int deep(T*& t)
//{
//	if (t == NULL)
//		return 0;
//	else
//		return max(deep(t->left), deep(t->right)) + 1;
//}
//bool balance(T*& t)
//{
//	if (NULL == t)
//		return true;
//	else
//	{
//		int l = deep(t->left);
//		int r = deep(t->right);
//		if (abs(l - r) > 1)
//			return false;
//		return balance(t->left) && balance(t->right);
//	}
//}
//int main()
//{
//	T* t = spanning_tree();
//	if (balance(t))
//		cout << "yes!";
//	else
//		cout << "no!";
//	return 0;
//}


////����������㷨����
////������ж������ȣ����Ը���һ����Ÿ�������ȵ�����indegree[]
////��������indegree[], ����ж�������Ϊ�㣬�㽫����������ӻ�����ջ
////��ջ���߶��в�Ϊ��ʱ��һֱ�ظ�������������
////1�����г�ջ���߳��ӵĲ�������������������Ϊv
////2�����붥��v�ڽӵ����ж������ȼ�һ������������Ϊ0�Ķ��㣬�������ջ������Ӳ���
////4. ����ʱ����Ķ�����С������ͼ�Ķ���������˵������ͼ�д��ڻ�·����������Ķ����˳��Ϊһ����������
//#define MAX 50
//int main()
//{
//	int n, m, map[MAX][MAX], indegree[MAX]{ 0 };//�� �� ��ͼ ���
//	char data[MAX];
//	queue<int>que;
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> data[i];
//	}
//	for (int i = 0; i < m; i++)
//	{
//		char x, y;
//		cin >> x >> y;
//		map[x - 'A'][y - 'A'] = 1;
//		indegree[y - 'A']++;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (indegree[i] == 0)
//		{
//			que.push(i);
//		}
//	}
//	int cnt = 0;//��¼����Ľڵ�����
//	while (!que.empty())
//	{
//		int k = que.front();
//		que.pop();
//		cnt++;
//		for (int i = 0; i < n; i++)
//		{
//			if (map[k][i])
//			{
//				map[k][i] = 0;
//				indegree[i]--;
//				if (!indegree[i])
//					que.push(i);
//			}
//		}
//	}
//	if (cnt < n)
//		cout << "yes";
//	else
//		cout << "no";
//	return 0;
//}


//#define MAX 50
//int n, a, b, arr[MAX][MAX];
//int cnt[MAX]{ 0 };//��¼�ڵ��Ƿ����
//int que[MAX], len = 0;//�������
//void find(int k)
//{
//	if (que[len - 1] == b)//�ҵ�Ŀ��ڵ�����
//	{
//		for (int i = 0; i < len; i++)
//		{
//			cout << que[i];
//		}
//		cout << endl;
//	}
//	else
//	for (int i = 0; i < n; i++)
//	{
//		if (arr[i][k] == 1 && cnt[i] == 0)
//		{
//			que[len] = i;
//			len++;
//			cnt[i] = 1;
//			find(i);
//			len--;
//			cnt[i] = 0;
//		}
//	}
//}
//int main()
//{
//	cin >> n >> a >> b;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> arr[i][j];
//		}
//	}
//	que[len] = a;
//	len++;
//	cnt[a] = 1;
//	find(a);
//	return 0;
//}