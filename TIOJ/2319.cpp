#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 200005;
int a[N];
vector <int> vertex[4 * N];

void insert_vertex(int node, int l, int r, int ql, int qr, int x) {
    if (ql <= l && r <= qr) {
        vertex[node].push_back(x);
        return;
    }
    int mid = (l + r) >> 1;
    if (qr <= mid)
        insert_vertex(2 * node, l, mid, ql, qr, x);
    else if (mid + 1 <= ql)
        insert_vertex(2 * node + 1, mid + 1, r, ql, qr, x);
    else {
        insert_vertex(2 * node, l, mid, ql, qr, x);
        insert_vertex(2 * node + 1, mid + 1, r, ql, qr, x);
    }
}

bool vis[N];
queue <int> Q;

void query(int node, int l, int r, int id) {
    for (int v : vertex[node])
        if (!vis[v]) {
            vis[v] = true;
            Q.push(v);
        }
    vertex[node].clear();
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (id <= mid)
        query(2 * node, l, mid, id);
    else
        query(2 * node + 1, mid + 1, r, id);
}

int pl[N], pr[N];

signed main() {
    IO;
    
    int n;
    cin >> n;
    vector <pii> ord;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ord.push_back({a[i], i});
    }
    for (int i = 1; i <= n; i++) {
        cin >> pl[i] >> pr[i];
        insert_vertex(1, 1, n, pl[i], pr[i], i);
    }

    sort(ord.begin(), ord.end(), [&](pii p, pii q) {
        return p.first > q.first;
    });
    
    int ans = 0;
    for (auto [val, id] : ord) {
        if (vis[id]) continue;
        vis[id] = true;
        while (!Q.empty()) Q.pop();
        query(1, 1, n, id);
        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            if (a[v] < val) {
                ans += val - a[v];
                a[v] = val;
            }
            query(1, 1, n, v);
        }
    }
    cout << ans << "\n";
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << "\n";

    return 0;
}