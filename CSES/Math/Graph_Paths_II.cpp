#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO;                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define matrix array<array<int, 110>, 110>
using namespace std;

int min(int a, int b)
{
    if (a < 0)
        return b;
    if (b < 0)
        return a;
    return a < b ? a : b;
}

matrix mul(int N, matrix A, matrix B)
{
    matrix C;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            C[i][j] = -1;
            for (int k = 1; k <= N; k++)
            {
                if (A[i][k] < 0 || B[k][j] < 0)
                    continue;
                C[i][j] = min(C[i][j], A[i][k] + B[k][j]);
            }
        }
    }
    return C;
}

signed main()
{
    IO;

        int n,
        m, k;
    cin >> n >> m >> k;

    matrix F;
    fill(&F[0][0], &F[0][0] + 110 * 110, -1);
    matrix A;
    fill(&A[0][0], &A[0][0] + 110 * 110, -1);

    int a, b, c;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        F[a][b] = min(F[a][b], c);
        A[a][b] = min(A[a][b], c);
    }

    k--;

    while (k > 0)
    {
        if (k & 1)
        {
            A = mul(n, A, F);
        }
        F = mul(n, F, F);
        k >>= 1;
    }

    cout << (A[1][n] == -1 ? -1 : A[1][n]) << "\n";

    return 0;
}