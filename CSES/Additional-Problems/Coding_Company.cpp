#pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

/// dp[i][j][k] 為 前 i 個人 有 j 個為匹配 且 penalty = k 的情況
int a[105];
int dp[2][55][10005];

signed main()
{
    IOS
    
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    sort(a + 1, a + n + 1, greater<int>());

    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n / 2; j++) {
            for (int k = 0; k <= 10000; k++) {
                int now = i % 2;
                int pre = (i + 1) % 2;

                dp[now][j][k] = 0;
                /// 第 i 個人 新開一組
                if (j - 1 >= 0 && k - a[i] >= 0)
                    dp[now][j][k] += dp[pre][j - 1][k - a[i]];
                
                /// 第 i 個人 加入其中一組
                if (j + 1 <= n / 2 && k + a[i] <= 10000)
                    dp[now][j][k] += (j + 1) * dp[pre][j + 1][k + a[i]];
                
                /// 第 i 個人 加入其中一組 沒有結束
                dp[now][j][k] += j * dp[pre][j][k];

                /// 第 i 個人 自己一組
                dp[now][j][k] += dp[pre][j][k];

                dp[now][j][k] %= mod;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i <= x; i++)
        cnt = (cnt + dp[n % 2][0][i]) % mod;
    
    cout << cnt << "\n";
    
    return 0;
}
/*
3 3
2 3 5
*/