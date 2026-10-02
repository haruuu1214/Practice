#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 2e9;


const int N = 5005;
int a[N], b[N], c[N];
int prea[N];
int dp[2][N];
int predp[2][N];

signed main()
{
    IO
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> c[i];

    for (int i = 1; i <= n; i++) prea[i] = prea[i - 1] + a[i];
    
    dp[0][0] = 1;
    predp[0][0] = 1;
    for (int j = 1; j <= 5000; j++)
        predp[0][j] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 5000; j++)
            dp[i % 2][j] = 0;
        for (int j = b[i]; j <= prea[i]; j++) {
            int lft = max(0ll, j - c[i]);
            int rgt = min(5000ll, min(j - b[i], prea[i - 1]));
            if (lft <= rgt)
                dp[i % 2][j] = (predp[(i + 1) % 2][rgt] - predp[(i + 1) % 2][lft] + dp[(i + 1) % 2][lft]) % mod;
        }
        predp[i % 2][0] = dp[i % 2][0];
        for (int j = 1; j <= 5000; j++)
            predp[i % 2][j] = (predp[i % 2][j - 1] + dp[i % 2][j]) % mod;
    }

    int sum = predp[n % 2][5000];
    sum = (sum + mod) % mod;
    cout << sum << "\n";


    return 0;
}