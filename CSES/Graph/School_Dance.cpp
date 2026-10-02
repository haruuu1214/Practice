#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

vector <int> G[505];
int match[505];
bool vis[505];

int dfs(int v)
{
    vis[v] = true;
    for (int u : G[v]) {
        if (match[u] == -1 || (!vis[match[u]] && dfs(match[u]))) {
            match[u] = v;
            return 1;
        }
    }
    return 0;
}

signed main()
{
    IOS
    
    int n, m, k;
    cin >> n >> m >> k;
    int a, b;
    for (int i = 1; i <= k; i++) {
        cin >> a >> b;
        G[a].push_back(b);
    }
    
    fill(match, match + 505, -1);

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        fill(vis, vis + 505, false);
        cnt += dfs(i);
    }
    cout << cnt << "\n";
    for (int i = 1; i <= m; i++) {
        if (match[i] > 0) {
            cout << match[i] << " " << i << "\n";
        }
    }

    return 0;
}