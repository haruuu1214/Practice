#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 2e9;

const int N = 100005;

signed main()
{
    IO
    
    int n, a;
    while (cin >> n) {
        priority_queue <ll, vector<ll>, greater<ll>> Q;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            Q.push(a);
        }
        ll ans = 0;
        while (Q.size() >= 2) {
            ll x = Q.top(); Q.pop();
            ll y = Q.top(); Q.pop();
            ans += x + y;
            Q.push(x + y);
        }
        cout << ans << "\n";
    }
    
    return 0;
}