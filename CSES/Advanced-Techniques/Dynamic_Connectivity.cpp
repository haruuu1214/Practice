#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

vector<pii> seg[4 * N];
void add_event(int node, int l, int r, int ql, int qr, pii eve) {
    if (ql <= l && r <= qr) {
        seg[node].push_back(eve);
        return;
    }
    int mid = (l + r) >> 1;
    if (qr <= mid)
        add_event(2 * node, l, mid, ql, qr, eve);
    else if (mid + 1 <= ql)
        add_event(2 * node + 1, mid + 1, r, ql, qr, eve);
    else {
        add_event(2 * node, l, mid, ql, qr, eve);
        add_event(2 * node + 1, mid + 1, r, ql, qr, eve);
    }
}

int par[N], sz[N], tot;
stack<pair<int*, int>> stk_par, stk_sz;

int find(int x) {
    while (x != par[x]) x = par[x];
    return x;
}

bool merge(int v, int u) {
    v = find(v);
    u = find(u);
    if (v == u) return false;
    tot -= 1;
    if (sz[v] < sz[u]) swap(v, u);
    stk_par.push({& par[u], par[u]});
    stk_sz.push({& sz[v], sz[v]});
    par[u] = v;
    sz[v] += sz[u];
    return true;
}

void undo() {
    tot += 1;
    * stk_par.top().first = stk_par.top().second;
    * stk_sz.top().first = stk_sz.top().second;
    stk_par.pop();
    stk_sz.pop();
}

int ans[N];

void traversal(int node, int l, int r) {
    int cnt = 0;
    for (auto [v, u] : seg[node])
        if (merge(v, u))
            cnt += 1;
    if (l == r)
        ans[l] = tot;
    else {
        int mid = (l + r) >> 1;
        traversal(2 * node, l, mid);
        traversal(2 * node + 1, mid + 1, r);
    }
    while (cnt > 0) {
        undo();
        cnt -= 1;
    }
}

signed main() {
    IO;
    
    int n, m, q;
    cin >> n >> m >> q;

    tot = n;
    iota(par, par + n + 1, 0);
    fill(sz, sz + n + 1, 1);

    int T = q + 1;
    map<pii, pii> mp;
    int v, u;
    FOR (i, 1, m) {
        cin >> v >> u;
        if (v > u) swap(v, u);
        if (! mp.count({v, u}))
            mp[{v, u}] = {1, 1};
        else
            mp[{v, u}].second += 1;
    }
    int op;
    FOR (i, 2, q + 1) {
        cin >> op >> v >> u;
        if (v > u) swap(v, u);
        if (op == 1) {
            if (! mp.count({v, u}))
                mp[{v, u}] = {i, 1};
            else
                mp[{v, u}].second += 1;
        } else {
            mp[{v, u}].second -= 1;
            if (mp[{v, u}].second == 0) {
                add_event(1, 1, T, mp[{v, u}].first, i - 1, {v, u});
                mp.erase(mp.find({v, u}));
            }
        }
    }
    for (auto [key, val] : mp)
        add_event(1, 1, T, val.first, T, key);

    traversal(1, 1, T);

    FOR (i, 1, T) cout << ans[i] << " \n"[i == T];

    return 0;
}