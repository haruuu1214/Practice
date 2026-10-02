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

int a[100005], b[100005];

signed main()
{
    IOS
    
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