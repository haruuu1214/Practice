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
    
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool allzro = true, allone = true;

    int cnt = 0;
    bool b = false;
    bool preuse = false;
    FOR (i, 0, n - 1) {
        bool now = (s[i] == '1' ? true : false);
        if (now) allzro = false;
        if (! now) allone = false;

        if (! i) {
            b = now;
        } else {
            if (now != b) {
                cnt += 1;
                b = now;
            }
            if (i != n - 1 && ! preuse && (s[i - 1] != s[i] && s[i] != s[i + 1])) {
                cnt -= 1;
                preuse = true;
            } else {
                preuse = false;
            }
        }
    }
    bool lst = (s[n - 1] == '1' ? true : false);
    if (! lst)
        if (! (n - 2 >= 0 && s[n - 2] == '1'))
            cnt += 1;
    
    if (allzro)
        cout << 1 << "\n";
    else if (allone)
        cout << 0 << "\n";
    else
        cout << cnt << "\n";
    
    return 0;
}