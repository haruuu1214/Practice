#pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;


const int N = 100005;

signed main() {
    IO;
    
    int n, r;
    cin >> n >> r;
    map<pii, int> mp;
    int rx, ry;
    for (int i = 0; i < n; i++) {
        cin >> rx >> ry;
        for (int x = - r; x <= + r; x++) {
            for (int y = - r; y <= + r; y++) {
                if (x * x + y * y <= r * r)
                    mp[{(rx + x), (ry + y)}] += 1;
            }
        }
    }
    int ans = 0;
    for (auto t : mp) {
        if (t.second % 2 == 1)
            ans += 1;
    }
    cout << ans << "\n";
    
    return 0;
}