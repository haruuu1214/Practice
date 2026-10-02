#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int N = 2505;

bitset <2505> a[N], tmp;

signed main() {
    IO;
    
    int n;
    cin >> n;
    int m, x;
    for (int i = 0; i < n; i++) {
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> x;
            a[i][x] = true;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            tmp = a[i] & a[j];
            if (tmp.count())
                ++ans;
        }
    cout << ans << "\n";
    
    return 0;
}