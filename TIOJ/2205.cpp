#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;


const int P = 1e6 + 3;
const int N = 200005;

struct BIT {
    int n;
    vector<int> info;
    void init(int _n) {
        n = _n;
        info.assign(_n + 1, 0);
    }
    void update(int id, int val) {
        for (int i = id; i <= n; i += i & -i)
            info[i] += val;
    }
    int query(int id) {
        int x = 0;
        for (int i = id; i > 0; i -= i & -i)
            x += info[i];
        return x % mod;
    }
    int query(int l, int r) {
        if (l > r) return 0;
        return ((query(r) - (l == 1 ? 0ll : query(l - 1))) % mod + mod) % mod;
    }
};

int a[N];
int pow_p[N];
int inv[N];

int fastpow(int x, int y) {
    int ans = 1, res = x;
    while (y > 0) {
        if (y & 1) ans = (ans * res) % mod;
        res = (res * res) % mod;
        y >>= 1;
    }
    return ans;
}

signed main() {
    IO;
    
    int n, q;
    cin >> n >> q;

    pow_p[1] = 1;
    FOR (i, 2, n) pow_p[i] = pow_p[i - 1] * P % mod;
    FOR (i, 1, n) inv[i] = fastpow(pow_p[i], mod - 2);

    BIT pre, suf;
    pre.init(n);
    suf.init(n);
    char c;
    FOR (i, 1, n) {
        cin >> c;
        a[i] = c - 'a' + 1;
        pre.update(i, a[i] * pow_p[i]);
        suf.update(n - i + 1, a[i] * pow_p[n - i + 1]);
    }

    int t, l, r;
    while (q--) {
        cin >> t >> l >> r;
        if (t == 1) {
            int len = r - l + 1;
            if (len % 3 != 0) {
                cout << 0 << "\n";
                continue;
            }
            int pl = l + len / 3, pr = r - len / 3;
            int lval = pre.query(l, pl - 1) * inv[l] % mod;
            int midval = suf.query(n - pr + 1, n - pl + 1) * inv[n - pr + 1] % mod;
            int rval = pre.query(pr + 1, r) * inv[pr + 1] % mod;
            lval = (lval + mod) % mod;
            midval = (midval + mod) % mod;
            rval = (rval + mod) % mod;
            if (lval == midval && midval == rval)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        } else {
            int lval = a[l], rval = a[r];
            int dl = rval - lval;
            int dr = lval - rval;
            pre.update(l, dl * pow_p[l] % mod);
            pre.update(r, dr * pow_p[r] % mod);
            suf.update(n - l + 1, dl * pow_p[n - l + 1] % mod);
            suf.update(n - r + 1, dr * pow_p[n - r + 1] % mod);
            a[l] = rval;
            a[r] = lval;
        }
    }
    
    return 0;
}
/*
6 1
abbaab
1 1 6
*/