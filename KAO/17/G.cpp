#pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector <int> f, sz;
void init(int n) {
    f.resize(n + 1);
    iota(f.begin(), f.end(), 0);
    sz.assign(n + 1, 1);
}

int find(int x) {
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    f[y] = x;
    return true;
}

bool same(int x, int y) {
    return (find(x) == find(y));
}

const int N = 500005;
vector <pii> G[N];
int par[19][N], mx_w[19][N], depth[N];
bitset <500005> used;

void bfs(int x) {
    queue <int> Q;
    depth[x] = 1;
    Q.push(x);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (auto [u, w] : G[v]) {
            if (!depth[u]) {
                mx_w[0][u] = w;
                par[0][u] = v;
                depth[u] = depth[v] + 1;
                Q.push(u);
            }
        }
    }
}

void build(int n) {
    for (int i = 1; i <= n; i++)
        if (!depth[i])
            bfs(i);
    for (int i = 1; i < 19; i++) {
        for (int j = 1; j <= n; j++) {
            mx_w[i][j] = max(mx_w[i - 1][j], mx_w[i - 1][par[i - 1][j]]);
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }
}

int query(int v, int u) {
    int mx = 0;
    if (depth[v] < depth[u])
        swap(v, u);
    int step = depth[v] - depth[u];
    for (int i = 0; i < 19; i++) {
        if (step & (1 << i)) {
            mx = max(mx, mx_w[i][v]);
            v = par[i][v];
        }
    }
    if (v == u) return mx;
    for (int i = 18; i >= 0; i--) {
        if (par[i][v] != par[i][u]) {
            mx = max(mx, mx_w[i][v]);
            mx = max(mx, mx_w[i][u]);
            v = par[i][v];
            u = par[i][u];
        }
    }
    mx = max(mx, mx_w[0][v]);
    mx = max(mx, mx_w[0][u]);
    return mx;
}

struct edge {
    int x, y, wei;
};
vector <edge> E;

signed main() {
    IO;
    
    int n, m;
    cin >> n >> m;
    
    int a, b, c;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        E.push_back({a, b, i});
    }
    init(n);
    for (auto &[v, u, w] : E) {
        if (!same(v, u)) {
            merge(v, u);
            G[v].push_back({u, w});
            G[u].push_back({v, w});
        } else {
            used[w] = true;
        }
    }
    build(n);
    
    for (auto &[v, u, w] : E) {
        if (!used[w]) {
            cout << "Mukyu\n";
            continue;
        }
        int res = query(v, u);
        if (res == w) {
            cout << "Mukyu\n";
        } else {
            cout << res << "\n";
        }
    }

    return 0;
}