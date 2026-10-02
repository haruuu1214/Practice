#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 13;
int dp[N][1 << N]; // 走到 i ，已經走過 mask (mask 不包含 i)
int from[N][1 << N];
int edge[N][N];
int dis[N];

signed main() {
    IO;

    fill(&edge[0][0], &edge[0][0] + N * N, INF);
    fill(&dp[0][0], &dp[0][0] + N * (1 << N), INF);

    int n, m;
    cin >> n >> m;
    int a, b, c;
    FOR (i, 1, m) {
        cin >> a >> b >> c;
        edge[a][b] = min(edge[a][b], c);
        edge[b][a] = min(edge[b][a], c);
    }
    int k, x, strt, tar = 0;
    cin >> k;
    FOR (i, 1, k) {
        cin >> x;
        if (i == 1)
            strt = x;
        tar |= (1 << x);
    }
    for (int i = 0; i < n; i++)
        dp[i][0] = 0;
    

    for (int mask = 1; mask < (1 << n); mask++) {
        if (mask == (mask & tar)) {
            priority_queue<pii, vector<pii>, greater<pii>> Q;
            fill(dis, dis + N, INF);
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i) && dp[i][mask ^ (1 << i)] < INF) {
                    dis[i] = dp[i][mask ^ (1 << i)];
                    Q.push({dis[i], i});
                }
            }
            while (! Q.empty()) {
                int step = Q.top().first, v = Q.top().second;
                Q.pop();
                if (step != dis[v]) continue;
                for (int u = 0; u < n; u++) {
                    if (edge[v][u] < INF) {
                        if (step + edge[v][u] < dis[u]) {
                            dis[u] = step + edge[v][u];
                            from[u][mask] = v;
                            Q.push({dis[u], u});
                        } else if (step + edge[v][u] == dis[u] && v < from[u][mask]) {
                            from[u][mask] = v;
                            Q.push({dis[u], u});
                        }
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) continue;
                dp[i][mask] = dis[i];
            }
        }
    }
    cout << "Minimum travel distance: " << dp[strt][(tar ^ (1 << strt))] << "\n";
    cout << "Travel route: ";
    int now = strt;
    int msk = (tar ^ (1 << strt));
    while (true) {
        cout << now << " ";
        if (msk == 0) break;
        now = from[now][msk];
        if (msk & (1 << now))
            msk ^= (1 << now);
    }
    cout << "\n";

    return 0;
}