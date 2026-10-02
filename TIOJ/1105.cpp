#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

pii a[3005];

signed main()
{
    IOS
    
    int n;
    while (cin >> n) {
        if (n == 0) break;
        for (int i = 1; i <= n; i++)
            cin >> a[i].first >> a[i].second;
        
        int mx = -1, x, y;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if ((a[i].first - a[j].first) * (a[i].first - a[j].first) + (a[i].second - a[j].second) * (a[i].second - a[j].second) > mx) {
                    mx = (a[i].first - a[j].first) * (a[i].first - a[j].first) + (a[i].second - a[j].second) * (a[i].second - a[j].second);
                    x = i, y = j;
                }
            }
        }
        cout << x - 1 << " " << y - 1 << "\n";
    }
    
    return 0;
}