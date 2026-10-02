#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 105;
int a[N];

signed main() {
    IO;
    
    int m, p, n;
    cin >> m >> p >> n;
    FOR (i, 1, n) cin >> a[i];
    a[n + 1] = p;
    n += 1;
    
    int ans = 0;
    int now = 0;
    FOR (i, 1, n) {
        if (i + 1 <= n && now + m >= a[i + 1])
            ;
        else if (now + m < a[i]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        } else {
            ans += 1;
            now = a[i];
        }
    }
    cout << ans - 1 << "\n";
    
    return 0;
}