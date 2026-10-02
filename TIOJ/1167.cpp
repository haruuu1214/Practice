#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 1000005;
int a[N];

signed main() {
    IO;
    
    int n, k;
    while (cin >> n >> k) {
        if (!n && !k) break;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1, greater<int>());
        cout << a[k] << "\n";
    }
    
    return 0;
}