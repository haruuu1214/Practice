#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const ll INF = 1e18;


const int N = 1005;
int a[N];
int dp[N][N];
int sum = 0;

void solve() {
    int n;
    cin >> n;
    int tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp >> a[i + 1];
        if (i == 1) a[1] = tmp;
    }
    ++n;
    fill(&dp[0][0], &dp[0][0] + N * N, INF);
    for (int i = 1; i <= n - 1; i++)
        dp[i][i + 1] = 0;
    for (int l = n; l >= 1; l--) {
        for (int r = l + 2; r <= n; r++) {
            for (int k = l + 1; k <= r - 1; k++) {
                if (r - l + 1 == 3)
                    dp[l][r] = a[l] * a[k] * a[r];
                else {
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r] + a[l] * a[k] * a[r]);
                }
            }
        }
    }
    int res = (dp[1][n] + 1000 - 1) / 1000;
    cout << res << "\n";
    sum += dp[1][n];
}

signed main()
{
    IO
    
    int t;
    cin >> t;
    while (t--)
        solve();
    cout << (sum + 1000 - 1) / 1000 << "\n";

    return 0;
}