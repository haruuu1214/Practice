#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;


const int N = 12;
int a[N][N];
int dp[N][N][1 << N];

void solve() {
    fill(&dp[0][0][0], &dp[0][0][0] + N * N * (1 << N), 0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    dp[0][m][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int mask = 0; mask < (1 << m); mask++)
            dp[i][0][mask << 1] = dp[i - 1][m][mask];
        for (int j = 1; j <= m; j++) {
            int x = 1 << (j - 1); /// 現在的底邊
            int y = 1 << j;       /// 現在的右側邊
            if (!a[i][j]) {
                for (int mask = 0; mask < (1 << (m + 1)); mask++) {
                    if ((mask & x) || (mask & y))
                        dp[i][j][mask] = 0;
                    else
                        dp[i][j][mask] = dp[i][j - 1][mask];
                }
            } else {
                for (int mask = 0; mask < (1 << (m + 1)); mask++) {
                    dp[i][j][mask] = dp[i][j - 1][mask ^ x ^ y];
                    bool D = (mask & x), R = (mask & y);
                    if (D ^ R)
                        dp[i][j][mask] += dp[i][j - 1][mask];
                    dp[i][j][mask] %= mod;
                }
            }
        }
    }
    cout << dp[n][m][0] << "\n";
}

signed main() {
    IO;
    
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    
    return 0;
}