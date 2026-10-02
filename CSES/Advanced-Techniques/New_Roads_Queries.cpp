#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 200005;
int dsu[N], sz[N];
int find(int x) {
    if (x == dsu[x]) return x;
    return dsu[x] = find(dsu[x]);
}

void merge(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a != b) {
        if (sz[b] > sz[a]) swap(a, b);
        dsu[b] = a;
        sz[a] += sz[b];
    }
}

vector<pii> G[N];
int par[19][N], mx_w[19][N], depth[N];
bool vis[N];
void dfs(int v, int p) {
    vis[v] = true;
    for (auto [u, w] : G[v]) {
        if (u == p) continue;
        depth[u] = depth[v] + 1;
        par[0][u] = v;
        mx_w[0][u] = w;
        dfs(u, v);
    }
}

void build(int n) {
    FOR (i, 1, n)
        if (! vis[i])
            dfs(i, -1);
    FOR (i, 1, 18) {
        FOR (j, 1, n) {
            mx_w[i][j] = max(mx_w[i - 1][j], mx_w[i - 1][par[i - 1][j]]);
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }
}

signed main() {
    IO;
    
    iota(dsu, dsu + N, 0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> E;
    int v, u;
    FOR (i, 1, m) {
        cin >> v >> u;
        if (find(v) != find(u)) {
            merge(v, u);
            G[v].push_back({u, i});
            G[u].push_back({v, i});
        }
    }

    build(n);

    while (q--) {
        cin >> v >> u;
        if (find(v) != find(u)) {
            cout << -1 << "\n";
        } else {
            if (depth[v] < depth[u]) swap(v, u);
            int ans = 0, step = depth[v] - depth[u];
            FOR (i, 0, 18)
                if (step & (1 << i)) {
                    ans = max(ans, mx_w[i][v]);
                    v = par[i][v];
                }
            if (v == u) {
                cout << ans << "\n";
                continue;
            }
            for (int i = 18; i >= 0; i--) {
                if (par[i][v] != par[i][u]) {
                    ans = max(ans, mx_w[i][v]);
                    ans = max(ans, mx_w[i][u]);
                    v = par[i][v];
                    u = par[i][u];
                }
            }
            ans = max(ans, mx_w[0][v]);
            ans = max(ans, mx_w[0][u]);
            cout << ans << "\n";
        }
    }
    
    return 0;
}