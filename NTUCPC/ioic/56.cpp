
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

/*
     前一個剩下   接上去這個的 {總數, 剩下的東西}
0 : 000 :   none   ~ (this)
1 : 001 :      a   ~ (this)
2 : 010 :      b   ~ (this)
4 : 100 :      c   ~ (this)
3 : 011 :     ab   ~ (this)
5 : 101 :     ac   ~ (this)
6 : 110 :     bc   ~ (this)
7 : 111 :    abc   ~ (this)
*/
int rotate(int i) {
    return ((i & 3) << 1) ^ (i & 4 ? 1 : 0);
}

int rev_rotate(int i) {
    return ((i & 6) >> 1) ^ (i & 1 ? 4 : 0);
}

struct info {
    pii cnt[7] = {}; // (amount, less type)
    info(char c = 'a') {
        int x = c - 'a';
        for (int i = 0; i < 7; i++) {
            cnt[i] = {0, i | (1 << x)};
            if (cnt[i].S == 7) {
                cnt[i].F += 1;
                cnt[i].S = 0;
            }
        }
    }
};
info seg[4 * N];
int tag[4 * N];
string s;

info merge(info l, info r) {
    info p;
    for (int i = 0; i < 7; i++) {
        int l_less = l.cnt[i].S;
        p.cnt[i] = {l.cnt[i].F + r.cnt[l_less].F, r.cnt[l_less].S};
    }
    return p;
}

void pull(int node) {
    seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
}

info rotate_node(info res) {
    info p;
    for (int i = 0; i < 7; i++) {
        int to = rotate(i);
        p.cnt[to] = res.cnt[i];
        if (res.cnt[i].F == 0)
            p.cnt[to].S = to | rotate(res.cnt[0].S);
        else
            p.cnt[to].S = rotate(res.cnt[i].S);
        if (p.cnt[to].S == 7) {
            p.cnt[to].F += 1;
            p.cnt[to].S = 0;
        }
    }
    return p;
}

void push(int node) {
    tag[node] %= 3;
    if (tag[node]) {
        tag[2 * node] += tag[node];
        tag[2 * node + 1] += tag[node];
        for (int i = 0; i < tag[node]; i++) {
            seg[2 * node] = rotate_node(seg[2 * node]);
            seg[2 * node + 1] = rotate_node(seg[2 * node + 1]);
        }
        tag[node] = 0;
    }
}

void build(int node, int l, int r) {
    if (l == r) {
        seg[node] = info(s[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    pull(node);
}

void update(int node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        seg[node] = rotate_node(seg[node]);
        tag[node] += 1;
        return;
    }
    push(node);
    int mid = (l + r) >> 1;
    if (qr <= mid)
        update(2 * node, l, mid, ql, qr);
    else if (mid + 1 <= ql)
        update(2 * node + 1, mid + 1, r, ql, qr);
    else {
        update(2 * node, l, mid, ql, qr);
        update(2 * node + 1, mid + 1, r, ql, qr);
    }
    pull(node);
}

info query(int node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
        return seg[node];
    push(node);
    int mid = (l + r) >> 1;
    if (qr <= mid)
        return query(2 * node, l, mid, ql, qr);
    else if (mid + 1 <= ql)
        return query(2 * node + 1, mid + 1, r, ql, qr);
    else
        return merge(query(2 * node, l, mid, ql, qr), query(2 * node + 1, mid + 1, r, ql, qr));
}

signed main() {
    IO;
    
    int n, q, o, l, r;
    cin >> n >> q;
    cin >> s;
    build(1, 0, n - 1);
    while (q--) {
        cin >> o >> l >> r;
        --l; --r;
        if (o == 1)
            update(1, 0, n - 1, l, r);
        else
            cout << query(1, 0, n - 1, l, r).cnt[0].F << "\n";
    }
    
    return 0;
}
/*
20 1
aabacbcbcacacababaac
2 7 20

acabccabc
*/