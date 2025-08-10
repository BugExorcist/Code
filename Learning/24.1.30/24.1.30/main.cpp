#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, min = INT_MAX, target, p;
	for (int i = 0; i < 64; i++) {
		cin >> x;
		p = x;
		int add = 0;
		for (int j = 0; j < 6; j++) {
			add += p % 10;
			p /= 10;
		}
		if (add < min) {
			min = add;
			target = x;
		}
	}
	cout << target;
	return 0;
}