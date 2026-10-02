#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

double power[105];

signed main()
{
    IOS
    
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= k; i++) {
        power[i] = 1;
        for (int j = 1; j <= n; j++)
            power[i] *= (double)i / k;
    }

    double ans = 0;
    for (int i = k; i >= 1; i--) {
        ans += i * (power[i] - power[i - 1]);
    }
    cout << fixed << setprecision(6) << ans << "\n";
    
    return 0;
}