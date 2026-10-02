#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;


const int N = 100005;
vector<pii> G[N];
int dis1[N], cnt1[N];
int dis2[N], cnt2[N];

signed main() {
    IO;
    
    int n, m, q, s, t;
    cin >> n >> m >> q >> s >> t;
    vector<int> a(q);
    FOR(i, 0, q - 1) cin >> a[i];
    int v, u, c;
    FOR(i, 1, m) {
        cin >> v >> u >> c;
        G[v].push_back({u, c});
        G[u].push_back({v, c});
    }
    {
        priority_queue<pii, vector<pii>, greater<pii>> Q;
        fill(dis1, dis1 + N, INF);
        dis1[s] = 0; cnt1[s] = 1;
        Q.push({0, s});
        while (!Q.empty()) {
            auto [step, v] = Q.top();
            Q.pop();
            if (step > dis1[v])
                continue;
            for (auto [u, w] : G[v]) {
                if (step + w < dis1[u]) {
                    dis1[u] = step + w;
                    cnt1[u] = cnt1[v];
                    Q.push({dis1[u], u});
                } else if (step + w == dis1[u]) {
                    cnt1[u] += cnt1[v];
                    cnt1[u] %= mod;
                }
            }
        }
    }
    {
        priority_queue<pii, vector<pii>, greater<pii>> Q;
        fill(dis2, dis2 + N, INF);
        dis2[t] = 0; cnt2[t] = 1;
        Q.push({0, t});
        while (!Q.empty()) {
            auto [step, v] = Q.top();
            Q.pop();
            if (step > dis2[v])
                continue;
            for (auto [u, w] : G[v]) {
                if (step + w < dis2[u]) {
                    dis2[u] = step + w;
                    cnt2[u] = cnt2[v];
                    Q.push({dis2[u], u});
                } else if (step + w == dis2[u]) {
                    cnt2[u] += cnt2[v];
                    cnt2[u] %= mod;
                }
            }
        }
    }
    FOR(i, 0, q - 1) {
        int res = dis1[a[i]] + dis2[a[i]];
        int cnt = cnt1[a[i]] * cnt2[a[i]] % mod;
        cout << res << " " << cnt << "\n";
    }
    
    return 0;
}