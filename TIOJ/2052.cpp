#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 1e18;

int M;
int C[2005][2005];

void init()
{
    C[1][0] = C[1][1] = 1;
    for (int i = 2; i <= 1500; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
        }
    }
}

signed main()
{
    IOS
    
    string s;
    cin >> M >> s;

    init();
    map <char, int> mp;
    for (int i = 0; i < s.size(); i++)
        mp[s[i]]++;
    
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        for (auto &head : mp) { /// 開頭
            if (head.first == s[i])
                break;
            int res = 1;
            head.second--;
            int len = s.size() - i - 1;
            for (auto j : mp) {
                res *= C[len][j.second];
                len -= j.second;
                res %= M;
            }
            head.second++;
            ans = (ans + res) % M;
        }
        mp[s[i]]--;
        if (mp[s[i]] == 0)
            mp.erase(mp.find(s[i]));
    }
    cout << ans << "\n";
    
    return 0;
}