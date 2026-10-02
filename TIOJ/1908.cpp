#include <bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 2e9;


const int N = 50005;
int a[22][22];
int id[1 << 22];
vector <int> mask, lst[N];
int n;

void dfs(int ori, int now, int i) {
    if (i == n) {
        lst[id[ori]].push_back(now);
        return;
    }
    dfs(ori, now, i + 1);
    if ( (i == 0 || ! (now & (1 << (i - 1)))) && (i == 0 || ! (ori & (1 << (i - 1)))) &&
         ! (ori & (1 << i)) && (i == n - 1 || ! (ori & (1 << (i + 1)))) )
        dfs(ori, now ^ (1 << i), i + 1);
}

void init() {
    for (int i = 0; i < (1 << n); i++) {
        if (! (i & (i >> 1))) {
            id[i] = mask.size();
            mask.push_back(i);
            dfs(i, 0, 0);
        }
    }
}

int dp[2][1 << 22];

signed main() {
    IO;
    
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    
    init();

    for (int i = 0; i < n; i++) {
        for (int m : mask) {
            int sum = 0;
            for (int j = 0; j < n; j++)
                if (m & (1 << j))
                    sum += a[i][j];
            dp[i % 2][m] = 0;
            for (int l : lst[id[m]])
                dp[i % 2][m] = max(dp[i % 2][m], dp[(i + 1) % 2][l] + sum);
        }
    }
    int mx = 0;
    for (int m : mask) {
        mx = max(mx, dp[(n - 1) % 2][m]);
    }
    cout << mx << "\n";

    return 0;
}