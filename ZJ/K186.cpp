#include <bits/stdc++.h>
#define int long long 
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
const int INF = 1e17;

const int N = 100005;
vector<int> G[N];
int a[N];
int deg[N], tmp[N];
bool on_cyc[N];
vector<int> cyc;

void find_cycle(int n) {
    queue<int> Q;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 1)
            Q.push(i);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int u : G[v]) {
            deg[u] -= 1;
            if (deg[u] == 1)
                Q.push(u);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 2) {
            cyc.push_back(i);
            deg[i] = 1;
            for (int v = i; ; ) {
                bool fg = false;
                for (int u : G[v]) {
                    if (deg[u] == 2) {
                        v = u;
                        cyc.push_back(v);
                        deg[v] = 1;
                        fg = true;
                        break;
                    }
                }
                if (!fg)
                    break;
            }
            break;
        }
    }
    for (int i : cyc)
        on_cyc[i] = true;
}

int ans = -INF;
int h[2][N]; /// 不包含點 i 的 最大、第二大 垂直高度

void update_result(int v, int x) {
    for (int i = 0; i < 2; i++)
        if (x > h[i][v])
            swap(x, h[i][v]);
}

void solve(int n) {
    queue<int> Q;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 1) {
            Q.push(i);
            h[0][i] = 0;
        }
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        ans = max(ans, a[v] + h[0][v] + h[1][v]);
        ans = max(ans, a[v] + h[0][v]);
        if (on_cyc[v]) continue;
        h[0][v] = max(a[v], h[0][v] + a[v]);
        for (int u : G[v]) {
            update_result(u, h[0][v]);
            deg[u] -= 1;
            if (deg[u] == 1)
                Q.push(u);
        }
    }
}

int cyc_sum[N], tree_sum[N];
int pre[N], suf[N];

signed main() {
    IO;
    
    fill(&h[0][0], &h[0][0] + 2 * N, -INF);
    int n, m;
    cin >> n >> m;
    int v, u;
    for (int i = 1; i <= m; i++) {
        cin >> v >> u;
        G[v].push_back(u);
        G[u].push_back(v);
        tmp[v] += 1;
        tmp[u] += 1;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans = max(ans, a[i]);
    }

    if (n == m) {
        for (int i = 1; i <= n; i++) deg[i] = tmp[i];
        find_cycle(n);
        for (int i = 1; i <= n; i++) deg[i] = tmp[i];
        solve(n);
        int cyc_sz = cyc.size();
        for (int i = 0; i < cyc_sz; i++)
            cyc_sum[i] = a[cyc[i]];
        
        for (int i = 0; i < cyc_sz; i++)
            tree_sum[i] = h[0][cyc[i]];
        
        pre[0] = cyc_sum[0];
        for (int i = 1; i < cyc_sz; i++)
            pre[i] = pre[i - 1] + cyc_sum[i];
        
        suf[cyc_sz - 1] = cyc_sum[cyc_sz - 1];
        for (int i = cyc_sz - 2; i >= 0; i--)
            suf[i] = suf[i + 1] + cyc_sum[i];
        
        /// in : [ push : sum[i] - pre[i - 1] , count_ans : best + pre[i] + max(0, sum[i]) ]
        // out : [ push : sum[i] + pre[i] ,     count_ans : best + suf[i] + max(0, sum[i]) ]
        int in_best = -INF, out_best = -INF;
        for (int i = 0; i < cyc_sz; i++) {
            ans = max(ans, in_best + pre[i] + max(0ll, tree_sum[i]));
            ans = max(ans, out_best + suf[i] + max(0ll, tree_sum[i]));

            int _in = max(0ll, tree_sum[i]) - (i > 0 ? pre[i - 1] : 0ll);
            int _out = max(0ll, tree_sum[i]) + pre[i];
            in_best = max(in_best, _in);
            out_best = max(out_best, _out);
        }
    } else {
        for (int i = 1; i <= n; i++) deg[i] = tmp[i];
        solve(n);
    }
    cout << ans << "\n";

    return 0;
}