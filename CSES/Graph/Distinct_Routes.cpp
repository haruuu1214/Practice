#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
using namespace std;

const int INF = 1e18;

struct Flow {
    struct edge {
        int u, rc, rev;
        bool tag;
    };
    int N;
    vector<vector<edge>> G;
    vector<int> dis, it;
    vector<bool> vis;
    Flow(int n) : N(n), G(n + 1), dis(n + 1), it(n + 1), vis(n + 1) {}
    void add(int v, int u, int c) {
        G[v].push_back({u, c, (int)G[u].size(), true});
        G[u].push_back({v, 0, (int)G[v].size() - 1, false});
    }
    int dfs(int v, int t, int cap) {
        if (v == t || cap <= 0) return cap;
        for (int &i = it[v]; i < (int)G[v].size(); i++) {
            auto &[u, rc, rev, tag] = G[v][i];
            if (dis[u] != dis[v] + 1 || rc <= 0) continue;
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
            dis[s] = 0;
            queue<int> Q;
            Q.push(s);
            while (! Q.empty()) {
                int v = Q.front();
                Q.pop();
                for (auto [u, rc, rev, tag] : G[v]) {
                    if (dis[u] < INT_MAX || rc <= 0) continue;
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
    vector<int> ret;
    bool find_a_route(int v) {
        if (vis[v]) return false;
        ret.push_back(v);
        if (v == N) return true;
        vis[v] = true;
        for (auto &[u, rc, rev, tag] : G[v]) {
            if (rc == 0 && tag == true) {
                if (find_a_route(u)) {
                    rc = 1;
                    vis[v] = false;
                    return true;
                }
            }
        }
        ret.pop_back();
        vis[v] = false;
        return false;
    }
};

signed main() {
    IO;
    
    int n, m;
    cin >> n >> m;
    Flow flow(n);
    int a, b, c;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        flow.add(a, b, 1);
    }
    int ans = flow.flow(1, n);
    cout << ans << "\n";
    for (int i = 1; i <= ans; i++) {
        flow.ret.clear();
        flow.find_a_route(1);
        cout << flow.ret.size() << "\n";
        for (int j : flow.ret)
            cout << j << " ";
        cout << "\n";
    }
    
    return 0;
}