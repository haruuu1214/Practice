#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
using namespace std;

const int mod = 998244353;
const int INF = 1e18;

const int N = 100005;

struct Flow {
    struct edge {
        int u, rc, rev;
    };
    vector<vector<edge>> G;
    vector<int> dis, it;
    vector<bool> vis;
    Flow(int n) : G(n + 1), dis(n + 1), it(n + 1), vis(n + 1) {}
    void add(int v, int u, int c) {
        G[v].push_back({u, c, (int)G[u].size()});
        G[u].push_back({v, 0, (int)G[v].size() - 1});
    }
    int dfs(int v, int t, int cap) {
        if (v == t || cap <= 0) return cap;
        for (int &i = it[v]; i < (int)G[v].size(); i++) {
            auto &[u, rc, rev] = G[v][i];
            if (rc <= 0 || dis[u] != dis[v] + 1) continue;
            int res = dfs(u, t, min(cap, rc));
            if (res <= 0) continue;
            rc -= res;
            G[u][rev].rc += res;
            return res;
        }
        return 0;
    }
    int flow(int s, int t) {
        int ans = 0;
        while (true) {
            fill(all(dis), INT_MAX);
            queue<int> Q;
            dis[s] = 0;
            Q.push(s);
            while (! Q.empty()) {
                int v = Q.front(); Q.pop();
                for (auto [u, rc, rev] : G[v]) {
                    if (rc <= 0 || dis[u] < INT_MAX) continue;
                    dis[u] = dis[v] + 1;
                    Q.push(u);
                }
            }
            if (dis[t] == INT_MAX) break;

            fill(all(it), 0);
            while (true) {
                int res = dfs(s, t, INT_MAX);
                if (res <= 0) break;
                ans += res;
            }
        }
        return ans;
    }
    void bfs_pass(int s) {
        queue<int> Q;
        vis[s] = true;
        Q.push(s);
        while (! Q.empty()) {
            int v = Q.front(); Q.pop();
            for (auto [u, rc, rev] : G[v]) {
                if (! vis[u] && rc > 0) {
                    vis[u] = true;
                    Q.push(u);
                }
            }
        }
    }
};

signed main() {
    IO;
    
    int m, n;
    cin >> m >> n;
    int v, u;
    Flow flow(2 * n + 1);

    int s = 0, t = 2 * n + 1;
    for (int i = 1; i <= n; i++)
        flow.add(s, i, 1);
    for (int i = 1; i <= n; i++)
        flow.add(n + i, t, 1);
    
    for (int i = 1; i <= m; i++) {
        cin >> v >> u;
        flow.add(v, n + u, INT_MAX);
    }
    int ans = flow.flow(s, t);
    flow.bfs_pass(s);
    vector<int> ans1, ans2;
    {
        int v = s;
        for (auto [u, rc, rev] : flow.G[v]) {
            if (flow.vis[v] && ! flow.vis[u] && rc == 0)
                ans1.push_back(u);
        }
    }
    {
        int u = t;
        for (auto [v, rc, rev] : flow.G[u]) {
            if (flow.vis[v] && ! flow.vis[u] && flow.G[v][rev].rc == 0)
                ans2.push_back(v - n);
        }
    }
    cout << ans1.size() << " " << ans2.size() << "\n";
    for (int i : ans1) cout << i << " "; cout << "\n";
    for (int i : ans2) cout << i << " "; cout << "\n";
    
    return 0;
}