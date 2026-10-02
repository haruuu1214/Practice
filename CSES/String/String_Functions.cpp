#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

vector <int> F;
vector <int> Z;
void build_F(string &s)
{
    F.resize(s.size(), -1);
    for (int i = 1; i < s.size(); i++) {
        int j = F[i - 1];
        while (j != -1 && s[i] != s[j + 1])
            j = F[j];
        if (s[i] == s[j + 1])
            F[i] = j + 1;
    }
}

void build_Z(string &s)
{
    Z.resize(s.size(), 0);
    for (int i = 1, l = 0, r = 0; i < s.size(); i++) {
        if (i <= r)
            Z[i] = min(Z[i - l], r - i + 1);
        while (r < s.size() && s[Z[i]] == s[i + Z[i]])
            Z[i]++;
        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }
    }
}

signed main()
{
    IOS
    
    string s;
    cin >> s;
    build_F(s);
    build_Z(s);
    for (int i : Z)
        cout << i << " ";
    cout << "\n";
    for (int i : F)
        cout << i + 1 << " ";
    cout << "\n";
    
    return 0;
}