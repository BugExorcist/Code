//typedef struct tree
//{
//	struct tree* left;
//	struct tree* right;
//	char data;
//}T;
//
//
//T* build_tree()
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
//		t->left = build_tree();
//		t->right = build_tree();
//	}
//	return t;
//}
//
//int get_deep(T* t)
//{
//	return t == NULL ? 0 : 1 + max(get_deep(t->left), get_deep(t->right));
//}
//
//int main()
//{
//	T* t;
//	t = build_tree();
//
//	cout << get_deep(t);
//
//	return 0;
//}

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
//	else if (x == '*' || x == '/')
//	{
//		return 3;
//	}
//}
//
//int main()
//{
//	char arr[100];
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
//	while (s.size() != 0)
//	{
//		cout << s.top();
//		s.pop();
//	}
//	return 0;
//}

//int main()
//{
//	char x;
//	stack<int>s;
//	while (cin >> x)
//	{
//		if (x == '#')
//		{
//			break;
//		}
//		else if (x >= '0' && x <= '9')
//		{
//			s.push(x - '0');
//		}
//		else
//		{
//			if (x == ' ')
//			{
//				continue;
//			}
//			else if (x == '+')
//			{
//				int a = s.top();
//				s.pop();
//				int b = s.top();
//				s.pop();
//				int num = b + a;
//				s.push(num);
//			}
//			else if (x == '-')
//			{
//				int a = s.top();
//				s.pop();
//				int b = s.top();
//				s.pop();
//				int num = b - a;
//				s.push(num);
//			}
//			else if (x == '/')
//			{
//				int a = s.top();
//				s.pop();
//				int b = s.top();
//				s.pop();
//				int num = b / a;
//				s.push(num);
//			}
//			else if (x == '*')
//			{
//				int a = s.top();
//				s.pop();
//				int b = s.top();
//				s.pop();
//				int num = b * a;
//				s.push(num);
//			}
//		}
//	}
//	cout << s.top();
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//int main()
//{
//	int t, y = 0;
//	cin >> t;
//	char arr[35];
//	for (int i = 0; i < t; i++)
//	{
//		int l;
//		cin >> l;
//		cin >> arr;
//		for (int j = 0; j < l - 2; j++)
//		{
//			if (arr[j] == 'g' &&arr[j + 1] == 'c'&& arr[j + 2] == 'd')
//			{
//				cout << "gyjjtxdy!"<<endl;
//				y = 1;
//				break;
//			}
//			if (arr[j] == 'l' && arr[j + 1] == 'c' && arr[j + 2] == 'm')
//			{
//				cout << "gyjjtxdy!"<<endl;
//				y = 1;
//				break;
//			}
//		}
//		if (y == 0)
//		{
//			cout << "I'm not satisfied!!!" << endl;
//		}
//		y = 0;
//	}
//	return 0;
//}



//int get_level(char x)
//{
//	if (x == '(')
//	{
//		return 0;
//	}
//	else if (x == '+' || x == '-')
//	{
//		return 1;
//	}
//	else if (x == '*' || x == '/')
//	{
//		return 2;
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


//int main()
//{
//	int n;
//	int count = 0;
//	cin >> n;
//	int x = n / 62;
//	int tmp = n - x;
//	cout << tmp;
//}

#include <bits/stdc++.h>
using namespace std;
int get(int x)
{
	if (x == 1)
	{
		return 1;
	}
	else if (x == 2)
	{
		return 2;
	}
	else if (x == 3)
	{
		return 4;
	}
	else
	{
		return get(x - 3) + get(x - 2) + get(x - 1);
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int x;
		cin >> x;
		cout << get(x) << endl;
	}
	return 0;
}


//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	char arr1[1003];
//	char arr2[1003];
//	cin >> arr1 >> arr2;
//	for (int i = 0; i < n - m + 1; i++)
//	{
//		if (arr1[i] == arr2[0])
//		{
//			for (int j = 0; j <= m; j++)
//			{
//				if (j == m)
//				{
//					cout << "yes" << endl;
//					return 0;
//
//				}
//			}
//		}
//	}
//	cout << "no" << endl;
//	return 0;
//}



//int main()
//{
//	int n;
//	cin >> n;
//	while (n--)
//	{
//		int t;
//		char a;
//		cin >> t >> a;
//		if (t == 1)
//		{
//			if (a >= 'a' && a <= 'z')
//			{
//				int k = a - 'a' + 1;
//				cout << k << endl;
//			}
//			else
//			{
//				int k = a - 'A' + 1;
//				cout << k << endl;
//			}
//		}
//		else
//		{
//			if (a >= 'a' && a <= 'z')
//			{
//				char k = a + ('A' - 'a');
//				cout << k << endl;
//			}
//			else
//			{
//				char k = a - ('A' - 'a');
//				cout << k << endl;
//			}
//		}
//	}
//	return 0;
//}



//int main()
//{
//	int t;
//	cin >> t;
//	char arr[32];
//	while (t--)
//	{
//		cin >> arr;
//		int l = 0, r = strlen(arr) - 1;
//		while (1)
//		{
//			if (arr[l] == arr[r])
//			{
//				l++;
//				r--;
//			}
//			else
//			{
//				cout << "NO" << endl;
//				break;
//			}
//			if (l >= r)
//			{
//				cout << "YES" << endl;
//				break;
//			}
//		}
//	}
//	return 0;
//}



//int main()
//{
//	int n, q;
//	cin >> n >> q;
//	int a, b;
//	char arr[1003]{ 0 }, c[3];
//	for (int i = 0; i < q; i++)
//	{
//		cin >> a >> c >> b;
//		if (c[1] == '=')
//		{
//			if (arr[a] == arr[b])
//			{
//				cout << "YES" << endl;
//			}
//			else
//			{
//				cout << "NO" << endl;
//			}
//		}
//		else
//		{
//			arr[a] = b;
//		}
//	}
//	return 0;
//}


//int main()
//{
//	int n;
//	int arr[150][2];
//	cin >> n;
//	int count = 0;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		arr[i][0] = x;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		arr[i][1] = x;
//		if (arr[i][0] > arr[i][1])
//		{
//			count += arr[i][0] - arr[i][1];
//		}
//	}
//	cout << count << endl;
//	return 0;
//}


//int main()
//{
//	long long t;
//	cin >> t;
//	for (long long i = 0; i < t; i++)
//	{
//		long long x;
//		cin >> x;
//		if (x == 1)
//		{
//			cout << 114514 << endl;
//		}
//		else
//		{
//			long long tmp = (x - 1) * x / 2;
//			cout << tmp + 114514<< endl;
//		}
//	}
//	return 0;
//}