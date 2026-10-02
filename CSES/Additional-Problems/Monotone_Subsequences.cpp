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

void solve()
{
    int n, k;
    cin >> n >> k;
    if (k * k < n) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (int i = 1; i <= n; i += k) {
        int now;
        if (i + k - 1 <= n)
            now = i + k - 1;
        else
            now = n;
        int last = i;
        for (int j = now; j >= last; j--)
            cout << j << " ";
    }
    cout << "\n";
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