#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 2e9;


const int N = 1005;
int dp[N][N];

signed main()
{
    IO
    
    string a, b;
    getline(cin, a);
    getline(cin, b);
    int n = a.size(), m = b.size();
    if (n == 0 && m == 0) {
        cout << 0 << "\n";
        return 0;
    } else if (n == 0) {
        cout << m << "\n";
        return 0;
    } else if (m == 0) {
        cout << n << "\n";
        return 0;
    }

    for (int i = 0; i <= n; i++)
        dp[i][0] = INF;
    for (int j = 0; j <= m; j++)
        dp[0][j] = INF;
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j])
                dp[i + 1][j + 1] = dp[i][j];
            else
                dp[i + 1][j + 1] = INF;
            dp[i + 1][j + 1] = min(dp[i + 1][j + 1], min({dp[i][j + 1], dp[i + 1][j], dp[i][j]}) + 1);
        }
    }
    cout << dp[n][m] << "\n";

    return 0;
}