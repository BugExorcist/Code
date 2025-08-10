#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;
int main()
{
	vector<int>v;
	for (int i = 0; i < 3; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	for (int i = 0; i < 3; i++)
	{
		cout << v[i] <<" ";
	}

	return 0;
}