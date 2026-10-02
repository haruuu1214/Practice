#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

int a[105];
bool dp[1000005];

signed main()
{
    IOS
    
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        dp[a[i]] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i - a[j] > 0 && dp[i - a[j]] == 0)
                dp[i] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << (dp[i] ? 'W' : 'L');
    
    return 0;
}