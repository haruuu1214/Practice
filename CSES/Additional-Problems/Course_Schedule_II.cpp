#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

vector <int> G[100005];
int in[100005];

signed main()
{
    IOS
    
    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        G[b].push_back(a);
        in[a]++;
    }

    priority_queue <int, vector <int>, less <int>> pq;
    for (int i = 1; i <= n; i++) {
        if (!in[i])
            pq.push(i);
    }

    vector <int> order;
    while (!pq.empty()) {
        int v = pq.top();
        pq.pop();
        order.push_back(v);
        for (int u : G[v]) {
            in[u]--;
            if (!in[u])
                pq.push(u);
        }
    }

    reverse(order.begin(), order.end());

    for (int it : order)
        cout << it << " ";
    cout << "\n";
    
    return 0;
}