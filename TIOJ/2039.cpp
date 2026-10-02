#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
const int INF = 2e9;

pii operator+(const pii p1, const pii p2) {
    return {p1.first + p2.first, p1.second + p2.second};
}
pii operator-(const pii p1, const pii p2) {
    return {p1.first - p2.first, p1.second - p2.second};
}
const int N = 2000005;
int n, k;
int a[N];
pii dp0[N];
pii dp1[N];

pii calc(int c) {
    dp0[1] = {0, 0};
    dp1[1] = {c - a[1], 1};
    for (int i = 2; i <= n; i++) {
        dp0[i] = max(dp0[i - 1], dp1[i - 1] + make_pair(+ a[i], 0));
        dp1[i] = max(dp1[i - 1], dp0[i - 1] + make_pair(- a[i] + c, 1));
    }
    return dp0[n];
}

void solve() {
    pii p = calc(0);
    if (p.second <= k) {
        cout << p.first << "\n";
        return;
    }
    int l = -1e5, r = 1e6;
    pii res;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        res = calc(mid);
        // cout << res.first << " " << res.second << "\n";
        if (res.second == k) {
            cout << res.first - mid * k << "\n";
            return;
        } else if (res.second > k)
            r = mid;
        else
            l = mid;
    }
    pii p1 = calc(l);
    pii p2 = calc(r);
    int dp_1 = p1.first - l * p1.second;
    int dp_2 = p2.first - r * p2.second;
    cout << (dp_1 + (dp_2 - dp_1) * (k - p1.second) / (p2.second - p1.second)) << "\n";
}

signed main() {
    IO;
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    solve();

    return 0;
}