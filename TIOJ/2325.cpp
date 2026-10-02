#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 1000005;
int a[N], ans[N], par[N];
vector<pii> ask[N];

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

const int MXN = 1000000;

signed main() {
    IO;
    
    int n, q;
    cin >> n >> q;
    FOR (i, 1, n) cin >> a[i];
    int a0, p;
    FOR (i, 1, q) {
        cin >> a0 >> p;
        ask[p].push_back({a0, i});
    }
    FOR (i, 0, MXN) par[i] = i;

// [l, r] : 答案 (ans) 的左右界 , [L, R] : 實際 (a0) 的左右界
    int l = 0, r = MXN, L = 0, R = MXN;
    FOR (i, 1, n) {
        if (l >= 0)
            l -= a[i], r -= a[i];
        else
            l += a[i], r += a[i];
        if (l <= 0 && r >= 0) {
            if (- l <= r) { // 合併左邊
                FOR (j, l, -1)
                    par[j - l + L] = find(- j - l + L);
                L += -l;
                l = 0;
            } else {
                FOR (j, 1, r)
                    par[j - l + L] = find(- j - l + L);
                R -= r;
                r = 0;
            }
        }
        for (auto [a0, qid] : ask[i]) {
            int x = find(a0);
            if (l >= 0)
                ans[qid] = l + (x - L);
            else
                ans[qid] = - (l + (x - L));
        }
    }
    FOR (i, 1, q) cout << ans[i] << "\n";
    
    return 0;
}