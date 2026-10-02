#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
using namespace std;

const int mod = 998244353;
const int INF = 1e18;

const int N = 1005;
bool coin[N][N];
int U[N], D[N];
bool dp[N][N], up_dp[N][N], down_dp[N][N];

signed main() {
    IO;
    
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    ++s; ++t;
    char c;
    fill(U, U + N, n + 1);

    FOR (i, 1, n)
        FOR (j, 1, m) {
            cin >> c;
            if (c == '1') {
                coin[i][j] = true;
                U[j] = min(U[j], i);
                D[j] = max(D[j], i);
            }
        }
    FOR (i, 1, m)
        if (U[i] > D[i])
            U[i] = D[i] = -1;

    if (U[1] == -1) {
        FOR (i, 1, n) dp[i][1] = true;
    } else if (s <= U[1]) {
        FOR (i, D[1], n) dp[i][1] = true;
    } else if (s >= D[1]) {
        FOR (i, 1, U[1]) dp[i][1] = true;
    }
    for (int i = 1; i <= n; i++)
        up_dp[i][1] = (up_dp[i - 1][1] | dp[i][1]);
    for (int i = n; i >= 1; i--)
        down_dp[i][1] = (down_dp[i + 1][1] | dp[i][1]);

    for (int j = 2; j <= m; j++) {
        if (U[j] == -1) {
            bool suc = false;
            for (int i = 1; i <= n; i++)
                if (dp[i][j - 1])
                    suc = true;
            if (suc) {
                for (int i = 1; i <= n; i++)
                    dp[i][j] = true;
            }
        } else {
            if (up_dp[U[j]][j - 1]) {
                for (int i = D[j]; i <= n; i++)
                    dp[i][j] = true;
            }
            if (down_dp[D[j]][j - 1]) {
                for (int i = 1; i <= U[j]; i++)
                    dp[i][j] = true;
            }
        }
        
        for (int i = 1; i <= n; i++)
            up_dp[i][j] = (up_dp[i - 1][j] | dp[i][j]);
        for (int i = n; i >= 1; i--)
            down_dp[i][j] = (down_dp[i + 1][j] | dp[i][j]);
    }
    cout << (dp[t][m] ? "Yes\n" : "No\n");

    return 0;
}