#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 1005;
int d[N];
int dp[1005][105], from[1005][105];
int buy[1005][105];
// 第 i 天 運 j 台到下一站

signed main() {
    IO;
    
    int n, m, a, c;
    cin >> n >> m >> a >> c;
    FOR (i, 1, n) cin >> d[i];

    fill(&dp[0][0], &dp[0][0] + 1005 * 105, INF);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 100; j++) { // 這站運 j 站到下一站
            for (int k = 0; k <= max(0ll, j + d[i] - m); k++) { // 上一站運 k 台車過來
                int cost = a * k + c * max(0ll, (j + d[i]) - (m + k));
                if (dp[i - 1][k] + cost < dp[i][j]) {
                    dp[i][j] = dp[i - 1][k] + cost;
                    from[i][j] = k;
                    buy[i][j] = d[i] + j - k;
                }
            }
        }
    }

    cout << dp[n][0] << "\n";
    vector<int> ans;
    int x = n, y = 0;
    while (x > 0) {
        ans.push_back(buy[x][y]);
        pii pre = {x - 1, from[x][y]};
        x = pre.first, y = pre.second;
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans)
        cout << i << " ";
    
    return 0;
}