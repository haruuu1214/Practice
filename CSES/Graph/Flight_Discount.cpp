#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define piii pair<int, pii>
using namespace std;

vector<pii> G[200005];
int dis[200005][2];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(&dis[0][0], &dis[0][0] + 200005 * 2, 1e18);
    int n, m, i;
    cin >> n >> m;
    int a, b, c;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }

    priority_queue<piii, vector<piii>, greater<piii>> pq;

    dis[1][0] = dis[1][1] = 0;
    pq.push({0, {1, 0}});
    while (!pq.empty()) {
        int w = pq.top().first;
        int v = pq.top().second.first;
        int use = pq.top().second.second;
        pq.pop();
        if (dis[v][use] != w)
            continue;
        for (pii u : G[v]) {
            if (w + u.second < dis[u.first][use]) {
                dis[u.first][use] = w + u.second;
                pq.push({dis[u.first][use], {u.first, use}});
            }
            if (!use && w + (u.second / 2) < dis[u.first][1]) {
                dis[u.first][1] = w + (u.second / 2);
                pq.push({dis[u.first][1], {u.first, 1}});
            }
        }
    }
    cout << dis[n][1] << "\n";

    return 0;
}