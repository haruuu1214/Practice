#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define siz(x) (int)x.size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// ---------------------------------------------

const int N = 18;
const int mod = 998244353;
int x[N], y[N], dis[N][N];
int dp[N][1 << N], first_bit[1 << N], cyc[1 << N];

signed main() {
    IO;
    int n, c;
    cin >> n >> c;
    FOR (i, 0, n - 1) cin >> x[i] >> y[i];
    FOR (i, 0, n - 1) FOR (j, 0, n - 1) dis[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);

    for (int msk = 1; msk < (1 << n); msk++) {
        int x = 0;
        for (int i = 0; i < n; i++)
            if (msk >> i & 1) {
                x = i;
                break;
            }
        first_bit[msk] = x;
    }
    fill(&dp[0][0], &dp[0][0] + N * (1 << N), INT_MAX);
    for (int i = 0; i < n; i++) dp[i][1 << i] = 0;

    fill(cyc, cyc + (1 << N), INT_MAX);
    for (int msk = 1; msk < (1 << n); msk++) {
        for (int j = first_bit[msk]; j < n; j++) {
            if (dp[j][msk] == INT_MAX) continue;
            cyc[msk] = min(cyc[msk], dp[j][msk] + dis[j][first_bit[msk]] + c);
            for (int k = first_bit[msk] + 1; k < n; k++) {
                if (msk >> k & 1) continue;
                dp[k][msk ^ (1 << k)] = min(dp[k][msk ^ (1 << k)], dp[j][msk] + dis[j][k]);
            }
        }
    }
    for (int msk = 1; msk < (1 << n); msk++) {
        for (int s = msk; ; s = (s - 1) & msk) {
            if (cyc[msk ^ s] != INT_MAX && cyc[s] != INT_MAX)
                cyc[msk] = min(cyc[msk], cyc[msk ^ s] + cyc[s]);
            if (! s) break;
        }
    }
    cout << cyc[(1 << n) - 1] - c << "\n";
}