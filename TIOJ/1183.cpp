#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= b; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char ch[4] = {'R', 'L', 'D', 'U'};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<vector<bool>> vis(n, vector<bool>(m));
    FOR(i, 0, n - 1) cin >> a[i];
    int x = -1, y = -1;
    FOR(i, 0, n - 1) {
        FOR(j, 0, m - 1) {
            if (a[i][j] == 'S') {
                x = i;
                y = j;
            }
        }
    }
    auto inside = [&](int px, int py) {
        return (0 <= px && px < n && 0 <= py && py < m);
    };
    string ans = "";
    while (a[x][y] != 'T') {
        int nx = -1, ny = -1;
        FOR(k, 0, 3) {
            nx = x + dx[k], ny = y + dy[k];
            if (inside(nx, ny) && (a[nx][ny] == '.' || a[nx][ny] == 'T') && !vis[nx][ny]) {
                vis[nx][ny] = true;
                ans += ch[k];
                break;
            }
        }
        x = nx, y = ny;
    }
    cout << ans << "\n";
}

signed main() {
    IO;
    
    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}