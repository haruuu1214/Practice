#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 2e9;

const int N = 200005;

pii a[N][2];
string s[N];
bitset <200005> dp[9];
bitset <200005> dp2[9][9];

bool try_one(int n, int m) {
    for (int j = 1; j <= m; j++)
        dp[j].reset();
    for (int j = 1; j <= m; j++)
        dp[j][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int prej = max(1, j - 1); prej <= min(m, j + 1); prej++) {
                if (!dp[prej][i - 1]) continue;
                if (a[i][0] == make_pair(-1, -1) || (a[i][0].first <= j && j <= a[i][0].second))
                    dp[j][i] = true;
            }
        }
    }
    bool fg = false;
    for (int i = 1; i <= m; i++)
        fg |= dp[i][n];
    return fg;
}

bool try_two(int n, int m) {
    for (int j = 1; j <= m; j++)
        for (int k = 1; k <= m; k++)
            dp2[j][k].reset();
    for (int j = 1; j <= m; j++)
        for (int k = 1; k <= m; k++)
            dp2[j][k][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int prej = max(1, j - 1); prej <= min(m, j + 1); prej++) {
                for (int k = 1; k <= m; k++) {
                    for (int prek = max(1, k - 1); prek <= min(m, k + 1); prek++) {
                        if (!dp2[prej][prek][i - 1]) continue;
                        if (a[i][0] == make_pair(-1, -1)) {
                            dp2[j][k][i] = true;
                        } else if (a[i][1] == make_pair(-1, -1)) {
                            if ((a[i][0].first <= j && j <= a[i][0].second) || (a[i][0].first <= k && k <= a[i][0].second))
                                dp2[j][k][i] = true;
                        } else {
                            if ((a[i][0].first <= j && j <= a[i][0].second) && (a[i][1].first <= k && k <= a[i][1].second))
                                dp2[j][k][i] = true;
                        }
                    }
                }
            }
        }
    }
    bool fg = false;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            fg |= dp2[i][j][n];
    return fg;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    
    bool two = false;
    for (int i = 1; i <= n; i++) {
        a[i][0] = a[i][1] = {-1, -1};
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '-') {
                int l = j, r = j;
                while (r + 1 < m && s[i][r + 1] == '-')
                    r++;
                if (a[i][0] == make_pair(-1, -1))
                    a[i][0] = {l + 1, r + 1};
                else {
                    a[i][1] = {l + 1, r + 1};
                    two = true;
                }
                j = r + 1;
            }
        }
    }

    if (two == false && try_one(n, m)) {
        cout << 1 << "\n";
    } else if (try_two(n, m)) {
        cout << 2 << "\n";
    } else {
        cout << 3 << "\n";
    }
}

signed main()
{
    IO
    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}