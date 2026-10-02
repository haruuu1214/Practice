
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define siz(x) (int)x.size()
using namespace std;

const int mod = 998244353; // 1e9 + 7;

const int N = 1;
int m;

vector<int> mul(vector<int> &A, vector<int> &B) {
    vector<int> C(m * m);
    for (int k = 0; k < m; k++)
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                C[i * m + j] = (C[i * m + j] + A[i * m + k] * B[k * m + j]) % mod;
    return C;
}

int fastpow(int a, int b) {
    int ans = 1, res = a;
    while (b > 0) {
        if (b & 1) ans = ans * res % mod;
        res = res * res % mod;
        b >>= 1;
    }
    return ans;
}

signed main() {
    IO;
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    m = n + 1;
    vector<int> A(m * m);
    // s[0, i] = [j - i, j]
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            bool fg = true;
            for (int pl = 0, pr = j - i; pl <= i; pl++, pr++)
                if (s[pl] != s[pr]) {
                    fg = false;
                    break;
                }
            if (fg)
                A[j * m + (i + 1)] = 1;
        }
    }
    A[0] = 10;
    A[(m - 2) * m + (m - 1)] = A[(m - 1) * m + (m - 1)] = 10;

    for (int j = 0; j < m; j++)
        for (int i = 0; i < m; i++)
            cout << A[i * m + j] << " \n"[i == m - 1];
    // return 0;

    int q, k;
    cin >> q;
    while (q--) {
        cin >> k;
        vector<int> V(m * m), T(m * m);
        for (int i = 0; i < m * m; i++) T[i] = A[i];
        for (int i = 0; i < m; i++) V[i * m + i] = 1;
        k -= 1;
        while (k > 0) {
            if (k & 1) V = mul(V, T);
            T = mul(T, T);
            k >>= 1;
        }
        int ans = V[0 * m + m - 1] * 10;
        ans = ans * fastpow(fastpow(10, m), mod - 2) % mod;
        cout << ans << "\n";
    }

    return 0;
}