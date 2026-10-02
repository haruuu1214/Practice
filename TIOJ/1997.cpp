#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const ll INF = 1e15;

const int N = 1000005;

int a[N];
ll pre[N];
ll dp[7][N];
int from[7][N];
ll m[7];

signed main()
{
    IO
    
    int n, k;
    cin >> n >> k;

    m[0] = 1;
    for (int i = 1; i <= k; i++) m[i] = -m[i - 1];

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];

    fill(&dp[0][0], &dp[0][0] + 7 * N, -INF);
    dp[0][0] = 0;
    
    for (int i = 1; i <= k; i++) {
        ll res = dp[i - 1][0];
        int best = 0;
        for (int j = 1; j <= n; j++) {
            // dp[i][j] = dp[i - 1][best] + m[i - 1] * (pre[j] - pre[best]);
            dp[i][j] = m[i - 1] * pre[j] + res;
            from[i][j] = best;
            if (dp[i - 1][j] - m[i - 1] * pre[j] > res) {
                res = dp[i - 1][j] - m[i - 1] * pre[j];
                best = j;
            }
        }
    }

    int x = k, y = n;
    while (x != 1) {
        y = from[x][y];
        x--;
        cout << y << "\n";
    }
    return 0;
}