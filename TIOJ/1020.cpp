#include <bits/stdc++.h>
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;


const int N = 35;
int a[N], pre[N], nxt[N];
vector<int> ans;
int n, cnt = 0;

void dfs(int x) {
    if (x == n + 1) {
        cnt += 1;
        bool suc = false;
        int now = 0;
        FOR (i, 0, n) {
            if (now > ans[i]) {
                suc = true;
                break;
            } else if (now == ans[i]) {
                ;
            } else {
                break;
            }
            now = nxt[now];
        }
        if (suc) {
            now = 0;
            FOR (i, 0, n) {
                ans[i] = now;
                now = nxt[now];
            }
        }
        return;
    }
    FOR (i, 0, x - 1) {
        if (i == 1) continue;
        int nxxt = nxt[i];
        if (x % (i + nxxt)) continue;
        nxt[i] = x; pre[x] = i;
        nxt[x] = nxxt; pre[nxxt] = x;
        dfs(x + 1);
        nxt[i] = nxxt; pre[nxxt] = i;
        nxt[x] = -1; pre[x] = -1;
    }
}

signed main() {
    IO;
    
    cin >> n;
    ans.assign(n + 1, -1);
    FOR (i, 0, n) a[i] = i;
    FOR (i, 0, n) pre[i] = -1, nxt[i] = -1;
    nxt[0] = 1;
    pre[1] = 0;
    dfs(2);
    cout << cnt << "\n";
    FOR (i, 0, n) cout << ans[i] << " \n"[i == n];

    return 0;
}