#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 85;
int dp[N][N][N][N];

signed main() {
    IO;
    
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    a = '_' + a;
    b = '_' + b;
    int ans = 0;
    for (int len1 = 1; len1 <= n; len1++) {
        for (int l1 = 1; l1 + len1 - 1 <= n; l1++) {
            int r1 = l1 + len1 - 1;
            for (int len2 = 1; len2 <= m; len2++) {
                for (int l2 = 1; l2 + len2 - 1 <= m; l2++) {
                    int r2 = l2 + len2 - 1;
                    if (len1 == 1 && len2 == 1) {
                        if (a[l1] == b[l2])
                            dp[l1][r1][l2][r2] = 1;
                    } else if (len1 >= 2 && len2 >= 2) {
                        if (a[l1] == a[r1] && b[l2] == b[r2] && a[l1] == b[l2])
                            dp[l1][r1][l2][r2] = dp[l1 + 1][r1 - 1][l2 + 1][r2 - 1] + 2;
                    }
                    if (len1 > 1) {
                        dp[l1][r1][l2][r2] = max({
                            dp[l1][r1][l2][r2],
                            dp[l1 + 1][r1][l2][r2],
                            dp[l1][r1 - 1][l2][r2]
                        });
                    }
                    if (len2 > 1) {
                        dp[l1][r1][l2][r2] = max({
                            dp[l1][r1][l2][r2],
                            dp[l1][r1][l2 + 1][r2],
                            dp[l1][r1][l2][r2 - 1]
                        });
                    }
                    ans = max(ans, dp[l1][r1][l2][r2]);
                }
            }
        }
    }
    cout << dp[1][n][1][m] << "\n";
    
    return 0;
}