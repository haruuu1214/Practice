#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 9;
int tr[26];
int mp[N][N];
bool dx[9][N];
bool dy[9][N];
bool dsq[9][3][3];
vector<string> a(9);
string col = "ROYGBIPLW";

void dfs(int x, int y) {
    if (y == 9) {
        dfs(x + 1, 0);
        return;
    }
    if (x == 9) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                if (mp[i][j] >= 0)
                    cout << col[mp[i][j]];
            cout << "\n";
        }
        exit(0);
    }
    if (a[x][y] == '*') {
        for (int id = 0; id < 9; id++) {
            if (! dx[id][x] && ! dy[id][y] && ! dsq[id][x / 3][y / 3]) {
                mp[x][y] = id;
                dx[id][x] = dy[id][y] = dsq[id][x / 3][y / 3] = true;
                dfs(x, y + 1);
                dx[id][x] = dy[id][y] = dsq[id][x / 3][y / 3] = false;
            }
        }
    } else {
        dfs(x, y + 1);
    }
}

signed main() {
    IO;
    fill(&mp[0][0], &mp[0][0] + 9 * 9, -1);
    fill(tr, tr + 26, -1);
    FOR (i, 0, 8) tr[col[i] - 'A'] = i;
    FOR (i, 0, 8) cin >> a[i];
    FOR (i, 0, 8) {
        FOR (j, 0, 8) {
            if (a[i][j] != '*') {
                dx[tr[a[i][j] - 'A']][i] = true;
                dy[tr[a[i][j] - 'A']][j] = true;
                dsq[tr[a[i][j] - 'A']][i / 3][j / 3] = true;
            }
        }
    }
    dfs(0, 0);
    
    return 0;
}