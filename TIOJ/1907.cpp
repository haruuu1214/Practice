#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 1e18;

const int N = 100005;
pii a[N];

int bit[1005];
void update(int id, int val) {
    for (int i = id; i <= 1000; i += (i & -i))
        bit[i] = max(bit[i], val);
}

int query(int id) {
    int res = 0;
    for (int i = id; i > 0; i -= (i & -i))
        res = max(res, bit[i]);
    return res;
}

int dp[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1, [](pii p, pii q){
        if (p.first != q.first)
            return p.first < q.first;
        return p.second > q.second;
    });
    fill(bit, bit + 1005, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = query(a[i].second - 1);
        dp[i] = x + 1;
        ans = max(ans, dp[i]);
        update(a[i].second, dp[i]);
    }
    cout << ans << "\n";
}

signed main() {
    IOS
    
    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}