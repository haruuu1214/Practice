
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define siz(x) (int)x.size()
using namespace std;

const int mod = 998244353; // 1e9 + 7;

const int N = 3000005;

struct Line {
    int a, b;
    Line(int _a, int _b) : a(_a), b(_b) {}
    int operator()(int x) {
        return a * x + b;
    }
};
int a[N], dp[N];

bool check(Line l1, Line l2, Line l3) {
    return (l3.b - l1.b) * (l1.a - l2.a) <= (l2.b - l1.b) * (l1.a - l3.a);
}

signed main() {
    IO;
    
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> a[i];

    auto solve = [&](vector<int> &v, int id, int dx) {
        int m = v.size();
        deque<Line> dq;
        dq.push_back(Line(1, 0));
        for (int i = 0; i < m; i++) {
            while (dq.size() >= 2 && dq[0](v[i]) >= dq[1](v[i]))
                dq.pop_front();
            dp[id + i * dx] = dq.front()(v[i]) + i * v[i] + t;
            Line l = Line(-i, dp[id + i * dx]);
            while (dq.size() >= 2 && check(dq[(int)dq.size() - 2], dq.back(), l))
                dq.pop_back();
            dq.push_back(l);
        }
    };

    int maxid = 0;
    for (int i = 1; i < n; i++)
        if (a[i] > a[maxid])
            maxid = i;
    vector<int> v;
    for (int i = 0; i < maxid; i++) v.push_back(a[i]);
    solve(v, 0, +1);
    v.clear();
    for (int i = n - 1; i > maxid; i--) v.push_back(a[i]);
    solve(v, n - 1, -1);
    
    int preans = maxid * a[maxid];
    for (int i = 0; i < maxid; i++)
        preans = min(preans, dp[i] + (maxid - i - 1) * a[maxid]);
    int sufans = (n - maxid - 1) * a[maxid];
    for (int i = maxid + 1; i < n; i++)
        sufans = min(sufans, dp[i] + (i - maxid - 1) * a[maxid]);
    cout << preans + sufans + a[maxid] + t << "\n";
    
    // for (int i = 0; i < n; i++) cout << dp[i] << " \n"[i == n - 1];
    
    return 0;
}