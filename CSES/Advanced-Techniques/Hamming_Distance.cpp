#pragma GCC optimize("Ofast,unroll-loops,O3")
#pragma GCC target("popcnt")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
#define STL(x) for(auto &HEHE:x) cout << HEHE << " "; cout << "\n";
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

array <bitset<35>, 20005> bit;

signed main()
{
    IOS
    
    int n, k;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++)
        cin >> bit[i];

    int mn = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int x = (bit[i] ^ bit[j]).count();
            mn = min(mn, x);
        }
    }

    cout << mn << "\n";
    
    return 0;
}