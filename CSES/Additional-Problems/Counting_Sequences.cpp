#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;
int fastpow(int a, int b)
{
    int ans = 1, res = a;
    while (b > 0) {
        if (b & 1) ans = (ans * res) % mod;
        res = (res * res) % mod;
        b >>= 1;
    }
    return ans;
}

int fac[1000005];
int invfac[1000005];

void init(int N)
{
    fac[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = (fac[i - 1] * i) % mod;
    
    invfac[N] = fastpow(fac[N], mod - 2);
    for (int i = N - 1; i >= 0; i--) {
        invfac[i] = (invfac[i + 1] * (i + 1)) % mod;
    }
}

int C(int n, int k)
{
    return (((fac[n] * invfac[k]) % mod) * invfac[n - k]) % mod;
}

signed main()
{
    IOS
    
    int n, k;
    cin >> n >> k;

    init(n);
    
    int sum = 0;
    for (int i = 0; i < k; i++) {
        if (i % 2 == 0)
            sum = (sum + (C(k, i) * fastpow(k - i, n)) % mod) % mod;
        else
            sum = (sum - (C(k, i) * fastpow(k - i, n)) % mod) % mod;
    }
    cout << (sum + mod) % mod << "\n";
    
    return 0;
}