#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

struct item {
    bool b1 = true, b2 = true;
    char c1 = '_', c2 = '_';
    bool conj = false;
};
int n, id = 0;
string s;
item input() {
    item x;
    if (id < n && s[id] == 'n') {
        x.b1 = false;
        id += 4;
    }
    if (id < n && 'A' <= s[id] && s[id] <= 'Z') {
        x.c1 = s[id];
        id += 2;
    }
    if (id < n && s[id] == 'a') {
        x.conj = true;
        id += 4;
    } else if (id < n && s[id] == 'o') {
        x.conj = false;
        id += 3;
    } else {
        return x;
    }
    if (id < n && s[id] == 'n') {
        x.b2 = false;
        id += 4;
    }
    if (id < n && 'A' <= s[id] && s[id] <= 'Z') {
        x.c2 = s[id];
        id += 2;
    }
    return x;
}

string output(item x) {
    string t = "";
    if (x.c2 == '_') {
        if (x.b1)
            t += "not ";
        t += x.c1;
    } else {
        if (x.b1)
            t += "not ";
        t += x.c1;
        if (x.conj)
            t += " or ";
        else
            t += " and ";
        if (x.b2)
            t += "not ";
        t += x.c2;
    }
    return t;
}

void solve() {
    getline(cin, s);
    n = s.size();
    id = 0;
    id += 3;
    item x, y;
    x = input();
    id += 5;
    y = input();

    string ans = "IF " + output(y) + " THEN " + output(x);
    cout << ans << "\n";
}

signed main() {
    IO;
    
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
        solve();
    
    return 0;
}