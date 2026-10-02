#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 1e18;

const int N = 1005;
int a[N];

signed main()
{
    IOS
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    long double ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] > a[j]) {
                int res = 0;
                res += a[j] * (a[i] - a[j]);
                res += a[j] * (a[j] - 1) / 2;
                int all = a[i] * a[j];
                ans += ((long double)res) / all;
            } else {
                int res = 0;
                res += a[i] * (a[i] - 1) / 2;
                int all = a[i] * a[j];
                ans += ((long double)res) / all;
            }
        }
    }
    ans = nearbyint(ans * (1e6)) / 1e6;
    cout << fixed << setprecision(6) << ans << "\n";

    return 0;
}