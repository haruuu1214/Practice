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
    
    int a, b, x1, y1, x2, y2;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;
    int dx = 0, dy = 0;
    if (a < x1)
        dx = x1 - a;
    else if (x2 < a)
        dx = a - x2;
    
    if (b < y1)
        dy = y1 - b;
    else if (y2 < b)
        dy = b - y2;
    cout << dx + dy << "\n";
    
    return 0;
}