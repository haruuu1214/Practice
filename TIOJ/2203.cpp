#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 1e9 + 7;
const int INF = 2e9;


const int N = 4 * 100005;
int mvv[N], v[N], vv[N], m[N], mv[N];
int tag_m[N], tag_v[N];

void applym(int node, int l, int r, int x) {
    int len = r - l + 1;
    tag_m[node] += x;
    tag_m[node] %= mod;
    m[node] += (x * len) % mod;
    m[node] %= mod;
    mv[node] += (x * v[node]) % mod;
    mv[node] %= mod;
    mvv[node] += (x * vv[node]) % mod;
    mvv[node] %= mod;
}

void applyv(int node, int l, int r, int x) {
    int len = r - l + 1;
    tag_v[node] += x;
    tag_v[node] %= mod;
    vv[node] += (((x * x) % mod) * len) % mod + (((2 * x) % mod) * v[node]) % mod;
    vv[node] %= mod;
    v[node] += (x * len) % mod;
    v[node] %= mod;
    mvv[node] += (((x * x) % mod) * m[node]) % mod + (((2 * x) % mod) * mv[node]) % mod;
    mvv[node] %= mod;
    mv[node] += (x * m[node]) % mod;
    mv[node] %= mod;
}

#define lc ((node << 1))
#define rc ((node << 1) | 1)
void push(int node, int l, int r) {
    int mid = (l + r) >> 1;
    if (tag_m[node]) {
        applym(lc, l, mid, tag_m[node]);
        applym(rc, mid + 1, r, tag_m[node]);
        tag_m[node] = 0;
    }
    if (tag_v[node]) {
        applyv(lc, l, mid, tag_v[node]);
        applyv(rc, mid + 1, r, tag_v[node]);
        tag_v[node] = 0;
    }
}

void pull(int node) {
    m[node] = (m[lc] + m[rc]) % mod;
    mv[node] = (mv[lc] + mv[rc]) % mod;
    mvv[node] = (mvv[lc] + mvv[rc]) % mod;
    v[node] = (v[lc] + v[rc]) % mod;
    vv[node] = (vv[lc] + vv[rc]) % mod;
}

void updatem(int node, int l, int r, int ql, int qr, int x) {
    if (ql <= l && r <= qr) {
        applym(node, l, r, x);
        return;
    }
    push(node, l, r);
    int mid = (l + r) >> 1;
    if (qr <= mid)
        updatem(lc, l, mid, ql, qr, x);
    else if (mid + 1 <= ql)
        updatem(rc, mid + 1, r, ql, qr, x);
    else {
        updatem(lc, l, mid, ql, qr, x);
        updatem(rc, mid + 1, r, ql, qr, x);
    }
    pull(node);
}

void updatev(int node, int l, int r, int ql, int qr, int x) {
    if (ql <= l && r <= qr) {
        applyv(node, l, r, x);
        return;
    }
    push(node, l, r);
    int mid = (l + r) >> 1;
    if (qr <= mid)
        updatev(lc, l, mid, ql, qr, x);
    else if (mid + 1 <= ql)
        updatev(rc, mid + 1, r, ql, qr, x);
    else {
        updatev(lc, l, mid, ql, qr, x);
        updatev(rc, mid + 1, r, ql, qr, x);
    }
    pull(node);
}

int query(int node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
        return mvv[node];
    push(node, l, r);
    int mid = (l + r) >> 1;
    if (qr <= mid)
        return query(lc, l, mid, ql, qr);
    else if (mid + 1 <= ql)
        return query(rc, mid + 1, r, ql, qr);
    else {
        return (query(lc, l, mid, ql, qr) + query(rc, mid + 1, r, ql, qr)) % mod;
    }
}

int fastpow(int a, int b)
{
    int ans = 1, res = a;
    while (b > 0) {
        if (b & 1) ans = (ans * res) % mod;
        res = (res * res) % mod;
        b >>= 1;
    }
    return ans;
}

signed main()
{
    IO
    
    int two = fastpow(2, mod - 2);
    int n, q;
    cin >> n >> q;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        updatem(1, 1, n, i, i, x);
    }
    for (int i = 1; i <= n; i++) {
        cin >> x;
        updatev(1, 1, n, i, i, x);
    }

    int op, l, r;
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> l >> r >> x;
            updatem(1, 1, n, l, r, x % mod);
        } else if (op == 2) {
            cin >> l >> r >> x;
            updatev(1, 1, n, l, r, x % mod);
        } else {
            cin >> l >> r;
            int ans = (two * query(1, 1, n, l, r)) % mod;
            cout << ans << "\n";
        }
    }
    
    return 0;
}