#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>>arr(1003, vector<char>(1003));

int get_long(int a, int b, char x) {
	int lu = 0, ru = 0, d = 0;
	for (int i = 1;; i++) {
		if (arr[a - i][b - i] == x) {
			lu = i;
		}
		if (arr[a + i][b - i] == x) {
			ru = i;
		}
		if (arr[a][b + 1] == x) {
			d = i;
		}
		if (a - i == 0 || b - i == 0 || a + i == n - 1 || b - i == m - 1) break;
	}
	return min(lu, min(ru, d));
}

int main() {
	cin >> n >> m;
	int longest = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			longest = max(longest, get_long(i, j, arr[i][j]));
		}
	}
	cout << longest;
	return 0;
}