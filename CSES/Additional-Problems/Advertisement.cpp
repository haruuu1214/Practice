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

int a[200005];

signed main()
{
    IOS
    
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];

///   height  idx
    deque <pii> dq;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int lidx = i;
        while (!dq.empty() && dq.back().first >= a[i]) {
            ans = max(ans, dq.back().first * (i - dq.back().second));
            lidx = min(lidx, dq.back().second);
            dq.pop_back();
        }
        dq.push_back({a[i], lidx});
    }

    while (!dq.empty()) {
        ans = max(ans, dq.back().first * (n + 1 - dq.back().second));
        dq.pop_back();
    }

    cout << ans << "\n";
    
    return 0;
}