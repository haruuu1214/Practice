#include <bits/stdc++.h>
#define int long long
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
const int mod = 1e9 + 7;
const int two_inv = 500000004;

/// count sum : [l, r]
int count_sum(int l, int r) {
    return (((((l + r) % mod) * ((r - l + 1) % mod)) % mod) * two_inv) % mod;
}

/*
 n = 12
 i      (n / i)                nxti
 1     12 / 1 = 12       12 / 12 + 1 =  2
 2     12 / 2 =  6       12 /  6 + 1 =  3
 3     12 / 3 =  4       12 /  4 + 1 =  4
 4     12 / 4 =  3       12 /  3 + 1 =  5
 5     12 / 5 =  2       12 /  2 + 1 =  7
 7     12 / 7 =  1       12 /  1 + 1 = 13
*/

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    int res = 0;
    int i = 1;
    while (i <= n) {
        int tmp = n / i;
        int nxt_i = n / tmp + 1;
        res = (res + ((tmp * count_sum(i, nxt_i - 1)) % mod)) % mod;
        i = nxt_i;
    }
    cout << res << "\n";

    return 0;
}