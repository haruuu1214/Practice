#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 2e9;


const int N = 100005;
vector <pii> G[N];
int dis[N][2];
int h[N][2];
int tmp;

void update_dis_max(int v, int x) {
    for (int i = 0; i < 2; i++) {
        if (x > dis[v][i])
            swap(x, dis[v][i]);
        else if (x == dis[v][i])
            break;
    }
}

void dfs(int v, int p) {
    for (auto [u, w] : G[v]) {
        if (u == p) continue;
        dfs(u, v);
        update_dis_max(v, h[v][0] + h[u][0] + w);
        update_dis_max(v, h[v][1] + h[u][0] + w);
        update_dis_max(v, h[v][0] + h[u][1] + w);
        tmp = h[u][0] + w;
        for (int i = 0; i < 2; i++) {
            if (tmp > h[v][i])
                swap(tmp, h[v][i]);
            else if (tmp == h[v][i])
                break;
        }
        tmp = h[u][1] + w;
        for (int i = 0; i < 2; i++) {
            if (tmp > h[v][i])
                swap(tmp, h[v][i]);
            else if (tmp == h[v][i])
                break;
        }
    }

    for (auto [u, w] : G[v]) {
        if (u == p) continue;
        update_dis_max(v, dis[u][0]);
        update_dis_max(v, dis[u][1]);
    }
}

signed main() {
    IO
    
    int n;
    cin >> n;
    int v, u, w;
    for (int i = 1; i <= n - 1; i++) {
        cin >> v >> u >> w;
        G[v].push_back({u, w});
        G[u].push_back({v, w});
    }
    dfs(0, -1);
    cout << dis[0][1] << "\n";
    
    return 0;
}