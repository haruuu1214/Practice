#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;


const int N = 1000005;

int trie[N][30];
bool is_end[N];
int cnt = 0;

void insert(string s) {
    int node = 0;
    for (int i = 0; i < s.size(); i++) {
        if (!trie[node][s[i] - 'a'])
            trie[node][s[i] - 'a'] = ++cnt;
        node = trie[node][s[i] - 'a'];
    }
    is_end[node] = true;
}

int dp[N];
string s;
int query(int x) {
    int node = 0, res = 0;
    for (int i = x; i < s.size(); i++) {
        if (!trie[node][s[i] - 'a']) return res;
        node = trie[node][s[i] - 'a'];
        if (is_end[node])
            res = (res + dp[i + 1]) % mod;
    }
    return res;
}

signed main() {
    IO;
    
    string t;
    cin >> s;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        insert(t);
    }

    dp[s.size()] = 1;
    for (int i = s.size() - 1; i >= 0; i--)
        dp[i] = query(i);
    
    cout << dp[0] << "\n";

    return 0;
}