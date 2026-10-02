#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 300005;
int x[N], y[N], w[N];

int cross(int p, int q) {
    return x[p] * y[q] - x[q] * y[p];
}

signed main() {
    IO;

    int n;
    cin >> n;
    vector <int> id;
    for (int i = 0; i < n; i++) id.push_back(i);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> w[i];
        if (y[i] < 0) {
            x[i] *= -1;
            y[i] *= -1;
        }
    }
    sort(id.begin(), id.end(), [&](int p, int q) {
        return cross(p, q) > 0;
    });

    int tot = 0;
    int mx = -INF;
    int mn = INF;
    int ans = 0;
    int i = 0;
    int resmn = 0, resmx = 0;
    while (i < n) {
        resmn = min(0ll, resmn);
        resmx = max(0ll, resmx);
        int nowx = x[id[i]], nowy = y[id[i]];
        resmn += w[id[i]]; resmx += w[id[i]]; tot += w[id[i]];
        while (i + 1 < n && cross(id[i], id[i + 1]) == 0) {
            i += 1;
            resmn += w[id[i]]; resmx += w[id[i]]; tot += w[id[i]];
        }
        mx = max(mx, resmx);
        mn = min(mn, resmn);
        i += 1;
    }

    ans = max(mx, tot - mn);
    
    cout << ans << "\n";

    return 0;
}