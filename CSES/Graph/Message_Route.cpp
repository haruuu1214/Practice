#include <bits/stdc++.h>
#define int long long
using namespace std;

vector <int> G[100005];
bool vis[100005];
int pre[100005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    queue <int> q;
    q.push(1);
    bool success=false;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v == n) {
            success=1;
            break;
        }
        for (int u : G[v]) {
            if (vis[u]) continue;
            q.push(u);
            vis[u] = 1;
            pre[u] = v;
        }
    }
    if (success) {
        vector <int> ans;
        int idx = n;
        while (idx != 1) {
            ans.push_back(idx);
            idx = pre[idx];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (int x : ans)
            cout << x << " ";
        cout << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}
