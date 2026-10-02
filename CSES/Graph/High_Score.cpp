#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

const int INF = 1e17;
const int N = 5005;
vector<int> G[N], rev_G[N];
vector<pair<pii, int>> E;
int dis[N];
int par[N];
bool front_vis[N], back_vis[N];

void go_front(int v) {
    front_vis[v] = true;
    for (int u : G[v]) {
        if (!front_vis[u])
            go_front(u);
    }
}

void go_back(int v) {
    back_vis[v] = true;
    for (int u : rev_G[v]) {
        if (!back_vis[u])
            go_back(u);
    }
}

signed main() {
    int n, m;
    cin >> n >> m;
    int a, b, c;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        E.push_back({{a, b}, c});
        G[a].push_back(b);
        rev_G[b].push_back(a);
    }
    fill(dis, dis + N, -INF);
    dis[1] = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (auto [p, w] : E) {
            auto [v, u] = p;
            if (dis[v] != -INF && dis[v] + w > dis[u]) {
                dis[u] = dis[v] + w;
                par[u] = v;
            }
        }
    }
    /// n-th time
    vector<int> cyc;
    {
        for (auto [p, w] : E) {
            auto [v, u] = p;
            if (dis[v] != -INF && dis[v] + w > dis[u])
                cyc.push_back(v);
        }
    }
    // for (int i = 1; i <= n - 1; i++)
    //     for (auto &v : cyc)
    //         v = par[v];
    go_front(1);
    go_back(n);
    for (int v : cyc) {
        if (front_vis[v] && back_vis[v]) {
            cout << -1 << "\n";
            return 0;
        }
    }
    cout << dis[n] << "\n";
    return 0;
}
