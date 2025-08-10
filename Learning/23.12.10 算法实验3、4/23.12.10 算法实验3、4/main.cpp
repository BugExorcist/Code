#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;


#include <bits/stdc++.h>
using namespace std;

int main() {
	char a[2003], b[2003];
	cin >> a >> b;
	int x = strlen(a), y = strlen(b);
	if (x * y == 0) {
		cout << x + y;
		return 0;
	}
	vector<vector<int>>dp(x + 1, vector<int>(y + 1));
	for (int i = 0; i <= x; i++)
		dp[i][0] = i;
	for (int i = 0; i <= y; i++)
		dp[0][i] = i;
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
			}
		}
	}
	cout << dp[x][y] << endl;
	return 0;
}
//int main()
//{
//    int n, dp[100005];
//    int sumA = 0, ans = 999999999;
//    int a[205], b[205];
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> a[i];
//        sumA += a[i];
//        dp[i] = 0;//初始化
//    }
//    for (int i = 0; i < n; i++)
//    {
//        cin >> b[i];
//    }
//    for (int k = 0; k < n; k++)
//    {
//        for (int i = sumA; i >= 0; i--)
//        {
//            if (i >= a[k])
//            {
//                dp[i] = min(dp[i] + b[k], dp[i - a[k]]);
//            }
//            else dp[i] = dp[i] + b[k];
//        }
//    }
//    for (int i = 0; i <= sumA; i++)
//    {
//        int t = max(i, dp[i]);//取较大的
//        ans = min(ans, t);//取较小的
//    }
//    cout << ans << endl;
//}


//int a[100001], b[1000001];
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d%d", &a[i], &b[i]);
//	}
//	sort(a, a + n);
//	sort(b, b + n);
//	for (int i = 0; i < n; i++)
//	{
//		a[i] -= i;
//	}
//	sort(a, a + n);
//	int midx = a[(n - 1) / 2];
//	int midy = b[(n - 1) / 2];
//	int sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		sum += abs(a[i] - midx);
//		sum += abs(b[i] - midy);
//	}
//	printf("%d\n", sum);
//	return 0;
//}


//struct node {
//	int sumv;
//	int count;
//	vector<int>pre;
//	node() {
//		sumv = 0;
//		count = 0;
//		pre.clear();
//	}
//};
//int main()
//{
//	ios::sync_with_stdio(false);
//	int n, m;
//	while (cin >> n >> m) {
//		node dp[6005];
//		int num[605];
//		for (int i = 0; i < n; i++)cin >> num[i];
//		//注意倒序,
//		for (int i = n - 1; i >= 0; i--) {
//			int s;
//			s = num[i];
//			for (int j = m; j >= 0; j--) {
//				if (j - s >= 0) {
//					if (dp[j].count < dp[j - s].count + 1 || (dp[j].count == (dp[j - s].count + 1)
//						&& dp[j].sumv <= (dp[j - s].sumv + s))) {//注意等于：：等于的时候直接覆盖掉，这样求出来的是最大的字典序
//						dp[j].count = dp[j - s].count + 1;		  //，但是我们是用的倒叙，所以反过来就是最小字典序
//						dp[j].pre = dp[j - s].pre;
//						dp[j].pre.push_back(s);
//						dp[j].sumv = dp[j - s].sumv + s;
//					}
//				}
//			}
//		}
//		cout << dp[m].count << ' ' << dp[m].sumv << endl;
//		int len = dp[m].pre.size();
//		//倒叙输出
//		for (int i = len - 1; i >= 0; i--) {
//			if (i != len - 1)cout << ' ';
//			cout << dp[m].pre[i];
//		}
//		cout << endl;
//	}
//
//	return 0;
//}



//int rob(vector<int>& nums) {
//    if (nums.empty()) {
//        return 0;
//    }
//    int size = nums.size();
//    if (size == 1) {
//        return nums[0];
//    }
//    vector<int> dp = vector<int>(size, 0);
//    dp[0] = nums[0];
//    dp[1] = max(nums[0], nums[1]);
//    for (int i = 2; i < size; i++) {
//        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
//    }
//    return dp[size - 1];
//}
//int main() {
//    int n;
//    cin >> n;
//    vector<int>nums(n);
//    for (int i = 0; i < n; i++) {
//        int x;
//        cin >> x;
//        nums[i] = x;
//    }
//    cout << rob(nums) << endl;
//    return 0;
//}




//int main() {
//	char a[2003], b[2003];
//	cin >> a >> b;
//	int x = strlen(a), y = strlen(b);
//	if (x * y == 0) {
//		cout << x + y;
//		return 0;
//	}
//	vector<vector<int>>dp(x + 1, vector<int>(y + 1));
//	for (int i = 0; i <= x; i++)
//		dp[i][0] = i;
//	for (int i = 0; i <= y; i++)
//		dp[0][i] = i;
//	for (int i = 1; i <= x; i++) {
//		for (int j = 1; j <= y; j++) {
//			if (a[i - 1] == b[j - 1]) {
//				dp[i][j] = dp[i - 1][j - 1];
//			}
//			else{
//				dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
//			}
//		}
//	}
//	cout << dp[x][y] << endl;
//	return 0;
//}

//int main() {
//	int m, n;
//	while (~scanf("%d %d", &m, &n)) {
//		vector<int>a;//价值
//		vector<int>b;//欢迎度
//		vector<vector<int>>dp(n + 1, vector<int>(m + 1));
//		for (int i = 0; i < n; i++) {
//			int aa, bb;
//			cin >> aa >> bb;
//			a.push_back(aa);
//			b.push_back(bb);
//		}
//		for (int i = 1; i <= n; i++) {
//			for (int j = a[i - 1]; j <= m; j++) {
//				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i - 1]] + b[i - 1]);
//			}
//		}
//		if (dp[n][m] == 0)
//			cout << "0";
//		else {
//			cout << dp[n][m] << endl;
//			vector<int>nums;//记录买了哪几个
//			int i, j = m;
//			for (i = n; i >= 1 && j > 0; i--) {
//				if (dp[i][j] > dp[i - 1][j]) {
//					nums.push_back(i);
//					j -= a[i - 1];
//				}
//			}
//			for (int i = nums.size() - 1; i >= 0; i--) {
//				cout << nums[i];
//				if (i != 0)
//					cout << " ";
//			}
//		}
//		cout << endl;
//	}
//	return 0;
//}