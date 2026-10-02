#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

vector <int> G[100005];
int depth[100005];
bool vis[100005];

void dfs(int v, int p)
{
    vis[v] = true;
    depth[v] = (p == -1 ? 1 : depth[p] + 1);
    for (int u : G[v]) {
        if (u == p) continue;

        if (vis[u]) {
            if (depth[u] > depth[v])
                cout << v << " " << u << "\n";
        } else {
            cout << v << " " << u << "\n";
            dfs(u, v);
        }
    }
}

signed main()
{
    IOS
    
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
    
    return 0;
}