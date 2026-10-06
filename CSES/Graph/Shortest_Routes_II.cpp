#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
int dis[505][505];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(&dis[0][0], &dis[0][0] + 505 * 505, INF);
    int n, m, q;
    cin >> n >> m >> q;

    int a, b, c;

    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        dis[a][b] = min(dis[a][b], c);
        dis[b][a] = min(dis[b][a], c);
    }

    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    
    while (q--) {
        cin >> a >> b;
        if (dis[a][b] >= INF)
            cout << "-1\n";
        else
            cout << dis[a][b] << "\n";
    }

    return 0;
}