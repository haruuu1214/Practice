#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

int a[10005];

signed main()
{
    IO;
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = a[1] * a[1], pre = a[1];
    for (int i = 2; i <= n; i++) {
        ans += (a[i] - pre) * (a[i] - pre);
        pre = a[i];
    }
    cout << ans << "\n";
    
    return 0;
}