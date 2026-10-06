#pragma GCC optimize("Ofast,unroll-loops,O3")
#pragma GCC target("popcnt")
#include <bits/stdc++.h>
#define int long long
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

array <bitset<3005>, 3005> bit;

signed main()
{
    IO;
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> bit[i];
    
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int x = (bit[i] & bit[j]).count();
            cnt += x * (x - 1);
        }
    }
    cout << cnt / 2 << "\n";
    
    return 0;
}