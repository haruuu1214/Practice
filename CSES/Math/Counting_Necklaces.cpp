#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;


const int N = 100005;

int fastpow(int a, int b) {
    int ans = 1, res = a;
    while (b > 0) {
        if (b & 1) ans = (ans * res) % mod;
        res = (res * res) % mod;
        b >>= 1;
    }
    return ans;
}

signed main() {
    IO;
    
    int n, m;
    cin >> n >> m;

    int ans = 0;
    for (int x = 0; x < n; x++) {
        /// one group has (n / gcd(n, x)) pearls
        /// so, there are (n / (n / gcd(n, x))) groups
        int group = n / (n / __gcd(n, x));
        ans = (ans + fastpow(m, group)) % mod;
    }
    ans = (ans * fastpow(n, mod - 2)) % mod;
    cout << ans << "\n";
    
    return 0;
}