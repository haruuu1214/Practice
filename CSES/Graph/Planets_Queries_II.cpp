#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define pii pair<int, int>
using namespace std;

// const int INF = 1e17;
const int N = 200005;
int nxt[N];
vector<int> par[N];
int deg[N], dp[30][N];
vector<map<int, int>> cyc;
vector<int> cyc_tot;
/**
 * >= 0 : on cycle
 *   -1 : on tree
*/
int comp_id[N];
int dis_to_cyc[N];

void finding_cycle(int n) {
    queue<int> Q;
    for (int i = 1; i <= n; i++)
        if (!deg[i])
            Q.push(i);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        int u = nxt[v];
        deg[u] -= 1;
        if (!deg[u])
            Q.push(u);
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            map<int, int> tmp;
            deg[i] = 0;
            comp_id[i] = cyc.size();
            tmp[i] = tmp.size();
            for (int v = i; ;) {
                int u = nxt[v];
                if (deg[u] == 1) {
                    v = u;
                    deg[v] = 0;
                    comp_id[v] = cyc.size();
                    tmp[v] = tmp.size();
                    continue;
                } else {
                    break;
                }
            }
            cyc.push_back(tmp);
            cyc_tot.push_back(tmp.size());
        }
    }
}

signed main() {
    IO;
    int n, q, x;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> nxt[i];
        par[nxt[i]].push_back(i);
        deg[nxt[i]] += 1;
    }
    fill(comp_id, comp_id + N, -1);
    finding_cycle(n);

    for (int i = 1; i <= n; i++) {
        if (comp_id[i] == -1)
            dp[0][i] = nxt[i];
    }
    for (int i = 1; i < 30; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
    
    queue<int> Q;
    for (int i = 1; i <= n; i++) {
        if (comp_id[i] >= 0) {
            Q.push(i);
            dis_to_cyc[i] = 0;
        }
    }
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int u : par[v]) {
            if (comp_id[u] >= 0) continue;
            comp_id[u] = comp_id[v];
            dis_to_cyc[u] = dis_to_cyc[v] + 1;
            cyc[comp_id[u]][u] = -1;
            Q.push(u);
        }
    }
    
    auto walk = [&](int v, int step) {
        for (int i = 0; i < 30; i++)
            if (step & (1 << i))
                v = dp[i][v];
        return v;
    };

    // for (int i = 1; i <= n; i++)
    //     cout << dis_to_cyc[i] << " ";
    // return 0;
    int v, u;
    for (int i = 1; i <= q; i++) {
        cin >> v >> u;
        if (comp_id[v] != comp_id[u]) {
            cout << -1 << "\n";
            continue;
        } else if (cyc[comp_id[v]][v] >= 0 && cyc[comp_id[u]][u] == -1) {
            cout << -1 << "\n";
        } else if (cyc[comp_id[v]][v] >= 0 && cyc[comp_id[u]][u] >= 0) {
            int x = cyc[comp_id[v]][v];
            int y = cyc[comp_id[u]][u];
            cout << (y - x + cyc_tot[comp_id[v]]) % cyc_tot[comp_id[v]] << "\n";
        } else if (cyc[comp_id[v]][v] == -1 && cyc[comp_id[u]][u] >= 0) {
            int near_v_vertex = walk(v, dis_to_cyc[v]);
            int x = cyc[comp_id[near_v_vertex]][near_v_vertex];
            int y = cyc[comp_id[u]][u];
            cout << dis_to_cyc[v] +
                    (y - x + cyc_tot[comp_id[v]]) % cyc_tot[comp_id[v]] << "\n";
        } else {
            int x = dis_to_cyc[v];
            int y = dis_to_cyc[u];
            if (x < y)
                cout << -1 << "\n";
            else {
                if (walk(v, x - y) == u)
                    cout << x - y << "\n";
                else
                    cout << -1 << "\n";
            }
        }
    }
}