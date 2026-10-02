
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define siz(x) (int)x.size()
using namespace std;

const int mod = 998244353; // 1e9 + 7;

const int N = 1;

signed main() {
    IO;
    
    int n;
    cin >> n;
    int ppre_sum = 0, pre_sum = 1, pre = 1;
    for (int i = 2; i <= n; i++) {
        int nxt = ppre_sum;
        int nxt_sum = (nxt + pre_sum) % mod;
        pre = nxt;
        ppre_sum = pre_sum;
        pre_sum = nxt_sum;
    }
    cout << pre << "\n";
    
    return 0;
}