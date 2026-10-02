#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

signed main() {
    IO;
    
    int n, m;
    cin >> n >> m;
    vector <pii> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), [](pii p, pii q) {
        return p.second > q.second;
    });
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (cnt < m) {
            ans += min(v[i].first, m - cnt) * v[i].second;
            cnt += min(v[i].first, m - cnt);
        }
    cout << ans << "\n";
    
    return 0;
}