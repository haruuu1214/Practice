#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

vector <int> G[200005];
int p[200005];
int depth[200005];
int dp[200005][20];
int pre[200005];
int lg;

void dfs(int v, int par)
{
    dp[v][0] = par;
    p[v] = par;
    depth[v] = (par == -1 ? 1 : depth[par] + 1);
    for (int u : G[v]) {
        if (u == par) continue;
        dfs(u, v);
    }
}

int lca(int a, int b)
{
    if (depth[a] < depth[b]) swap(a, b);
    int step = depth[a] - depth[b];
    for (int i = 0; i <= 18; i++) {
        if (step & (1 << i))
            a = dp[a][i];
    }

    if (a == b) return a;

    for (int i = 18; i >= 0; i--) {
        if (dp[a][i] != dp[b][i]) {
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return dp[a][0];
}

void dfs2(int v, int par)
{
    for (int u : G[v]) {
        if (u == par) continue;
        dfs2(u, v);
        pre[v] += pre[u];
    }
}

signed main()
{
    IO;
    
    int n, q;
    cin >> n >> q;
    int a, b;
    for (int i = 1; i <= n - 1; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, 0);

    for (int lg = 1; lg <= 18; lg++) {
        for (int i = 1; i <= n; i++) {
            dp[i][lg] = dp[dp[i][lg - 1]][lg - 1];
        }
    }

    while (q--) {
        cin >> a >> b;
        int l = lca(a, b);
        pre[p[l]]--;
        pre[l]--;
        pre[a]++;
        pre[b]++;
    }

    dfs2(1, 0);

    for (int i = 1; i <= n; i++)
        cout << pre[i] << " ";
    cout << "\n";
    
    return 0;
}