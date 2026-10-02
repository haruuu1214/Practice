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

signed main() {
    IO;
    
    string s;
    cin >> s;
    build(s);
    vector <int> ans;
    int now = s.size() - 1;
    while (f[now] != -1) {
        ans.push_back(f[now]);
        now = f[now];
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans)
        cout << i + 1 << " ";
    cout << "\n";
    
    return 0;
}