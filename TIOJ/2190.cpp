#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;
int P;

int fastpow(int a, int b) {
    int res = a, ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * res) % P;
        res = (res * res) % P;
        b >>= 1;
    }
    return ans;
}

void solve() {
    int a, b, x1, y1, x2, y2;
    cin >> P >> a >> b >> x1 >> y1 >> x2 >> y2;
    int m = ((y2 - y1) % P) * (fastpow(x2 - x1, P - 2)) % P;
    int x3 = (((m * m) % P) - x1 - x2) % P;
    x3 = (x3 + P) % P;
    int y3 = ((m * x3 % P) + (y1 - (m * x1 % P))) % P;
    y3 = (y3 + P) % P;
    cout << x3 << " " << y3 << "\n";
}

signed main() {
    IO;
    
    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}