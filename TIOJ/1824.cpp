#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

signed main() {
    IO;
    
    string s;
    cin >> s;
    int x = 0;
    int id = 0;
    FOR (i, 0, (int)s.size() - 1) {
        x *= 10;
        if (s[i] == '?') id = i;
        else x += (s[i] - '0');
    }
    int ten = 1;
    FOR (t, 1, id) ten *= 10;
    FOR (i, 0, 9) {
        if ((x + i * ten) % 7 == 0) {
            string tmp = "";
            FOR (j, 0, (int)s.size() - 1) {
                if (s[j] == '?')
                    tmp += (char)('0' + i);
                else
                    tmp += s[j];
            }
            cout << tmp << "\n";
        }
    }
    
    return 0;
}