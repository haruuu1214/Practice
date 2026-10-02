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
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        f[y] = x;
        return true;
    }
    bool same(int x, int y) {
        return (find(x) == find(y) ? true : false);
    }
};

signed main()
{
    IOS
    
    int n, m;
    int a, b;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        DSU D(2 * n);
        bool fail = false;
        for (int i = 1; i <= m; i++) {
            cin >> a >> b;
            if (fail) continue;
            if (D.same(a, b))
                fail = true;
            else {
                D.merge(a, b + n);
                D.merge(b, a + n);
            }
        }
        if (!fail)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    
    return 0;
}