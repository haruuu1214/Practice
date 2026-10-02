#pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

struct BIT {
    int N;
    vector<int> info;
    BIT(int n) : N(n), info(n + 1) {}
    void update(int idx, int val) {
        for (int i = idx; i <= N; i += i & -i)
            info[i] += val;
    }
    int query(int idx) {
        int res = 0;
        for (int i = idx; i > 0; i -= i & -i)
            res += info[i];
        return res;
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

struct qry {
    int p, k, id;
};
vector<int> op[100005];
pii ops[100005];  /// {id, val}
qry ask[100005];
int ans[100005];
BIT bit(100000);
int n;

void do_thing(int l, int r) {
    for (int i = l; i <= r; i++) {
        for (int it : op[i])
            bit.update(it, 1);
    }
}

void undo_thing(int l, int r) {
    for (int i = l; i <= r; i++) {
        for (int it : op[i])
            bit.update(it, -1);
    }
}

void split(int S, vector<int>& qrys, vector<int>& lft, vector<int>& rgt) {
    for (int it : qrys) {
        if (bit.query(max(0ll, ask[it].p - S), min(100000ll, ask[it].p + S)) >= ask[it].k) {
            lft.push_back(it);
        } else {
            rgt.push_back(it);
        }
    }
    vector<int>().swap(qrys);
}

void total_BS(int l, int r, vector<int>& qrys) {
    if (l == r) {
        for (int it : qrys)
            ans[ask[it].id] = l;
        return;
    }
    int mid = (l + r) >> 1;
    do_thing(l, mid);
    vector<int> lft;
    vector<int> rgt;
    split(mid, qrys, lft, rgt);

    total_BS(mid + 1, r, rgt);
    undo_thing(l, mid);
    total_BS(l, mid, lft);
}

signed main() {
    IO;
    /// 題目是 0-base
    int q;
    cin >> n >> q;
    int x, a, b;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        ops[i] = {i, x};
        op[x].push_back(i);
    }

    for (int i = 1; i <= q; i++) {
        cin >> a >> b;
        ++a;  /// 1-base
        ask[i] = {a, b, i};
    }

    vector<int> v;
    for (int i = 1; i <= q; i++)
        v.push_back(i);
    total_BS(1, n, v);

    for (int i = 1; i <= q; i++)
        cout << ans[i] << "\n";

    return 0;
}