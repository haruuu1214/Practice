#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 2e9;

const int N = 30;

int cnt[30], cntcnt[1000005];

void inc(int x) {
    cntcnt[cnt[x]]--;
    cnt[x]++;
    cntcnt[cnt[x]]++;
}

void dec(int x) {
    cntcnt[cnt[x]]--;
    cnt[x]--;
    cntcnt[cnt[x]]++;
}

int n;

void solve() {
    string s;
    cin >> s;

    cntcnt[0] = 26;
    
    int mn = INF, ansl = -1, ansr = -1;
    int r = 0;
    for (int l = 0; l < n; l++) {
        while (r < n && cntcnt[0] > 0) {
            inc(s[r] - 'a');
            r++;
        }
        if (cntcnt[0] == 0) {
            if (r - l < mn) {
                mn = r - l;
                ansl = l, ansr = r - 1;
            }
        } else {
            for (int i = l; i < r; i++)
                dec(s[i] - 'a');
            break;
        }
        dec(s[l] - 'a');
    }
    if (mn == INF)
        cout << "not found\n";
    else {
        for (int i = ansl; i <= ansr; i++)
            cout << s[i];
        cout << "\n";
    }
}

signed main()
{
    IO
    
    while (cin >> n) {
        if (n == 0) break;
        solve();
    }
    
    return 0;
}