#include <bits/stdc++.h>
#define int long long
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<int> G[1 << 15];
vector<int> ans;

void dfs(int v) {
    while (!G[v].empty()) {
        int u = G[v].back();
        G[v].pop_back();
        dfs(u);
    }
    ans.push_back(v & 1);
}

signed main() {
    IO;

    int n;
    cin >> n;
    if (n == 1) {
        cout << "10\n";
        return 0;
    }

    for (int i = 0; i < (1 << (n - 1)); i++) {
        G[i].push_back((i << 1) & ((1 << (n - 1)) - 1));
        G[i].push_back(((i << 1) | 1) & ((1 << (n - 1)) - 1));
    }

    dfs(0);
    reverse(ans.begin(), ans.end());

    /// output (n - 2) times '0'
    for (int i = 1; i <= n - 2; i++)
        cout << 0;
    for (int it : ans)
        cout << it;
    cout << "\n";

    return 0;
}