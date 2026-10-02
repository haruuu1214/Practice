#include <bits/stdc++.h>
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 2e9;


const int N = 200005;
int a[N];
int b[N];
int id[N], num[N];
int dp[N], best[N];
deque<int> dq[N]; /// {id, val}

signed main() {
    IO;
    
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    vector<pii> v;
    for (int i = 1; i <= n; i++)
        v.push_back({a[i], i});
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++) {
        int tmp = lower_bound(v.begin(), v.end(), make_pair(b[i], -INF)) - v.begin();
        id[v[tmp].second] = i;
        id[v[tmp].second] = n - id[v[tmp].second] + 1;
        num[v[tmp].second] = v[tmp].first;
    }
    
    int ans = 0;
    vector<int> now;
    for (int i = n; i >= 1; i--) {
        int tmp = upper_bound(now.begin(), now.end(), id[i]) - now.begin();
        if (tmp == (int)now.size()) {
            dp[i] = tmp + 1;
            dq[dp[i]].push_back(i);
            now.push_back(id[i]);
        } else {
            dp[i] = tmp + 1;
            dq[dp[i]].push_back(i);
            now[tmp] = id[i];
        }
        ans = max(ans, dp[i]);
    }
    
    int lst_pos = 0, lst_val = INF;
    for (int i = ans; i >= 1; i--) {
        int res = 0; int now_pos = 0; int now_val = 0;
        while (!dq[i].empty() && dq[i].front() > lst_pos) {
            if (num[dq[i].front()] >= res && id[dq[i].front()] < lst_val) {
                res = num[dq[i].front()];
                now_pos = dq[i].front();
                now_val = id[dq[i].front()];
            }
            dq[i].pop_front();
        }
        lst_pos = now_pos;
        lst_val = now_val;
        cout << res << " ";
    }
    cout << "\n";

    return 0;
}
/*
10
1 3 9 5 4 6 8 2 18 10
3 1 4 5 9 2 10 6 8 18
---------------------
2 1 5 4 3 8 10 6 7 9 
1 3 9 5 4 6 8 2 18 10

5 5 4 4 4 2 1 3 2 1

*/