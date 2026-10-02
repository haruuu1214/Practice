#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

map <char, int> idx;
map <vector<int>, int> mp;

signed main()
{
    IOS
    
    string s;
    cin >> s;

    int len = 0;
    for (int i = 0; i < s.size(); i++) {
        if (!idx.count(s[i]))
            idx[s[i]] = len++;
    }

    vector <int> now;
    for (int i = 0; i < len; i++)
        now.push_back(0);
    
    int cntzero = len;

    int ans = 0;
    mp[now]++;
    for (int i = 0; i < s.size(); i++) {
        if (now[idx[s[i]]] == 0) cntzero--;
        now[idx[s[i]]]++;
        if (cntzero == 0) {
            for (int j = 0; j < len; j++) {
                now[j]--;
                if (now[j] == 0)
                    cntzero++;
            }
        }
        if (mp.count(now))
            ans += mp[now];
        mp[now]++;
    }

    cout << ans << "\n";
    
    return 0;
}