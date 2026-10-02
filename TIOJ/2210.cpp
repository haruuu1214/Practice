#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;
int s[N], a[N], b[N];
vector <int> sub;
int n;
int tot = 0;

/// 及格線在 x
int calc(int x) {
    int res = 0;
    int sum = tot; /// 總分
    for (int i = 1; i <= n; i++)
        if (s[i] < x) {
            res += (x - s[i]) * a[i];
            sum += (x - s[i]);
        }
    int tar = 2 * x * n;
    if (sum <= tar)
        return res;
    for (int i = 0; i < n; i++) {
        int id = sub[i];
        if (s[id] > x) {
            res += min(sum - tar, s[id] - x) * b[id];
            sum -= min(sum - tar, s[id] - x);
        }
        if (sum <= tar)
            break;
    }
    return res;
}

signed main() {
    IO;
    
    int c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    
    for (int i = 1; i <= n; i++) sub.push_back(i);
    sort(sub.begin(), sub.end(), [&](int p, int q) {
        return b[p] < b[q];
    });

    for (int i = 1; i <= n; i++) tot += s[i];

    int l = 0, r = c;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (calc(mid) <= calc(mid + 1))
            r = mid;
        else
            l = mid;
    }
    cout << calc(r) << "\n";

    return 0;
}