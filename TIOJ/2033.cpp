#include <bits/stdc++.h>
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;


const int N = 3000005;
int pos[N], to[N];
bool vis[N];

signed main() {
    IO;
    
    string a, b;
    getline(cin, a);
    getline(cin, b);
    
    int sz1 = a.size(), sz2 = b.size();
    int n = 0, m = 0;
    {
        int x = 0;
        for (int i = 0; i < sz1; i++) {
            if ('0' <= a[i] && a[i] <= '9') {
                x = x * 10 + (a[i] - '0');
            } else {
                if (x > 0) {
                    n += 1;
                    pos[x] = n;
                }
                x = 0;
            }
        }
        if (x > 0) {
            n += 1;
            pos[x] = n;
        }
    }
    {
        int x = 0;
        for (int i = 0; i < sz2; i++) {
            if ('0' <= b[i] && b[i] <= '9') {
                x = x * 10 + (b[i] - '0');
            } else {
                if (x > 0) {
                    m += 1;
                    to[m] = pos[x];
                }
                x = 0;
            }
        }
        if (x > 0) {
            m += 1;
            to[m] = pos[x];
        }
    }
    if (n != m) {
        cout << -1 << "\n";
        return 0;
    }
    // FOR(i, 1, n) {
    //     if (! pos[i]) {
    //         cout << -1 << "\n";
    //         return 0;
    //     }
    // }
    // FOR(i, 1, m) {
    //     if (! to[i]) {
    //         cout << -1 << "\n";
    //         return 0;
    //     }
    // }
    int ans = 0;
    FOR(i, 1, m) {
        if (! vis[i]) {
            int tot = 0;
            int id = i;
            vis[id] = true;
            while (! vis[to[id]]) {
                id = to[id];
                vis[id] = true;
                tot += 1;
            }
            ans += tot;
        }
    }
    cout << ans << "\n";
    
    return 0;
}