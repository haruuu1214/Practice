#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 200005;

bool is_pr[50005];

void solve() {
    int l, r;
    cin >> l >> r;
    int n = r - l + 1;
    vector <bool> is_prime(n, true);
    int zro = l;
    for (int i = 2; i * i <= r; i++) {
        if (is_pr[i]) {
            int strt = max(i * i, ((zro + i - 1) / i) * i);
            for (int j = strt; j <= r; j += i)
                is_prime[j - zro] = false;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (is_prime[i])
            cnt++;
    cout << cnt << "\n";
}

signed main() {
    IO;
    
    fill(is_pr, is_pr + 50005, true);
    is_pr[0] = is_pr[1] = false;
    for (int i = 2; i <= 50000; i++) {
        if (is_pr[i]) {
            for (int j = i * i; j <= 50000; j += i)
                is_pr[j] = false;
        }
    }

    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}