#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

struct DSU
{
    int N;
    vector <int> f, sz;
    DSU(int x) {
        init(x);
    }
    void init(int n) {
        N = n;
        f.resize(n + 1);
        iota(f.begin(), f.end(), 0);
        sz.assign(n + 1, 1);
    }
    int find(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        f[y] = x;
        return true;
    }
};

void solve()
{
    int n;
    cin >> n;
    cout << n << "\n"; 
}

signed main()
{
    IOS
    
    int n, m, q;
    cin >> n >> m >> q;
    int a, b;
    DSU dsu(n);
    loop(i, 1, m)
        cin >> a >> b;
    
    string s;

    vector <pair <int, pii>> qrys;
    while (q--) {
        cin >> s >> a >> b;
        if (s[0] == 'c') {
            qrys.push_back({1, {a, b}});
        } else {
            qrys.push_back({2, {a, b}});
        }
    }

    vector <bool> ans;
    for (int i = SZ(qrys) - 1; i >= 0; i--) {
        if (qrys[i].F == 1) {
            dsu.merge(qrys[i].S.F, qrys[i].S.S);
        } else {
            if (dsu.same(qrys[i].S.F, qrys[i].S.S))
                ans.push_back(true);
            else
                ans.push_back(false);
        }
    }
    reverse(ans.begin(), ans.end());

    for (bool x : ans)
        cout << (x ? "YES\n" : "NO\n");

    return 0;
}