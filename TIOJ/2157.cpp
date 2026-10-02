#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 500005;
int two[N];

signed main() {
    IO;
    
    int n;
    cin >> n;
    two[0] = 1;
    for (int i = 1; i <= n; i++) two[i] = (two[i - 1] * 2) % mod;
    vector <int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    int ans = 0;
    int x = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] != x) {
            if (cnt) {
                int less = n - i;
                ans = (ans + x * (two[cnt] - 1) % mod * two[less] % mod) % mod;
            }
            x = v[i];
            cnt = 1;
        } else {
            cnt += 1;
        }
    }
    if (cnt)
        ans = (ans + x * (two[cnt] - 1) % mod) % mod;
    cout << ans << "\n";

    return 0;
}