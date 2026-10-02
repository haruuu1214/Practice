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

int a[10005];

signed main()
{
    IOS
    
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