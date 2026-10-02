#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;
int h[N], w[N], dp[N];
int S[4 * N], tag[4 * N];

void push(int node, int l, int r) {
    if (tag[node]) {
        int mid = (l + r) >> 1;
        S[2 * node] = (S[2 * node] == INF ? tag[node] : S[2 * node] + tag[node]);
        tag[2 * node] += tag[node];
        S[2 * node + 1] = (S[2 * node + 1] == INF ? tag[node] : S[2 * node + 1] + tag[node]);
        tag[2 * node + 1] += tag[node];
        tag[node] = 0;
    }
}

void update(int node, int l, int r, int ql, int qr, int val) {
    if (ql <= l && r <= qr) {
        S[node] = (S[node] == INF ? val : S[node] + val);
        tag[node] += val;
        return;
    }
    push(node, l, r);
    int mid = (l + r) >> 1;
    if (qr <= mid)
        update(2 * node, l, mid, ql, qr, val);
    else if (mid + 1 <= ql)
        update(2 * node + 1, mid + 1, r, ql, qr, val);
    else {
        update(2 * node, l, mid, ql, qr, val);
        update(2 * node + 1, mid + 1, r, ql, qr, val);
    }
    S[node] = min(S[2 * node], S[2 * node + 1]);
}

int query(int node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
        return S[node];
    push(node, l, r);
    int mid = (l + r) >> 1;
    if (qr <= mid)
        return query(2 * node, l, mid, ql, qr);
    else if (mid + 1 <= ql)
        return query(2 * node + 1, mid + 1, r, ql, qr);
    else
        return min(query(2 * node, l, mid, ql, qr), query(2 * node + 1, mid + 1, r, ql, qr));
}

signed main() {
    IO;

    fill(S, S + 4 * N, INF);
    int n, l;
    cin >> n >> l;
    FOR (i, 1, n) cin >> h[i] >> w[i];

    int cur = 0, lft = 1;
    deque<int> dq;
    dq.push_back(0);
    h[0] = INF;
    FOR (i, 1, n) {
        cur += w[i];
        while (cur > l) {
            cur -= w[lft];
            lft += 1;
        }
        while (dq.size() >= 2 && h[i] > h[dq.back()]) {
            update(1, 1, n, dq[(int)dq.size() - 2] + 1, dq.back(), h[i] - h[dq.back()]);
            dq.pop_back();
        }
        dq.push_back(i);
        update(1, 1, n, i, i, h[i]);

        dp[i] = query(1, 1, n, lft, i);
        
        if (i + 1 <= n)
            update(1, 1, n, i + 1, i + 1, dp[i]);
    }
    cout << dp[n] << "\n";

    return 0;
}