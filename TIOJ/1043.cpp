#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
// const ll INF = 1e18;
const int INF = 2e9;


const int N = 10005;
int a[N];
int dp[N];

signed main()
{
    IO
    
    int n, m;
    while (cin >> n >> m) {
        if (!n && !m) break;
        for (int i = 1; i <= n; i++) cin >> a[i];
        fill(dp, dp + N, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (j - a[i] >= 0)
                    dp[j] += dp[j - a[i]];
            }
        }
        cout << dp[m] << "\n";
    }
    
    return 0;
}