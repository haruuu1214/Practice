#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


struct BIT {
    int N;
    vector <int> info;
    BIT(int n) : N(n), info(n + 1) {}
    void update(int idx, int val) {
        for (int i = idx; i <= N; i += i & -i)
            info[i] += val;
    }
    int query(int idx) {
        int res = 0;
        for (int i = idx; i > 0; i -= i & -i)
            res += info[i];
        return res;
    }
    int kth(int k) { /// kth small
        int res = 0;
        for (int i = 1 << __lg(N); i > 0; i >>= 1) {
            if (res + i <= N && info[res + i] < k) {
                res += i;
                k -= info[res];
            }
        }
        return res + 1;
    }
};

const int N = 200005;
int h[N], w[N];
int l[N], r[N];

signed main() {
    IO;
    
    int n, q;
    cin >> n >> q;
    BIT bit(n);
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) bit.update(i, w[i]);

    deque<int> dq;
    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && h[dq.back()] <= h[i])
            dq.pop_back();
        if (dq.empty())
            l[i] = 1;
        else
            l[i] = dq.back() + 1;
        dq.push_back(i);
    }
    while (!dq.empty()) dq.pop_back();
    for (int i = n; i >= 1; i--) {
        while (!dq.empty() && h[dq.back()] <= h[i])
            dq.pop_back();
        if (dq.empty())
            r[i] = n;
        else
            r[i] = dq.back() - 1;
        dq.push_back(i);
    }

    int op, p, x;
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> p >> x;
            bit.update(p, x - w[p]);
            w[p] = x;
        } else {
            cin >> p;
            cout << bit.query(r[p]) - bit.query(l[p] - 1) << "\n";
        }
    }

    return 0;
}