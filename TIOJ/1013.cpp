#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
// const ll INF = 1e18;
const int INF = 2e9;


string mp[10] = {
    "*****************",
    "*...*.......**..*",
    "**..*....*.*.*..*",
    "*......*.**.**.**",
    "*..**...**..**.**",
    "**.....**..*.*..*",
    "*....*..........*",
    "*.....****.*...**",
    "****.*.*........*",
    "*****************"
};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n = 10, m = 17;
const int N = 20;
bool f_vis[N][N];
int dis[N][N];

signed main()
{
    IO
    
    int fx, fy, t, sx, sy, tx, ty;
    cin >> fx >> fy >> t >> sx >> sy >> tx >> ty;
    
    fill(&f_vis[0][0], &f_vis[0][0] + N * N, false);
    fill(&dis[0][0], &dis[0][0] + N * N, -1);

    queue <int> fire;
    f_vis[fx][fy] = true;
    fire.push(fx * m + fy);
    /// 過 t 分鐘
    for (int i = 1; i <= t - 1; i++) {
        queue <int> f2;
        while (!fire.empty()) {
            int x = fire.front() / m, y = fire.front() % m;
            fire.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx == tx && ny == ty) continue;
                if (!f_vis[nx][ny] && mp[nx][ny] == '.') {
                    f2.push(nx * m + ny);
                    f_vis[nx][ny] = true;
                }
            }
        }
        swap(fire, f2);
    }

    if (f_vis[sx][sy]) {
        cout << "Help!\n";
        return 0;
    }
    
    queue <int> pos;
    dis[sx][sy] = 0;
    pos.push(sx * m + sy);
    
    while (!pos.empty()) {
        queue <int> f2;
        while (!fire.empty()) {
            int x = fire.front() / m, y = fire.front() % m;
            fire.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx == tx && ny == ty) continue;
                if (!f_vis[nx][ny] && mp[nx][ny] == '.') {
                    f2.push(nx * m + ny);
                    f_vis[nx][ny] = true;
                }
            }
        }
        swap(fire, f2);
        queue <int> p2;
        while (!pos.empty()) {
            int x = pos.front() / m, y = pos.front() % m;
            pos.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (dis[nx][ny] == -1 && !f_vis[nx][ny] && mp[nx][ny] == '.') {
                    p2.push(nx * m + ny);
                    dis[nx][ny] = dis[x][y] + 1;
                }
            }
        }
        swap(pos, p2);
    }
    if (dis[tx][ty] == -1)
        cout << "Help!\n";
    else
        cout << dis[tx][ty] << "\n";
    
    return 0;
}