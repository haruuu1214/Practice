#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

int a[25];

signed main()
{
    IOS
    
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k; i++) cin >> a[i];

    int ans = 0, mul_cnt, mul;
    for (int mask = 0; mask < (1 << k); mask++) {
        bool F = true;
        mul_cnt = 0; mul = 1;
        for (int i = 0; i < k; i++) {
            if (mask & (1 << i)) {
                if (mul > n / a[i]) {
                    F = false;
                    break;
                }
                mul_cnt++;
                mul *= a[i];
            }
        }
        if (!F) continue;
        if (mul_cnt == 0) continue;

        if (mul_cnt % 2 == 1) ans += n / mul;
        else ans -= n / mul;
    }
    cout << ans << "\n";
    
    return 0;
}