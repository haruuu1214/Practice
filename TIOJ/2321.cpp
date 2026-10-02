#include <bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 2e9;


const int N = 200005;
vector <int> G[N];
int in[N], out[N];
int travs[2 * N];
int vertex[2 * N];
int num[2 * N];
int ti = 0;
int dp[20][N], depth[N];

void dfs(int v, int p = 0) {
    depth[v] = (p == 0 ? 1 : depth[p] + 1);
    dp[0][v] = p;
    in[v] = ++ti;
    vertex[in[v]] = v;
    for (int u : G[v]) {
        if (u == p) continue;
        dfs(u, v);
    }
    out[v] = ++ti;
    vertex[out[v]] = v;
}

int lca(int v, int u) {
    if (depth[v] > depth[u]) swap(v, u);
    int step = depth[u] - depth[v];
    for (int i = 0; i < 20; i++)
        if (step & (1 << i))
            u = dp[i][u];
    if (v == u) return v;
    for (int i = 19; i >= 0; i--)
        if (dp[i][v] != dp[i][u]) {
            v = dp[i][v];
            u = dp[i][u];
        }
    return dp[0][v];
}

int walk(int v, int step) {
    for (int i = 0; i < 20; i++)
        if (step & (1 << i))
            v = dp[i][v];
    return v;
}

bool root[N];

signed main() {
    IO;
    
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    dfs(1);

    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
    int M = ti;
    int q;
    cin >> q;
    int a_son;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        if (lca(a, b) == a) {
            a_son = walk(b, depth[b] - depth[a] - 1);
            num[1] += 1;
            num[in[a_son]] -= 1;
            num[out[a_son] + 1] += 1;
            num[M + 1] -= 1;
        } else {
            num[in[a]] += 1;
            num[out[a] + 1] -= 1;
        }
    }
    int cnt = 0;
    int sum = 0;
    for (int i = 1; i <= M; i++) {
        sum += num[i];
        if (sum == q && ! root[vertex[i]]) {
            root[vertex[i]] = true;
            ++cnt;
        }
    }
    cout << cnt << "\n";
    for (int i = 1; i <= n; i++)
        if (root[i])
            cout << i << " ";
    cout << "\n";

    return 0;
}
/*
7
1 2
2 3
3 5
2 4
4 6
4 7
3
3 2
2 1
3 5
*/