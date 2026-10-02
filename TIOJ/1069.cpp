#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
// const ll INF = 1e18;
const int INF = 2e9;


const int N = 1005;
vector <int> G[N];
bool vis[N];
int match[N];
int t[N], x[N], y[N];

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
/*
1
3
1 1 1
2 3 3
4 2 2
*/
void solve() {
    int n;
    cin >> n;
    fill(vis, vis + N, false);
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> x[i] >> y[i];
        G[i].clear();
        match[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (t[i] < t[j] && abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[j] - t[i])
                G[i].push_back(j);
        }
    }
    int ans = n;
    for (int i = 1; i <= n; i++) {
        fill(vis, vis + N, false);
        if (dfs(i))
            ans--;
    }
    cout << ans << "\n";
}

signed main() {
    IO
    
    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}