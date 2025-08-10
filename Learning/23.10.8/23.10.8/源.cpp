#include <bits/stdc++.h>
using namespace std;
//int factorial(int n)
//{
//	if (n == 0)
//		return 1;
//	else
//		return n * factorial(n - 1);
//}
//int dictionary_value(int arr[], int n)
//{
//	int value = 0;
//	for (int i = 0; i < n; i++)
//	{
//		int count = 0;
//		for (int j = i + 1; j < n; j++)
//		{
//			if (arr[j] < arr[i])
//				count++;
//		}
//		value += count * factorial(n - i - 1);
//	}
//	return value;
//}
//void next_permutation(int arr[], int n)
//{
//	for (int i = n - 1; i > 0; i--)
//	{
//		if (arr[i] > arr[i - 1])
//		{
//			int min = n - 1;
//			for (int j = n - 1; j >= i; j--)
//			{
//				if (arr[j] > arr[n - 1] && arr[j] < arr[min])
//					min = j;
//			}
//			swap(arr[i - 1], arr[min]);
//			int l = i, r = n - 1;
//			while (l < r)
//			{
//				swap(arr[l], arr[r]);
//				l++;
//				r--;
//			}
//			return;
//		}
//	}
//	//cout << "没有下一个字典序排列" << endl;
//	//exit(-1);
//}
//int main()
//{
//	int n, arr[16], next[16];
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//		next[i] = arr[i];
//	}
//	int value = dictionary_value(arr, n);
//	next_permutation(next, n);
//	cout << value << endl;
//	for (int i = 0; i < n; i++)
//	{
//		cout << next[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}

//int josephus(int x, int y)
//{
//	if (x == 1)
//		return 1;
//	else
//		return (josephus(x - 1, y) + y - 1) % x + 1;
//}
//
//int main()
//{
//	int n, m = 2;
//	cin >> n;
//	int p = josephus(n, m);
//	cout << p << endl;
//	return 0;
//}


//
//int  arr[100005] = { 0 };//1开0关
//void change(int x)
//{
//	if (arr[x] == 0)
//		arr[x] = 1;
//	else arr[x] = 0;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		int t = 1;
//		while (1)
//		{
//			if (t * i <= n)
//				change(t * i);
//			else
//				break;
//			t++;
//		}
//	}
//	int count = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (arr[i] == 1)
//			count++;
//	}
//	cout << count << endl;
//	return 0;
//}

int main()
{
	int m, n, t,arr[21][21];
	cin >> m >> n >> t;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	int spand = 0,get = 0, xx = 0, yy = 0;
	while (1)
	{
		int Max = 0, x = 0, y = 0;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				if (arr[i][j] > Max)
				{
					Max = arr[i][j];
					x = j;
					y = i;
				}
			}
		if (spand == 0)
			spand += (y);
		else
			spand += (abs(x - xx) + abs(y - yy));
		xx = x;
		yy = y;
		spand += (yy + 1);//采花生并返回的时间
		if (spand > t)
		{
			break;
		}
		spand -= (yy);//去掉返回的时间
		get += Max;
		arr[yy][xx] = 0;
	}
	cout << get << endl;
	return 0;
}

//int arr[1003], ans = 0;
//void swap_cakes(int x)
//{
//	ans++;
//	int l = 0, r = x;
//	while (l < r)
//	{
//		int m = arr[l];
//		arr[l] = arr[r];
//		arr[r] = m;
//		l++;
//		r--;
//	}
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	while (n > 1)
//	{
//		int p = 0;
//		for (int i = 0; i < n; i++)//找最大的饼
//		{
//			if (arr[p] < arr[i])
//				p = i;
//		}
//		if (p != n - 1)//翻饼
//		{
//			if (p != 0)
//			{
//				swap_cakes(p);
//			}
//			swap_cakes(n - 1);
//		}
//		n--;
//	}
//	cout << ans << endl;
//	return 0;
//}