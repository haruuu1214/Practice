#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define F first
#define S second
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR0(i,n) for(int i=0;i<n;i++)
#define FOR(i,n) for(int i=1;i<=n;i++)
using namespace std;

int dp[10005];

signed main()
{
    IO;

    int n, m, k, w, v;

    cin >> n >> m >> k;

    fill(dp, dp + 10005, -1e18);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> w >> v;
        for (int j = m; j >= 1; j--) {
            if (j - w >= 0) {
                dp[j] = max(dp[j], dp[j - w] + v);
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        dp[i] = max(dp[i - 1], dp[i]);
    }

    double _m = m;
    for (int i = 1; i <= k; i++) {
        double _i = i;
        int tmp = (int)(_m / _i);

        cout << dp[tmp] * i << "\n";
    }
    
    return 0;
}