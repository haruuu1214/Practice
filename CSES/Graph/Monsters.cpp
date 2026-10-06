#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

bool mp[1005][1005];
int from[1005][1005];
int mvx[5] = {-100, 1, 0, -1, 0};
int mvy[5] = {-100, 0, 1, 0, -1};
bool visA[1005][1005];
bool visM[1005][1005];
int n, m;
int si, sj;

bool inside(int a, int b)
{
    return (1 <= a && a <= n && 1 <= b && b <= m ? true : false);
}

void backtrack(int x, int y)
{
    vector <int> ans;
    while (x != si || y != sj) {
        ans.push_back(from[x][y]);
        if (from[x][y] == 1)
            x--;
        else if (from[x][y] == 2)
            y--;
        else if (from[x][y] == 3)
            x++;
        else
            y++;
    }
    reverse(ans.begin(), ans.end());
    cout << "YES\n";
    cout << ans.size() << "\n";
    for (int it : ans) {
        if (it == 1)
            cout << "D";
        else if (it == 2)
            cout << "R";
        else if (it == 3)
            cout << "U";
        else
            cout << "L";
    }
    cout << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    char ch;
    cin >> n >> m;
    queue <pii> M;
    queue <pii> A;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> ch;
            if (ch == '#')
                mp[i][j] = 0;
            else if (ch == '.')
                mp[i][j] = 1;
            else if (ch == 'A') {
                si = i, sj = j;
                A.push({i, j});
                visA[i][j] = 1;
            } else {
                M.push({i, j});
                visM[i][j] = 1;
            }
        }
    }

    if (si == 1 || si == n || sj == 1 || sj == m) {
        cout << "YES\n";
        cout << "0\n";
        return 0;
    }

    int x, y, sz;
    while (!A.empty()) {
        sz = M.size();
        while (sz--) {
            pii tmp = M.front();
            x = tmp.first, y = tmp.second;
            M.pop();
            for (int i = 1; i <= 4; i++) {
                int nxtx = x + mvx[i], nxty = y + mvy[i];
                if (inside(nxtx, nxty) && !visM[nxtx][nxty] && mp[nxtx][nxty]) {
                    M.push({nxtx, nxty});
                    visM[nxtx][nxty] = 1;
                }
            }
        }
        
        sz = A.size();
        while (sz--) {
            pii tmp = A.front();
            x = tmp.first, y = tmp.second;
            A.pop();
            for (int i = 1; i <= 4; i++) {
                int nxtx = x + mvx[i], nxty = y + mvy[i];
                if (inside(nxtx, nxty) && !visM[nxtx][nxty] && !visA[nxtx][nxty] && mp[nxtx][nxty]) {
                    A.push({nxtx, nxty});
                    visA[nxtx][nxty] = 1; from[nxtx][nxty] = i;
                    if (nxtx == 1 || nxtx == n || nxty == 1 || nxty == m) {
                        backtrack(nxtx, nxty);
                        return 0;
                    }
                }
            }
        }
    }
    cout << "NO\n";
    
    return 0;
}