#include <bits/stdc++.h>
using namespace std;
const int N = 105;
bool mp[N][N], blk[N][N];
bool dir[2][N][N];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m, q;
    cin >> n >> m >> q;
    int mx = 0, res = 0;

    auto inside = [&](int x, int y) {
        return (0 <= x && x < n && 0 <= y && y < m);
    };
    int o, x, y;
    while (q--) {
        cin >> x >> y >> o;

        auto check = [&](int px, int py, int dx, int dy) {
            while (inside(px, py)) {
                if (blk[px][py])
                    return true;
                px += dx;
                py += dy;
            }
            return false;
        };

        auto update = [&](int d, int px, int py, int dx, int dy) {
            while (inside(px, py) && ! blk[px][py]) {
                dir[d][px][py] = 1;
                if (! mp[px][py]) {
                    mp[px][py] = 1;
                    res += 1;
                }
                px += dx;
                py += dy;
            }
        };

        auto remove = [&](int d, int px, int py, int dx, int dy) {
            while (inside(px, py) && ! blk[px][py]) {
                dir[d][px][py] = 0;
                if (mp[px][py] && ! dir[d ^ 1][px][py]) {
                    mp[px][py] = 0;
                    res -= 1;
                }
                px += dx;
                py += dy;
            }
        };

        if (o == 0) {
            if (mp[x][y]) {
                mp[x][y] = 0;
                res -= 1;
            }
            blk[x][y] = 1;
            res += 1;

            if (check(x - 1, y, - 1, 0)) update(0, x - 1, y, - 1, 0);
            if (check(x + 1, y, + 1, 0)) update(0, x + 1, y, + 1, 0);
            if (check(x, y - 1, 0, - 1)) update(1, x, y - 1, 0, - 1);
            if (check(x, y + 1, 0, + 1)) update(1, x, y + 1, 0, + 1);
        } else {
            blk[x][y] = 0;
            res -= 1;

            if (check(x - 1, y, - 1, 0)) remove(0, x - 1, y, - 1, 0);
            if (check(x + 1, y, + 1, 0)) remove(0, x + 1, y, + 1, 0);
            if (check(x, y - 1, 0, - 1)) remove(1, x, y - 1, 0, - 1);
            if (check(x, y + 1, 0, + 1)) remove(1, x, y + 1, 0, + 1);
        }
        mx = max(mx, res);
    }
    cout << mx << "\n" << res << "\n";
    
    return 0;
}