#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 1005;
int a[N], dp[2][N][N];

signed main() {
    IO;
    
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    for (int len = 1; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if (len == 1) {
                dp[0][l][r] = abs(x - a[l]) * (n - len + 1);
                dp[1][l][r] = abs(x - a[l]) * (n - len + 1);
            } else {
                dp[0][l][r] = min(
                    dp[0][l + 1][r] + abs(a[l + 1] - a[l]) * (n - len + 1),
                    dp[1][l + 1][r] + abs(a[r] - a[l]) * (n - len + 1)
                );
                dp[1][l][r] = min(
                    dp[0][l][r - 1] + abs(a[l] - a[r]) * (n - len + 1),
                    dp[1][l][r - 1] + abs(a[r - 1] - a[r]) * (n - len + 1)
                );
            }
        }
    }
    cout << min(dp[0][1][n], dp[1][1][n]) << "\n";
    
    return 0;
}