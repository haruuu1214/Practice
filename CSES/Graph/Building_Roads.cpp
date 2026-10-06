#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> G[100005];
bool vis[100005];

void dfs(int v, int p) {
    vis[v] = true;
    for (int u : G[v]) {
        if (u == p)
            continue;
        if (!vis[u])
            dfs(u, v);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int cnt = 0;
    vector<int> block;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, -1);
            block.push_back(i);
            cnt++;
        }
    }
    cout << cnt - 1 << "\n";
    for (int i = 0; i + 1 < (int)block.size(); i++) {
        cout << block[i] << " " << block[i + 1] << "\n";
    }

    return 0;
}
