#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

vector <int> z;
void build(string &s) {
    z.resize(s.size(), 0);
    int l = 0, r = 0;
    for (int i = 1; i < s.size(); i++) {
        if (i <= r)
            z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

signed main() {
    IO;
    
    string a, b;
    cin >> a >> b;
    a = b + '_' + a;

    build(a);
    int cnt = 0;
    for (int i = 0; i < z.size(); i++)
        if (z[i] == b.size())
            cnt++;
    cout << cnt << "\n";
    
    return 0;
}