#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
 
double dp[105][605];
 
signed main() {
    IOS
    
    int n, a, b;
 
    cin >> n >> a >> b;
 
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= 6; k++) { /// Dice
                if (j - k >= 0)
                    dp[i][j] += dp[i - 1][j - k];
            }
            dp[i][j] /= 6;
        }
    }
 
    double ans = 0;
    for (int j = a; j <= b; j++) {
        ans += dp[n][j];
    }
    cout << fixed << setprecision(6) << ans << "\n";
    
    return 0;
}