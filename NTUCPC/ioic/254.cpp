
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define siz(x) (int)x.size()
using namespace std;

const int mod = 998244353; // 1e9 + 7;

const int N = 200005;
int a[N], cnt[N], ans[N];

signed main() {
    IO;
    
    int n, q;
    cin >> n >> q;
    FOR (i, 1, n) cin >> a[i];
    int l = n + 1;
    for (int r = n; r >= 1; r--) {
        while (l - 1 >= 1 && cnt[a[l - 1]] == 0) {
            l -= 1;
            cnt[a[l]] += 1;
        }
        ans[r] = l;
        cnt[a[r]] -= 1;
    }
    int r;
    while (q--) {
        cin >> r;
        cout << ans[r] << "\n";
    }
    
    return 0;
}