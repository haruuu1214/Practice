
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

const int N = 200005;
int a[N];
int seg[4 * N];

void update(int node, int l, int r, int id, int va) {
    if (l == r) {
        seg[node] = va;
        return;
    }
    int mid = (l + r) >> 1;
    if (id <= mid)
        update(2 * node, l, mid, id, va);
    else
        update(2 * node + 1, mid + 1, r, id, va);
    seg[node] = max(seg[2 * node], seg[2 * node + 1]);
}

int bin_search(int node, int l, int r, int k) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (seg[2 * node] <= k)
        return bin_search(2 * node + 1, mid + 1, r, k);
    else
        return bin_search(2 * node, l, mid, k);
}

int ans[N];
struct info {
    int qid, l, r;
};

signed main() {
    IO;
    
    int n, q;
    cin >> n >> q;
    FOR (i, 1, n) cin >> a[i];
    vector<info> qrys(q);
    FOR (i, 0, q - 1) {
        cin >> qrys[i].l >> qrys[i].r;
        qrys[i].qid = i;
    }
    sort(all(qrys), [&](info x, info y) {
        return x.l > y.l;
    });
    fill(seg, seg + 4 * N, n + 1);
    int id = 0;
    for (int i = n; i >= 1; i--) {
        update(1, 0, 2e5, a[i], i);
        while (id < q && qrys[id].l == i) {
            ans[qrys[id].qid] = bin_search(1, 0, 2e5, qrys[id].r);
            id += 1;
        }
    }
    FOR (i, 0, q - 1) cout << ans[i] << "\n";
    
    return 0;
}
/*
10 8
4 4 4 1 1 0 3 2 2 4
8 9
1 10
2 10
6 9
1 4
7 9
1 2
6 9
*/