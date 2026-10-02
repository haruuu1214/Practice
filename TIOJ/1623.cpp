#include <bits/stdc++.h>
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;
const int INF = 2e9;


const int N = 2005;
int a[N];

signed main() {
    IO;
    
    int n, k, m;
    cin >> n >> k >> m;
    FOR (i, 1, n) cin >> a[i];

    vector<int> dp(n + 1, INF), cap(n + 1, INF);
    dp[0] = 0; cap[0] = m;
    for (int i = 1; i <= n; i++) {
        vector<int> ndp(n + 1, INF), ncap(n + 1, INF);
        ndp[0] = 0; ncap[0] = m;
        for (int j = 1; j <= i; j++) {
            ndp[j] = dp[j];
            ncap[j] = cap[j];
            if (cap[j - 1] + a[i] <= m) {
                if (make_pair(dp[j - 1], cap[j - 1] + a[i]) < make_pair(ndp[j], ncap[j])) {
                    ndp[j] = dp[j - 1];
                    ncap[j] = cap[j - 1] + a[i];
                }
            } else if (a[i] <= m) {
                if (make_pair(dp[j - 1] + 1, a[i]) < make_pair(ndp[j], ncap[j])) {
                    ndp[j] = dp[j - 1] + 1;
                    ncap[j] = a[i];
                }
            }
        }
        swap(dp, ndp);
        swap(cap, ncap);
    }

    int ans = 0;
    for (int j = 1; j <= n; j++)
        if (dp[j] <= k)
            ans = max(ans, j);
    cout << ans << "\n";
    
    return 0;
}