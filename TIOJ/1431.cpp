#include <bits/stdc++.h>
#define int long long
#define ll __int128_t
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

int C(int n, int k) {
    __int128 x = 1;
    FOR (i, n - k + 1, n) x *= i;
    FOR (i, 1, k) x /= i;
    int _x = x;
    return _x;
}

void solve() {
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (char c : s)
        cnt[c - 'a'] += 1;
    int odd = 0;
    FOR (i, 0, 25)
        if (cnt[i] & 1)
            odd += 1;
    if (odd >= 2) {
        cout << 0 << "\n";
        return;
    }
    vector<int> v;
    int tot = 0;
    FOR (i, 0, 25)
        if (cnt[i] > 1) {
            v.push_back(cnt[i] / 2);
            tot += cnt[i] / 2;
        }
    int ans = 1;
    for (int i : v) {
        ans *= C(tot, i);
        tot -= i;
    }
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