#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define FOR(p, a, b) for (int p = a; p <= b; p++)
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
const int INF = 1e18;
const int N = 50005;

int a[N], b[N];

signed main() {
    IO;

    int n;
    while (cin >> n) {
        FOR (i, 1, n) cin >> a[i];
        FOR (i, 1, n) cin >> b[i];
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);
        int ans = 0;
        FOR (i, 1, n) ans += a[i] * b[i];
        cout << ans << "\n";
    }

    return 0;
}