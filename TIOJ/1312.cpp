#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
#define STL(x) for(auto &HEHE:x) cout << HEHE << " "; cout << "\n";
#define arr0(x,y) loop(HEHE,0,y-1) cout << x[HEHE] << " "; cout << "\n";
#define arr1(x,y) loop(HEHE,1,y) cout << x[HEHE] << " "; cout << "\n";
using namespace std;
template<class T, class ...U>


struct DSU
{
    int N;
    vector <int> f, sz;
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        N = n;
        f.resize(n + 1);
        iota(f.begin(), f.end(), 0);
        sz.assign(n + 1, 1);
    }
    int find(int x) {
        while (x != f[x])
            x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (x > y) {
            swap(x, y);
        }
        sz[x] += sz[y];
        f[y] = x;
        return true;
    }
    int size(int x) {
        return sz[find(x)];
    }
};

signed main()
{
    IOS
    
    int n, m;

    while (cin >> n >> m) {
        DSU D(n);

        int a, b;
        loop(i, 1, m) {
            cin >> a >> b;
            D.merge(a, b);
        }

        int x;
        cin >> x;

        cout << D.find(x) << "\n";
    }

    return 0;
}