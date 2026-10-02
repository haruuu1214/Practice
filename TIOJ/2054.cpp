#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

signed main() {
    IO;
    
    int n, h, w;
    cin >> n >> w >> h;

    vector<pii> v(n);
    vector<int> px;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        px.push_back(v[i].first);
    }
    sort(px.begin(), px.end());
    px.resize(unique(px.begin(), px.end()) - px.begin());
    sort(v.begin(), v.end(), [&](pii p, pii q) {
        return p.second < q.second;
    });
    int ans = 0;
    for (int L : px) {
        int R = L + h;
        deque<int> Y;
        for (auto &[x, y] : v) {
            if (L <= x && x <= R) {
                while (!Y.empty() && Y.front() < y - w)
                    Y.pop_front();
                Y.push_back(y);
                ans = max(ans, (int)Y.size());
            }
        }
    }
    cout << ans << "\n";
    
    return 0;
}