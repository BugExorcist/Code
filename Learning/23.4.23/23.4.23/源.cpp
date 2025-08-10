#include <bits/stdc++.h>
using namespace std;
typedef struct tree
{
	int data;
	tree* left;
	tree* right;
}T;
void spanning_tree(T* t)
{
	int x;
	cin >> x;
	if (t == NULL)
	{
		t = (T*)malloc(sizeof(T));
		t->data = x;
		t->left = NULL;
		t->right = NULL;
	}
	else if (x < t->data)
		spanning_tree(t->left);
	else if (x > t->data)
		spanning_tree(t->right);
}
int main()
{
	T* t = NULL;
	int n;
	cin >> n;
	while (n--)
		spanning_tree(t);
	int k, count = 0;
	cin >> k;
	T* findt = t;
	while (1)
	{
		count++;
		if (findt == NULL)
		{
			cout << "-1";
			break;
		}
		else if (findt->data == k)
		{
			cout << count;
		}
	}
	return 0;
}

//int main()
//{
//	int n;
//	cin >> n;
//	int arr[1003];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	int k;
//	cin >> k;
//	int left = 0;
//	int right = n - 1;
//	int mid;
//	int count = 0, find = 0;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		count++;
//		if (arr[mid] == k)
//		{
//			cout << mid << endl;
//			find = 1;
//			break;
//		}
//		else if(k < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else 
//		{
//			left = mid + 1;
//		}
//	}
//	if (find == 0)
//	{
//		cout << "-1" << endl;
//	}
//	cout << count;
//	return 0;
//}