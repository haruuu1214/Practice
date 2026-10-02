#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

vector <int> G[200005], rev_G[200005], topo_G[200005];
vector <int> order;
vector <int> topo;
bool vis[200005];
int scc[200005];
int in[200005];
int opp[200005];
int pick[200005];
int n, m;

int tr(int x)
{
    if (x > m) return x - m;
    return x + m;
}

void rev_dfs(int v)
{
    vis[v] = true;
    for (int u : rev_G[v]) {
        if (!vis[u])
            rev_dfs(u);
    }
    order.push_back(v);
}

void dfs(int v, int block)
{
    scc[v] = block;
    for (int u : G[v]) {
        if (scc[u] == -1)
            dfs(u, block);
    }
}

int kosaraju()
{
    for (int i = 1; i <= 2 * m; i++) {
        if (!vis[i])
            rev_dfs(i);
    }
    fill(scc, scc + 2 * m + 1, -1);
    int scc_cnt = 0;
    for (int i = 2 * m - 1; i >= 0; i--) {
        if (scc[order[i]] == -1)
            dfs(order[i], ++scc_cnt);
    }
    return scc_cnt;
}

void topological_sort(int N)
{
    queue <int> Q;
    for (int i = 1; i <= N; i++)
        if (in[i] == 0)
            Q.push(i);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        topo.push_back(v);
        for (int u : topo_G[v]) {
            in[u]--;
            if (!in[u])
                Q.push(u);
        }
    }
}

signed main()
{
    IOS
    
    cin >> n >> m;
    int a, b;
    char c1, c2;
    for (int i = 1; i <= n; i++) {
        cin >> c1 >> a >> c2 >> b;
        if (c1 == '-') a += m;
        if (c2 == '-') b += m;
        G[tr(a)].push_back(b);
        G[tr(b)].push_back(a);
        rev_G[b].push_back(tr(a));
        rev_G[a].push_back(tr(b));
    }

    int sz = kosaraju();

    for (int i = 1; i <= m; i++) {
        if (scc[i] == scc[i + m]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        opp[scc[i]] = scc[i + m];
        opp[scc[i + m]] = scc[i];
    }
    
    for (int v = 1; v <= 2 * m; v++) {
        for (int u : G[v]) {
            if (scc[v] != scc[u]) {
                topo_G[scc[u]].push_back(scc[v]);
                in[scc[v]]++;
            }
        }
    }

    topological_sort(sz);

    for (int v : topo) {
        if (!pick[v]) {
            pick[v] = 1;
            pick[opp[v]] = 2;
        }
    }

    for (int i = 1; i <= m; i++) {
        if (pick[scc[i]] == 1) cout << "+ ";
        else cout << "- ";
    }
    cout << "\n";

    return 0;
}