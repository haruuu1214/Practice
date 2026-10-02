#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;


const int N = 3;

struct matrix {
    int m[N][N];
};

matrix mul(matrix &A, matrix &B) {
    matrix C;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            C.m[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C.m[i][j] += A.m[i][k] * B.m[k][j] % mod;
                C.m[i][j] %= mod;
            }
        }
    return C;
}

int trans[N][N] = {
    {1, 0, 1},
    {2, 1, 0},
    {1, 1, 0}
};

signed main() {
    IO;
    
    int n;
    cin >> n;
    --n;

    matrix F;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            F.m[i][j] = trans[i][j];
    
    matrix A;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            A.m[i][j] = 0;
    A.m[0][0] = 1;
/*
    output(A);

    for (int i = 1; i <= n; i++) {
        A = mul(F, A);
        output(A);
    }
*/

    while (n > 0) {
        if (n & 1) A = mul(F, A);
        F = mul(F, F);
        n >>= 1;
    }

    cout << A.m[2][0] << "\n";
    
    return 0;
}