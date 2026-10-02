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
    
    int a, b, c;
    while (cin >> a >> b >> c) {
        if (a > c) swap(a, c);
        if (b > c) swap(b, c);
        if (a + b == c)
            cout << "Good Pair\n";
        else
            cout << "Not Good Pair\n";
    }
    
    return 0;
}