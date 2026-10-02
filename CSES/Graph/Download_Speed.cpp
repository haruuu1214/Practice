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
    };
    vector<vector<edge>> G;
    vector<int> dis, it;
    Flow(int n) : G(n + 1), dis(n + 1), it(n + 1) {}
    void add(int v, int u, int c) {
        G[v].push_back({u, c, (int)G[u].size()});
        G[u].push_back({v, 0, (int)G[v].size() - 1});
    }
    int dfs(int v, int t, int cap) {
        if (v == t || cap <= 0) return cap;
        for (int &i = it[v]; i < (int)G[v].size(); i++) {
            auto &[u, rc, rev] = G[v][i];
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
                for (auto [u, rc, rev] : G[v]) {
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
};

const int N = 100005;

signed main() {
    IO;
    
    int n, m;
    cin >> n >> m;
    Flow flow(n);
    int a, b, c;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        flow.add(a, b, c);
    }
    cout << flow.flow(1, n) << "\n";
    
    return 0;
}