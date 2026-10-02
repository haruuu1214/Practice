#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= b; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

signed main() {
    IO;
    
    int a, b;
    while (cin >> a >> b) {
        int ans = 0;
        int c, d;
        while (a != 0 && b != 0) {
            c = a / b;
            d = a % b;
            ans += c;
            a = b;
            b = d;
        }
        cout << ans << "\n";
    }
    
    return 0;
}