#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;
int a[N], pre[N];
int l[N], r[N];

signed main() {
    IO;
    
    int n;
    while (cin >> n) {
        FOR (i, 1, n) cin >> a[i];
        FOR (i, 1, n) pre[i] = pre[i - 1] + a[i];

        deque<int> dq;
        for (int i = 1; i <= n; i++) {
            while (! dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
            if (dq.empty())
                l[i] = 1;
            else
                l[i] = dq.back() + 1;
            dq.push_back(i);
        }
        while (! dq.empty()) dq.pop_back();
        dq.push_back(n + 1);
        for (int i = n; i >= 1; i--) {
            while (! dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
            if (dq.empty())
                r[i] = n;
            else
                r[i] = dq.back() - 1;
            dq.push_back(i);
        }

        int ans = -1, al = 0, ar = 0;
        FOR (i, 1, n) {
            int res = a[i] * (pre[r[i]] - pre[l[i] - 1]);
            if (res > ans) {
                ans = res;
                al = l[i];
                ar = r[i];
            } else if (res == ans && (l[i] < al || (l[i] == al && r[i] < ar))) {
                ans = res;
                al = l[i];
                ar = r[i];
            }
        }
        cout << ans << "\n" << al << " " << ar << "\n";
    }
    
    
    return 0;
}