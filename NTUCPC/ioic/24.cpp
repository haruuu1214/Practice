#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
using namespace std;

const int mod = 998244353;
const int INF = 1e18;

const int N = 1000005;
int fac[N], invfac[N];

int fastpow(int a, int b) {
    int ans = 1, res = a;
    while (b > 0) {
        if (b & 1) ans = ans * res % mod;
        res = res * res % mod;
        b >>= 1;
    }
    return ans;
}

signed main() {
    IO;
    
    fac[0] = invfac[0] = 1;
    fac[1] = 1;
    for (int i = 2; i <= 1000000; i++)
        fac[i] = fac[i - 1] * i % mod;
    invfac[1000000] = fastpow(fac[1000000], mod - 2);
    for (int i = 1000000 - 1; i >= 1; i--)
        invfac[i] = invfac[i + 1] * (i + 1) % mod;
    
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        // 2  1
        int ans = fac[n - 2] * invfac[n - k - 1] % mod;
        if (n - k - 2 < 0)
            ans = ans * fastpow(fastpow(n, -(n - k - 2)), mod - 2) % mod;
        else
            ans = ans * fastpow(n, n - k - 2) % mod;
        ans = ans * (k + 1) % mod;
        cout << ans << "\n";
    }
    
    return 0;
}