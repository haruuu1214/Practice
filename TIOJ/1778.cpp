#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 1000000009;
const int INF = 2e9;


const int N = 100005;

#define matrix array<array<ll, 105>, 105>

int n;
matrix mul(matrix a, matrix b) {
    matrix c;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            c[i][j] = 0;
            for (int k = 1; k <= n; k++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
        }
    return c;
}

signed main()
{
    IO
    
    int m, s, t;
    ll k;
    int v, u;

    cin >> n >> m >> s >> t >> k;

    matrix mat;
    fill(&mat[0][0], &mat[0][0] + 105 * 105, 0);
    for (int i = 1; i <= m; i++) {
        cin >> v >> u;
        mat[v][u]++;
        mat[u][v]++;
    }

    matrix ans;
    fill(&ans[0][0], &ans[0][0] + 105 * 105, 0);
    for (int i = 1; i <= n; i++)
        ans[i][i] = 1;
    while (k > 0) {
        if (k & 1) ans = mul(mat, ans);
        mat = mul(mat, mat);
        k >>= 1;
    }
    cout << ans[s][t] << "\n";


    return 0;
}