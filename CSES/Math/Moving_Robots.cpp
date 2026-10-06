#include <bits/stdc++.h>
#define int long long
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int mvx[4] = {1, -1, 0, 0};
int mvy[4] = {0, 0, 1, -1};
double dp[105][8][8];
double ans[8][8];

bool inside(int x, int y)
{
    return (0 <= x && x <= 7 && 0 <= y && y <= 7 ? 1 : 0);
}

signed main()
{
    IO;
    
    int n;
    cin >> n;

/// init
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            ans[i][j] = 1;

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            for (int k = 0; k <= n; k++)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                        dp[k][i][j] = 0;
                    
            dp[0][x][y] = 1;

            for (int k = 0; k < n; k++) {
                for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 8; j++) {
                        double cnt = 0;
                        for (int p = 0; p < 4; p++) {
                            if (inside(i + mvx[p], j + mvy[p]))
                                cnt++;
                        }
                        for (int p = 0; p < 4; p++) {
                            if (inside(i + mvx[p], j + mvy[p]))
                                dp[k + 1][i + mvx[p]][j + mvy[p]] += dp[k][i][j] / cnt;
                        }
                    }
                }
            }

            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                    ans[i][j] *= (1 - dp[n][i][j]);
        }
    }
    

    double res = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            res += ans[i][j];
        }
    }
    cout << fixed << setprecision(6) << res << "\n";
    return 0;
}