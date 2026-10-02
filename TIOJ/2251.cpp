#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
#define STL(x) for(auto &HEHE:x) cout << HEHE << " "; cout << "\n";
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

string input, s;
int sz, idx;
map <string, int> mp;

int getnumber()
{
    int t = 0;
    while (idx < sz && '0' <= s[idx] && s[idx] <= '9') {
        t = t * 10 + (s[idx] - '0');
        idx++;
    }
    return t;
}

string getword()
{
    string t;
    t += s[idx];
    idx++;
    while (idx < sz && 'a' <= s[idx] && s[idx] <= 'z') {
        t += s[idx];
        idx++;
    }
    return t;
}

map<string, int> bracket()
{
    map <string, int> now;
    idx++; /// (
    while (s[idx] != ')') {
        if (s[idx] == '(') {
            map <string, int> tmp = bracket();
            for (auto it : tmp)
                now[it.first] += it.second;
        } else if ('A' <= s[idx] && s[idx] <= 'Z') {
            string t = getword();
            int mul = 1;
            if ('0' <= s[idx] && s[idx] <= '9') {
                mul = getnumber();
            }
            now[t] += mul;
        } else {
            /// ???
            cout << "FAIL\n";
        }
    }
    idx++; /// )
    if (idx < sz && '0' <= s[idx] && s[idx] <= '9') {
        int mul = getnumber();
        for (auto &it : now)
            now[it.first] = it.second * mul;
    }
    return now;
}

void solve()
{
    idx = 0;
    mp = bracket();
    cout << input << "\n";
    for (auto it : mp) {
        cout << it.first << ":" << it.second << "\n";
    }
}

signed main()
{
    IOS
    
    cin >> input;

    s = '(' + input + ')';
    sz = s.size();
    
    solve();
    
    return 0;
}