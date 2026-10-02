#include <bits/stdc++.h>
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
using namespace std;

const int mod = 998244353;
const int INF = 2e9;

const int N = 500005;
int a[N], b[N];
int cnt[2 * N];

signed main() {
    IO;
    
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    FOR (i, 1, n) cin >> a[i];
    FOR (i, 1, m) cin >> b[i];

    int col = 0;
    int ans = 0;
    int j = 0;
    for (int i = 0; i <= n; i++) {
        if (i > 0) {
            if (! cnt[a[i]])
                col += 1;
            cnt[a[i]] += 1;
        }
        while (col > x && j >= 1) {
            cnt[b[j]] -= 1;
            if (! cnt[b[j]])
                col -= 1;
            j -= 1;
        }
        while (col < x && j + 1 <= m) {
            j += 1;
            if (! cnt[b[j]])
                col += 1;
            cnt[b[j]] += 1;
        }
        while (col == x && j + 1 <= m && cnt[b[j + 1]] > 0) {
            j += 1;
            cnt[b[j]] += 1;
        }
        if (col <= x)
            ans = max(ans, i + j);
    }
    cout << ans << "\n";
    
    return 0;
}