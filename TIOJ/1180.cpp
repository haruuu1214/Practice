#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= b; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

signed main() {
    IO;
    
    int t, n;
    cin >> t;
    FOR(tt, 1, t) {
        cout << "Case #" << tt << ":\n";
        cin >> n;
        int now = 1;
        cout << "TFCIS" << 0 << "=" << now << "\n";
        FOR(i, 1, n) {
            now *= i;
            cout << "TFCIS" << i << "=" << now << "\n";
        }
    }
    
    return 0;
}