#include <bits/stdc++.h>
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

const int N = 50005;
struct edge {
    int to, w, fir, rev_fir, len;
};
vector<edge> G[N];
int depth[N];
int par[16][N];
int dp1[16][60][N], dp2[16][60][N];

void dfs(int v, int p) {
    depth[v] = (p == -1 ? 1 : depth[p] + 1);
    for (auto [u, w, fir, rev_fir, len] : G[v]) {
        if (u == p) continue;
        par[0][u] = v;
        int tar = rev_fir;
        for (int i = 0; i < 60; i++) {
            dp1[0][i][u] = tar - i + w;
            if (tar == i)
                tar += len;
        }
        tar = fir;
        for (int i = 0; i < 60; i++) {
            dp2[0][i][u] = tar - i + w;
            if (tar == i)
                tar += len;
        }
        dfs(u, v);
    }
}

int dis[16][N];

void dfs_sub2(int v, int p) {
    depth[v] = (p == -1 ? 1 : depth[p] + 1);
    for (auto [u, w, fir, rev_fir, len] : G[v]) {
        if (u == p) continue;
        par[0][u] = v;
        dis[0][u] = w + 1;
        dfs_sub2(u, v);
    }
}

int jump(int a, int x) {
    for (int i = 0; i < 16; i++)
        if (x & (1 << i))
            a = par[i][a];
    return a;
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int x = depth[a] - depth[b];
    for (int i = 0; i < 16; i++)
        if (x & (1 << i))
            a = par[i][a];
    if (a == b)
        return a;
    for (int i = 15; i >= 0; i--) {
        if (par[i][a] != par[i][b]) {
            a = par[i][a];
            b = par[i][b];
        }
    }
    return par[0][a];
}

int solve(int m, int from, int to) {
    int mid = lca(from, to);
    int ans = 0, now_time = m;
    int now = from, x = depth[from] - depth[mid];
    for (int i = 0; i < 16; i++)
        if (x & (1 << i)) {
            now_time = (m + ans) % 60;
            ans += dp1[i][now_time][now] + 1;
            now = par[i][now];
        }
    x = depth[to] - depth[mid];
    int has_walk = 0;
    for (int i = 0; i < 16; i++) {
        if (x & (1 << i)) {
            now_time = (m + ans) % 60;
            ans += dp2[i][now_time][jump(to, x - has_walk - (1 << i))] + 1;
            has_walk ^= (1 << i);
        }
    }
    if (from != to)
        ans -= 1;
    return ans;
}

int solve_sub2(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int x = depth[a] - depth[b], ans = 0;
    for (int i = 0; i < 16; i++)
        if (x & (1 << i)) {
            ans += dis[i][a];
            a = par[i][a];
        }
    if (a == b)
        return ans - 1;
    for (int i = 15; i >= 0; i--) {
        if (par[i][a] != par[i][b]) {
            ans += dis[i][a];
            ans += dis[i][b];
            a = par[i][a];
            b = par[i][b];
        }
    }
    ans += dis[0][a];
    ans += dis[0][b];
    return ans - 1;
}

signed main() {
    IO;
    
    bool sub2 = true;
    int n, q, v, u, w, a, b, p;
    cin >> n >> q;
    FOR (i, 1, n - 1) {
        cin >> v >> u >> w >> a >> b >> p;
        G[v].push_back({u, w, a, b, p});
        G[u].push_back({v, w, b, a, p});
        if (p != 1) sub2 = false;
    }

    if (sub2) {
        dfs_sub2(1, -1);
        for (int i = 1; i < 16; i++)
            for (int j = 1; j <= n; j++)
                par[i][j] = par[i - 1][par[i - 1][j]];
        for (int i = 1; i < 16; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = dis[i - 1][j] + dis[i - 1][par[i - 1][j]];
        int h, m, s, t;
        while (q--) {
            cin >> h >> m >> s >> t;
            cout << solve_sub2(s, t) << "\n";
        }
        return 0;
    }

    dfs(1, -1);

    for (int i = 1; i < 16; i++)
        for (int j = 1; j <= n; j++)
            par[i][j] = par[i - 1][par[i - 1][j]];
    

    for (int i = 1; i < 16; i++) {
        for (int j = 1; j <= n; j++) {
            for (int m = 0; m < 60; m++) {
                int half_ti = dp1[i - 1][m][j] + 1, hf = par[i - 1][j];
                dp1[i][m][j] = half_ti + dp1[i - 1][(m + half_ti) % 60][hf];
                half_ti = dp2[i - 1][m][hf] + 1;
                dp2[i][m][j] = half_ti + dp2[i - 1][(m + half_ti) % 60][j];
            }
        }
    }

    int h, m, s, t;
    while (q--) {
        cin >> h >> m >> s >> t;
        cout << solve(m, s, t) << "\n";
    }
    
    return 0;
}
/*
5 3
1 2 1 0 0 1
2 3 10 0 0 1
1 4 100 0 0 1
4 5 1000 0 0 1
0 59 2 3
0 59 4 5
0 59 3 1
*/