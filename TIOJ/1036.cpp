#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int N = 10000005;
bool is_prime[N];
int pre[N];
vector <int> primes;

void init() {
    fill(is_prime, is_prime + N, true);
    is_prime[1] = false;
    pre[1] = 0;
    for (int i = 2; i <= 10000000; i++) {
        if (is_prime[i])
            primes.push_back(i);
        pre[i] = pre[i - 1] + (is_prime[i] ? 1 : 0);
        for (int p : primes) {
            if (p * i > 10000000) break;
            is_prime[p * i] = false;
            if (i % p == 0) break;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    cout << pre[n] << "\n";
}

signed main()
{
    IOS
    init();
    int t = 1;
    cin >> t;

    while (t--)
        solve();
    
    return 0;
}