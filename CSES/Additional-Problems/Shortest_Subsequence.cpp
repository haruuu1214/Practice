#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

char ch[4] = {'A', 'T', 'C', 'G'};
int nxt[1000005][4];

signed main()
{
    IO;
    
    string s;
    cin >> s;

    int n = s.size();
    for (int j = 0; j < 4; j++)
        nxt[n][j] = n;
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (s[i] == ch[j])
                nxt[i][j] = i;
            else
                nxt[i][j] = nxt[i + 1][j];
        }
    }

    int now = 0;
    int nxt_choose;
    char nxt_ch;
    while (now <= n) {
        nxt_choose = -1;
        for (int j = 0; j < 4; j++) {
            if (nxt[now][j] > nxt_choose) {
                nxt_choose = nxt[now][j];
                nxt_ch = ch[j];
            }
        }
        cout << nxt_ch;
        now = nxt_choose + 1;
    }
    
    return 0;
}