#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

struct position
{
    int x, y, z;
};
int nx, ny, nz;
bool mp[55][55][55];
int step[55][55][55];
position from[55][55][55];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

bool inside(int _x, int _y, int _z) {
    return (1 <= _x && _x <= nx && 1 <= _y && _y <= ny && 1 <= _z && _z <= nz);
}

signed main()
{
    IOS
    
    cin >> nx >> ny >> nz;
    int a, b, c;
    for (int k = 1; k <= nz; k++) {
        for (int j = 1; j <= ny; j++) {
            for (int i = 1; i <= nx; i++) {
                cin >> mp[i][j][k];
            }
        }
    }

    if (nx == 1 && ny == 1 && nz == 1) {
        cout << "(1,1,1)\n";
        return 0;
    }

    if (mp[1][1][1] || mp[nx][ny][nz]) {
        cout << "no route\n";
        return 0;
    }

    fill(&step[0][0][0], &step[0][0][0] + 55 * 55 * 55, INF);
    queue <pair <position, int>> Q;
    Q.push({{1, 1, 1}, 0});
    step[1][1][1] = 0;
    from[1][1][1] = {1, 1, 1};

    while (!Q.empty()) {
        position pos = Q.front().first;
        int now_step = Q.front().second;
        Q.pop();
        if (step[nx][ny][nz] != INF) break;
        for (int i = 0; i < 6; i++) {
            position nxt = {pos.x + dx[i], pos.y + dy[i], pos.z + dz[i]};
            if (inside(nxt.x, nxt.y, nxt.z) && !mp[nxt.x][nxt.y][nxt.z]) {
                if (now_step + 1 < step[nxt.x][nxt.y][nxt.z]) {
                    Q.push({nxt, now_step + 1});
                    step[nxt.x][nxt.y][nxt.z] = now_step + 1;
                    from[nxt.x][nxt.y][nxt.z] = pos;
                }
            }
        }
    }

    if (step[nx][ny][nz] == INF) {
        cout << "no route\n";
        return 0;
    }

    vector <position> v;
    position pos = {nx, ny, nz};
    while (pos.x != 1 || pos.y != 1 || pos.z != 1) {
        v.push_back(pos);
        pos = from[pos.x][pos.y][pos.z];
    }

    reverse(v.begin(), v.end());
    cout << "(1,1,1)";
    for (auto it : v) {
        // if (it.x == 1 && it.y == 1 && it.z == 1) continue;
        cout  << "->" << "(" << it.x << "," << it.y << "," << it.z << ")";
    }
    cout << "\n";
    
    return 0;
}