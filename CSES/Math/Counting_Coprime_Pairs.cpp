#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 1e18;

const int N = 1000005;

vector <int> primes;
bool is_prime[N];
int lpf[N];

void build(int n) {
    fill(is_prime, is_prime + N, true);
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            lpf[i] = i;
        }
        for (int p : primes) {
            if (i * p > n) break;
            is_prime[i * p] = 0;
            lpf[i * p] = p;
            if (i % p == 0) break;
        }
    }
}

int a[N];
int mob[N];

void Mobius(int n) {
    mob[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (lpf[i / lpf[i]] == lpf[i])
            mob[i] = 0;
        else
            mob[i] = -1 * mob[i / lpf[i]];
    }
}


signed main()
{
    IOS
    
    int n, t;
    cin >> n;
    int MXN = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        a[t]++;
        MXN = max(MXN, t);
    }

    build(MXN); Mobius(MXN);

    int ans = n * (n - 1) / 2ll;
    for (int i = 2; i <= MXN; i++) {
        if (mob[i] != 0) {
            int cnt = 0;
            for (int j = i; j <= MXN; j += i)
                cnt += a[j];
            ans += mob[i] * cnt * (cnt - 1) / 2;
        }
    }
    cout << ans << "\n";
    
    return 0;
}