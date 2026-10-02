#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e12;

int dp[45][1605];
int pre_r[45][45];
int pre_n[45];
int pre_p[45];
int s[45];

signed main()
{
    IOS
    
    int c, T, tmp;
    cin >> c >> T;
    for (int i = 1; i <= c; i++) {
        cin >> tmp;
        pre_p[i] = pre_p[i - 1] + tmp;
    }
    for (int i = 1; i <= c; i++) cin >> s[i];
    for (int i = 1; i <= c; i++) {
        cin >> tmp;
        pre_n[i] = pre_n[i - 1] + tmp;
    }
    for (int i = 1; i <= c; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> tmp;
            pre_r[i][j] = pre_r[i][j - 1] + tmp;
        }
    }

    fill(&dp[0][0], &dp[0][0] + 45 * 1605, INF);
    dp[0][0] = 0;
    for (int i = 1; i <= c - 1; i++) {
        for (int j = 0; j <= 1600; j++) {
            for (int k = 0; k <= i - 1; k++) {
                if (j - (pre_r[i][i] - pre_r[i][k]) < 0) continue;
                dp[i][j] = min(dp[i][j],
                    dp[k][j - (pre_r[i][i] - pre_r[i][k])] +
                    (pre_p[i] - pre_p[k]) * (pre_n[c] - pre_n[k]) +
                    s[i] * (pre_n[i] - pre_n[k])
                );
            }
        }
    }

    int ans = -1;
    int cost;
    int i = c;
    for (int j = 0; j <= 1600; j++) {
        for (int k = 0; k <= c - 1; k++) {
            if (j - (pre_r[i][i] - pre_r[i][k]) < 0) continue;
            dp[i][j] = min(dp[i][j],
                dp[k][j - (pre_r[i][i] - pre_r[i][k])] +
                (pre_p[i] - pre_p[k]) * (pre_n[c] - pre_n[k]) +
                s[i] * (pre_n[i] - pre_n[k])
            );
            cost = dp[i][j];
            if (cost <= T)
                ans = max(ans, j);
        }
    }
    for (int j = 0; j <= 1600; j++) {
        for (int k = 0; k <= c - 1; k++) {
            cost = dp[k][j] + (pre_p[i] - pre_p[k]) * (pre_n[c] - pre_n[k]);
            if (cost <= T)
                ans = max(ans, j);
        }
    }
    cout << ans << "\n";
    
    return 0;
}