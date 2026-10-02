#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define pii pair<int, int>
using namespace std;

const int N = 200005;
vector<map<int, int>> cyc;
/**
 * > 0 : on cycle
 *  -1 : on tree
*/
int nxt[N];
vector<int> par[N];
vector<int> cyc_tot;
int comp_id[N];
int deg[N];
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
            tmp[i] = tmp.size();
            comp_id[i] = cyc.size();
            for (int v = i; ;) {
                int u = nxt[v];
                if (deg[u] == 1) {
                    v = u;
                    deg[v] = 0;
                    tmp[v] = tmp.size();
                    comp_id[v] = cyc.size();
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
    fill(comp_id, comp_id + N, -1);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nxt[i];
        par[nxt[i]].push_back(i);
        deg[nxt[i]] += 1;
    }
    finding_cycle(n);
    queue<int> Q;
    for (int i = 1; i <= n; i++)
        if (comp_id[i] >= 0)
            Q.push(i);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int u : par[v]) {
            if (comp_id[u] == -1) {
                Q.push(u);
                dis_to_cyc[u] = dis_to_cyc[v] + 1;
                comp_id[u] = comp_id[v];
                cyc[comp_id[u]][u] = -1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (cyc[comp_id[i]][i] == -1)
            cout << dis_to_cyc[i] + cyc_tot[comp_id[i]] << " ";
        else
            cout << cyc_tot[comp_id[i]] << " ";
    }
}