#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 15;
int dp[N][N][N];
int ten[N];
int C[N][N];

void init() {
    C[0][0] = 1;
    FOR (i, 1, 12) {
        C[i][0] = 1;
        FOR (j, 1, i - 1)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        C[i][i] = 1;
    }
    ten[0] = 1;
    FOR (i, 1, 12) ten[i] = ten[i - 1] * 10;
    FOR (i, 0, 9)
        dp[1][i][i] = 1;
    FOR (i, 2, 12) {
        FOR (j, 0, 9) {
            FOR (k, 0, 9) {
                int S = 0;
                S += 1 * C[i - 1][1] * ten[i - 1 - 1];
                if (j == k) S += ten[i - 1];
                dp[i][j][k] = S;
            }
        }
    }
}

int calc(string s, int x) {
    int ans = 0;
    vector<int> num;
    FOR (i, 0, (int)s.size() - 1)
        num.push_back(s[i] - '0');
    reverse(num.begin(), num.end());
    int len = num.size();
    int precnt = 0;
    for (int i = len - 1; i >= 0; i--) {
        int mx = num[i];
        for (int j = (i == len - 1); j < mx; j++) {
            ans += dp[i + 1][j][x];
        }
        ans += precnt * mx * ten[i];
        if (mx == x) precnt += 1;
    }
    for (int i = 1; i <= len - 1; i++)
        for (int j = 1; j <= 9; j++) {
            ans += dp[i][j][x];
        }
    // 特判 n
    FOR (i, 0, len - 1)
        if (s[i] - '0' == x)
            ans += 1;
    return ans;
}

signed main() {
    IO;
    
    init();
    
    string s;
    int x;

    while (cin >> s >> x)
        cout << calc(s, x) << "\n";
    
    return 0;
}