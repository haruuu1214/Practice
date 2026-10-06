#include <bits/stdc++.h>
#define int long long
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

struct BIT
{
    int N;
    vector <int> info;
    BIT(int n) : N(n), info(n + 1) {}
    void update(int idx, int val) {
        for (int i = idx; i <= N; i += i & -i)
            info[i] += val;
    }
    int query(int idx) {
        int res = 0;
        for (int i = idx; i > 0; i -= i & -i)
            res += info[i];
        return res;
    }
};
int a[200005];
vector <int> G[200005];
int in[200005];
int out[200005];
int timecnt = 0;

void dfs(int v, int p)
{
    in[v] = ++timecnt;
    for (int u : G[v]) {
        if (u == p) continue;
        dfs(u, v);
    }
    out[v] = ++timecnt;
}

signed main()
{
    IO;
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int v, u;
    for (int i = 1; i <= n - 1; i++) {
        cin >> v >> u;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    
    dfs(1, -1);

    BIT bit(2 * n);
    for (int i = 1; i <= n; i++) {
        bit.update(in[i], +a[i]);
        bit.update(out[i], -a[i]);
    }

    int op, x, y;
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            bit.update(in[x], y - a[x]);
            bit.update(out[x], a[x] - y);
            a[x] = y;
        } else {
            cin >> x;
            cout << bit.query(in[x]) << "\n";
        }
    }

    return 0;
}