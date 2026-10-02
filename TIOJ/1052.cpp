#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

signed main() {
    IO
    
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        int row = 0, wor = 0, ch = 0;
        while (getline(cin, s)) {
            if (s.size() == 5) {
                bool fg = true;
                for (int i = 0; i < 5; i++) {
                    if (s[i] != '=') {
                        fg = false;
                        break;
                    }
                }
                if (fg)
                    break;
            }
            bool strt = false;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '\t' || s[i] == ' ')
                    strt = false;
                else {
                    if (!strt)
                        wor++;
                    strt = true;
                }
            }
            row++;
            ch += s.size();
        }
        cout << row << " " << wor << " " << ch << "\n";
    }
    
    return 0;
}