#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define F first
#define S second
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector <int> G[5005];
int dis[5005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, i, a, b;
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int ans = 1e18;

    for (int i = 1; i <= n; i++) { /// pass node i
        fill(dis, dis + 5005, 0);
        queue <pii> Q; /// [v, p]

        Q.push({i, -1});
        dis[i] = 1;

        while (!Q.empty()) {
            int v = Q.front().F;
            int p = Q.front().S;
            Q.pop();
            for (int u : G[v]) {
                if (u == p) continue;
                if (dis[u]) {
                    ans = min(ans, dis[v] + dis[u] - 1);
                } else {
                    dis[u] = dis[v] + 1;
                    Q.push({u, v});
                }
            }
        }
    }
    cout << (ans == 1e18 ? -1 : ans) << "\n";
    
    return 0;
}