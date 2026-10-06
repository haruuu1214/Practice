#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define F first
#define S second
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR0(i,n) for(int i=0;i<n;i++)
#define FOR(i,n) for(int i=1;i<=n;i++)
using namespace std;

void DB() {cout << "\n";}
template<class T, class ...U>
void DB(T a, U ...b) {cout << a << " "; DB(b...);}

vector <int> G[200005];
int a[200005];
int in[200005], out[200005];
int color[400005];
int ans[200005];
int preidx[200005];
int now = 0;

struct _BIT
{
    int n;
    vector <int> data;
    void init(int _n) {
        n = _n;
        data.assign(n+1, 0);
    }
    void update(int idx, int val) {
        for (int i=idx; i<=n; i += i & -i)
            data[i] += val;
    }
    int query(int idx) {
        int sum = 0;
        for (int i=idx; i>0; i -= i & -i)
            sum += data[i];
        return sum;
    }
};

struct QRY
{
    int l, r, id;
}queries[200005];

void dfs(int v, int p)
{
    in[v] = ++now;
    color[now] = a[v];
    for (int u:G[v]) {
        if (u == p) continue;
        dfs(u, v);
    }
    out[v] = ++now;
    color[now] = a[v];
}

bool cmpr(QRY a, QRY b) { return a.r < b.r; }

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, i, x, y;
    cin >> n;

    vector <int> v;
    for (i=1; i<=n; i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (i=1; i<=n; i++)
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    
    for (i=1; i<=n-1; i++) {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    now = 0;
    dfs(1, -1);

    for (i=1; i<=n; i++) {
        queries[i].l = in[i];
        queries[i].r = out[i];
        queries[i].id = i;
    }

    sort(queries + 1, queries + n + 1, cmpr);

    _BIT bit;
    int mxN = now, idx = 1;
    bit.init(mxN);
    for (i=1; i<=mxN; i++) {
        if (preidx[color[i]] > 0) {
            bit.update(preidx[color[i]], -1);
            bit.update(i, 1);
            preidx[color[i]] = i;   
        } else {
            bit.update(i, 1);
            preidx[color[i]] = i; 
        }

        while (idx <= n && queries[idx].r <= i) {
            ans[queries[idx].id] = bit.query(queries[idx].r) - bit.query(queries[idx].l - 1);
            idx++;
        }
    }

    for (i=1; i<=n; i++)
        cout << ans[i] << " ";
    cout << "\n";
    
    return 0;
}