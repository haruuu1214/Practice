#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
using namespace std;

const int mod = 998244353;
const int INF = 1e18;

const int N = 100005;

struct item {
    int cost = 0, l = -1, r = -1;
};

string s;
int n;
int i = 0;

item dfs() {
    int cnt = 0, l = -1, r = -1;
    while (i < n && s[i] != 'E') {
        if (s[i] == 'T') {
            int x = (s[i + 1] - '0') * 10 + (s[i + 2] - '0');
            i += 3;
            if (l == -1) {
                l = x;
                r = x;
            } else {
                cnt += abs(x - r);
                r = x;
            }
        } else if (s[i] == 'L') {
            int tim = (s[i + 1] - '0');
            i += 2;
            item res = dfs();
            if (l == -1) {
                l = res.l;
                r = res.r;
            } else {
                cnt += abs(res.l - r);
                r = res.r;
            }
            cnt += res.cost * tim + abs(res.l - res.r) * (tim - 1);
            r = res.r;
        }
    }
    if (i < n && s[i] == 'E')
        i += 1;
    return {cnt, l, r};
}

signed main() {
    IO;
    
    cin >> s;
    n = s.size();

    item ans = dfs();
    cout << ans.cost + abs(10 - ans.l) << "\n";
    
    return 0;
}