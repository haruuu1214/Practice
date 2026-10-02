#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

const int INF = 1e18;

const int N = 1005;
#define all(x) x.begin(), x.end()

struct Dinic {
    struct E {int v, c, r, rc;};
    vector<vector<E>> adj;
    vector<int> vis, dis, it;
    Dinic(int n) : adj(n), vis(n), dis(n), it(n) {}
    void add(int u, int v, int c, int d = 0) {
        adj[u].push_back({v, c, (int)adj[v].size(), c});
        adj[v].push_back({u, d, (int)adj[u].size() - 1, d});
    }
    bool bfs(int s, int t) {    
        fill(all(dis), INF);
        queue<int> Q;
        Q.push(s); dis[s] = 0;
        while (! Q.empty()) {
            int u = Q.front(); Q.pop();
            for (const auto& [v, c, r, rc] : adj[u]) {
                if (dis[v] < INF || rc == 0) continue;
                dis[v] = dis[u] + 1;
                Q.push(v);
            }
        }
        return dis[t] < INF;
    }
    int dfs(int u, int t, int cap) {
        if (u == t || cap == 0) return cap;
        vis[u] = true;
        for (int &i = it[u]; i < (int)adj[u].size(); i++) {
            auto &[v, c, r, rc] = adj[u][i];
            if (dis[u] + 1 != dis[v]) continue;
            int tmp = dfs(v, t, min(cap, rc));
            if (tmp > 0) {
                rc -= tmp;
                adj[v][r].rc += tmp;
                return tmp;
            }
        }
        return 0;
    }
    int flow(int s, int t) {
        int ans = 0, tmp;
        while (bfs(s, t)) {
            fill(all(vis), false);
            fill(all(it), 0);
            while ((tmp = dfs(s, t, INF)) > 0)
                ans += tmp;
        }
        return ans;
    }
    bool is_cut(int u) { return dis[u] < INF; }
};

typedef tuple<int, int, int> Edge;
vector<Edge> gomoryHu(int N, vector<Edge> ed) {
    vector<Edge> tree;
    vector<int> par(N, 0);
    for (int i = 1; i < N; i++) {
        Dinic din(N);
        for (const auto &[u, v, w] : ed) {
            din.add(u, v, w, w);
        }
        tree.emplace_back(i, par[i], din.flow(i, par[i]));
        for (int j = i + 1; j < N; j++)
            if (par[j] == par[i] && din.is_cut(j))
                par[j] = i;
    }
    return tree;
}

int par[20][N], dis[20][N], depth[N];
vector<pii> G[N];
void dfs(int v, int p) {
    depth[v] = (p == -1 ? 1 : depth[p] + 1);
    for (auto x : G[v]) {
        auto [u, w] = x;
        if (u == p) continue;
        dfs(u, v);
        dis[0][u] = w;
        par[0][u] = v;
    }
}

int query(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int step = depth[a] - depth[b];
    int ans = INF;
    for (int i = 0; i < 20; i++)
        if ((1 << i) & step) {
            ans = min(INF, dis[i][a]);
            a = par[i][a];
        }
    if (a == b) return ans;
    for (int i = 19; i >= 0; i--) {
        if (par[i][a] != par[i][b]) {
            ans = min(ans, dis[i][a]);
            ans = min(ans, dis[i][b]);
            a = par[i][a];
            b = par[i][b];
        }
    }
    ans = min(ans, dis[0][a]);
    ans = min(ans, dis[0][b]);
    return ans;
}

signed main() {
    IO;
    
    int n, m, q;
    cin >> n >> m >> q;
    vector<Edge> ed(m);
    int tot = 0;
    for (auto &e : ed) {
        auto &[u, v, c] = e;
        cin >> u >> v >> c;
        --u;
        --v;
        tot += c;
    }

/*
4 6 6
1 2 9
1 3 6
1 4 1
2 3 1
2 4 4
3 4 2
1 2
1 3
1 4
2 3
2 4
3 4
*/
 
    vector<Edge> e2 = gomoryHu(n, ed);
    
    for (auto e : e2) {
        auto &[u, v, c] = e;
        u += 1;
        v += 1;
        G[v].push_back({u, c});
        G[u].push_back({v, c});
        // cout << u << " " << v << " " << c << "\n";
    }
    fill(&dis[0][0], &dis[0][0] + 20 * N, INF);
    dfs(1, -1);
    for (int i = 1; i < 20; i++)
        for (int j = 1; j <= n; j++)
            par[i][j] = par[i - 1][par[i - 1][j]];

    for (int i = 1; i < 20; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] = min(dis[i - 1][j], dis[i - 1][par[i - 1][j]]);
    
    int s, t;
    while (q--) {
        cin >> s >> t;
        cout << tot - query(s, t) << "\n";
    }

    return 0;
}