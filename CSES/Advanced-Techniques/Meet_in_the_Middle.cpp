#include <bits/stdc++.h>
#define int long long
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int a[50];

signed main()
{
    IO;
    
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector <int> L;
    
    int mid = n >> 1;
/// 1 ~ mid 、 mid ~ n
    int len;

    len = mid - 1 + 1;
/// idx need to add 1
    for (int mask = 0; mask < (1 << len); mask++) {
        int cnt = 0;
        for (int i = 0; i < len; i++) {
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
        for (int i = 0; i < len; i++) {
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