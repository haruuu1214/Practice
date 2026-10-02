#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

vector<int> G[50005];
array<bitset<50005>, 50005> dp;
int in[50005];

signed main() {
    IO;

    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        in[b]++;
    }

    queue<int> Q;
    vector<int> order;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0)
            Q.push(i);
    }

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        order.push_back(v);
        for (int u : G[v]) {
            in[u]--;
            if (in[u] == 0)
                Q.push(u);
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        int v = order[i];
        dp[v][v] = 1;
        for (int u : G[v])
            dp[v] |= dp[u];
    }

    for (int i = 1; i <= n; i++) {
        int x = dp[i].count();
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}