#include <bits/stdc++.h>
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int INF = 1e7;

const int N = 500005;

struct queries {
    int pos, x, t;
    /// x = 0 -> 詢問
};

pii seg[4 * N]; /// {最小值, 個數}
int tag[4 * N];

#define lc ((node << 1))
#define rc ((node << 1) | 1)
#define mid ((l + r) >> 1)
void build(int node, int l, int r) {
    if (l == r) {
        seg[node] = {0, 1};
        return;
    }
    build(lc, l, mid);
    build(rc, mid + 1, r);
    seg[node] = {0, seg[lc].second + seg[rc].second};
}

void push(int node, int l, int r) {
    if (tag[node] != 0) {
        seg[lc].first += tag[node];
        seg[rc].first += tag[node];
        tag[lc] += tag[node];
        tag[rc] += tag[node];
        tag[node] = 0;
    }
}

void pull(int node) {
    if (seg[lc].first != seg[rc].first) {
        if (seg[lc].first < seg[rc].first)
            seg[node] = seg[lc];
        else
            seg[node] = seg[rc];
    } else {
        seg[node] = {seg[lc].first, seg[lc].second + seg[rc].second};
    }
}

void update(int node, int l, int r, int ql, int qr, int val) {
    if (ql <= l && r <= qr) {
        seg[node].first += val;
        tag[node] += val;
        return;
    }
    push(node, l, r);
    if (qr <= mid)
        update(lc, l, mid, ql, qr, val);
    else if (mid + 1 <= ql)
        update(rc, mid + 1, r, ql, qr, val);
    else {
        update(lc, l, mid, ql, qr, val);
        update(rc, mid + 1, r, ql, qr, val);
    }
    pull(node);
}

pii query(int node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
        return seg[node];
    push(node, l, r);
    if (qr <= mid)
        return query(lc, l, mid, ql, qr);
    else if (mid + 1 <= ql)
        return query(rc, mid + 1, r, ql, qr);
    else {
        pii lson = query(lc, l, mid, ql, qr);
        pii rson = query(rc, mid + 1, r, ql, qr);
        if (lson.first != rson.first) {
            if (lson.first < rson.first)
                return lson;
            else
                return rson;
        } else {
            return {lson.first, lson.second + rson.second};
        }
    }
}

vector <queries> qrys;
vector <pii> ans;

signed main()
{
    IOS
    int n, m;
    cin >> n >> m;
    int a, b, c, d;

    for (int i = 1; i <= m; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            ++b; ++c;
            qrys.push_back({b, +d, i});
            qrys.push_back({c + 1, -d, i});
        } else {
            cin >> b;
            ++b;
            qrys.push_back({b, 0, i});
        }
    }
    sort(qrys.begin(), qrys.end(), [&](queries p, queries q){
        if (p.pos == q.pos)
            return p.t < q.t;
        return p.pos < q.pos;
    });

    build(1, 1, m);
    for (auto &[p, val, times] : qrys) {
        if (val != 0) {
            update(1, 1, m, times, m, val);
        } else {
            if (times == 1) {
                ans.push_back({times, 1});
            } else {
                pii qry = query(1, 1, m, 1, times - 1);
                if (qry.first != 0)
                    ans.push_back({times, 0});
                else
                    ans.push_back({times, qry.second});
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (pii p : ans)
        cout << p.second << "\n";

    
    return 0;
}