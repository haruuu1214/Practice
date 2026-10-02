#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
// const ll INF = 1e18;
const int INF = 2e9;


const int N = 1000005;

vector <pii> G[N], rev_G[N];
int d1[N], d2[N];

signed main()
{
    IO
    
    int n, m;
    cin >> n >> m;
    int a, b, c;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        rev_G[b].push_back({a, c});
    }
    
    fill(d1, d1 + N, INF);
    fill(d2, d2 + N, INF);

    priority_queue <pii, vector<pii>, greater<pii>> Q;
    Q.push({0, 1});
    d1[1] = 0;
    while (!Q.empty()) {
        auto [dis, v] = Q.top();
        Q.pop();
        if (dis != d1[v]) continue;
        for (auto &[u, w] : G[v]) {
            if (dis + w < d1[u]) {
                d1[u] = dis + w;
                Q.push({d1[u], u});
            }
        }
    }

    Q.push({0, 1});
    d2[1] = 0;
    while (!Q.empty()) {
        auto [dis, v] = Q.top();
        Q.pop();
        if (dis != d2[v]) continue;
        for (auto &[u, w] : rev_G[v]) {
            if (dis + w < d2[u]) {
                d2[u] = dis + w;
                Q.push({d2[u], u});
            }
        }
    }

    ll ans = 0;
    for (int i = 2; i <= n; i++) {
        if (d1[i] == INF || d2[i] == INF) {
            cout << 0 << "\n";
            return 0;
        }
        ans += (ll)d1[i] + (ll)d2[i];
    }
    cout << ans << "\n";
    
    return 0;
}