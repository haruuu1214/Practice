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
    int comp;
    vector <int> f, sz;
    DSU(int x) {
        init(x);
    }
    void init(int n) {
        comp = n;
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
        comp--;
        return true;
    }
    bool same(int x, int y) {
        return (find(x) == find(y) ? true : false);
    }
    int count_comp() {
        return comp;
    }
};

map <pii, int> mp;
pii E[200005];
pii br[200005];
bool choose[200005];
int ans[200005];

signed main()
{
    IO;
    
    int n, m, k;
    cin >> n >> m >> k;
    DSU D(n);

    for (int i = 1; i <= m; i++) {
        cin >> E[i].first >> E[i].second;
        if (E[i].first > E[i].second)
            swap(E[i].first, E[i].second);
        mp[E[i]] = i;
    }

    for (int i = 1; i <= k; i++) {
        cin >> br[i].first >> br[i].second;
        if (br[i].first > br[i].second)
            swap(br[i].first, br[i].second);
        choose[mp[br[i]]] = true;
    }

    for (int i = 1; i <= m; i++) {
        if (!choose[i])
            D.merge(E[i].first, E[i].second);
    }

    for (int i = k; i >= 1; i--) {
        ans[i] = D.count_comp();
        D.merge(br[i].first, br[i].second);
    }

    for (int i = 1; i <= k; i++)
        cout << ans[i] << " ";
    cout << "\n";
    
    return 0;
}