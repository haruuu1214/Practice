#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

signed main() {
    IO;
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    int sum = 0;
    FOR(i, 0, n - 1)
        FOR(j, 0, m - 1) {
            cin >> a[i][j];
            sum += a[i][j];
        }
    vector<int> X, Y;
    FOR(i, 0, n - 1) {
        int tmp = 0;
        FOR(j, 0, m - 1)
            tmp += a[i][j];
        X.push_back(tmp);
    }
    FOR(j, 0, m - 1) {
        int tmp = 0;
        FOR(i, 0, n - 1)
            tmp += a[i][j];
        Y.push_back(tmp);
    }
    int len1 = n - 1;
    int len2 = m - 1;
    vector<int> cst1(len1), cst2(len2);
    FOR(i, 0, len1 - 1)
        cst1[i] = X[i] + X[i + 1];
    FOR(i, 0, len2 - 1)
        cst2[i] = Y[i] + Y[i + 1];
    sort(cst1.begin(), cst1.end(), greater<int>());
    sort(cst2.begin(), cst2.end(), greater<int>());
    vector<int> pre1(n, 0);
    vector<int> pre2(m, 0);
    FOR(i, 1, n - 1)
        pre1[i] = pre1[i - 1] + cst1[i - 1];
    FOR(i, 1, m - 1)
        pre2[i] = pre2[i - 1] + cst2[i - 1];

    vector<int> ans(n * m + 1, -1ll);
    FOR(i, 0, n - 1)
        FOR(j, 0, m - 1)
            ans[(i + 1) * (j + 1)] = max(ans[(i + 1) * (j + 1)], pre1[i] + pre2[j]);
    
    int tot = 0;
    FOR(i, 0, n - 1)
        tot += a[i][0];
    FOR(i, 0, n - 1)
        tot += a[i][m - 1];
    FOR(i, 0, m - 1)
        tot += a[0][i];
    FOR(i, 0, m - 1)
        tot += a[n - 1][i];
    FOR(i, 0, n - 1)
        FOR(j, 0, m - 1)
            tot += a[i][j];
    
    FOR(i, 1, n * m) {
        if (ans[i] == -1)
            cout << -1 << " \n"[i == n * m];
        else
            cout << tot + ans[i] << " \n"[i == n * m];
    }

    return 0;
}