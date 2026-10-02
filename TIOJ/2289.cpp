#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
// const ll INF = 1e18;
const int INF = 2e9;


const int N = 500005;
pii a[N];

signed main()
{
    IO
    
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= q; i++)
        cin >> a[i].first >> a[i].second;
    sort(a + 1, a + q + 1);

    int ans = 1, l = a[1].first, r = a[1].second;
    for (int i = 2; i <= q; i++) {
        if (max(l, a[i].first) <= min(r, a[i].second)) {
            l = max(l, a[i].first);
            r = min(r, a[i].second);
        } else {
            ans++;
            l = a[i].first;
            r = a[i].second;
        }
    }
    cout << ans << "\n";
    
    return 0;
}