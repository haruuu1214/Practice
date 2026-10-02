#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

const int mod = 998244353;
const int INF = 2e9;


const int N = 100005;

int calc(int dis) {
    int l = 0, r = INF;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (mid * (mid + 1) / 2 <= dis)
            l = mid;
        else
            r = mid;
    }
    if (l * (l + 1) / 2 == dis)
        return l;
    else if (((l + 1) * (l + 2) / 2 - dis) % 2 == 0)
        return l + 1;
    else if (((l + 2) * (l + 3) / 2 - dis) % 2 == 0)
        return l + 2;
    else
        return l + 3;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = INF;
    ans = min(ans, calc(n - k));
    ans = min(ans, calc(k - 0));
    cout << ans << "\n";
}

signed main() {
    IO;
    
    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}