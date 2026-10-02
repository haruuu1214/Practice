#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= b; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pii> v(n);
    FOR(i, 0, n - 1) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    int ans = 0, tot = 0;
    for (auto [x, y] : v) {
        if (tot < m) {
            int now = min(m - tot, y);
            tot += now;
            ans += x * now;
        }
    }
    if (tot < m)
        cout << "so sad\n";
    else
        cout << ans << "\n";
}

signed main() {
    IO;
    
    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}