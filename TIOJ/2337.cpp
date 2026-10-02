#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
using namespace std;

const int mod = 998244353;
const int INF = 1e18;

const int N = 205;
bool vis[N];
bool fail[N];
int n, m, t;
vector<int> order;
vector<string> a;
int ans = INF;

void dfs(int Q, int res) {
    if (res >= ans)
        return;
    if (Q == m) {
        ans = min(ans, res);
        return;
    }
    bool fg = true;
    for (int i = 0; i < n; i++)
        if (! fail[i])
            fg = false;
    if (fg) {
        ans = min(ans, res);
        return;
    }
    int best = -1;
    vector<int> cand;
    for (int j = 0; j < m; j++) {
        if (vis[j]) continue;
        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += (a[i][j] == 'X' && ! fail[i]);
        if (cnt > best) {
            best = cnt;
            cand.clear();
            cand.push_back(j);
        } else if (cnt == best) {
            cand.push_back(j);
        }
    }
    for (int j : cand) {
        int ti = 0;
        vector<int> upd;
        for (int i = 0; i < n; i++) {
            if (! fail[i]) {
                ti += 1;
                if (a[i][j] == 'X') {
                    fail[i] = true;
                    upd.push_back(i);
                }
            }
        }
        vis[j] = true;
        dfs(Q + 1, res + ti * t);
        vis[j] = false;
        for (int i : upd)
            fail[i] = false;
    }
}

signed main() {
    IO;
    
    cin >> n >> m >> t;
    a.resize(n);
    FOR (i, 0, n - 1)
        cin >> a[i];
    
    dfs(0, 0);
    
    cout << ans << "\n";
    
    return 0;
}
/*

4 3 1
XOX
OXO
XXO
OOX

6 3 1
XXO
XXO
OXO
XOX
XOX
OOX

*/