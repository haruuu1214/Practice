#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;
int a[N];

vector <int> h;
vector <int> len;
int h_cnt;
int calc(int h_low, int h_high, int l) {
    int cnt = 0;
    int lid = h_cnt - 1 - (upper_bound(len.begin(), len.end(), l) - len.begin() - 1);
    int rid = upper_bound(h.begin(), h.end(), h_high) - h.begin() - 1;
    lid = max(0ll, lid);
    rid = min(h_cnt - 1, rid);
    for (int i = lid; i <= rid; i++) {
        cnt += max(0ll, l - len[h_cnt - 1 - i] + 1) * max(0ll, (h_high - max(h[i], h_low) + 1));
    }
    return cnt;
}

int lmin[N], rmin[N];

signed main() {
    IO;
    
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i * i <= m; i++) {
        if (i * i == m) {
            h.push_back(i);
            len.push_back(i);
        } else if (m % i == 0) {
            h.push_back(i);
            h.push_back(m / i);
            len.push_back(i);
            len.push_back(m / i);
        }
    }
    h_cnt = h.size();
    sort(h.begin(), h.end());
    sort(len.begin(), len.end());
    deque <int> dq;
    a[0] = -1; a[n + 1] = -1;
    dq.push_back(0);
    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && a[dq.back()] > a[i])
            dq.pop_back();
        if (a[dq.back()] == a[i])
            lmin[i] = -1;
        else
            lmin[i] = dq.back();
        dq.push_back(i);
    }
    while (!dq.empty()) dq.pop_back();
    dq.push_back(n + 1);
    for (int i = n; i >= 1; i--) {
        while (!dq.empty() && a[dq.back()] >= a[i])
            dq.pop_back();
        rmin[i] = dq.back();
        dq.push_back(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (lmin[i] == -1) continue;
        int h_low = max(a[lmin[i]], a[rmin[i]]) + 1;
        int h_high = a[i];
        ans += max(0ll, calc(h_low, h_high, rmin[i] - lmin[i] - 1));
    }
    cout << ans << "\n";

    return 0;
}
/*
5 4
1 3 2 4 1
-> 5

8 8 
3 4 3 3 5 6 3 1
-> 11

6 2
3 3 0 3 3 3
-> 19

5 7
6 6 6 6 6
-> 0
*/