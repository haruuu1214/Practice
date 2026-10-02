
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

const int N = 1005;
int a[4][N];

signed main() {
    IO;
    
    int n, x;
    cin >> n >> x;
    FOR (i, 0, 3) FOR (j, 1, n) cin >> a[i][j];

    vector<int> v1, v2;
    FOR (i, 1, n) FOR (j, 1, n) v1.push_back(a[0][i] + a[1][j]);
    FOR (i, 1, n) FOR (j, 1, n) v2.push_back(a[2][i] + a[3][j]);
    sort(all(v1));
    sort(all(v2));
    int ans = 0;
    int r = (int)v2.size();
    for (int l = 0; l < (int)v1.size(); l++) {
        while (r - 1 >= 0 && v1[l] + v2[r - 1] >= x) r -= 1;
        ans += (int)v2.size() - r;
    }
    cout << ans << "\n";
    
    return 0;
}