/**
 * dp(0) = 1
 * dp(n) = sigma_0 ~ n - 1 (dp(i) * dp(n - i - 1))
 *       = (1 / (n + 1)) * C(2n, n)
*/
#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 1e9 + 7;
int invfac[1000005], fac[1000005];

int mul(int a, int b)
{
    return (a * b) % mod;
}

int fastpow(int a, int k)
{
    int ans = 1, res = a;
    while (k > 0) {
        if (k & 1) ans = (ans * res) % mod;
        res = (res * res) % mod;
        k >>= 1;
    }
    return ans;
}

signed main()
{
    IOS
    
    int MX = 1000000;
    fac[0] = 1;
    for (int i = 1; i <= MX; i++)
        fac[i] = (fac[i - 1] * i) % mod;

    invfac[MX] = fastpow(fac[MX], mod - 2);
    for (int i = MX; i >= 1; i--)
        invfac[i - 1] = (invfac[i] * i) % mod;
    
    int n;
    cin >> n;

    if (n % 2 == 1) {
        cout << 0 << "\n";
        return 0;
    }

    n /= 2;

    cout << mul(fastpow(n + 1, mod - 2), mul(fac[2 * n], mul(invfac[n], invfac[n]))) << "\n";
    
    return 0;
}