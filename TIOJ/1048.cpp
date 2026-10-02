#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

vector <char> v;

char get_ch(int idx) {
    char c = v[idx - 1];
    v.erase(v.begin() + idx - 1);
    return c;
}

int fac[15];

signed main() {
    IO
    
    fac[0] = 1;
    for (int i = 1; i <= 15; i++) fac[i] = fac[i - 1] * i;
    int n, m;
    while (cin >> n >> m) {
        if (!n && !m) break;
        m %= fac[n];
        if (!m) m += fac[n];
        v.clear();
        for (int i = 0; i < n; i++)
            v.push_back((char)('A' + i));
        
        for (int i = n - 1; i >= 1; i--) {
            int idx = (m + fac[i] - 1) / fac[i];
            cout << get_ch(idx) << " ";
            m -= (idx - 1) * fac[i];
        }
        cout << get_ch(1) << "\n";
    }
    
    return 0;
}