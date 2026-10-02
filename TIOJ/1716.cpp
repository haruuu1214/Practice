#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

signed main() {
    IO;
    
    int t;
    cin >> t;
    int a, b, c;
    while (t--) {
        cin >> a >> b >> c;
        if (b * b - 4 * a * c >= 0) {
            int x = b * b - 4 * a * c;
            int sq = sqrt(x);
            if (sq * sq == x)
                cout << "Yes\n";
            else
                cout << "No\n";
        } else {
            cout << "No\n";
        }
    }
    
    return 0;
}