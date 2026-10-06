#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

int a[100005], b[100005];

signed main()
{
    IO;
    
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    sort(b + 1, b + m + 1);
    
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        int idx = lower_bound(b + 1, b + m + 1, a[i]) - b;
        if (idx <= m)
            ans = min(ans, abs(b[idx] - a[i]));
        if (idx - 1 >= 1)
            ans = min(ans, abs(a[i] - b[idx]));
    }
    
    cout << ans << "\n";
    
    return 0;
}