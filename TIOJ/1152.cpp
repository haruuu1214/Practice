#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

vector <int> G[10005];
int mx, pt;

void dfs(int v, int p, int step)
{
    if (step > mx) {
        mx = step;
        pt = v;
    }
    for (int u : G[v]) {
        if (u == p) continue;
        dfs(u, v, step + 1);
    }
}

signed main()
{
    IOS
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u;
        while (cin >> u) {
            if (u == -1) break;
            G[i].push_back(u);
            G[u].push_back(i);
        }
    }

    mx = -1, pt = -1;
    dfs(0, -1, 0);
    int tmp = pt;
    mx = -1, pt = -1;
    dfs(tmp, -1, 0);

    cout << mx << "\n";
    
    return 0;
}