#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
using namespace std;

const int mod = 998244353;
const int INF = 1e18;

const int N = 100005;

signed main() {
    IO;
    
    int n, m;
    cin >> n >> m;
    if (n % 2 == 1) {
        cout << n << "\n";
        for (int i = 1; i <= n; i++)
            cout << i << " " << 1 << "\n";
    } else if (m % 2 == 1) {
        cout << m << "\n";
        for (int i = 1; i <= m; i++)
            cout << 1 << " " << i << "\n";
    } else {
        cout << n * m << "\n";
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cout << i << " " << j << "\n";
    }
    
    return 0;
}