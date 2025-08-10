#include <bits/stdc++.h>
using namespace std;
//int main()
//{
//	float a, b = 0;
//	cin >> a;
//	for(int i = 1; i <= a; i++)
//	{
//		b += 1.0 / i;
//	}
//	cout << b;
//
//
//	return 0;
//}

//typedef struct tree
//{
//	char data;
//	tree* left;
//	tree* right;
//}T;
//T* spanning_tree_pm(char* pp, char* pm, int len)
//{
//	T* t;
//	if (len == 0){
//		return NULL;
//	}
//	t = (T*)malloc(sizeof(T));
//	t->data = *pp;
//	char* p;
//	for (p = pm; p < pm + len; p++){
//		if (*p == *pp){
//			break;
//		}
//	}
//	int newlen = p - pm;
//	t->left = spanning_tree_pm(pp + 1, pm, newlen);
//	t->right = spanning_tree_pm(pp + newlen + 1, p + 1, len - newlen - 1);
//	return t;
//}
//void print_tree_t(T* t)
//{
//	if (t == NULL)
//	{
//		return;
//	}
//	print_tree_t(t->left);
//	print_tree_t(t->right);
//	cout << t->data;
//}
//int main()
//{
//	T* t;
//	char strp[50];
//	char strm[50];
//	cin >> strm >> strp;
//	char *pp = strp;
//	char *pm = strm;
//	t = spanning_tree_pm(pp, pm, strlen(strp));
//	print_tree_t(t);
//	
//	return 0;
//}


//int Count = 0;
//int max_degree = 0;
//typedef struct tree
//{
//	char data;
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
//		t->data = x;
//		t->left = spanning_tree();
//		t->right = spanning_tree();
//	}
//	return t;
//}
//void get_tree(T* t)
//{
//	if (t == NULL)
//	{
//		return;
//	}
//	else
//	{
//		Count++;
//	}
//	get_tree(t->right);
//}
//void get_degree(T* t, int k)
//{
//	if (t == NULL)
//	{
//		return;
//	}
//	if (max_degree < k)
//	{
//		max_degree = k;
//	}
//	if (t->left != NULL)
//	{
//		get_degree(t->left,k );
//	}
//	if (t->right != NULL)
//	{
//		get_degree(t->right, k + 1);
//	}
//	
//}
//int main()
//{
//	T* t;
//	t = spanning_tree();
//	if (t->right == NULL)
//	{
//		t = t->left;
//		int k = 1;
//		get_degree(t, k);
//		cout << max_degree;
//	}
//	else
//	{
//		cout << "ERROR";
//	}
//	return 0;
//}