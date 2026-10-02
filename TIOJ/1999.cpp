#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

signed main() {
    IO;
    
    int n, m;
    cin >> n >> m;
    priority_queue <int, vector<int>, greater<int>> Q;
    for (int i = 1; i <= m; i++) Q.push(0);
    int t;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        int x = Q.top();
        Q.pop();
        Q.push(x + t);
    }
    int ans = 0;
    while (!Q.empty()) {
        ans = max(ans, Q.top());
        Q.pop();
    }
    cout << ans << "\n";
    
    return 0;
}