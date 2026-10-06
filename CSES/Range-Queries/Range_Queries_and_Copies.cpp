#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define F first
#define S second
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define mid ((l + r) >> 1)
using namespace std;
template<class T, class ...U>

struct info
{
    int val;
    info *lc, *rc;
    info(int x = 0) { val = x; lc = rc = nullptr; }
    info(info* p) { *this = *p; }
    void pull() {
        val = 0;
        if (lc) val += lc->val;
        if (rc) val += rc->val;
    }
};

info* ver[200005];

info* build(vector <int> &v, int l, int r)
{
    if (l == r) return new info(v[l - 1]);
    info* res = new info;
    res->lc = build(v, l, mid);
    res->rc = build(v, mid + 1, r);
    res->pull();
    return res;
}

// p : previous version of current node
info* update(info* p, int l, int r, int idx, int x)
{
    if (idx < l || r < idx) return p;
    if (l == r) return new info(x);

    info* res = new info;
    res->lc = update(p->lc, l, mid, idx, x);
    res->rc = update(p->rc, mid + 1, r, idx, x);
    res->pull();
    return res;
}

int query(info *node, int l, int r, int ql, int qr)
{
    if (!node) return 0;
    if (ql <= l && r <= qr) return node->val;
    if (qr <= mid)
        return query(node->lc, l, mid, ql, qr);
    else if (mid + 1 <= ql)
        return query(node->rc, mid + 1, r, ql, qr);
    else
        return query(node->lc, l, mid, ql, qr) + query(node->rc, mid + 1, r, ql, qr);
}

signed main()
{
    IO;

    int n, q, tmp;
    cin >> n >> q;

    vector <int> v;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    ver[1] = build(v, 1, n);
    int len = 1;

    int t, k, a, b;
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> k >> a >> b;
            ver[k] = update(ver[k], 1, n, a, b);
        } else if (t == 2) {
            cin >> k >> a >> b;
            cout << query(ver[k], 1, n, a, b) << "\n";
        } else {
            cin >> k;
            ver[++len] = ver[k];
        }
    }
    
    return 0;
}