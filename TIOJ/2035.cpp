#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

signed main() {
    IO;
    
    int mul[10];
    int a, n;
    cin >> a >> n;
    
    mul[0] = 1;
    for (int i = 1; i <= 9; i++) mul[i] = mul[i - 1] * a;

    int _n = n;
    int res1 = 0;
    int i = 0;
    while (n > 0) {
        res1 += (n % 10) * mul[i++];
        n /= 10;
    }

    int len = i;
    n = _n;
    int res2 = 0;
    while (n > 0) {
        int x = n % 10, tmp = 1;
        for (int i = 1; i <= len; i++) tmp *= x;
        res2 += tmp;
        n /= 10;
    }
    cout << (res1 == res2 ? "YES\n" : "NO\n");

    return 0;
}