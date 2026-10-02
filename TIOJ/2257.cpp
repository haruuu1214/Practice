#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
#define STL(x) for(auto &HEHE:x) cout << HEHE << " "; cout << "\n";
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

int bit[200005], in[100005], out[100005];

int query(int idx)
{
    int sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val)
{
    while (idx <= 200000) {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

vector <int> G[100005];
pii E[100005];
int a[200005];
int depth[100005];
int timecnt = 0;

void dfs(int v, int p)
{
    in[v] = ++timecnt;
    a[in[v]] = (p == -1 ? 0 : 1);
    depth[v] = (p == -1 ? 1 : depth[p] + 1);
    for (int u : G[v]) {
        if (u == p) continue;
        dfs(u, v);
    }
    out[v] = ++timecnt;
    a[out[v]] = (p == -1 ? 0 : -1);
}

signed main()
{
    IOS
    
    int n, s, q1, q2;
    cin >> n >> s >> q1 >> q2;
    int v, u;
    for (int i = 1; i <= n - 1; i++) {
        cin >> v >> u;
        G[v].push_back(u);
        G[u].push_back(v);
        E[i] = {v, u};
    }

    dfs(s, -1);
    
    for (int i = 1; i <= 2 * n; i++) {
        update(i, a[i]);
    }

    int q = q1 + q2;

    int op, x, y;
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            int mul = query(in[y]);
            cout << x * mul << "\n";
        } else {
            cin >> x;
            v = E[x].first;
            u = E[x].second;
            if (depth[v] < depth[u])
                swap(v, u);
            update(in[v], -1);
            update(out[v], 1);
        }
    }
    
    return 0;
}