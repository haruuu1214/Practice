#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
#define STL(x) for(auto &HEHE:x) cout << HEHE << " "; cout << "\n";
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

#define mid ((l + r) >> 1)
#define lc ((node << 1))
#define rc ((node << 1) | 1)

int S[4 * 200005];
int MX[4 * 200005];
int ass[4 * 200005];

void push(int node, int l, int r)
{
    if (ass[node]) {
        S[lc] = ass[node] * (mid - l + 1);
        S[rc] = ass[node] * (r - mid);
        MX[lc] = MX[rc] = ass[node];
        ass[lc] = ass[rc] = ass[node];
        ass[node] = 0;
    }
}

void assign(int node, int l, int r, int ql, int qr, int v)
{
    if (ql <= l && r <= qr) {
        S[node] = (r - l + 1) * v;
        MX[node] = v;
        ass[node] = v;
        return;
    }
    push(node, l, r);
    if (qr <= mid)
        assign(lc, l, mid, ql, qr, v);
    else if (mid < ql)
        assign(rc, mid + 1, r, ql, qr, v);
    else {
        assign(lc, l, mid, ql, qr, v);
        assign(rc, mid + 1, r, ql, qr, v);
    }
    S[node] = S[lc] + S[rc];
    MX[node] = max(MX[lc], MX[rc]);
}

/// position need to be the right of id, and value is bigger than v
int BS_MAX(int node, int l, int r, int id, int v)
{
    if (MX[node] < v)
        return -1;
    if (l == r)
        return l;
    push(node, l, r);
    if (mid < id || MX[lc] < v)
        return BS_MAX(rc, mid + 1, r, id, v);
    else
        return BS_MAX(lc, l, mid, id, v);
}

int query(int node, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
        return S[node];
    push(node, l, r);
    if (qr <= mid)
        return query(lc, l, mid, ql, qr);
    else if (mid < ql)
        return query(rc, mid + 1, r, ql, qr);
    else
        return query(lc, l, mid, ql, qr) + query(rc, mid + 1, r, ql, qr);
}

int a[200005], pre[200005], ans[200005];
struct qry
{
    int ql, qr, id;
};

signed main()
{
    IOS
    
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    
    int l, r;
    vector <qry> qrys;
    for (int i = 1; i <= q; i++) {
        cin >> l >> r;
        qrys.push_back({l, r, i});
    }

    sort(qrys.begin(), qrys.end(), [&](qry x, qry y){
        return x.ql > y.ql;
    });

    int q_idx = 0;
    for (int i = n; i >= 1; i--) {
        int pos = BS_MAX(1, 1, n, i, a[i]);
        if (pos == -1)
            pos = n;
        else
            pos--;
        assign(1, 1, n, i, pos, a[i]);
        while (q_idx < q && qrys[q_idx].ql == i) {
            ans[qrys[q_idx].id] = query(1, 1, n, qrys[q_idx].ql, qrys[q_idx].qr) - (pre[qrys[q_idx].qr] - pre[qrys[q_idx].ql - 1]);
            q_idx++;
        }
    }

    for (int i = 1; i <= q; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}