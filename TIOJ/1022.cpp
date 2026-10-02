#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define FOR(p, a, b) for (int p = a; p <= b; p++)
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
const int INF = 1e18;
const int N = 105;
int a[N][N], dis[N][N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    auto inside = [&](int px, int py) {
        return (1 <= px && px <= n && 1 <= py && py <= m);
    };
    FOR (i, 1, n) FOR (j, 1, m) cin >> a[i][j];
    fill(&dis[0][0], &dis[0][0] + N * N, INF);
    dis[1][1] = 0;
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> Q;
    Q.push({0, {1, 1}});
    while (! Q.empty()) {
        int x = Q.top().first;
        pii v = Q.top().second;
        Q.pop();
        if (x != dis[v.first][v.second]) continue;
        FOR (d, 0, 3) {
            pii u = {v.first + dx[d], v.second + dy[d]};
            if (inside(u.first, u.second) && abs(a[v.first][v.second] - a[u.first][u.second]) <= 5 && x + 1 < dis[u.first][u.second]) {
                dis[u.first][u.second] = x + 1;
                Q.push({x + 1, u});
            }
        }
    }
    cout << dis[n][m] << "\n";
}

signed main() {
    IO;

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}