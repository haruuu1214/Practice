#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

multiset <int> G[2005];
vector <int> order;

void walk(int v)
{
    while (!G[v].empty()) {
        int u = *G[v].begin();
        G[v].erase(G[v].find(u));
        G[u].erase(G[u].find(v));
        walk(u);
    }
    order.push_back(v);
}

signed main()
{
    IO;
    
    int n;

    while (cin >> n) {
        if (n == 0) break;
        
        order.clear();

        int a, b;
        for (int i = 1; i <= n; i++) {
            cin >> a >> b;
            G[a].insert(b);
            G[b].insert(a);
        }
        int start = 1;
        for (int i = 1; i <= 500; i++) {
            if (G[i].size() % 2 == 1) {
                start = i;
                break;
            }
        }
        walk(start);
        reverse(order.begin(), order.end());
        for (int it : order)
            cout << it << "\n";
        cout << "\n";
    }
    
    return 0;
}