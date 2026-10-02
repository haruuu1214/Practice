#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

int dp[4][200005];

void solve()
{
    int n;
    cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++)
            sum += dp[j][i - 1];
        for (int j = 0; j < 4; j++)
            dp[j][i] = sum - dp[j][i - 1];
    }
    cout << dp[0][n] << "\n";
}

signed main()
{
    IOS
    int t, cnt = 0;
    cin >> t;

    while (t--) {
        //cout << "Case " << ++cnt << ": ";
        solve();
    }
    
    return 0;
}