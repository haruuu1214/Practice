#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 2e9;


const int N = 100005;

signed main()
{
    IO
    
    int n;
    while (cin >> n) {
        if (n == 0) break;
        int sum = 0;
        int t, mx = 1, mn = 10;
        for (int i = 1; i <= n; i++) {
            cin >> t;
            sum += t;
            mx = max(mx, t);
            mn = min(mn, t);
        }
        sum -= mx;
        sum -= mn;
        long double ans = (long double)sum / ((long double)(n - 2));
        cout << fixed << setprecision(2) << ans << "\n";
    }
    
    return 0;
}