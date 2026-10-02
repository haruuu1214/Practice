#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
using namespace std;


struct BIT
{
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
};
BIT bit(20000);
int a[20005];
int pre[20005];
vector <int> v;

int get_id(int x)
{
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

/// > k 的數字有幾個
int calc(int n, int k)
{
    int cnt = 0;
    vector <pii> bit_op;
    bit.update(get_id(0), 1);
    bit_op.push_back({get_id(0), -1});
    for (int i = 1; i <= n; i++) {
        cnt += bit.query(get_id(pre[i] - k) - 1);
        bit.update(get_id(pre[i]), 1);
        bit_op.push_back({get_id(pre[i]), -1});
    }
    for (auto &[id, val] : bit_op)
        bit.update(id, val);
    return cnt;
}

signed main()
{
    IOS
    
    int n, k;
    while (cin >> n >> k) {
        if (n == 0 && k == 0) break;

        v.clear();
        v.push_back(0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
            v.push_back(pre[i]);
        }
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());

        int l = -1e9, r = 1e9;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (calc(n, mid) < k)
                r = mid;
            else
                l = mid;
        }
        cout << r << "\n";
    }
    
    return 0;
}