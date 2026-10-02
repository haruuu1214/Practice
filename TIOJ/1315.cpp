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
    int a[3];
    FOR(i, 0, 2) cin >> a[i];
    sort(a, a + 3);
    __int128_t x = a[0], y = a[1], z = a[2];
    if (x + y > z && x * x + y * y == z * z)
        cout << "yes\n";
    else
        cout << "no\n";
}

signed main() {
    IO;
    
    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}