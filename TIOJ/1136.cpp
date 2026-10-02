#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 105;
bool vis[N][N];
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
vector <string> a;
int h, w;
bool inside(int x, int y) {
    return (0 <= x && x < h && 0 <= y && y < w);
}

void dfs(int i, int j, char c) {
    vis[i][j] = true;
    for (int k = 0; k < 8; k++) {
        if (inside(i + dx[k], j + dy[k]) && !vis[i + dx[k]][j + dy[k]] && a[i + dx[k]][j + dy[k]] == c)
            dfs(i + dx[k], j + dy[k], c);
    }
}

signed main() {
    IO;
    
    cin >> h >> w;
    swap(h, w);
    a.resize(h);
    for (int i = 0; i < h; i++) cin >> a[i];
    
    int cnt1 = 0, cnt2 = 0;
    fill(&vis[0][0], &vis[0][0] + N * N, false);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!vis[i][j] && a[i][j] == 'G') {
                dfs(i, j, 'G');
                cnt1++;
            }
        }
    }
    fill(&vis[0][0], &vis[0][0] + N * N, false);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!vis[i][j] && a[i][j] == '-') {
                dfs(i, j, '-');
                cnt2++;
            }
        }
    }
    cout << cnt1 << " " << cnt2 << "\n";

    return 0;
}