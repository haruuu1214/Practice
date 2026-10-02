#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
// const int INF = 1e9;
const int INF = 1e18;


const int N = 100005;
int a[N], d[N], t[N];
priority_queue<int, vector<int>, greater<int>> Q;

signed main() {
    IO;
    
    int T, n;
    while (cin >> T >> n) {
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> d[i];
        for (int i = 1; i <= n; i++) cin >> t[i];
        while (!Q.empty()) Q.pop();
        
        int ans = 0;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            T -= t[i];
            
            while (T < 0 && !Q.empty()) {
                res -= Q.top();
                Q.pop();
                T += 1;
            }
            
            if (T < 0) break;
            
            for (int j = 0; ; j++) {
                if (a[i] - j * d[i] <= 0) break;
                if (T > 0) {
                    res += a[i] - j * d[i];
                    Q.push(a[i] - j * d[i]);
                    T -= 1;
                } else if (!Q.empty() && Q.top() < a[i] - j * d[i]) {
                    int tmp = Q.top();
                    res += (a[i] - j * d[i]) - tmp;
                    Q.pop();
                    Q.push(a[i] - j * d[i]);
                } else {
                    break;
                }
            }
            ans = max(ans, res);
        }
        cout << ans << "\n";
    }
    
    return 0;
}