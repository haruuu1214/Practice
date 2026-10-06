#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> G[100005];
vector<int> order;
int vis[100005];
bool pointed[100005];

bool dfs(int v) {
    vis[v] = 2;
    bool legal = true;
    for (int u : G[v]) {
        if (vis[u] == 2)
            return false;
        else if (vis[u] == 0)
            legal &= dfs(u);
    }
    vis[v] = 1;
    order.push_back(v);
    return legal;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        pointed[b] = 1;
    }

    vector<int> head;
    head.clear();
    for (int i = 1; i <= n; i++) {
        if (pointed[i] == 0)
            head.push_back(i);
    }

    bool legal = true;
    for (int x : head)
        legal &= dfs(x);

    if ((int)order.size() != n)
        legal = false;
    if (!legal)
        cout << "IMPOSSIBLE\n";
    else {
        reverse(order.begin(), order.end());
        for (int x : order)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}
