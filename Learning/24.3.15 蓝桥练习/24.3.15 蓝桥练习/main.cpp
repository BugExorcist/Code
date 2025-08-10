#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int step[3] = { 1, 2, 3 };
	vector<int>dp(n + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			if (i - step[j] >= 0) {
				dp[i] = min(dp[i], dp[i - step[j]] + 1);
			}
		}
	}
	cout << dp[n];
	return 0;
}