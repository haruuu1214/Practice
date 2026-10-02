#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
const int mod = 1e9 + 7;
const int INF = 1e18;

signed main() {
    IO;

    int n;
    cin >> n;

    int ans = 0;

    for (int i = 0; i <= 50; i++) {
        if (n < (1ll << i))
            break;

        int len = n - ((1ll << i) - 1);

        ans += (1ll << i) * (len / (1ll << (i + 1)));

        int less = min((1ll << i), len % (1ll << (i + 1)));

        ans += max(0ll, less);
    }

    cout << ans << "\n";

    return 0;
}