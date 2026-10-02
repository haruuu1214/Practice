#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= b; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

void solve() {
    string s;
    set<char> st;
    FOR(tt, 1, 12) {
        cin >> s;
        for (char c : s) {
            if (c != '.' && c != 'X')
                st.insert(c);
        }
    }
    cout << st.size() << "\n";
}

signed main() {
    IO;
    
    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}