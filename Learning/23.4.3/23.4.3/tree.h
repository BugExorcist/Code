#pragma once
#include <bits/stdc++.h>
using namespace std;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	int data;

}BTN;

void PrevOrede(BTN* root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data << " ";
	PrevOrede(root->left);
	PrevOrede(root->right);
}
void InOrede(BTN* root)
{

}
void PostOrede(BTN* root)
{

}
