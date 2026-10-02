#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;
vector<pii> G[N];
int dis[N], in[N];

signed main() {
    IO;
    
    int n, m;
    cin >> n >> m;
    int a, b, w;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> w;
        G[a].push_back({b, w});
        in[b] += 1;
    }
    fill(dis, dis + N, INF);
    dis[1] = 0;
    queue<int> Q;
    for (int i = 1; i <= n; i++)
        if (!in[i])
            Q.push(i);
    
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (pii it : G[v]) {
            int u = it.first, w = it.second;
            in[u] -= 1;
            if (!in[u])
                Q.push(u);
            if (dis[v] != INF && dis[v] + w < dis[u])
                dis[u] = dis[v] + w;
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += dis[i];
    cout << sum << "\n";
    
    return 0;
}