#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int amount;

struct DSU {
    int N;
    vector<int> f, sz;
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
        if (sz[x] < sz[y]) {
            swap(x, y);
        }
        sz[x] += sz[y];
        f[y] = x;
        return true;
    }
    int size(int x) {
        return sz[find(x)];
    }
    int mx_sz() {
        int res = -1;
        for (int i = 1; i <= N; i++)
            res = max(res, sz[i]);
        return res;
    }
};

int a[1000005];

signed main() {
    IO;

    int n;
    while (cin >> n) {
        DSU D(n);
        int x;
        amount = n;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            if (D.merge(i, x)) {
                amount--;
            }
        }
        cout << amount << " " << D.mx_sz() << "\n";
    }

    return 0;
}