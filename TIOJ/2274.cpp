#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 2e9;

const int N = 1005;
ll a[N][N];

signed main()
{
    IO
    
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    
    ll mx = -INF;
    int x1, x2, y1, y2;
    
    ll res;
    int id;
    for (int i = 1; i <= n; i++) {
        res = -INF;
        id = 0;
        for (int j = 1; j <= m; j++) {
            if (res > mx) {
                mx = res;
                x1 = i, x2 = i, y1 = id, y2 = j - 1;
            }
            if (res < 0) {
                res = a[i][j];
                id = j;
            } else {
                res += a[i][j];
            }
        }
        if (res > mx) {
            mx = res;
            x1 = i, x2 = i, y1 = id, y2 = m;
        }
    }

    for (int j = 1; j <= m; j++) {
        res = -INF;
        id = 0;
        for (int i = 1; i <= n; i++) {
            if (res > mx) {
                mx = res;
                x1 = id, x2 = i - 1, y1 = j, y2 = j;
            }
            if (res < 0) {
                res = a[i][j];
                id = i;
            } else {
                res += a[i][j];
            }
        }
        if (res > mx) {
            mx = res;
            x1 = id, x2 = n, y1 = j, y2 = j;
        }
    }
    cout << mx << "\n";
    for (int i = 1; i <= x1 - 1; i++)
        cout << 'U';
    for (int i = x2 + 1; i <= n; i++)
        cout << 'D';
    for (int i = 1; i <= y1 - 1; i++)
        cout << 'L';
    for (int i = y2 + 1; i <= m; i++)
        cout << 'R';

    if (x1 == x2)
        cout << 'U';
    else
        cout << 'L';

    return 0;
}