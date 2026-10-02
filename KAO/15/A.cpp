#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

signed main() {
    IO;
    
    int n;
    cin >> n;
    if (n > 0) {
        cout << 2 * n - 1 << "\n";
    } else {
        cout << 2 * (-n) << "\n";
    }
    
    return 0;
}