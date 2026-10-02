#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define siz(x) (int)x.size()
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// ---------------------------------------------
struct Node {
    int x;
    Node(int _x = 0) : x(_x) {}
};
Node combine(Node a, Node b) {
    return Node(max(a.x, b.x));
}

struct Segment_Tree {
    vector<Node> seg;
    int n;
    Segment_Tree(int _n) : n(_n), seg(4 * _n + 5) {}
    void update(int node, int l, int r, int id, int va) {
        if (l == r) {
            seg[node].x = max(seg[node].x, va);
            return;
        }
        int mid = (l + r) >> 1;
        if (id <= mid)
            update((node << 1), l, mid, id, va);
        else
            update(((node << 1) | 1), mid + 1, r, id, va);
        seg[node] = combine(seg[node << 1], seg[(node << 1) | 1]);
    }
    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return seg[node];
        int mid = (l + r) >> 1;
        if (qr <= mid)
            return query((node << 1), l, mid, ql, qr);
        else if (mid + 1 <= ql)
            return query(((node << 1) | 1), mid + 1, r, ql, qr);
        else
            return combine(query((node << 1), l, mid, ql, qr), query(((node << 1) | 1), mid + 1, r, ql, qr));
    }
};
const int N = 2005;
int a[N];

vector<int> num;
int getid(int x) {
    return lower_bound(all(num), x) - num.begin() + 1;
}
int getl(int x) {
    return upper_bound(all(num), x) - num.begin() + 1;
}
int getr(int x) {
    return lower_bound(all(num), x) - num.begin();
}

signed main() {
    IO;
    int n;
    cin >> n;
    FOR (i, 1, n) {
        cin >> a[i];
        num.push_back(a[i]);
    }
    sort(all(num)); num.resize(unique(all(num)) - num.begin());
    vector<Segment_Tree> seg(n + 1, Segment_Tree(n));
    int ans = 0;
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i < j; i++) {
            if (a[i] < a[j]) {
                int res;
                if (getl(a[i]) <= getr(a[j])) res = seg[i].query(1, 1, n, getl(a[i]), getr(a[j])).x + 2;
                else res = 2;
                seg[j].update(1, 1, n, getid(a[i]), res);
                ans = max(ans, res);
            }
            if (a[i] > a[j] && 1 <= getr(a[j])) {
                int res = seg[i].query(1, 1, n, 1, getr(a[j])).x;
                seg[j].update(1, 1, n, getid(a[i]), res);
                ans = max(ans, res);
            }
        }
    }
    cout << ans;
}
/*
2
1 2
*/