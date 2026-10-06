#pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e15;

vector <pii> E;
int dis[505][505];
int edge[505][505];

signed main()
{
    IO;
    
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        fill(&dis[0][0], &dis[0][0] + 505 * 505, INF);
        fill(&edge[0][0], &edge[0][0] + 505 * 505, INF);
        int a, b;
        for (int i = 1; i <= m; i++) {
            cin >> a >> b;
            E.push_back({a, b});
            dis[a][b] = 1;
            edge[a][b] = 1;
        }

        int ans = INF;
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i < k; i++) {
                for (int j = i + 1; j < k; j++) {
                    ans = min(ans, edge[i][k] + edge[k][j] + dis[j][i]);
                    ans = min(ans, edge[k][i] + edge[j][k] + dis[i][j]);
                }
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        if (ans == INF) /// 無環
            cout << 0 << "\n";
        else
            cout << ans << "\n";
    }
    
    
    return 0;
}