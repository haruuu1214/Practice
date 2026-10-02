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
    
    int x;
    vector<int> v;
    FOR (i, 0, 40) v.push_back((1ll << i));
    while (cin >> x) {
        if (! x) break;
        int ans = 0;
        int id = upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
        ans += v[id];
        while (cin >> x) {
            if (! x) break;
            id = upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
            ans += v[id];
        }
        cout << ans << "\n";
    }
    
    return 0;
}