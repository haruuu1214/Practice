#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

vector<int> G[50005], rev_G[50005], topo_G[50005];
vector<int> order;
bool vis[50005];
int scc[50005], in[50005];
array<bitset<50005>, 50005> dp;

void dfs1(int v) {
    vis[v] = true;
    for (int u : rev_G[v]) {
        if (!vis[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int block_id) {
    scc[v] = block_id;
    for (int u : G[v]) {
        if (scc[u] == -1)
            dfs2(u, block_id);
    }
}

int get_scc(int N) {
    fill(vis, vis + 50005, 0);
    for (int i = 1; i <= N; i++) {
        if (!vis[i])
            dfs1(i);
    }
    fill(scc, scc + 50005, -1);
    int scc_cnt = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (scc[order[i]] == -1)
            dfs2(order[i], ++scc_cnt);
    }
    return scc_cnt;
}

signed main() {
    IO;

    int n, m, q;
    cin >> n >> m >> q;
    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        rev_G[b].push_back(a);
    }

    int scc_cnt = get_scc(n);

    for (int v = 1; v <= n; v++) {
        for (int u : G[v]) {
            if (scc[v] != scc[u]) {
                topo_G[scc[v]].push_back(scc[u]);
                in[scc[u]]++;
            }
        }
    }

    order.clear();
    queue<int> Q;
    for (int i = 1; i <= scc_cnt; i++) {
        if (!in[i])
            Q.push(i);
    }

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        order.push_back(v);
        for (int u : topo_G[v]) {
            in[u]--;
            if (!in[u])
                Q.push(u);
        }
    }

    for (int i = scc_cnt - 1; i >= 0; i--) {
        int v = order[i];
        dp[v][v] = true;
        for (int u : topo_G[v])
            dp[v] |= dp[u];
    }

    while (q--) {
        cin >> a >> b;
        cout << (dp[scc[a]][scc[b]] ? "YES" : "NO") << "\n";
    }

    return 0;
}