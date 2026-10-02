#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

void solve() {
    int x[3], y[3];
    FOR (i, 0, 2) cin >> x[i] >> y[i];
    pii p[2];
    FOR (i, 0, 1)
        p[i] = {x[i + 1] - x[i], y[i + 1] - y[i]};
    int cro = p[0].first * p[1].second - p[0].second * p[1].first;
    if ((x[0] == x[1] && y[0] == y[1]) ||
        (x[0] == x[2] && y[0] == y[2]) ||
        (x[2] == x[1] && y[2] == y[1]))
        cout << "YES\n";
    else if (cro == 0)
        cout << "NO\n";
    else
        cout << "YES\n";
}

signed main() {
    IO;
    
    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}