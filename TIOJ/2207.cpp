#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

int n, k;
string s[3];

void solve_one() {
    for (int i = 0; i < n; i++)
        cout << !(s[0][i] - '0');
    cout << "\n";
}

void solve_two() {
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (s[0][i] == s[1][i])
            cout << !(s[0][i] - '0');
        else {
            if (cnt1 < cnt2) {
                cout << s[0][i];
                ++cnt1;
            } else {
                cout << s[1][i];
                ++cnt2;
            }
        }
    }
    cout << "\n";
}

void solve_three() {
    int cnt[3] = {0, 0, 0};
    vector <int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        if (s[0][i] == s[1][i] && s[1][i] == s[2][i])
            ans[i] = !(s[0][i] - '0');
        else {
            if (s[0][i] != s[1][i] && s[0][i] != s[2][i]) {
                ans[i] = (s[0][i] - '0');
                ++cnt[1]; ++cnt[2];
            } else if (s[1][i] != s[0][i] && s[1][i] != s[2][i]) {
                ans[i] = (s[1][i] - '0');
                ++cnt[0]; ++cnt[2];
            } else {
                ans[i] = (s[2][i] - '0');
                ++cnt[0]; ++cnt[1];
            }
        }
    }
    int before_mnid = 0;
    if (cnt[1] < cnt[before_mnid])
        before_mnid = 1;
    if (cnt[2] < cnt[before_mnid])
        before_mnid = 2;
    for (int i = 0; i < n; i++) {
        if (s[0][i] == s[1][i] && s[1][i] == s[2][i])
            ;
        else {
            if (s[0][i] != s[1][i] && s[0][i] != s[2][i]) {
                if (before_mnid == 0) {
                    if (cnt[0] + 1 > cnt[1] - 1 || cnt[0] + 1 > cnt[2] - 1)
                        break;
                    ans[i] = !ans[i];
                    ++cnt[0];
                    --cnt[1]; --cnt[2];
                }
            } else if (s[1][i] != s[0][i] && s[1][i] != s[2][i]) {
                if (before_mnid == 1) {
                    if (cnt[1] + 1 > cnt[0] - 1 || cnt[1] + 1 > cnt[2] - 1)
                        break;
                    ans[i] = !ans[i];
                    ++cnt[1];
                    --cnt[0]; --cnt[2];
                }
            } else {
                if (before_mnid == 2) {
                    if (cnt[2] + 1 > cnt[0] - 1 || cnt[2] + 1 > cnt[1] - 1)
                        break;
                    ans[i] = !ans[i];
                    ++cnt[2];
                    --cnt[0]; --cnt[1];
                }
            }
        }
    }
    for (int i : ans)
        cout << i;
    cout << "\n";
}

signed main() {
    IO;
    
    cin >> n >> k;
    for (int i = 0; i < k; i++) cin >> s[i];
    if (k == 1)
        solve_one();
    else if (k == 2)
        solve_two();
    else
        solve_three();
    
    return 0;
}