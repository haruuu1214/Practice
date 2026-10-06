#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

const int N = 100005;
vector <int> G[N];
int vis[N], timer = 0;
bool odd[N];
vector <pii> E;

void dfs(int v, int p)
{
    vis[v] = ++timer;
    for (int u : G[v]) {
        if (u == p) continue;
        if (!vis[u]) {
            dfs(u, v);
            if (odd[u]) {
                E.push_back({u, v});
                odd[u] = 0;
            } else {
                E.push_back({v, u});
                odd[v] = (odd[v] == 1 ? 0 : 1);
            }
        } else if (vis[v] > vis[u]) {
            E.push_back({v, u});
            odd[v] = (odd[v] == 1 ? 0 : 1);
        }
    }
}

signed main()
{
    IO;
    
    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            dfs(i, -1);
    }

    bool F = true;
    for (int i = 1; i <= n; i++) {
        if (odd[i] == 1) {
            F = false;
            break;
        }
    }

    if (!F)
        cout << "IMPOSSIBLE\n";
    else {
        for (pii e : E)
            cout << e.first << " " << e.second << "\n";
    }

    return 0;
}