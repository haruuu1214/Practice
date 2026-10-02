#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

bool mp[1005][1005];
int depth[1005];

signed main()
{
    IOS
    
    int n, m;
    cin >> n >> m;
    char ch;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> ch;
            if (ch == '.')
                mp[i][j] = true;
        }
    }

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!mp[i][j])
                depth[j] = 0;
            else
                depth[j]++;
        }
///     height index
        deque <pii> dq;
        for (int j = 1; j <= m; j++) {
            int lidx = j;
            while (!dq.empty() && dq.back().first >= depth[j]) {
                mx = max(mx, dq.back().first * (j - dq.back().second));
                lidx = min(lidx, dq.back().second);
                dq.pop_back();
            }
            dq.push_back({depth[j], lidx});
        }
        while (!dq.empty()) {
            mx = max(mx, dq.back().first * (m + 1 - dq.back().second));
            dq.pop_back();
        }
    }
    cout << mx << "\n";
    
    return 0;
}