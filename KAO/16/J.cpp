#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define F first 
#define S second
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 300005;
vector <pii> G[N];
bool chs[N];
pii dis[N];

signed main() {
    IO;
    
    int n, m, k, a, b, c;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    for (int i = 1; i <= k; i++) {
        cin >> a;
        chs[a] = true;
    }
    
    /// [step, [v, start]]
    priority_queue <pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> Q;
    fill(dis, dis + N, make_pair(INF, -1));
    for (int i = 1; i <= n; i++)
        if (chs[i]) {
            Q.push({0, {i, i}});
            dis[i] = {0, i};
        }
    int ans = INF;
    while (!Q.empty()) {
        int step = Q.top().first;
        int v = Q.top().second.first;
        int strt = Q.top().second.second;
        Q.pop();
        if (step < dis[v].first)
            continue;
        for (auto &i : G[v]) {
            int u = i.first;
            int w = i.second;
            if (strt != dis[u].second)
                ans = min(ans, step + w + dis[u].first);
            if (step + w < dis[u].first) {
                dis[u] = {step + w, strt};
                Q.push({step + w, {u, strt}});
            }
        }
    }
    if (ans == INF)
        cout << "zombie\n";
    else
        cout << ans << "\n";

    return 0;
}