#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

vector <int> f;
void build(string &s) {
    f.resize(s.size(), -1);
    for (int i = 1; i < s.size(); i++) {
        int j = f[i - 1];
        while (j != -1 && s[i] != s[j + 1])
            j = f[j];
        if (s[i] == s[j + 1])
            f[i] = j + 1;
    }
}

int count(string &a, string &s) {
    int j = -1, cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        while (j != -1 && a[i] != s[j + 1])
            j = f[j];
        if (a[i] == s[j + 1])
            j++;
        if (j + 1 == s.size()) {
            cnt++;
            j = f[j];
        }
    }
    return cnt;
}

signed main() {
    IO;
    
    string a, b;
    cin >> a >> b;
    build(b);
    cout << count(a, b) << "\n";
    
    return 0;
}