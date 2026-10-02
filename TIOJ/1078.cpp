#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

int C[105][105];

void build() {
    C[0][0] = 1;
    for (int i = 1; i <= 60; i++) {
        C[i][0] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        C[i][i] = 1;
    }
}

void solve() {
    int n;
    cin >> n;
    int mx = 0;
    while ((n >> mx))
        ++mx;
    int ans = 0;
    /// 100 -> 1 , 1x , mx = 3
    /// 101 -> 1 , 1x , mx = 3
    for (int i = 1; i < mx; i++) {
        /// i 個 -> 至少 (i / 2 + 1) 個 1
        /// 5 位 -> 1xxxx -> C(4, 2) + C(4, 3) + C(4, 4) = 11
        /// 6 位 -> 1xxxxx -> C(5, 3) + C(5, 4) + C(5, 5) = 16
        for (int j = i / 2; j <= i - 1; j++)
            ans += C[i - 1][j];
    }
    /// 101001
    /// -> 100000 ~ 101011
    /// -> 100xxx + 10100x + 101011 (101010)
    int sum_zro = 0, sum_one = 0;
    for (int i = mx - 1; i >= 0; i--) {
        if (i == 0) {
            if (n & 1ll) {
                if (sum_one > sum_zro + 1)
                    ans++;
                if (sum_one + 1 > sum_zro)
                    ans++;
            } else {
                if (sum_one > sum_zro + 1)
                    ans++;
            }
            break;
        }
        if (n & (1ll << i)) {
            if (i != mx - 1) {
                /// 100xxxx -> 至少 3 個 0
                /// 100xxx -> 至少 3 個 0
                /// 100xx -> 至少 2 個 0
                for (int j = 0; j <= i; j++) {
                    if ((sum_zro + 1) + (i - j) < sum_one + j)
                        ans += C[i][j];
                }
            }
            sum_one++;
        } else {
            sum_zro++;
        }
    }
    cout << ans << "\n";
}

signed main() {
    IO;
    build();
    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}