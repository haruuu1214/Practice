#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
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
    
    int n;
    cin >> n;

    int ans = 0;
    int group;
    /// x = 0
    {
        group = n * n;
        ans = (ans + fastpow(2, group)) % mod;
    }
    /// x = 1
    {
        if (n % 2 == 1)
            group = (n * n - 1) / 4 + 1;
        else
            group = n * n / 4;
        ans = (ans + fastpow(2, group)) % mod;
    }
    /// x = 2
    {
        if (n % 2 == 1)
            group = (n * n - 1) / 2 + 1;
        else
            group = n * n / 2;
        ans = (ans + fastpow(2, group)) % mod;
    }
    /// x = 3
    {
        if (n % 2 == 1)
            group = (n * n - 1) / 4 + 1;
        else
            group = n * n / 4;
        ans = (ans + fastpow(2, group)) % mod;
    }
    ans = (ans * fastpow(4, mod - 2)) % mod;
    cout << ans << "\n";
    
    return 0;
}