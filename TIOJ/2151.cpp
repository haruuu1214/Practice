#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 205;
int a[N];
int dis[N][N];

struct matrix {
    int m[N][N];
};
int n;
matrix mul(matrix &A, matrix &B) {
    matrix C;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            C.m[i][j] = -INF;
            for (int k = 0; k < n; k++)
                C.m[i][j] = max(C.m[i][j], A.m[i][k] + B.m[k][j]);
        }
    return C;
}

signed main() {
    IO;
    
    int m, s, t;
    cin >> n >> m >> s >> t;
    --s;
    for (int i = 0; i < n; i++) cin >> a[i];

    fill(&dis[0][0], &dis[0][0] + N * N, -INF);
    int v, u;
    for (int i = 1; i <= m; i++) {
        cin >> v >> u;
        --v;
        --u;
        dis[v][u] = a[u];
    }

    matrix A, F;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A.m[i][j] = -INF;
    A.m[s][s] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            F.m[i][j] = dis[i][j];
    
    while (t > 0) {
        if (t & 1)
            A = mul(A, F);
        F = mul(F, F);
        t >>= 1;
    }
    
    int ans = -INF;
    for (int i = 0; i < n; i++)
        ans = max(ans, A.m[s][i]);
    cout << ans << "\n";

    return 0;
}