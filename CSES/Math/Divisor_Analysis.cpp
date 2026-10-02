#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 1e9 + 7;

int fastpow(int a, int b) {
    int res = a, ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * res) % mod;
        res = (res * res) % mod;
        b /= 2;
    }
    return ans;
}

int inv(int x) { return fastpow(x, mod - 2); }

signed main()
{
    IOS
    
    int n;

    cin >> n;
    int p, k;
    int cnt = 1, cnt2 = 1;
    int sum = 1;
    int pro = 1;
    for (int i = 1; i <= n; i++) {
        cin >> p >> k;
        cnt = cnt * (k + 1) % mod;
        sum = sum * ((((fastpow(p, k + 1) - 1) % mod) * (inv(p - 1))) % mod) % mod;
        pro = fastpow(pro, k + 1) *
              fastpow(fastpow(p, k * (k + 1) / 2), cnt2) % mod;
        cnt2 = cnt2 * (k + 1) % (mod - 1);
    }
    cout << cnt << " " << sum << " " << pro << "\n";
    
    return 0;
}