#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

int C[25][25];
int fac[25];

signed main() {
    IO
    
    for (int i = 0; i <= 20; i++) C[i][0] = 1;
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    
    fac[0] = 1;
    for (int i = 1; i <= 20; i++) fac[i] = fac[i - 1] * i;

    int n;
    while (cin >> n) {
        if (!n) break;
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            ans += ((i % 2 == n % 2) ? 1ll : -1ll) * C[n][i] * fac[i];
        }
        cout << ans << "\n";
    }
    
    return 0;
}