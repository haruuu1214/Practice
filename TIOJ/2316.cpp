#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 2e9;


int mul(int x, int y) {
    if (1ll * x * y >= 1ll * mod)
        return (1ll * x * y) % mod;
    return x * y;
}
int add(int x, int y) {
    if (x >= mod - y)
        return (x - mod) + y;
    return x + y;
}
int sub(int x, int y) {
    if (x <= mod + y)
        return (x + mod) - y;
    return x - y;
}

int fastpow(int a, int b) {
    int res = a, ans = 1;
    while (b > 0) {
        if (b & 1) ans = mul(ans, res);
        res = mul(res, res);
        b >>= 1;
    }
    return ans;
}

const int N = 100005;
int m[N];
vector <int> a[N];
vector <int> pre_a[N];
vector <int> inv[N];
vector <int> pre_inv[N];

map<pii, int> id;
vector<int> qrys[N];
int q_len = 0;
int ans[N];

signed main() {
    IO;
    
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> m[i];
        a[i].resize(m[i]);
        inv[i].resize(m[i]);
        pre_a[i].resize(m[i]);
        pre_inv[i].resize(m[i]);
        for (int j = 0; j < m[i]; j++)
            cin >> a[i][j];
        sort(a[i].begin(), a[i].end());
        for (int j = 0; j < m[i]; j++)
            pre_a[i][j] = (j == 0 ? a[i][j] : add(pre_a[i][j - 1], a[i][j]));
        for (int j = 0; j < m[i]; j++) {
            inv[i][j] = fastpow(a[i][j], mod - 2);
            pre_inv[i][j] = (j == 0 ? inv[i][j] : add(pre_inv[i][j - 1], inv[i][j]));
        }
    }
    int x, y;
    for (int i = 1; i <= q; i++) {
        cin >> x >> y;
        if (id.count({x, y}))
            qrys[id[{x, y}]].push_back(i);
        else {
            id[{x, y}] = q_len;
            qrys[q_len].push_back(i);
            ++q_len;
        }
    }
    
    for (auto qry : id) {
        x = qry.first.first;
        y = qry.first.second;
        int res = 0;
        if (m[x] <= m[y]) {
            for (int i = 0; i < m[x]; i++) {
                int id = upper_bound(a[y].begin(), a[y].end(), a[x][i] - 1) - a[y].begin() - 1;
                if (id >= 0) {
                    res = add(res, mul(pre_a[y][id], inv[x][i]));
                }
            }
        } else {
            for (int i = 0; i < m[y]; i++) {
                int id = upper_bound(a[x].begin(), a[x].end(), a[y][i]) - a[x].begin() - 1;
                if (id < 0) {
                    res = add(res, mul(pre_inv[x][pre_inv[x].size() - 1], a[y][i]));
                } else {
                    int tmp = mul(sub(pre_inv[x][pre_inv[x].size() - 1], pre_inv[x][id]), a[y][i]);
                    res = add(res, tmp);
                }
            }
        }
        res = mul(res, fastpow(mul(m[x], m[y]), mod - 2));
        for (int qid : qrys[qry.second])
            ans[qid] = res;
    }
    for (int i = 1; i <= q; i++)
        cout << add(ans[i], mod) << "\n";
    return 0;
}