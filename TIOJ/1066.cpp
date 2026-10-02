#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 20005;
int a[5] = {1, 5, 10, 20, 50};
int b[5];
int c[5];

void solve() {
    int x;
    cin >> x;
    int cnt = 0;
    for (int i = 0; i < 5; i++) cin >> b[i];
    for (int i = 0; i < 5; i++) cin >> c[i];
    for (int i = 0; i < 5; i++) {
        c[i] += b[i];
        x -= a[i] * b[i];
        b[i] = 0;
    }
    x = -x;
    int ans = 0;
    for (int i = 4; i >= 0; i--) {
        int to_give = x / a[i];
        int really_give = min(to_give, c[i]);
        ans += really_give;
        x -= really_give * a[i];
    }
    cout << ans << "\n";
}

signed main() {
    IO
    
    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}