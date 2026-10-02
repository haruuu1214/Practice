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

int pre[1000005]; // max
int suf[1000005]; // min
int a[1000005];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    pre[0] = -INF;
    for (int i = 1; i <= n; i++)
        pre[i] = max(pre[i - 1], a[i]);
    suf[n + 1] = INF;
    for (int i = n; i >= 1; i--)
        suf[i] = min(suf[i + 1], a[i]);
    
    int cnt = 0;
    for (int i = 2; i <= n - 1; i++) {
        if (pre[i - 1] < a[i] && a[i] < suf[i + 1])
            cnt++;
    }
    cout << cnt << "\n";
}

signed main()
{
    IOS
    int t = 1;
    cin >> t;

    while (t--)
        solve();
    
    return 0;
}