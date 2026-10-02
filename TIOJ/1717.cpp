#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;
vector<int> G[N];
int in[N];
int dp[N];
int cst[N];

void solve() {
    int n, m, x;
    cin >> n;
    fill(G, G + n + 1, vector<int>());
    for (int i = 1; i <= n; i++) dp[i] = in[i] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> cst[i];
        cin >> m;
        for (int j = 1; j <= m; j++) {
            cin >> x;
            in[x] += 1;
            G[i].push_back(x);
        }
    }
    queue <int> Q;
    for (int i = 1; i <= n; i++)
        if (!in[i]) {
            dp[i] = cst[i];
            Q.push(i);
        }
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int u : G[v]) {
            in[u] -= 1;
            dp[u] = max(dp[u], dp[v] + cst[u]);
            if (!in[u])
                Q.push(u);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    cout << ans << "\n";
}
 
signed main() {
    IO;
    
    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}