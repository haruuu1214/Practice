#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 1005;
vector <int> G[N];
int match[N];
bool vis[N];

bool dfs(int v) {
    vis[v] = true;
    for (int u : G[v]) {
        if (match[u] == -1 || (!vis[match[u]] && dfs(match[u]))) {
            match[u] = v;
            return true;
        }
    }
    return false;
}

signed main() {
    IO;
    
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        G[a].push_back(n + b);
    }
    fill(match, match + N, -1);
    for (int i = 1; i <= n; i++) {
        fill(vis, vis + N, false);
        dfs(i);
    }
    int cnt = 0;
    for (int i = 1; i <= 2 * n; i++)
        if (match[i] != -1)
            cnt++;
    cout << cnt << "\n";
    
    return 0;
}