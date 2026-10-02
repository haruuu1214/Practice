#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
void debug() { cerr << endl; }
template <typename T, typename ...U>
void debug(T i, U ...j) { cerr << i << ' ', debug(j...); }
#define test(x...) debug("[" + string(x) + "]", x)

struct Node {
    vector<pii> edges;
};

struct DSU {
    vector<int> parent, size, tag;
    vector<tuple<int, int, int, int, int>> history;
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        tag.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return find(parent[x]);
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (size[x] < size[y]) swap(x, y);
        history.pb({x, y, parent[y], tag[x], size[x]});
        parent[y] = x;
        size[x] += size[y];
        return true;
    }
    void add_tag(int head, int val) {
        tag[head] += val;
    }
    void undo() {
        auto [px, py, parent_py, base, sz_x] = history.back();
        parent[py] = parent_py;
        size[px] = sz_x;
        int delta = tag[px] - base;
        // tag[px] = base;
        tag[py] += delta;
        history.pop_back();
    }
};

const int N = 400005;
vector<Node> seg;
vector<int> nums;

void split(int node, int l, int r, int ql, int qr, pii edge) {
    if (ql <= l && r <= qr) {
        // add edge to node
        seg[node].edges.pb(edge);
        return;
    }
    int mid = (l + r) >> 1;
    if (qr <= mid)
        split(2 * node, l, mid, ql, qr, edge);
    else if (mid + 1 <= ql)
        split(2 * node + 1, mid + 1, r, ql, qr, edge);
    else {
        split(2 * node, l, mid, ql, qr, edge);
        split(2 * node + 1, mid + 1, r, ql, qr, edge);
    }
}

void _assert(bool condition) {
    if (!condition) {
        exit(0);
    }
}

signed main() {
	IO;
	int n, m, k, v, u, l, r;
    cin >> n >> m >> k;
    // _assert(n <= 1e5);
    vector<pii> edges(m);
    vector<pii> intervals(m);
    for (int i = 0; i < m; i++) {
        cin >> v >> u >> l >> r;
        nums.pb(l);
        nums.pb(r + 1);
        edges[i] = {v, u};
        intervals[i] = {l, r + 1};
    }
    if (m == 0) {
        for (int i = 2; i <= n; i++) {
            cout << 0 << " \n"[i == n];
        }
        return 0;
    }
    sort(all(nums));
    nums.resize(unique(all(nums)) - nums.begin());
    seg.resize(4 * sz(nums) + 5);
    int mx_k = sz(nums) - 1;
    for (int i = 0; i < m; i++) {
        int ql = lower_bound(all(nums), intervals[i].F) - nums.begin();
        int qr = lower_bound(all(nums), intervals[i].S) - nums.begin();
        _assert(1 <= ql + 1 && ql + 1 <= qr && qr <= mx_k);
        split(1, 1, mx_k, ql + 1, qr, edges[i]);
    }
    // N = 2, M = 2
    // 2 2 10
    // 1 2 1 2
    // 1 2 8 9
    // [1, 3, 8, 10]
    // [0, 1] [1, 2] [2, 3]
    DSU dsu(n);
    auto dfs = [&](auto self, int node, int l, int r) -> void {
        int count = 0;
        for (auto &[v, u] : seg[node].edges) {
            if (dsu.merge(v, u)) {
                count++;
            }
        }
        if (l == r) {
            dsu.add_tag(dsu.find(1), nums[l] - nums[l - 1]);
        } else {
            int mid = (l + r) >> 1;
            self(self, 2 * node, l, mid);
            self(self, 2 * node + 1, mid + 1, r);
        }
        while (count--) {
            dsu.undo();
        }
    };
    dfs(dfs, 1, 1, mx_k);
    for (int i = 2; i <= n; i++) {
        cout << dsu.tag[dsu.find(i)] << " \n"[i == n];
    }
}