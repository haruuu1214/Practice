#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> G[100005];
bool vis[100005];
bool color[100005];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i])
            continue;

        queue<int> q;
        q.push(i);
        vis[i] = 1;
        color[i] = true;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            bool next_color = !color[v];
            for (int u : G[v]) {
                if (vis[u]) {
                    if (color[u] != next_color) {
                        cout << "IMPOSSIBLE\n";
                        return 0;
                    }
                } else {
                    q.push(u);
                    vis[u] = true;
                    color[u] = next_color;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (int)color[i] + 1 << " ";
    }
    cout << "\n";
    return 0;
}
