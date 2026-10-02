#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;
vector<int> G[N];
bool vis[N];
int id[N];

signed main() {
    IO;
    
    int n, k, x;
    cin >> n;
    FOR (i, 1, n) {
        cin >> k;
        FOR (t, 1, k) {
            cin >> x;
            G[i].push_back(x);
        }
        reverse(G[i].begin(), G[i].end());
    }

    stack<int> stk;
    stk.push(1);
    int now = 0;
    while (! stk.empty()) {
        int v = stk.top();
        stk.pop();
        id[v] = ++now;
        for (int u : G[v]) {
            if (! vis[u]) {
                vis[u] = true;
                stk.push(u);
            }
        }
    }
    FOR (i, 1, n)
        cout << id[i] << "\n";
    
    return 0;
}