#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m = 31415, n = 14142, count = 1;
	while (n != 0)
	{
		count++;
		int r = m % n;
		m = n;
		n = r;
	}
	cout << "count=" << count << endl;
}
