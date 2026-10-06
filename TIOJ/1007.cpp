#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

/// dp[i] means the numbers of the states when 'i' is not light
int dp[105];
int pre[105];

signed main()
{
    IO;
    
    int n, m;
    cin >> n >> m;

    dp[0] = 1;
    pre[0] = 1;

    for (int i = 1; i <= m + 1; i++) {
        int l = max(0ll, i - n - 1);
        dp[i] = pre[i - 1] - pre[l] + dp[l];
        pre[i] = pre[i - 1] + dp[i];
    }
    cout << dp[m + 1] << "\n";
    
    return 0;
}