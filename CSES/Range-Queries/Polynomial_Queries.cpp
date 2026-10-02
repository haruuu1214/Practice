#include <bits/stdc++.h>
using namespace std;

#define lc (node << 1)
#define rc ((node << 1) | 1)
#define int long long
struct Segment_tree
{
    int N;
    vector <int> info, tag, d;
    Segment_tree(int n) : N(n), info(4 * n + 5), tag(4 * n + 5), d(4 * n + 5) {}
    Segment_tree(vector <int> init) : Segment_tree(init.size()) {
        function <void(int, int, int)> build = [&](int node, int l, int r) {
            if (l == r) {
                info[node] = init[l - 1];
                return;
            }
            int mid = (l + r) >> 1;
            build(lc, l, mid);
            build(rc, mid + 1, r);
            pull(node);
        };
        build(1, 1, N);
    }
    int merge(int a, int b) {
        return a + b; /// 自定義
    }
    void push(int node, int l, int r) {
        int mid = (l + r) >> 1;
        info[lc] += (mid - l + 1) * (2 * tag[node] + (mid - l) * d[node]) / 2ll;
        info[rc] += (r - mid) * (2 * tag[node] + (mid + 1 - l) * d[node] + (r - l) * d[node]) / 2ll;
        tag[lc] += tag[node];
        tag[rc] += tag[node] + (mid + 1 - l) * d[node];
        d[lc] += d[node];
        d[rc] += d[node];
        tag[node] = d[node] = 0;
    }
    void pull(int node) {
        info[node] = merge(info[(node << 1)], info[((node << 1) | 1)]);
    }
    void update(int node, int l, int r, int ql, int qr, int _start, int _d) {
        if (ql <= l && r <= qr) {
            info[node] += (r - l + 1) * (2 * _start + (r - l) * _d) / 2ll;
            tag[node] += _start;
            d[node] += _d;
            return;
        }
        push(node, l, r);
        int mid = (l + r) >> 1;
        if (qr <= mid)
            update(lc, l, mid, ql, qr, _start, _d);
        else if (mid + 1 <= ql)
            update(rc, mid + 1, r, ql, qr, _start + max(0ll, mid + 1 - max(l, ql)) * _d, _d);
        else {
            update(lc, l, mid, ql, qr, _start, _d);
            update(rc, mid + 1, r, ql, qr, _start + max(0ll, mid + 1 - max(l, ql)) * _d, _d);
        }
        pull(node);
    }
    int query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return info[node];
        push(node, l, r);
        int mid = (l + r) >> 1;
        if (qr <= mid)
            return query(lc, l, mid, ql, qr);
        else if (mid + 1 <= ql)
            return query(((node << 1) | 1), mid + 1, r, ql, qr);
        else
            return merge(query((node << 1), l, mid, ql, qr), query(((node << 1) | 1), mid + 1, r, ql, qr));
    }
    void update(int l, int r, int _start, int _d) { update(1, 1, N, l, r, _start, _d); }
    int query(int l, int r) { return query(1, 1, N, l, r); }
};

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector <long long> v;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        v.push_back(x);
    }

    Segment_tree S(v);

    int a, b, c;
    while (q--) {
        cin >> a >> b >> c;
        if (a == 1)
            S.update(b, c, 1, 1);
        else
            cout << S.query(b, c) << "\n";
    }
    
    return 0;
}