#pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
using namespace std;
const int N = 200005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}
int a[N];

signed main() {
    IO;

    int n;
    cin >> n;
    FOR (i, 1, n) cin >> a[i];

    vector<int> num;
    FOR (i, 1, n) num.push_back(a[i]);
    shuffle(all(num), rng);
    
    int ans = INT_MAX, k = 2;
    for (int x : num) {
        if ((long double) clock() / CLOCKS_PER_SEC > (long double)0.95) break;
        vector<int> v;
        auto build_cand = [&](int now) {
            for (int i = 2; i * i <= now; i++) {
                if (now % i == 0) {
                    while (now % i == 0) now /= i;
                    v.push_back(i);
                }
            }
            if (now != 1)
                v.push_back(now);
        };
        if (x - 1 >= 2) build_cand(x - 1);
        if (x >= 2) build_cand(x);
        if (x + 1 >= 2) build_cand(x + 1);
        for (int j : v) {
            if (j <= 1 || j == k) continue;
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] < j) cnt += j - a[i];
                else cnt += min(a[i] % j, j - a[i] % j);
            }
            if (cnt < ans) {
                ans = cnt;
                k = j;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] >= k && a[i] % k <= k - a[i] % k)
            cout << a[i] - a[i] % k << " \n"[i == n];
        else
            cout << a[i] + k - a[i] % k << " \n"[i == n];
    }

    return 0;
}