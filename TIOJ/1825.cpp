#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;
int l[26], r[26];

signed main() {
    IO;
    
    string s;
    cin >> s;
    FOR(i, 0, (int)s.size() - 1) {
        if (! l[s[i] - 'A'])
            l[s[i] - 'A'] = i + 1;
        r[s[i] - 'A'] = max(r[s[i] - 'A'], i + 1);
    }
    FOR(i, 0, 25) {
        if (l[i] && r[i]) {
            cout << (char)('A' + i) << ":" << l[i] << "," << r[i] << "\n";
        }
    }
    
    return 0;
}