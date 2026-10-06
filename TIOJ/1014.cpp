#pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int INF = 1e9;

int a[18];
int dp[18][1 << 18];

signed main()
{
    IO;
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < n; i++) {
        int t = ((1 + i) + a[i] - 1) / a[i];
        dp[i][1 << i] = t * a[i];
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) { /// now
            if (mask & (1 << i) == false) continue;
            if (dp[i][mask] == 0) continue;
            for (int j = 0; j < n; j++) { /// nxt
                if (mask & (1 << j) == true) continue;
                int t = (dp[i][mask] + abs(i - j) + a[j] - 1) / a[j];

                if (dp[j][mask | (1 << j)] == 0)
                    dp[j][mask | (1 << j)] = t * a[j];
                else
                    dp[j][mask | (1 << j)] = min(dp[j][mask | (1 << j)], t * a[j]);
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dp[i][(1 << n) - 1]);
    }
    
    cout << ans << "\n";

    return 0;
}