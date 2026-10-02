#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 45;
vector<int> G[N];
int dis[N][N];
mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
int col[N];

void dfs(int v) {
    int adj = 0;
    for (int u : G[v]) {
        if (col[u] != -1) {
            adj |= (1ll << col[u]);
        }
    }
    int x = 0;
    for (int i = 0; i < 40; i++) {
        if (adj & (1ll << i))
            x += 1;
        else
            break;
    }
    col[v] = x;
    for (int u : G[v])
        if (col[u] == -1)
            dfs(u);
}

signed main() {
    IO;
    
    fill(&dis[0][0], &dis[0][0] + N * N, INF);
    int n;
    cin >> n;
    int v, u;
    for (int i = 1; i < n; i++) {
        cin >> v >> u;
        dis[v][u] = 1;
        dis[u][v] = 1;
    }
    
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dis[i][j] == 2)
                G[i].push_back(j);
        }
    }

    vector<int> id(n);
    for (int i = 0; i < n; i++)
        id[i] = i + 1;
    int ans = 40;
    int t = 0;
    while (t <= 500) {
        t += 1;
        shuffle(id.begin(), id.end(), rng);
        fill(col, col + N, -1);
        for (int i : id) {
            if (col[i] == -1)
                dfs(i);
        }
        int mx = 0;
        for (int i = 1; i <= n; i++) mx = max(mx, col[i] + 1);
        ans = min(ans, mx);
    }
    cout << ans << "\n";
    
    return 0;
}