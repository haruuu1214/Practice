#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

const int INF = 1e17;
const int N = 100005;
vector<int> G[N];
vector<int> cyc;
stack<int> stk;
int vis[N];
bool suc = false;

void finding_cycle(int v) {
    if (vis[v] == 2)
        return;
    vis[v] = 1;
    stk.push(v);
    for (int u : G[v]) {
        if (suc)
            return;
        if (vis[u] == 1) {
            cyc.push_back(u);
            while (stk.top() != u) {
                cyc.push_back(stk.top());
                stk.pop();
            }
            cyc.push_back(u);
            suc = true;
            return;
        }
        finding_cycle(u);
    }
    if (suc)
        return;
    stk.pop();
    vis[v] = 2;
}

signed main() {
    int n, m;
    cin >> n >> m;
    int v, u;
    for (int i = 1; i <= m; i++) {
        cin >> v >> u;
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            finding_cycle(i);
        if (suc)
            break;
    }
    if (suc) {
        cout << cyc.size() << "\n";
        reverse(cyc.begin(), cyc.end());
        for (int i : cyc)
            cout << i << " ";
        cout << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }
}