#define _CRT_SECURE_NO_WARNINGS 1


//int main()
//{
//	vector<char>v,w;
//	char x;
//	scanf("%c", &x);
//	while (x != '@')
//	{
//		v.push_back(x);
//		scanf("%c", &x);
//	}
//	scanf("%c", &x);
//	while (x != '#')
//	{
//		w.push_back(x);
//		scanf("%c", &x);
//	}
//	reverse(w.begin(), w.end());
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (v[i] != w[i])
//		{
//			cout << "no!" << endl;
//			return 0;
//		}
//	}
//	cout << "yes!" << endl;
//	return 0;
//}


//int main()
//{
//	int n, max = 0, k;
//	cin >> n;
//	map<int, int>mp;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		mp[x]++;
//		if (mp[x] > max)
//		{
//			max = mp[x];
//			k = x;
//		}
//	}
//	if (max > n / 2)
//	{
//		cout << k;
//	}
//	else
//	{
//		cout << "-1";
//	}
//	return 0;
//}

//int main()
//{
//	int n;
//	cin >> n;
//	list<int>l;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		l.push_back(x);
//	}
//	int k;
//	cin >> k;
//	int t = l.size();
//	for (int i =0; i < t ; i++)
//	{
//		if (l.front() == k)
//		{
//			l.pop_front();
//			continue;
//		}
//		int tmp = l.front();
//		l.pop_front();
//		l.push_back(tmp);
//	}
//	if (l.size() == 0)
//	{
//		cout << "-1";
//		return 0;
//	}
//	for (auto i : l)
//	{
//		cout << i << " ";
//	}
//	return 0;
//}

//void Print(vector<char>*vi, stack<char>*sc)
//{
//	while(vi->size() != 0)
//	{
//		cout << vi->front();
//		vi->erase(vi->begin());
//	}
//	if (sc->size() != 0)
//	{
//		if (sc->top() == ')')
//		{
//			sc->pop();
//			while (sc->top() != '(')
//			{
//				cout << sc->top();
//				sc->pop();
//			}
//			sc->pop();
//		}
//		while (sc->top() != '+' && sc->top() != '-' && sc->size() != 0)
//		{
//			cout << sc->top();
//			sc->pop();
//		}
//	}
//}
//
//void PrintAll(vector<char>* vi, stack<char>* sc)
//{
//	while (vi->size() != 0)
//	{
//		cout << vi->front();
//		vi->erase(vi->begin());
//	}
//	while (sc->size() != 0)
//	{
//		cout << sc->top();
//		sc->pop();
//	}
//}
//
//int main()
//{
//	vector<char>vi;
//	stack<char>sc;
//	char arr[100];
//	cin >> arr;
//	int t = 0, type = 0;
//	for (int i = 0; i < strlen(arr); i++)
//	{
//		if (arr[i] >= 'A' && arr[i] <= 'Z')
//		{
//			vi.push_back(arr[i]);
//		}
//		else
//		{
//			if (arr[i] == '(')
//			{
//				type++;
//			}
//			if (arr[i] == ')')
//			{
//				sc.push(arr[i]);
//				Print(&vi, &sc);
//				type--;
//			}
//			else if (arr[i] == '+' && type == 0|| arr[i] == '-' && type == 0)
//			{
//				Print(&vi, &sc);
//				sc.push(arr[i]);
//			}
//			else
//			{
//				sc.push(arr[i]);
//			}
//		}
//	}
//	PrintAll(&vi, &sc);
//	return 0;
//}

//int Level(char x)
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
//		else if(arr[i] == ')')
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
//			while (s.size() != 0 && Level(arr[i]) <= Level(s.top()))
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
//	char a;
//	stack<int>s;
//	while (cin >> a)
//	{
//		if (a == '#')
//		{
//			break;
//		}
//		else if (a >= '0' && a <= '9')
//		{
//			s.push(a - '0');
//		}
//		else
//		{
//			if (a == ' ')
//			{
//				continue;
//			}
//			else if (a == '+')
//			{
//				int a = s.top();
//				s.pop();
//				int b = s.top();
//				s.pop();
//				int num = b + a;
//				s.push(num);
//			}
//			else if (a == '-')
//			{
//				int a = s.top();
//				s.pop();
//				int b = s.top();
//				s.pop();
//				int num = b - a;
//				s.push(num);
//			}
//			else if (a == '*')
//			{
//				int a = s.top();
//				s.pop();
//				int b = s.top();
//				s.pop();
//				int num = b * a;
//				s.push(num);
//			}
//			else if (a == '/')
//			{
//				int a = s.top();
//				s.pop();
//				int b = s.top();
//				s.pop();
//				int num = b / a;
//				s.push(num);
//			}
//		}
//	}
//	cout << s.top();
//	return 0;
//}


//int main()
//{
//	int n;
//	cin >> n;
//	stack<int>s;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		s.push(x);
//	}
//	cin >> n;
//	while (n--)
//	{
//		if (s.size() == 0)
//		{
//			cout << "-1";
//			return 0;
//		}
//		s.pop();
//	}
//	if (s.size() == 0)
//	{
//		cout << "-1";
//		return 0;
//	}
//	cout << s.top();
//	return 0;
//}

//int main()
//{
//	list<int>l;
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		l.push_back(x);
//	}
//	int p;
//	cin >> p;
//	if (p >= n)
//	{
//		cout << "error!";
//		return 0;
//	}
//	while (p--)
//	{
//		int tmp = l.front();
//		l.pop_front();
//		l.push_back(tmp);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		cout << l.front()<< " ";
//		l.pop_front();
//	}
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <list>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int>v;
//	for (int i = 0; i < n; i++)
//	{
//		int  x;
//		cin >> x;
//		v.push_back(x);
//	}
//	int key = v.front();
//	list<int>l;
//	for(int i = 1; i < v.size(); i++)
//	{
//		if (v[i] < key)
//		{
//			l.push_front(v[i]);
//			v.erase(v.begin() + i);
//			i--;
//		}
//	}
//	while(!l.empty())
//	{
//		cout << l.front() << " ";
//		l.pop_front();
//	}
//	for(int i =0; i < v.size(); i++)
//	{
//		cout << v[i] << " ";
//	}
//	return 0;
//}

//int main()
//{
//	int c;
//	cin >> c;
//	vector<int>v;
//	for (int i = 0; i < c; i++)
//	{
//		int x;
//		cin >> x;
//		v.push_back(x);
//	}
//	int a, b;
//	cin >> a >> b;
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (v[i] >= a && v[i] <= b)
//		{
//			v.erase(v.begin() + i);
//			i--;
//		}
//	}
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << " ";
//	}
//	return 0;
//}

//int main()
//{
//	int n;
//	cin >> n;
//	map<int, int>mp;
//	int max = 0, key;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		mp[x]++;
//		if (max < mp[x])
//		{
//			max = mp[x];
//			key = x;
//		}
//		else if(max == mp[x])
//		{
//			if (key > x)
//			{
//				key = x;
//			}
//		}
//	}
//	cout << key;
//	return 0;
//}

#include<bits/stdc++.h>
using namespace std;
int m, n;
int test[50][50];

void change(int i, int j)
{
	if (test[i][j] != 0)
	{
		test[i][j] = 0;
		if (i - 1 >= 0)//上面
		{
			change(i - 1, j);
		}
		if (i + 1 < m)//下面
		{
			change(i + 1, j);
		}
		if (j - 1 >= 0)//左边
		{
			change(i, j - 1);
		}
		if (j + 1 < n)//右边
		{
			change(i, j + 1);
		}
	}
}
int main()
{
	int i, j;
	cin >> m >> n;
	int counter = 0;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> test[i][j];
		}
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (test[i][j] != 0)
			{
				counter++;
				change(i, j);
			}
		}
	}
	cout << counter;
	return 0;
}
