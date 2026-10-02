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
    
    int n;
    while (cin >> n) {
        if (!n) break;
        vector<int> v(n);
        FOR(i, 0, n - 1) cin >> v[i];
        sort(v.begin(), v.end());
        FOR(i, 0, n - 1) cout << v[i] << " \n"[i == n - 1];
    }
    
    return 0;
}