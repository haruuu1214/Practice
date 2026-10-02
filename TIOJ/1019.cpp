#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 1005;
int a[N];
int dp[N];

void solve() {
    int n;
    cin >> n;
    FOR (i, 1, n) cin >> a[i];
    dp[0] = INF;
    dp[1] = 0;
    FOR (i, 2, n) {
        dp[i] = min(dp[i - 2] + abs(a[i] - a[i - 2]), dp[i - 1] + abs(a[i] - a[i - 1]));
    }
    cout << dp[n] << "\n";
}

signed main() {
    IO;
    
    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}