#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;
pii a[N];

signed main() {
    IO;
    
    int n;
    cin >> n;
    int hor, ver;
    int x = 0, y = 0;
    n += 1;
    cin >> y;
    a[1] = {x, y};
    FOR (i, 2, n) {
        cin >> hor >> ver;
        x += hor;
        y += ver;
        a[i] = {x, y};
    }
    
    int ans = 0;
    deque<pii> dq; /// [ left_id, height ]
    FOR (i, 1, n) {
        int lid = a[i].first, h = a[i].second;
        while (! dq.empty() && dq.back().second >= h) { 
            int area = dq.back().second * (a[i].first - dq.back().first);
            ans = max(ans, area);
            lid = min(lid, dq.back().first);
            dq.pop_back();
        }
        dq.push_back({lid, h});
    }
    // int lst_x = a[n].first;
    // while (! dq.empty()) { 
    //     int area = dq.back().second * (lst_x - dq.back().first);
    //     ans = max(ans, area);
    //     dq.pop_back();
    // }
    cout << ans << "\n";

    return 0;
}
/*
3
2
2
2
1
-1
1
-3

{0, 2}
{2, 4}
{3, 3}
{4, 3}
*/