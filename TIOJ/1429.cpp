#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;
vector<int> G[N];
int k;
priority_queue<int, vector<int>, less<int>> Q[N];
int sz[N], dp[N];
int a[N], b[N]; // 出動費用、領導力
int ans = 0;

void dfs(int v) {
    int mx = 0;
    for (int u : G[v]) {
        dfs(u);
        if (sz[u] > sz[mx])
            mx = u;
    }
    swap(Q[v], Q[mx]);
    int res = dp[mx];
    for (int u : G[v]) {
        if (u == mx) continue;
        int x;
        while (! Q[u].empty()) {
            x = Q[u].top();
            Q[u].pop();
            if (res + x <= k) {
                res += x;
                Q[v].push(x);
            } else if (! Q[v].empty() && Q[v].top() > x) {
                res -= Q[v].top();
                Q[v].pop();
                res += x;
                Q[v].push(x);
            }
        }
    }
    if (res + a[v] <= k) {
        res += a[v];
        Q[v].push(a[v]);
    } else if (! Q[v].empty() && Q[v].top() > a[v]) {
        res -= Q[v].top();
        Q[v].pop();
        res += a[v];
        Q[v].push(a[v]);
    }
    ans = max(ans, (int)Q[v].size() * b[v]);
    sz[v] = (int)Q[v].size();
    dp[v] = res;
}

signed main() {
    IO;
    
    int n;
    cin >> n >> k;
    int root = -1;
    int p;
    FOR(i, 1, n) {
        cin >> p >> a[i] >> b[i];
        if (p == 0)
            root = i;
        else
            G[p].push_back(i);
    }
    dfs(root);
    cout << ans << "\n";
    
    return 0;
}