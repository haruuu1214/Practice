#pragma GCC optimize("Ofast, unroll-loops, O3")
#include <bits/stdc++.h>
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
using namespace std;


const int N = 200005;
int seg[4 * N], a[N], w[N];

void build(int node, int l, int r) {
    if (l == r) {
        seg[node] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build((node << 1), l, mid);
    build(((node << 1) | 1), mid + 1, r);
    seg[node] = max(seg[(node << 1)], seg[((node << 1) | 1)]);
}

void update(int node, int l, int r, int id, int va) {
    if (l == r) {
        seg[node] = va;
        return;
    }
    int mid = (l + r) >> 1;
    if (id <= mid)
        update((node << 1), l, mid, id, va);
    else
        update(((node << 1) | 1), mid + 1, r, id, va);
    seg[node] = max(seg[(node << 1)], seg[((node << 1) | 1)]);
}

int query(int node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return seg[node];
    int mid = (l + r) >> 1;
    if (qr <= mid) return query((node << 1), l, mid, ql, qr);
    else if (mid + 1 <= ql) return query(((node << 1) | 1), mid + 1, r, ql, qr);
    else return max(query((node << 1), l, mid, ql, qr), query(((node << 1) | 1), mid + 1, r, ql, qr));
}

vector<int> G[N];
int n, sz[N], mxson[N], par[N], depth[N], topf[N], id[N], idcnt = 0;

void dfs(int v, int p) {
    depth[v] = (p == -1 ? 0 : depth[p] + 1);
    sz[v] = 1;
    for (int u : G[v]) {
        if (u == p) continue;
        dfs(u, v);
        par[u] = v;
        sz[v] += sz[u];
        if (sz[u] > sz[mxson[v]]) mxson[v] = u;
    }
}

void dfs2(int v, int tp) {
    id[v] = ++idcnt;
    topf[v] = tp;
    if (mxson[v])
        dfs2(mxson[v], tp);
    for (int u : G[v]) {
        if (u == par[v] || u == mxson[v]) continue;
        dfs2(u, u);
    }
}

int split(int a, int b) {
    int res = 0;
    while (topf[a] != topf[b]) {
        if (depth[topf[a]] < depth[topf[b]]) swap(a, b);
        res = max(res, query(1, 1, n, id[topf[a]], id[a]));
        a = par[topf[a]];
    }
    if (depth[a] < depth[b]) swap(a, b);
    res = max(res, query(1, 1, n, id[b], id[a]));
    return res;
}

signed main() {
    IO;
    
    int q;
    cin >> n >> q;
    FOR (i, 1, n) cin >> w[i];
    int v, u;
    FOR (i, 1, n - 1) {
        cin >> v >> u;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    dfs(1, -1);
    dfs2(1, 1);
    FOR (i, 1, n) a[id[i]] = w[i];
    build(1, 1, n);
    int o, x;
    while (q--) {
        cin >> o;
        if (o == 1) {
            cin >> v >> x;
            update(1, 1, n, id[v], x);
        } else {
            cin >> v >> u;
            cout << split(v, u) << " ";
        }
    }
    
    return 0;
}