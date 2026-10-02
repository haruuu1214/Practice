#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 2e9;


const int N = 10005;
int a[N], b[N], c[N];

signed main()
{
    IO
    
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        if (a[i] > b[i])
            c[i] = 9 - (a[i] - b[i]);
        else
            c[i] = b[i] - a[i];
    }

    int ans = 0;
    for (int i = n; i >= k; i--) {
        int dx = c[i];
        if (dx == 0) continue;
        ans += dx;
        for (int j = i; j >= i - k + 1; j--) {
            c[j] -= dx;
            if (c[j] < 0)
                c[j] += 9;
        }
    }

    for (int i = 1; i <= n; i++)
        if (c[i] != 0) {
            cout << 0 << "\n";
            return 0;
        }
    
    cout << (ans == 0 ? 9 : ans) << "\n";
    
    return 0;
}