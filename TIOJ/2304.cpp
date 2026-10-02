#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 4e9;


const int N = 1005;
int a[N], b[N];
int dp[N][N];
int sum[N][N];

signed main()
{
    IO
    
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 && j == 0) {
                sum[i][j] = 0;
                dp[i][j] = 0;
            } else if (i == 0) {
                sum[i][j] = sum[i][j - 1] + b[j];
                dp[i][j] = INF;
                if (dp[i][j - 1] >= 0 && sum[i][j] >= 0)
                    dp[i][j] = min(dp[i][j], max(dp[i][j - 1], sum[i][j]));
            } else if (j == 0) {
                sum[i][j] = sum[i - 1][j] + a[i];
                dp[i][j] = INF;
                if (dp[i - 1][j] >= 0 && sum[i][j] >= 0)
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][j], sum[i][j]));
            } else {
                sum[i][j] = sum[i - 1][j] + a[i];
                dp[i][j] = INF;
                if (dp[i][j - 1] >= 0 && sum[i][j] >= 0)
                    dp[i][j] = min(dp[i][j], max(dp[i][j - 1], sum[i][j]));
                if (dp[i - 1][j] >= 0 && sum[i][j] >= 0)
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][j], sum[i][j]));
            }
        }
    }
    cout << (dp[n][m] == INF ? -1 : dp[n][m]) << "\n";

    return 0;
}