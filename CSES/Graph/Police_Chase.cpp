#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int N = 5005;
const int INF = 1e12;

struct edge
{
    int v, u, rev, cap;
};

vector <edge> E;
vector <int> G[N];
int lvl[N];
int p[N]; /// the parent
bool vis[N];

signed main()
{
    IO; 
    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G[a].push_back(2 * i);
        G[b].push_back(2 * i + 1);
        E.push_back({a, b, 2 * i + 1, 1});
        E.push_back({b, a, 2 * i, 1});
    }

    int s = 1, t = n;

    while (true) {
        fill(lvl, lvl + N, INF);
        lvl[s] = 0;
        queue <int> Q;
        Q.push(s);
        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            for (int id : G[v]) {
                if (E[id].cap > 0 && lvl[E[id].u] == INF) {
                    lvl[E[id].u] = lvl[v] + 1;
                    Q.push(E[id].u);
                    p[E[id].u] = id;
                }
            }
        }

        if (lvl[t] == INF) break;

        int now = t, mincap = INF;
        while (now != s) {
            mincap = min(mincap, E[p[now]].cap);
            now = E[p[now]].v;
        }

        now = t;
        while (now != s) {
            E[p[now]].cap -= mincap;
            E[E[p[now]].rev].cap += mincap;
            now = E[p[now]].v;
        }
    }

    queue <int> Q;
    vis[s] = true;
    Q.push(s);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int id : G[v]) {
            if (!vis[E[id].u] && E[id].cap > 0) {
                vis[E[id].u] = true;
                Q.push(E[id].u);
            }
        }
    }

    vector <pii> ans;
    for (edge e : E) {
        if (vis[e.v] == true && vis[e.u] == false && e.cap == 0) {
            ans.push_back({e.v, e.u});
        }
    }

    cout << ans.size() << "\n";
    for (auto it : ans)
        cout << it.first << " " << it.second << "\n";
    
    return 0;
}