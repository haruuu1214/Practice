#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 3;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char dir[4] = {'R', 'L', 'D', 'U'};
int a[N][N];

signed main() {
    IO;
    
    int n, m;
    n = 3, m = 3;
    FOR (i, 0, n - 1) FOR (j, 0, m - 1) cin >> a[i][j];
    auto inside = [&](int px, int py) {
        return (0 <= px && px < n && 0 <= py && py < m);
    };
    int now = 1;
    int x, y;
    FOR (i, 0, n - 1) FOR (j, 0, m - 1)
        if (a[i][j] == 1) {
            x = i; y = j;
        }
    string s = "*";
    while (now <= 9) {
        bool suc = false;
        FOR (p, 0, 3) {
            int nx = x + dx[p], ny = y + dy[p];
            if (inside(nx, ny) && a[nx][ny] == now + 1) {
                s += dir[p];
                x = nx;
                y = ny;
                suc = true;
                now += 1;
                break;
            }
        }
        if (! suc) break;
    }
    cout << s << "\n";

    return 0;
}