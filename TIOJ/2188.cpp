#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

signed main() {
    IO;
    
    string s;
    cin >> s;
    string ans;
    int n = s.size();
    int t = 0;
    for (int i = 0; i < n; i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            t = t * 10 + (s[i] - '0');
        } else {
            if (!t) {
                ans += s[i];
            } else {
                while (t--)
                    ans += s[i];
            }
            t = 0;
        }
    }
    cout << ans << "\n";
    
    return 0;
}