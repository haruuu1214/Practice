#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


struct DSU
{
    int N;
    vector <int> f, sz;
    DSU(int x) {
        init(x);
    }
    void init(int n) {
        N = n;
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
};

const int N = 1005;

int dp[25][N], mx_w[25][N];
int depth[N];
vector <pii> G[N];
vector <pair<int, pii>> E;
vector <pair<int, pii>> not_used;

void dfs(int v, int p) {
    depth[v] = (p == -1 ? 0 : depth[p] + 1);
    for (auto &[u, w] : G[v]) {
        if (u == p) continue;
        dp[0][u] = v;
        mx_w[0][u] = w;
        dfs(u, v);
    }
}

void build(int n) {
    fill(&mx_w[0][0], &mx_w[0][0] + 25 * N, -1);
    dfs(1, -1);
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= n; j++) {
            mx_w[i][j] = max(mx_w[i - 1][j], mx_w[i - 1][dp[i - 1][j]]);
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
}

int get_max(int a, int b) {
    if (depth[a] > depth[b])
        swap(a, b);
    int mx = -1;
    int step = depth[b] - depth[a];
    for (int i = 0; i <= 20; i++)
        if (step & (1 << i)) {
            mx = max(mx, mx_w[i][b]);
            b = dp[i][b];
        }
    if (a == b)
        return mx;
    for (int i = 20; i >= 0; i--) {
        if (dp[i][a] != dp[i][b]) {
            mx = max(mx, mx_w[i][a]);
            mx = max(mx, mx_w[i][b]);
            a = dp[i][a];
            b = dp[i][b];
        }
    }
    mx = max(mx, mx_w[0][a]);
    mx = max(mx, mx_w[0][b]);
    return mx;
}

signed main() {
    IO
    
    int n, m, v, u, w;
    cin >> n >> m;
    int mn_add = INF;
    for (int i = 1; i <= m; i++) {
        cin >> v >> u >> w;
        if (v == u) {
            mn_add = min(mn_add, w);
            continue;
        }
        E.push_back({w, {v, u}});
    }
    sort(E.begin(), E.end());
    DSU d(n);

    int ans1 = 0;
    for (auto i : E) {
        int w = i.first;
        auto [v, u] = i.second;
        if (!d.same(v, u)) {
            ans1 += w;
            d.merge(v, u);
            G[v].push_back({u, w});
            G[u].push_back({v, w});
        } else {
            not_used.push_back({w, {v, u}});
        }
    }

    bool fg = true;
    for (int i = 1; i <= n - 1; i++)
        if (!d.same(i, i + 1))
            fg = false;

    if (!fg) {
        cout << -1 << " " << -1 << "\n";
        return 0;
    }

    build(n);

    int ans2 = INF;
    int chg = 0;
    for (auto i : not_used) {
        int w = i.first;
        auto [v, u] = i.second;
        chg = get_max(v, u);
        ans2 = min(ans2, ans1 - chg + w);
    }
    if (mn_add != INF)
        ans2 = min(ans2, ans1 + mn_add);
    
    if (ans2 == INF)
        cout << ans1 << " " << -1 << "\n";
    else
        cout << ans1 << " " << ans2 << "\n";
    
    return 0;
}