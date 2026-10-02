#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 2e9;


const int N = 2005;
vector <int> G[N];
bool vis[N];
int match[N];

bool dfs(int v) {
    vis[v] = true;
    for (int u : G[v]) {
        if (match[u] == -1 || (!vis[match[u]] && dfs(match[u]))) {
            match[u] = v;
            return true;
        }
    }
    return false;
}
int n, m;

void solve() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        fill(vis, vis + N, false);
        if (dfs(i))
            ans++;
    }
    cout << ans << "\n";
}

signed main() {
    IO
    
    int a, b;
    int t = 1;
    while (cin >> n >> m) {
        if (!n && !m) break;
        fill(G, G + N, vector<int>());
        fill(match, match + N, -1);
        for (int i = 1; i <= m; i++) {
            cin >> a >> b;
            G[a].push_back(n + b);
        }
        cout << "Case #" << t << ":";
        solve();
        ++t;
    }

    
    return 0;
}