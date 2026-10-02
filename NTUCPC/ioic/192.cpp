
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define siz(x) (int)x.size()
using namespace std;

const int mod = 998244353; // 1e9 + 7;

const int N = 1000005;

struct Line {
    int a, b;
    Line(int _a = 0, int _b = 0) : a(_a), b(_b) {}
    int operator()(int x) {
        return a * x + b;
    }
};
Line seg[4 * N];    

void insert(int node, int l, int r, Line li) {
    if (l == r) {
        if (li(l) > seg[node](l))
            swap(seg[node], li);
        return;
    }
    int mid = (l + r) >> 1;
    if (seg[node].a > li.a)
        swap(seg[node], li);
    if (seg[node](mid) < li(mid)) {
        swap(seg[node], li);
        insert(2 * node, l, mid, li);
    } else {
        insert(2 * node + 1, mid + 1, r, li);
    }
}

int query(int node, int l, int r, int x) {
    if (l == r)
        return seg[node](x);
    int mid = (l + r) >> 1;
    if (x <= mid)
        return max(seg[node](x), query(2 * node, l, mid, x));
    else
        return max(seg[node](x), query(2 * node, mid + 1, r, x));
}

signed main() {
    IO;
    
    int q;
    cin >> q;
    int o, x, y;
    while (q--) {
        cin >> o;
        if (o == 0) {
            cin >> x >> y;
            insert(1, 1, 1e6, Line(x, y));
        } else {
            cin >> x;
            int ans = query(1, 1, 1e6, x);
            if (! ans)
                cout << "empty\n";
            else
                cout << ans << "\n";
        }
    }
    
    return 0;
}