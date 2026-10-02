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
    int n, x;
    cin >> n >> x;
    vector<int> v(n - 1);
    FOR(i, 0, n - 2) cin >> v[i];
    sort(v.begin(), v.end());
    int id = lower_bound(v.begin(), v.end(), x) - v.begin();
    cout << v[id] << " " << v[id - 1] << "\n";
}

signed main() {
    IO;
    
    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}