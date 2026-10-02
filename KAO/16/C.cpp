#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

signed main() {
    IO;
    
    int h, w;
    cin >> h >> w;
    vector <string> s(w);
    for (int i = 0; i < w; i++) cin >> s[i];

    int n = 2 * h - 1;
    auto inside = [&](int x) {
        return (0 <= x && x < n);
    };

    for (int i = 0; i < n; i += 2) {
        int now = i;
        for (int j = 0; j < w; j++) {
            if (inside(now - 1) && s[j][now - 1] == '-')
                now -= 2;
            else if (inside(now + 1) && s[j][now + 1] == '-')
                now += 2;
        }
        cout << now / 2 + 1 << " ";
    }
    
    return 0;
}