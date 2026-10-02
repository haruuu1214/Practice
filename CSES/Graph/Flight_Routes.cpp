#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

const int INF = 1e17;
const int N = 100005;

vector<pii> G[N];
int vis[N];

signed main() {
    int n, m, k;
    cin >> n >> m >> k;
    int v, u, w;
    for (int i = 1; i <= m; i++) {
        cin >> v >> u >> w;
        G[v].push_back({u, w});
    }
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    Q.push({0, 1});
    while (!Q.empty()) {
        auto [step, v] = Q.top();
        Q.pop();
        if (vis[v] >= k)
            continue;
        
        vis[v] += 1;
        if (v == n)
            cout << step << " ";
        
        for (auto [u, w] : G[v]) {
            if (vis[u] < k) {
                Q.push({step + w, u});
            }
        }
    }
    cout << "\n";
}