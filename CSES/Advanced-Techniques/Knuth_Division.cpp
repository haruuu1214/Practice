#pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

int opt[5005][5005];
int dp[5005][5005];
int pre[5005];
int a[5005];

signed main()
{
    IO;
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
        opt[i][i] = i;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1, j = i + k; j <= n; i++, j++) {
            dp[i][j] = INF;
            int down = opt[i][j - 1], up = opt[i + 1][j];
            for (int t = down; t <= up; t++) {
                if (dp[i][t] + dp[t + 1][j] < dp[i][j]) {
                    dp[i][j] = dp[i][t] + dp[t + 1][j];
                    opt[i][j] = t;
                }
            }
            dp[i][j] += pre[j] - pre[i - 1];
        }
    }

    cout << dp[1][n] << "\n";
    
    return 0;
}