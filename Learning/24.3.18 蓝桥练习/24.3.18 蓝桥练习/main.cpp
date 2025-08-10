//#include <bits/stdc++.h>
//using namespace std;
//
//int n, m;
//char arr[1003][1003];
//
//int get_long(int a, int b, char x) {
//	int length = 0;
//	for (int i = 1; a - i >= 0 && b - i >= 0 && a + i < n && b + i < m; i++) {
//		if (arr[a + i][b] == x && arr[a - i][b - i] == x && arr[a - i][b + i] == x) {
//			length = i;
//		}
//		else {
//			break; // 如果不满足构成字母 Y 的条件，退出循环
//		}
//	}
//	return length;
//}
//
//int main() {
//	cin >> n >> m;
//	int longest = 0;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> arr[i][j];
//		}
//	}
//	for (int i = 1; i < n - 1; i++) {
//		for (int j = 1; j < m - 1; j++) {
//			longest = max(longest, get_long(i, j, arr[i][j]));
//		}
//	}
//	cout << longest;
//	return 0;
//}


//#include <iostream>
//#include <string.h>
//using namespace std;
//
//int main()
//{
//	char arr[1000006];
//	cin >> arr;
//	int L = 0, R = 0, total = 0;
//	for (int i = 0; i < strlen(arr); i++) {
//		if (arr[i] == 'L') {
//			L++;
//		}
//		else {
//			R++;
//		}
//		if (L == R) total++;
//	}
//	cout << total;
//
//	return 0;
//}

//#include <bits\stdc++.h>
//using namespace std;
//
//int main() {
//	int total = 0;
//	for (int i = 3; i <= 1000000; i += 2) {
//		int chk = 0;
//		for (int j = 2; j * j <= i; j++) {
//			if (i % j == 0) {
//				chk = 1;
//				break;
//			}
//		}
//		if (chk)
//			continue;
//		int p = i, num = 0;
//		while (p) {
//			num += p % 10;
//			p /= 10;
//		}
//		if (num == 23) 
//			total++;
//	}
//	cout << total;
//	return 0;
//}