#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


struct event {
    int id, l, r, x, x_cnt;
};

vector<event> eve;

signed main() {
    IO;
    
    int n, m;
    cin >> n >> m;
    int l, r, c, w;
    FOR(i, 1, n) {
        cin >> l >> r >> c >> w;
        eve.push_back({i, l, r, w, c});
    }
    sort(eve.begin(), eve.end(), [&](event p, event q) {
        if (p.x == q.x) return p.id < q.id;
        return p.x > q.x;
    });
    vector<int> tic_cnt(m + 1), ans(m + 1);
    FOR(i, 1, m) cin >> tic_cnt[i];
    set<int> id;
    FOR(i, 1, m) id.insert(i);
    for (auto [i, l, r, x, x_cnt] : eve) {
        auto p = id.lower_bound(l);
        while (x_cnt > 0 && p != id.end() && (*p) <= r) {
            int take = min(x_cnt, tic_cnt[*p]);
            x_cnt -= take;
            tic_cnt[*p] -= take;
            ans[*p] += take * x;
            if (tic_cnt[*p] == 0) {
                auto q = next(p);
                id.erase(p);
                p = q;
            }
        }
    }
    FOR(i, 1, m) cout << ans[i] << " \n"[i == m];
    
    return 0;
}