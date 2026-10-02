#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
const int N = 1005;
int a[N][N], step[2];
int dis1[N][N], dis2[N][N];

signed main() {
    IO;
    
    int n, m, x1, y1;
    cin >> n >> m >> step[0] >> step[1] >> x1 >> y1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    fill(&dis1[0][0], &dis1[0][0] + N * N, INF);
    fill(&dis2[0][0], &dis2[0][0] + N * N, INF);

    auto inside = [&](int x, int y) {
        return (1 <= x && x <= n && 1 <= y && y <= m);
    };

    priority_queue <pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> Q;
    Q.push({0, {1, 1}});
    dis1[1][1] = 0;
    while (!Q.empty()) {
        auto [now, pos] = Q.top();
        auto [x, y] = pos;
        Q.pop();
        if (x == x1 && y == y1) break;
        if (now > dis1[x][y]) continue;
        for (int sid = 0; sid < 2; sid++) {
            for (int i = 0; i < 4; i++) {
                int nx = x + step[sid] * dx[i];
                int ny = y + step[sid] * dy[i];
                if (inside(nx, ny) && !a[nx][ny] && now + 1 < dis1[nx][ny]) {
                    Q.push({now + 1, {nx, ny}});
                    dis1[nx][ny] = now + 1;
                }
            }
        }
    }
    
    while (!Q.empty()) Q.pop();

    Q.push({0, {x1, y1}});
    dis2[x1][y1] = 0;
    while (!Q.empty()) {
        auto [now, pos] = Q.top();
        auto [x, y] = pos;
        Q.pop();
        if (x == n && y == m) break;
        if (now > dis2[x][y]) continue;
        for (int sid = 0; sid < 2; sid++) {
            for (int i = 0; i < 4; i++) {
                int nx = x + step[sid] * dx[i];
                int ny = y + step[sid] * dy[i];
                if (inside(nx, ny) && !a[nx][ny] && now + 1 < dis2[nx][ny]) {
                    Q.push({now + 1, {nx, ny}});
                    dis2[nx][ny] = now + 1;
                }
            }
        }
    }

    int ans = dis1[x1][y1] + dis2[n][m];
    if (ans >= INF)
        cout << -1 << "\n";
    else
        cout << ans << "\n";

    return 0;
}