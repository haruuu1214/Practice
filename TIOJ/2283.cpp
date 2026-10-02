#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const ll INF = 1e18;

const int N = 200005;

vector <int> blk[N];
vector <int> vertex[N];
ll w[N], dis[N];
bool blk_vis[N];

signed main()
{
    IO
    
    int n, m, k, x;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> k >> w[i];
        for (int j = 1; j <= k; j++) {
            cin >> x;
            blk[i].push_back(x);
            vertex[x].push_back(i);
        }
    }

    fill(dis, dis + N, INF);
    priority_queue <pll, vector<pll>, greater<pll>> Q;
    dis[1] = 0;
    Q.push({0, 1});
    while (!Q.empty()) {
        auto [d, v] = Q.top();
        Q.pop();
        if (d != dis[v])
            continue;
        for (int id : vertex[v]) {
            if (blk_vis[id])
                continue;
            blk_vis[id] = true;
            for (int u : blk[id]) {
                if (d + w[id] < dis[u]) {
                    dis[u] = d + w[id];
                    Q.push({dis[u], u});
                }
            }
        }
    }
    ll mx = 0;
    for (int i = 1; i <= n; i++)
        mx = max(mx, dis[i]);
    if (mx == INF)
        cout << -1 << "\n";
    else
        cout << mx << "\n";
    
    return 0;
}