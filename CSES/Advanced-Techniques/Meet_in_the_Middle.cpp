#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

int a[50];

signed main()
{
    IOS
    
    int n, x;
    cin >> n >> x;
    loop(i, 1, n) cin >> a[i];

    vector <int> L;
    
    int mid = n >> 1;
/// 1 ~ mid 、 mid ~ n
    int len;

    len = mid - 1 + 1;
/// idx need to add 1
    for (int mask = 0; mask < (1 << len); mask++) {
        int cnt = 0;
        loop(i, 0, len - 1) {
            if (mask & (1 << i))
                cnt += a[i + 1];
        }
        L.push_back(cnt);
    }
    sort(L.begin(), L.end());

    int ans = 0;
    len = n - (mid + 1) + 1;

    for (int mask = 0; mask < (1 << len); mask++) {
        int cnt = 0;
        loop(i, 0, len - 1) {
            if (cnt > x) break;
            if (mask & (1 << i))
                cnt += a[mid + i + 1];
        }
        if (cnt > x) continue;

        ans += upper_bound(L.begin(), L.end(), x - cnt) - lower_bound(L.begin(), L.end(), x - cnt);
    }
    cout << ans << "\n";

    return 0;
}