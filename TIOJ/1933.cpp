#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;
pii a[N];
int dp[N];

void solve() {
    int n, l, c;
    cin >> n >> l >> c;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].second += a[i].first;
    }
    sort(a + 1, a + n + 1, [&](pii p, pii q) {
        return p.second < q.second;
    });
    vector<int> tim;
    for (int i = 1; i <= n; i++) tim.push_back(a[i].second);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int from = upper_bound(tim.begin(), tim.end(), a[i].first) - tim.begin();
        from = min(from, i - 1);
        dp[i] = max(dp[i - 1], dp[from] + c - a[i].second);
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