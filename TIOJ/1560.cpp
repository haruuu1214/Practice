#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= b; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;
int dp[2][55];

signed main() {
    IO;
    
    dp[0][1] = dp[1][1] = 1;
    FOR(i, 2, 50) {
        if (i & 1) {
            dp[0][i] = dp[1][i - 1];
            dp[1][i] = dp[0][i - 1] + dp[1][i - 1];
        } else {
            dp[0][i] = dp[1][i - 1];
            dp[1][i] = dp[0][i - 1] + dp[1][i - 1];
        }
    }
    int n;
    while (cin >> n) {
        cout << dp[0][n] + dp[1][n] << "\n";
    }
    
    return 0;
}