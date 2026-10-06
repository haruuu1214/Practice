#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;

const int N = 100005;
int dp[25][N];

signed main()
{
    IO;
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> dp[0][i];
    
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }

    int q;
    cin >> q;
    int a, b;
    while (q--) {
        cin >> a >> b;
        for (int i = 0; i <= 20; i++) {
            if (b & (1ll << i))
                a = dp[i][a];
        }
        cout << a << "\n";
    }
    
    return 0;
}