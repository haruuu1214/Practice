#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define loop(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
void space() {cout << "\n";}

int a[505];
int G[505][505];
int dp[505][505];

signed main()
{
    IOS

    int n;
    cin >> n;

    loop(i, 1, n) cin >> a[i];

    loop(i, 1, n) {
        loop(j, i+1, n) {
            G[i][j] = __gcd(a[i], a[j]);
        }
    }

    fill(&dp[0][0], &dp[0][0] + 505 * 505, -1e18);
    loop(i, 1, n+1) dp[i][i-1] = 0;

    for (int l=n; l>=1; l--) {
        for (int r=l+1; r<=n; r++) {
            for (int k = l+1; k <= r-1; k++) {
                if (G[l][k] != 1 && G[k][r] != 1 && G[l][r] != 1) {
                    dp[l][r] = max(dp[l][r],  G[l][k] + G[k][r] + dp[l+1][k-1] + dp[k+1][r-1]);
                }
            }

            if (G[l][r] > 1)
                dp[l][r] = max(dp[l][r], G[l][r] + dp[l+1][r-1]);
            
            for (int k = l+1; k < r-1; k++) {
                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k+1][r]);
            }
        }
    }
    cout << (dp[1][n] < 0 ? -1 : dp[1][n]) << "\n";
    
    return 0;
}