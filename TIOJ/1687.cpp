#include <bits/stdc++.h>
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;


const int N = 100005;
vector<int> G[N];
int par[20][N];
int depth[N];

void dfs(int v, int p = 0) {
    depth[v] = depth[p] + 1;
    par[0][v] = p;
    for (int u : G[v]) {
        if (u == p) continue;
        dfs(u, v);
    }
}

void build(int n) {
    dfs(1);
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }
}
/// [lca, steps of  v <-> u]
pii lca(int v, int u) {
    if (depth[v] < depth[u]) swap(v, u);
    int step = depth[v] - depth[u];
    int cnt = step;
    for (int i = 0; i < 20; i++) {
        if (step & (1 << i))
            v = par[i][v];
    }
    if (v == u)
        return {v, cnt};
    for (int i = 19; i >= 0; i--) {
        if (par[i][v] != par[i][u]) {
            cnt += 2 * (1 << i);
            v = par[i][v];
            u = par[i][u];
        }
    }
    return {par[0][v], cnt + 2};
}

signed main() {
    IO;
    
    int n, q;
    cin >> n >> q;
    int a, b;
    for (int i = 1; i <= n - 1; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    build(n);
    int s, t, k;
    while (q--) {
        cin >> s >> t >> k;
        auto [mid, dis] = lca(s, t);
        int fst = lca(s, mid).second;
        int lst = dis - fst;
        if (k <= fst) {
            int res = s;
            for (int i = 0; i < 20; i++)
                if (k & (1 << i))
                    res = par[i][res];
            cout << res << "\n";
        } else if (k <= dis) {
            int res = t;
            k -= fst;
            k = lst - k;
            for (int i = 0; i < 20; i++)
                if (k & (1 << i))
                    res = par[i][res];
            cout << res << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}