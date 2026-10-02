#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

signed main() {
    IO;
    
    int n, m;
    while (cin >> m >> n) {
        if (! m && ! n) break;
        int t, w, g;
        vector<int> fail(m);
        int ans = 0, cnt = 0;
        FOR (i, 1, n) {
            cin >> t >> w >> g;
            --w;
            if (fail[w] == -1)
                continue;
            if (g) {
                cnt += 1;
                ans += t + 20 * fail[w];
                fail[w] = -1;
            } else {
                fail[w] += 1;
            }
        }
        cout << ans << " " << cnt << "\n";
    }
    
    return 0;
}