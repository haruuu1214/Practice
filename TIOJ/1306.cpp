#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;
vector<int> f;

void build(string s) {
    f.clear();
    f.assign(s.size(), -1);
    for (int i = 1; i < (int)s.size(); i++) {
        int j = f[i - 1];
        while (j != -1 && s[i] != s[j + 1])
            j = f[j];
        if (s[i] == s[j + 1])
            f[i] = j + 1;
    }
}

int match(string s, string t) {
    int ans = 0;
    for (int i = 0, j = -1; i < (int)t.size(); i++) {
        while (j != -1 && t[i] != s[j + 1])
            j = f[j];
        if (t[i] == s[j + 1])
            j += 1;
        if (j + 1 == s.size()) {
            ans += 1;
            j = f[j];
        }
    }
    return ans;
}

void solve() {
    string s, t;
    cin >> s;
    int q;
    cin >> q;
    while (q--) {
        cin >> t;
        build(t);   
        cout << match(t, s) << "\n";
    }
}

signed main() {
    IO;
    
    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}