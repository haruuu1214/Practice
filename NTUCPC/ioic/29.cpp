#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 300005;

vector<int> G[N];
int id[N];
vector<int> vec[2];
bool vis[N];

void dfs(int i, int v) {
    vis[v] = true;
    for (; id[v] < (int)G[v].size(); ) {
        int u = G[v][id[v]];
        id[v] += 1;
        dfs(i, u);
    }
    vec[i].push_back(v);
}

int in[N], out[N];

signed main() {
    IO;
    
    int n, m;
    cin >> n >> m;
    bool fg = true;
    int v, u;
    for (int i = 1; i <= m; i++) {
        cin >> v >> u;
        G[v].push_back(u);
        out[v] += 1;
        in[u] += 1;
    }

    for (int i = 2; i <= n - 1; i++)
        if (in[i] != out[i])
            fg = false;
    if (in[1] + 1 != out[1])
        fg = false;
    if (in[n] != out[n] + 1)
        fg = false;
    
    if (! fg) {
        cout << 0 << "\n";
        return 0;
    }

    fill(id, id + N, 0);
    dfs(0, 1);
    
    fill(id, id + N, 0);
    for (int i = 1; i <= n; i++)
        reverse(G[i].begin(), G[i].end());
    dfs(1, 1);

    bool same = true;
    for (int i = 0; i < m + 1; i++)
        if (vec[0][i] != vec[1][i])
            same = false;
    
    bool con = true;
    for (int i = 1; i <= n; i++)
        if (! vis[i])
            con = false;
    if (! con) {
        cout << 0 << "\n";
    } else if (! same) {
        cout << 2 << "\n";
        reverse(vec[0].begin(), vec[0].end());
        for (int i = 0; i < m; i++)
            cout << vec[0][i] << " " << vec[0][i + 1] << "\n";
    } else {
        cout << 1 << "\n";
        reverse(vec[0].begin(), vec[0].end());
        for (int i = 0; i < m; i++)
            cout << vec[0][i] << " " << vec[0][i + 1] << "\n";
    }
    
    return 0;
}
/*

4 2
1 2
3 4

*/