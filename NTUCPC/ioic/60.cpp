#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

signed main() {
    IO;
    
    int n, m, k;
    cin >> n >> m >> k;
    FOR (i, 1, n) {
        string s;
        cin >> s;
        if (k == 1) {
            cout << m << "\n";
            continue;
        }
        if (m == k) {
            int cnt = 0;
            for (int i = 0; i < m / 2; i++)
                if (s[i] != s[m - i - 1])
                    cnt += 1;
            cout << m - cnt << "\n";
            continue;
        }
        map<char, int> mp, mp1, mp2;
        for (int i = 0; i < m; i++) {
            mp[s[i]] += 1;
            if (i & 1)
                mp1[s[i]] += 1;
            else
                mp2[s[i]] += 1;
        }
        int ans = 0, mx = 0;
        for (auto [key, val] : mp)
            mx = max(mx, val);
        ans = max(ans, mx);
        if (k & 1) {
            int mx1 = 0, mx2 = 0;
            for (auto [key, val] : mp1)
                mx1 = max(mx1, val);
            for (auto [key, val] : mp2)
                mx2 = max(mx2, val);
            ans = max(ans, mx1 + mx2);
        }
        cout << ans << "\n";
    }
    
    return 0;
}