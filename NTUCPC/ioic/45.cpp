#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;


const int N = 500005;
vector<pii> G[N], rev_G[N];
int deg[N], to[N];
int dis1[N], cnt1[N];
int dis2[N], cnt2[N];

pii ans[N];

pii seg[4 * N];

pii merge(pii p, pii q) {
    if (p.first == q.first)
        return {p.first, (p.second + q.second) % mod};
    else
        return (p.first > q.first ? p : q);
}

void push(int node) {
    if (seg[node].first != -1) {
        seg[2 * node] = merge(seg[2 * node], seg[node]);
        seg[2 * node + 1] = merge(seg[2 * node + 1], seg[node]);
        seg[node] = {-1, 0};
    }
}

void update(int node, int l, int r, int ql, int qr, pii p) {
    if (ql <= l && r <= qr) {
        seg[node] = merge(seg[node], p);
        return;
    }
    push(node);
    int mid = (l + r) >> 1;
    if (qr <= mid)
        update(2 * node, l, mid, ql, qr, p);
    else if (mid + 1 <= ql)
        update(2 * node + 1, mid + 1, r, ql, qr, p);
    else {
        update(2 * node, l, mid, ql, qr, p);
        update(2 * node + 1, mid + 1, r, ql, qr, p);
    }
}

void traversal(int node, int l, int r) {
    if (l == r) {
        ans[l] = seg[node];
        return;
    }
    push(node);
    int mid = (l + r) >> 1;
    traversal(2 * node, l, mid);
    traversal(2 * node + 1, mid + 1, r);
}

vector<tuple<int, int, int>> E;

signed main() {
    IO;

    int n, m, v, u, w;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> v >> u >> w;
        if (u == 1 || v == n) continue;
        E.emplace_back(v, u, w);
        G[v].push_back({u, w});
        rev_G[u].push_back({v, w});
        deg[u] += 1;
    }
    vector<int> order;
    priority_queue<int, vector<int>, greater<int>> Q;
    for (int i = 1; i <= n; i++)
        if (! deg[i])
            Q.push(i);
    while (! Q.empty()) {
        v = Q.top();
        Q.pop();
        order.push_back(v);
        for (auto [u, w] : G[v]) {
            deg[u] -= 1;
            if (! deg[u])
                Q.push(u);
        }
    }
    for (int i = 0; i < n; i++)
        to[order[i]] = i + 1; // old -> new

    fill(dis1, dis1 + N, -INF);
    fill(dis2, dis2 + N, -INF);
    dis1[1] = 0;
    cnt1[1] = 1;
    for (int i = 0; i < n; i++) {
        int v = order[i];
        for (auto [u, w] : G[v]) {
            if (dis1[v] + w > dis1[u]) {
                dis1[u] = dis1[v] + w;
                cnt1[u] = cnt1[v];
            } else if (dis1[v] + w == dis1[u]) {
                cnt1[u] = (cnt1[u] + cnt1[v]) % mod;
            }
        }
    }
    reverse(order.begin(), order.end());
    dis2[n] = 0;
    cnt2[n] = 1;
    for (int i = 0; i < n; i++) {
        int v = order[i];
        for (auto [u, w] : rev_G[v]) {
            if (dis2[v] + w > dis2[u]) {
                dis2[u] = dis2[v] + w;
                cnt2[u] = cnt2[v];
            } else if (dis2[v] + w == dis2[u]) {
                cnt2[u] = (cnt2[u] + cnt2[v]) % mod;
            }
        }
    }

    fill(seg, seg + 4 * N, make_pair(-INF, 0));
    for (auto [v, u, w] : E) {
        if (dis1[v] >= 0 && dis2[u] >= 0) {
            int l = to[v], r = to[u];
            int d = dis1[v] + dis2[u] + w, cnt = cnt1[v] * cnt2[u] % mod;
            if (l + 1 <= r - 1) {
                update(1, 1, n, l + 1, r - 1, {d, cnt});
            }
        }
    }
    traversal(1, 1, n);
    for (int i = 1; i <= n; i++) {
        if (ans[to[i]].first < 0)
            cout << -1 << "\n";
        else
            cout << ans[to[i]].first << " " << ans[to[i]].second << "\n";
    }


    return 0;
}
/*
5 4
1 4 2
4 3 5
3 2 4
4 5 1

5 4
1 2 2
2 3 5
3 4 4
2 5 1
*/