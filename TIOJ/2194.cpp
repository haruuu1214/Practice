#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e15;


const int N = 1005;
int t[N], s[N], d[N];
int n, m;

// return [more than k 's amount, equal k 's amount]
pii calc_amount(int R, int k) {
    int A = 0, B = 0;
    for (int i = 1; i <= R; i++) {
        if (d[i] == 0) {
            if (s[i] > k)
                A = INF;
            else if (s[i] == k)
                B = INF;
        } else if (s[i] >= k) {
            int tmp = (s[i] - k) / d[i] + 1;
            A += tmp;
            if (s[i] % d[i] == k % d[i]) {
                A -= 1;
                B += 1;
            }
        }
    }
    return {A, B};
}

/// calculate sum of all number bigger than k
/// k 's amount cannot be INFINITY
int calc_ans(int R, int k) {
    int sum = 0;
    for (int i = 1; i <= R; i++) {
        if (d[i] == 0) {
            ;
        } else if (s[i] >= k) {
            int tmp = (s[i] - k) / d[i] + 1;
            if (s[i] % d[i] == k % d[i])
                tmp -= 1;
            sum += (2 * s[i] - (tmp - 1) * d[i]) * tmp / 2;
        }
    }
    return sum;
}

signed main() {
    IO;
    
    cin >> n >> m;
    for (int i = 1; i < n; i++) cin >> t[i];
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> d[i];

    int MXS = 0;
    for (int i = 1; i <= n; i++) MXS = max(MXS, s[i]);

    int ans = 0;
    for (int R = 1; R <= n; R++) {
        int ti = 0;
        for (int i = 1; i < R; i++) ti += t[i];
        int tar = m - ti;
        int l = 0, r = MXS + 1;
        pii p;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            p = calc_amount(R, mid);
            if (p.first + p.second > tar)
                l = mid;
            else
                r = mid;
        }
        p = calc_amount(R, l);
        int res = calc_ans(R, l) + max(0ll, min(tar - p.first, p.second)) * l;
        ans = max(ans, res);
    }
    cout << ans << "\n";

    return 0;
}