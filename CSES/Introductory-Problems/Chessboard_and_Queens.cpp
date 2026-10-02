#include <bits/stdc++.h>
using namespace std;

const int N = 8;
int x[N], y[N], dx[2 * N], dy[2 * N];
vector<string> mp(8);
int ans = 0, cur = 0;

void dfs(int i, int j) {
    if (i == 8) {
        if (y[j]) {
            if (j == 7) {
                if (cur == 8)
                    ans += 1;
                return;
            }
            dfs(0, j + 1);
        }
        return;
    }
    if (mp[i][j] == '.') {
        if (! x[i] && ! y[j] && ! dx[i + j] && ! dy[(i - j + 2 * N) % (2 * N)]) {
            x[i] = y[j] = dx[i + j] = dy[(i - j + 2 * N) % (2 * N)] = true;
            cur += 1;
            dfs(i + 1, j);
            x[i] = y[j] = dx[i + j] = dy[(i - j + 2 * N) % (2 * N)] = false;
            cur -= 1;
        }
    }
    dfs(i + 1, j);
}

signed main() {
    for (int i = 0; i < 8; i++)
        cin >> mp[i];
    dfs(0, 0);
    cout << ans << "\n";
}