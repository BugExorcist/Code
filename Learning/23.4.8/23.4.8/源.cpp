#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int>v;
	for (int i = 0; i < n; i++)
	{
		int x;

		cin >> x;
		v.push_back(x);
	}
	int num, key;
	cin >> key >>num;
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it == key)
		{
			cout << num << " ";
		}
		cout << *it << " ";
		it++;
	}
	return 0;
}



//int get_level(char x)
//{
//	if (x == '(')
//	{
//		return 1;
//	}
//	else if (x == '+' || x == '-')
//	{
//		return 2;
//	}
//	else if(x == '*' || x == '/')
//	{
//		return 3;
//	}
//}
//
//int main()
//{
//	char arr[50];
//	cin >> arr;
//	stack<char>s;
//	for (int i = 0; i < strlen(arr); i++)
//	{
//		if (arr[i] >= 'A' && arr[i] <= 'Z')
//		{
//			cout << arr[i];
//		}
//		else if (arr[i] == '(')
//		{
//			s.push(arr[i]);
//		}
//		else if (arr[i] == ')')
//		{
//			while (s.top() != '(')
//			{
//				cout << s.top();
//				s.pop();
//			}
//			s.pop();
//		}
//		else
//		{
//			while (s.size() != 0 && get_level(arr[i]) <= get_level(s.top()))
//			{
//				cout << s.top();
//				s.pop();
//			}
//			s.push(arr[i]);
//		}
//	}
//	while (!s.empty())
//	{
//		cout << s.top();
//		s.pop();
//	}
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//int s, t;
//int main()
//{
//	cin >> s >> t;
//	char a[1003], b[1003];
//	cin >> a >> b;
//	for (int i = 0; i < s - t + 1; i++)
//	{
//		if (a[i] == b[0])
//		{
//			for (int j = 0; j <= t; j++)
//			{
//				if (j == t)
//				{
//					cout << "yes" << endl;
//					return 0;
//				}
//				if (a[i + j] != b[j])
//				{
//					break;
//				}
//
//			}
//		}
//	}
//	cout << "no" << endl;
//	return 0;
//}





//typedef struct Tree
//{
//	char data;
//	Tree* left;
//	Tree* right;
//}T;
//
//T* spanning_tree()
//{
//	char x;
//	cin >> x;
//	T* t;
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
//void PrintWidth(T* t)
//{
//	queue<T*>que;
//	que.push(t);
//	while (!que.empty())
//	{
//		if (que.front()->left != NULL)
//		{
//			que.push(que.front()->left);
//		}
//		if (que.front()->right != NULL)
//		{
//			que.push(que.front()->right);
//		}
//		cout << que.front()->data;
//		que.pop();
//	}
//}
//
//int main()
//{
//	T* t;
//	t = spanning_tree();
//	PrintWidth(t);
//
//
//	return 0;
//}



//typedef pair<int, int>p;
//int main()
//{
//	int n;
//	cin >> n;
//	deque<int>qe;
//	for (int i = 1; i <= n; i++)
//	{
//		char x;
//		cin >> x;
//		if (x == '0')
//		{
//			qe.push_front(i);
//		}
//		else
//		{
//			qe.push_back(i);
//		}
//	}
//	vector<int>v (n);
//	for (int i = 1; i <= n; i++)
//	{
//		int x;
//		cin >> x;
//		v[i - 1] = x;
//	}
//	priority_queue<pair<int, int>>q;
//	for (int i = 0; i < n; i++)
//	{
//		q.push({ v[i], qe[i]});
//	}
//	while(!q.empty())
//	{
//		cout << q.top().second << " ";
//		q.pop();
//	}
//	cout << endl;
//	return 0;
//}


//int main()
//{
//	int x;
//	cin >> x;
//	priority_queue<int,vector<int>,greater<int>>que;
//	for (int i = 0; i < x; i++)
//	{
//		int n;
//		cin >> n;
//		que.push(n);
//	}
//	int all = 0;
//	for (int i = 0; i < x - 1 ; i++)
//	{
//		int a = que.top();
//		que.pop();
//		int b = que.top();
//		que.pop();
//		all += a + b;
//		que.push(a + b);
//	}
//	cout << all << endl;
//	return 0;
//}