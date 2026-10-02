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


signed main()
{
    IOS
    
    int n;
    while (cin >> n) {
        if (n == 0) break;

        vector <pii> v;
        int a, b;
        for (int i = 1; i <= n; i++) {
            cin >> a >> b;
            v.push_back({a, b});
        }
        sort(v.begin(), v.end(), [&](pii x, pii y) {
            return x.second > y.second;
        });
        
        int ans = 0;
        int t = 0;
        for (auto &now : v) {
            t += now.first;
            ans = max(ans, t + now.second);
        }
        cout << ans << "\n";
    }

    return 0;
}