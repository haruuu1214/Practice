#pragma GCC optimize("Ofast, no-stack-protector")
#include <bits/stdc++.h>
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;


const int N = 5005;
bool vis[N][N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

signed main() {
    IO;

    int h, w;
    cin >> h >> w;
    vector <string> v(h);
    for (int i = 0; i < h; i++)
        cin >> v[i];
    
    auto inside = [&](int x, int y) {
        return (0 <= x && x < h && 0 <= y && y < w);
    };

    int n;
    cin >> n;
    int res = 0, x, y;
    queue <pii> Q;
    for (int i = 1; i <= n; i++) {
        queue <pii> nxt;
        cin >> x >> y;
        --x, --y;
        if (!vis[x][y]) {
            vis[x][y] = true;
            nxt.push({x, y});
            res++;
        }
        while (!Q.empty()) {
            int px = Q.front().first, py = Q.front().second;
            Q.pop();
            for (int k = 0; k < 4; k++) {
                int nx = px + dx[k], ny = py + dy[k];
                if (inside(nx, ny) && !vis[nx][ny] && v[nx][ny] == '.') {
                    vis[nx][ny] = true;
                    nxt.push({nx, ny});
                    res++;
                }
            }
        }
        swap(Q, nxt);
        cout << res << "\n";
    }
    
    return 0;
}
/*
5 5
.....
.....
.....
.....
.....
3
3 3
3 3
3 3
*/