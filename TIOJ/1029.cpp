#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 1005;
int a[N];
int dp[N][N];

signed main() {
    IO;
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    for (int l = n; l >= 1; l--) {
        for (int r = l; r <= n; r++) {
            if (l == r) {
                dp[l][r] = a[l];
            } else {
                int len = r - l + 1;
                if (len % 2 == 1)
                    dp[l][r] = max(
                        a[l] + dp[l + 1][r],
                        a[r] + dp[l][r - 1]
                    );
                else
                    dp[l][r] = min(
                        - a[l] + dp[l + 1][r],
                        - a[r] + dp[l][r - 1]
                    );
            }
        }
    }
    int sub = dp[1][n];
    int add = 0;
    for (int i = 1; i <= n; i++) add += a[i];
    if (n % 2 == 0)
        sub = -sub;
    int A = (add + sub) / 2;
    int B = (add - sub) / 2;
    cout << A << " " << B << "\n";
    
    return 0;
}