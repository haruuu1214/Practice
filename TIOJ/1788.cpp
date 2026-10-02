#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

void solve() {
    string s;
    cin >> s;
    int sz = s.size();
    int l, r;
    bool fail = false;
    priority_queue <int, vector<int>, greater<int>> Q;
    int ans = 0;
    int cnt = 0; /// 右刮 - 左刮 的個數
    for (int i = 0; i < sz; i++) {
        if (s[i] == '(') {
            --cnt;
        } else if (s[i] == ')') {
            ++cnt;
        } else {
            cin >> l >> r;
            ++cnt;
            ans += r;
            Q.push(l - r);
        }
        while (!Q.empty() && cnt > 0) {
            ans += Q.top();
            Q.pop();
            cnt -= 2;
        }
        if (cnt > 0)
            fail = true;
    }
    while (!Q.empty() && cnt > 0) {
        ans += Q.top();
        Q.pop();
        cnt -= 2;
    }
    if (fail || cnt != 0)
        cout << "QAQ\n";
    else
        cout << ans << "\n";
}

signed main() {
    IO;
    
    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}