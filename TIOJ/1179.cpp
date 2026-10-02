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
    
    int x;
    while (cin >> x) {
        if (!x) break;
        int sum = x, tot = 1;
        cout << x << " ";
        while (cin >> x) {
            if (!x) break;
            sum += x;
            tot += 1;
        }
        cout << tot << " " << sum << "\n";
    }
    
    return 0;
}