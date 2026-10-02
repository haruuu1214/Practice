#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

int mvx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int mvy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
int mp[9][9];

bool inside(int x, int y)
{
    return (1 <= x && x <= 8 && 1 <= y && y <= 8 ? true : false);
}

int deg(int x, int y)
{
    int res = 0;
    for (int i = 0; i < 8; i++) {
        int mx = x + mvx[i];
        int my = y + mvy[i];
        if (inside(mx, my) && !mp[mx][my])
            res++;
    }
    return res;
}

bool dfs(int step, int x, int y)
{
    mp[x][y] = step;
    if (step == 64) return true;
    vector <pair <int, pii>> v;
    for (int i = 0; i < 8; i++) {
        int mx = x + mvx[i];
        int my = y + mvy[i];
        if (inside(mx, my) && !mp[mx][my]) {
            int d = deg(mx, my);
            v.push_back({d, {mx, my}});
        }
    }
    sort(v.begin(), v.end());
    for (auto p : v) {
        if (dfs(step + 1, p.second.first, p.second.second))
            return true;
    }
    mp[x][y] = 0;
    return false;
}

signed main()
{
    IOS
    
    int x, y;
    cin >> x >> y;
    dfs(1, x, y);

    for (int j = 1; j <= 8; j++) {
        for (int i = 1; i <= 8; i++) {
            cout << mp[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}