#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;
int a[N], pre[N];

signed main() {
    IO
    
    int n, m;
    while (cin >> n >> m) {
        if (!n && !m) break;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];

        int l = 0, r = 1000005;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            bool fg = false;
            int cnt = 1, id = 1;
            for (int i = 1; i <= n; i++) {
                if (a[i] > mid) {
                    cnt = INF;
                    break;
                }
                if (pre[i] - pre[id - 1] > mid) {
                    id = i;
                    cnt++;
                }
            }
            if (cnt <= m + 1)
                r = mid;
            else
                l = mid;
        }
        cout << r << "\n";
    }
    
    return 0;
}