#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

const int INF = 1e17;
const int N = 5005;
vector<pair<pii, int>> E;
int par[N];
int dis[N];

signed main() {
    int n, m;
    cin >> n >> m;
    int v, u, w;
    for (int i = 1; i <= m; i++) {
        cin >> v >> u >> w;
        E.push_back({{v, u}, w});
    }
    for (int i = 1; i <= n; i++) {
        for (auto [p, w] : E) {
            auto [v, u] = p;
            if (dis[v] + w < dis[u]) {
                dis[u] = dis[v] + w;
                par[u] = v;
            }
        }
    }
    int cyc_vertex = -1;
    {
        for (auto [p, w] : E) {
            auto [v, u] = p;
            if (dis[v] + w < dis[u])
                cyc_vertex = u;
        }
    }
    if (cyc_vertex == -1) {
        cout << "NO" << "\n";
        return 0;
    }
    cout << "YES" << "\n";
    for (int i = 1; i <= n; i++)
        cyc_vertex = par[cyc_vertex];
    vector<int> cyc;
    int fst = cyc_vertex;
    cyc.push_back(fst);
    cyc_vertex = par[fst];
    while (cyc_vertex != fst) {
        cyc.push_back(cyc_vertex);
        cyc_vertex = par[cyc_vertex];
    }
    cyc.push_back(fst);
    reverse(cyc.begin(), cyc.end());
    for (int v : cyc)
        cout << v << " ";
    return 0;
}