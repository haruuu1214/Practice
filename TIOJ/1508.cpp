#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 15;
int a[N];

signed main() {
    IO;
    
    int n, m;
    cin >> n >> m;
    bitset <100005> bs;
    for (int i = 1; i <= n; i++) {
        int tot = 0;
        bs.reset();
        bs[0] = 1;
        for (int j = 0; j < m; j++) {
            cin >> a[j];
            tot += a[j];
            bs |= bs << a[j];
        }
        if (tot % 2 == 0 && bs[tot / 2])
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    
    return 0;
}