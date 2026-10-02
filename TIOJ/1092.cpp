#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 10005;
vector <int> G[N];
int in[N];
bool win[N];

signed main() {
    IO;
    int n, m;
    while (cin >> n >> m) {
        if (!n && !m) break;
        fill(G, G + n + 1, vector<int>());
        fill(win, win + n + 1, true);
        for (int i = 1; i <= m; i++) {
            int v, u;
            cin >> v >> u;
            G[u].push_back(v);
            in[v]++;
        }
        queue <int> Q;
        for (int i = 1; i <= n; i++)
            if (!in[i])
                Q.push(i);
        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            for (int u : G[v]) {
                if (win[v])
                    win[u] = false;
                in[u]--;
                if (!in[u]) {
                    Q.push(u);
                }
            }
        }
        string s;
        cin >> s;
        if (s == "Mimi") {
            if (win[1])
                cout << "Mimi\n";
            else
                cout << "Moumou\n";
        } else {
            if (win[1])
                cout << "Moumou\n";
            else
                cout << "Mimi\n";
        }
    }
    
    return 0;
}