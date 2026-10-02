#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 1000005;

struct Line {
    int a = 0, b = INF;
    Line() : a(0), b(INF) {}
    Line(int _a, int _b) : a(_a), b(_b) {}
    int operator()(int x) {
        return a * x + b;
    }
} seg[4 * N];

void update(int node, int l, int r, Line add) {
    if (l == r) {
        if (add(l) < seg[node](l))
            seg[node] = add;
        return;
    }
    if (seg[node].a > add.a)
        swap(seg[node], add);
    int mid = (l + r) >> 1;
    if (add(mid) > seg[node](mid))
        update(2 * node, l, mid, add);
    else {
        swap(seg[node], add);
        update(2 * node + 1, mid + 1, r, add);
    }
}

int query(int node, int l, int r, int x) {
    if (l == r) {
        return seg[node](x);
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        return min(seg[node](x), query(2 * node, l, mid, x));
    else
        return min(seg[node](x), query(2 * node + 1, mid + 1, r, x));
}

int s[N], f[N], dp[N];

signed main() {
    IO;
    
    int n, x;
    cin >> n >> x;
    FOR (i, 1, n) cin >> s[i];
    FOR (i, 1, n) cin >> f[i];
    update(1, 1, 1000000, Line(x, 0ll));
    FOR (i, 1, n) {
        dp[i] = query(1, 1, 1000000, s[i]);
        update(1, 1, 1000000, Line(f[i], dp[i]));
    }
    cout << dp[n] << "\n";
    
    return 0;
}