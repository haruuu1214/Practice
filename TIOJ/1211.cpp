#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
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
    IO;
    
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        int a, b, c;
        DSU D(n);
        vector <tuple<int, int, int>> v;
        for (int i = 1; i <= m; i++) {
            cin >> a >> b >> c;
            v.push_back({c, a, b});
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for (auto [w, a, b] : v) {
            if (D.same(a, b) == false) {
                ans += w;
                D.merge(a, b);
            }
        }
        for (int i = 2; i <= n; i++) {
            if (D.same(1, i) == false) {
                ans = -1;
                break;
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}