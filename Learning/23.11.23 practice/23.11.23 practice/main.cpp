#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    string s = "2611055971756562";
    if (s[0] == '0') return 0;
    int len = s.length();
    vector<int>dp(len + 1);
    dp[0] = 1;
    dp[1] = 1;
    int pair = 0;
    for (int i = 2; i <= len; i++) {
        if (s[i - 1] == '0') {
            if (s[i - 2] < '1' || s[i - 2] > '2')
                return 0;
            else {
                dp[i] += dp[i - 2];
                continue;
            }
        }
        dp[i] += dp[i - 1];
        if (s[i - 2] == '1' || s[i - 1] >= '1' && s[i - 1] <= '6' && s[i - 2] == '2') {
            dp[i] += dp[i - 2];
        }
    }
    return dp[len];
}