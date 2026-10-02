#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;


const int N = 100005;
int dp[2][15][1 << 15];

signed main() {
    IO;
    
    int n, m;
    cin >> n >> m;
    swap(n, m);
    dp[0][m][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int mask = 0; mask < (1 << m); mask++)
            dp[i & 1][0][mask << 1] = dp[(i - 1) & 1][m][mask];
        for (int j = 1; j <= m; j++) {
            for (int mask = 0; mask < (1 << (m + 1)); mask++) {
                int D = mask & (1 << (j - 1));
                int R = mask & (1 << j);
                if (D && R) {
                    dp[i & 1][j][mask] = 0;
                } else if (!D && !R) {
                    dp[i & 1][j][mask] = (dp[i & 1][j - 1][mask ^ (1 << (j - 1))] + dp[i & 1][j - 1][mask ^ (1 << j)]) % mod;
                } else {
                    dp[i & 1][j][mask] = dp[i & 1][j - 1][mask ^ D ^ R];
                }
            }
        }
    }
    cout << dp[n & 1][m][0] << "\n";
    
    return 0;
}