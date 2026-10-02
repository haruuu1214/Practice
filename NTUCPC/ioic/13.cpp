#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int N = 1000005;
int cnt[N];

signed main() {
    IO;
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int MX = 0, S = 0;
    FOR(i, 0, n - 1) {
        cin >> a[i];
        cnt[a[i]] += 1;
        MX = max(MX, a[i]);
    }

    for (int i = MX - 1; i >= 1; i--)
        cnt[i] += cnt[i + 1];
    
    int ans = 0;
    for (int i = k; i <= MX; i++) {
        int res = 0;
        for (int j = i; j <= MX; j += i)
            res += cnt[j];
        ans = max(ans, res * i);
    }
    cout << ans << "\n";

    return 0;
}